/* powercontrol.c generated by valac 0.16.1, the Vala compiler
 * generated from powercontrol.vala, do not modify */

/*
 * Copyright (C) 2012 Simon Busch <morphis@gravedo.de>
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
#include <fsodevice.h>
#include <fsobasics.h>
#include <fsoframework.h>
#include <stdlib.h>
#include <string.h>
#include <freesmartphone.h>


#define HERRING_TYPE_WI_FI_POWER_CONTROL (herring_wi_fi_power_control_get_type ())
#define HERRING_WI_FI_POWER_CONTROL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), HERRING_TYPE_WI_FI_POWER_CONTROL, HerringWiFiPowerControl))
#define HERRING_WI_FI_POWER_CONTROL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), HERRING_TYPE_WI_FI_POWER_CONTROL, HerringWiFiPowerControlClass))
#define HERRING_IS_WI_FI_POWER_CONTROL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), HERRING_TYPE_WI_FI_POWER_CONTROL))
#define HERRING_IS_WI_FI_POWER_CONTROL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), HERRING_TYPE_WI_FI_POWER_CONTROL))
#define HERRING_WI_FI_POWER_CONTROL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), HERRING_TYPE_WI_FI_POWER_CONTROL, HerringWiFiPowerControlClass))

typedef struct _HerringWiFiPowerControl HerringWiFiPowerControl;
typedef struct _HerringWiFiPowerControlClass HerringWiFiPowerControlClass;
typedef struct _HerringWiFiPowerControlPrivate HerringWiFiPowerControlPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _fso_framework_kernel26_module_unref0(var) ((var == NULL) ? NULL : (var = (fso_framework_kernel26_module_unref (var), NULL)))
typedef struct _Block1Data Block1Data;
#define _g_free0(var) (var = (g_free (var), NULL))

struct _HerringWiFiPowerControl {
	FsoDeviceBasePowerControl parent_instance;
	HerringWiFiPowerControlPrivate * priv;
};

struct _HerringWiFiPowerControlClass {
	FsoDeviceBasePowerControlClass parent_class;
};

struct _HerringWiFiPowerControlPrivate {
	FsoDeviceBasePowerControlResource* resource;
	gboolean powered;
	FsoFrameworkKernel26Module* module;
	gboolean firmware_available;
};

struct _Block1Data {
	int _ref_count_;
	HerringWiFiPowerControl * self;
	FsoFrameworkSubsystem* subsystem;
};


static gpointer herring_wi_fi_power_control_parent_class = NULL;
static GType herring_wi_fi_power_control_type_id = 0;

GType herring_wi_fi_power_control_get_type (void) G_GNUC_CONST;
GType herring_wi_fi_power_control_register_type (GTypeModule * module);
#define HERRING_WI_FI_POWER_CONTROL_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), HERRING_TYPE_WI_FI_POWER_CONTROL, HerringWiFiPowerControlPrivate))
enum  {
	HERRING_WI_FI_POWER_CONTROL_DUMMY_PROPERTY
};
HerringWiFiPowerControl* herring_wi_fi_power_control_new (FsoFrameworkSubsystem* subsystem);
HerringWiFiPowerControl* herring_wi_fi_power_control_construct (GType object_type, FsoFrameworkSubsystem* subsystem);
static Block1Data* block1_data_ref (Block1Data* _data1_);
static void block1_data_unref (void * _userdata_);
#define HERRING_MODULE_NAME "fsodevice.herring_quirks"
static gboolean __lambda4_ (Block1Data* _data1_);
static gboolean ___lambda4__gsource_func (gpointer self);
static gboolean herring_wi_fi_power_control_real_getPower (FsoDeviceBasePowerControl* base);
static void herring_wi_fi_power_control_real_setPower (FsoDeviceBasePowerControl* base, gboolean on);
static void herring_wi_fi_power_control_finalize (GObject* obj);


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static Block1Data* block1_data_ref (Block1Data* _data1_) {
	g_atomic_int_inc (&_data1_->_ref_count_);
	return _data1_;
}


static void block1_data_unref (void * _userdata_) {
	Block1Data* _data1_;
	_data1_ = (Block1Data*) _userdata_;
	if (g_atomic_int_dec_and_test (&_data1_->_ref_count_)) {
		HerringWiFiPowerControl * self;
		self = _data1_->self;
		_g_object_unref0 (_data1_->subsystem);
		_g_object_unref0 (self);
		g_slice_free (Block1Data, _data1_);
	}
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


static gboolean __lambda4_ (Block1Data* _data1_) {
	HerringWiFiPowerControl * self;
	gboolean result = FALSE;
	FsoFrameworkSubsystem* _tmp0_;
	FsoDeviceBasePowerControlResource* _tmp1_;
	self = _data1_->self;
	_tmp0_ = _data1_->subsystem;
	_tmp1_ = fso_device_base_power_control_resource_new ((FsoDeviceISimplePowerControl*) self, "WiFi", _tmp0_, FREE_SMARTPHONE_USAGE_RESOURCE_POLICY_AUTO);
	_g_object_unref0 (self->priv->resource);
	self->priv->resource = _tmp1_;
	result = FALSE;
	return result;
}


static gboolean ___lambda4__gsource_func (gpointer self) {
	gboolean result;
	result = __lambda4_ (self);
	return result;
}


HerringWiFiPowerControl* herring_wi_fi_power_control_construct (GType object_type, FsoFrameworkSubsystem* subsystem) {
	HerringWiFiPowerControl * self = NULL;
	Block1Data* _data1_;
	FsoFrameworkSubsystem* _tmp0_;
	FsoFrameworkSubsystem* _tmp1_;
	const gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	gchar* module_name;
	FsoFrameworkSmartKeyFile* _tmp4_;
	const gchar* _tmp5_;
	gchar* _tmp6_ = NULL;
	gchar* iface_name;
	FsoFrameworkSmartKeyFile* _tmp7_;
	const gchar* _tmp8_;
	gchar* _tmp9_ = NULL;
	gchar* firmware_path;
	FsoFrameworkSmartKeyFile* _tmp10_;
	const gchar* _tmp11_;
	gchar* _tmp12_ = NULL;
	gchar* nvram_path;
	gboolean _tmp13_ = FALSE;
	const gchar* _tmp14_;
	gboolean _tmp15_ = FALSE;
	gboolean _tmp18_;
	FsoFrameworkKernel26Module* _tmp19_;
	FsoFrameworkKernel26Module* _tmp20_;
	const gchar* _tmp21_;
	const gchar* _tmp22_ = NULL;
	const gchar* _tmp23_;
	const gchar* _tmp24_ = NULL;
	const gchar* _tmp25_;
	const gchar* _tmp26_ = NULL;
	gchar* _tmp27_ = NULL;
	gchar* _tmp28_;
	FsoFrameworkSubsystem* _tmp29_;
	FsoFrameworkLogger* _tmp30_;
	g_return_val_if_fail (subsystem != NULL, NULL);
	_data1_ = g_slice_new0 (Block1Data);
	_data1_->_ref_count_ = 1;
	_tmp0_ = subsystem;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_data1_->subsystem = _tmp1_;
	self = (HerringWiFiPowerControl*) fso_device_base_power_control_construct (object_type, NULL, "1", "0", (guint) 3);
	_data1_->self = g_object_ref (self);
	_tmp2_ = string_to_string (HERRING_MODULE_NAME);
	_tmp3_ = g_strconcat (_tmp2_, "/wifi_power_control", NULL);
	module_name = _tmp3_;
	_tmp4_ = fso_framework_theConfig;
	_tmp5_ = module_name;
	_tmp6_ = fso_framework_smart_key_file_stringValue (_tmp4_, _tmp5_, "iface_name", "wlan0");
	iface_name = _tmp6_;
	_tmp7_ = fso_framework_theConfig;
	_tmp8_ = module_name;
	_tmp9_ = fso_framework_smart_key_file_stringValue (_tmp7_, _tmp8_, "firmware_path", "/lib/firmware/fw_bcm4329.bin");
	firmware_path = _tmp9_;
	_tmp10_ = fso_framework_theConfig;
	_tmp11_ = module_name;
	_tmp12_ = fso_framework_smart_key_file_stringValue (_tmp10_, _tmp11_, "nvram_path", "/lib/firmware/nvram_net.txt");
	nvram_path = _tmp12_;
	_tmp14_ = firmware_path;
	_tmp15_ = fso_framework_file_handling_isPresent (_tmp14_);
	if (_tmp15_) {
		const gchar* _tmp16_;
		gboolean _tmp17_ = FALSE;
		_tmp16_ = nvram_path;
		_tmp17_ = fso_framework_file_handling_isPresent (_tmp16_);
		_tmp13_ = _tmp17_;
	} else {
		_tmp13_ = FALSE;
	}
	_tmp18_ = _tmp13_;
	self->priv->firmware_available = _tmp18_;
	_tmp19_ = fso_framework_kernel26_module_new ("bcm4329");
	_fso_framework_kernel26_module_unref0 (self->priv->module);
	self->priv->module = _tmp19_;
	_tmp20_ = self->priv->module;
	_tmp21_ = iface_name;
	_tmp22_ = string_to_string (_tmp21_);
	_tmp23_ = firmware_path;
	_tmp24_ = string_to_string (_tmp23_);
	_tmp25_ = nvram_path;
	_tmp26_ = string_to_string (_tmp25_);
	_tmp27_ = g_strconcat ("iface_name=", _tmp22_, " firmware_path=", _tmp24_, " nvram_path=", _tmp26_, NULL);
	_tmp28_ = _tmp27_;
	fso_framework_kernel26_module_set_arguments (_tmp20_, _tmp28_);
	_g_free0 (_tmp28_);
	_tmp29_ = _data1_->subsystem;
	fso_framework_subsystem_registerObjectForServiceWithPrefix (_tmp29_, FREE_SMARTPHONE_DEVICE_TYPE_POWER_CONTROL, (GBoxedCopyFunc) g_object_ref, g_object_unref, FSO_FRAMEWORK_DEVICE_ServiceDBusName, FSO_FRAMEWORK_DEVICE_PowerControlServicePath, (FreeSmartphoneDevicePowerControl*) self);
	g_idle_add_full (G_PRIORITY_DEFAULT_IDLE, ___lambda4__gsource_func, block1_data_ref (_data1_), block1_data_unref);
	_tmp30_ = ((FsoFrameworkAbstractObject*) self)->logger;
	fso_framework_logger_info (_tmp30_, "Created.");
	_g_free0 (nvram_path);
	_g_free0 (firmware_path);
	_g_free0 (iface_name);
	_g_free0 (module_name);
	block1_data_unref (_data1_);
	_data1_ = NULL;
	return self;
}


HerringWiFiPowerControl* herring_wi_fi_power_control_new (FsoFrameworkSubsystem* subsystem) {
	return herring_wi_fi_power_control_construct (HERRING_TYPE_WI_FI_POWER_CONTROL, subsystem);
}


static gboolean herring_wi_fi_power_control_real_getPower (FsoDeviceBasePowerControl* base) {
	HerringWiFiPowerControl * self;
	gboolean result = FALSE;
	gboolean _tmp0_;
	self = (HerringWiFiPowerControl*) base;
	_tmp0_ = self->priv->powered;
	result = _tmp0_;
	return result;
}


static void herring_wi_fi_power_control_real_setPower (FsoDeviceBasePowerControl* base, gboolean on) {
	HerringWiFiPowerControl * self;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp2_;
	gboolean _tmp4_;
	gboolean _tmp9_;
	gboolean _tmp10_ = FALSE;
	gboolean _tmp11_;
	gboolean _tmp18_;
	gboolean _tmp20_;
	self = (HerringWiFiPowerControl*) base;
	_tmp2_ = self->priv->powered;
	if (_tmp2_) {
		gboolean _tmp3_;
		_tmp3_ = on;
		_tmp1_ = _tmp3_;
	} else {
		_tmp1_ = FALSE;
	}
	_tmp4_ = _tmp1_;
	if (_tmp4_) {
		_tmp0_ = TRUE;
	} else {
		gboolean _tmp5_ = FALSE;
		gboolean _tmp6_;
		gboolean _tmp8_;
		_tmp6_ = self->priv->powered;
		if (!_tmp6_) {
			gboolean _tmp7_;
			_tmp7_ = on;
			_tmp5_ = !_tmp7_;
		} else {
			_tmp5_ = FALSE;
		}
		_tmp8_ = _tmp5_;
		_tmp0_ = _tmp8_;
	}
	_tmp9_ = _tmp0_;
	if (_tmp9_) {
		return;
	}
	_tmp11_ = on;
	if (_tmp11_) {
		gboolean _tmp12_ = FALSE;
		gboolean _tmp13_;
		gboolean _tmp17_;
		_tmp13_ = self->priv->firmware_available;
		if (!_tmp13_) {
			_tmp12_ = TRUE;
		} else {
			FsoFrameworkKernel26Module* _tmp14_;
			gboolean _tmp15_;
			gboolean _tmp16_;
			_tmp14_ = self->priv->module;
			_tmp15_ = fso_framework_kernel26_module_get_available (_tmp14_);
			_tmp16_ = _tmp15_;
			_tmp12_ = !_tmp16_;
		}
		_tmp17_ = _tmp12_;
		_tmp10_ = _tmp17_;
	} else {
		_tmp10_ = FALSE;
	}
	_tmp18_ = _tmp10_;
	if (_tmp18_) {
		FsoFrameworkLogger* _tmp19_;
		_tmp19_ = ((FsoFrameworkAbstractObject*) self)->logger;
		fso_framework_logger_warning (_tmp19_, "Tried to enable WiFi but needed kernel module or firmware is not avail" \
"able");
		return;
	}
	_tmp20_ = on;
	if (_tmp20_) {
		FsoFrameworkKernel26Module* _tmp21_;
		gboolean _tmp22_ = FALSE;
		FsoFrameworkLogger* _tmp34_;
		_tmp21_ = self->priv->module;
		_tmp22_ = fso_framework_kernel26_module_load (_tmp21_);
		if (!_tmp22_) {
			FsoFrameworkLogger* _tmp23_;
			FsoFrameworkKernel26Module* _tmp24_;
			const gchar* _tmp25_;
			const gchar* _tmp26_;
			const gchar* _tmp27_ = NULL;
			FsoFrameworkKernel26Module* _tmp28_;
			const gchar* _tmp29_;
			const gchar* _tmp30_;
			const gchar* _tmp31_ = NULL;
			gchar* _tmp32_ = NULL;
			gchar* _tmp33_;
			_tmp23_ = ((FsoFrameworkAbstractObject*) self)->logger;
			_tmp24_ = self->priv->module;
			_tmp25_ = fso_framework_kernel26_module_get_name (_tmp24_);
			_tmp26_ = _tmp25_;
			_tmp27_ = string_to_string (_tmp26_);
			_tmp28_ = self->priv->module;
			_tmp29_ = fso_framework_kernel26_module_get_arguments (_tmp28_);
			_tmp30_ = _tmp29_;
			_tmp31_ = string_to_string (_tmp30_);
			_tmp32_ = g_strconcat ("Failed to load kernel module ", _tmp27_, " with arguments \"", _tmp31_, "\" to enable WiFi device", NULL);
			_tmp33_ = _tmp32_;
			fso_framework_logger_error (_tmp23_, _tmp33_);
			_g_free0 (_tmp33_);
			return;
		}
		_tmp34_ = ((FsoFrameworkAbstractObject*) self)->logger;
		fso_framework_logger_debug (_tmp34_, "Successfully enabled WiFi device");
		self->priv->powered = TRUE;
	} else {
		FsoFrameworkKernel26Module* _tmp35_;
		gboolean _tmp36_ = FALSE;
		FsoFrameworkLogger* _tmp44_;
		_tmp35_ = self->priv->module;
		_tmp36_ = fso_framework_kernel26_module_unload (_tmp35_);
		if (!_tmp36_) {
			FsoFrameworkLogger* _tmp37_;
			FsoFrameworkKernel26Module* _tmp38_;
			const gchar* _tmp39_;
			const gchar* _tmp40_;
			const gchar* _tmp41_ = NULL;
			gchar* _tmp42_ = NULL;
			gchar* _tmp43_;
			_tmp37_ = ((FsoFrameworkAbstractObject*) self)->logger;
			_tmp38_ = self->priv->module;
			_tmp39_ = fso_framework_kernel26_module_get_name (_tmp38_);
			_tmp40_ = _tmp39_;
			_tmp41_ = string_to_string (_tmp40_);
			_tmp42_ = g_strconcat ("Failed to unload kernel module ", _tmp41_, " to disable WiFi device", NULL);
			_tmp43_ = _tmp42_;
			fso_framework_logger_error (_tmp37_, _tmp43_);
			_g_free0 (_tmp43_);
			return;
		}
		_tmp44_ = ((FsoFrameworkAbstractObject*) self)->logger;
		fso_framework_logger_debug (_tmp44_, "Successfully disabled WiFi device");
		self->priv->powered = FALSE;
	}
}


static void herring_wi_fi_power_control_class_init (HerringWiFiPowerControlClass * klass) {
	herring_wi_fi_power_control_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (HerringWiFiPowerControlPrivate));
	FSO_DEVICE_BASE_POWER_CONTROL_CLASS (klass)->getPower = herring_wi_fi_power_control_real_getPower;
	FSO_DEVICE_BASE_POWER_CONTROL_CLASS (klass)->setPower = herring_wi_fi_power_control_real_setPower;
	G_OBJECT_CLASS (klass)->finalize = herring_wi_fi_power_control_finalize;
}


static void herring_wi_fi_power_control_instance_init (HerringWiFiPowerControl * self) {
	self->priv = HERRING_WI_FI_POWER_CONTROL_GET_PRIVATE (self);
	self->priv->powered = FALSE;
	self->priv->firmware_available = FALSE;
}


static void herring_wi_fi_power_control_finalize (GObject* obj) {
	HerringWiFiPowerControl * self;
	self = HERRING_WI_FI_POWER_CONTROL (obj);
	_g_object_unref0 (self->priv->resource);
	_fso_framework_kernel26_module_unref0 (self->priv->module);
	G_OBJECT_CLASS (herring_wi_fi_power_control_parent_class)->finalize (obj);
}


GType herring_wi_fi_power_control_get_type (void) {
	return herring_wi_fi_power_control_type_id;
}


GType herring_wi_fi_power_control_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (HerringWiFiPowerControlClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) herring_wi_fi_power_control_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (HerringWiFiPowerControl), 0, (GInstanceInitFunc) herring_wi_fi_power_control_instance_init, NULL };
	herring_wi_fi_power_control_type_id = g_type_module_register_type (module, FSO_DEVICE_TYPE_BASE_POWER_CONTROL, "HerringWiFiPowerControl", &g_define_type_info, 0);
	return herring_wi_fi_power_control_type_id;
}



