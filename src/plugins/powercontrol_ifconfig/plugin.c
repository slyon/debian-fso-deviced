/* plugin.c generated by valac 0.16.1, the Vala compiler
 * generated from plugin.vala, do not modify */

/*
 * Copyright (C) 2009-2012 Michael 'Mickey' Lauer <mlauer@vanille-media.de>
 *                    2010-2012 Sebastian Krzyszkowiak <seba.dos1@gmail.com>
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
#include <fsobasics.h>
#include <fsodevice.h>
#include <freesmartphone.h>
#include <fsoframework.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>
#include <fsoresource.h>


#define POWER_CONTROL_TYPE_IFCONFIG (power_control_ifconfig_get_type ())
#define POWER_CONTROL_IFCONFIG(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), POWER_CONTROL_TYPE_IFCONFIG, PowerControlIfconfig))
#define POWER_CONTROL_IFCONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), POWER_CONTROL_TYPE_IFCONFIG, PowerControlIfconfigClass))
#define POWER_CONTROL_IS_IFCONFIG(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), POWER_CONTROL_TYPE_IFCONFIG))
#define POWER_CONTROL_IS_IFCONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), POWER_CONTROL_TYPE_IFCONFIG))
#define POWER_CONTROL_IFCONFIG_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), POWER_CONTROL_TYPE_IFCONFIG, PowerControlIfconfigClass))

typedef struct _PowerControlIfconfig PowerControlIfconfig;
typedef struct _PowerControlIfconfigClass PowerControlIfconfigClass;
typedef struct _PowerControlIfconfigPrivate PowerControlIfconfigPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
typedef struct _PowerControlIfconfigGetPowerData PowerControlIfconfigGetPowerData;
typedef struct _PowerControlIfconfigSetPowerData PowerControlIfconfigSetPowerData;

#define POWER_CONTROL_TYPE_WI_FI_RESOURCE (power_control_wi_fi_resource_get_type ())
#define POWER_CONTROL_WI_FI_RESOURCE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), POWER_CONTROL_TYPE_WI_FI_RESOURCE, PowerControlWiFiResource))
#define POWER_CONTROL_WI_FI_RESOURCE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), POWER_CONTROL_TYPE_WI_FI_RESOURCE, PowerControlWiFiResourceClass))
#define POWER_CONTROL_IS_WI_FI_RESOURCE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), POWER_CONTROL_TYPE_WI_FI_RESOURCE))
#define POWER_CONTROL_IS_WI_FI_RESOURCE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), POWER_CONTROL_TYPE_WI_FI_RESOURCE))
#define POWER_CONTROL_WI_FI_RESOURCE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), POWER_CONTROL_TYPE_WI_FI_RESOURCE, PowerControlWiFiResourceClass))

typedef struct _PowerControlWiFiResource PowerControlWiFiResource;
typedef struct _PowerControlWiFiResourceClass PowerControlWiFiResourceClass;
typedef struct _PowerControlWiFiResourcePrivate PowerControlWiFiResourcePrivate;
typedef struct _power_control_wi_fi_resource_enableResourceData power_control_wi_fi_resource_enableResourceData;
typedef struct _power_control_wi_fi_resource_disableResourceData power_control_wi_fi_resource_disableResourceData;
typedef struct _power_control_wi_fi_resource_suspendResourceData power_control_wi_fi_resource_suspendResourceData;
typedef struct _power_control_wi_fi_resource_resumeResourceData power_control_wi_fi_resource_resumeResourceData;

struct _PowerControlIfconfig {
	FsoFrameworkAbstractObject parent_instance;
	PowerControlIfconfigPrivate * priv;
};

struct _PowerControlIfconfigClass {
	FsoFrameworkAbstractObjectClass parent_class;
};

struct _PowerControlIfconfigPrivate {
	FsoFrameworkSubsystem* subsystem;
	gchar* iface;
	gboolean power;
};

struct _PowerControlIfconfigGetPowerData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	PowerControlIfconfig* self;
	gboolean result;
	gboolean _tmp0_;
};

struct _PowerControlIfconfigSetPowerData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	PowerControlIfconfig* self;
	gboolean on;
	gboolean _tmp0_;
};

struct _PowerControlWiFiResource {
	FsoFrameworkAbstractDBusResource parent_instance;
	PowerControlWiFiResourcePrivate * priv;
	gboolean on;
};

struct _PowerControlWiFiResourceClass {
	FsoFrameworkAbstractDBusResourceClass parent_class;
};

struct _power_control_wi_fi_resource_enableResourceData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	PowerControlWiFiResource* self;
	gboolean _tmp0_;
	FsoFrameworkLogger* _tmp1_;
	gboolean _tmp2_;
	PowerControlIfconfig* _tmp3_;
};

struct _power_control_wi_fi_resource_disableResourceData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	PowerControlWiFiResource* self;
	gboolean _tmp0_;
	FsoFrameworkLogger* _tmp1_;
	gboolean _tmp2_;
	PowerControlIfconfig* _tmp3_;
};

struct _power_control_wi_fi_resource_suspendResourceData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	PowerControlWiFiResource* self;
};

struct _power_control_wi_fi_resource_resumeResourceData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	PowerControlWiFiResource* self;
};


static gpointer power_control_ifconfig_parent_class = NULL;
static FsoDeviceISimplePowerControlIface* power_control_ifconfig_fso_device_isimple_power_control_parent_iface = NULL;
static FreeSmartphoneDevicePowerControlIface* power_control_ifconfig_free_smartphone_device_power_control_parent_iface = NULL;
static GType power_control_ifconfig_type_id = 0;
static gpointer power_control_wi_fi_resource_parent_class = NULL;
extern PowerControlIfconfig* instance;
static GType power_control_wi_fi_resource_type_id = 0;
extern gchar* iface;
gchar* iface = NULL;
PowerControlIfconfig* instance = NULL;
extern PowerControlWiFiResource* resource;
PowerControlWiFiResource* resource = NULL;

GType power_control_ifconfig_get_type (void) G_GNUC_CONST;
GType power_control_ifconfig_register_type (GTypeModule * module);
#define POWER_CONTROL_IFCONFIG_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), POWER_CONTROL_TYPE_IFCONFIG, PowerControlIfconfigPrivate))
enum  {
	POWER_CONTROL_IFCONFIG_DUMMY_PROPERTY
};
PowerControlIfconfig* power_control_ifconfig_new (FsoFrameworkSubsystem* subsystem, const gchar* iface);
PowerControlIfconfig* power_control_ifconfig_construct (GType object_type, FsoFrameworkSubsystem* subsystem, const gchar* iface);
static gchar* power_control_ifconfig_real_repr (FsoFrameworkAbstractObject* base);
void power_control_ifconfig_exec (const gchar* app, const gchar* iface, const gchar* arg, const gchar* arg2);
static gboolean power_control_ifconfig_real_getPower (FsoDeviceISimplePowerControl* base);
static void power_control_ifconfig_real_setPower (FsoDeviceISimplePowerControl* base, gboolean on);
static void power_control_ifconfig_real_get_power_data_free (gpointer _data);
static void power_control_ifconfig_real_get_power (FreeSmartphoneDevicePowerControl* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean power_control_ifconfig_real_get_power_co (PowerControlIfconfigGetPowerData* _data_);
static void power_control_ifconfig_real_set_power_data_free (gpointer _data);
static void power_control_ifconfig_real_set_power (FreeSmartphoneDevicePowerControl* base, gboolean on, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean power_control_ifconfig_real_set_power_co (PowerControlIfconfigSetPowerData* _data_);
static void power_control_ifconfig_finalize (GObject* obj);
GType power_control_wi_fi_resource_get_type (void) G_GNUC_CONST;
GType power_control_wi_fi_resource_register_type (GTypeModule * module);
enum  {
	POWER_CONTROL_WI_FI_RESOURCE_DUMMY_PROPERTY
};
PowerControlWiFiResource* power_control_wi_fi_resource_new (FsoFrameworkSubsystem* subsystem);
PowerControlWiFiResource* power_control_wi_fi_resource_construct (GType object_type, FsoFrameworkSubsystem* subsystem);
static void power_control_wi_fi_resource_real_enableResource_data_free (gpointer _data);
static void power_control_wi_fi_resource_real_enableResource (FsoFrameworkAbstractDBusResource* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean power_control_wi_fi_resource_real_enableResource_co (power_control_wi_fi_resource_enableResourceData* _data_);
static void power_control_wi_fi_resource_real_disableResource_data_free (gpointer _data);
static void power_control_wi_fi_resource_real_disableResource (FsoFrameworkAbstractDBusResource* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean power_control_wi_fi_resource_real_disableResource_co (power_control_wi_fi_resource_disableResourceData* _data_);
static void power_control_wi_fi_resource_real_suspendResource_data_free (gpointer _data);
static void power_control_wi_fi_resource_real_suspendResource (FsoFrameworkAbstractDBusResource* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean power_control_wi_fi_resource_real_suspendResource_co (power_control_wi_fi_resource_suspendResourceData* _data_);
static void power_control_wi_fi_resource_real_resumeResource_data_free (gpointer _data);
static void power_control_wi_fi_resource_real_resumeResource (FsoFrameworkAbstractDBusResource* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean power_control_wi_fi_resource_real_resumeResource_co (power_control_wi_fi_resource_resumeResourceData* _data_);
static void power_control_wi_fi_resource_finalize (GObject* obj);
gchar* fso_factory_function (FsoFrameworkSubsystem* subsystem, GError** error);
void fso_register_function (GTypeModule* module);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


PowerControlIfconfig* power_control_ifconfig_construct (GType object_type, FsoFrameworkSubsystem* subsystem, const gchar* iface) {
	PowerControlIfconfig * self = NULL;
	FsoFrameworkSubsystem* _tmp0_;
	FsoFrameworkSubsystem* _tmp1_;
	const gchar* _tmp2_;
	gchar* _tmp3_;
	FsoFrameworkSubsystem* _tmp4_;
	FsoFrameworkLogger* _tmp5_;
	g_return_val_if_fail (subsystem != NULL, NULL);
	g_return_val_if_fail (iface != NULL, NULL);
	self = (PowerControlIfconfig*) fso_framework_abstract_object_construct (object_type);
	_tmp0_ = subsystem;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->subsystem);
	self->priv->subsystem = _tmp1_;
	_tmp2_ = iface;
	_tmp3_ = g_strdup (_tmp2_);
	_g_free0 (self->priv->iface);
	self->priv->iface = _tmp3_;
	self->priv->power = FALSE;
	_tmp4_ = subsystem;
	fso_framework_subsystem_registerObjectForService (_tmp4_, FREE_SMARTPHONE_DEVICE_TYPE_POWER_CONTROL, (GBoxedCopyFunc) g_object_ref, g_object_unref, FSO_FRAMEWORK_DEVICE_ServiceDBusName, FSO_FRAMEWORK_DEVICE_ProximityServicePath, (FreeSmartphoneDevicePowerControl*) self);
	_tmp5_ = ((FsoFrameworkAbstractObject*) self)->logger;
	fso_framework_logger_info (_tmp5_, "Created");
	return self;
}


PowerControlIfconfig* power_control_ifconfig_new (FsoFrameworkSubsystem* subsystem, const gchar* iface) {
	return power_control_ifconfig_construct (POWER_CONTROL_TYPE_IFCONFIG, subsystem, iface);
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


static gchar* power_control_ifconfig_real_repr (FsoFrameworkAbstractObject* base) {
	PowerControlIfconfig * self;
	gchar* result = NULL;
	const gchar* _tmp0_;
	const gchar* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	self = (PowerControlIfconfig*) base;
	_tmp0_ = self->priv->iface;
	_tmp1_ = string_to_string (_tmp0_);
	_tmp2_ = g_strconcat ("<", _tmp1_, ">", NULL);
	result = _tmp2_;
	return result;
}


void power_control_ifconfig_exec (const gchar* app, const gchar* iface, const gchar* arg, const gchar* arg2) {
	gchar** _tmp0_ = NULL;
	gchar** argv;
	gint argv_length1;
	gint _argv_size_;
	const gchar* _tmp1_;
	gchar* _tmp2_;
	gchar* _tmp3_;
	const gchar* _tmp4_;
	gchar* _tmp5_;
	gchar* _tmp6_;
	const gchar* _tmp7_;
	gchar* _tmp8_;
	gchar* _tmp9_;
	const gchar* _tmp10_;
	gchar* _tmp11_;
	gchar* _tmp12_;
	GPid child_pid = 0;
	gint input_fd = 0;
	gint output_fd = 0;
	gint error_fd = 0;
	GError * _inner_error_ = NULL;
	g_return_if_fail (app != NULL);
	g_return_if_fail (iface != NULL);
	g_return_if_fail (arg != NULL);
	g_return_if_fail (arg2 != NULL);
	_tmp0_ = g_new0 (gchar*, 4 + 1);
	argv = _tmp0_;
	argv_length1 = 4;
	_argv_size_ = argv_length1;
	_tmp1_ = app;
	_tmp2_ = g_strdup (_tmp1_);
	_g_free0 (argv[0]);
	argv[0] = _tmp2_;
	_tmp3_ = argv[0];
	_tmp4_ = iface;
	_tmp5_ = g_strdup (_tmp4_);
	_g_free0 (argv[1]);
	argv[1] = _tmp5_;
	_tmp6_ = argv[1];
	_tmp7_ = arg;
	_tmp8_ = g_strdup (_tmp7_);
	_g_free0 (argv[2]);
	argv[2] = _tmp8_;
	_tmp9_ = argv[2];
	_tmp10_ = arg2;
	_tmp11_ = g_strdup (_tmp10_);
	_g_free0 (argv[3]);
	argv[3] = _tmp11_;
	_tmp12_ = argv[3];
	{
		GPid _tmp13_ = 0;
		gint _tmp14_ = 0;
		gint _tmp15_ = 0;
		gint _tmp16_ = 0;
		g_spawn_async_with_pipes (".", argv, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, &_tmp13_, &_tmp14_, &_tmp15_, &_tmp16_, &_inner_error_);
		child_pid = _tmp13_;
		input_fd = _tmp14_;
		output_fd = _tmp15_;
		error_fd = _tmp16_;
		if (_inner_error_ != NULL) {
			goto __catch0_g_error;
		}
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError* e = NULL;
		FsoFrameworkLogger* _tmp17_;
		const gchar* _tmp18_;
		const gchar* _tmp19_ = NULL;
		const gchar* _tmp20_;
		const gchar* _tmp21_ = NULL;
		const gchar* _tmp22_;
		const gchar* _tmp23_ = NULL;
		gchar* _tmp24_ = NULL;
		gchar* _tmp25_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp17_ = fso_framework_theLogger;
		_tmp18_ = app;
		_tmp19_ = string_to_string (_tmp18_);
		_tmp20_ = iface;
		_tmp21_ = string_to_string (_tmp20_);
		_tmp22_ = arg;
		_tmp23_ = string_to_string (_tmp22_);
		_tmp24_ = g_strconcat ("Could not call ", _tmp19_, " ", _tmp21_, " ", _tmp23_, "!", NULL);
		_tmp25_ = _tmp24_;
		fso_framework_logger_error (_tmp17_, _tmp25_);
		_g_free0 (_tmp25_);
		_g_error_free0 (e);
	}
	__finally0:
	if (_inner_error_ != NULL) {
		argv = (_vala_array_free (argv, argv_length1, (GDestroyNotify) g_free), NULL);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	argv = (_vala_array_free (argv, argv_length1, (GDestroyNotify) g_free), NULL);
}


static gboolean power_control_ifconfig_real_getPower (FsoDeviceISimplePowerControl* base) {
	PowerControlIfconfig * self;
	gboolean result = FALSE;
	gboolean _tmp0_;
	self = (PowerControlIfconfig*) base;
	_tmp0_ = self->priv->power;
	result = _tmp0_;
	return result;
}


static void power_control_ifconfig_real_setPower (FsoDeviceISimplePowerControl* base, gboolean on) {
	PowerControlIfconfig * self;
	gchar* arg = NULL;
	gboolean _tmp0_;
	gboolean _tmp1_;
	const gchar* _tmp4_;
	const gchar* _tmp5_;
	gboolean _tmp6_;
	self = (PowerControlIfconfig*) base;
	_tmp0_ = on;
	self->priv->power = _tmp0_;
	_tmp1_ = on;
	if (_tmp1_) {
		gchar* _tmp2_;
		_tmp2_ = g_strdup ("up");
		_g_free0 (arg);
		arg = _tmp2_;
	} else {
		gchar* _tmp3_;
		_tmp3_ = g_strdup ("down");
		_g_free0 (arg);
		arg = _tmp3_;
	}
	_tmp4_ = self->priv->iface;
	_tmp5_ = arg;
	power_control_ifconfig_exec ("/sbin/ifconfig", _tmp4_, _tmp5_, "");
	_tmp6_ = on;
	if (_tmp6_) {
		const gchar* _tmp7_;
		_tmp7_ = self->priv->iface;
		power_control_ifconfig_exec ("/sbin/iwconfig", _tmp7_, "power", "on");
	}
	_g_free0 (arg);
}


static void power_control_ifconfig_real_get_power_data_free (gpointer _data) {
	PowerControlIfconfigGetPowerData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (PowerControlIfconfigGetPowerData, _data_);
}


static void power_control_ifconfig_real_get_power (FreeSmartphoneDevicePowerControl* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	PowerControlIfconfig * self;
	PowerControlIfconfigGetPowerData* _data_;
	PowerControlIfconfig* _tmp0_;
	self = (PowerControlIfconfig*) base;
	_data_ = g_slice_new0 (PowerControlIfconfigGetPowerData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, power_control_ifconfig_real_get_power);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, power_control_ifconfig_real_get_power_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	power_control_ifconfig_real_get_power_co (_data_);
}


static gboolean power_control_ifconfig_real_get_power_finish (FreeSmartphoneDevicePowerControl* base, GAsyncResult* _res_, GError** error) {
	gboolean result;
	PowerControlIfconfigGetPowerData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return FALSE;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	result = _data_->result;
	return result;
}


static gboolean power_control_ifconfig_real_get_power_co (PowerControlIfconfigGetPowerData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = FALSE;
	_data_->_tmp0_ = fso_device_isimple_power_control_getPower ((FsoDeviceISimplePowerControl*) _data_->self);
	_data_->result = _data_->_tmp0_;
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void power_control_ifconfig_real_set_power_data_free (gpointer _data) {
	PowerControlIfconfigSetPowerData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (PowerControlIfconfigSetPowerData, _data_);
}


static void power_control_ifconfig_real_set_power (FreeSmartphoneDevicePowerControl* base, gboolean on, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	PowerControlIfconfig * self;
	PowerControlIfconfigSetPowerData* _data_;
	PowerControlIfconfig* _tmp0_;
	gboolean _tmp1_;
	self = (PowerControlIfconfig*) base;
	_data_ = g_slice_new0 (PowerControlIfconfigSetPowerData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, power_control_ifconfig_real_set_power);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, power_control_ifconfig_real_set_power_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	_tmp1_ = on;
	_data_->on = _tmp1_;
	power_control_ifconfig_real_set_power_co (_data_);
}


static void power_control_ifconfig_real_set_power_finish (FreeSmartphoneDevicePowerControl* base, GAsyncResult* _res_, GError** error) {
	PowerControlIfconfigSetPowerData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static gboolean power_control_ifconfig_real_set_power_co (PowerControlIfconfigSetPowerData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = _data_->on;
	fso_device_isimple_power_control_setPower ((FsoDeviceISimplePowerControl*) _data_->self, _data_->_tmp0_);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void power_control_ifconfig_class_init (PowerControlIfconfigClass * klass) {
	power_control_ifconfig_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (PowerControlIfconfigPrivate));
	FSO_FRAMEWORK_ABSTRACT_OBJECT_CLASS (klass)->repr = power_control_ifconfig_real_repr;
	G_OBJECT_CLASS (klass)->finalize = power_control_ifconfig_finalize;
}


static void power_control_ifconfig_fso_device_isimple_power_control_interface_init (FsoDeviceISimplePowerControlIface * iface) {
	power_control_ifconfig_fso_device_isimple_power_control_parent_iface = g_type_interface_peek_parent (iface);
	iface->getPower = (gboolean (*)(FsoDeviceISimplePowerControl*)) power_control_ifconfig_real_getPower;
	iface->setPower = (void (*)(FsoDeviceISimplePowerControl*, gboolean)) power_control_ifconfig_real_setPower;
}


static void power_control_ifconfig_free_smartphone_device_power_control_interface_init (FreeSmartphoneDevicePowerControlIface * iface) {
	power_control_ifconfig_free_smartphone_device_power_control_parent_iface = g_type_interface_peek_parent (iface);
	iface->get_power = (gboolean (*)(FreeSmartphoneDevicePowerControl*, GError**)) power_control_ifconfig_real_get_power;
	iface->get_power_finish = power_control_ifconfig_real_get_power_finish;
	iface->set_power = (void (*)(FreeSmartphoneDevicePowerControl*, gboolean, GError**)) power_control_ifconfig_real_set_power;
	iface->set_power_finish = power_control_ifconfig_real_set_power_finish;
}


static void power_control_ifconfig_instance_init (PowerControlIfconfig * self) {
	self->priv = POWER_CONTROL_IFCONFIG_GET_PRIVATE (self);
}


static void power_control_ifconfig_finalize (GObject* obj) {
	PowerControlIfconfig * self;
	self = POWER_CONTROL_IFCONFIG (obj);
	_g_object_unref0 (self->priv->subsystem);
	_g_free0 (self->priv->iface);
	G_OBJECT_CLASS (power_control_ifconfig_parent_class)->finalize (obj);
}


GType power_control_ifconfig_get_type (void) {
	return power_control_ifconfig_type_id;
}


GType power_control_ifconfig_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (PowerControlIfconfigClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) power_control_ifconfig_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (PowerControlIfconfig), 0, (GInstanceInitFunc) power_control_ifconfig_instance_init, NULL };
	static const GInterfaceInfo fso_device_isimple_power_control_info = { (GInterfaceInitFunc) power_control_ifconfig_fso_device_isimple_power_control_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	static const GInterfaceInfo free_smartphone_device_power_control_info = { (GInterfaceInitFunc) power_control_ifconfig_free_smartphone_device_power_control_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	power_control_ifconfig_type_id = g_type_module_register_type (module, FSO_FRAMEWORK_TYPE_ABSTRACT_OBJECT, "PowerControlIfconfig", &g_define_type_info, 0);
	g_type_module_add_interface (module, power_control_ifconfig_type_id, FSO_DEVICE_TYPE_ISIMPLE_POWER_CONTROL, &fso_device_isimple_power_control_info);
	g_type_module_add_interface (module, power_control_ifconfig_type_id, FREE_SMARTPHONE_DEVICE_TYPE_POWER_CONTROL, &free_smartphone_device_power_control_info);
	return power_control_ifconfig_type_id;
}


PowerControlWiFiResource* power_control_wi_fi_resource_construct (GType object_type, FsoFrameworkSubsystem* subsystem) {
	PowerControlWiFiResource * self = NULL;
	FsoFrameworkSubsystem* _tmp0_;
	g_return_val_if_fail (subsystem != NULL, NULL);
	_tmp0_ = subsystem;
	self = (PowerControlWiFiResource*) fso_framework_abstract_dbus_resource_construct (object_type, "WiFi", _tmp0_);
	return self;
}


PowerControlWiFiResource* power_control_wi_fi_resource_new (FsoFrameworkSubsystem* subsystem) {
	return power_control_wi_fi_resource_construct (POWER_CONTROL_TYPE_WI_FI_RESOURCE, subsystem);
}


static void power_control_wi_fi_resource_real_enableResource_data_free (gpointer _data) {
	power_control_wi_fi_resource_enableResourceData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (power_control_wi_fi_resource_enableResourceData, _data_);
}


static void power_control_wi_fi_resource_real_enableResource (FsoFrameworkAbstractDBusResource* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	PowerControlWiFiResource * self;
	power_control_wi_fi_resource_enableResourceData* _data_;
	PowerControlWiFiResource* _tmp0_;
	self = (PowerControlWiFiResource*) base;
	_data_ = g_slice_new0 (power_control_wi_fi_resource_enableResourceData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, power_control_wi_fi_resource_real_enableResource);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, power_control_wi_fi_resource_real_enableResource_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	power_control_wi_fi_resource_real_enableResource_co (_data_);
}


static void power_control_wi_fi_resource_real_enableResource_finish (FsoFrameworkAbstractDBusResource* base, GAsyncResult* _res_, GError** error) {
	power_control_wi_fi_resource_enableResourceData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static gboolean power_control_wi_fi_resource_real_enableResource_co (power_control_wi_fi_resource_enableResourceData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = _data_->self->on;
	if (_data_->_tmp0_) {
		if (_data_->_state_ == 0) {
			g_simple_async_result_complete_in_idle (_data_->_async_result);
		} else {
			g_simple_async_result_complete (_data_->_async_result);
		}
		g_object_unref (_data_->_async_result);
		return FALSE;
	}
	_data_->_tmp1_ = ((FsoFrameworkAbstractObject*) _data_->self)->logger;
	_data_->_tmp2_ = FALSE;
	_data_->_tmp2_ = fso_framework_logger_debug (_data_->_tmp1_, "Enabling...");
	g_assert (_data_->_tmp2_);
	_data_->_tmp3_ = instance;
	free_smartphone_device_power_control_set_power ((FreeSmartphoneDevicePowerControl*) _data_->_tmp3_, TRUE, NULL, NULL);
	_data_->self->on = TRUE;
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void power_control_wi_fi_resource_real_disableResource_data_free (gpointer _data) {
	power_control_wi_fi_resource_disableResourceData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (power_control_wi_fi_resource_disableResourceData, _data_);
}


static void power_control_wi_fi_resource_real_disableResource (FsoFrameworkAbstractDBusResource* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	PowerControlWiFiResource * self;
	power_control_wi_fi_resource_disableResourceData* _data_;
	PowerControlWiFiResource* _tmp0_;
	self = (PowerControlWiFiResource*) base;
	_data_ = g_slice_new0 (power_control_wi_fi_resource_disableResourceData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, power_control_wi_fi_resource_real_disableResource);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, power_control_wi_fi_resource_real_disableResource_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	power_control_wi_fi_resource_real_disableResource_co (_data_);
}


static void power_control_wi_fi_resource_real_disableResource_finish (FsoFrameworkAbstractDBusResource* base, GAsyncResult* _res_) {
	power_control_wi_fi_resource_disableResourceData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static gboolean power_control_wi_fi_resource_real_disableResource_co (power_control_wi_fi_resource_disableResourceData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = _data_->self->on;
	if (!_data_->_tmp0_) {
		if (_data_->_state_ == 0) {
			g_simple_async_result_complete_in_idle (_data_->_async_result);
		} else {
			g_simple_async_result_complete (_data_->_async_result);
		}
		g_object_unref (_data_->_async_result);
		return FALSE;
	}
	_data_->_tmp1_ = ((FsoFrameworkAbstractObject*) _data_->self)->logger;
	_data_->_tmp2_ = FALSE;
	_data_->_tmp2_ = fso_framework_logger_debug (_data_->_tmp1_, "Disabling...");
	g_assert (_data_->_tmp2_);
	_data_->_tmp3_ = instance;
	free_smartphone_device_power_control_set_power ((FreeSmartphoneDevicePowerControl*) _data_->_tmp3_, FALSE, NULL, NULL);
	_data_->self->on = FALSE;
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void power_control_wi_fi_resource_real_suspendResource_data_free (gpointer _data) {
	power_control_wi_fi_resource_suspendResourceData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (power_control_wi_fi_resource_suspendResourceData, _data_);
}


static void power_control_wi_fi_resource_real_suspendResource (FsoFrameworkAbstractDBusResource* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	PowerControlWiFiResource * self;
	power_control_wi_fi_resource_suspendResourceData* _data_;
	PowerControlWiFiResource* _tmp0_;
	self = (PowerControlWiFiResource*) base;
	_data_ = g_slice_new0 (power_control_wi_fi_resource_suspendResourceData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, power_control_wi_fi_resource_real_suspendResource);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, power_control_wi_fi_resource_real_suspendResource_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	power_control_wi_fi_resource_real_suspendResource_co (_data_);
}


static void power_control_wi_fi_resource_real_suspendResource_finish (FsoFrameworkAbstractDBusResource* base, GAsyncResult* _res_) {
	power_control_wi_fi_resource_suspendResourceData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static gboolean power_control_wi_fi_resource_real_suspendResource_co (power_control_wi_fi_resource_suspendResourceData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void power_control_wi_fi_resource_real_resumeResource_data_free (gpointer _data) {
	power_control_wi_fi_resource_resumeResourceData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (power_control_wi_fi_resource_resumeResourceData, _data_);
}


static void power_control_wi_fi_resource_real_resumeResource (FsoFrameworkAbstractDBusResource* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	PowerControlWiFiResource * self;
	power_control_wi_fi_resource_resumeResourceData* _data_;
	PowerControlWiFiResource* _tmp0_;
	self = (PowerControlWiFiResource*) base;
	_data_ = g_slice_new0 (power_control_wi_fi_resource_resumeResourceData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, power_control_wi_fi_resource_real_resumeResource);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, power_control_wi_fi_resource_real_resumeResource_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	power_control_wi_fi_resource_real_resumeResource_co (_data_);
}


static void power_control_wi_fi_resource_real_resumeResource_finish (FsoFrameworkAbstractDBusResource* base, GAsyncResult* _res_) {
	power_control_wi_fi_resource_resumeResourceData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static gboolean power_control_wi_fi_resource_real_resumeResource_co (power_control_wi_fi_resource_resumeResourceData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void power_control_wi_fi_resource_class_init (PowerControlWiFiResourceClass * klass) {
	power_control_wi_fi_resource_parent_class = g_type_class_peek_parent (klass);
	FSO_FRAMEWORK_ABSTRACT_DBUS_RESOURCE_CLASS (klass)->enableResource = power_control_wi_fi_resource_real_enableResource;
	FSO_FRAMEWORK_ABSTRACT_DBUS_RESOURCE_CLASS (klass)->enableResource_finish = power_control_wi_fi_resource_real_enableResource_finish;
	FSO_FRAMEWORK_ABSTRACT_DBUS_RESOURCE_CLASS (klass)->disableResource = power_control_wi_fi_resource_real_disableResource;
	FSO_FRAMEWORK_ABSTRACT_DBUS_RESOURCE_CLASS (klass)->disableResource_finish = power_control_wi_fi_resource_real_disableResource_finish;
	FSO_FRAMEWORK_ABSTRACT_DBUS_RESOURCE_CLASS (klass)->suspendResource = power_control_wi_fi_resource_real_suspendResource;
	FSO_FRAMEWORK_ABSTRACT_DBUS_RESOURCE_CLASS (klass)->suspendResource_finish = power_control_wi_fi_resource_real_suspendResource_finish;
	FSO_FRAMEWORK_ABSTRACT_DBUS_RESOURCE_CLASS (klass)->resumeResource = power_control_wi_fi_resource_real_resumeResource;
	FSO_FRAMEWORK_ABSTRACT_DBUS_RESOURCE_CLASS (klass)->resumeResource_finish = power_control_wi_fi_resource_real_resumeResource_finish;
	G_OBJECT_CLASS (klass)->finalize = power_control_wi_fi_resource_finalize;
}


static void power_control_wi_fi_resource_instance_init (PowerControlWiFiResource * self) {
}


static void power_control_wi_fi_resource_finalize (GObject* obj) {
	PowerControlWiFiResource * self;
	self = POWER_CONTROL_WI_FI_RESOURCE (obj);
	G_OBJECT_CLASS (power_control_wi_fi_resource_parent_class)->finalize (obj);
}


/**
 * Implementation of org.freesmartphone.Resource for the Proximity Resource
 **/
GType power_control_wi_fi_resource_get_type (void) {
	return power_control_wi_fi_resource_type_id;
}


GType power_control_wi_fi_resource_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (PowerControlWiFiResourceClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) power_control_wi_fi_resource_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (PowerControlWiFiResource), 0, (GInstanceInitFunc) power_control_wi_fi_resource_instance_init, NULL };
	power_control_wi_fi_resource_type_id = g_type_module_register_type (module, FSO_FRAMEWORK_TYPE_ABSTRACT_DBUS_RESOURCE, "PowerControlWiFiResource", &g_define_type_info, 0);
	return power_control_wi_fi_resource_type_id;
}


/**
 * This function gets called on plugin initialization time.
 * @return the name of your plugin here
 * @note that it needs to be a name in the format <subsystem>.<plugin>
 * else your module will be unloaded immediately.
 **/
gchar* fso_factory_function (FsoFrameworkSubsystem* subsystem, GError** error) {
	gchar* result = NULL;
	FsoFrameworkSmartKeyFile* _tmp0_;
	FsoFrameworkSmartKeyFile* _tmp1_;
	FsoFrameworkSmartKeyFile* config;
	gchar* _tmp2_ = NULL;
	FsoFrameworkSubsystem* _tmp3_;
	const gchar* _tmp4_;
	PowerControlIfconfig* _tmp5_;
	FsoFrameworkSubsystem* _tmp6_;
	PowerControlWiFiResource* _tmp7_;
	PowerControlIfconfig* _tmp8_;
	gchar* _tmp9_;
	g_return_val_if_fail (subsystem != NULL, NULL);
	_tmp0_ = fso_framework_theConfig;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	config = _tmp1_;
	_tmp2_ = fso_framework_smart_key_file_stringValue (config, "fsodevice.powercontrol_ifconfig", "interface", "wlan0");
	_g_free0 (iface);
	iface = _tmp2_;
	_tmp3_ = subsystem;
	_tmp4_ = iface;
	_tmp5_ = power_control_ifconfig_new (_tmp3_, _tmp4_);
	_g_object_unref0 (instance);
	instance = _tmp5_;
	_tmp6_ = subsystem;
	_tmp7_ = power_control_wi_fi_resource_new (_tmp6_);
	_g_object_unref0 (resource);
	resource = _tmp7_;
	_tmp8_ = instance;
	free_smartphone_device_power_control_set_power ((FreeSmartphoneDevicePowerControl*) _tmp8_, FALSE, NULL, NULL);
	_tmp9_ = g_strdup ("fsodevice.powercontrol_ifconfig");
	result = _tmp9_;
	_g_object_unref0 (config);
	return result;
}


void fso_register_function (GTypeModule* module) {
	FsoFrameworkLogger* _tmp0_;
	g_return_if_fail (module != NULL);
	power_control_ifconfig_register_type (module);
	power_control_wi_fi_resource_register_type (module);
	_tmp0_ = fso_framework_theLogger;
	fso_framework_logger_debug (_tmp0_, "fsodevice.powercontrol_ifconfig fso_register_function()");
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}



