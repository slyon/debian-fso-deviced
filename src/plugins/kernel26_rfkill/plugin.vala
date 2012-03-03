/*
 * Copyright (C) 2009-2011 Michael 'Mickey' Lauer <mlauer@vanille-media.de>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 *
 */

using GLib;

namespace Kernel26
{

/**
 * @class Kernel26.RfKillPowerControl
 *
 * Implementing org.freesmartphone.Device.PowerControl via Linux 2.6 rfkill API
 **/
class RfKillPowerControl : FsoDevice.ISimplePowerControl, FreeSmartphone.Device.PowerControl, FsoFramework.AbstractObject
{
    const string[] opValue = { "Add", "Del", "Change", "ChangeAll", "unknown:4", "unknown:5", "unknown:6" };
    const string[] typeValue = { "All", "WiFi", "Bluetooth", "UWB", "WiMax", "WWan", "GPS", "FM" };

    private uint id;
    private string type;
    private bool softoff;
    private bool hardoff;

    /* not forking into background gives a reliable pid(and also prints to stderr/stdout). */
    private const string[] bluetoothd = { "/usr/sbin/bluetoothd", "-n" };
    private int bluetoothd_pid = 0;
    private string bluetoothd_startup_handler;
    private string wifi_iface;

    private FsoDevice.BasePowerControlResource resource;

    private RfKillPowerControl( uint id, Linux.RfKillType type, bool softoff, bool hardoff )
    {
        this.id = id;

        switch ( type )
        {
            case Linux.RfKillType.WLAN:
                this.wifi_iface = config.stringValue( "fsodevice.kernel26_rfkill", "wifi_interface", "wlan0" );
                this.type = "WiFi";
                break;
            case Linux.RfKillType.BLUETOOTH:
                bluetoothd_startup_handler = config.stringValue( "fsodevice.kernel26_rfkill", "bluetoothd_startup_handler","fsodeviced" );
                this.type = "Bluetooth";
                break;
            case Linux.RfKillType.UWB:
                this.type = "UWB";
                break;
            case Linux.RfKillType.WIMAX:
                this.type = "WiMax";
                break;
            case Linux.RfKillType.WWAN:
                this.type = "WWan";
                break;
            case 0x6:
                this.type = "GPS";
                break;
            case 0x7:
                this.type = "FM";
                break;
            default:
                logger.warning( "Unknown RfKillType %u - please report" );
                this.type = "unknown:%u".printf( (uint)type );
                break;
        }

        this.softoff = softoff;
        this.hardoff = hardoff;

        subsystem.registerObjectForServiceWithPrefix<FreeSmartphone.Device.PowerControl>( FsoFramework.Device.ServiceDBusName,
            FsoFramework.Device.PowerControlServicePath, this );

#if WANT_FSO_RESOURCE
        Idle.add( () => {
            this.resource = new FsoDevice.BasePowerControlResource( this, this.type, subsystem );
            return false;
        } );
#endif
        logger.info( "created." );
    }

    public override string repr()
    {
        return "<%u:%s:soft%s:hard%s>".printf( id, type, softoff ? "off":"on", hardoff ? "off":"on" );
    }

    private void init()
    {
        if ( fd != -1 )
        {
            return;
        }
        fd = Posix.open( Path.build_filename( devfs_root, "rfkill" ), Posix.O_RDWR );
        if ( fd == -1 )
        {
            logger.error( @"Can't open $devfs_root: $(strerror(errno)); rfkill plugin will not be operating" );
            return;
        }
        channel = new IOChannel.unix_new( fd );
        watch = channel.add_watch( IOCondition.IN | IOCondition.HUP, onActionFromRfKill );
    }

    internal static bool onActionFromRfKill( IOChannel source, IOCondition condition )
    {
        if ( ( condition & IOCondition.HUP ) == IOCondition.HUP )
        {
            warning( "HUP on rfkill, will no longer get any notifications" );
            return false;
        }

        if ( ( condition & IOCondition.IN ) == IOCondition.IN )
        {
            assert( fd != -1 );
            var event = Linux.RfKillEvent();
            ssize_t bytesread = Posix.read( fd, &event, sizeof( Linux.RfKillEvent ) );
            if ( bytesread != sizeof( Linux.RfKillEvent ) )
            {
                warning( "can't read full rfkill event, got only %d bytes", (int)bytesread );
                return true;
            }
#if DEBUG
            debug( "onActionFromRfKill: read %d bytes", (int)bytesread );
#endif
            handleEvent( event );
            return true;
        }

        error( "Unsupported IOCondition %u", (int)condition );
        return true;
    }

    protected static void handleEvent( Linux.RfKillEvent event )
    {
#if DEBUG
        debug( "got rfkill event: ID %u, %s, %s, SOFTBLOCK %s, HARDBLOCK %s",
            event.idx,
            typeValue[event.type],
            opValue[event.op],
            event.soft == 1 ? "true" : "false",
            event.hard == 1 ? "true" : "false" );
#endif

        switch ( event.op )
        {
            case Linux.RfKillOp.ADD:
                instances.insert( (int)event.idx, new Kernel26.RfKillPowerControl( event.idx, event.type, event.soft == 1, event.hard == 1 ) );
                break;
            case Linux.RfKillOp.DEL:
                instances.remove( (int)event.idx );
                break;
            case Linux.RfKillOp.CHANGE:
                var instance = instances.lookup( (int)event.idx );
                if ( instance == null )
                {
                    warning( "Got rfkill change event for unknown IDX; ignoring" );
                    return;
                }
                instance.powerChangedTo( event.soft == 1, event.hard == 1 );
                break;
            default:
                error( "unknown rfkill op %u; ignoring", event.op );
                break;
        }
    }

    protected void setup_wifi_interface( bool on )
    {
        try
        {
            var iface = new FsoFramework.Network.WextInterface( wifi_iface );

            if ( on )
            {
                iface.up();
                iface.set_power( true ); // TODO: add config option for that
            }
            else
            {
                iface.down();
            }

            iface.finish();
        }
        catch ( FsoFramework.Network.Error err )
        {
            logger.error( @"%s network interface $(wifi_iface) failed!".printf( on ? "Enabling" : "Disabling" ) );
        }
    }

    protected void start_bluetoothd()
    {
        logger.info("bluetoothd starting...");
        GLib.Process.spawn_async( GLib.Environment.get_variable( "PWD" ),
                                  bluetoothd,
                                  null,
                                  0,
                                  null,
                                  out this.bluetoothd_pid );
        logger.debug(@"bluetoothd pid: $(this.bluetoothd_pid)");
    }

    protected void stop_bluetoothd()
    {
        logger.info("bluetoothd stopping...");
        if ( bluetoothd_pid != 0)
        {
            Posix.kill( (Posix.pid_t)bluetoothd_pid, Posix.SIGKILL );
            logger.debug(@"killing bluetoothd with pid: $(this.bluetoothd_pid)");
        }
    }

    public void powerChangedTo( bool softoff, bool hardoff )
    {
        assert( logger.debug( @"Status changed from..." ) );
        this.softoff = softoff;
        this.hardoff = hardoff;
        assert( logger.debug( @"... to" ) );
        //FIXME: Send DBus signal on power change?
    }

    public bool getPower()
    {
        return ( this.hardoff ) ? false : !this.softoff;
    }

    public void setPower( bool on )
    {

        if ( (bluetoothd_startup_handler == "fsodeviced" ) && ( this.type == "Bluetooth" )
             && ( on == false ) )
        {
            stop_bluetoothd();
        }

        var event = Linux.RfKillEvent() {
            idx   = this.id,
            op    = Linux.RfKillOp.CHANGE,
            soft  = (uint8)(!on) };

        var bwritten = Posix.write( fd, &event, sizeof( Linux.RfKillEvent ) );
        if ( bwritten == -1 )
        {
            logger.error( @"Could not write rfkill event: $(strerror(errno))" );
        }

        if (this.type == "WiFi")
        {
            this.setup_wifi_interface( on );
        }
        else if ( ( bluetoothd_startup_handler == "fsodeviced" ) && ( this.type == "Bluetooth" )
             && ( on == true ) )
        {
            start_bluetoothd();
        }
    }

    //
    // DBUS API (org.freesmartphone.Device.PowerControl)
    //
    public async bool get_power() throws DBusError, IOError
    {
        return getPower();
    }

    public async void set_power( bool on ) throws DBusError, IOError
    {
        setPower( on );
    }
}
} /* namespace */

internal HashTable<int,Kernel26.RfKillPowerControl> instances;
internal static string sysfs_root;
internal static string devfs_root;
internal weak FsoFramework.Subsystem subsystem;

internal static int fd;
internal static uint watch;
internal static IOChannel channel;

/**
 * This function gets called on plugin initialization time.
 * @return the name of your plugin here
 * @note that it needs to be a name in the format <subsystem>.<plugin>
 * else your module will be unloaded immediately.
 **/
public static string fso_factory_function( FsoFramework.Subsystem system ) throws Error
{
    instances = new HashTable<int,Kernel26.RfKillPowerControl>( direct_hash, direct_equal );

    subsystem = system;
    devfs_root = FsoFramework.theConfig.stringValue( "cornucopia", "devfs_root", "/dev" );

    fd = Posix.open( Path.build_filename( devfs_root, "rfkill" ), Posix.O_RDWR );
    if ( fd == -1 )
    {
        FsoFramework.theLogger.error( @"Can't open $devfs_root/rfkill: $(strerror(errno)); rfkill plugin will not be operating" );
    }
    else
    {
        channel = new IOChannel.unix_new( fd );
        watch = channel.add_watch( IOCondition.IN | IOCondition.HUP, Kernel26.RfKillPowerControl.onActionFromRfKill );
    }

    return "fsodevice.kernel26_rfkill";
}

[ModuleInit]
public static void fso_register_function( TypeModule module )
{
    FsoFramework.theLogger.debug( "fsodevice.kernel26_rfkill fso_register_function()" );
}

/**
 * This function gets called on plugin load time.
 * @return false, if the plugin operating conditions are present.
 * @note Some versions of glib contain a bug that leads to a SIGSEGV
 * in g_module_open, if you return true here.
 **/
/*public static bool g_module_check_init( void* m )
{
    var ok = FsoFramework.FileHandling.isPresent( Kernel26.SYS_CLASS_LEDS );
    return (!ok);
}
*/

// vim:ts=4:sw=4:expandtab
