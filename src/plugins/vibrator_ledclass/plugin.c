/* plugin.c generated by valac 0.16.1, the Vala compiler
 * generated from plugin.vala, do not modify */


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


#define VIBRATOR_TYPE_LEDCLASS (vibrator_ledclass_get_type ())
#define VIBRATOR_LEDCLASS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VIBRATOR_TYPE_LEDCLASS, VibratorLedClass))
#define VIBRATOR_LEDCLASS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VIBRATOR_TYPE_LEDCLASS, VibratorLedClassClass))
#define VIBRATOR_IS_LEDCLASS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VIBRATOR_TYPE_LEDCLASS))
#define VIBRATOR_IS_LEDCLASS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VIBRATOR_TYPE_LEDCLASS))
#define VIBRATOR_LEDCLASS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VIBRATOR_TYPE_LEDCLASS, VibratorLedClassClass))

typedef struct _VibratorLedClass VibratorLedClass;
typedef struct _VibratorLedClassClass VibratorLedClassClass;
typedef struct _VibratorLedClassPrivate VibratorLedClassPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _VibratorLedclassGetNameData VibratorLedclassGetNameData;
typedef struct _VibratorLedclassVibratePatternData VibratorLedclassVibratePatternData;
typedef struct _VibratorLedclassVibrateData VibratorLedclassVibrateData;
typedef struct _VibratorLedclassStopData VibratorLedclassStopData;
#define _g_dir_close0(var) ((var == NULL) ? NULL : (var = (g_dir_close (var), NULL)))

struct _VibratorLedClass {
	FsoFrameworkAbstractObject parent_instance;
	VibratorLedClassPrivate * priv;
};

struct _VibratorLedClassClass {
	FsoFrameworkAbstractObjectClass parent_class;
};

struct _VibratorLedClassPrivate {
	FsoFrameworkSubsystem* subsystem;
	gint max_brightness;
	gchar* sysfsnode;
	gchar* brightness;
	guint fulltimeoutwatch;
	guint smalltimeoutwatch;
	guint don;
	guint doff;
	gboolean on;
	gint pulses;
	gint strength;
};

struct _VibratorLedclassGetNameData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	VibratorLedClass* self;
	gchar* result;
	const gchar* _tmp0_;
	gchar* _tmp1_;
};

struct _VibratorLedclassVibratePatternData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	VibratorLedClass* self;
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

struct _VibratorLedclassVibrateData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	VibratorLedClass* self;
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

struct _VibratorLedclassStopData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	VibratorLedClass* self;
};


static gpointer vibrator_ledclass_parent_class = NULL;
static FreeSmartphoneDeviceVibratorIface* vibrator_ledclass_free_smartphone_device_vibrator_parent_iface = NULL;
static GType vibrator_ledclass_type_id = 0;
extern gchar* sysfs_root;
gchar* sysfs_root = NULL;
extern gchar* sys_class_net;
gchar* sys_class_net = NULL;
extern gchar* sys_class_leds;
gchar* sys_class_leds = NULL;
extern GList* instances;
GList* instances = NULL;

GType vibrator_ledclass_get_type (void) G_GNUC_CONST;
GType vibrator_ledclass_register_type (GTypeModule * module);
#define VIBRATOR_LEDCLASS_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), VIBRATOR_TYPE_LEDCLASS, VibratorLedClassPrivate))
enum  {
	VIBRATOR_LEDCLASS_DUMMY_PROPERTY
};
VibratorLedClass* vibrator_ledclass_new (FsoFrameworkSubsystem* subsystem, const gchar* sysfsnode);
VibratorLedClass* vibrator_ledclass_construct (GType object_type, FsoFrameworkSubsystem* subsystem, const gchar* sysfsnode);
static gchar* vibrator_ledclass_real_repr (FsoFrameworkAbstractObject* base);
static gint _vibrator_ledclass_valueToPercent (VibratorLedClass* self, gint value);
static guint _vibrator_ledclass_percentToValue (VibratorLedClass* self, guint percent);
static void vibrator_ledclass_set_brightness (VibratorLedClass* self, gint brightness);
static gboolean vibrator_ledclass_onToggleTimeout (VibratorLedClass* self);
static gboolean _vibrator_ledclass_onToggleTimeout_gsource_func (gpointer self);
static void vibrator_ledclass_cleanTimeouts (VibratorLedClass* self);
static void vibrator_ledclass_get_name_data_free (gpointer _data);
void vibrator_ledclass_get_name (VibratorLedClass* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
gchar* vibrator_ledclass_get_name_finish (VibratorLedClass* self, GAsyncResult* _res_, GError** error);
static gboolean vibrator_ledclass_get_name_co (VibratorLedclassGetNameData* _data_);
static void vibrator_ledclass_real_vibrate_pattern_data_free (gpointer _data);
static void vibrator_ledclass_real_vibrate_pattern (FreeSmartphoneDeviceVibrator* base, gint pulses, gint delay_on, gint delay_off, gint strength, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean vibrator_ledclass_real_vibrate_pattern_co (VibratorLedclassVibratePatternData* _data_);
static void vibrator_ledclass_real_vibrate_data_free (gpointer _data);
static void vibrator_ledclass_real_vibrate (FreeSmartphoneDeviceVibrator* base, gint milliseconds, gint strength, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean vibrator_ledclass_real_vibrate_co (VibratorLedclassVibrateData* _data_);
static gboolean __lambda2_ (VibratorLedClass* self);
static gboolean ___lambda2__gsource_func (gpointer self);
static void vibrator_ledclass_real_stop_data_free (gpointer _data);
static void vibrator_ledclass_real_stop (FreeSmartphoneDeviceVibrator* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean vibrator_ledclass_real_stop_co (VibratorLedclassStopData* _data_);
static void vibrator_ledclass_finalize (GObject* obj);
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


VibratorLedClass* vibrator_ledclass_construct (GType object_type, FsoFrameworkSubsystem* subsystem, const gchar* sysfsnode) {
	VibratorLedClass * self = NULL;
	FsoFrameworkSubsystem* _tmp0_;
	FsoFrameworkSubsystem* _tmp1_;
	const gchar* _tmp2_;
	gchar* _tmp3_;
	const gchar* _tmp4_;
	gchar* _tmp5_;
	gchar* _tmp6_;
	gchar* _tmp7_ = NULL;
	gchar* _tmp8_;
	gint _tmp9_ = 0;
	gint _tmp10_;
	const gchar* _tmp11_;
	gchar* _tmp12_;
	const gchar* _tmp13_;
	gboolean _tmp14_ = FALSE;
	FsoFrameworkSubsystem* _tmp20_;
	FsoFrameworkLogger* _tmp21_;
	g_return_val_if_fail (subsystem != NULL, NULL);
	g_return_val_if_fail (sysfsnode != NULL, NULL);
	self = (VibratorLedClass*) fso_framework_abstract_object_construct (object_type);
	_tmp0_ = subsystem;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->subsystem);
	self->priv->subsystem = _tmp1_;
	_tmp2_ = sysfsnode;
	_tmp3_ = g_strdup (_tmp2_);
	_g_free0 (self->priv->sysfsnode);
	self->priv->sysfsnode = _tmp3_;
	_tmp4_ = self->priv->sysfsnode;
	_tmp5_ = g_strconcat (_tmp4_, "/max_brightness", NULL);
	_tmp6_ = _tmp5_;
	_tmp7_ = fso_framework_file_handling_read (_tmp6_);
	_tmp8_ = _tmp7_;
	_tmp9_ = atoi (_tmp8_);
	self->priv->max_brightness = _tmp9_;
	_g_free0 (_tmp8_);
	_g_free0 (_tmp6_);
	_tmp10_ = self->priv->max_brightness;
	if (_tmp10_ == 0) {
		self->priv->max_brightness = 255;
	}
	_tmp11_ = sysfsnode;
	_tmp12_ = g_strconcat (_tmp11_, "/brightness", NULL);
	_g_free0 (self->priv->brightness);
	self->priv->brightness = _tmp12_;
	_tmp13_ = self->priv->brightness;
	_tmp14_ = fso_framework_file_handling_isPresent (_tmp13_);
	if (!_tmp14_) {
		FsoFrameworkLogger* _tmp15_;
		const gchar* _tmp16_;
		const gchar* _tmp17_ = NULL;
		gchar* _tmp18_ = NULL;
		gchar* _tmp19_;
		_tmp15_ = ((FsoFrameworkAbstractObject*) self)->logger;
		_tmp16_ = self->priv->brightness;
		_tmp17_ = string_to_string (_tmp16_);
		_tmp18_ = g_strconcat ("sysfs class is damaged, missing ", _tmp17_, "; skipping.", NULL);
		_tmp19_ = _tmp18_;
		fso_framework_logger_error (_tmp15_, _tmp19_);
		_g_free0 (_tmp19_);
		return self;
	}
	_tmp20_ = subsystem;
	fso_framework_subsystem_registerObjectForServiceWithPrefix (_tmp20_, FREE_SMARTPHONE_DEVICE_TYPE_VIBRATOR, (GBoxedCopyFunc) g_object_ref, g_object_unref, FSO_FRAMEWORK_DEVICE_ServiceDBusName, FSO_FRAMEWORK_DEVICE_VibratorServicePath, (FreeSmartphoneDeviceVibrator*) self);
	_tmp21_ = ((FsoFrameworkAbstractObject*) self)->logger;
	fso_framework_logger_info (_tmp21_, "Created");
	return self;
}


VibratorLedClass* vibrator_ledclass_new (FsoFrameworkSubsystem* subsystem, const gchar* sysfsnode) {
	return vibrator_ledclass_construct (VIBRATOR_TYPE_LEDCLASS, subsystem, sysfsnode);
}


static gchar* vibrator_ledclass_real_repr (FsoFrameworkAbstractObject* base) {
	VibratorLedClass * self;
	gchar* result = NULL;
	const gchar* _tmp0_;
	const gchar* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	self = (VibratorLedClass*) base;
	_tmp0_ = self->priv->sysfsnode;
	_tmp1_ = string_to_string (_tmp0_);
	_tmp2_ = g_strconcat ("<", _tmp1_, ">", NULL);
	result = _tmp2_;
	return result;
}


static gint _vibrator_ledclass_valueToPercent (VibratorLedClass* self, gint value) {
	gint result = 0;
	gint _tmp0_;
	gdouble max;
	gint _tmp1_;
	gdouble v;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->max_brightness;
	max = (gdouble) _tmp0_;
	_tmp1_ = value;
	v = (gdouble) _tmp1_;
	result = (gint) ((100.0 / max) * v);
	return result;
}


static guint _vibrator_ledclass_percentToValue (VibratorLedClass* self, guint percent) {
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
	_tmp1_ = self->priv->max_brightness;
	max = (gdouble) _tmp1_;
	_tmp2_ = percent;
	if (_tmp2_ >= ((guint) 100)) {
		gint _tmp3_;
		_tmp3_ = self->priv->max_brightness;
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


static void vibrator_ledclass_set_brightness (VibratorLedClass* self, gint brightness) {
	gint _tmp0_;
	guint _tmp1_ = 0U;
	guint percent;
	gchar* _tmp2_ = NULL;
	gchar* _tmp3_;
	const gchar* _tmp4_;
	g_return_if_fail (self != NULL);
	_tmp0_ = brightness;
	_tmp1_ = _vibrator_ledclass_percentToValue (self, (guint) _tmp0_);
	percent = _tmp1_;
	_tmp2_ = g_strdup_printf ("%u", percent);
	_tmp3_ = _tmp2_;
	_tmp4_ = self->priv->brightness;
	fso_framework_file_handling_write (_tmp3_, _tmp4_, FALSE);
	_g_free0 (_tmp3_);
	self->priv->on = percent > ((guint) 0);
}


static gboolean _vibrator_ledclass_onToggleTimeout_gsource_func (gpointer self) {
	gboolean result;
	result = vibrator_ledclass_onToggleTimeout (self);
	return result;
}


static gboolean vibrator_ledclass_onToggleTimeout (VibratorLedClass* self) {
	gboolean result = FALSE;
	gboolean _tmp0_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->on;
	if (!_tmp0_) {
		gint _tmp1_;
		guint _tmp2_;
		guint _tmp3_ = 0U;
		_tmp1_ = self->priv->strength;
		vibrator_ledclass_set_brightness (self, _tmp1_);
		_tmp2_ = self->priv->don;
		_tmp3_ = g_timeout_add_full (G_PRIORITY_DEFAULT, _tmp2_, _vibrator_ledclass_onToggleTimeout_gsource_func, g_object_ref (self), g_object_unref);
		self->priv->smalltimeoutwatch = _tmp3_;
	} else {
		gint _tmp4_;
		gint _tmp5_;
		vibrator_ledclass_set_brightness (self, 0);
		_tmp4_ = self->priv->pulses;
		self->priv->pulses = _tmp4_ - 1;
		_tmp5_ = self->priv->pulses;
		if (_tmp5_ > 0) {
			guint _tmp6_;
			guint _tmp7_ = 0U;
			_tmp6_ = self->priv->doff;
			_tmp7_ = g_timeout_add_full (G_PRIORITY_DEFAULT, _tmp6_, _vibrator_ledclass_onToggleTimeout_gsource_func, g_object_ref (self), g_object_unref);
			self->priv->smalltimeoutwatch = _tmp7_;
		}
	}
	result = FALSE;
	return result;
}


static void vibrator_ledclass_cleanTimeouts (VibratorLedClass* self) {
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


static void vibrator_ledclass_get_name_data_free (gpointer _data) {
	VibratorLedclassGetNameData* _data_;
	_data_ = _data;
	_g_free0 (_data_->result);
	_g_object_unref0 (_data_->self);
	g_slice_free (VibratorLedclassGetNameData, _data_);
}


void vibrator_ledclass_get_name (VibratorLedClass* self, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	VibratorLedclassGetNameData* _data_;
	VibratorLedClass* _tmp0_;
	_data_ = g_slice_new0 (VibratorLedclassGetNameData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, vibrator_ledclass_get_name);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, vibrator_ledclass_get_name_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	vibrator_ledclass_get_name_co (_data_);
}


gchar* vibrator_ledclass_get_name_finish (VibratorLedClass* self, GAsyncResult* _res_, GError** error) {
	gchar* result;
	VibratorLedclassGetNameData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return NULL;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	result = _data_->result;
	_data_->result = NULL;
	return result;
}


static gboolean vibrator_ledclass_get_name_co (VibratorLedclassGetNameData* _data_) {
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


static void vibrator_ledclass_real_vibrate_pattern_data_free (gpointer _data) {
	VibratorLedclassVibratePatternData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (VibratorLedclassVibratePatternData, _data_);
}


static void vibrator_ledclass_real_vibrate_pattern (FreeSmartphoneDeviceVibrator* base, gint pulses, gint delay_on, gint delay_off, gint strength, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	VibratorLedClass * self;
	VibratorLedclassVibratePatternData* _data_;
	VibratorLedClass* _tmp0_;
	gint _tmp1_;
	gint _tmp2_;
	gint _tmp3_;
	gint _tmp4_;
	self = (VibratorLedClass*) base;
	_data_ = g_slice_new0 (VibratorLedclassVibratePatternData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, vibrator_ledclass_real_vibrate_pattern);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, vibrator_ledclass_real_vibrate_pattern_data_free);
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
	vibrator_ledclass_real_vibrate_pattern_co (_data_);
}


static void vibrator_ledclass_real_vibrate_pattern_finish (FreeSmartphoneDeviceVibrator* base, GAsyncResult* _res_, GError** error) {
	VibratorLedclassVibratePatternData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static gboolean vibrator_ledclass_real_vibrate_pattern_co (VibratorLedclassVibratePatternData* _data_) {
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
	vibrator_ledclass_onToggleTimeout (_data_->self);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void vibrator_ledclass_real_vibrate_data_free (gpointer _data) {
	VibratorLedclassVibrateData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (VibratorLedclassVibrateData, _data_);
}


static void vibrator_ledclass_real_vibrate (FreeSmartphoneDeviceVibrator* base, gint milliseconds, gint strength, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	VibratorLedClass * self;
	VibratorLedclassVibrateData* _data_;
	VibratorLedClass* _tmp0_;
	gint _tmp1_;
	gint _tmp2_;
	self = (VibratorLedClass*) base;
	_data_ = g_slice_new0 (VibratorLedclassVibrateData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, vibrator_ledclass_real_vibrate);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, vibrator_ledclass_real_vibrate_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	_tmp1_ = milliseconds;
	_data_->milliseconds = _tmp1_;
	_tmp2_ = strength;
	_data_->strength = _tmp2_;
	vibrator_ledclass_real_vibrate_co (_data_);
}


static void vibrator_ledclass_real_vibrate_finish (FreeSmartphoneDeviceVibrator* base, GAsyncResult* _res_, GError** error) {
	VibratorLedclassVibrateData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static gboolean __lambda2_ (VibratorLedClass* self) {
	gboolean result = FALSE;
	vibrator_ledclass_cleanTimeouts (self);
	vibrator_ledclass_set_brightness (self, 0);
	result = FALSE;
	return result;
}


static gboolean ___lambda2__gsource_func (gpointer self) {
	gboolean result;
	result = __lambda2_ (self);
	return result;
}


static gboolean vibrator_ledclass_real_vibrate_co (VibratorLedclassVibrateData* _data_) {
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
	vibrator_ledclass_cleanTimeouts (_data_->self);
	_data_->_tmp7_ = _data_->strength;
	vibrator_ledclass_set_brightness (_data_->self, _data_->_tmp7_);
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


static void vibrator_ledclass_real_stop_data_free (gpointer _data) {
	VibratorLedclassStopData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (VibratorLedclassStopData, _data_);
}


static void vibrator_ledclass_real_stop (FreeSmartphoneDeviceVibrator* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	VibratorLedClass * self;
	VibratorLedclassStopData* _data_;
	VibratorLedClass* _tmp0_;
	self = (VibratorLedClass*) base;
	_data_ = g_slice_new0 (VibratorLedclassStopData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, vibrator_ledclass_real_stop);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, vibrator_ledclass_real_stop_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	vibrator_ledclass_real_stop_co (_data_);
}


static void vibrator_ledclass_real_stop_finish (FreeSmartphoneDeviceVibrator* base, GAsyncResult* _res_, GError** error) {
	VibratorLedclassStopData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static gboolean vibrator_ledclass_real_stop_co (VibratorLedclassStopData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	vibrator_ledclass_cleanTimeouts (_data_->self);
	vibrator_ledclass_set_brightness (_data_->self, 0);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void vibrator_ledclass_class_init (VibratorLedClassClass * klass) {
	vibrator_ledclass_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (VibratorLedClassPrivate));
	FSO_FRAMEWORK_ABSTRACT_OBJECT_CLASS (klass)->repr = vibrator_ledclass_real_repr;
	G_OBJECT_CLASS (klass)->finalize = vibrator_ledclass_finalize;
}


static void vibrator_ledclass_free_smartphone_device_vibrator_interface_init (FreeSmartphoneDeviceVibratorIface * iface) {
	vibrator_ledclass_free_smartphone_device_vibrator_parent_iface = g_type_interface_peek_parent (iface);
	iface->vibrate_pattern = (void (*)(FreeSmartphoneDeviceVibrator*, gint, gint, gint, gint, GError**)) vibrator_ledclass_real_vibrate_pattern;
	iface->vibrate_pattern_finish = vibrator_ledclass_real_vibrate_pattern_finish;
	iface->vibrate = (void (*)(FreeSmartphoneDeviceVibrator*, gint, gint, GError**)) vibrator_ledclass_real_vibrate;
	iface->vibrate_finish = vibrator_ledclass_real_vibrate_finish;
	iface->stop = (void (*)(FreeSmartphoneDeviceVibrator*, GError**)) vibrator_ledclass_real_stop;
	iface->stop_finish = vibrator_ledclass_real_stop_finish;
}


static void vibrator_ledclass_instance_init (VibratorLedClass * self) {
	self->priv = VIBRATOR_LEDCLASS_GET_PRIVATE (self);
}


static void vibrator_ledclass_finalize (GObject* obj) {
	VibratorLedClass * self;
	self = VIBRATOR_LEDCLASS (obj);
	_g_object_unref0 (self->priv->subsystem);
	_g_free0 (self->priv->sysfsnode);
	_g_free0 (self->priv->brightness);
	G_OBJECT_CLASS (vibrator_ledclass_parent_class)->finalize (obj);
}


GType vibrator_ledclass_get_type (void) {
	return vibrator_ledclass_type_id;
}


GType vibrator_ledclass_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (VibratorLedClassClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vibrator_ledclass_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (VibratorLedClass), 0, (GInstanceInitFunc) vibrator_ledclass_instance_init, NULL };
	static const GInterfaceInfo free_smartphone_device_vibrator_info = { (GInterfaceInitFunc) vibrator_ledclass_free_smartphone_device_vibrator_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	vibrator_ledclass_type_id = g_type_module_register_type (module, FSO_FRAMEWORK_TYPE_ABSTRACT_OBJECT, "VibratorLedClass", &g_define_type_info, 0);
	g_type_module_add_interface (module, vibrator_ledclass_type_id, FREE_SMARTPHONE_DEVICE_TYPE_VIBRATOR, &free_smartphone_device_vibrator_info);
	return vibrator_ledclass_type_id;
}


/**
 * This function gets called on plugin initialization time.
 * @return the name of your plugin here
 * @note that it needs to be a name in the format <subsystem>.<plugin>
 * else your module will be unloaded immediately.
 **/
static gboolean string_contains (const gchar* self, const gchar* needle) {
	gboolean result = FALSE;
	const gchar* _tmp0_;
	gchar* _tmp1_ = NULL;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (needle != NULL, FALSE);
	_tmp0_ = needle;
	_tmp1_ = strstr ((gchar*) self, (gchar*) _tmp0_);
	result = _tmp1_ != NULL;
	return result;
}


gchar* fso_factory_function (FsoFrameworkSubsystem* subsystem, GError** error) {
	gchar* result = NULL;
	FsoFrameworkSmartKeyFile* _tmp0_;
	FsoFrameworkSmartKeyFile* _tmp1_;
	FsoFrameworkSmartKeyFile* config;
	gchar* _tmp2_ = NULL;
	const gchar* _tmp3_;
	gchar* _tmp4_ = NULL;
	const gchar* _tmp5_;
	gchar* _tmp6_ = NULL;
	const gchar* _tmp7_;
	GDir* _tmp8_ = NULL;
	GDir* dir;
	const gchar* _tmp9_ = NULL;
	gchar* _tmp10_;
	gchar* entry;
	gchar* _tmp22_;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (subsystem != NULL, NULL);
	_tmp0_ = fso_framework_theConfig;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	config = _tmp1_;
	_tmp2_ = fso_framework_smart_key_file_stringValue (config, "cornucopia", "sysfs_root", "/sys");
	_g_free0 (sysfs_root);
	sysfs_root = _tmp2_;
	_tmp3_ = sysfs_root;
	_tmp4_ = g_strdup_printf ("%s/class/leds", _tmp3_);
	_g_free0 (sys_class_leds);
	sys_class_leds = _tmp4_;
	_tmp5_ = sysfs_root;
	_tmp6_ = g_strdup_printf ("%s/class/net", _tmp5_);
	_g_free0 (sys_class_net);
	sys_class_net = _tmp6_;
	_tmp7_ = sys_class_leds;
	_tmp8_ = g_dir_open (_tmp7_, (guint) 0, &_inner_error_);
	dir = _tmp8_;
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_g_object_unref0 (config);
		return NULL;
	}
	_tmp9_ = g_dir_read_name (dir);
	_tmp10_ = g_strdup (_tmp9_);
	entry = _tmp10_;
	while (TRUE) {
		const gchar* _tmp11_;
		const gchar* _tmp12_;
		gboolean _tmp13_ = FALSE;
		const gchar* _tmp20_ = NULL;
		gchar* _tmp21_;
		_tmp11_ = entry;
		if (!(_tmp11_ != NULL)) {
			break;
		}
		_tmp12_ = entry;
		_tmp13_ = string_contains (_tmp12_, "vib");
		if (_tmp13_) {
			const gchar* _tmp14_;
			const gchar* _tmp15_;
			gchar* _tmp16_ = NULL;
			gchar* filename;
			FsoFrameworkSubsystem* _tmp17_;
			const gchar* _tmp18_;
			VibratorLedClass* _tmp19_;
			_tmp14_ = sys_class_leds;
			_tmp15_ = entry;
			_tmp16_ = g_build_filename (_tmp14_, _tmp15_, NULL);
			filename = _tmp16_;
			_tmp17_ = subsystem;
			_tmp18_ = filename;
			_tmp19_ = vibrator_ledclass_new (_tmp17_, _tmp18_);
			instances = g_list_append (instances, _tmp19_);
			_g_free0 (filename);
		}
		_tmp20_ = g_dir_read_name (dir);
		_tmp21_ = g_strdup (_tmp20_);
		_g_free0 (entry);
		entry = _tmp21_;
	}
	_tmp22_ = g_strdup ("fsodevice.vibrator_ledclasss");
	result = _tmp22_;
	_g_free0 (entry);
	_g_dir_close0 (dir);
	_g_object_unref0 (config);
	return result;
}


void fso_register_function (GTypeModule* module) {
	FsoFrameworkLogger* _tmp0_;
	g_return_if_fail (module != NULL);
	vibrator_ledclass_register_type (module);
	_tmp0_ = fso_framework_theLogger;
	fso_framework_logger_debug (_tmp0_, "fsodevice.vibrator_ledclasss fso_register_function()");
}



