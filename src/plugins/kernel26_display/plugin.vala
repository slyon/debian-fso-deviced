/*
 * (C) 2009-2011 Michael 'Mickey' Lauer <mlauer@vanille-media.de>
 * (C) 2009 Sudharshan "Sup3rkiddo" S <sudharsh@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

using GLib;

namespace Kernel26
{

internal const string DISPLAY_PLUGIN_NAME = "fsodevice.kernel26_display";
internal const double DISPLAY_SMOOTH_PERIOD = 1 * 0.7; // seconds
internal const double DISPLAY_SMOOTH_STEP =  1 * 0.03; // seconds

class Display : FreeSmartphone.Device.Display,
                FreeSmartphone.Info,
                FsoFramework.AbstractObject
{
    private FsoFramework.Subsystem subsystem;
    private static uint counter;
    private bool smoothup;
    private bool smoothdown;
    private bool smoothInProgress = false;

    private int max_brightness;
    private int current_brightness;
    private string sysfsnode;
    private int fb_fd = -1;

    private const int FBIOBLANK = 0x4611;
    private const int FB_BLANK_UNBLANK = 0;
    private const int FB_BLANK_POWERDOWN = 4;

    public Display( FsoFramework.Subsystem subsystem, string sysfsnode )
    {
        this.subsystem = subsystem;
        this.sysfsnode = sysfsnode;
        this.max_brightness = FsoFramework.FileHandling.read( this.sysfsnode + "/max_brightness" ).to_int();

        this.current_brightness = _getBrightness();

        fb_fd = Posix.open( dev_fb0, Posix.O_RDONLY );
        if ( fb_fd == -1 )
            logger.warning( @"Can't open $dev_fb0 ($(strerror(errno))). Full display power control not available." );

        var smooth = config.stringValue( DISPLAY_PLUGIN_NAME, "smooth", "none" ).down();
        smoothup = smooth in new string[] { "up", "always" };
        smoothdown = smooth in new string[] { "down", "always" };

        debug( @"smoothup = $smoothup, smoothdown = $smoothdown" );

        subsystem.registerObjectForService<FreeSmartphone.Device.Display>( FsoFramework.Device.ServiceDBusName, "%s/%u".printf( FsoFramework.Device.DisplayServicePath, counter ), this );
        subsystem.registerObjectForService<FreeSmartphone.Info>( FsoFramework.Device.ServiceDBusName, "%s/%u".printf( FsoFramework.Device.DisplayServicePath, counter++ ), this );

        logger.info( @"Created w/ max brightness = $max_brightness, smooth up = $smoothup, smooth down = $smoothdown" );
    }

    public override string repr()
    {
        return @"<$sysfsnode>";
    }

    private void _setBacklightPower( bool on )
    {
        var value = on ? "0" : "1";
        FsoFramework.FileHandling.write( value, this.sysfsnode + "/bl_power" );

        if ( fb_fd != -1 )
        {
            Linux.ioctl( fb_fd, FBIOBLANK, on ? FB_BLANK_UNBLANK : FB_BLANK_POWERDOWN );
        }

        this.backlight_power( on ); // DBUS SIGNAL
    }

    private int _valueToPercent( int value )
    {
        double max = max_brightness;
        double v = value;
        return (int)(100.0 / max * v);
    }

    private int _percentToValue( int percent )
    {
        double p = percent;
        double max = max_brightness;
        double value;
        if ( percent >= 100 )
            value = max_brightness;
        else if ( percent <= 0 )
            value = 0;
        else
            value = p / 100.0 * max;
        return (int)value;
    }

    private int _getBrightness()
    {
        var value = FsoFramework.FileHandling.read( this.sysfsnode + "/actual_brightness" ).to_int();
        return _valueToPercent( value );
    }

    private async void _setBrightnessSoft( int brightness )
    {
        if ( current_brightness == 0 ) // previously we were off
        {
            _setBacklightPower( true );
        }

        smoothInProgress = true;

        double current = current_brightness;
        double interval = brightness - current_brightness;

        for ( double dt = 0; dt < DISPLAY_SMOOTH_PERIOD; dt += DISPLAY_SMOOTH_STEP )
        {
            double x = dt/DISPLAY_SMOOTH_PERIOD;
            double fx = ( interval > 0 ) ? x * x * x : (1-x) * (1-x) * (1-x);
            double val = ( interval > 0 ) ? ( current + ( fx * interval ) ) : ( current + ( (1-fx) * interval ) ); // may want to shift 7+current...
#if DEBUG
            message( "x = %.2f, fx = %.2f (val = %.2f)", x, fx, val );
#endif
            if ( !smoothInProgress ) // check whether someone else wants to interrupt us
            {
                return;
            }

            FsoFramework.FileHandling.write( ( (int)Math.round( val ) ).to_string(), this.sysfsnode + "/brightness" );
            current_brightness = brightness;
            Timeout.add( (int)(DISPLAY_SMOOTH_STEP * 1000), _setBrightnessSoft.callback );
            yield;
        }

        FsoFramework.FileHandling.write( brightness.to_string(), this.sysfsnode + "/brightness" );
        current_brightness = brightness;
        assert( logger.debug( @"Brightness set to $brightness [soft]" ) );

        if ( brightness == 0 ) // now we are off
        {
            _setBacklightPower( false );
        }
        smoothInProgress = false;
    }

    private void _setBrightness( int brightness )
    {
        if ( current_brightness == brightness )
        {
            return;
        }

        if ( ( current_brightness < brightness ) && smoothup )
        {
            _setBrightnessSoft( brightness );
            return;
        }

        if ( ( current_brightness > brightness ) && smoothdown )
        {
            _setBrightnessSoft( brightness );
            return;
        }
#if DEBUG
        message( "interrupting smooth in progress (if any)" );
#endif
        smoothInProgress = false; // signalize to stop any smoothing in progress
        FsoFramework.FileHandling.write( brightness.to_string(), this.sysfsnode + "/brightness" );

        if ( current_brightness == 0 ) // previously we were off
        {
            _setBacklightPower( true );
        }
        else if ( brightness == 0 ) // now we are off
        {
            _setBacklightPower( false );
        }
        current_brightness = brightness;

        assert( logger.debug( @"Brightness set to $brightness [hard]" ) );
    }

    //
    // FreeSmartphone.Info (DBUS API)
    //
    public async HashTable<string,Variant> get_info() throws DBusError, IOError
    {
        string _leaf;
        Variant val;
        HashTable<string,Variant> info_table = new HashTable<string,Variant>( str_hash, str_equal );
        /* Just read all the files in the sysfs path and return it as a{ss} */
        try
        {
            Dir dir = Dir.open( this.sysfsnode, 0 );
            while ((_leaf = dir.read_name()) != null)
            {
                if( FileUtils.test (this.sysfsnode + "/" + _leaf, FileTest.IS_REGULAR) && _leaf != "uevent" )
                {
                    val = FsoFramework.FileHandling.read(this.sysfsnode + "/" + _leaf ).strip();
                    info_table.insert( _leaf, val );
                }
            }
        }
        catch ( GLib.Error error )
        {
            logger.warning( error.message );
        }
        return info_table;
    }

    //
    // FreeSmartphone.Device.Display (DBUS API)
    //
    public async void set_brightness( int brightness )
    {
        _setBrightness( _percentToValue( brightness ) );
    }

    public async int get_brightness()
    {
        return _getBrightness();
    }

    public async bool get_backlight_power()
    {
        return FsoFramework.FileHandling.read( this.sysfsnode + "/bl_power" ).to_int() == 0;
    }

    public async void set_backlight_power( bool power )
    {
        _setBacklightPower( power );
    }
}

}

static string dev_fb0;
static string sys_class_backlight;
List<Kernel26.Display> instances;

public static string fso_factory_function( FsoFramework.Subsystem subsystem ) throws Error
{
    // grab sysfs and dev paths
    var config = FsoFramework.theConfig;
    var sysfs_root = config.stringValue( "cornucopia", "sysfs_root", "/sys" );
    sys_class_backlight = "%s/class/backlight".printf( sysfs_root );
    var dev_root = config.stringValue( "cornucopia", "dev_root", "/dev" );
    dev_fb0 = "%s/fb0".printf( dev_root );

    // scan sysfs path for leds
    var dir = Dir.open( sys_class_backlight, 0 );
    string entry = dir.read_name();
    while ( entry != null )
    {
        var filename = Path.build_filename( sys_class_backlight, entry );
        instances.append( new Kernel26.Display( subsystem, filename ) );
        entry = dir.read_name();
    }
    return Kernel26.DISPLAY_PLUGIN_NAME;
}


[ModuleInit]
public static void fso_register_function( TypeModule module )
{
    FsoFramework.theLogger.debug( "fsodevice.kernel26_display fso_register_function()" );
}

// vim:ts=4:sw=4:expandtab
