/* audiorouter.c generated by valac 0.16.0, the Vala compiler
 * generated from audiorouter.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <freesmartphone.h>
#include <fsobasics.h>


#define FSO_DEVICE_TYPE_AUDIO_ROUTER (fso_device_audio_router_get_type ())
#define FSO_DEVICE_AUDIO_ROUTER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_DEVICE_TYPE_AUDIO_ROUTER, FsoDeviceAudioRouter))
#define FSO_DEVICE_IS_AUDIO_ROUTER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_DEVICE_TYPE_AUDIO_ROUTER))
#define FSO_DEVICE_AUDIO_ROUTER_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), FSO_DEVICE_TYPE_AUDIO_ROUTER, FsoDeviceAudioRouterIface))

typedef struct _FsoDeviceAudioRouter FsoDeviceAudioRouter;
typedef struct _FsoDeviceAudioRouterIface FsoDeviceAudioRouterIface;

#define FSO_DEVICE_TYPE_NULL_ROUTER (fso_device_null_router_get_type ())
#define FSO_DEVICE_NULL_ROUTER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_DEVICE_TYPE_NULL_ROUTER, FsoDeviceNullRouter))
#define FSO_DEVICE_NULL_ROUTER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_DEVICE_TYPE_NULL_ROUTER, FsoDeviceNullRouterClass))
#define FSO_DEVICE_IS_NULL_ROUTER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_DEVICE_TYPE_NULL_ROUTER))
#define FSO_DEVICE_IS_NULL_ROUTER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_DEVICE_TYPE_NULL_ROUTER))
#define FSO_DEVICE_NULL_ROUTER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_DEVICE_TYPE_NULL_ROUTER, FsoDeviceNullRouterClass))

typedef struct _FsoDeviceNullRouter FsoDeviceNullRouter;
typedef struct _FsoDeviceNullRouterClass FsoDeviceNullRouterClass;
typedef struct _FsoDeviceNullRouterPrivate FsoDeviceNullRouterPrivate;

#define FSO_DEVICE_TYPE_BASE_AUDIO_ROUTER (fso_device_base_audio_router_get_type ())
#define FSO_DEVICE_BASE_AUDIO_ROUTER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_DEVICE_TYPE_BASE_AUDIO_ROUTER, FsoDeviceBaseAudioRouter))
#define FSO_DEVICE_BASE_AUDIO_ROUTER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_DEVICE_TYPE_BASE_AUDIO_ROUTER, FsoDeviceBaseAudioRouterClass))
#define FSO_DEVICE_IS_BASE_AUDIO_ROUTER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_DEVICE_TYPE_BASE_AUDIO_ROUTER))
#define FSO_DEVICE_IS_BASE_AUDIO_ROUTER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_DEVICE_TYPE_BASE_AUDIO_ROUTER))
#define FSO_DEVICE_BASE_AUDIO_ROUTER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_DEVICE_TYPE_BASE_AUDIO_ROUTER, FsoDeviceBaseAudioRouterClass))

typedef struct _FsoDeviceBaseAudioRouter FsoDeviceBaseAudioRouter;
typedef struct _FsoDeviceBaseAudioRouterClass FsoDeviceBaseAudioRouterClass;
typedef struct _FsoDeviceBaseAudioRouterPrivate FsoDeviceBaseAudioRouterPrivate;

struct _FsoDeviceAudioRouterIface {
	GTypeInterface parent_iface;
	gboolean (*isScenarioAvailable) (FsoDeviceAudioRouter* self, const gchar* scenario);
	gchar** (*availableScenarios) (FsoDeviceAudioRouter* self, int* result_length1);
	gchar* (*currentScenario) (FsoDeviceAudioRouter* self);
	gchar* (*pullScenario) (FsoDeviceAudioRouter* self, GError** error);
	void (*pushScenario) (FsoDeviceAudioRouter* self, const gchar* scenario);
	void (*setScenario) (FsoDeviceAudioRouter* self, const gchar* scenario);
	void (*saveScenario) (FsoDeviceAudioRouter* self, const gchar* scenario, GError** error);
	guint8 (*currentVolume) (FsoDeviceAudioRouter* self, GError** error);
	void (*setVolume) (FsoDeviceAudioRouter* self, guint8 volume, GError** error);
};

struct _FsoDeviceNullRouter {
	GObject parent_instance;
	FsoDeviceNullRouterPrivate * priv;
};

struct _FsoDeviceNullRouterClass {
	GObjectClass parent_class;
};

struct _FsoDeviceBaseAudioRouter {
	FsoFrameworkAbstractObject parent_instance;
	FsoDeviceBaseAudioRouterPrivate * priv;
};

struct _FsoDeviceBaseAudioRouterClass {
	FsoFrameworkAbstractObjectClass parent_class;
	gboolean (*isScenarioAvailable) (FsoDeviceBaseAudioRouter* self, const gchar* scenario);
	gchar** (*availableScenarios) (FsoDeviceBaseAudioRouter* self, int* result_length1);
	gchar* (*currentScenario) (FsoDeviceBaseAudioRouter* self);
	gchar* (*pullScenario) (FsoDeviceBaseAudioRouter* self, GError** error);
	void (*pushScenario) (FsoDeviceBaseAudioRouter* self, const gchar* scenario);
	void (*setScenario) (FsoDeviceBaseAudioRouter* self, const gchar* scenario);
	void (*saveScenario) (FsoDeviceBaseAudioRouter* self, const gchar* scenario, GError** error);
	guint8 (*currentVolume) (FsoDeviceBaseAudioRouter* self, GError** error);
	void (*setVolume) (FsoDeviceBaseAudioRouter* self, guint8 volume, GError** error);
};


static gpointer fso_device_null_router_parent_class = NULL;
static FsoDeviceAudioRouterIface* fso_device_null_router_fso_device_audio_router_parent_iface = NULL;
static gpointer fso_device_base_audio_router_parent_class = NULL;
static FsoDeviceAudioRouterIface* fso_device_base_audio_router_fso_device_audio_router_parent_iface = NULL;

GType fso_device_audio_router_get_type (void) G_GNUC_CONST;
gboolean fso_device_audio_router_isScenarioAvailable (FsoDeviceAudioRouter* self, const gchar* scenario);
gchar** fso_device_audio_router_availableScenarios (FsoDeviceAudioRouter* self, int* result_length1);
gchar* fso_device_audio_router_currentScenario (FsoDeviceAudioRouter* self);
gchar* fso_device_audio_router_pullScenario (FsoDeviceAudioRouter* self, GError** error);
void fso_device_audio_router_pushScenario (FsoDeviceAudioRouter* self, const gchar* scenario);
void fso_device_audio_router_setScenario (FsoDeviceAudioRouter* self, const gchar* scenario);
void fso_device_audio_router_saveScenario (FsoDeviceAudioRouter* self, const gchar* scenario, GError** error);
guint8 fso_device_audio_router_currentVolume (FsoDeviceAudioRouter* self, GError** error);
void fso_device_audio_router_setVolume (FsoDeviceAudioRouter* self, guint8 volume, GError** error);
GType fso_device_null_router_get_type (void) G_GNUC_CONST;
enum  {
	FSO_DEVICE_NULL_ROUTER_DUMMY_PROPERTY
};
static gboolean fso_device_null_router_real_isScenarioAvailable (FsoDeviceAudioRouter* base, const gchar* scenario);
static gchar** fso_device_null_router_real_availableScenarios (FsoDeviceAudioRouter* base, int* result_length1);
static gchar* fso_device_null_router_real_currentScenario (FsoDeviceAudioRouter* base);
static gchar* fso_device_null_router_real_pullScenario (FsoDeviceAudioRouter* base, GError** error);
static void fso_device_null_router_real_pushScenario (FsoDeviceAudioRouter* base, const gchar* scenario);
static void fso_device_null_router_real_setScenario (FsoDeviceAudioRouter* base, const gchar* scenario);
static void fso_device_null_router_real_saveScenario (FsoDeviceAudioRouter* base, const gchar* scenario, GError** error);
static guint8 fso_device_null_router_real_currentVolume (FsoDeviceAudioRouter* base, GError** error);
static void fso_device_null_router_real_setVolume (FsoDeviceAudioRouter* base, guint8 volume, GError** error);
FsoDeviceNullRouter* fso_device_null_router_new (void);
FsoDeviceNullRouter* fso_device_null_router_construct (GType object_type);
GType fso_device_base_audio_router_get_type (void) G_GNUC_CONST;
enum  {
	FSO_DEVICE_BASE_AUDIO_ROUTER_DUMMY_PROPERTY
};
gboolean fso_device_base_audio_router_isScenarioAvailable (FsoDeviceBaseAudioRouter* self, const gchar* scenario);
static gboolean fso_device_base_audio_router_real_isScenarioAvailable (FsoDeviceBaseAudioRouter* self, const gchar* scenario);
gchar** fso_device_base_audio_router_availableScenarios (FsoDeviceBaseAudioRouter* self, int* result_length1);
static gchar** fso_device_base_audio_router_real_availableScenarios (FsoDeviceBaseAudioRouter* self, int* result_length1);
gchar* fso_device_base_audio_router_currentScenario (FsoDeviceBaseAudioRouter* self);
static gchar* fso_device_base_audio_router_real_currentScenario (FsoDeviceBaseAudioRouter* self);
gchar* fso_device_base_audio_router_pullScenario (FsoDeviceBaseAudioRouter* self, GError** error);
static gchar* fso_device_base_audio_router_real_pullScenario (FsoDeviceBaseAudioRouter* self, GError** error);
void fso_device_base_audio_router_pushScenario (FsoDeviceBaseAudioRouter* self, const gchar* scenario);
static void fso_device_base_audio_router_real_pushScenario (FsoDeviceBaseAudioRouter* self, const gchar* scenario);
void fso_device_base_audio_router_setScenario (FsoDeviceBaseAudioRouter* self, const gchar* scenario);
static void fso_device_base_audio_router_real_setScenario (FsoDeviceBaseAudioRouter* self, const gchar* scenario);
void fso_device_base_audio_router_saveScenario (FsoDeviceBaseAudioRouter* self, const gchar* scenario, GError** error);
static void fso_device_base_audio_router_real_saveScenario (FsoDeviceBaseAudioRouter* self, const gchar* scenario, GError** error);
guint8 fso_device_base_audio_router_currentVolume (FsoDeviceBaseAudioRouter* self, GError** error);
static guint8 fso_device_base_audio_router_real_currentVolume (FsoDeviceBaseAudioRouter* self, GError** error);
void fso_device_base_audio_router_setVolume (FsoDeviceBaseAudioRouter* self, guint8 volume, GError** error);
static void fso_device_base_audio_router_real_setVolume (FsoDeviceBaseAudioRouter* self, guint8 volume, GError** error);
FsoDeviceBaseAudioRouter* fso_device_base_audio_router_construct (GType object_type);


gboolean fso_device_audio_router_isScenarioAvailable (FsoDeviceAudioRouter* self, const gchar* scenario) {
	g_return_val_if_fail (self != NULL, FALSE);
	return FSO_DEVICE_AUDIO_ROUTER_GET_INTERFACE (self)->isScenarioAvailable (self, scenario);
}


gchar** fso_device_audio_router_availableScenarios (FsoDeviceAudioRouter* self, int* result_length1) {
	g_return_val_if_fail (self != NULL, NULL);
	return FSO_DEVICE_AUDIO_ROUTER_GET_INTERFACE (self)->availableScenarios (self, result_length1);
}


gchar* fso_device_audio_router_currentScenario (FsoDeviceAudioRouter* self) {
	g_return_val_if_fail (self != NULL, NULL);
	return FSO_DEVICE_AUDIO_ROUTER_GET_INTERFACE (self)->currentScenario (self);
}


gchar* fso_device_audio_router_pullScenario (FsoDeviceAudioRouter* self, GError** error) {
	g_return_val_if_fail (self != NULL, NULL);
	return FSO_DEVICE_AUDIO_ROUTER_GET_INTERFACE (self)->pullScenario (self, error);
}


void fso_device_audio_router_pushScenario (FsoDeviceAudioRouter* self, const gchar* scenario) {
	g_return_if_fail (self != NULL);
	FSO_DEVICE_AUDIO_ROUTER_GET_INTERFACE (self)->pushScenario (self, scenario);
}


void fso_device_audio_router_setScenario (FsoDeviceAudioRouter* self, const gchar* scenario) {
	g_return_if_fail (self != NULL);
	FSO_DEVICE_AUDIO_ROUTER_GET_INTERFACE (self)->setScenario (self, scenario);
}


void fso_device_audio_router_saveScenario (FsoDeviceAudioRouter* self, const gchar* scenario, GError** error) {
	g_return_if_fail (self != NULL);
	FSO_DEVICE_AUDIO_ROUTER_GET_INTERFACE (self)->saveScenario (self, scenario, error);
}


guint8 fso_device_audio_router_currentVolume (FsoDeviceAudioRouter* self, GError** error) {
	g_return_val_if_fail (self != NULL, 0U);
	return FSO_DEVICE_AUDIO_ROUTER_GET_INTERFACE (self)->currentVolume (self, error);
}


void fso_device_audio_router_setVolume (FsoDeviceAudioRouter* self, guint8 volume, GError** error) {
	g_return_if_fail (self != NULL);
	FSO_DEVICE_AUDIO_ROUTER_GET_INTERFACE (self)->setVolume (self, volume, error);
}


static void fso_device_audio_router_base_init (FsoDeviceAudioRouterIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
	}
}


GType fso_device_audio_router_get_type (void) {
	static volatile gsize fso_device_audio_router_type_id__volatile = 0;
	if (g_once_init_enter (&fso_device_audio_router_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FsoDeviceAudioRouterIface), (GBaseInitFunc) fso_device_audio_router_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		GType fso_device_audio_router_type_id;
		fso_device_audio_router_type_id = g_type_register_static (G_TYPE_INTERFACE, "FsoDeviceAudioRouter", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (fso_device_audio_router_type_id, G_TYPE_OBJECT);
		g_once_init_leave (&fso_device_audio_router_type_id__volatile, fso_device_audio_router_type_id);
	}
	return fso_device_audio_router_type_id__volatile;
}


static gboolean fso_device_null_router_real_isScenarioAvailable (FsoDeviceAudioRouter* base, const gchar* scenario) {
	FsoDeviceNullRouter * self;
	gboolean result = FALSE;
	self = (FsoDeviceNullRouter*) base;
	g_return_val_if_fail (scenario != NULL, FALSE);
	result = FALSE;
	return result;
}


static gchar** fso_device_null_router_real_availableScenarios (FsoDeviceAudioRouter* base, int* result_length1) {
	FsoDeviceNullRouter * self;
	gchar** result = NULL;
	gchar** _tmp0_ = NULL;
	gchar** _tmp1_;
	gint _tmp1__length1;
	self = (FsoDeviceNullRouter*) base;
	_tmp0_ = g_new0 (gchar*, 0 + 1);
	_tmp1_ = _tmp0_;
	_tmp1__length1 = 0;
	if (result_length1) {
		*result_length1 = _tmp1__length1;
	}
	result = _tmp1_;
	return result;
}


static gchar* fso_device_null_router_real_currentScenario (FsoDeviceAudioRouter* base) {
	FsoDeviceNullRouter * self;
	gchar* result = NULL;
	gchar* _tmp0_;
	self = (FsoDeviceNullRouter*) base;
	_tmp0_ = g_strdup ("");
	result = _tmp0_;
	return result;
}


static gchar* fso_device_null_router_real_pullScenario (FsoDeviceAudioRouter* base, GError** error) {
	FsoDeviceNullRouter * self;
	gchar* result = NULL;
	gchar* _tmp0_;
	self = (FsoDeviceNullRouter*) base;
	_tmp0_ = g_strdup ("");
	result = _tmp0_;
	return result;
}


static void fso_device_null_router_real_pushScenario (FsoDeviceAudioRouter* base, const gchar* scenario) {
	FsoDeviceNullRouter * self;
	self = (FsoDeviceNullRouter*) base;
	g_return_if_fail (scenario != NULL);
}


static void fso_device_null_router_real_setScenario (FsoDeviceAudioRouter* base, const gchar* scenario) {
	FsoDeviceNullRouter * self;
	self = (FsoDeviceNullRouter*) base;
	g_return_if_fail (scenario != NULL);
}


static void fso_device_null_router_real_saveScenario (FsoDeviceAudioRouter* base, const gchar* scenario, GError** error) {
	FsoDeviceNullRouter * self;
	self = (FsoDeviceNullRouter*) base;
	g_return_if_fail (scenario != NULL);
}


static guint8 fso_device_null_router_real_currentVolume (FsoDeviceAudioRouter* base, GError** error) {
	FsoDeviceNullRouter * self;
	guint8 result = 0U;
	self = (FsoDeviceNullRouter*) base;
	result = (guint8) 0;
	return result;
}


static void fso_device_null_router_real_setVolume (FsoDeviceAudioRouter* base, guint8 volume, GError** error) {
	FsoDeviceNullRouter * self;
	self = (FsoDeviceNullRouter*) base;
}


FsoDeviceNullRouter* fso_device_null_router_construct (GType object_type) {
	FsoDeviceNullRouter * self = NULL;
	self = (FsoDeviceNullRouter*) g_object_new (object_type, NULL);
	return self;
}


FsoDeviceNullRouter* fso_device_null_router_new (void) {
	return fso_device_null_router_construct (FSO_DEVICE_TYPE_NULL_ROUTER);
}


static void fso_device_null_router_class_init (FsoDeviceNullRouterClass * klass) {
	fso_device_null_router_parent_class = g_type_class_peek_parent (klass);
}


static void fso_device_null_router_fso_device_audio_router_interface_init (FsoDeviceAudioRouterIface * iface) {
	fso_device_null_router_fso_device_audio_router_parent_iface = g_type_interface_peek_parent (iface);
	iface->isScenarioAvailable = (gboolean (*)(FsoDeviceAudioRouter*, const gchar*)) fso_device_null_router_real_isScenarioAvailable;
	iface->availableScenarios = (gchar** (*)(FsoDeviceAudioRouter*, int*)) fso_device_null_router_real_availableScenarios;
	iface->currentScenario = (gchar* (*)(FsoDeviceAudioRouter*)) fso_device_null_router_real_currentScenario;
	iface->pullScenario = (gchar* (*)(FsoDeviceAudioRouter*, GError**)) fso_device_null_router_real_pullScenario;
	iface->pushScenario = (void (*)(FsoDeviceAudioRouter*, const gchar*)) fso_device_null_router_real_pushScenario;
	iface->setScenario = (void (*)(FsoDeviceAudioRouter*, const gchar*)) fso_device_null_router_real_setScenario;
	iface->saveScenario = (void (*)(FsoDeviceAudioRouter*, const gchar*, GError**)) fso_device_null_router_real_saveScenario;
	iface->currentVolume = (guint8 (*)(FsoDeviceAudioRouter*, GError**)) fso_device_null_router_real_currentVolume;
	iface->setVolume = (void (*)(FsoDeviceAudioRouter*, guint8, GError**)) fso_device_null_router_real_setVolume;
}


static void fso_device_null_router_instance_init (FsoDeviceNullRouter * self) {
}


GType fso_device_null_router_get_type (void) {
	static volatile gsize fso_device_null_router_type_id__volatile = 0;
	if (g_once_init_enter (&fso_device_null_router_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FsoDeviceNullRouterClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_device_null_router_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoDeviceNullRouter), 0, (GInstanceInitFunc) fso_device_null_router_instance_init, NULL };
		static const GInterfaceInfo fso_device_audio_router_info = { (GInterfaceInitFunc) fso_device_null_router_fso_device_audio_router_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		GType fso_device_null_router_type_id;
		fso_device_null_router_type_id = g_type_register_static (G_TYPE_OBJECT, "FsoDeviceNullRouter", &g_define_type_info, 0);
		g_type_add_interface_static (fso_device_null_router_type_id, FSO_DEVICE_TYPE_AUDIO_ROUTER, &fso_device_audio_router_info);
		g_once_init_leave (&fso_device_null_router_type_id__volatile, fso_device_null_router_type_id);
	}
	return fso_device_null_router_type_id__volatile;
}


static gboolean fso_device_base_audio_router_real_isScenarioAvailable (FsoDeviceBaseAudioRouter* self, const gchar* scenario) {
	g_critical ("Type `%s' does not implement abstract method `fso_device_base_audio_router_isScenarioAvailable'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return FALSE;
}


gboolean fso_device_base_audio_router_isScenarioAvailable (FsoDeviceBaseAudioRouter* self, const gchar* scenario) {
	g_return_val_if_fail (self != NULL, FALSE);
	return FSO_DEVICE_BASE_AUDIO_ROUTER_GET_CLASS (self)->isScenarioAvailable (self, scenario);
}


static gchar** fso_device_base_audio_router_real_availableScenarios (FsoDeviceBaseAudioRouter* self, int* result_length1) {
	g_critical ("Type `%s' does not implement abstract method `fso_device_base_audio_router_availableScenarios'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}


gchar** fso_device_base_audio_router_availableScenarios (FsoDeviceBaseAudioRouter* self, int* result_length1) {
	g_return_val_if_fail (self != NULL, NULL);
	return FSO_DEVICE_BASE_AUDIO_ROUTER_GET_CLASS (self)->availableScenarios (self, result_length1);
}


static gchar* fso_device_base_audio_router_real_currentScenario (FsoDeviceBaseAudioRouter* self) {
	g_critical ("Type `%s' does not implement abstract method `fso_device_base_audio_router_currentScenario'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}


gchar* fso_device_base_audio_router_currentScenario (FsoDeviceBaseAudioRouter* self) {
	g_return_val_if_fail (self != NULL, NULL);
	return FSO_DEVICE_BASE_AUDIO_ROUTER_GET_CLASS (self)->currentScenario (self);
}


static gchar* fso_device_base_audio_router_real_pullScenario (FsoDeviceBaseAudioRouter* self, GError** error) {
	g_critical ("Type `%s' does not implement abstract method `fso_device_base_audio_router_pullScenario'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}


gchar* fso_device_base_audio_router_pullScenario (FsoDeviceBaseAudioRouter* self, GError** error) {
	g_return_val_if_fail (self != NULL, NULL);
	return FSO_DEVICE_BASE_AUDIO_ROUTER_GET_CLASS (self)->pullScenario (self, error);
}


static void fso_device_base_audio_router_real_pushScenario (FsoDeviceBaseAudioRouter* self, const gchar* scenario) {
	g_critical ("Type `%s' does not implement abstract method `fso_device_base_audio_router_pushScenario'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return;
}


void fso_device_base_audio_router_pushScenario (FsoDeviceBaseAudioRouter* self, const gchar* scenario) {
	g_return_if_fail (self != NULL);
	FSO_DEVICE_BASE_AUDIO_ROUTER_GET_CLASS (self)->pushScenario (self, scenario);
}


static void fso_device_base_audio_router_real_setScenario (FsoDeviceBaseAudioRouter* self, const gchar* scenario) {
	g_critical ("Type `%s' does not implement abstract method `fso_device_base_audio_router_setScenario'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return;
}


void fso_device_base_audio_router_setScenario (FsoDeviceBaseAudioRouter* self, const gchar* scenario) {
	g_return_if_fail (self != NULL);
	FSO_DEVICE_BASE_AUDIO_ROUTER_GET_CLASS (self)->setScenario (self, scenario);
}


static void fso_device_base_audio_router_real_saveScenario (FsoDeviceBaseAudioRouter* self, const gchar* scenario, GError** error) {
	g_critical ("Type `%s' does not implement abstract method `fso_device_base_audio_router_saveScenario'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return;
}


void fso_device_base_audio_router_saveScenario (FsoDeviceBaseAudioRouter* self, const gchar* scenario, GError** error) {
	g_return_if_fail (self != NULL);
	FSO_DEVICE_BASE_AUDIO_ROUTER_GET_CLASS (self)->saveScenario (self, scenario, error);
}


static guint8 fso_device_base_audio_router_real_currentVolume (FsoDeviceBaseAudioRouter* self, GError** error) {
	guint8 result = 0U;
	GError* _tmp0_;
	GError * _inner_error_ = NULL;
	_tmp0_ = g_error_new_literal (FREE_SMARTPHONE_ERROR, FREE_SMARTPHONE_ERROR_UNSUPPORTED, "Not Implemented");
	_inner_error_ = _tmp0_;
	if (_inner_error_->domain == FREE_SMARTPHONE_ERROR) {
		g_propagate_error (error, _inner_error_);
		return 0U;
	} else {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return 0U;
	}
	return result;
}


guint8 fso_device_base_audio_router_currentVolume (FsoDeviceBaseAudioRouter* self, GError** error) {
	g_return_val_if_fail (self != NULL, 0U);
	return FSO_DEVICE_BASE_AUDIO_ROUTER_GET_CLASS (self)->currentVolume (self, error);
}


static void fso_device_base_audio_router_real_setVolume (FsoDeviceBaseAudioRouter* self, guint8 volume, GError** error) {
	GError* _tmp0_;
	GError * _inner_error_ = NULL;
	_tmp0_ = g_error_new_literal (FREE_SMARTPHONE_ERROR, FREE_SMARTPHONE_ERROR_UNSUPPORTED, "Not Implemented");
	_inner_error_ = _tmp0_;
	if (_inner_error_->domain == FREE_SMARTPHONE_ERROR) {
		g_propagate_error (error, _inner_error_);
		return;
	} else {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}


void fso_device_base_audio_router_setVolume (FsoDeviceBaseAudioRouter* self, guint8 volume, GError** error) {
	g_return_if_fail (self != NULL);
	FSO_DEVICE_BASE_AUDIO_ROUTER_GET_CLASS (self)->setVolume (self, volume, error);
}


FsoDeviceBaseAudioRouter* fso_device_base_audio_router_construct (GType object_type) {
	FsoDeviceBaseAudioRouter * self = NULL;
	self = (FsoDeviceBaseAudioRouter*) fso_framework_abstract_object_construct (object_type);
	return self;
}


static void fso_device_base_audio_router_class_init (FsoDeviceBaseAudioRouterClass * klass) {
	fso_device_base_audio_router_parent_class = g_type_class_peek_parent (klass);
	FSO_DEVICE_BASE_AUDIO_ROUTER_CLASS (klass)->isScenarioAvailable = fso_device_base_audio_router_real_isScenarioAvailable;
	FSO_DEVICE_BASE_AUDIO_ROUTER_CLASS (klass)->availableScenarios = fso_device_base_audio_router_real_availableScenarios;
	FSO_DEVICE_BASE_AUDIO_ROUTER_CLASS (klass)->currentScenario = fso_device_base_audio_router_real_currentScenario;
	FSO_DEVICE_BASE_AUDIO_ROUTER_CLASS (klass)->pullScenario = fso_device_base_audio_router_real_pullScenario;
	FSO_DEVICE_BASE_AUDIO_ROUTER_CLASS (klass)->pushScenario = fso_device_base_audio_router_real_pushScenario;
	FSO_DEVICE_BASE_AUDIO_ROUTER_CLASS (klass)->setScenario = fso_device_base_audio_router_real_setScenario;
	FSO_DEVICE_BASE_AUDIO_ROUTER_CLASS (klass)->saveScenario = fso_device_base_audio_router_real_saveScenario;
	FSO_DEVICE_BASE_AUDIO_ROUTER_CLASS (klass)->currentVolume = fso_device_base_audio_router_real_currentVolume;
	FSO_DEVICE_BASE_AUDIO_ROUTER_CLASS (klass)->setVolume = fso_device_base_audio_router_real_setVolume;
}


static void fso_device_base_audio_router_fso_device_audio_router_interface_init (FsoDeviceAudioRouterIface * iface) {
	fso_device_base_audio_router_fso_device_audio_router_parent_iface = g_type_interface_peek_parent (iface);
	iface->isScenarioAvailable = (gboolean (*)(FsoDeviceAudioRouter*, const gchar*)) fso_device_base_audio_router_isScenarioAvailable;
	iface->availableScenarios = (gchar** (*)(FsoDeviceAudioRouter*, int*)) fso_device_base_audio_router_availableScenarios;
	iface->currentScenario = (gchar* (*)(FsoDeviceAudioRouter*)) fso_device_base_audio_router_currentScenario;
	iface->pullScenario = (gchar* (*)(FsoDeviceAudioRouter*, GError**)) fso_device_base_audio_router_pullScenario;
	iface->pushScenario = (void (*)(FsoDeviceAudioRouter*, const gchar*)) fso_device_base_audio_router_pushScenario;
	iface->setScenario = (void (*)(FsoDeviceAudioRouter*, const gchar*)) fso_device_base_audio_router_setScenario;
	iface->saveScenario = (void (*)(FsoDeviceAudioRouter*, const gchar*, GError**)) fso_device_base_audio_router_saveScenario;
	iface->currentVolume = (guint8 (*)(FsoDeviceAudioRouter*, GError**)) fso_device_base_audio_router_currentVolume;
	iface->setVolume = (void (*)(FsoDeviceAudioRouter*, guint8, GError**)) fso_device_base_audio_router_setVolume;
}


static void fso_device_base_audio_router_instance_init (FsoDeviceBaseAudioRouter * self) {
}


GType fso_device_base_audio_router_get_type (void) {
	static volatile gsize fso_device_base_audio_router_type_id__volatile = 0;
	if (g_once_init_enter (&fso_device_base_audio_router_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FsoDeviceBaseAudioRouterClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_device_base_audio_router_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoDeviceBaseAudioRouter), 0, (GInstanceInitFunc) fso_device_base_audio_router_instance_init, NULL };
		static const GInterfaceInfo fso_device_audio_router_info = { (GInterfaceInitFunc) fso_device_base_audio_router_fso_device_audio_router_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		GType fso_device_base_audio_router_type_id;
		fso_device_base_audio_router_type_id = g_type_register_static (FSO_FRAMEWORK_TYPE_ABSTRACT_OBJECT, "FsoDeviceBaseAudioRouter", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
		g_type_add_interface_static (fso_device_base_audio_router_type_id, FSO_DEVICE_TYPE_AUDIO_ROUTER, &fso_device_audio_router_info);
		g_once_init_leave (&fso_device_base_audio_router_type_id__volatile, fso_device_base_audio_router_type_id);
	}
	return fso_device_base_audio_router_type_id__volatile;
}



