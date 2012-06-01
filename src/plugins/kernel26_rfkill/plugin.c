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
#include <fsobasics.h>
#include <fsodevice.h>
#include <freesmartphone.h>
#include <stdlib.h>
#include <string.h>
#include <linux/rfkill.h>
#include <fsoframework.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <fsosystem.h>
#include <signal.h>
#include <gio/gio.h>


#define KERNEL26_TYPE_RF_KILL_POWER_CONTROL (kernel26_rf_kill_power_control_get_type ())
#define KERNEL26_RF_KILL_POWER_CONTROL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), KERNEL26_TYPE_RF_KILL_POWER_CONTROL, Kernel26RfKillPowerControl))
#define KERNEL26_RF_KILL_POWER_CONTROL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), KERNEL26_TYPE_RF_KILL_POWER_CONTROL, Kernel26RfKillPowerControlClass))
#define KERNEL26_IS_RF_KILL_POWER_CONTROL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), KERNEL26_TYPE_RF_KILL_POWER_CONTROL))
#define KERNEL26_IS_RF_KILL_POWER_CONTROL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), KERNEL26_TYPE_RF_KILL_POWER_CONTROL))
#define KERNEL26_RF_KILL_POWER_CONTROL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), KERNEL26_TYPE_RF_KILL_POWER_CONTROL, Kernel26RfKillPowerControlClass))

typedef struct _Kernel26RfKillPowerControl Kernel26RfKillPowerControl;
typedef struct _Kernel26RfKillPowerControlClass Kernel26RfKillPowerControlClass;
typedef struct _Kernel26RfKillPowerControlPrivate Kernel26RfKillPowerControlPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_io_channel_unref0(var) ((var == NULL) ? NULL : (var = (g_io_channel_unref (var), NULL)))
#define _fso_framework_network_interface_unref0(var) ((var == NULL) ? NULL : (var = (fso_framework_network_interface_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
typedef struct _Kernel26RfKillPowerControlGetPowerData Kernel26RfKillPowerControlGetPowerData;
typedef struct _Kernel26RfKillPowerControlSetPowerData Kernel26RfKillPowerControlSetPowerData;
#define _g_hash_table_unref0(var) ((var == NULL) ? NULL : (var = (g_hash_table_unref (var), NULL)))

struct _Kernel26RfKillPowerControl {
	FsoFrameworkAbstractObject parent_instance;
	Kernel26RfKillPowerControlPrivate * priv;
};

struct _Kernel26RfKillPowerControlClass {
	FsoFrameworkAbstractObjectClass parent_class;
};

struct _Kernel26RfKillPowerControlPrivate {
	guint id;
	gchar* type;
	gboolean softoff;
	gboolean hardoff;
	gint bluetoothd_pid;
	gchar* bluetoothd_startup_handler;
	gchar* wifi_iface;
	FsoDeviceBasePowerControlResource* resource;
};

struct _Kernel26RfKillPowerControlGetPowerData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	Kernel26RfKillPowerControl* self;
	gboolean result;
	gboolean _tmp0_;
};

struct _Kernel26RfKillPowerControlSetPowerData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	Kernel26RfKillPowerControl* self;
	gboolean on;
	gboolean _tmp0_;
};


static gpointer kernel26_rf_kill_power_control_parent_class = NULL;
extern FsoFrameworkSubsystem* subsystem;
extern gint fd;
extern gchar* devfs_root;
extern GIOChannel* channel;
extern guint watch;
extern GHashTable* instances;
static FsoDeviceISimplePowerControlIface* kernel26_rf_kill_power_control_fso_device_isimple_power_control_parent_iface = NULL;
static FreeSmartphoneDevicePowerControlIface* kernel26_rf_kill_power_control_free_smartphone_device_power_control_parent_iface = NULL;
static GType kernel26_rf_kill_power_control_type_id = 0;
GHashTable* instances = NULL;
extern gchar* sysfs_root;
gchar* sysfs_root = NULL;
gchar* devfs_root = NULL;
FsoFrameworkSubsystem* subsystem = NULL;
gint fd = 0;
guint watch = 0U;
GIOChannel* channel = NULL;

GType kernel26_rf_kill_power_control_get_type (void) G_GNUC_CONST;
GType kernel26_rf_kill_power_control_register_type (GTypeModule * module);
#define KERNEL26_RF_KILL_POWER_CONTROL_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), KERNEL26_TYPE_RF_KILL_POWER_CONTROL, Kernel26RfKillPowerControlPrivate))
enum  {
	KERNEL26_RF_KILL_POWER_CONTROL_DUMMY_PROPERTY
};
static Kernel26RfKillPowerControl* kernel26_rf_kill_power_control_new (guint id, guint8 type, gboolean softoff, gboolean hardoff);
static Kernel26RfKillPowerControl* kernel26_rf_kill_power_control_construct (GType object_type, guint id, guint8 type, gboolean softoff, gboolean hardoff);
static gboolean __lambda0_ (Kernel26RfKillPowerControl* self);
static gboolean ___lambda0__gsource_func (gpointer self);
static gchar* kernel26_rf_kill_power_control_real_repr (FsoFrameworkAbstractObject* base);
static void kernel26_rf_kill_power_control_init (Kernel26RfKillPowerControl* self);
gboolean kernel26_rf_kill_power_control_onActionFromRfKill (GIOChannel* source, GIOCondition condition);
static gboolean _kernel26_rf_kill_power_control_onActionFromRfKill_gio_func (GIOChannel* source, GIOCondition condition, gpointer self);
void kernel26_rf_kill_power_control_handleEvent (struct rfkill_event* event);
void kernel26_rf_kill_power_control_powerChangedTo (Kernel26RfKillPowerControl* self, gboolean softoff, gboolean hardoff);
void kernel26_rf_kill_power_control_setup_wifi_interface (Kernel26RfKillPowerControl* self, gboolean on);
void kernel26_rf_kill_power_control_start_bluetoothd (Kernel26RfKillPowerControl* self);
void kernel26_rf_kill_power_control_stop_bluetoothd (Kernel26RfKillPowerControl* self);
static gboolean kernel26_rf_kill_power_control_real_getPower (FsoDeviceISimplePowerControl* base);
static void kernel26_rf_kill_power_control_real_setPower (FsoDeviceISimplePowerControl* base, gboolean on);
static void kernel26_rf_kill_power_control_real_get_power_data_free (gpointer _data);
static void kernel26_rf_kill_power_control_real_get_power (FreeSmartphoneDevicePowerControl* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean kernel26_rf_kill_power_control_real_get_power_co (Kernel26RfKillPowerControlGetPowerData* _data_);
static void kernel26_rf_kill_power_control_real_set_power_data_free (gpointer _data);
static void kernel26_rf_kill_power_control_real_set_power (FreeSmartphoneDevicePowerControl* base, gboolean on, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean kernel26_rf_kill_power_control_real_set_power_co (Kernel26RfKillPowerControlSetPowerData* _data_);
static void kernel26_rf_kill_power_control_finalize (GObject* obj);
gchar* fso_factory_function (FsoFrameworkSubsystem* system, GError** error);
static void _g_object_unref0_ (gpointer var);
void fso_register_function (GTypeModule* module);

static const gchar* KERNEL26_RF_KILL_POWER_CONTROL_opValue[7] = {"Add", "Del", "Change", "ChangeAll", "unknown:4", "unknown:5", "unknown:6"};
static const gchar* KERNEL26_RF_KILL_POWER_CONTROL_typeValue[8] = {"All", "WiFi", "Bluetooth", "UWB", "WiMax", "WWan", "GPS", "FM"};
static const gchar* KERNEL26_RF_KILL_POWER_CONTROL_bluetoothd[2] = {"/usr/sbin/bluetoothd", "-n"};

static gboolean __lambda0_ (Kernel26RfKillPowerControl* self) {
	gboolean result = FALSE;
	const gchar* _tmp0_;
	FsoFrameworkSubsystem* _tmp1_;
	FsoDeviceBasePowerControlResource* _tmp2_;
	_tmp0_ = self->priv->type;
	_tmp1_ = subsystem;
	_tmp2_ = fso_device_base_power_control_resource_new ((FsoDeviceISimplePowerControl*) self, _tmp0_, _tmp1_);
	_g_object_unref0 (self->priv->resource);
	self->priv->resource = _tmp2_;
	result = FALSE;
	return result;
}


static gboolean ___lambda0__gsource_func (gpointer self) {
	gboolean result;
	result = __lambda0_ (self);
	return result;
}


static Kernel26RfKillPowerControl* kernel26_rf_kill_power_control_construct (GType object_type, guint id, guint8 type, gboolean softoff, gboolean hardoff) {
	Kernel26RfKillPowerControl * self = NULL;
	guint _tmp0_;
	guint8 _tmp1_;
	gboolean _tmp16_;
	gboolean _tmp17_;
	FsoFrameworkSubsystem* _tmp18_;
	FsoFrameworkLogger* _tmp19_;
	self = (Kernel26RfKillPowerControl*) fso_framework_abstract_object_construct (object_type);
	_tmp0_ = id;
	self->priv->id = _tmp0_;
	_tmp1_ = type;
	switch (_tmp1_) {
		case RFKILL_TYPE_WLAN:
		{
			FsoFrameworkSmartKeyFile* _tmp2_;
			gchar* _tmp3_ = NULL;
			gchar* _tmp4_;
			_tmp2_ = ((FsoFrameworkAbstractObject*) self)->config;
			_tmp3_ = fso_framework_smart_key_file_stringValue (_tmp2_, "fsodevice.kernel26_rfkill", "wifi_interface", "wlan0");
			_g_free0 (self->priv->wifi_iface);
			self->priv->wifi_iface = _tmp3_;
			_tmp4_ = g_strdup ("WiFi");
			_g_free0 (self->priv->type);
			self->priv->type = _tmp4_;
			break;
		}
		case RFKILL_TYPE_BLUETOOTH:
		{
			FsoFrameworkSmartKeyFile* _tmp5_;
			gchar* _tmp6_ = NULL;
			gchar* _tmp7_;
			_tmp5_ = ((FsoFrameworkAbstractObject*) self)->config;
			_tmp6_ = fso_framework_smart_key_file_stringValue (_tmp5_, "fsodevice.kernel26_rfkill", "bluetoothd_startup_handler", "fsodeviced");
			_g_free0 (self->priv->bluetoothd_startup_handler);
			self->priv->bluetoothd_startup_handler = _tmp6_;
			_tmp7_ = g_strdup ("Bluetooth");
			_g_free0 (self->priv->type);
			self->priv->type = _tmp7_;
			break;
		}
		case RFKILL_TYPE_UWB:
		{
			gchar* _tmp8_;
			_tmp8_ = g_strdup ("UWB");
			_g_free0 (self->priv->type);
			self->priv->type = _tmp8_;
			break;
		}
		case RFKILL_TYPE_WIMAX:
		{
			gchar* _tmp9_;
			_tmp9_ = g_strdup ("WiMax");
			_g_free0 (self->priv->type);
			self->priv->type = _tmp9_;
			break;
		}
		case RFKILL_TYPE_WWAN:
		{
			gchar* _tmp10_;
			_tmp10_ = g_strdup ("WWan");
			_g_free0 (self->priv->type);
			self->priv->type = _tmp10_;
			break;
		}
		case 0x6:
		{
			gchar* _tmp11_;
			_tmp11_ = g_strdup ("GPS");
			_g_free0 (self->priv->type);
			self->priv->type = _tmp11_;
			break;
		}
		case 0x7:
		{
			gchar* _tmp12_;
			_tmp12_ = g_strdup ("FM");
			_g_free0 (self->priv->type);
			self->priv->type = _tmp12_;
			break;
		}
		default:
		{
			FsoFrameworkLogger* _tmp13_;
			guint8 _tmp14_;
			gchar* _tmp15_ = NULL;
			_tmp13_ = ((FsoFrameworkAbstractObject*) self)->logger;
			fso_framework_logger_warning (_tmp13_, "Unknown RfKillType %u - please report");
			_tmp14_ = type;
			_tmp15_ = g_strdup_printf ("unknown:%u", (guint) _tmp14_);
			_g_free0 (self->priv->type);
			self->priv->type = _tmp15_;
			break;
		}
	}
	_tmp16_ = softoff;
	self->priv->softoff = _tmp16_;
	_tmp17_ = hardoff;
	self->priv->hardoff = _tmp17_;
	_tmp18_ = subsystem;
	fso_framework_subsystem_registerObjectForServiceWithPrefix (_tmp18_, FREE_SMARTPHONE_DEVICE_TYPE_POWER_CONTROL, (GBoxedCopyFunc) g_object_ref, g_object_unref, FSO_FRAMEWORK_DEVICE_ServiceDBusName, FSO_FRAMEWORK_DEVICE_PowerControlServicePath, (FreeSmartphoneDevicePowerControl*) self);
	g_idle_add_full (G_PRIORITY_DEFAULT_IDLE, ___lambda0__gsource_func, g_object_ref (self), g_object_unref);
	_tmp19_ = ((FsoFrameworkAbstractObject*) self)->logger;
	fso_framework_logger_info (_tmp19_, "created.");
	return self;
}


static Kernel26RfKillPowerControl* kernel26_rf_kill_power_control_new (guint id, guint8 type, gboolean softoff, gboolean hardoff) {
	return kernel26_rf_kill_power_control_construct (KERNEL26_TYPE_RF_KILL_POWER_CONTROL, id, type, softoff, hardoff);
}


static gchar* kernel26_rf_kill_power_control_real_repr (FsoFrameworkAbstractObject* base) {
	Kernel26RfKillPowerControl * self;
	gchar* result = NULL;
	const gchar* _tmp0_ = NULL;
	gboolean _tmp1_;
	const gchar* _tmp2_ = NULL;
	gboolean _tmp3_;
	guint _tmp4_;
	const gchar* _tmp5_;
	const gchar* _tmp6_;
	const gchar* _tmp7_;
	gchar* _tmp8_ = NULL;
	self = (Kernel26RfKillPowerControl*) base;
	_tmp1_ = self->priv->softoff;
	if (_tmp1_) {
		_tmp0_ = "off";
	} else {
		_tmp0_ = "on";
	}
	_tmp3_ = self->priv->hardoff;
	if (_tmp3_) {
		_tmp2_ = "off";
	} else {
		_tmp2_ = "on";
	}
	_tmp4_ = self->priv->id;
	_tmp5_ = self->priv->type;
	_tmp6_ = _tmp0_;
	_tmp7_ = _tmp2_;
	_tmp8_ = g_strdup_printf ("<%u:%s:soft%s:hard%s>", _tmp4_, _tmp5_, _tmp6_, _tmp7_);
	result = _tmp8_;
	return result;
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


static gboolean _kernel26_rf_kill_power_control_onActionFromRfKill_gio_func (GIOChannel* source, GIOCondition condition, gpointer self) {
	gboolean result;
	result = kernel26_rf_kill_power_control_onActionFromRfKill (source, condition);
	return result;
}


static void kernel26_rf_kill_power_control_init (Kernel26RfKillPowerControl* self) {
	gint _tmp0_;
	const gchar* _tmp1_;
	gchar* _tmp2_ = NULL;
	gchar* _tmp3_;
	gint _tmp4_ = 0;
	gint _tmp5_;
	gint _tmp14_;
	GIOChannel* _tmp15_;
	GIOChannel* _tmp16_;
	guint _tmp17_ = 0U;
	g_return_if_fail (self != NULL);
	_tmp0_ = fd;
	if (_tmp0_ != (-1)) {
		return;
	}
	_tmp1_ = devfs_root;
	_tmp2_ = g_build_filename (_tmp1_, "rfkill", NULL);
	_tmp3_ = _tmp2_;
	_tmp4_ = open (_tmp3_, O_RDWR, (mode_t) 0);
	fd = _tmp4_;
	_g_free0 (_tmp3_);
	_tmp5_ = fd;
	if (_tmp5_ == (-1)) {
		FsoFrameworkLogger* _tmp6_;
		const gchar* _tmp7_;
		const gchar* _tmp8_ = NULL;
		gint _tmp9_;
		const gchar* _tmp10_ = NULL;
		const gchar* _tmp11_ = NULL;
		gchar* _tmp12_ = NULL;
		gchar* _tmp13_;
		_tmp6_ = ((FsoFrameworkAbstractObject*) self)->logger;
		_tmp7_ = devfs_root;
		_tmp8_ = string_to_string (_tmp7_);
		_tmp9_ = errno;
		_tmp10_ = g_strerror (_tmp9_);
		_tmp11_ = string_to_string (_tmp10_);
		_tmp12_ = g_strconcat ("Can't open ", _tmp8_, ": ", _tmp11_, "; rfkill plugin will not be operating", NULL);
		_tmp13_ = _tmp12_;
		fso_framework_logger_error (_tmp6_, _tmp13_);
		_g_free0 (_tmp13_);
		return;
	}
	_tmp14_ = fd;
	_tmp15_ = g_io_channel_unix_new (_tmp14_);
	_g_io_channel_unref0 (channel);
	channel = _tmp15_;
	_tmp16_ = channel;
	_tmp17_ = g_io_add_watch (_tmp16_, G_IO_IN | G_IO_HUP, _kernel26_rf_kill_power_control_onActionFromRfKill_gio_func, NULL);
	watch = _tmp17_;
}


gboolean kernel26_rf_kill_power_control_onActionFromRfKill (GIOChannel* source, GIOCondition condition) {
	gboolean result = FALSE;
	GIOCondition _tmp0_;
	GIOCondition _tmp1_;
	GIOCondition _tmp8_;
	g_return_val_if_fail (source != NULL, FALSE);
	_tmp0_ = condition;
	if ((_tmp0_ & G_IO_HUP) == G_IO_HUP) {
		g_warning ("plugin.vala:123: HUP on rfkill, will no longer get any notifications");
		result = FALSE;
		return result;
	}
	_tmp1_ = condition;
	if ((_tmp1_ & G_IO_IN) == G_IO_IN) {
		gint _tmp2_;
		struct rfkill_event event = {0};
		gint _tmp3_;
		gssize _tmp4_ = 0L;
		gssize bytesread;
		gssize _tmp5_;
		struct rfkill_event _tmp7_;
		_tmp2_ = fd;
		g_assert (_tmp2_ != (-1));
		memset (&event, 0, sizeof (struct rfkill_event));
		_tmp3_ = fd;
		_tmp4_ = read (_tmp3_, &event, (gsize) sizeof (struct rfkill_event));
		bytesread = _tmp4_;
		_tmp5_ = bytesread;
		if (((gulong) _tmp5_) != sizeof (struct rfkill_event)) {
			gssize _tmp6_;
			_tmp6_ = bytesread;
			g_warning ("plugin.vala:134: can't read full rfkill event, got only %d bytes", (gint) _tmp6_);
			result = TRUE;
			return result;
		}
		_tmp7_ = event;
		kernel26_rf_kill_power_control_handleEvent (&_tmp7_);
		result = TRUE;
		return result;
	}
	_tmp8_ = condition;
	g_error ("plugin.vala:144: Unsupported IOCondition %u", (guint) ((gint) _tmp8_));
	result = TRUE;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void kernel26_rf_kill_power_control_handleEvent (struct rfkill_event* event) {
	struct rfkill_event _tmp0_;
	guint8 _tmp1_;
	g_return_if_fail (event != NULL);
	_tmp0_ = *event;
	_tmp1_ = _tmp0_.op;
	switch (_tmp1_) {
		case RFKILL_OP_ADD:
		{
			GHashTable* _tmp2_;
			struct rfkill_event _tmp3_;
			guint32 _tmp4_;
			struct rfkill_event _tmp5_;
			guint32 _tmp6_;
			struct rfkill_event _tmp7_;
			guint8 _tmp8_;
			struct rfkill_event _tmp9_;
			guint8 _tmp10_;
			struct rfkill_event _tmp11_;
			guint8 _tmp12_;
			Kernel26RfKillPowerControl* _tmp13_;
			_tmp2_ = instances;
			_tmp3_ = *event;
			_tmp4_ = _tmp3_.idx;
			_tmp5_ = *event;
			_tmp6_ = _tmp5_.idx;
			_tmp7_ = *event;
			_tmp8_ = _tmp7_.type;
			_tmp9_ = *event;
			_tmp10_ = _tmp9_.soft;
			_tmp11_ = *event;
			_tmp12_ = _tmp11_.hard;
			_tmp13_ = kernel26_rf_kill_power_control_new ((guint) _tmp6_, _tmp8_, ((gint) _tmp10_) == 1, ((gint) _tmp12_) == 1);
			g_hash_table_insert (_tmp2_, GINT_TO_POINTER ((gint) _tmp4_), _tmp13_);
			break;
		}
		case RFKILL_OP_DEL:
		{
			GHashTable* _tmp14_;
			struct rfkill_event _tmp15_;
			guint32 _tmp16_;
			_tmp14_ = instances;
			_tmp15_ = *event;
			_tmp16_ = _tmp15_.idx;
			g_hash_table_remove (_tmp14_, GINT_TO_POINTER ((gint) _tmp16_));
			break;
		}
		case RFKILL_OP_CHANGE:
		{
			GHashTable* _tmp17_;
			struct rfkill_event _tmp18_;
			guint32 _tmp19_;
			gconstpointer _tmp20_ = NULL;
			Kernel26RfKillPowerControl* _tmp21_;
			Kernel26RfKillPowerControl* instance;
			Kernel26RfKillPowerControl* _tmp22_;
			Kernel26RfKillPowerControl* _tmp23_;
			struct rfkill_event _tmp24_;
			guint8 _tmp25_;
			struct rfkill_event _tmp26_;
			guint8 _tmp27_;
			_tmp17_ = instances;
			_tmp18_ = *event;
			_tmp19_ = _tmp18_.idx;
			_tmp20_ = g_hash_table_lookup (_tmp17_, GINT_TO_POINTER ((gint) _tmp19_));
			_tmp21_ = _g_object_ref0 ((Kernel26RfKillPowerControl*) _tmp20_);
			instance = _tmp21_;
			_tmp22_ = instance;
			if (_tmp22_ == NULL) {
				g_warning ("plugin.vala:171: Got rfkill change event for unknown IDX; ignoring");
				_g_object_unref0 (instance);
				return;
			}
			_tmp23_ = instance;
			_tmp24_ = *event;
			_tmp25_ = _tmp24_.soft;
			_tmp26_ = *event;
			_tmp27_ = _tmp26_.hard;
			kernel26_rf_kill_power_control_powerChangedTo (_tmp23_, ((gint) _tmp25_) == 1, ((gint) _tmp27_) == 1);
			_g_object_unref0 (instance);
			break;
		}
		default:
		{
			struct rfkill_event _tmp28_;
			guint8 _tmp29_;
			_tmp28_ = *event;
			_tmp29_ = _tmp28_.op;
			g_error ("plugin.vala:177: unknown rfkill op %u; ignoring", (guint) _tmp29_);
			break;
		}
	}
}


void kernel26_rf_kill_power_control_setup_wifi_interface (Kernel26RfKillPowerControl* self, gboolean on) {
	GError * _inner_error_ = NULL;
	g_return_if_fail (self != NULL);
	{
		const gchar* _tmp0_;
		FsoFrameworkNetworkWextInterface* _tmp1_;
		FsoFrameworkNetworkWextInterface* iface;
		gboolean _tmp2_;
		FsoFrameworkNetworkWextInterface* _tmp6_;
		_tmp0_ = self->priv->wifi_iface;
		_tmp1_ = fso_framework_network_wext_interface_new (_tmp0_, &_inner_error_);
		iface = _tmp1_;
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == FSO_FRAMEWORK_NETWORK_ERROR) {
				goto __catch0_fso_framework_network_error;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
		_tmp2_ = on;
		if (_tmp2_) {
			FsoFrameworkNetworkWextInterface* _tmp3_;
			FsoFrameworkNetworkWextInterface* _tmp4_;
			_tmp3_ = iface;
			fso_framework_network_interface_up ((FsoFrameworkNetworkInterface*) _tmp3_, &_inner_error_);
			if (_inner_error_ != NULL) {
				_fso_framework_network_interface_unref0 (iface);
				if (_inner_error_->domain == FSO_FRAMEWORK_NETWORK_ERROR) {
					goto __catch0_fso_framework_network_error;
				}
				_fso_framework_network_interface_unref0 (iface);
				g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return;
			}
			_tmp4_ = iface;
			fso_framework_network_wext_interface_set_power (_tmp4_, TRUE, &_inner_error_);
			if (_inner_error_ != NULL) {
				_fso_framework_network_interface_unref0 (iface);
				if (_inner_error_->domain == FSO_FRAMEWORK_NETWORK_ERROR) {
					goto __catch0_fso_framework_network_error;
				}
				_fso_framework_network_interface_unref0 (iface);
				g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return;
			}
		} else {
			FsoFrameworkNetworkWextInterface* _tmp5_;
			_tmp5_ = iface;
			fso_framework_network_interface_down ((FsoFrameworkNetworkInterface*) _tmp5_, &_inner_error_);
			if (_inner_error_ != NULL) {
				_fso_framework_network_interface_unref0 (iface);
				if (_inner_error_->domain == FSO_FRAMEWORK_NETWORK_ERROR) {
					goto __catch0_fso_framework_network_error;
				}
				_fso_framework_network_interface_unref0 (iface);
				g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return;
			}
		}
		_tmp6_ = iface;
		fso_framework_network_interface_finish ((FsoFrameworkNetworkInterface*) _tmp6_);
		_fso_framework_network_interface_unref0 (iface);
	}
	goto __finally0;
	__catch0_fso_framework_network_error:
	{
		GError* err = NULL;
		const gchar* _tmp7_ = NULL;
		gboolean _tmp8_;
		FsoFrameworkLogger* _tmp9_;
		const gchar* _tmp10_;
		const gchar* _tmp11_ = NULL;
		gchar* _tmp12_ = NULL;
		gchar* _tmp13_;
		const gchar* _tmp14_;
		gchar* _tmp15_ = NULL;
		gchar* _tmp16_;
		err = _inner_error_;
		_inner_error_ = NULL;
		_tmp8_ = on;
		if (_tmp8_) {
			_tmp7_ = "Enabling";
		} else {
			_tmp7_ = "Disabling";
		}
		_tmp9_ = ((FsoFrameworkAbstractObject*) self)->logger;
		_tmp10_ = self->priv->wifi_iface;
		_tmp11_ = string_to_string (_tmp10_);
		_tmp12_ = g_strconcat ("%s network interface ", _tmp11_, " failed!", NULL);
		_tmp13_ = _tmp12_;
		_tmp14_ = _tmp7_;
		_tmp15_ = g_strdup_printf (_tmp13_, _tmp14_);
		_tmp16_ = _tmp15_;
		fso_framework_logger_error (_tmp9_, _tmp16_);
		_g_free0 (_tmp16_);
		_g_free0 (_tmp13_);
		_g_error_free0 (err);
	}
	__finally0:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}


void kernel26_rf_kill_power_control_start_bluetoothd (Kernel26RfKillPowerControl* self) {
	FsoFrameworkLogger* _tmp0_;
	const gchar* _tmp1_ = NULL;
	GPid _tmp2_ = 0;
	FsoFrameworkLogger* _tmp3_;
	gint _tmp4_;
	gchar* _tmp5_ = NULL;
	gchar* _tmp6_;
	gchar* _tmp7_ = NULL;
	gchar* _tmp8_;
	GError * _inner_error_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = ((FsoFrameworkAbstractObject*) self)->logger;
	fso_framework_logger_info (_tmp0_, "bluetoothd starting...");
	_tmp1_ = g_getenv ("PWD");
	g_spawn_async (_tmp1_, KERNEL26_RF_KILL_POWER_CONTROL_bluetoothd, NULL, 0, NULL, NULL, &_tmp2_, &_inner_error_);
	self->priv->bluetoothd_pid = (gint) _tmp2_;
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp3_ = ((FsoFrameworkAbstractObject*) self)->logger;
	_tmp4_ = self->priv->bluetoothd_pid;
	_tmp5_ = g_strdup_printf ("%i", _tmp4_);
	_tmp6_ = _tmp5_;
	_tmp7_ = g_strconcat ("bluetoothd pid: ", _tmp6_, NULL);
	_tmp8_ = _tmp7_;
	fso_framework_logger_debug (_tmp3_, _tmp8_);
	_g_free0 (_tmp8_);
	_g_free0 (_tmp6_);
}


void kernel26_rf_kill_power_control_stop_bluetoothd (Kernel26RfKillPowerControl* self) {
	FsoFrameworkLogger* _tmp0_;
	gint _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = ((FsoFrameworkAbstractObject*) self)->logger;
	fso_framework_logger_info (_tmp0_, "bluetoothd stopping...");
	_tmp1_ = self->priv->bluetoothd_pid;
	if (_tmp1_ != 0) {
		gint _tmp2_;
		FsoFrameworkLogger* _tmp3_;
		gint _tmp4_;
		gchar* _tmp5_ = NULL;
		gchar* _tmp6_;
		gchar* _tmp7_ = NULL;
		gchar* _tmp8_;
		_tmp2_ = self->priv->bluetoothd_pid;
		kill ((pid_t) _tmp2_, SIGKILL);
		_tmp3_ = ((FsoFrameworkAbstractObject*) self)->logger;
		_tmp4_ = self->priv->bluetoothd_pid;
		_tmp5_ = g_strdup_printf ("%i", _tmp4_);
		_tmp6_ = _tmp5_;
		_tmp7_ = g_strconcat ("killing bluetoothd with pid: ", _tmp6_, NULL);
		_tmp8_ = _tmp7_;
		fso_framework_logger_debug (_tmp3_, _tmp8_);
		_g_free0 (_tmp8_);
		_g_free0 (_tmp6_);
	}
}


void kernel26_rf_kill_power_control_powerChangedTo (Kernel26RfKillPowerControl* self, gboolean softoff, gboolean hardoff) {
	FsoFrameworkLogger* _tmp0_;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp2_;
	gboolean _tmp3_;
	FsoFrameworkLogger* _tmp4_;
	gboolean _tmp5_ = FALSE;
	g_return_if_fail (self != NULL);
	_tmp0_ = ((FsoFrameworkAbstractObject*) self)->logger;
	_tmp1_ = fso_framework_logger_debug (_tmp0_, "Status changed from...");
	g_assert (_tmp1_);
	_tmp2_ = softoff;
	self->priv->softoff = _tmp2_;
	_tmp3_ = hardoff;
	self->priv->hardoff = _tmp3_;
	_tmp4_ = ((FsoFrameworkAbstractObject*) self)->logger;
	_tmp5_ = fso_framework_logger_debug (_tmp4_, "... to");
	g_assert (_tmp5_);
}


static gboolean kernel26_rf_kill_power_control_real_getPower (FsoDeviceISimplePowerControl* base) {
	Kernel26RfKillPowerControl * self;
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_;
	gboolean _tmp3_;
	self = (Kernel26RfKillPowerControl*) base;
	_tmp1_ = self->priv->hardoff;
	if (_tmp1_) {
		_tmp0_ = FALSE;
	} else {
		gboolean _tmp2_;
		_tmp2_ = self->priv->softoff;
		_tmp0_ = !_tmp2_;
	}
	_tmp3_ = _tmp0_;
	result = _tmp3_;
	return result;
}


static void kernel26_rf_kill_power_control_real_setPower (FsoDeviceISimplePowerControl* base, gboolean on) {
	Kernel26RfKillPowerControl * self;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	const gchar* _tmp2_;
	gboolean _tmp4_;
	gboolean _tmp6_;
	guint _tmp7_;
	gboolean _tmp8_;
	struct rfkill_event _tmp9_ = {0};
	struct rfkill_event event;
	gint _tmp10_;
	gssize _tmp11_ = 0L;
	gssize bwritten;
	gssize _tmp12_;
	const gchar* _tmp19_;
	self = (Kernel26RfKillPowerControl*) base;
	_tmp2_ = self->priv->bluetoothd_startup_handler;
	if (g_strcmp0 (_tmp2_, "fsodeviced") == 0) {
		const gchar* _tmp3_;
		_tmp3_ = self->priv->type;
		_tmp1_ = g_strcmp0 (_tmp3_, "Bluetooth") == 0;
	} else {
		_tmp1_ = FALSE;
	}
	_tmp4_ = _tmp1_;
	if (_tmp4_) {
		gboolean _tmp5_;
		_tmp5_ = on;
		_tmp0_ = _tmp5_ == FALSE;
	} else {
		_tmp0_ = FALSE;
	}
	_tmp6_ = _tmp0_;
	if (_tmp6_) {
		kernel26_rf_kill_power_control_stop_bluetoothd (self);
	}
	_tmp7_ = self->priv->id;
	_tmp8_ = on;
	memset (&_tmp9_, 0, sizeof (struct rfkill_event));
	_tmp9_.idx = (guint32) _tmp7_;
	_tmp9_.op = RFKILL_OP_CHANGE;
	_tmp9_.soft = (guint8) (!_tmp8_);
	event = _tmp9_;
	_tmp10_ = fd;
	_tmp11_ = write (_tmp10_, &event, (gsize) sizeof (struct rfkill_event));
	bwritten = _tmp11_;
	_tmp12_ = bwritten;
	if (_tmp12_ == ((gssize) (-1))) {
		FsoFrameworkLogger* _tmp13_;
		gint _tmp14_;
		const gchar* _tmp15_ = NULL;
		const gchar* _tmp16_ = NULL;
		gchar* _tmp17_ = NULL;
		gchar* _tmp18_;
		_tmp13_ = ((FsoFrameworkAbstractObject*) self)->logger;
		_tmp14_ = errno;
		_tmp15_ = g_strerror (_tmp14_);
		_tmp16_ = string_to_string (_tmp15_);
		_tmp17_ = g_strconcat ("Could not write rfkill event: ", _tmp16_, NULL);
		_tmp18_ = _tmp17_;
		fso_framework_logger_error (_tmp13_, _tmp18_);
		_g_free0 (_tmp18_);
	}
	_tmp19_ = self->priv->type;
	if (g_strcmp0 (_tmp19_, "WiFi") == 0) {
		gboolean _tmp20_;
		_tmp20_ = on;
		kernel26_rf_kill_power_control_setup_wifi_interface (self, _tmp20_);
	} else {
		gboolean _tmp21_ = FALSE;
		gboolean _tmp22_ = FALSE;
		const gchar* _tmp23_;
		gboolean _tmp25_;
		gboolean _tmp27_;
		_tmp23_ = self->priv->bluetoothd_startup_handler;
		if (g_strcmp0 (_tmp23_, "fsodeviced") == 0) {
			const gchar* _tmp24_;
			_tmp24_ = self->priv->type;
			_tmp22_ = g_strcmp0 (_tmp24_, "Bluetooth") == 0;
		} else {
			_tmp22_ = FALSE;
		}
		_tmp25_ = _tmp22_;
		if (_tmp25_) {
			gboolean _tmp26_;
			_tmp26_ = on;
			_tmp21_ = _tmp26_ == TRUE;
		} else {
			_tmp21_ = FALSE;
		}
		_tmp27_ = _tmp21_;
		if (_tmp27_) {
			kernel26_rf_kill_power_control_start_bluetoothd (self);
		}
	}
}


static void kernel26_rf_kill_power_control_real_get_power_data_free (gpointer _data) {
	Kernel26RfKillPowerControlGetPowerData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (Kernel26RfKillPowerControlGetPowerData, _data_);
}


static void kernel26_rf_kill_power_control_real_get_power (FreeSmartphoneDevicePowerControl* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	Kernel26RfKillPowerControl * self;
	Kernel26RfKillPowerControlGetPowerData* _data_;
	Kernel26RfKillPowerControl* _tmp0_;
	self = (Kernel26RfKillPowerControl*) base;
	_data_ = g_slice_new0 (Kernel26RfKillPowerControlGetPowerData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, kernel26_rf_kill_power_control_real_get_power);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, kernel26_rf_kill_power_control_real_get_power_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	kernel26_rf_kill_power_control_real_get_power_co (_data_);
}


static gboolean kernel26_rf_kill_power_control_real_get_power_finish (FreeSmartphoneDevicePowerControl* base, GAsyncResult* _res_, GError** error) {
	gboolean result;
	Kernel26RfKillPowerControlGetPowerData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return FALSE;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	result = _data_->result;
	return result;
}


static gboolean kernel26_rf_kill_power_control_real_get_power_co (Kernel26RfKillPowerControlGetPowerData* _data_) {
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


static void kernel26_rf_kill_power_control_real_set_power_data_free (gpointer _data) {
	Kernel26RfKillPowerControlSetPowerData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (Kernel26RfKillPowerControlSetPowerData, _data_);
}


static void kernel26_rf_kill_power_control_real_set_power (FreeSmartphoneDevicePowerControl* base, gboolean on, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	Kernel26RfKillPowerControl * self;
	Kernel26RfKillPowerControlSetPowerData* _data_;
	Kernel26RfKillPowerControl* _tmp0_;
	gboolean _tmp1_;
	self = (Kernel26RfKillPowerControl*) base;
	_data_ = g_slice_new0 (Kernel26RfKillPowerControlSetPowerData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, kernel26_rf_kill_power_control_real_set_power);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, kernel26_rf_kill_power_control_real_set_power_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	_tmp1_ = on;
	_data_->on = _tmp1_;
	kernel26_rf_kill_power_control_real_set_power_co (_data_);
}


static void kernel26_rf_kill_power_control_real_set_power_finish (FreeSmartphoneDevicePowerControl* base, GAsyncResult* _res_, GError** error) {
	Kernel26RfKillPowerControlSetPowerData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static gboolean kernel26_rf_kill_power_control_real_set_power_co (Kernel26RfKillPowerControlSetPowerData* _data_) {
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


static void kernel26_rf_kill_power_control_class_init (Kernel26RfKillPowerControlClass * klass) {
	kernel26_rf_kill_power_control_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (Kernel26RfKillPowerControlPrivate));
	FSO_FRAMEWORK_ABSTRACT_OBJECT_CLASS (klass)->repr = kernel26_rf_kill_power_control_real_repr;
	G_OBJECT_CLASS (klass)->finalize = kernel26_rf_kill_power_control_finalize;
}


static void kernel26_rf_kill_power_control_fso_device_isimple_power_control_interface_init (FsoDeviceISimplePowerControlIface * iface) {
	kernel26_rf_kill_power_control_fso_device_isimple_power_control_parent_iface = g_type_interface_peek_parent (iface);
	iface->getPower = (gboolean (*)(FsoDeviceISimplePowerControl*)) kernel26_rf_kill_power_control_real_getPower;
	iface->setPower = (void (*)(FsoDeviceISimplePowerControl*, gboolean)) kernel26_rf_kill_power_control_real_setPower;
}


static void kernel26_rf_kill_power_control_free_smartphone_device_power_control_interface_init (FreeSmartphoneDevicePowerControlIface * iface) {
	kernel26_rf_kill_power_control_free_smartphone_device_power_control_parent_iface = g_type_interface_peek_parent (iface);
	iface->get_power = (gboolean (*)(FreeSmartphoneDevicePowerControl*, GError**)) kernel26_rf_kill_power_control_real_get_power;
	iface->get_power_finish = kernel26_rf_kill_power_control_real_get_power_finish;
	iface->set_power = (void (*)(FreeSmartphoneDevicePowerControl*, gboolean, GError**)) kernel26_rf_kill_power_control_real_set_power;
	iface->set_power_finish = kernel26_rf_kill_power_control_real_set_power_finish;
}


static void kernel26_rf_kill_power_control_instance_init (Kernel26RfKillPowerControl * self) {
	self->priv = KERNEL26_RF_KILL_POWER_CONTROL_GET_PRIVATE (self);
	self->priv->bluetoothd_pid = 0;
}


static void kernel26_rf_kill_power_control_finalize (GObject* obj) {
	Kernel26RfKillPowerControl * self;
	self = KERNEL26_RF_KILL_POWER_CONTROL (obj);
	_g_free0 (self->priv->type);
	_g_free0 (self->priv->bluetoothd_startup_handler);
	_g_free0 (self->priv->wifi_iface);
	_g_object_unref0 (self->priv->resource);
	G_OBJECT_CLASS (kernel26_rf_kill_power_control_parent_class)->finalize (obj);
}


/**
 * @class Kernel26.RfKillPowerControl
 *
 * Implementing org.freesmartphone.Device.PowerControl via Linux 2.6 rfkill API
 **/
GType kernel26_rf_kill_power_control_get_type (void) {
	return kernel26_rf_kill_power_control_type_id;
}


GType kernel26_rf_kill_power_control_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (Kernel26RfKillPowerControlClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) kernel26_rf_kill_power_control_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Kernel26RfKillPowerControl), 0, (GInstanceInitFunc) kernel26_rf_kill_power_control_instance_init, NULL };
	static const GInterfaceInfo fso_device_isimple_power_control_info = { (GInterfaceInitFunc) kernel26_rf_kill_power_control_fso_device_isimple_power_control_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	static const GInterfaceInfo free_smartphone_device_power_control_info = { (GInterfaceInitFunc) kernel26_rf_kill_power_control_free_smartphone_device_power_control_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	kernel26_rf_kill_power_control_type_id = g_type_module_register_type (module, FSO_FRAMEWORK_TYPE_ABSTRACT_OBJECT, "Kernel26RfKillPowerControl", &g_define_type_info, 0);
	g_type_module_add_interface (module, kernel26_rf_kill_power_control_type_id, FSO_DEVICE_TYPE_ISIMPLE_POWER_CONTROL, &fso_device_isimple_power_control_info);
	g_type_module_add_interface (module, kernel26_rf_kill_power_control_type_id, FREE_SMARTPHONE_DEVICE_TYPE_POWER_CONTROL, &free_smartphone_device_power_control_info);
	return kernel26_rf_kill_power_control_type_id;
}


/**
 * This function gets called on plugin initialization time.
 * @return the name of your plugin here
 * @note that it needs to be a name in the format <subsystem>.<plugin>
 * else your module will be unloaded immediately.
 **/
static void _g_object_unref0_ (gpointer var) {
	(var == NULL) ? NULL : (var = (g_object_unref (var), NULL));
}


gchar* fso_factory_function (FsoFrameworkSubsystem* system, GError** error) {
	gchar* result = NULL;
	GHashFunc _tmp0_;
	GEqualFunc _tmp1_;
	GHashTable* _tmp2_;
	FsoFrameworkSubsystem* _tmp3_;
	FsoFrameworkSmartKeyFile* _tmp4_;
	gchar* _tmp5_ = NULL;
	const gchar* _tmp6_;
	gchar* _tmp7_ = NULL;
	gchar* _tmp8_;
	gint _tmp9_ = 0;
	gint _tmp10_;
	gchar* _tmp23_;
	g_return_val_if_fail (system != NULL, NULL);
	_tmp0_ = g_direct_hash;
	_tmp1_ = g_direct_equal;
	_tmp2_ = g_hash_table_new_full (_tmp0_, _tmp1_, NULL, _g_object_unref0_);
	_g_hash_table_unref0 (instances);
	instances = _tmp2_;
	_tmp3_ = system;
	subsystem = _tmp3_;
	_tmp4_ = fso_framework_theConfig;
	_tmp5_ = fso_framework_smart_key_file_stringValue (_tmp4_, "cornucopia", "devfs_root", "/dev");
	_g_free0 (devfs_root);
	devfs_root = _tmp5_;
	_tmp6_ = devfs_root;
	_tmp7_ = g_build_filename (_tmp6_, "rfkill", NULL);
	_tmp8_ = _tmp7_;
	_tmp9_ = open (_tmp8_, O_RDWR, (mode_t) 0);
	fd = _tmp9_;
	_g_free0 (_tmp8_);
	_tmp10_ = fd;
	if (_tmp10_ == (-1)) {
		FsoFrameworkLogger* _tmp11_;
		const gchar* _tmp12_;
		const gchar* _tmp13_ = NULL;
		gint _tmp14_;
		const gchar* _tmp15_ = NULL;
		const gchar* _tmp16_ = NULL;
		gchar* _tmp17_ = NULL;
		gchar* _tmp18_;
		_tmp11_ = fso_framework_theLogger;
		_tmp12_ = devfs_root;
		_tmp13_ = string_to_string (_tmp12_);
		_tmp14_ = errno;
		_tmp15_ = g_strerror (_tmp14_);
		_tmp16_ = string_to_string (_tmp15_);
		_tmp17_ = g_strconcat ("Can't open ", _tmp13_, "/rfkill: ", _tmp16_, "; rfkill plugin will not be operating", NULL);
		_tmp18_ = _tmp17_;
		fso_framework_logger_error (_tmp11_, _tmp18_);
		_g_free0 (_tmp18_);
	} else {
		gint _tmp19_;
		GIOChannel* _tmp20_;
		GIOChannel* _tmp21_;
		guint _tmp22_ = 0U;
		_tmp19_ = fd;
		_tmp20_ = g_io_channel_unix_new (_tmp19_);
		_g_io_channel_unref0 (channel);
		channel = _tmp20_;
		_tmp21_ = channel;
		_tmp22_ = g_io_add_watch (_tmp21_, G_IO_IN | G_IO_HUP, _kernel26_rf_kill_power_control_onActionFromRfKill_gio_func, NULL);
		watch = _tmp22_;
	}
	_tmp23_ = g_strdup ("fsodevice.kernel26_rfkill");
	result = _tmp23_;
	return result;
}


void fso_register_function (GTypeModule* module) {
	FsoFrameworkLogger* _tmp0_;
	g_return_if_fail (module != NULL);
	kernel26_rf_kill_power_control_register_type (module);
	_tmp0_ = fso_framework_theLogger;
	fso_framework_logger_debug (_tmp0_, "fsodevice.kernel26_rfkill fso_register_function()");
}



