/* plugin.c generated by valac 0.14.2, the Vala compiler
 * generated from plugin.vala, do not modify */

/*
 * Copyright (C) 2011 Simon Busch <morphis@gravedo.de>
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
#include <stdlib.h>
#include <string.h>
#include <fsobasics.h>
#include <fsoframework.h>


#define HERRING_TYPE_RESUME_HANDLER (herring_resume_handler_get_type ())
#define HERRING_RESUME_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), HERRING_TYPE_RESUME_HANDLER, HerringResumeHandler))
#define HERRING_RESUME_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), HERRING_TYPE_RESUME_HANDLER, HerringResumeHandlerClass))
#define HERRING_IS_RESUME_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), HERRING_TYPE_RESUME_HANDLER))
#define HERRING_IS_RESUME_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), HERRING_TYPE_RESUME_HANDLER))
#define HERRING_RESUME_HANDLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), HERRING_TYPE_RESUME_HANDLER, HerringResumeHandlerClass))

typedef struct _HerringResumeHandler HerringResumeHandler;
typedef struct _HerringResumeHandlerClass HerringResumeHandlerClass;

#define HERRING_TYPE_ALSA_STREAM_KEEPER (herring_alsa_stream_keeper_get_type ())
#define HERRING_ALSA_STREAM_KEEPER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), HERRING_TYPE_ALSA_STREAM_KEEPER, HerringAlsaStreamKeeper))
#define HERRING_ALSA_STREAM_KEEPER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), HERRING_TYPE_ALSA_STREAM_KEEPER, HerringAlsaStreamKeeperClass))
#define HERRING_IS_ALSA_STREAM_KEEPER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), HERRING_TYPE_ALSA_STREAM_KEEPER))
#define HERRING_IS_ALSA_STREAM_KEEPER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), HERRING_TYPE_ALSA_STREAM_KEEPER))
#define HERRING_ALSA_STREAM_KEEPER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), HERRING_TYPE_ALSA_STREAM_KEEPER, HerringAlsaStreamKeeperClass))

typedef struct _HerringAlsaStreamKeeper HerringAlsaStreamKeeper;
typedef struct _HerringAlsaStreamKeeperClass HerringAlsaStreamKeeperClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))


extern HerringResumeHandler* resumehandler;
HerringResumeHandler* resumehandler = NULL;
extern HerringAlsaStreamKeeper* streamkeeper;
HerringAlsaStreamKeeper* streamkeeper = NULL;

#define HERRING_MODULE_NAME "fsodevice.herring_quirks"
GType herring_resume_handler_get_type (void) G_GNUC_CONST;
GType herring_resume_handler_register_type (GTypeModule * module);
GType herring_alsa_stream_keeper_get_type (void) G_GNUC_CONST;
GType herring_alsa_stream_keeper_register_type (GTypeModule * module);
gchar* fso_factory_function (FsoFrameworkSubsystem* subsystem, GError** error);
HerringResumeHandler* herring_resume_handler_new (void);
HerringResumeHandler* herring_resume_handler_construct (GType object_type);
HerringAlsaStreamKeeper* herring_alsa_stream_keeper_new (void);
HerringAlsaStreamKeeper* herring_alsa_stream_keeper_construct (GType object_type);
void fso_register_function (GTypeModule* module);


/**
 * This function gets called on plugin initialization time.
 * @return the name of your plugin here
 * @note that it needs to be a name in the format <subsystem>.<plugin>
 * else your module will be unloaded immediately.
 **/
static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


gchar* fso_factory_function (FsoFrameworkSubsystem* subsystem, GError** error) {
	gchar* result = NULL;
	FsoFrameworkSmartKeyFile* _tmp0_;
	FsoFrameworkSmartKeyFile* _tmp1_;
	FsoFrameworkSmartKeyFile* config;
	gchar* _tmp2_ = NULL;
	gchar* sysfs_root;
	HerringResumeHandler* _tmp3_;
	HerringAlsaStreamKeeper* _tmp4_;
	gchar* _tmp5_;
	g_return_val_if_fail (subsystem != NULL, NULL);
	_tmp0_ = fso_framework_theConfig;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	config = _tmp1_;
	_tmp2_ = fso_framework_smart_key_file_stringValue (config, "cornucopia", "sysfs_root", "/sys");
	sysfs_root = _tmp2_;
	_tmp3_ = herring_resume_handler_new ();
	_g_object_unref0 (resumehandler);
	resumehandler = _tmp3_;
	_tmp4_ = herring_alsa_stream_keeper_new ();
	_g_object_unref0 (streamkeeper);
	streamkeeper = _tmp4_;
	_tmp5_ = g_strdup (HERRING_MODULE_NAME);
	result = _tmp5_;
	_g_free0 (sysfs_root);
	_g_object_unref0 (config);
	return result;
}


void fso_register_function (GTypeModule* module) {
	FsoFrameworkLogger* _tmp0_;
	g_return_if_fail (module != NULL);
	herring_resume_handler_register_type (module);
	herring_alsa_stream_keeper_register_type (module);
	_tmp0_ = fso_framework_theLogger;
	fso_framework_logger_debug (_tmp0_, "fsodevice.herring_quirks fso_register_function()");
}



