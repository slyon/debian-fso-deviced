/* ambientlight.c generated by valac 0.14.2, the Vala compiler
 * generated from ambientlight.vala, do not modify */

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
#include <fsobasics.h>
#include <freesmartphone.h>
#include <fsoframework.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>
#include <linux/input.h>
#include <float.h>
#include <math.h>
#include <gio/gio.h>


#define PALM_PRE_TYPE_AMBIENT_LIGHT (palm_pre_ambient_light_get_type ())
#define PALM_PRE_AMBIENT_LIGHT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PALM_PRE_TYPE_AMBIENT_LIGHT, PalmPreAmbientLight))
#define PALM_PRE_AMBIENT_LIGHT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PALM_PRE_TYPE_AMBIENT_LIGHT, PalmPreAmbientLightClass))
#define PALM_PRE_IS_AMBIENT_LIGHT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PALM_PRE_TYPE_AMBIENT_LIGHT))
#define PALM_PRE_IS_AMBIENT_LIGHT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PALM_PRE_TYPE_AMBIENT_LIGHT))
#define PALM_PRE_AMBIENT_LIGHT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PALM_PRE_TYPE_AMBIENT_LIGHT, PalmPreAmbientLightClass))

typedef struct _PalmPreAmbientLight PalmPreAmbientLight;
typedef struct _PalmPreAmbientLightClass PalmPreAmbientLightClass;
typedef struct _PalmPreAmbientLightPrivate PalmPreAmbientLightPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _PalmPreAmbientLightGetAmbientLightBrightnessData PalmPreAmbientLightGetAmbientLightBrightnessData;

struct _PalmPreAmbientLight {
	FsoFrameworkAbstractObject parent_instance;
	PalmPreAmbientLightPrivate * priv;
};

struct _PalmPreAmbientLightClass {
	FsoFrameworkAbstractObjectClass parent_class;
};

struct _PalmPreAmbientLightPrivate {
	FsoFrameworkSubsystem* subsystem;
	gchar* sysfsnode;
	gchar* resultnode;
	gchar* averagenode;
	gchar* pollintervalnode;
	gint maxvalue;
	gint minvalue;
	glong start_timestamp;
	gint brightness_timestamp;
	gint _brightness;
	FsoFrameworkAsyncReactorChannel* input;
};

struct _PalmPreAmbientLightGetAmbientLightBrightnessData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	PalmPreAmbientLight* self;
	gint brightness;
	gint timestamp;
	gint _tmp0_;
	gint _tmp1_;
	gint _tmp2_;
};


static gpointer palm_pre_ambient_light_parent_class = NULL;
extern gchar* palm_pre_devfs_root;
static FreeSmartphoneDeviceAmbientLightIface* palm_pre_ambient_light_free_smartphone_device_ambient_light_parent_iface = NULL;
static GType palm_pre_ambient_light_type_id = 0;

GType palm_pre_ambient_light_get_type (void) G_GNUC_CONST;
GType palm_pre_ambient_light_register_type (GTypeModule * module);
#define PALM_PRE_AMBIENT_LIGHT_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), PALM_PRE_TYPE_AMBIENT_LIGHT, PalmPreAmbientLightPrivate))
enum  {
	PALM_PRE_AMBIENT_LIGHT_DUMMY_PROPERTY
};
#define PALM_PRE_AMBIENT_LIGHT_DEFAULT_INPUT_NODE "input/event4"
#define PALM_PRE_AMBIENT_LIGHT_DARKNESS 0
#define PALM_PRE_AMBIENT_LIGHT_SUNLIGHT 1000
PalmPreAmbientLight* palm_pre_ambient_light_new (FsoFrameworkSubsystem* subsystem, const gchar* sysfsnode);
PalmPreAmbientLight* palm_pre_ambient_light_construct (GType object_type, FsoFrameworkSubsystem* subsystem, const gchar* sysfsnode);
static void palm_pre_ambient_light_onInputEvent (PalmPreAmbientLight* self, void* data, gssize length);
static void _palm_pre_ambient_light_onInputEvent_fso_framework_async_reactor_channel_action_func (void* data, gssize length, gpointer self);
static gchar* palm_pre_ambient_light_real_repr (FsoFrameworkAbstractObject* base);
static gint _palm_pre_ambient_light_valueToPercent (PalmPreAmbientLight* self, gint value);
static void palm_pre_ambient_light_set_brightness (PalmPreAmbientLight* self, gint value);
static void palm_pre_ambient_light_real_get_ambient_light_brightness_data_free (gpointer _data);
static void palm_pre_ambient_light_real_get_ambient_light_brightness (FreeSmartphoneDeviceAmbientLight* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean palm_pre_ambient_light_real_get_ambient_light_brightness_co (PalmPreAmbientLightGetAmbientLightBrightnessData* _data_);
static gint palm_pre_ambient_light_get_brightness (PalmPreAmbientLight* self);
static void palm_pre_ambient_light_finalize (GObject* obj);
static void _vala_palm_pre_ambient_light_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_palm_pre_ambient_light_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


static void _palm_pre_ambient_light_onInputEvent_fso_framework_async_reactor_channel_action_func (void* data, gssize length, gpointer self) {
	palm_pre_ambient_light_onInputEvent (self, data, length);
}


PalmPreAmbientLight* palm_pre_ambient_light_construct (GType object_type, FsoFrameworkSubsystem* subsystem, const gchar* sysfsnode) {
	PalmPreAmbientLight * self = NULL;
	FsoFrameworkSubsystem* _tmp0_;
	FsoFrameworkSubsystem* _tmp1_;
	const gchar* _tmp2_;
	gchar* _tmp3_;
	const gchar* _tmp4_;
	gchar* _tmp5_;
	const gchar* _tmp6_;
	gchar* _tmp7_;
	const gchar* _tmp8_;
	gchar* _tmp9_;
	const gchar* _tmp10_;
	gboolean _tmp11_ = FALSE;
	const gchar* _tmp17_;
	gchar* _tmp18_ = NULL;
	gchar* _tmp19_;
	gint _tmp20_ = 0;
	gint _tmp21_;
	gint fd;
	gint _tmp22_;
	gint _tmp32_;
	FsoFrameworkAsyncReactorChannel* _tmp33_;
	FsoFrameworkSubsystem* _tmp34_;
	FsoFrameworkLogger* _tmp35_;
	g_return_val_if_fail (subsystem != NULL, NULL);
	g_return_val_if_fail (sysfsnode != NULL, NULL);
	self = (PalmPreAmbientLight*) fso_framework_abstract_object_construct (object_type);
	self->priv->minvalue = PALM_PRE_AMBIENT_LIGHT_DARKNESS;
	self->priv->maxvalue = PALM_PRE_AMBIENT_LIGHT_SUNLIGHT;
	_tmp0_ = subsystem;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->subsystem);
	self->priv->subsystem = _tmp1_;
	_tmp2_ = sysfsnode;
	_tmp3_ = g_strdup (_tmp2_);
	_g_free0 (self->priv->sysfsnode);
	self->priv->sysfsnode = _tmp3_;
	_tmp4_ = sysfsnode;
	_tmp5_ = g_strconcat (_tmp4_, "/result", NULL);
	_g_free0 (self->priv->resultnode);
	self->priv->resultnode = _tmp5_;
	_tmp6_ = sysfsnode;
	_tmp7_ = g_strconcat (_tmp6_, "/average", NULL);
	_g_free0 (self->priv->averagenode);
	self->priv->averagenode = _tmp7_;
	_tmp8_ = sysfsnode;
	_tmp9_ = g_strconcat (_tmp8_, "/poll_interval", NULL);
	_g_free0 (self->priv->pollintervalnode);
	self->priv->pollintervalnode = _tmp9_;
	_tmp10_ = self->priv->resultnode;
	_tmp11_ = fso_framework_file_handling_isPresent (_tmp10_);
	if (!_tmp11_) {
		FsoFrameworkLogger* _tmp12_;
		const gchar* _tmp13_;
		const gchar* _tmp14_ = NULL;
		gchar* _tmp15_ = NULL;
		gchar* _tmp16_;
		_tmp12_ = ((FsoFrameworkAbstractObject*) self)->logger;
		_tmp13_ = self->priv->resultnode;
		_tmp14_ = string_to_string (_tmp13_);
		_tmp15_ = g_strconcat ("Sysfs class is damaged, missing ", _tmp14_, "; skipping.", NULL);
		_tmp16_ = _tmp15_;
		fso_framework_logger_error (_tmp12_, _tmp16_);
		_g_free0 (_tmp16_);
		return self;
	}
	_tmp17_ = palm_pre_devfs_root;
	_tmp18_ = g_build_filename (_tmp17_, PALM_PRE_AMBIENT_LIGHT_DEFAULT_INPUT_NODE, NULL);
	_tmp19_ = _tmp18_;
	_tmp20_ = open (_tmp19_, O_RDONLY, (mode_t) 0);
	_tmp21_ = _tmp20_;
	_g_free0 (_tmp19_);
	fd = _tmp21_;
	_tmp22_ = fd;
	if (_tmp22_ == (-1)) {
		FsoFrameworkLogger* _tmp23_;
		const gchar* _tmp24_;
		const gchar* _tmp25_ = NULL;
		const gchar* _tmp26_ = NULL;
		gint _tmp27_;
		const gchar* _tmp28_ = NULL;
		const gchar* _tmp29_ = NULL;
		gchar* _tmp30_ = NULL;
		gchar* _tmp31_;
		_tmp23_ = ((FsoFrameworkAbstractObject*) self)->logger;
		_tmp24_ = palm_pre_devfs_root;
		_tmp25_ = string_to_string (_tmp24_);
		_tmp26_ = string_to_string (PALM_PRE_AMBIENT_LIGHT_DEFAULT_INPUT_NODE);
		_tmp27_ = errno;
		_tmp28_ = strerror (_tmp27_);
		_tmp29_ = string_to_string (_tmp28_);
		_tmp30_ = g_strconcat ("Can't open ", _tmp25_, "/", _tmp26_, ": ", _tmp29_, NULL);
		_tmp31_ = _tmp30_;
		fso_framework_logger_error (_tmp23_, _tmp31_);
		_g_free0 (_tmp31_);
		return self;
	}
	_tmp32_ = fd;
	_tmp33_ = fso_framework_async_reactor_channel_new (_tmp32_, _palm_pre_ambient_light_onInputEvent_fso_framework_async_reactor_channel_action_func, g_object_ref (self), g_object_unref, (gsize) sizeof (struct input_event));
	_g_object_unref0 (self->priv->input);
	self->priv->input = _tmp33_;
	_tmp34_ = subsystem;
	fso_framework_subsystem_registerObjectForServiceWithPrefix (_tmp34_, FREE_SMARTPHONE_DEVICE_TYPE_AMBIENT_LIGHT, (GBoxedCopyFunc) g_object_ref, g_object_unref, FSO_FRAMEWORK_DEVICE_ServiceDBusName, FSO_FRAMEWORK_DEVICE_AmbientLightServicePath, (FreeSmartphoneDeviceAmbientLight*) self);
	_tmp35_ = ((FsoFrameworkAbstractObject*) self)->logger;
	fso_framework_logger_info (_tmp35_, "Created");
	return self;
}


PalmPreAmbientLight* palm_pre_ambient_light_new (FsoFrameworkSubsystem* subsystem, const gchar* sysfsnode) {
	return palm_pre_ambient_light_construct (PALM_PRE_TYPE_AMBIENT_LIGHT, subsystem, sysfsnode);
}


static gchar* palm_pre_ambient_light_real_repr (FsoFrameworkAbstractObject* base) {
	PalmPreAmbientLight * self;
	gchar* result = NULL;
	const gchar* _tmp0_;
	const gchar* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	self = (PalmPreAmbientLight*) base;
	_tmp0_ = self->priv->sysfsnode;
	_tmp1_ = string_to_string (_tmp0_);
	_tmp2_ = g_strconcat ("<", _tmp1_, ">", NULL);
	result = _tmp2_;
	return result;
}


static void palm_pre_ambient_light_onInputEvent (PalmPreAmbientLight* self, void* data, gssize length) {
	void* _tmp0_;
	struct input_event* event;
	gboolean _tmp1_ = FALSE;
	struct input_event* _tmp2_;
	guint16 _tmp3_;
	gboolean _tmp6_;
	struct input_event* _tmp7_;
	gint32 _tmp8_;
	gint _tmp9_ = 0;
	g_return_if_fail (self != NULL);
	_tmp0_ = data;
	event = (struct input_event*) _tmp0_;
	_tmp2_ = event;
	_tmp3_ = (*_tmp2_).type;
	if (((gint) _tmp3_) != 3) {
		_tmp1_ = TRUE;
	} else {
		struct input_event* _tmp4_;
		guint16 _tmp5_;
		_tmp4_ = event;
		_tmp5_ = (*_tmp4_).code;
		_tmp1_ = ((gint) _tmp5_) != 40;
	}
	_tmp6_ = _tmp1_;
	if (_tmp6_) {
		return;
	}
	_tmp7_ = event;
	_tmp8_ = (*_tmp7_).value;
	_tmp9_ = _palm_pre_ambient_light_valueToPercent (self, (gint) _tmp8_);
	palm_pre_ambient_light_set_brightness (self, _tmp9_);
}


static gint _palm_pre_ambient_light_valueToPercent (PalmPreAmbientLight* self, gint value) {
	gint result = 0;
	gint _tmp0_;
	gdouble v;
	gint _tmp1_;
	gint _tmp2_;
	gint _tmp3_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = value;
	v = (gdouble) _tmp0_;
	_tmp1_ = self->priv->maxvalue;
	_tmp2_ = self->priv->minvalue;
	_tmp3_ = self->priv->minvalue;
	result = (gint) ((100.0 / (_tmp1_ - _tmp2_)) * (v - _tmp3_));
	return result;
}


static void palm_pre_ambient_light_real_get_ambient_light_brightness_data_free (gpointer _data) {
	PalmPreAmbientLightGetAmbientLightBrightnessData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (PalmPreAmbientLightGetAmbientLightBrightnessData, _data_);
}


static void palm_pre_ambient_light_real_get_ambient_light_brightness (FreeSmartphoneDeviceAmbientLight* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	PalmPreAmbientLight * self;
	PalmPreAmbientLightGetAmbientLightBrightnessData* _data_;
	PalmPreAmbientLight* _tmp0_;
	self = (PalmPreAmbientLight*) base;
	_data_ = g_slice_new0 (PalmPreAmbientLightGetAmbientLightBrightnessData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, palm_pre_ambient_light_real_get_ambient_light_brightness);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, palm_pre_ambient_light_real_get_ambient_light_brightness_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	palm_pre_ambient_light_real_get_ambient_light_brightness_co (_data_);
}


static void palm_pre_ambient_light_real_get_ambient_light_brightness_finish (FreeSmartphoneDeviceAmbientLight* base, GAsyncResult* _res_, gint* brightness, gint* timestamp, GError** error) {
	PalmPreAmbientLightGetAmbientLightBrightnessData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	if (brightness) {
		*brightness = _data_->brightness;
	}
	if (timestamp) {
		*timestamp = _data_->timestamp;
	}
}


static gboolean palm_pre_ambient_light_real_get_ambient_light_brightness_co (PalmPreAmbientLightGetAmbientLightBrightnessData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = palm_pre_ambient_light_get_brightness (_data_->self);
	_data_->_tmp1_ = _data_->_tmp0_;
	_data_->brightness = _data_->_tmp1_;
	_data_->_tmp2_ = _data_->self->priv->brightness_timestamp;
	_data_->timestamp = _data_->_tmp2_;
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static gint palm_pre_ambient_light_get_brightness (PalmPreAmbientLight* self) {
	gint result;
	gint _tmp0_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->_brightness;
	result = _tmp0_;
	return result;
}


static void palm_pre_ambient_light_set_brightness (PalmPreAmbientLight* self, gint value) {
	gint _tmp0_;
	gint _tmp1_;
	gint _tmp2_;
	GTimeVal tv = {0};
	GTimeVal _tmp6_;
	glong _tmp7_;
	glong _tmp8_;
	g_return_if_fail (self != NULL);
	_tmp0_ = palm_pre_ambient_light_get_brightness (self);
	_tmp1_ = _tmp0_;
	_tmp2_ = value;
	if (_tmp1_ != _tmp2_) {
		gint _tmp3_;
		gint _tmp4_;
		gint _tmp5_;
		_tmp3_ = value;
		self->priv->_brightness = _tmp3_;
		_tmp4_ = palm_pre_ambient_light_get_brightness (self);
		_tmp5_ = _tmp4_;
		g_signal_emit_by_name ((FreeSmartphoneDeviceAmbientLight*) self, "ambient-light-brightness", _tmp5_);
	}
	g_get_current_time (&tv);
	g_get_current_time (&tv);
	_tmp6_ = tv;
	_tmp7_ = _tmp6_.tv_sec;
	_tmp8_ = self->priv->start_timestamp;
	self->priv->brightness_timestamp = (gint) (_tmp7_ - _tmp8_);
}


static void palm_pre_ambient_light_class_init (PalmPreAmbientLightClass * klass) {
	palm_pre_ambient_light_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (PalmPreAmbientLightPrivate));
	FSO_FRAMEWORK_ABSTRACT_OBJECT_CLASS (klass)->repr = palm_pre_ambient_light_real_repr;
	G_OBJECT_CLASS (klass)->get_property = _vala_palm_pre_ambient_light_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_palm_pre_ambient_light_set_property;
	G_OBJECT_CLASS (klass)->finalize = palm_pre_ambient_light_finalize;
}


static void palm_pre_ambient_light_free_smartphone_device_ambient_light_interface_init (FreeSmartphoneDeviceAmbientLightIface * iface) {
	palm_pre_ambient_light_free_smartphone_device_ambient_light_parent_iface = g_type_interface_peek_parent (iface);
	iface->get_ambient_light_brightness = (void (*)(FreeSmartphoneDeviceAmbientLight*, gint*, gint*, GError**)) palm_pre_ambient_light_real_get_ambient_light_brightness;
	iface->get_ambient_light_brightness_finish = palm_pre_ambient_light_real_get_ambient_light_brightness_finish;
}


static void palm_pre_ambient_light_instance_init (PalmPreAmbientLight * self) {
	self->priv = PALM_PRE_AMBIENT_LIGHT_GET_PRIVATE (self);
	self->priv->brightness_timestamp = -1;
	self->priv->_brightness = -1;
}


static void palm_pre_ambient_light_finalize (GObject* obj) {
	PalmPreAmbientLight * self;
	self = PALM_PRE_AMBIENT_LIGHT (obj);
	_g_object_unref0 (self->priv->subsystem);
	_g_free0 (self->priv->sysfsnode);
	_g_free0 (self->priv->resultnode);
	_g_free0 (self->priv->averagenode);
	_g_free0 (self->priv->pollintervalnode);
	_g_object_unref0 (self->priv->input);
	G_OBJECT_CLASS (palm_pre_ambient_light_parent_class)->finalize (obj);
}


GType palm_pre_ambient_light_get_type (void) {
	return palm_pre_ambient_light_type_id;
}


GType palm_pre_ambient_light_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (PalmPreAmbientLightClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) palm_pre_ambient_light_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (PalmPreAmbientLight), 0, (GInstanceInitFunc) palm_pre_ambient_light_instance_init, NULL };
	static const GInterfaceInfo free_smartphone_device_ambient_light_info = { (GInterfaceInitFunc) palm_pre_ambient_light_free_smartphone_device_ambient_light_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	palm_pre_ambient_light_type_id = g_type_module_register_type (module, FSO_FRAMEWORK_TYPE_ABSTRACT_OBJECT, "PalmPreAmbientLight", &g_define_type_info, 0);
	g_type_module_add_interface (module, palm_pre_ambient_light_type_id, FREE_SMARTPHONE_DEVICE_TYPE_AMBIENT_LIGHT, &free_smartphone_device_ambient_light_info);
	return palm_pre_ambient_light_type_id;
}


static void _vala_palm_pre_ambient_light_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	PalmPreAmbientLight * self;
	self = PALM_PRE_AMBIENT_LIGHT (object);
	switch (property_id) {
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_palm_pre_ambient_light_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	PalmPreAmbientLight * self;
	self = PALM_PRE_AMBIENT_LIGHT (object);
	switch (property_id) {
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


