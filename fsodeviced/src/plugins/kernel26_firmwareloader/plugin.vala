/*
 * Copyright (C) 2009-2010 Michael 'Mickey' Lauer <mlauer@vanille-media.de>
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
    internal const string FIRMWARE_PATH = "/lib/firmware";
/**
 * @class Kernel26.FirmwareLoader
 *
 * Implementing the Linux 2.6 firmwareloader API
 **/
internal class FirmwareLoader : FsoFramework.AbstractObject
{
    public FirmwareLoader()
    {
        logger.info( "Created." );
    }

    public override string repr()
    {
        return "<>";
    }
}
} /* namespace */

internal Kernel26.FirmwareLoader instance;
internal static string sysfs_root;
internal weak FsoFramework.Subsystem subsystem;

/**
 * This function gets called on plugin initialization time.
 * @return the name of your plugin here
 * @note that it needs to be a name in the format <subsystem>.<plugin>
 * else your module will be unloaded immediately.
 **/
public static string fso_factory_function( FsoFramework.Subsystem system ) throws Error
{
    subsystem = system;
    // grab sysfs paths
    var config = FsoFramework.theConfig;
    sysfs_root = config.stringValue( "cornucopia", "sysfs_root", "/sys" );

    instance = new Kernel26.FirmwareLoader();

    return "fsodevice.kernel26_firmwareloader";
}

[ModuleInit]
public static void fso_register_function( TypeModule module )
{
    FsoFramework.theLogger.debug( "fsodevice.kernel26_firmwareloader fso_register_function()" );
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
