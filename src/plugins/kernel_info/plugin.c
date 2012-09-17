/* plugin.c generated by valac 0.16.0, the Vala compiler
 * generated from plugin.vala, do not modify */

/*
 * plugin.vala
 * Written by Sudharshan "Sup3rkiddo" S <sudharsh@gmail.com>
 * All Rights Reserved
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <fsobasics.h>
#include <freesmartphone.h>
#include <fsoframework.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>


#define KERNEL_TYPE_INFO (kernel_info_get_type ())
#define KERNEL_INFO(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), KERNEL_TYPE_INFO, KernelInfo))
#define KERNEL_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), KERNEL_TYPE_INFO, KernelInfoClass))
#define KERNEL_IS_INFO(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), KERNEL_TYPE_INFO))
#define KERNEL_IS_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), KERNEL_TYPE_INFO))
#define KERNEL_INFO_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), KERNEL_TYPE_INFO, KernelInfoClass))

typedef struct _KernelInfo KernelInfo;
typedef struct _KernelInfoClass KernelInfoClass;
typedef struct _KernelInfoPrivate KernelInfoPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_hash_table_unref0(var) ((var == NULL) ? NULL : (var = (g_hash_table_unref (var), NULL)))
#define _g_variant_unref0(var) ((var == NULL) ? NULL : (var = (g_variant_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
typedef struct _KernelInfoGetCpuInfoData KernelInfoGetCpuInfoData;

struct _KernelInfo {
	FsoFrameworkAbstractObject parent_instance;
	KernelInfoPrivate * priv;
};

struct _KernelInfoClass {
	FsoFrameworkAbstractObjectClass parent_class;
};

struct _KernelInfoPrivate {
	FsoFrameworkSubsystem* subsystem;
};

struct _KernelInfoGetCpuInfoData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	KernelInfo* self;
	GHashTable* result;
	GFile* _tmp0_;
	GFile* node_file;
	gchar* line;
	GHashFunc _tmp1_;
	GEqualFunc _tmp2_;
	GHashTable* _tmp3_;
	GHashTable* _ret;
	GVariant* val;
	GFile* _tmp4_;
	GFileInputStream* _tmp5_;
	GFileInputStream* _tmp6_;
	GFileInputStream* _tmp7_;
	GDataInputStream* _tmp8_;
	GDataInputStream* _tmp9_;
	GDataInputStream* stream;
	GDataInputStream* _tmp10_;
	gchar* _tmp11_;
	gchar* _tmp12_;
	GDataInputStream* _tmp13_;
	gchar* _tmp14_;
	gchar* _tmp15_;
	const gchar* _tmp16_;
	gboolean _tmp17_;
	const gchar* _tmp18_;
	const gchar* _tmp19_;
	gboolean _tmp20_;
	const gchar* _tmp21_;
	gchar** _tmp22_;
	gchar** _tmp23_;
	gchar** _list;
	gint _list_length1;
	gint __list_size_;
	gboolean _tmp24_;
	gchar** _tmp25_;
	gint _tmp25__length1;
	const gchar* _tmp26_;
	gchar** _tmp27_;
	gint _tmp27__length1;
	const gchar* _tmp28_;
	gboolean _tmp29_;
	gchar** _tmp30_;
	gint _tmp30__length1;
	const gchar* _tmp31_;
	gchar* _tmp32_;
	GVariant* _tmp33_;
	GHashTable* _tmp34_;
	gchar** _tmp35_;
	gint _tmp35__length1;
	const gchar* _tmp36_;
	gchar* _tmp37_;
	GVariant* _tmp38_;
	GVariant* _tmp39_;
	GError* _error_;
	FsoFrameworkLogger* _tmp40_;
	GError* _tmp41_;
	const gchar* _tmp42_;
	GError * _inner_error_;
};


static gpointer kernel_info_parent_class = NULL;
static FreeSmartphoneDeviceInfoIface* kernel_info_free_smartphone_device_info_parent_iface = NULL;
static GType kernel_info_type_id = 0;
extern KernelInfo* instance;
KernelInfo* instance = NULL;

GType kernel_info_get_type (void) G_GNUC_CONST;
GType kernel_info_register_type (GTypeModule * module);
#define KERNEL_INFO_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), KERNEL_TYPE_INFO, KernelInfoPrivate))
enum  {
	KERNEL_INFO_DUMMY_PROPERTY
};
#define KERNEL_INFO_PROC_NODE "/proc/cpuinfo"
KernelInfo* kernel_info_new (FsoFrameworkSubsystem* subsystem);
KernelInfo* kernel_info_construct (GType object_type, FsoFrameworkSubsystem* subsystem);
static gchar* kernel_info_real_repr (FsoFrameworkAbstractObject* base);
static void kernel_info_real_get_cpu_info_data_free (gpointer _data);
static void kernel_info_real_get_cpu_info (FreeSmartphoneDeviceInfo* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean kernel_info_real_get_cpu_info_co (KernelInfoGetCpuInfoData* _data_);
static void _g_free0_ (gpointer var);
static void _g_variant_unref0_ (gpointer var);
static GVariant* _variant_new1 (gchar* value);
static void kernel_info_finalize (GObject* obj);
gchar* fso_factory_function (FsoFrameworkSubsystem* subsystem, GError** error);
void fso_register_function (GTypeModule* module);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


KernelInfo* kernel_info_construct (GType object_type, FsoFrameworkSubsystem* subsystem) {
	KernelInfo * self = NULL;
	FsoFrameworkSubsystem* _tmp0_;
	FsoFrameworkSubsystem* _tmp1_;
	FsoFrameworkSubsystem* _tmp2_;
	FsoFrameworkLogger* _tmp3_;
	g_return_val_if_fail (subsystem != NULL, NULL);
	self = (KernelInfo*) fso_framework_abstract_object_construct (object_type);
	_tmp0_ = subsystem;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->subsystem);
	self->priv->subsystem = _tmp1_;
	_tmp2_ = subsystem;
	fso_framework_subsystem_registerObjectForService (_tmp2_, FREE_SMARTPHONE_DEVICE_TYPE_INFO, (GBoxedCopyFunc) g_object_ref, g_object_unref, FSO_FRAMEWORK_DEVICE_ServiceDBusName, FSO_FRAMEWORK_DEVICE_InfoServicePath, (FreeSmartphoneDeviceInfo*) self);
	_tmp3_ = ((FsoFrameworkAbstractObject*) self)->logger;
	fso_framework_logger_info (_tmp3_, "Created new Info Object");
	return self;
}


KernelInfo* kernel_info_new (FsoFrameworkSubsystem* subsystem) {
	return kernel_info_construct (KERNEL_TYPE_INFO, subsystem);
}


static gchar* kernel_info_real_repr (FsoFrameworkAbstractObject* base) {
	KernelInfo * self;
	gchar* result = NULL;
	gchar* _tmp0_ = NULL;
	self = (KernelInfo*) base;
	_tmp0_ = g_strdup_printf ("<FsoFramework.Device.Info @ %s>", FSO_FRAMEWORK_DEVICE_InfoServicePath);
	result = _tmp0_;
	return result;
}


static void kernel_info_real_get_cpu_info_data_free (gpointer _data) {
	KernelInfoGetCpuInfoData* _data_;
	_data_ = _data;
	_g_hash_table_unref0 (_data_->result);
	_g_object_unref0 (_data_->self);
	g_slice_free (KernelInfoGetCpuInfoData, _data_);
}


static void kernel_info_real_get_cpu_info (FreeSmartphoneDeviceInfo* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	KernelInfo * self;
	KernelInfoGetCpuInfoData* _data_;
	KernelInfo* _tmp0_;
	self = (KernelInfo*) base;
	_data_ = g_slice_new0 (KernelInfoGetCpuInfoData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, kernel_info_real_get_cpu_info);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, kernel_info_real_get_cpu_info_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	kernel_info_real_get_cpu_info_co (_data_);
}


static GHashTable* kernel_info_real_get_cpu_info_finish (FreeSmartphoneDeviceInfo* base, GAsyncResult* _res_, GError** error) {
	GHashTable* result;
	KernelInfoGetCpuInfoData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return NULL;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	result = _data_->result;
	_data_->result = NULL;
	return result;
}


static void _g_free0_ (gpointer var) {
	var = (g_free (var), NULL);
}


static void _g_variant_unref0_ (gpointer var) {
	(var == NULL) ? NULL : (var = (g_variant_unref (var), NULL));
}


static gchar* string_strip (const gchar* self) {
	gchar* result = NULL;
	gchar* _tmp0_ = NULL;
	gchar* _result_;
	const gchar* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = g_strdup (self);
	_result_ = _tmp0_;
	_tmp1_ = _result_;
	g_strstrip (_tmp1_);
	result = _result_;
	return result;
}


static GVariant* _variant_new1 (gchar* value) {
	return g_variant_ref_sink (g_variant_new_string (value));
}


static gpointer _g_variant_ref0 (gpointer self) {
	return self ? g_variant_ref (self) : NULL;
}


static gboolean kernel_info_real_get_cpu_info_co (KernelInfoGetCpuInfoData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = NULL;
	_data_->_tmp0_ = g_file_new_for_path (KERNEL_INFO_PROC_NODE);
	_data_->node_file = _data_->_tmp0_;
	_data_->_tmp1_ = g_str_hash;
	_data_->_tmp2_ = g_str_equal;
	_data_->_tmp3_ = g_hash_table_new_full (_data_->_tmp1_, _data_->_tmp2_, _g_free0_, _g_variant_unref0_);
	_data_->_ret = _data_->_tmp3_;
	_data_->_tmp4_ = _data_->node_file;
	_data_->_tmp5_ = NULL;
	_data_->_tmp5_ = g_file_read (_data_->_tmp4_, NULL, &_data_->_inner_error_);
	_data_->_tmp6_ = _data_->_tmp5_;
	if (_data_->_inner_error_ != NULL) {
		if ((_data_->_inner_error_->domain == G_DBUS_ERROR) || (_data_->_inner_error_->domain == G_IO_ERROR)) {
			g_simple_async_result_set_from_error (_data_->_async_result, _data_->_inner_error_);
			g_error_free (_data_->_inner_error_);
			_g_variant_unref0 (_data_->val);
			_g_hash_table_unref0 (_data_->_ret);
			_g_free0 (_data_->line);
			_g_object_unref0 (_data_->node_file);
			if (_data_->_state_ == 0) {
				g_simple_async_result_complete_in_idle (_data_->_async_result);
			} else {
				g_simple_async_result_complete (_data_->_async_result);
			}
			g_object_unref (_data_->_async_result);
			return FALSE;
		} else {
			_g_variant_unref0 (_data_->val);
			_g_hash_table_unref0 (_data_->_ret);
			_g_free0 (_data_->line);
			_g_object_unref0 (_data_->node_file);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
			g_clear_error (&_data_->_inner_error_);
			return FALSE;
		}
	}
	_data_->_tmp7_ = _data_->_tmp6_;
	_data_->_tmp8_ = g_data_input_stream_new ((GInputStream*) _data_->_tmp7_);
	_data_->_tmp9_ = _data_->_tmp8_;
	_g_object_unref0 (_data_->_tmp7_);
	_data_->stream = _data_->_tmp9_;
	{
		_data_->_tmp10_ = _data_->stream;
		_data_->_tmp11_ = NULL;
		_data_->_tmp11_ = g_data_input_stream_read_line (_data_->_tmp10_, NULL, NULL, &_data_->_inner_error_);
		_data_->_tmp12_ = _data_->_tmp11_;
		if (_data_->_inner_error_ != NULL) {
			goto __catch0_g_error;
		}
		_g_free0 (_data_->line);
		_data_->line = _data_->_tmp12_;
		while (TRUE) {
			_data_->_tmp13_ = _data_->stream;
			_data_->_tmp14_ = NULL;
			_data_->_tmp14_ = g_data_input_stream_read_line (_data_->_tmp13_, NULL, NULL, &_data_->_inner_error_);
			_data_->_tmp15_ = _data_->_tmp14_;
			if (_data_->_inner_error_ != NULL) {
				goto __catch0_g_error;
			}
			_g_free0 (_data_->line);
			_data_->line = _data_->_tmp15_;
			_data_->_tmp16_ = _data_->line;
			if (!(_data_->_tmp16_ != NULL)) {
				break;
			}
			_data_->_tmp18_ = _data_->line;
			if (g_strcmp0 (_data_->_tmp18_, "\n") == 0) {
				_data_->_tmp17_ = TRUE;
			} else {
				_data_->_tmp19_ = _data_->line;
				_data_->_tmp17_ = g_strcmp0 (_data_->_tmp19_, "") == 0;
			}
			_data_->_tmp20_ = _data_->_tmp17_;
			if (_data_->_tmp20_) {
				continue;
			}
			_data_->_tmp21_ = _data_->line;
			_data_->_tmp23_ = NULL;
			_data_->_tmp23_ = _data_->_tmp22_ = g_strsplit (_data_->_tmp21_, ":", 0);
			_data_->_list = _data_->_tmp23_;
			_data_->_list_length1 = _vala_array_length (_data_->_tmp22_);
			_data_->__list_size_ = _data_->_list_length1;
			_data_->_tmp25_ = _data_->_list;
			_data_->_tmp25__length1 = _data_->_list_length1;
			_data_->_tmp26_ = _data_->_tmp25_[1];
			if (g_strcmp0 (_data_->_tmp26_, "") != 0) {
				_data_->_tmp27_ = _data_->_list;
				_data_->_tmp27__length1 = _data_->_list_length1;
				_data_->_tmp28_ = _data_->_tmp27_[0];
				_data_->_tmp24_ = g_strcmp0 (_data_->_tmp28_, "") != 0;
			} else {
				_data_->_tmp24_ = FALSE;
			}
			_data_->_tmp29_ = _data_->_tmp24_;
			if (_data_->_tmp29_) {
				_data_->_tmp30_ = _data_->_list;
				_data_->_tmp30__length1 = _data_->_list_length1;
				_data_->_tmp31_ = _data_->_tmp30_[1];
				_data_->_tmp32_ = NULL;
				_data_->_tmp32_ = string_strip (_data_->_tmp31_);
				_data_->_tmp33_ = _variant_new1 (_data_->_tmp32_);
				_g_variant_unref0 (_data_->val);
				_data_->val = _data_->_tmp33_;
				_data_->_tmp34_ = _data_->_ret;
				_data_->_tmp35_ = _data_->_list;
				_data_->_tmp35__length1 = _data_->_list_length1;
				_data_->_tmp36_ = _data_->_tmp35_[0];
				_data_->_tmp37_ = NULL;
				_data_->_tmp37_ = string_strip (_data_->_tmp36_);
				_data_->_tmp38_ = _data_->val;
				_data_->_tmp39_ = _g_variant_ref0 (_data_->_tmp38_);
				g_hash_table_insert (_data_->_tmp34_, _data_->_tmp37_, _data_->_tmp39_);
			}
			_data_->_list = (_vala_array_free (_data_->_list, _data_->_list_length1, (GDestroyNotify) g_free), NULL);
		}
	}
	goto __finally0;
	__catch0_g_error:
	{
		_data_->_error_ = _data_->_inner_error_;
		_data_->_inner_error_ = NULL;
		_data_->_tmp40_ = ((FsoFrameworkAbstractObject*) _data_->self)->logger;
		_data_->_tmp41_ = _data_->_error_;
		_data_->_tmp42_ = _data_->_tmp41_->message;
		fso_framework_logger_warning (_data_->_tmp40_, _data_->_tmp42_);
		_g_error_free0 (_data_->_error_);
	}
	__finally0:
	if (_data_->_inner_error_ != NULL) {
		if ((_data_->_inner_error_->domain == G_DBUS_ERROR) || (_data_->_inner_error_->domain == G_IO_ERROR)) {
			g_simple_async_result_set_from_error (_data_->_async_result, _data_->_inner_error_);
			g_error_free (_data_->_inner_error_);
			_g_object_unref0 (_data_->stream);
			_g_variant_unref0 (_data_->val);
			_g_hash_table_unref0 (_data_->_ret);
			_g_free0 (_data_->line);
			_g_object_unref0 (_data_->node_file);
			if (_data_->_state_ == 0) {
				g_simple_async_result_complete_in_idle (_data_->_async_result);
			} else {
				g_simple_async_result_complete (_data_->_async_result);
			}
			g_object_unref (_data_->_async_result);
			return FALSE;
		} else {
			_g_object_unref0 (_data_->stream);
			_g_variant_unref0 (_data_->val);
			_g_hash_table_unref0 (_data_->_ret);
			_g_free0 (_data_->line);
			_g_object_unref0 (_data_->node_file);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
			g_clear_error (&_data_->_inner_error_);
			return FALSE;
		}
	}
	_data_->result = _data_->_ret;
	_g_object_unref0 (_data_->stream);
	_g_variant_unref0 (_data_->val);
	_g_free0 (_data_->line);
	_g_object_unref0 (_data_->node_file);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
	_g_object_unref0 (_data_->stream);
	_g_variant_unref0 (_data_->val);
	_g_hash_table_unref0 (_data_->_ret);
	_g_free0 (_data_->line);
	_g_object_unref0 (_data_->node_file);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void kernel_info_class_init (KernelInfoClass * klass) {
	kernel_info_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (KernelInfoPrivate));
	FSO_FRAMEWORK_ABSTRACT_OBJECT_CLASS (klass)->repr = kernel_info_real_repr;
	G_OBJECT_CLASS (klass)->finalize = kernel_info_finalize;
}


static void kernel_info_free_smartphone_device_info_interface_init (FreeSmartphoneDeviceInfoIface * iface) {
	kernel_info_free_smartphone_device_info_parent_iface = g_type_interface_peek_parent (iface);
	iface->get_cpu_info = (GHashTable* (*)(FreeSmartphoneDeviceInfo*, GError**)) kernel_info_real_get_cpu_info;
	iface->get_cpu_info_finish = kernel_info_real_get_cpu_info_finish;
}


static void kernel_info_instance_init (KernelInfo * self) {
	self->priv = KERNEL_INFO_GET_PRIVATE (self);
}


static void kernel_info_finalize (GObject* obj) {
	KernelInfo * self;
	self = KERNEL_INFO (obj);
	_g_object_unref0 (self->priv->subsystem);
	G_OBJECT_CLASS (kernel_info_parent_class)->finalize (obj);
}


GType kernel_info_get_type (void) {
	return kernel_info_type_id;
}


GType kernel_info_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (KernelInfoClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) kernel_info_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (KernelInfo), 0, (GInstanceInitFunc) kernel_info_instance_init, NULL };
	static const GInterfaceInfo free_smartphone_device_info_info = { (GInterfaceInitFunc) kernel_info_free_smartphone_device_info_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	kernel_info_type_id = g_type_module_register_type (module, FSO_FRAMEWORK_TYPE_ABSTRACT_OBJECT, "KernelInfo", &g_define_type_info, 0);
	g_type_module_add_interface (module, kernel_info_type_id, FREE_SMARTPHONE_DEVICE_TYPE_INFO, &free_smartphone_device_info_info);
	return kernel_info_type_id;
}


gchar* fso_factory_function (FsoFrameworkSubsystem* subsystem, GError** error) {
	gchar* result = NULL;
	FsoFrameworkSubsystem* _tmp0_;
	KernelInfo* _tmp1_;
	gchar* _tmp2_;
	g_return_val_if_fail (subsystem != NULL, NULL);
	_tmp0_ = subsystem;
	_tmp1_ = kernel_info_new (_tmp0_);
	_g_object_unref0 (instance);
	instance = _tmp1_;
	_tmp2_ = g_strdup ("fsodevice.kernel_info");
	result = _tmp2_;
	return result;
}


void fso_register_function (GTypeModule* module) {
	FsoFrameworkLogger* _tmp0_;
	g_return_if_fail (module != NULL);
	kernel_info_register_type (module);
	_tmp0_ = fso_framework_theLogger;
	fso_framework_logger_debug (_tmp0_, "fsodevice.kernel_info fso_register_function()");
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



