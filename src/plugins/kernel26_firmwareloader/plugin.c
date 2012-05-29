/* plugin.c generated by valac 0.14.2, the Vala compiler
 * generated from plugin.vala, do not modify */

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

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <fsobasics.h>
#include <fsoframework.h>


#define KERNEL26_TYPE_FIRMWARE_LOADER (kernel26_firmware_loader_get_type ())
#define KERNEL26_FIRMWARE_LOADER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), KERNEL26_TYPE_FIRMWARE_LOADER, Kernel26FirmwareLoader))
#define KERNEL26_FIRMWARE_LOADER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), KERNEL26_TYPE_FIRMWARE_LOADER, Kernel26FirmwareLoaderClass))
#define KERNEL26_IS_FIRMWARE_LOADER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), KERNEL26_TYPE_FIRMWARE_LOADER))
#define KERNEL26_IS_FIRMWARE_LOADER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), KERNEL26_TYPE_FIRMWARE_LOADER))
#define KERNEL26_FIRMWARE_LOADER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), KERNEL26_TYPE_FIRMWARE_LOADER, Kernel26FirmwareLoaderClass))

typedef struct _Kernel26FirmwareLoader Kernel26FirmwareLoader;
typedef struct _Kernel26FirmwareLoaderClass Kernel26FirmwareLoaderClass;
typedef struct _Kernel26FirmwareLoaderPrivate Kernel26FirmwareLoaderPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _Kernel26FirmwareLoader {
	FsoFrameworkAbstractObject parent_instance;
	Kernel26FirmwareLoaderPrivate * priv;
};

struct _Kernel26FirmwareLoaderClass {
	FsoFrameworkAbstractObjectClass parent_class;
};

struct _Kernel26FirmwareLoaderPrivate {
	gchar* firmwarePath;
};


static gpointer kernel26_firmware_loader_parent_class = NULL;
extern gchar* sysfs_root;
static GType kernel26_firmware_loader_type_id = 0;
extern Kernel26FirmwareLoader* instance;
Kernel26FirmwareLoader* instance = NULL;
gchar* sysfs_root = NULL;
extern FsoFrameworkSubsystem* subsystem;
FsoFrameworkSubsystem* subsystem = NULL;

#define KERNEL26_MODULE_NAME "fsodevice.kernel26_firmwareloader"
#define KERNEL26_FIRMWARE_PATH_DEFAULT "/lib/firmware"
GType kernel26_firmware_loader_get_type (void) G_GNUC_CONST;
GType kernel26_firmware_loader_register_type (GTypeModule * module);
#define KERNEL26_FIRMWARE_LOADER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), KERNEL26_TYPE_FIRMWARE_LOADER, Kernel26FirmwareLoaderPrivate))
enum  {
	KERNEL26_FIRMWARE_LOADER_DUMMY_PROPERTY
};
Kernel26FirmwareLoader* kernel26_firmware_loader_new (void);
Kernel26FirmwareLoader* kernel26_firmware_loader_construct (GType object_type);
static void kernel26_firmware_loader_onFirmwareUploadRequest (Kernel26FirmwareLoader* self, GHashTable* properties);
static void _kernel26_firmware_loader_onFirmwareUploadRequest_fso_framework_kobject_notifier_func (GHashTable* properties, gpointer self);
static gchar* kernel26_firmware_loader_real_repr (FsoFrameworkAbstractObject* base);
static void kernel26_firmware_loader_finalize (GObject* obj);
gchar* fso_factory_function (FsoFrameworkSubsystem* system, GError** error);
void fso_register_function (GTypeModule* module);


static void _kernel26_firmware_loader_onFirmwareUploadRequest_fso_framework_kobject_notifier_func (GHashTable* properties, gpointer self) {
	kernel26_firmware_loader_onFirmwareUploadRequest (self, properties);
}


Kernel26FirmwareLoader* kernel26_firmware_loader_construct (GType object_type) {
	Kernel26FirmwareLoader * self = NULL;
	FsoFrameworkSmartKeyFile* _tmp0_;
	gchar* _tmp1_ = NULL;
	FsoFrameworkLogger* _tmp2_;
	self = (Kernel26FirmwareLoader*) fso_framework_abstract_object_construct (object_type);
	fso_framework_base_kobject_notifier_addMatch ("add", "firmware", _kernel26_firmware_loader_onFirmwareUploadRequest_fso_framework_kobject_notifier_func, self);
	fso_framework_base_kobject_notifier_addMatch ("add", "compat_firmware", _kernel26_firmware_loader_onFirmwareUploadRequest_fso_framework_kobject_notifier_func, self);
	_tmp0_ = ((FsoFrameworkAbstractObject*) self)->config;
	_tmp1_ = fso_framework_smart_key_file_stringValue (_tmp0_, KERNEL26_MODULE_NAME, "firmware_path", KERNEL26_FIRMWARE_PATH_DEFAULT);
	_g_free0 (self->priv->firmwarePath);
	self->priv->firmwarePath = _tmp1_;
	_tmp2_ = ((FsoFrameworkAbstractObject*) self)->logger;
	fso_framework_logger_info (_tmp2_, "Created.");
	return self;
}


Kernel26FirmwareLoader* kernel26_firmware_loader_new (void) {
	return kernel26_firmware_loader_construct (KERNEL26_TYPE_FIRMWARE_LOADER);
}


static gchar* kernel26_firmware_loader_real_repr (FsoFrameworkAbstractObject* base) {
	Kernel26FirmwareLoader * self;
	gchar* result = NULL;
	gchar* _tmp0_;
	self = (Kernel26FirmwareLoader*) base;
	_tmp0_ = g_strdup ("<>");
	result = _tmp0_;
	return result;
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


static void kernel26_firmware_loader_onFirmwareUploadRequest (Kernel26FirmwareLoader* self, GHashTable* properties) {
	GHashTable* _tmp0_;
	gconstpointer _tmp1_ = NULL;
	gchar* _tmp2_;
	gchar* devpath;
	const gchar* _tmp3_;
	GHashTable* _tmp5_;
	gconstpointer _tmp6_ = NULL;
	gchar* _tmp7_;
	gchar* firmware;
	const gchar* _tmp8_;
	const gchar* _tmp10_;
	const gchar* _tmp11_;
	gchar* _tmp12_ = NULL;
	gchar* loading;
	const gchar* _tmp13_;
	const gchar* _tmp14_;
	gchar* _tmp15_ = NULL;
	gchar* data;
	const gchar* _tmp16_;
	const gchar* _tmp17_;
	gchar* _tmp18_ = NULL;
	gchar* sourcepath;
	FsoFrameworkLogger* _tmp37_;
	const gchar* _tmp38_;
	const gchar* _tmp39_ = NULL;
	const gchar* _tmp40_;
	const gchar* _tmp41_ = NULL;
	gchar* _tmp42_ = NULL;
	gchar* _tmp43_;
	GError * _inner_error_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (properties != NULL);
	_tmp0_ = properties;
	_tmp1_ = g_hash_table_lookup (_tmp0_, "DEVPATH");
	_tmp2_ = g_strdup ((const gchar*) _tmp1_);
	devpath = _tmp2_;
	_tmp3_ = devpath;
	if (_tmp3_ == NULL) {
		FsoFrameworkLogger* _tmp4_;
		_tmp4_ = ((FsoFrameworkAbstractObject*) self)->logger;
		fso_framework_logger_error (_tmp4_, "Can't process firmware upload due to missing DEVPATH in kobject notifi" \
"cation");
		_g_free0 (devpath);
		return;
	}
	_tmp5_ = properties;
	_tmp6_ = g_hash_table_lookup (_tmp5_, "FIRMWARE");
	_tmp7_ = g_strdup ((const gchar*) _tmp6_);
	firmware = _tmp7_;
	_tmp8_ = firmware;
	if (_tmp8_ == NULL) {
		FsoFrameworkLogger* _tmp9_;
		_tmp9_ = ((FsoFrameworkAbstractObject*) self)->logger;
		fso_framework_logger_error (_tmp9_, "Can't process firmware upload request due to missing FIRMWARE in kobje" \
"ct notification");
		_g_free0 (firmware);
		_g_free0 (devpath);
		return;
	}
	_tmp10_ = sysfs_root;
	_tmp11_ = devpath;
	_tmp12_ = g_build_filename (_tmp10_, _tmp11_, "loading", NULL);
	loading = _tmp12_;
	_tmp13_ = sysfs_root;
	_tmp14_ = devpath;
	_tmp15_ = g_build_filename (_tmp13_, _tmp14_, "data", NULL);
	data = _tmp15_;
	_tmp16_ = self->priv->firmwarePath;
	_tmp17_ = firmware;
	_tmp18_ = g_build_filename (_tmp16_, _tmp17_, NULL);
	sourcepath = _tmp18_;
	{
		const gchar* _tmp19_;
		const gchar* _tmp20_;
		gint _tmp21_ = 0;
		guint8* _tmp22_ = NULL;
		guint8* blob;
		gint blob_length1;
		gint _blob_size_;
		guint8* _tmp23_;
		gint _tmp23__length1;
		const gchar* _tmp24_;
		const gchar* _tmp25_;
		_tmp19_ = loading;
		fso_framework_file_handling_write ("1\n", _tmp19_, FALSE);
		_tmp20_ = sourcepath;
		_tmp22_ = fso_framework_file_handling_readContentsOfFile (_tmp20_, &_tmp21_, &_inner_error_);
		blob = _tmp22_;
		blob_length1 = _tmp21_;
		_blob_size_ = blob_length1;
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_FILE_ERROR) {
				goto __catch0_g_file_error;
			}
			_g_free0 (sourcepath);
			_g_free0 (data);
			_g_free0 (loading);
			_g_free0 (firmware);
			_g_free0 (devpath);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
		_tmp23_ = blob;
		_tmp23__length1 = blob_length1;
		_tmp24_ = data;
		fso_framework_file_handling_writeContentsToFile (_tmp23_, _tmp23__length1, _tmp24_, &_inner_error_);
		if (_inner_error_ != NULL) {
			blob = (g_free (blob), NULL);
			if (_inner_error_->domain == G_FILE_ERROR) {
				goto __catch0_g_file_error;
			}
			blob = (g_free (blob), NULL);
			_g_free0 (sourcepath);
			_g_free0 (data);
			_g_free0 (loading);
			_g_free0 (firmware);
			_g_free0 (devpath);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
		_tmp25_ = loading;
		fso_framework_file_handling_write ("0\n", _tmp25_, FALSE);
		blob = (g_free (blob), NULL);
	}
	goto __finally0;
	__catch0_g_file_error:
	{
		GError* e = NULL;
		FsoFrameworkLogger* _tmp26_;
		const gchar* _tmp27_;
		const gchar* _tmp28_ = NULL;
		const gchar* _tmp29_;
		const gchar* _tmp30_ = NULL;
		GError* _tmp31_;
		const gchar* _tmp32_;
		const gchar* _tmp33_ = NULL;
		gchar* _tmp34_ = NULL;
		gchar* _tmp35_;
		const gchar* _tmp36_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp26_ = ((FsoFrameworkAbstractObject*) self)->logger;
		_tmp27_ = sourcepath;
		_tmp28_ = string_to_string (_tmp27_);
		_tmp29_ = data;
		_tmp30_ = string_to_string (_tmp29_);
		_tmp31_ = e;
		_tmp32_ = _tmp31_->message;
		_tmp33_ = string_to_string (_tmp32_);
		_tmp34_ = g_strconcat ("Could not upload firmware ", _tmp28_, " to ", _tmp30_, ": ", _tmp33_, NULL);
		_tmp35_ = _tmp34_;
		fso_framework_logger_error (_tmp26_, _tmp35_);
		_g_free0 (_tmp35_);
		_tmp36_ = loading;
		fso_framework_file_handling_write ("-1\n", _tmp36_, FALSE);
		_g_error_free0 (e);
		_g_free0 (sourcepath);
		_g_free0 (data);
		_g_free0 (loading);
		_g_free0 (firmware);
		_g_free0 (devpath);
		return;
	}
	__finally0:
	if (_inner_error_ != NULL) {
		_g_free0 (sourcepath);
		_g_free0 (data);
		_g_free0 (loading);
		_g_free0 (firmware);
		_g_free0 (devpath);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp37_ = ((FsoFrameworkAbstractObject*) self)->logger;
	_tmp38_ = sourcepath;
	_tmp39_ = string_to_string (_tmp38_);
	_tmp40_ = data;
	_tmp41_ = string_to_string (_tmp40_);
	_tmp42_ = g_strconcat ("Successfully uploaded firmware ", _tmp39_, " to ", _tmp41_, NULL);
	_tmp43_ = _tmp42_;
	fso_framework_logger_info (_tmp37_, _tmp43_);
	_g_free0 (_tmp43_);
	_g_free0 (sourcepath);
	_g_free0 (data);
	_g_free0 (loading);
	_g_free0 (firmware);
	_g_free0 (devpath);
}


static void kernel26_firmware_loader_class_init (Kernel26FirmwareLoaderClass * klass) {
	kernel26_firmware_loader_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (Kernel26FirmwareLoaderPrivate));
	FSO_FRAMEWORK_ABSTRACT_OBJECT_CLASS (klass)->repr = kernel26_firmware_loader_real_repr;
	G_OBJECT_CLASS (klass)->finalize = kernel26_firmware_loader_finalize;
}


static void kernel26_firmware_loader_instance_init (Kernel26FirmwareLoader * self) {
	self->priv = KERNEL26_FIRMWARE_LOADER_GET_PRIVATE (self);
}


static void kernel26_firmware_loader_finalize (GObject* obj) {
	Kernel26FirmwareLoader * self;
	self = KERNEL26_FIRMWARE_LOADER (obj);
	_g_free0 (self->priv->firmwarePath);
	G_OBJECT_CLASS (kernel26_firmware_loader_parent_class)->finalize (obj);
}


/**
 * @class Kernel26.FirmwareLoader
 *
 * Implementing the Linux 2.6 firmwareloader API
 **/
GType kernel26_firmware_loader_get_type (void) {
	return kernel26_firmware_loader_type_id;
}


GType kernel26_firmware_loader_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (Kernel26FirmwareLoaderClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) kernel26_firmware_loader_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Kernel26FirmwareLoader), 0, (GInstanceInitFunc) kernel26_firmware_loader_instance_init, NULL };
	kernel26_firmware_loader_type_id = g_type_module_register_type (module, FSO_FRAMEWORK_TYPE_ABSTRACT_OBJECT, "Kernel26FirmwareLoader", &g_define_type_info, 0);
	return kernel26_firmware_loader_type_id;
}


/**
 * This function gets called on plugin initialization time.
 * @return the name of your plugin here
 * @note that it needs to be a name in the format <subsystem>.<plugin>
 * else your module will be unloaded immediately.
 **/
static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


gchar* fso_factory_function (FsoFrameworkSubsystem* system, GError** error) {
	gchar* result = NULL;
	FsoFrameworkSubsystem* _tmp0_;
	FsoFrameworkSmartKeyFile* _tmp1_;
	FsoFrameworkSmartKeyFile* _tmp2_;
	FsoFrameworkSmartKeyFile* config;
	gchar* _tmp3_ = NULL;
	Kernel26FirmwareLoader* _tmp4_;
	gchar* _tmp5_;
	g_return_val_if_fail (system != NULL, NULL);
	_tmp0_ = system;
	subsystem = _tmp0_;
	_tmp1_ = fso_framework_theConfig;
	_tmp2_ = _g_object_ref0 (_tmp1_);
	config = _tmp2_;
	_tmp3_ = fso_framework_smart_key_file_stringValue (config, "cornucopia", "sysfs_root", "/sys");
	_g_free0 (sysfs_root);
	sysfs_root = _tmp3_;
	_tmp4_ = kernel26_firmware_loader_new ();
	_g_object_unref0 (instance);
	instance = _tmp4_;
	_tmp5_ = g_strdup ("fsodevice.kernel26_firmwareloader");
	result = _tmp5_;
	_g_object_unref0 (config);
	return result;
}


void fso_register_function (GTypeModule* module) {
	FsoFrameworkLogger* _tmp0_;
	g_return_if_fail (module != NULL);
	kernel26_firmware_loader_register_type (module);
	_tmp0_ = fso_framework_theLogger;
	fso_framework_logger_debug (_tmp0_, "fsodevice.kernel26_firmwareloader fso_register_function()");
}


