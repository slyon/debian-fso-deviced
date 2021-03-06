/* plugin.c generated by valac 0.16.1, the Vala compiler
 * generated from plugin.vala, do not modify */

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
#include <fsobasics.h>
#include <freesmartphone.h>
#include <fsoframework.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include <gio/gio.h>


#define VIBRATOR_TYPE_OMAP_VIBE (vibrator_omap_vibe_get_type ())
#define VIBRATOR_OMAP_VIBE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VIBRATOR_TYPE_OMAP_VIBE, VibratorOmapVibe))
#define VIBRATOR_OMAP_VIBE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VIBRATOR_TYPE_OMAP_VIBE, VibratorOmapVibeClass))
#define VIBRATOR_IS_OMAP_VIBE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VIBRATOR_TYPE_OMAP_VIBE))
#define VIBRATOR_IS_OMAP_VIBE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VIBRATOR_TYPE_OMAP_VIBE))
#define VIBRATOR_OMAP_VIBE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VIBRATOR_TYPE_OMAP_VIBE, VibratorOmapVibeClass))

typedef struct _VibratorOmapVibe VibratorOmapVibe;
typedef struct _VibratorOmapVibeClass VibratorOmapVibeClass;
typedef struct _VibratorOmapVibePrivate VibratorOmapVibePrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _VibratorOmapVibeGetNameData VibratorOmapVibeGetNameData;
typedef struct _VibratorOmapVibeVibratePatternData VibratorOmapVibeVibratePatternData;
typedef struct _VibratorOmapVibeVibrateData VibratorOmapVibeVibrateData;
typedef struct _VibratorOmapVibeStopData VibratorOmapVibeStopData;

struct _VibratorOmapVibe {
	FsoFrameworkAbstractObject parent_instance;
	VibratorOmapVibePrivate * priv;
};

struct _VibratorOmapVibeClass {
	FsoFrameworkAbstractObjectClass parent_class;
};

struct _VibratorOmapVibePrivate {
	FsoFrameworkSubsystem* subsystem;
	gchar* sysfsnode;
	gchar* direction;
	gint max_strength;
	guint fulltimeoutwatch;
	guint smalltimeoutwatch;
	guint don;
	guint doff;
	gboolean on;
	gint pulses;
	gint strength;
};

struct _VibratorOmapVibeGetNameData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	VibratorOmapVibe* self;
	gchar* result;
	const gchar* _tmp0_;
	gchar* _tmp1_;
};

struct _VibratorOmapVibeVibratePatternData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	VibratorOmapVibe* self;
	gint pulses;
	gint delay_on;
	gint delay_off;
	gint strength;
	gboolean _tmp0_;
	gint _tmp1_;
	guint _tmp2_;
	gboolean _tmp3_;
	GError* _tmp4_;
	gint _tmp5_;
	GError* _tmp6_;
	gint _tmp7_;
	GError* _tmp8_;
	gint _tmp9_;
	GError* _tmp10_;
	gint _tmp11_;
	gint _tmp12_;
	gint _tmp13_;
	gint _tmp14_;
	GError * _inner_error_;
};

struct _VibratorOmapVibeVibrateData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	VibratorOmapVibe* self;
	gint milliseconds;
	gint strength;
	gboolean _tmp0_;
	gint _tmp1_;
	guint _tmp2_;
	gboolean _tmp3_;
	GError* _tmp4_;
	gint _tmp5_;
	GError* _tmp6_;
	gint _tmp7_;
	gint _tmp8_;
	guint _tmp9_;
	GError * _inner_error_;
};

struct _VibratorOmapVibeStopData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	VibratorOmapVibe* self;
};


static gpointer vibrator_omap_vibe_parent_class = NULL;
static FreeSmartphoneDeviceVibratorIface* vibrator_omap_vibe_free_smartphone_device_vibrator_parent_iface = NULL;
static GType vibrator_omap_vibe_type_id = 0;
extern gchar* sysfs_root;
gchar* sysfs_root = NULL;
extern VibratorOmapVibe* instance;
VibratorOmapVibe* instance = NULL;

GType vibrator_omap_vibe_get_type (void) G_GNUC_CONST;
GType vibrator_omap_vibe_register_type (GTypeModule * module);
#define VIBRATOR_OMAP_VIBE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), VIBRATOR_TYPE_OMAP_VIBE, VibratorOmapVibePrivate))
enum  {
	VIBRATOR_OMAP_VIBE_DUMMY_PROPERTY
};
VibratorOmapVibe* vibrator_omap_vibe_new (FsoFrameworkSubsystem* subsystem, const gchar* sysfsnode);
VibratorOmapVibe* vibrator_omap_vibe_construct (GType object_type, FsoFrameworkSubsystem* subsystem, const gchar* sysfsnode);
static gchar* vibrator_omap_vibe_real_repr (FsoFrameworkAbstractObject* base);
static gint _vibrator_omap_vibe_valueToPercent (VibratorOmapVibe* self, gint value);
static guint _vibrator_omap_vibe_percentToValue (VibratorOmapVibe* self, guint percent);
static void vibrator_omap_vibe_set_vibration (VibratorOmapVibe* self, gint strength);
static gboolean vibrator_omap_vibe_onToggleTimeout (VibratorOmapVibe* self);
static gboolean _vibrator_omap_vibe_onToggleTimeout_gsource_func (gpointer self);
static void vibrator_omap_vibe_cleanTimeouts (VibratorOmapVibe* self);
static void vibrator_omap_vibe_get_name_data_free (gpointer _data);
void vibrator_omap_vibe_get_name (VibratorOmapVibe* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
gchar* vibrator_omap_vibe_get_name_finish (VibratorOmapVibe* self, GAsyncResult* _res_, GError** error);
static gboolean vibrator_omap_vibe_get_name_co (VibratorOmapVibeGetNameData* _data_);
static void vibrator_omap_vibe_real_vibrate_pattern_data_free (gpointer _data);
static void vibrator_omap_vibe_real_vibrate_pattern (FreeSmartphoneDeviceVibrator* base, gint pulses, gint delay_on, gint delay_off, gint strength, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean vibrator_omap_vibe_real_vibrate_pattern_co (VibratorOmapVibeVibratePatternData* _data_);
static void vibrator_omap_vibe_real_vibrate_data_free (gpointer _data);
static void vibrator_omap_vibe_real_vibrate (FreeSmartphoneDeviceVibrator* base, gint milliseconds, gint strength, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean vibrator_omap_vibe_real_vibrate_co (VibratorOmapVibeVibrateData* _data_);
static gboolean __lambda2_ (VibratorOmapVibe* self);
static gboolean ___lambda2__gsource_func (gpointer self);
static void vibrator_omap_vibe_real_stop_data_free (gpointer _data);
static void vibrator_omap_vibe_real_stop (FreeSmartphoneDeviceVibrator* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean vibrator_omap_vibe_real_stop_co (VibratorOmapVibeStopData* _data_);
static void vibrator_omap_vibe_finalize (GObject* obj);
gchar* fso_factory_function (FsoFrameworkSubsystem* subsystem, GError** error);
void fso_register_function (GTypeModule* module);


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


VibratorOmapVibe* vibrator_omap_vibe_construct (GType object_type, FsoFrameworkSubsystem* subsystem, const gchar* sysfsnode) {
	VibratorOmapVibe * self = NULL;
	FsoFrameworkSubsystem* _tmp0_;
	FsoFrameworkSubsystem* _tmp1_;
	const gchar* _tmp2_;
	gchar* _tmp3_;
	const gchar* _tmp4_;
	gchar* _tmp5_;
	const gchar* _tmp6_;
	gboolean _tmp7_ = FALSE;
	FsoFrameworkSubsystem* _tmp13_;
	FsoFrameworkLogger* _tmp14_;
	g_return_val_if_fail (subsystem != NULL, NULL);
	g_return_val_if_fail (sysfsnode != NULL, NULL);
	self = (VibratorOmapVibe*) fso_framework_abstract_object_construct (object_type);
	_tmp0_ = subsystem;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->subsystem);
	self->priv->subsystem = _tmp1_;
	_tmp2_ = sysfsnode;
	_tmp3_ = g_strdup (_tmp2_);
	_g_free0 (self->priv->sysfsnode);
	self->priv->sysfsnode = _tmp3_;
	_tmp4_ = sysfsnode;
	_tmp5_ = g_strconcat (_tmp4_, "/direction", NULL);
	_g_free0 (self->priv->direction);
	self->priv->direction = _tmp5_;
	_tmp6_ = self->priv->direction;
	_tmp7_ = fso_framework_file_handling_isPresent (_tmp6_);
	if (!_tmp7_) {
		FsoFrameworkLogger* _tmp8_;
		const gchar* _tmp9_;
		const gchar* _tmp10_ = NULL;
		gchar* _tmp11_ = NULL;
		gchar* _tmp12_;
		_tmp8_ = ((FsoFrameworkAbstractObject*) self)->logger;
		_tmp9_ = self->priv->direction;
		_tmp10_ = string_to_string (_tmp9_);
		_tmp11_ = g_strconcat ("sysfs class is damaged, missing ", _tmp10_, "; skipping.", NULL);
		_tmp12_ = _tmp11_;
		fso_framework_logger_error (_tmp8_, _tmp12_);
		_g_free0 (_tmp12_);
		return self;
	}
	_tmp13_ = subsystem;
	fso_framework_subsystem_registerObjectForService (_tmp13_, FREE_SMARTPHONE_DEVICE_TYPE_VIBRATOR, (GBoxedCopyFunc) g_object_ref, g_object_unref, FSO_FRAMEWORK_DEVICE_ServiceDBusName, FSO_FRAMEWORK_DEVICE_VibratorServicePath, (FreeSmartphoneDeviceVibrator*) self);
	_tmp14_ = ((FsoFrameworkAbstractObject*) self)->logger;
	fso_framework_logger_info (_tmp14_, "Created");
	return self;
}


VibratorOmapVibe* vibrator_omap_vibe_new (FsoFrameworkSubsystem* subsystem, const gchar* sysfsnode) {
	return vibrator_omap_vibe_construct (VIBRATOR_TYPE_OMAP_VIBE, subsystem, sysfsnode);
}


static gchar* vibrator_omap_vibe_real_repr (FsoFrameworkAbstractObject* base) {
	VibratorOmapVibe * self;
	gchar* result = NULL;
	const gchar* _tmp0_;
	const gchar* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	self = (VibratorOmapVibe*) base;
	_tmp0_ = self->priv->sysfsnode;
	_tmp1_ = string_to_string (_tmp0_);
	_tmp2_ = g_strconcat ("<", _tmp1_, ">", NULL);
	result = _tmp2_;
	return result;
}


static gint _vibrator_omap_vibe_valueToPercent (VibratorOmapVibe* self, gint value) {
	gint result = 0;
	gint _tmp0_;
	gdouble max;
	gint _tmp1_;
	gdouble v;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->max_strength;
	max = (gdouble) _tmp0_;
	_tmp1_ = value;
	v = (gdouble) _tmp1_;
	result = (gint) ((100.0 / max) * v);
	return result;
}


static guint _vibrator_omap_vibe_percentToValue (VibratorOmapVibe* self, guint percent) {
	guint result = 0U;
	guint _tmp0_;
	gdouble p;
	gint _tmp1_;
	gdouble max;
	gdouble value = 0.0;
	guint _tmp2_;
	gdouble _tmp7_;
	g_return_val_if_fail (self != NULL, 0U);
	_tmp0_ = percent;
	p = (gdouble) _tmp0_;
	_tmp1_ = self->priv->max_strength;
	max = (gdouble) _tmp1_;
	_tmp2_ = percent;
	if (_tmp2_ >= ((guint) 100)) {
		gint _tmp3_;
		_tmp3_ = self->priv->max_strength;
		value = (gdouble) _tmp3_;
	} else {
		guint _tmp4_;
		_tmp4_ = percent;
		if (_tmp4_ <= ((guint) 0)) {
			value = (gdouble) 0;
		} else {
			gdouble _tmp5_;
			gdouble _tmp6_;
			_tmp5_ = p;
			_tmp6_ = max;
			value = (_tmp5_ / 100.0) * _tmp6_;
		}
	}
	_tmp7_ = value;
	result = (guint) ((gint) _tmp7_);
	return result;
}


static void vibrator_omap_vibe_set_vibration (VibratorOmapVibe* self, gint strength) {
	const gchar* _tmp0_ = NULL;
	gint _tmp1_;
	const gchar* _tmp2_;
	const gchar* _tmp3_;
	gint _tmp4_;
	g_return_if_fail (self != NULL);
	_tmp1_ = strength;
	if (_tmp1_ > 0) {
		_tmp0_ = "1";
	} else {
		_tmp0_ = "0";
	}
	_tmp2_ = _tmp0_;
	_tmp3_ = self->priv->direction;
	fso_framework_file_handling_write (_tmp2_, _tmp3_, FALSE);
	_tmp4_ = strength;
	self->priv->on = _tmp4_ > 0;
}


static gboolean _vibrator_omap_vibe_onToggleTimeout_gsource_func (gpointer self) {
	gboolean result;
	result = vibrator_omap_vibe_onToggleTimeout (self);
	return result;
}


static gboolean vibrator_omap_vibe_onToggleTimeout (VibratorOmapVibe* self) {
	gboolean result = FALSE;
	gboolean _tmp0_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->on;
	if (!_tmp0_) {
		gint _tmp1_;
		guint _tmp2_;
		guint _tmp3_ = 0U;
		_tmp1_ = self->priv->strength;
		vibrator_omap_vibe_set_vibration (self, _tmp1_);
		_tmp2_ = self->priv->don;
		_tmp3_ = g_timeout_add_full (G_PRIORITY_DEFAULT, _tmp2_, _vibrator_omap_vibe_onToggleTimeout_gsource_func, g_object_ref (self), g_object_unref);
		self->priv->smalltimeoutwatch = _tmp3_;
	} else {
		gint _tmp4_;
		gint _tmp5_;
		vibrator_omap_vibe_set_vibration (self, 0);
		_tmp4_ = self->priv->pulses;
		self->priv->pulses = _tmp4_ - 1;
		_tmp5_ = self->priv->pulses;
		if (_tmp5_ > 0) {
			guint _tmp6_;
			guint _tmp7_ = 0U;
			_tmp6_ = self->priv->doff;
			_tmp7_ = g_timeout_add_full (G_PRIORITY_DEFAULT, _tmp6_, _vibrator_omap_vibe_onToggleTimeout_gsource_func, g_object_ref (self), g_object_unref);
			self->priv->smalltimeoutwatch = _tmp7_;
		}
	}
	result = FALSE;
	return result;
}


static void vibrator_omap_vibe_cleanTimeouts (VibratorOmapVibe* self) {
	guint _tmp0_;
	guint _tmp2_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->smalltimeoutwatch;
	if (_tmp0_ > ((guint) 0)) {
		guint _tmp1_;
		_tmp1_ = self->priv->smalltimeoutwatch;
		g_source_remove (_tmp1_);
		self->priv->smalltimeoutwatch = (guint) 0;
	}
	_tmp2_ = self->priv->fulltimeoutwatch;
	if (_tmp2_ > ((guint) 0)) {
		guint _tmp3_;
		_tmp3_ = self->priv->fulltimeoutwatch;
		g_source_remove (_tmp3_);
		self->priv->fulltimeoutwatch = (guint) 0;
	}
	self->priv->pulses = 0;
}


static void vibrator_omap_vibe_get_name_data_free (gpointer _data) {
	VibratorOmapVibeGetNameData* _data_;
	_data_ = _data;
	_g_free0 (_data_->result);
	_g_object_unref0 (_data_->self);
	g_slice_free (VibratorOmapVibeGetNameData, _data_);
}


void vibrator_omap_vibe_get_name (VibratorOmapVibe* self, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	VibratorOmapVibeGetNameData* _data_;
	VibratorOmapVibe* _tmp0_;
	_data_ = g_slice_new0 (VibratorOmapVibeGetNameData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, vibrator_omap_vibe_get_name);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, vibrator_omap_vibe_get_name_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	vibrator_omap_vibe_get_name_co (_data_);
}


gchar* vibrator_omap_vibe_get_name_finish (VibratorOmapVibe* self, GAsyncResult* _res_, GError** error) {
	gchar* result;
	VibratorOmapVibeGetNameData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return NULL;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	result = _data_->result;
	_data_->result = NULL;
	return result;
}


static gboolean vibrator_omap_vibe_get_name_co (VibratorOmapVibeGetNameData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = _data_->self->priv->sysfsnode;
	_data_->_tmp1_ = NULL;
	_data_->_tmp1_ = g_path_get_basename (_data_->_tmp0_);
	_data_->result = _data_->_tmp1_;
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


static void vibrator_omap_vibe_real_vibrate_pattern_data_free (gpointer _data) {
	VibratorOmapVibeVibratePatternData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (VibratorOmapVibeVibratePatternData, _data_);
}


static void vibrator_omap_vibe_real_vibrate_pattern (FreeSmartphoneDeviceVibrator* base, gint pulses, gint delay_on, gint delay_off, gint strength, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	VibratorOmapVibe * self;
	VibratorOmapVibeVibratePatternData* _data_;
	VibratorOmapVibe* _tmp0_;
	gint _tmp1_;
	gint _tmp2_;
	gint _tmp3_;
	gint _tmp4_;
	self = (VibratorOmapVibe*) base;
	_data_ = g_slice_new0 (VibratorOmapVibeVibratePatternData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, vibrator_omap_vibe_real_vibrate_pattern);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, vibrator_omap_vibe_real_vibrate_pattern_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	_tmp1_ = pulses;
	_data_->pulses = _tmp1_;
	_tmp2_ = delay_on;
	_data_->delay_on = _tmp2_;
	_tmp3_ = delay_off;
	_data_->delay_off = _tmp3_;
	_tmp4_ = strength;
	_data_->strength = _tmp4_;
	vibrator_omap_vibe_real_vibrate_pattern_co (_data_);
}


static void vibrator_omap_vibe_real_vibrate_pattern_finish (FreeSmartphoneDeviceVibrator* base, GAsyncResult* _res_, GError** error) {
	VibratorOmapVibeVibratePatternData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static gboolean vibrator_omap_vibe_real_vibrate_pattern_co (VibratorOmapVibeVibratePatternData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp1_ = _data_->self->priv->pulses;
	if (_data_->_tmp1_ > 0) {
		_data_->_tmp0_ = TRUE;
	} else {
		_data_->_tmp2_ = _data_->self->priv->fulltimeoutwatch;
		_data_->_tmp0_ = _data_->_tmp2_ > ((guint) 0);
	}
	_data_->_tmp3_ = _data_->_tmp0_;
	if (_data_->_tmp3_) {
		_data_->_tmp4_ = g_error_new_literal (FREE_SMARTPHONE_ERROR, FREE_SMARTPHONE_ERROR_INVALID_PARAMETER, "Already vibrating... please try again");
		_data_->_inner_error_ = _data_->_tmp4_;
		if (((_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR) || (_data_->_inner_error_->domain == G_DBUS_ERROR)) || (_data_->_inner_error_->domain == G_IO_ERROR)) {
			g_simple_async_result_set_from_error (_data_->_async_result, _data_->_inner_error_);
			g_error_free (_data_->_inner_error_);
			if (_data_->_state_ == 0) {
				g_simple_async_result_complete_in_idle (_data_->_async_result);
			} else {
				g_simple_async_result_complete (_data_->_async_result);
			}
			g_object_unref (_data_->_async_result);
			return FALSE;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
			g_clear_error (&_data_->_inner_error_);
			return FALSE;
		}
	}
	_data_->_tmp5_ = _data_->pulses;
	if (_data_->_tmp5_ < 1) {
		_data_->_tmp6_ = g_error_new_literal (FREE_SMARTPHONE_ERROR, FREE_SMARTPHONE_ERROR_INVALID_PARAMETER, "Number of pulses needs to be at least 1");
		_data_->_inner_error_ = _data_->_tmp6_;
		if (((_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR) || (_data_->_inner_error_->domain == G_DBUS_ERROR)) || (_data_->_inner_error_->domain == G_IO_ERROR)) {
			g_simple_async_result_set_from_error (_data_->_async_result, _data_->_inner_error_);
			g_error_free (_data_->_inner_error_);
			if (_data_->_state_ == 0) {
				g_simple_async_result_complete_in_idle (_data_->_async_result);
			} else {
				g_simple_async_result_complete (_data_->_async_result);
			}
			g_object_unref (_data_->_async_result);
			return FALSE;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
			g_clear_error (&_data_->_inner_error_);
			return FALSE;
		}
	}
	_data_->_tmp7_ = _data_->delay_on;
	if (_data_->_tmp7_ < 50) {
		_data_->_tmp8_ = g_error_new_literal (FREE_SMARTPHONE_ERROR, FREE_SMARTPHONE_ERROR_INVALID_PARAMETER, "Delay on duration needs to be at least 50 milliseconds");
		_data_->_inner_error_ = _data_->_tmp8_;
		if (((_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR) || (_data_->_inner_error_->domain == G_DBUS_ERROR)) || (_data_->_inner_error_->domain == G_IO_ERROR)) {
			g_simple_async_result_set_from_error (_data_->_async_result, _data_->_inner_error_);
			g_error_free (_data_->_inner_error_);
			if (_data_->_state_ == 0) {
				g_simple_async_result_complete_in_idle (_data_->_async_result);
			} else {
				g_simple_async_result_complete (_data_->_async_result);
			}
			g_object_unref (_data_->_async_result);
			return FALSE;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
			g_clear_error (&_data_->_inner_error_);
			return FALSE;
		}
	}
	_data_->_tmp9_ = _data_->delay_off;
	if (_data_->_tmp9_ < 50) {
		_data_->_tmp10_ = g_error_new_literal (FREE_SMARTPHONE_ERROR, FREE_SMARTPHONE_ERROR_INVALID_PARAMETER, "Delay off duration needs to be at least 50 milliseconds");
		_data_->_inner_error_ = _data_->_tmp10_;
		if (((_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR) || (_data_->_inner_error_->domain == G_DBUS_ERROR)) || (_data_->_inner_error_->domain == G_IO_ERROR)) {
			g_simple_async_result_set_from_error (_data_->_async_result, _data_->_inner_error_);
			g_error_free (_data_->_inner_error_);
			if (_data_->_state_ == 0) {
				g_simple_async_result_complete_in_idle (_data_->_async_result);
			} else {
				g_simple_async_result_complete (_data_->_async_result);
			}
			g_object_unref (_data_->_async_result);
			return FALSE;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
			g_clear_error (&_data_->_inner_error_);
			return FALSE;
		}
	}
	_data_->_tmp11_ = _data_->delay_on;
	_data_->self->priv->don = (guint) _data_->_tmp11_;
	_data_->_tmp12_ = _data_->delay_off;
	_data_->self->priv->doff = (guint) _data_->_tmp12_;
	_data_->_tmp13_ = _data_->pulses;
	_data_->self->priv->pulses = _data_->_tmp13_;
	_data_->_tmp14_ = _data_->strength;
	_data_->self->priv->strength = _data_->_tmp14_;
	vibrator_omap_vibe_onToggleTimeout (_data_->self);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void vibrator_omap_vibe_real_vibrate_data_free (gpointer _data) {
	VibratorOmapVibeVibrateData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (VibratorOmapVibeVibrateData, _data_);
}


static void vibrator_omap_vibe_real_vibrate (FreeSmartphoneDeviceVibrator* base, gint milliseconds, gint strength, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	VibratorOmapVibe * self;
	VibratorOmapVibeVibrateData* _data_;
	VibratorOmapVibe* _tmp0_;
	gint _tmp1_;
	gint _tmp2_;
	self = (VibratorOmapVibe*) base;
	_data_ = g_slice_new0 (VibratorOmapVibeVibrateData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, vibrator_omap_vibe_real_vibrate);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, vibrator_omap_vibe_real_vibrate_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	_tmp1_ = milliseconds;
	_data_->milliseconds = _tmp1_;
	_tmp2_ = strength;
	_data_->strength = _tmp2_;
	vibrator_omap_vibe_real_vibrate_co (_data_);
}


static void vibrator_omap_vibe_real_vibrate_finish (FreeSmartphoneDeviceVibrator* base, GAsyncResult* _res_, GError** error) {
	VibratorOmapVibeVibrateData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static gboolean __lambda2_ (VibratorOmapVibe* self) {
	gboolean result = FALSE;
	vibrator_omap_vibe_cleanTimeouts (self);
	vibrator_omap_vibe_set_vibration (self, 0);
	result = FALSE;
	return result;
}


static gboolean ___lambda2__gsource_func (gpointer self) {
	gboolean result;
	result = __lambda2_ (self);
	return result;
}


static gboolean vibrator_omap_vibe_real_vibrate_co (VibratorOmapVibeVibrateData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp1_ = _data_->self->priv->pulses;
	if (_data_->_tmp1_ > 0) {
		_data_->_tmp0_ = TRUE;
	} else {
		_data_->_tmp2_ = _data_->self->priv->fulltimeoutwatch;
		_data_->_tmp0_ = _data_->_tmp2_ > ((guint) 0);
	}
	_data_->_tmp3_ = _data_->_tmp0_;
	if (_data_->_tmp3_) {
		_data_->_tmp4_ = g_error_new_literal (FREE_SMARTPHONE_ERROR, FREE_SMARTPHONE_ERROR_INVALID_PARAMETER, "Already vibrating... please try again");
		_data_->_inner_error_ = _data_->_tmp4_;
		if (((_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR) || (_data_->_inner_error_->domain == G_DBUS_ERROR)) || (_data_->_inner_error_->domain == G_IO_ERROR)) {
			g_simple_async_result_set_from_error (_data_->_async_result, _data_->_inner_error_);
			g_error_free (_data_->_inner_error_);
			if (_data_->_state_ == 0) {
				g_simple_async_result_complete_in_idle (_data_->_async_result);
			} else {
				g_simple_async_result_complete (_data_->_async_result);
			}
			g_object_unref (_data_->_async_result);
			return FALSE;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
			g_clear_error (&_data_->_inner_error_);
			return FALSE;
		}
	}
	_data_->_tmp5_ = _data_->milliseconds;
	if (_data_->_tmp5_ < 50) {
		_data_->_tmp6_ = g_error_new_literal (FREE_SMARTPHONE_ERROR, FREE_SMARTPHONE_ERROR_INVALID_PARAMETER, "Vibration time needs to be at least 50 milliseconds");
		_data_->_inner_error_ = _data_->_tmp6_;
		if (((_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR) || (_data_->_inner_error_->domain == G_DBUS_ERROR)) || (_data_->_inner_error_->domain == G_IO_ERROR)) {
			g_simple_async_result_set_from_error (_data_->_async_result, _data_->_inner_error_);
			g_error_free (_data_->_inner_error_);
			if (_data_->_state_ == 0) {
				g_simple_async_result_complete_in_idle (_data_->_async_result);
			} else {
				g_simple_async_result_complete (_data_->_async_result);
			}
			g_object_unref (_data_->_async_result);
			return FALSE;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
			g_clear_error (&_data_->_inner_error_);
			return FALSE;
		}
	}
	vibrator_omap_vibe_cleanTimeouts (_data_->self);
	_data_->_tmp7_ = _data_->strength;
	vibrator_omap_vibe_set_vibration (_data_->self, _data_->_tmp7_);
	_data_->_tmp8_ = _data_->milliseconds;
	_data_->_tmp9_ = 0U;
	_data_->_tmp9_ = g_timeout_add_full (G_PRIORITY_DEFAULT, (guint) _data_->_tmp8_, ___lambda2__gsource_func, g_object_ref (_data_->self), g_object_unref);
	_data_->self->priv->fulltimeoutwatch = _data_->_tmp9_;
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void vibrator_omap_vibe_real_stop_data_free (gpointer _data) {
	VibratorOmapVibeStopData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (VibratorOmapVibeStopData, _data_);
}


static void vibrator_omap_vibe_real_stop (FreeSmartphoneDeviceVibrator* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	VibratorOmapVibe * self;
	VibratorOmapVibeStopData* _data_;
	VibratorOmapVibe* _tmp0_;
	self = (VibratorOmapVibe*) base;
	_data_ = g_slice_new0 (VibratorOmapVibeStopData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, vibrator_omap_vibe_real_stop);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, vibrator_omap_vibe_real_stop_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	vibrator_omap_vibe_real_stop_co (_data_);
}


static void vibrator_omap_vibe_real_stop_finish (FreeSmartphoneDeviceVibrator* base, GAsyncResult* _res_, GError** error) {
	VibratorOmapVibeStopData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static gboolean vibrator_omap_vibe_real_stop_co (VibratorOmapVibeStopData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	vibrator_omap_vibe_cleanTimeouts (_data_->self);
	vibrator_omap_vibe_set_vibration (_data_->self, 0);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void vibrator_omap_vibe_class_init (VibratorOmapVibeClass * klass) {
	vibrator_omap_vibe_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (VibratorOmapVibePrivate));
	FSO_FRAMEWORK_ABSTRACT_OBJECT_CLASS (klass)->repr = vibrator_omap_vibe_real_repr;
	G_OBJECT_CLASS (klass)->finalize = vibrator_omap_vibe_finalize;
}


static void vibrator_omap_vibe_free_smartphone_device_vibrator_interface_init (FreeSmartphoneDeviceVibratorIface * iface) {
	vibrator_omap_vibe_free_smartphone_device_vibrator_parent_iface = g_type_interface_peek_parent (iface);
	iface->vibrate_pattern = (void (*)(FreeSmartphoneDeviceVibrator*, gint, gint, gint, gint, GError**)) vibrator_omap_vibe_real_vibrate_pattern;
	iface->vibrate_pattern_finish = vibrator_omap_vibe_real_vibrate_pattern_finish;
	iface->vibrate = (void (*)(FreeSmartphoneDeviceVibrator*, gint, gint, GError**)) vibrator_omap_vibe_real_vibrate;
	iface->vibrate_finish = vibrator_omap_vibe_real_vibrate_finish;
	iface->stop = (void (*)(FreeSmartphoneDeviceVibrator*, GError**)) vibrator_omap_vibe_real_stop;
	iface->stop_finish = vibrator_omap_vibe_real_stop_finish;
}


static void vibrator_omap_vibe_instance_init (VibratorOmapVibe * self) {
	self->priv = VIBRATOR_OMAP_VIBE_GET_PRIVATE (self);
}


static void vibrator_omap_vibe_finalize (GObject* obj) {
	VibratorOmapVibe * self;
	self = VIBRATOR_OMAP_VIBE (obj);
	_g_object_unref0 (self->priv->subsystem);
	_g_free0 (self->priv->sysfsnode);
	_g_free0 (self->priv->direction);
	G_OBJECT_CLASS (vibrator_omap_vibe_parent_class)->finalize (obj);
}


GType vibrator_omap_vibe_get_type (void) {
	return vibrator_omap_vibe_type_id;
}


GType vibrator_omap_vibe_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (VibratorOmapVibeClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vibrator_omap_vibe_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (VibratorOmapVibe), 0, (GInstanceInitFunc) vibrator_omap_vibe_instance_init, NULL };
	static const GInterfaceInfo free_smartphone_device_vibrator_info = { (GInterfaceInitFunc) vibrator_omap_vibe_free_smartphone_device_vibrator_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	vibrator_omap_vibe_type_id = g_type_module_register_type (module, FSO_FRAMEWORK_TYPE_ABSTRACT_OBJECT, "VibratorOmapVibe", &g_define_type_info, 0);
	g_type_module_add_interface (module, vibrator_omap_vibe_type_id, FREE_SMARTPHONE_DEVICE_TYPE_VIBRATOR, &free_smartphone_device_vibrator_info);
	return vibrator_omap_vibe_type_id;
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
	FsoFrameworkSmartKeyFile* _tmp2_;
	gchar* _tmp3_ = NULL;
	const gchar* _tmp4_;
	gchar* _tmp5_ = NULL;
	gchar* dirname;
	const gchar* _tmp6_;
	gboolean _tmp7_ = FALSE;
	gchar* _tmp12_;
	g_return_val_if_fail (subsystem != NULL, NULL);
	_tmp0_ = fso_framework_theConfig;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	config = _tmp1_;
	_tmp2_ = config;
	_tmp3_ = fso_framework_smart_key_file_stringValue (_tmp2_, "cornucopia", "sysfs_root", "/sys");
	_g_free0 (sysfs_root);
	sysfs_root = _tmp3_;
	_tmp4_ = sysfs_root;
	_tmp5_ = g_build_filename (_tmp4_, "bus", "platform", "devices", "omap_vibe", NULL);
	dirname = _tmp5_;
	_tmp6_ = dirname;
	_tmp7_ = fso_framework_file_handling_isPresent (_tmp6_);
	if (_tmp7_) {
		FsoFrameworkSubsystem* _tmp8_;
		const gchar* _tmp9_;
		VibratorOmapVibe* _tmp10_;
		_tmp8_ = subsystem;
		_tmp9_ = dirname;
		_tmp10_ = vibrator_omap_vibe_new (_tmp8_, _tmp9_);
		_g_object_unref0 (instance);
		instance = _tmp10_;
	} else {
		FsoFrameworkLogger* _tmp11_;
		_tmp11_ = fso_framework_theLogger;
		fso_framework_logger_error (_tmp11_, "No omap_vibe device found; vibrator object will not be available");
	}
	_tmp12_ = g_strdup ("fsodevice.vibrator_omapvibes");
	result = _tmp12_;
	_g_free0 (dirname);
	_g_object_unref0 (config);
	return result;
}


void fso_register_function (GTypeModule* module) {
	FsoFrameworkLogger* _tmp0_;
	g_return_if_fail (module != NULL);
	vibrator_omap_vibe_register_type (module);
	_tmp0_ = fso_framework_theLogger;
	fso_framework_logger_debug (_tmp0_, "fsodevice.vibrator_omapvibe fso_register_function()");
}



