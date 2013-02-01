/* plugin.c generated by valac 0.16.1, the Vala compiler
 * generated from plugin.vala, do not modify */

/*
 * Copyright (C) 2010-2012 Michael 'Mickey' Lauer <mlauer@vanille-media.de>
 *               2010-2012 Sebastian Krzyszkowiak <dos@dosowisko.net>
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
#include <freesmartphone.h>
#include <fsodevice.h>
#include <fsoframework.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>
#include <linux/input.h>
#include <gio/gio.h>


#define GPIO_TYPE_INPUT_DEVICE (gpio_input_device_get_type ())
#define GPIO_INPUT_DEVICE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GPIO_TYPE_INPUT_DEVICE, GpioInputDevice))
#define GPIO_INPUT_DEVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GPIO_TYPE_INPUT_DEVICE, GpioInputDeviceClass))
#define GPIO_IS_INPUT_DEVICE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GPIO_TYPE_INPUT_DEVICE))
#define GPIO_IS_INPUT_DEVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GPIO_TYPE_INPUT_DEVICE))
#define GPIO_INPUT_DEVICE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GPIO_TYPE_INPUT_DEVICE, GpioInputDeviceClass))

typedef struct _GpioInputDevice GpioInputDevice;
typedef struct _GpioInputDeviceClass GpioInputDeviceClass;
typedef struct _GpioInputDevicePrivate GpioInputDevicePrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _GpioInputDeviceGetIdData GpioInputDeviceGetIdData;
typedef struct _GpioInputDeviceGetCapabilitiesData GpioInputDeviceGetCapabilitiesData;
#define __g_list_free__g_free0_0(var) ((var == NULL) ? NULL : (var = (_g_list_free__g_free0_ (var), NULL)))

struct _GpioInputDevice {
	FsoFrameworkAbstractObject parent_instance;
	GpioInputDevicePrivate * priv;
};

struct _GpioInputDeviceClass {
	FsoFrameworkAbstractObjectClass parent_class;
};

struct _GpioInputDevicePrivate {
	FsoFrameworkSubsystem* subsystem;
	gchar* path;
	gchar* node;
	gchar* onValue;
	gint code;
	FsoFrameworkAsyncReactorChannel* channel;
};

struct _GpioInputDeviceGetIdData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	GpioInputDevice* self;
	gchar* result;
	const gchar* _tmp0_;
	gchar* _tmp1_;
};

struct _GpioInputDeviceGetCapabilitiesData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	GpioInputDevice* self;
	gchar* result;
	gchar* _tmp0_;
};


static gpointer gpio_input_device_parent_class = NULL;
static FreeSmartphoneDeviceInputIface* gpio_input_device_free_smartphone_device_input_parent_iface = NULL;
static FsoDeviceSignallingInputDeviceIface* gpio_input_device_fso_device_signalling_input_device_parent_iface = NULL;
static GType gpio_input_device_type_id = 0;
extern gchar* sysfs_root;
gchar* sysfs_root = NULL;
extern GpioInputDevice* instance;
GpioInputDevice* instance = NULL;

#define GPIO_GPIO_INPUT_PLUGIN_NAME "fsodevice.gpio_input"
GType gpio_input_device_get_type (void) G_GNUC_CONST;
GType gpio_input_device_register_type (GTypeModule * module);
#define GPIO_INPUT_DEVICE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), GPIO_TYPE_INPUT_DEVICE, GpioInputDevicePrivate))
enum  {
	GPIO_INPUT_DEVICE_DUMMY_PROPERTY
};
GpioInputDevice* gpio_input_device_new (FsoFrameworkSubsystem* subsystem, const gchar* path, gint code, const gchar* onValue);
GpioInputDevice* gpio_input_device_construct (GType object_type, FsoFrameworkSubsystem* subsystem, const gchar* path, gint code, const gchar* onValue);
static void gpio_input_device_onActionFromChannel (GpioInputDevice* self, void* data, gssize length);
static void _gpio_input_device_onActionFromChannel_fso_framework_async_reactor_channel_action_func (void* data, gssize length, gpointer self);
static gchar* gpio_input_device_real_repr (FsoFrameworkAbstractObject* base);
static void gpio_input_device_real_get_id_data_free (gpointer _data);
static void gpio_input_device_real_get_id (FreeSmartphoneDeviceInput* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean gpio_input_device_real_get_id_co (GpioInputDeviceGetIdData* _data_);
static void gpio_input_device_real_get_capabilities_data_free (gpointer _data);
static void gpio_input_device_real_get_capabilities (FreeSmartphoneDeviceInput* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean gpio_input_device_real_get_capabilities_co (GpioInputDeviceGetCapabilitiesData* _data_);
static void gpio_input_device_finalize (GObject* obj);
gchar* fso_factory_function (FsoFrameworkSubsystem* subsystem, GError** error);
static void _g_free0_ (gpointer var);
static void _g_list_free__g_free0_ (GList* self);
void fso_register_function (GTypeModule* module);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


static void _gpio_input_device_onActionFromChannel_fso_framework_async_reactor_channel_action_func (void* data, gssize length, gpointer self) {
	gpio_input_device_onActionFromChannel (self, data, length);
}


GpioInputDevice* gpio_input_device_construct (GType object_type, FsoFrameworkSubsystem* subsystem, const gchar* path, gint code, const gchar* onValue) {
	GpioInputDevice * self = NULL;
	FsoFrameworkSubsystem* _tmp0_;
	FsoFrameworkSubsystem* _tmp1_;
	const gchar* _tmp2_;
	gchar* _tmp3_;
	gint _tmp4_;
	const gchar* _tmp5_;
	gchar* _tmp6_;
	FsoFrameworkSubsystem* _tmp7_;
	gint _tmp8_;
	gchar* _tmp9_ = NULL;
	gchar* _tmp10_;
	const gchar* _tmp11_;
	gboolean _tmp12_ = FALSE;
	const gchar* _tmp18_;
	gchar* _tmp19_ = NULL;
	gchar* powernode;
	const gchar* _tmp20_;
	gchar* _tmp21_ = NULL;
	gchar* node;
	const gchar* _tmp22_;
	gchar* _tmp23_;
	const gchar* _tmp24_;
	const gchar* _tmp25_;
	gint _tmp26_ = 0;
	gint fd;
	gint _tmp27_;
	gint _tmp36_;
	FsoFrameworkAsyncReactorChannel* _tmp37_;
	FsoFrameworkLogger* _tmp38_;
	g_return_val_if_fail (subsystem != NULL, NULL);
	g_return_val_if_fail (path != NULL, NULL);
	g_return_val_if_fail (onValue != NULL, NULL);
	self = (GpioInputDevice*) fso_framework_abstract_object_construct (object_type);
	_tmp0_ = subsystem;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->subsystem);
	self->priv->subsystem = _tmp1_;
	_tmp2_ = path;
	_tmp3_ = g_strdup (_tmp2_);
	_g_free0 (self->priv->path);
	self->priv->path = _tmp3_;
	_tmp4_ = code;
	self->priv->code = _tmp4_;
	_tmp5_ = onValue;
	_tmp6_ = g_strdup (_tmp5_);
	_g_free0 (self->priv->onValue);
	self->priv->onValue = _tmp6_;
	_tmp7_ = subsystem;
	_tmp8_ = code;
	_tmp9_ = g_strdup_printf ("%s/gpio%d", FSO_FRAMEWORK_DEVICE_InputServicePath, _tmp8_);
	_tmp10_ = _tmp9_;
	fso_framework_subsystem_registerObjectForService (_tmp7_, FREE_SMARTPHONE_DEVICE_TYPE_INPUT, (GBoxedCopyFunc) g_object_ref, g_object_unref, FSO_FRAMEWORK_DEVICE_ServiceDBusName, _tmp10_, (FreeSmartphoneDeviceInput*) self);
	_g_free0 (_tmp10_);
	_tmp11_ = path;
	_tmp12_ = fso_framework_file_handling_isPresent (_tmp11_);
	if (!_tmp12_) {
		FsoFrameworkLogger* _tmp13_;
		const gchar* _tmp14_;
		const gchar* _tmp15_ = NULL;
		gchar* _tmp16_ = NULL;
		gchar* _tmp17_;
		_tmp13_ = ((FsoFrameworkAbstractObject*) self)->logger;
		_tmp14_ = path;
		_tmp15_ = string_to_string (_tmp14_);
		_tmp16_ = g_strconcat ("Sysfs class is damaged, missing ", _tmp15_, "; skipping.", NULL);
		_tmp17_ = _tmp16_;
		fso_framework_logger_error (_tmp13_, _tmp17_);
		_g_free0 (_tmp17_);
		return self;
	}
	_tmp18_ = path;
	_tmp19_ = g_build_filename (_tmp18_, "disable", NULL);
	powernode = _tmp19_;
	_tmp20_ = path;
	_tmp21_ = g_build_filename (_tmp20_, "state", NULL);
	node = _tmp21_;
	_tmp22_ = node;
	_tmp23_ = g_strdup (_tmp22_);
	_g_free0 (self->priv->node);
	self->priv->node = _tmp23_;
	_tmp24_ = powernode;
	fso_framework_file_handling_write ("0", _tmp24_, FALSE);
	_tmp25_ = node;
	_tmp26_ = open (_tmp25_, O_RDONLY, (mode_t) 0);
	fd = _tmp26_;
	_tmp27_ = fd;
	if (_tmp27_ == (-1)) {
		FsoFrameworkLogger* _tmp28_;
		const gchar* _tmp29_;
		const gchar* _tmp30_ = NULL;
		gint _tmp31_;
		const gchar* _tmp32_ = NULL;
		const gchar* _tmp33_ = NULL;
		gchar* _tmp34_ = NULL;
		gchar* _tmp35_;
		_tmp28_ = ((FsoFrameworkAbstractObject*) self)->logger;
		_tmp29_ = node;
		_tmp30_ = string_to_string (_tmp29_);
		_tmp31_ = errno;
		_tmp32_ = g_strerror (_tmp31_);
		_tmp33_ = string_to_string (_tmp32_);
		_tmp34_ = g_strconcat ("Can't open ", _tmp30_, " (", _tmp33_, "; object will not be functional", NULL);
		_tmp35_ = _tmp34_;
		fso_framework_logger_warning (_tmp28_, _tmp35_);
		_g_free0 (_tmp35_);
		_g_free0 (node);
		_g_free0 (powernode);
		return self;
	}
	_tmp36_ = fd;
	_tmp37_ = fso_framework_async_reactor_channel_new_rewind (_tmp36_, _gpio_input_device_onActionFromChannel_fso_framework_async_reactor_channel_action_func, g_object_ref (self), g_object_unref, (gsize) 512);
	_g_object_unref0 (self->priv->channel);
	self->priv->channel = _tmp37_;
	_tmp38_ = ((FsoFrameworkAbstractObject*) self)->logger;
	fso_framework_logger_info (_tmp38_, "Created new GpioInputDevice");
	_g_free0 (node);
	_g_free0 (powernode);
	return self;
}


GpioInputDevice* gpio_input_device_new (FsoFrameworkSubsystem* subsystem, const gchar* path, gint code, const gchar* onValue) {
	return gpio_input_device_construct (GPIO_TYPE_INPUT_DEVICE, subsystem, path, code, onValue);
}


static gchar* gpio_input_device_real_repr (FsoFrameworkAbstractObject* base) {
	GpioInputDevice * self;
	gchar* result = NULL;
	const gchar* _tmp0_;
	const gchar* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	self = (GpioInputDevice*) base;
	_tmp0_ = self->priv->path;
	_tmp1_ = string_to_string (_tmp0_);
	_tmp2_ = g_strconcat ("<", _tmp1_, ">", NULL);
	result = _tmp2_;
	return result;
}


static void gpio_input_device_onActionFromChannel (GpioInputDevice* self, void* data, gssize length) {
	gint _tmp0_ = 0;
	const gchar* _tmp1_;
	void* _tmp2_;
	gssize _tmp3_;
	gint _tmp4_ = 0;
	gint _tmp5_;
	gint32 eventValue;
	gint _tmp6_;
	struct input_event _tmp7_ = {0};
	struct input_event event;
	g_return_if_fail (self != NULL);
	_tmp1_ = self->priv->onValue;
	_tmp2_ = data;
	_tmp3_ = length;
	_tmp4_ = g_ascii_strncasecmp (_tmp1_, (const gchar*) _tmp2_, (gsize) (_tmp3_ - 1));
	if (_tmp4_ == 0) {
		_tmp0_ = 1;
	} else {
		_tmp0_ = 0;
	}
	_tmp5_ = _tmp0_;
	eventValue = (gint32) _tmp5_;
	_tmp6_ = self->priv->code;
	memset (&_tmp7_, 0, sizeof (struct input_event));
	_tmp7_.type = EV_SW;
	_tmp7_.code = (guint16) _tmp6_;
	_tmp7_.value = eventValue;
	event = _tmp7_;
	g_signal_emit_by_name ((FsoDeviceSignallingInputDevice*) self, "received-event", &event);
}


static void gpio_input_device_real_get_id_data_free (gpointer _data) {
	GpioInputDeviceGetIdData* _data_;
	_data_ = _data;
	_g_free0 (_data_->result);
	_g_object_unref0 (_data_->self);
	g_slice_free (GpioInputDeviceGetIdData, _data_);
}


static void gpio_input_device_real_get_id (FreeSmartphoneDeviceInput* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	GpioInputDevice * self;
	GpioInputDeviceGetIdData* _data_;
	GpioInputDevice* _tmp0_;
	self = (GpioInputDevice*) base;
	_data_ = g_slice_new0 (GpioInputDeviceGetIdData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, gpio_input_device_real_get_id);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, gpio_input_device_real_get_id_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	gpio_input_device_real_get_id_co (_data_);
}


static gchar* gpio_input_device_real_get_id_finish (FreeSmartphoneDeviceInput* base, GAsyncResult* _res_, GError** error) {
	gchar* result;
	GpioInputDeviceGetIdData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return NULL;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	result = _data_->result;
	_data_->result = NULL;
	return result;
}


static gboolean gpio_input_device_real_get_id_co (GpioInputDeviceGetIdData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = _data_->self->priv->path;
	_data_->_tmp1_ = g_strdup (_data_->_tmp0_);
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


static void gpio_input_device_real_get_capabilities_data_free (gpointer _data) {
	GpioInputDeviceGetCapabilitiesData* _data_;
	_data_ = _data;
	_g_free0 (_data_->result);
	_g_object_unref0 (_data_->self);
	g_slice_free (GpioInputDeviceGetCapabilitiesData, _data_);
}


static void gpio_input_device_real_get_capabilities (FreeSmartphoneDeviceInput* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	GpioInputDevice * self;
	GpioInputDeviceGetCapabilitiesData* _data_;
	GpioInputDevice* _tmp0_;
	self = (GpioInputDevice*) base;
	_data_ = g_slice_new0 (GpioInputDeviceGetCapabilitiesData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, gpio_input_device_real_get_capabilities);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, gpio_input_device_real_get_capabilities_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	gpio_input_device_real_get_capabilities_co (_data_);
}


static gchar* gpio_input_device_real_get_capabilities_finish (FreeSmartphoneDeviceInput* base, GAsyncResult* _res_, GError** error) {
	gchar* result;
	GpioInputDeviceGetCapabilitiesData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return NULL;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	result = _data_->result;
	_data_->result = NULL;
	return result;
}


static gboolean gpio_input_device_real_get_capabilities_co (GpioInputDeviceGetCapabilitiesData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = g_strdup ("");
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


static void gpio_input_device_class_init (GpioInputDeviceClass * klass) {
	gpio_input_device_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (GpioInputDevicePrivate));
	FSO_FRAMEWORK_ABSTRACT_OBJECT_CLASS (klass)->repr = gpio_input_device_real_repr;
	G_OBJECT_CLASS (klass)->finalize = gpio_input_device_finalize;
}


static void gpio_input_device_free_smartphone_device_input_interface_init (FreeSmartphoneDeviceInputIface * iface) {
	gpio_input_device_free_smartphone_device_input_parent_iface = g_type_interface_peek_parent (iface);
	iface->get_id = (gchar* (*)(FreeSmartphoneDeviceInput*, GError**)) gpio_input_device_real_get_id;
	iface->get_id_finish = gpio_input_device_real_get_id_finish;
	iface->get_capabilities = (gchar* (*)(FreeSmartphoneDeviceInput*, GError**)) gpio_input_device_real_get_capabilities;
	iface->get_capabilities_finish = gpio_input_device_real_get_capabilities_finish;
}


static void gpio_input_device_fso_device_signalling_input_device_interface_init (FsoDeviceSignallingInputDeviceIface * iface) {
	gpio_input_device_fso_device_signalling_input_device_parent_iface = g_type_interface_peek_parent (iface);
}


static void gpio_input_device_instance_init (GpioInputDevice * self) {
	self->priv = GPIO_INPUT_DEVICE_GET_PRIVATE (self);
}


static void gpio_input_device_finalize (GObject* obj) {
	GpioInputDevice * self;
	self = GPIO_INPUT_DEVICE (obj);
	_g_object_unref0 (self->priv->subsystem);
	_g_free0 (self->priv->path);
	_g_free0 (self->priv->node);
	_g_free0 (self->priv->onValue);
	_g_object_unref0 (self->priv->channel);
	G_OBJECT_CLASS (gpio_input_device_parent_class)->finalize (obj);
}


/**
 * Implementation of org.freesmartphone.Device.Input for the gpio Input Device
 **/
GType gpio_input_device_get_type (void) {
	return gpio_input_device_type_id;
}


GType gpio_input_device_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (GpioInputDeviceClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) gpio_input_device_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (GpioInputDevice), 0, (GInstanceInitFunc) gpio_input_device_instance_init, NULL };
	static const GInterfaceInfo free_smartphone_device_input_info = { (GInterfaceInitFunc) gpio_input_device_free_smartphone_device_input_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	static const GInterfaceInfo fso_device_signalling_input_device_info = { (GInterfaceInitFunc) gpio_input_device_fso_device_signalling_input_device_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	gpio_input_device_type_id = g_type_module_register_type (module, FSO_FRAMEWORK_TYPE_ABSTRACT_OBJECT, "GpioInputDevice", &g_define_type_info, 0);
	g_type_module_add_interface (module, gpio_input_device_type_id, FREE_SMARTPHONE_DEVICE_TYPE_INPUT, &free_smartphone_device_input_info);
	g_type_module_add_interface (module, gpio_input_device_type_id, FSO_DEVICE_TYPE_SIGNALLING_INPUT_DEVICE, &fso_device_signalling_input_device_info);
	return gpio_input_device_type_id;
}


/**
 * This function gets called on plugin initialization time.
 * @return the name of your plugin here
 * @note that it needs to be a name in the format <subsystem>.<plugin>
 * else your module will be unloaded immediately.
 **/
static void _g_free0_ (gpointer var) {
	var = (g_free (var), NULL);
}


static void _g_list_free__g_free0_ (GList* self) {
	g_list_foreach (self, (GFunc) _g_free0_, NULL);
	g_list_free (self);
}


gchar* fso_factory_function (FsoFrameworkSubsystem* subsystem, GError** error) {
	gchar* result = NULL;
	FsoFrameworkSmartKeyFile* _tmp0_;
	FsoFrameworkSmartKeyFile* _tmp1_;
	FsoFrameworkSmartKeyFile* config;
	FsoFrameworkSmartKeyFile* _tmp2_;
	gchar* _tmp3_ = NULL;
	FsoFrameworkSmartKeyFile* _tmp4_;
	GList* _tmp5_ = NULL;
	GList* entries;
	GList* _tmp6_;
	gchar* _tmp44_;
	g_return_val_if_fail (subsystem != NULL, NULL);
	_tmp0_ = fso_framework_theConfig;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	config = _tmp1_;
	_tmp2_ = config;
	_tmp3_ = fso_framework_smart_key_file_stringValue (_tmp2_, "cornucopia", "sysfs_root", "/sys");
	_g_free0 (sysfs_root);
	sysfs_root = _tmp3_;
	_tmp4_ = config;
	_tmp5_ = fso_framework_smart_key_file_keysWithPrefix (_tmp4_, GPIO_GPIO_INPUT_PLUGIN_NAME, "node");
	entries = _tmp5_;
	_tmp6_ = entries;
	{
		GList* entry_collection = NULL;
		GList* entry_it = NULL;
		entry_collection = _tmp6_;
		for (entry_it = entry_collection; entry_it != NULL; entry_it = entry_it->next) {
			gchar* _tmp7_;
			gchar* entry = NULL;
			_tmp7_ = g_strdup ((const gchar*) entry_it->data);
			entry = _tmp7_;
			{
				FsoFrameworkSmartKeyFile* _tmp8_;
				const gchar* _tmp9_;
				gchar* _tmp10_ = NULL;
				gchar* readvalue;
				const gchar* _tmp11_;
				gchar** _tmp12_;
				gchar** _tmp13_ = NULL;
				gchar** values;
				gint values_length1;
				gint _values_size_;
				gchar** _tmp14_;
				gint _tmp14__length1;
				gchar** _tmp20_;
				gint _tmp20__length1;
				const gchar* _tmp21_;
				gchar* _tmp22_;
				gchar* name;
				gchar** _tmp23_;
				gint _tmp23__length1;
				const gchar* _tmp24_;
				gint _tmp25_ = 0;
				gint code;
				gchar** _tmp26_;
				gint _tmp26__length1;
				const gchar* _tmp27_;
				gchar* _tmp28_;
				gchar* onValue;
				const gchar* _tmp29_;
				const gchar* _tmp30_;
				gchar* _tmp31_ = NULL;
				gchar* dirname;
				const gchar* _tmp32_;
				gboolean _tmp33_ = FALSE;
				_tmp8_ = config;
				_tmp9_ = entry;
				_tmp10_ = fso_framework_smart_key_file_stringValue (_tmp8_, GPIO_GPIO_INPUT_PLUGIN_NAME, _tmp9_, "");
				readvalue = _tmp10_;
				_tmp11_ = readvalue;
				_tmp13_ = _tmp12_ = g_strsplit (_tmp11_, ",", 0);
				values = _tmp13_;
				values_length1 = _vala_array_length (_tmp12_);
				_values_size_ = values_length1;
				_tmp14_ = values;
				_tmp14__length1 = values_length1;
				if (_tmp14__length1 != 3) {
					FsoFrameworkLogger* _tmp15_;
					const gchar* _tmp16_;
					const gchar* _tmp17_ = NULL;
					gchar* _tmp18_ = NULL;
					gchar* _tmp19_;
					_tmp15_ = fso_framework_theLogger;
					_tmp16_ = entry;
					_tmp17_ = string_to_string (_tmp16_);
					_tmp18_ = g_strconcat ("Config option ", _tmp17_, " has not 3 elements. Ignoring.", NULL);
					_tmp19_ = _tmp18_;
					fso_framework_logger_warning (_tmp15_, _tmp19_);
					_g_free0 (_tmp19_);
					values = (_vala_array_free (values, values_length1, (GDestroyNotify) g_free), NULL);
					_g_free0 (readvalue);
					_g_free0 (entry);
					continue;
				}
				_tmp20_ = values;
				_tmp20__length1 = values_length1;
				_tmp21_ = _tmp20_[0];
				_tmp22_ = g_strdup (_tmp21_);
				name = _tmp22_;
				_tmp23_ = values;
				_tmp23__length1 = values_length1;
				_tmp24_ = _tmp23_[1];
				_tmp25_ = atoi (_tmp24_);
				code = _tmp25_;
				_tmp26_ = values;
				_tmp26__length1 = values_length1;
				_tmp27_ = _tmp26_[2];
				_tmp28_ = g_strdup (_tmp27_);
				onValue = _tmp28_;
				_tmp29_ = sysfs_root;
				_tmp30_ = name;
				_tmp31_ = g_build_filename (_tmp29_, "devices", "platform", "gpio-switch", _tmp30_, NULL);
				dirname = _tmp31_;
				_tmp32_ = dirname;
				_tmp33_ = fso_framework_file_handling_isPresent (_tmp32_);
				if (_tmp33_) {
					FsoFrameworkSubsystem* _tmp34_;
					const gchar* _tmp35_;
					gint _tmp36_;
					const gchar* _tmp37_;
					GpioInputDevice* _tmp38_;
					_tmp34_ = subsystem;
					_tmp35_ = dirname;
					_tmp36_ = code;
					_tmp37_ = onValue;
					_tmp38_ = gpio_input_device_new (_tmp34_, _tmp35_, _tmp36_, _tmp37_);
					_g_object_unref0 (instance);
					instance = _tmp38_;
				} else {
					FsoFrameworkLogger* _tmp39_;
					const gchar* _tmp40_;
					const gchar* _tmp41_ = NULL;
					gchar* _tmp42_ = NULL;
					gchar* _tmp43_;
					_tmp39_ = fso_framework_theLogger;
					_tmp40_ = name;
					_tmp41_ = string_to_string (_tmp40_);
					_tmp42_ = g_strconcat ("Ignoring defined gpio-switch ", _tmp41_, " which is not available", NULL);
					_tmp43_ = _tmp42_;
					fso_framework_logger_error (_tmp39_, _tmp43_);
					_g_free0 (_tmp43_);
				}
				_g_free0 (dirname);
				_g_free0 (onValue);
				_g_free0 (name);
				values = (_vala_array_free (values, values_length1, (GDestroyNotify) g_free), NULL);
				_g_free0 (readvalue);
				_g_free0 (entry);
			}
		}
	}
	_tmp44_ = g_strdup (GPIO_GPIO_INPUT_PLUGIN_NAME);
	result = _tmp44_;
	__g_list_free__g_free0_0 (entries);
	_g_object_unref0 (config);
	return result;
}


void fso_register_function (GTypeModule* module) {
	FsoFrameworkLogger* _tmp0_;
	g_return_if_fail (module != NULL);
	gpio_input_device_register_type (module);
	_tmp0_ = fso_framework_theLogger;
	fso_framework_logger_debug (_tmp0_, "fsodevice.gpio_input fso_register_function()");
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


static gint _vala_array_length (gpointer array) {
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
}


