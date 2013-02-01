/* main.c generated by valac 0.16.1, the Vala compiler
 * generated from main.vala, do not modify */

/*
 * Copyright (C) 2009-2012 Michael 'Mickey' Lauer <mlauer@vanille-media.de>
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

#include <glib.h>
#include <glib-object.h>
#include <fsoframework.h>
#include <signal.h>
#include <fsobasics.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <config.h>
#include <gio/gio.h>

#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_option_context_free0(var) ((var == NULL) ? NULL : (var = (g_option_context_free (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_main_loop_unref0(var) ((var == NULL) ? NULL : (var = (g_main_loop_unref (var), NULL)))


extern GMainLoop* mainloop;
GMainLoop* mainloop = NULL;
extern FsoFrameworkSubsystem* subsystem;
FsoFrameworkSubsystem* subsystem = NULL;
extern gboolean use_session_bus;
gboolean use_session_bus = FALSE;
extern gboolean show_version;
gboolean show_version = FALSE;

void sighandler (gint signum);
gint _vala_main (gchar** args, int args_length1);
static void _sighandler_sighandler_t (gint signal);

const GOptionEntry options[3] = {{"test", 't', 0, G_OPTION_ARG_NONE, &use_session_bus, "Operate on DBus session bus for testing purpose", NULL}, {"version", 'v', 0, G_OPTION_ARG_NONE, &show_version, "Display version number", NULL}, {NULL}};

void sighandler (gint signum) {
	gint _tmp0_;
	FsoFrameworkLogger* _tmp1_;
	gint _tmp2_;
	gchar* _tmp3_ = NULL;
	gchar* _tmp4_;
	GMainLoop* _tmp5_;
	_tmp0_ = signum;
	signal (_tmp0_, NULL);
	_tmp1_ = fso_framework_theLogger;
	_tmp2_ = signum;
	_tmp3_ = g_strdup_printf ("received signal -%d, exiting.", _tmp2_);
	_tmp4_ = _tmp3_;
	fso_framework_logger_info (_tmp1_, _tmp4_);
	_g_free0 (_tmp4_);
	_tmp5_ = mainloop;
	g_main_loop_quit (_tmp5_);
}


static void _sighandler_sighandler_t (gint signal) {
	sighandler (signal);
}


gint _vala_main (gchar** args, int args_length1) {
	gint result = 0;
	gboolean _tmp12_;
	GBusType _tmp16_ = 0;
	gboolean _tmp17_;
	GBusType _tmp18_;
	GBusType bus_type;
	GBusType _tmp19_;
	FsoFrameworkDBusSubsystem* _tmp20_;
	FsoFrameworkSubsystem* _tmp21_;
	FsoFrameworkSubsystem* _tmp22_;
	guint _tmp23_ = 0U;
	guint count;
	FsoFrameworkLogger* _tmp24_;
	guint _tmp25_;
	gchar* _tmp26_ = NULL;
	gchar* _tmp27_;
	guint _tmp28_;
	FsoFrameworkLogger* _tmp33_;
	GError * _inner_error_ = NULL;
	{
		GOptionContext* _tmp0_;
		GOptionContext* opt_context;
		GOptionContext* _tmp1_;
		GOptionContext* _tmp2_;
		GOptionContext* _tmp3_;
		GOptionContext* _tmp4_;
		GOptionContext* _tmp5_;
		_tmp0_ = g_option_context_new ("");
		opt_context = _tmp0_;
		_tmp1_ = opt_context;
		g_option_context_set_summary (_tmp1_, "FreeSmartphone.org Device daemon");
		_tmp2_ = opt_context;
		g_option_context_set_description (_tmp2_, "This daemon implements the freesmartphone.org Device API");
		_tmp3_ = opt_context;
		g_option_context_set_help_enabled (_tmp3_, TRUE);
		_tmp4_ = opt_context;
		g_option_context_add_main_entries (_tmp4_, options, NULL);
		_tmp5_ = opt_context;
		g_option_context_parse (_tmp5_, &args_length1, &args, &_inner_error_);
		if (_inner_error_ != NULL) {
			_g_option_context_free0 (opt_context);
			if (_inner_error_->domain == G_OPTION_ERROR) {
				goto __catch0_g_option_error;
			}
			_g_option_context_free0 (opt_context);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return 0;
		}
		_g_option_context_free0 (opt_context);
	}
	goto __finally0;
	__catch0_g_option_error:
	{
		GError* e = NULL;
		FILE* _tmp6_;
		GError* _tmp7_;
		const gchar* _tmp8_;
		FILE* _tmp9_;
		gchar** _tmp10_;
		gint _tmp10__length1;
		const gchar* _tmp11_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp6_ = stdout;
		_tmp7_ = e;
		_tmp8_ = _tmp7_->message;
		fprintf (_tmp6_, "%s\n", _tmp8_);
		_tmp9_ = stdout;
		_tmp10_ = args;
		_tmp10__length1 = args_length1;
		_tmp11_ = _tmp10_[0];
		fprintf (_tmp9_, "Run '%s --help' to see a full list of available command line options.\n", _tmp11_);
		result = 1;
		_g_error_free0 (e);
		return result;
	}
	__finally0:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return 0;
	}
	_tmp12_ = show_version;
	if (_tmp12_) {
		FILE* _tmp13_;
		gchar* _tmp14_ = NULL;
		gchar* _tmp15_;
		_tmp13_ = stdout;
		_tmp14_ = g_strdup_printf ("fsodeviced %s\n", PACKAGE_VERSION);
		_tmp15_ = _tmp14_;
		fprintf (_tmp13_, "%s", _tmp15_);
		_g_free0 (_tmp15_);
		result = 1;
		return result;
	}
	_tmp17_ = use_session_bus;
	if (_tmp17_) {
		_tmp16_ = G_BUS_TYPE_SESSION;
	} else {
		_tmp16_ = G_BUS_TYPE_SYSTEM;
	}
	_tmp18_ = _tmp16_;
	bus_type = _tmp18_;
	_tmp19_ = bus_type;
	_tmp20_ = fso_framework_dbus_subsystem_new ("fsodevice", _tmp19_);
	_g_object_unref0 (subsystem);
	subsystem = (FsoFrameworkSubsystem*) _tmp20_;
	_tmp21_ = subsystem;
	fso_framework_subsystem_registerPlugins (_tmp21_);
	_tmp22_ = subsystem;
	_tmp23_ = fso_framework_subsystem_loadPlugins (_tmp22_);
	count = _tmp23_;
	_tmp24_ = fso_framework_theLogger;
	_tmp25_ = count;
	_tmp26_ = g_strdup_printf ("loaded %u plugins", _tmp25_);
	_tmp27_ = _tmp26_;
	fso_framework_logger_info (_tmp24_, _tmp27_);
	_g_free0 (_tmp27_);
	_tmp28_ = count;
	if (_tmp28_ > ((guint) 0)) {
		GMainLoop* _tmp29_;
		FsoFrameworkLogger* _tmp30_;
		GMainLoop* _tmp31_;
		FsoFrameworkLogger* _tmp32_;
		_tmp29_ = g_main_loop_new (NULL, FALSE);
		_g_main_loop_unref0 (mainloop);
		mainloop = _tmp29_;
		_tmp30_ = fso_framework_theLogger;
		fso_framework_logger_info (_tmp30_, "fsodeviced => mainloop");
		signal (SIGINT, _sighandler_sighandler_t);
		signal (SIGTERM, _sighandler_sighandler_t);
		_tmp31_ = mainloop;
		g_main_loop_run (_tmp31_);
		_tmp32_ = fso_framework_theLogger;
		fso_framework_logger_info (_tmp32_, "mainloop => fsodeviced");
	}
	_tmp33_ = fso_framework_theLogger;
	fso_framework_logger_info (_tmp33_, "fsodeviced shutdown.");
	result = 0;
	return result;
}


int main (int argc, char ** argv) {
	g_type_init ();
	return _vala_main (argv, argc);
}



