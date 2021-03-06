/* audioplayer.c generated by valac 0.16.1, the Vala compiler
 * generated from audioplayer.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>
#include <freesmartphone.h>
#include <gee.h>
#include <gobject/gvaluecollector.h>


#define FSO_DEVICE_TYPE_AUDIO_PLAYER (fso_device_audio_player_get_type ())
#define FSO_DEVICE_AUDIO_PLAYER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_DEVICE_TYPE_AUDIO_PLAYER, FsoDeviceAudioPlayer))
#define FSO_DEVICE_IS_AUDIO_PLAYER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_DEVICE_TYPE_AUDIO_PLAYER))
#define FSO_DEVICE_AUDIO_PLAYER_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), FSO_DEVICE_TYPE_AUDIO_PLAYER, FsoDeviceAudioPlayerIface))

typedef struct _FsoDeviceAudioPlayer FsoDeviceAudioPlayer;
typedef struct _FsoDeviceAudioPlayerIface FsoDeviceAudioPlayerIface;

#define FSO_DEVICE_TYPE_NULL_PLAYER (fso_device_null_player_get_type ())
#define FSO_DEVICE_NULL_PLAYER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_DEVICE_TYPE_NULL_PLAYER, FsoDeviceNullPlayer))
#define FSO_DEVICE_NULL_PLAYER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_DEVICE_TYPE_NULL_PLAYER, FsoDeviceNullPlayerClass))
#define FSO_DEVICE_IS_NULL_PLAYER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_DEVICE_TYPE_NULL_PLAYER))
#define FSO_DEVICE_IS_NULL_PLAYER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_DEVICE_TYPE_NULL_PLAYER))
#define FSO_DEVICE_NULL_PLAYER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_DEVICE_TYPE_NULL_PLAYER, FsoDeviceNullPlayerClass))

typedef struct _FsoDeviceNullPlayer FsoDeviceNullPlayer;
typedef struct _FsoDeviceNullPlayerClass FsoDeviceNullPlayerClass;
typedef struct _FsoDeviceNullPlayerPrivate FsoDeviceNullPlayerPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _FsoDeviceNullPlayerPlaySoundData FsoDeviceNullPlayerPlaySoundData;
typedef struct _FsoDeviceNullPlayerStopSoundData FsoDeviceNullPlayerStopSoundData;
typedef struct _FsoDeviceNullPlayerStopAllSoundsData FsoDeviceNullPlayerStopAllSoundsData;

#define FSO_DEVICE_TYPE_PLAYING_SOUND (fso_device_playing_sound_get_type ())
#define FSO_DEVICE_PLAYING_SOUND(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_DEVICE_TYPE_PLAYING_SOUND, FsoDevicePlayingSound))
#define FSO_DEVICE_PLAYING_SOUND_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_DEVICE_TYPE_PLAYING_SOUND, FsoDevicePlayingSoundClass))
#define FSO_DEVICE_IS_PLAYING_SOUND(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_DEVICE_TYPE_PLAYING_SOUND))
#define FSO_DEVICE_IS_PLAYING_SOUND_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_DEVICE_TYPE_PLAYING_SOUND))
#define FSO_DEVICE_PLAYING_SOUND_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_DEVICE_TYPE_PLAYING_SOUND, FsoDevicePlayingSoundClass))

typedef struct _FsoDevicePlayingSound FsoDevicePlayingSound;
typedef struct _FsoDevicePlayingSoundClass FsoDevicePlayingSoundClass;
typedef struct _FsoDevicePlayingSoundPrivate FsoDevicePlayingSoundPrivate;
typedef struct _FsoDeviceParamSpecPlayingSound FsoDeviceParamSpecPlayingSound;

#define FSO_DEVICE_TYPE_BASE_AUDIO_PLAYER (fso_device_base_audio_player_get_type ())
#define FSO_DEVICE_BASE_AUDIO_PLAYER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_DEVICE_TYPE_BASE_AUDIO_PLAYER, FsoDeviceBaseAudioPlayer))
#define FSO_DEVICE_BASE_AUDIO_PLAYER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_DEVICE_TYPE_BASE_AUDIO_PLAYER, FsoDeviceBaseAudioPlayerClass))
#define FSO_DEVICE_IS_BASE_AUDIO_PLAYER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_DEVICE_TYPE_BASE_AUDIO_PLAYER))
#define FSO_DEVICE_IS_BASE_AUDIO_PLAYER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_DEVICE_TYPE_BASE_AUDIO_PLAYER))
#define FSO_DEVICE_BASE_AUDIO_PLAYER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_DEVICE_TYPE_BASE_AUDIO_PLAYER, FsoDeviceBaseAudioPlayerClass))

typedef struct _FsoDeviceBaseAudioPlayer FsoDeviceBaseAudioPlayer;
typedef struct _FsoDeviceBaseAudioPlayerClass FsoDeviceBaseAudioPlayerClass;
typedef struct _FsoDeviceBaseAudioPlayerPrivate FsoDeviceBaseAudioPlayerPrivate;

struct _FsoDeviceAudioPlayerIface {
	GTypeInterface parent_iface;
	gchar** (*supportedFormats) (FsoDeviceAudioPlayer* self, int* result_length1);
	void (*play_sound) (FsoDeviceAudioPlayer* self, const gchar* name, gint loop, gint length, GAsyncReadyCallback _callback_, gpointer _user_data_);
	void (*play_sound_finish) (FsoDeviceAudioPlayer* self, GAsyncResult* _res_, GError** error);
	void (*stop_sound) (FsoDeviceAudioPlayer* self, const gchar* name, GAsyncReadyCallback _callback_, gpointer _user_data_);
	void (*stop_sound_finish) (FsoDeviceAudioPlayer* self, GAsyncResult* _res_, GError** error);
	void (*stop_all_sounds) (FsoDeviceAudioPlayer* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
	void (*stop_all_sounds_finish) (FsoDeviceAudioPlayer* self, GAsyncResult* _res_);
};

struct _FsoDeviceNullPlayer {
	GObject parent_instance;
	FsoDeviceNullPlayerPrivate * priv;
};

struct _FsoDeviceNullPlayerClass {
	GObjectClass parent_class;
};

struct _FsoDeviceNullPlayerPlaySoundData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	FsoDeviceNullPlayer* self;
	gchar* name;
	gint loop;
	gint length;
};

struct _FsoDeviceNullPlayerStopSoundData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	FsoDeviceNullPlayer* self;
	gchar* name;
};

struct _FsoDeviceNullPlayerStopAllSoundsData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	FsoDeviceNullPlayer* self;
};

struct _FsoDevicePlayingSound {
	GTypeInstance parent_instance;
	volatile int ref_count;
	FsoDevicePlayingSoundPrivate * priv;
	gchar* name;
	gint loop;
	gint length;
	gboolean finished;
	guint32 data;
	guint watch;
};

struct _FsoDevicePlayingSoundClass {
	GTypeClass parent_class;
	void (*finalize) (FsoDevicePlayingSound *self);
};

struct _FsoDeviceParamSpecPlayingSound {
	GParamSpec parent_instance;
};

struct _FsoDeviceBaseAudioPlayer {
	GObject parent_instance;
	FsoDeviceBaseAudioPlayerPrivate * priv;
	GeeHashMap* sounds;
};

struct _FsoDeviceBaseAudioPlayerClass {
	GObjectClass parent_class;
	gchar** (*supportedFormats) (FsoDeviceBaseAudioPlayer* self, int* result_length1);
	void (*play_sound) (FsoDeviceBaseAudioPlayer* self, const gchar* name, gint loop, gint length, GAsyncReadyCallback _callback_, gpointer _user_data_);
	void (*play_sound_finish) (FsoDeviceBaseAudioPlayer* self, GAsyncResult* _res_, GError** error);
	void (*stop_sound) (FsoDeviceBaseAudioPlayer* self, const gchar* name, GAsyncReadyCallback _callback_, gpointer _user_data_);
	void (*stop_sound_finish) (FsoDeviceBaseAudioPlayer* self, GAsyncResult* _res_, GError** error);
	void (*stop_all_sounds) (FsoDeviceBaseAudioPlayer* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
	void (*stop_all_sounds_finish) (FsoDeviceBaseAudioPlayer* self, GAsyncResult* _res_);
};


static gpointer fso_device_null_player_parent_class = NULL;
static FsoDeviceAudioPlayerIface* fso_device_null_player_fso_device_audio_player_parent_iface = NULL;
static gpointer fso_device_playing_sound_parent_class = NULL;
static gpointer fso_device_base_audio_player_parent_class = NULL;
static FsoDeviceAudioPlayerIface* fso_device_base_audio_player_fso_device_audio_player_parent_iface = NULL;

GType fso_device_audio_player_get_type (void) G_GNUC_CONST;
gchar** fso_device_audio_player_supportedFormats (FsoDeviceAudioPlayer* self, int* result_length1);
void fso_device_audio_player_play_sound (FsoDeviceAudioPlayer* self, const gchar* name, gint loop, gint length, GAsyncReadyCallback _callback_, gpointer _user_data_);
void fso_device_audio_player_play_sound_finish (FsoDeviceAudioPlayer* self, GAsyncResult* _res_, GError** error);
void fso_device_audio_player_stop_sound (FsoDeviceAudioPlayer* self, const gchar* name, GAsyncReadyCallback _callback_, gpointer _user_data_);
void fso_device_audio_player_stop_sound_finish (FsoDeviceAudioPlayer* self, GAsyncResult* _res_, GError** error);
void fso_device_audio_player_stop_all_sounds (FsoDeviceAudioPlayer* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
void fso_device_audio_player_stop_all_sounds_finish (FsoDeviceAudioPlayer* self, GAsyncResult* _res_);
GType fso_device_null_player_get_type (void) G_GNUC_CONST;
enum  {
	FSO_DEVICE_NULL_PLAYER_DUMMY_PROPERTY
};
static gchar** fso_device_null_player_real_supportedFormats (FsoDeviceAudioPlayer* base, int* result_length1);
static void fso_device_null_player_real_play_sound_data_free (gpointer _data);
static void fso_device_null_player_real_play_sound (FsoDeviceAudioPlayer* base, const gchar* name, gint loop, gint length, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean fso_device_null_player_real_play_sound_co (FsoDeviceNullPlayerPlaySoundData* _data_);
static void fso_device_null_player_real_stop_sound_data_free (gpointer _data);
static void fso_device_null_player_real_stop_sound (FsoDeviceAudioPlayer* base, const gchar* name, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean fso_device_null_player_real_stop_sound_co (FsoDeviceNullPlayerStopSoundData* _data_);
static void fso_device_null_player_real_stop_all_sounds_data_free (gpointer _data);
static void fso_device_null_player_real_stop_all_sounds (FsoDeviceAudioPlayer* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean fso_device_null_player_real_stop_all_sounds_co (FsoDeviceNullPlayerStopAllSoundsData* _data_);
FsoDeviceNullPlayer* fso_device_null_player_new (void);
FsoDeviceNullPlayer* fso_device_null_player_construct (GType object_type);
gpointer fso_device_playing_sound_ref (gpointer instance);
void fso_device_playing_sound_unref (gpointer instance);
GParamSpec* fso_device_param_spec_playing_sound (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void fso_device_value_set_playing_sound (GValue* value, gpointer v_object);
void fso_device_value_take_playing_sound (GValue* value, gpointer v_object);
gpointer fso_device_value_get_playing_sound (const GValue* value);
GType fso_device_playing_sound_get_type (void) G_GNUC_CONST;
enum  {
	FSO_DEVICE_PLAYING_SOUND_DUMMY_PROPERTY
};
FsoDevicePlayingSound* fso_device_playing_sound_new (const gchar* name, gint loop, gint length, guint32 data);
FsoDevicePlayingSound* fso_device_playing_sound_construct (GType object_type, const gchar* name, gint loop, gint length, guint32 data);
gboolean fso_device_playing_sound_onTimeout (FsoDevicePlayingSound* self);
static gboolean _fso_device_playing_sound_onTimeout_gsource_func (gpointer self);
static void fso_device_playing_sound_finalize (FsoDevicePlayingSound* obj);
GType fso_device_base_audio_player_get_type (void) G_GNUC_CONST;
enum  {
	FSO_DEVICE_BASE_AUDIO_PLAYER_DUMMY_PROPERTY
};
gchar** fso_device_base_audio_player_supportedFormats (FsoDeviceBaseAudioPlayer* self, int* result_length1);
static gchar** fso_device_base_audio_player_real_supportedFormats (FsoDeviceBaseAudioPlayer* self, int* result_length1);
void fso_device_base_audio_player_play_sound (FsoDeviceBaseAudioPlayer* self, const gchar* name, gint loop, gint length, GAsyncReadyCallback _callback_, gpointer _user_data_);
void fso_device_base_audio_player_play_sound_finish (FsoDeviceBaseAudioPlayer* self, GAsyncResult* _res_, GError** error);
void fso_device_base_audio_player_stop_sound (FsoDeviceBaseAudioPlayer* self, const gchar* name, GAsyncReadyCallback _callback_, gpointer _user_data_);
void fso_device_base_audio_player_stop_sound_finish (FsoDeviceBaseAudioPlayer* self, GAsyncResult* _res_, GError** error);
void fso_device_base_audio_player_stop_all_sounds (FsoDeviceBaseAudioPlayer* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
void fso_device_base_audio_player_stop_all_sounds_finish (FsoDeviceBaseAudioPlayer* self, GAsyncResult* _res_);
FsoDeviceBaseAudioPlayer* fso_device_base_audio_player_construct (GType object_type);
static GObject * fso_device_base_audio_player_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void fso_device_base_audio_player_finalize (GObject* obj);


gchar** fso_device_audio_player_supportedFormats (FsoDeviceAudioPlayer* self, int* result_length1) {
	g_return_val_if_fail (self != NULL, NULL);
	return FSO_DEVICE_AUDIO_PLAYER_GET_INTERFACE (self)->supportedFormats (self, result_length1);
}


void fso_device_audio_player_play_sound (FsoDeviceAudioPlayer* self, const gchar* name, gint loop, gint length, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	FSO_DEVICE_AUDIO_PLAYER_GET_INTERFACE (self)->play_sound (self, name, loop, length, _callback_, _user_data_);
}


void fso_device_audio_player_play_sound_finish (FsoDeviceAudioPlayer* self, GAsyncResult* _res_, GError** error) {
	FSO_DEVICE_AUDIO_PLAYER_GET_INTERFACE (self)->play_sound_finish (self, _res_, error);
}


void fso_device_audio_player_stop_sound (FsoDeviceAudioPlayer* self, const gchar* name, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	FSO_DEVICE_AUDIO_PLAYER_GET_INTERFACE (self)->stop_sound (self, name, _callback_, _user_data_);
}


void fso_device_audio_player_stop_sound_finish (FsoDeviceAudioPlayer* self, GAsyncResult* _res_, GError** error) {
	FSO_DEVICE_AUDIO_PLAYER_GET_INTERFACE (self)->stop_sound_finish (self, _res_, error);
}


void fso_device_audio_player_stop_all_sounds (FsoDeviceAudioPlayer* self, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	FSO_DEVICE_AUDIO_PLAYER_GET_INTERFACE (self)->stop_all_sounds (self, _callback_, _user_data_);
}


void fso_device_audio_player_stop_all_sounds_finish (FsoDeviceAudioPlayer* self, GAsyncResult* _res_) {
	FSO_DEVICE_AUDIO_PLAYER_GET_INTERFACE (self)->stop_all_sounds_finish (self, _res_);
}


static void fso_device_audio_player_base_init (FsoDeviceAudioPlayerIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
	}
}


GType fso_device_audio_player_get_type (void) {
	static volatile gsize fso_device_audio_player_type_id__volatile = 0;
	if (g_once_init_enter (&fso_device_audio_player_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FsoDeviceAudioPlayerIface), (GBaseInitFunc) fso_device_audio_player_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		GType fso_device_audio_player_type_id;
		fso_device_audio_player_type_id = g_type_register_static (G_TYPE_INTERFACE, "FsoDeviceAudioPlayer", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (fso_device_audio_player_type_id, G_TYPE_OBJECT);
		g_once_init_leave (&fso_device_audio_player_type_id__volatile, fso_device_audio_player_type_id);
	}
	return fso_device_audio_player_type_id__volatile;
}


static gchar** fso_device_null_player_real_supportedFormats (FsoDeviceAudioPlayer* base, int* result_length1) {
	FsoDeviceNullPlayer * self;
	gchar** result = NULL;
	gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* _tmp2_;
	gchar* _tmp3_;
	gchar* _tmp4_;
	gchar* _tmp5_;
	gchar** _tmp6_ = NULL;
	gchar** _tmp7_;
	gint _tmp7__length1;
	self = (FsoDeviceNullPlayer*) base;
	_tmp0_ = g_strdup ("caf");
	_tmp1_ = g_strdup ("mod");
	_tmp2_ = g_strdup ("mp3");
	_tmp3_ = g_strdup ("wav");
	_tmp4_ = g_strdup ("ogg");
	_tmp5_ = g_strdup ("sid");
	_tmp6_ = g_new0 (gchar*, 6 + 1);
	_tmp6_[0] = _tmp0_;
	_tmp6_[1] = _tmp1_;
	_tmp6_[2] = _tmp2_;
	_tmp6_[3] = _tmp3_;
	_tmp6_[4] = _tmp4_;
	_tmp6_[5] = _tmp5_;
	_tmp7_ = _tmp6_;
	_tmp7__length1 = 6;
	if (result_length1) {
		*result_length1 = _tmp7__length1;
	}
	result = _tmp7_;
	return result;
}


static void fso_device_null_player_real_play_sound_data_free (gpointer _data) {
	FsoDeviceNullPlayerPlaySoundData* _data_;
	_data_ = _data;
	_g_free0 (_data_->name);
	_g_object_unref0 (_data_->self);
	g_slice_free (FsoDeviceNullPlayerPlaySoundData, _data_);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void fso_device_null_player_real_play_sound (FsoDeviceAudioPlayer* base, const gchar* name, gint loop, gint length, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	FsoDeviceNullPlayer * self;
	FsoDeviceNullPlayerPlaySoundData* _data_;
	FsoDeviceNullPlayer* _tmp0_;
	const gchar* _tmp1_;
	gchar* _tmp2_;
	gint _tmp3_;
	gint _tmp4_;
	self = (FsoDeviceNullPlayer*) base;
	_data_ = g_slice_new0 (FsoDeviceNullPlayerPlaySoundData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, fso_device_null_player_real_play_sound);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, fso_device_null_player_real_play_sound_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	_tmp1_ = name;
	_tmp2_ = g_strdup (_tmp1_);
	_data_->name = _tmp2_;
	_tmp3_ = loop;
	_data_->loop = _tmp3_;
	_tmp4_ = length;
	_data_->length = _tmp4_;
	fso_device_null_player_real_play_sound_co (_data_);
}


static void fso_device_null_player_real_play_sound_finish (FsoDeviceAudioPlayer* base, GAsyncResult* _res_, GError** error) {
	FsoDeviceNullPlayerPlaySoundData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static gboolean fso_device_null_player_real_play_sound_co (FsoDeviceNullPlayerPlaySoundData* _data_) {
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


static void fso_device_null_player_real_stop_sound_data_free (gpointer _data) {
	FsoDeviceNullPlayerStopSoundData* _data_;
	_data_ = _data;
	_g_free0 (_data_->name);
	_g_object_unref0 (_data_->self);
	g_slice_free (FsoDeviceNullPlayerStopSoundData, _data_);
}


static void fso_device_null_player_real_stop_sound (FsoDeviceAudioPlayer* base, const gchar* name, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	FsoDeviceNullPlayer * self;
	FsoDeviceNullPlayerStopSoundData* _data_;
	FsoDeviceNullPlayer* _tmp0_;
	const gchar* _tmp1_;
	gchar* _tmp2_;
	self = (FsoDeviceNullPlayer*) base;
	_data_ = g_slice_new0 (FsoDeviceNullPlayerStopSoundData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, fso_device_null_player_real_stop_sound);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, fso_device_null_player_real_stop_sound_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	_tmp1_ = name;
	_tmp2_ = g_strdup (_tmp1_);
	_data_->name = _tmp2_;
	fso_device_null_player_real_stop_sound_co (_data_);
}


static void fso_device_null_player_real_stop_sound_finish (FsoDeviceAudioPlayer* base, GAsyncResult* _res_, GError** error) {
	FsoDeviceNullPlayerStopSoundData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static gboolean fso_device_null_player_real_stop_sound_co (FsoDeviceNullPlayerStopSoundData* _data_) {
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


static void fso_device_null_player_real_stop_all_sounds_data_free (gpointer _data) {
	FsoDeviceNullPlayerStopAllSoundsData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (FsoDeviceNullPlayerStopAllSoundsData, _data_);
}


static void fso_device_null_player_real_stop_all_sounds (FsoDeviceAudioPlayer* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	FsoDeviceNullPlayer * self;
	FsoDeviceNullPlayerStopAllSoundsData* _data_;
	FsoDeviceNullPlayer* _tmp0_;
	self = (FsoDeviceNullPlayer*) base;
	_data_ = g_slice_new0 (FsoDeviceNullPlayerStopAllSoundsData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, fso_device_null_player_real_stop_all_sounds);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, fso_device_null_player_real_stop_all_sounds_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	fso_device_null_player_real_stop_all_sounds_co (_data_);
}


static void fso_device_null_player_real_stop_all_sounds_finish (FsoDeviceAudioPlayer* base, GAsyncResult* _res_) {
	FsoDeviceNullPlayerStopAllSoundsData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static gboolean fso_device_null_player_real_stop_all_sounds_co (FsoDeviceNullPlayerStopAllSoundsData* _data_) {
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


FsoDeviceNullPlayer* fso_device_null_player_construct (GType object_type) {
	FsoDeviceNullPlayer * self = NULL;
	self = (FsoDeviceNullPlayer*) g_object_new (object_type, NULL);
	return self;
}


FsoDeviceNullPlayer* fso_device_null_player_new (void) {
	return fso_device_null_player_construct (FSO_DEVICE_TYPE_NULL_PLAYER);
}


static void fso_device_null_player_class_init (FsoDeviceNullPlayerClass * klass) {
	fso_device_null_player_parent_class = g_type_class_peek_parent (klass);
}


static void fso_device_null_player_fso_device_audio_player_interface_init (FsoDeviceAudioPlayerIface * iface) {
	fso_device_null_player_fso_device_audio_player_parent_iface = g_type_interface_peek_parent (iface);
	iface->supportedFormats = (gchar** (*)(FsoDeviceAudioPlayer*, int*)) fso_device_null_player_real_supportedFormats;
	iface->play_sound = (void (*)(FsoDeviceAudioPlayer*, const gchar*, gint, gint, GError**)) fso_device_null_player_real_play_sound;
	iface->play_sound_finish = fso_device_null_player_real_play_sound_finish;
	iface->stop_sound = (void (*)(FsoDeviceAudioPlayer*, const gchar*, GError**)) fso_device_null_player_real_stop_sound;
	iface->stop_sound_finish = fso_device_null_player_real_stop_sound_finish;
	iface->stop_all_sounds = (void (*)(FsoDeviceAudioPlayer*)) fso_device_null_player_real_stop_all_sounds;
	iface->stop_all_sounds_finish = fso_device_null_player_real_stop_all_sounds_finish;
}


static void fso_device_null_player_instance_init (FsoDeviceNullPlayer * self) {
}


GType fso_device_null_player_get_type (void) {
	static volatile gsize fso_device_null_player_type_id__volatile = 0;
	if (g_once_init_enter (&fso_device_null_player_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FsoDeviceNullPlayerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_device_null_player_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoDeviceNullPlayer), 0, (GInstanceInitFunc) fso_device_null_player_instance_init, NULL };
		static const GInterfaceInfo fso_device_audio_player_info = { (GInterfaceInitFunc) fso_device_null_player_fso_device_audio_player_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		GType fso_device_null_player_type_id;
		fso_device_null_player_type_id = g_type_register_static (G_TYPE_OBJECT, "FsoDeviceNullPlayer", &g_define_type_info, 0);
		g_type_add_interface_static (fso_device_null_player_type_id, FSO_DEVICE_TYPE_AUDIO_PLAYER, &fso_device_audio_player_info);
		g_once_init_leave (&fso_device_null_player_type_id__volatile, fso_device_null_player_type_id);
	}
	return fso_device_null_player_type_id__volatile;
}


static gboolean _fso_device_playing_sound_onTimeout_gsource_func (gpointer self) {
	gboolean result;
	result = fso_device_playing_sound_onTimeout (self);
	return result;
}


FsoDevicePlayingSound* fso_device_playing_sound_construct (GType object_type, const gchar* name, gint loop, gint length, guint32 data) {
	FsoDevicePlayingSound* self = NULL;
	const gchar* _tmp0_;
	gchar* _tmp1_;
	gint _tmp2_;
	gint _tmp3_;
	guint32 _tmp4_;
	gint _tmp5_;
	g_return_val_if_fail (name != NULL, NULL);
	self = (FsoDevicePlayingSound*) g_type_create_instance (object_type);
	_tmp0_ = name;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->name);
	self->name = _tmp1_;
	_tmp2_ = loop;
	self->loop = _tmp2_;
	_tmp3_ = length;
	self->length = _tmp3_;
	_tmp4_ = data;
	self->data = _tmp4_;
	_tmp5_ = length;
	if (_tmp5_ > 0) {
		gint _tmp6_;
		guint _tmp7_ = 0U;
		_tmp6_ = length;
		_tmp7_ = g_timeout_add_seconds_full (G_PRIORITY_DEFAULT, (guint) _tmp6_, _fso_device_playing_sound_onTimeout_gsource_func, fso_device_playing_sound_ref (self), fso_device_playing_sound_unref);
		self->watch = _tmp7_;
	}
	return self;
}


FsoDevicePlayingSound* fso_device_playing_sound_new (const gchar* name, gint loop, gint length, guint32 data) {
	return fso_device_playing_sound_construct (FSO_DEVICE_TYPE_PLAYING_SOUND, name, loop, length, data);
}


gboolean fso_device_playing_sound_onTimeout (FsoDevicePlayingSound* self) {
	gboolean result = FALSE;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->name;
	g_signal_emit_by_name (self, "sound-finished", _tmp0_);
	result = FALSE;
	return result;
}


static void fso_device_value_playing_sound_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void fso_device_value_playing_sound_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		fso_device_playing_sound_unref (value->data[0].v_pointer);
	}
}


static void fso_device_value_playing_sound_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = fso_device_playing_sound_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer fso_device_value_playing_sound_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* fso_device_value_playing_sound_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		FsoDevicePlayingSound* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = fso_device_playing_sound_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* fso_device_value_playing_sound_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	FsoDevicePlayingSound** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = fso_device_playing_sound_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* fso_device_param_spec_playing_sound (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	FsoDeviceParamSpecPlayingSound* spec;
	g_return_val_if_fail (g_type_is_a (object_type, FSO_DEVICE_TYPE_PLAYING_SOUND), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer fso_device_value_get_playing_sound (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, FSO_DEVICE_TYPE_PLAYING_SOUND), NULL);
	return value->data[0].v_pointer;
}


void fso_device_value_set_playing_sound (GValue* value, gpointer v_object) {
	FsoDevicePlayingSound* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, FSO_DEVICE_TYPE_PLAYING_SOUND));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, FSO_DEVICE_TYPE_PLAYING_SOUND));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		fso_device_playing_sound_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		fso_device_playing_sound_unref (old);
	}
}


void fso_device_value_take_playing_sound (GValue* value, gpointer v_object) {
	FsoDevicePlayingSound* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, FSO_DEVICE_TYPE_PLAYING_SOUND));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, FSO_DEVICE_TYPE_PLAYING_SOUND));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		fso_device_playing_sound_unref (old);
	}
}


static void fso_device_playing_sound_class_init (FsoDevicePlayingSoundClass * klass) {
	fso_device_playing_sound_parent_class = g_type_class_peek_parent (klass);
	FSO_DEVICE_PLAYING_SOUND_CLASS (klass)->finalize = fso_device_playing_sound_finalize;
	g_signal_new ("sound_finished", FSO_DEVICE_TYPE_PLAYING_SOUND, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__STRING, G_TYPE_NONE, 1, G_TYPE_STRING);
}


static void fso_device_playing_sound_instance_init (FsoDevicePlayingSound * self) {
	self->ref_count = 1;
}


static void fso_device_playing_sound_finalize (FsoDevicePlayingSound* obj) {
	FsoDevicePlayingSound * self;
	guint _tmp0_;
	self = FSO_DEVICE_PLAYING_SOUND (obj);
	_tmp0_ = self->watch;
	if (_tmp0_ > ((guint) 0)) {
		guint _tmp1_;
		_tmp1_ = self->watch;
		g_source_remove (_tmp1_);
	}
	_g_free0 (self->name);
}


/**
 * @class PlayingSound
 *
 * Helper class, wraps a sound that's currently playing
 **/
GType fso_device_playing_sound_get_type (void) {
	static volatile gsize fso_device_playing_sound_type_id__volatile = 0;
	if (g_once_init_enter (&fso_device_playing_sound_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { fso_device_value_playing_sound_init, fso_device_value_playing_sound_free_value, fso_device_value_playing_sound_copy_value, fso_device_value_playing_sound_peek_pointer, "p", fso_device_value_playing_sound_collect_value, "p", fso_device_value_playing_sound_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (FsoDevicePlayingSoundClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_device_playing_sound_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoDevicePlayingSound), 0, (GInstanceInitFunc) fso_device_playing_sound_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType fso_device_playing_sound_type_id;
		fso_device_playing_sound_type_id = g_type_register_fundamental (g_type_fundamental_next (), "FsoDevicePlayingSound", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&fso_device_playing_sound_type_id__volatile, fso_device_playing_sound_type_id);
	}
	return fso_device_playing_sound_type_id__volatile;
}


gpointer fso_device_playing_sound_ref (gpointer instance) {
	FsoDevicePlayingSound* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void fso_device_playing_sound_unref (gpointer instance) {
	FsoDevicePlayingSound* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		FSO_DEVICE_PLAYING_SOUND_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}


static gchar** fso_device_base_audio_player_real_supportedFormats (FsoDeviceBaseAudioPlayer* self, int* result_length1) {
	g_critical ("Type `%s' does not implement abstract method `fso_device_base_audio_player_supportedFormats'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}


gchar** fso_device_base_audio_player_supportedFormats (FsoDeviceBaseAudioPlayer* self, int* result_length1) {
	g_return_val_if_fail (self != NULL, NULL);
	return FSO_DEVICE_BASE_AUDIO_PLAYER_GET_CLASS (self)->supportedFormats (self, result_length1);
}


void fso_device_base_audio_player_play_sound (FsoDeviceBaseAudioPlayer* self, const gchar* name, gint loop, gint length, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	FSO_DEVICE_BASE_AUDIO_PLAYER_GET_CLASS (self)->play_sound (self, name, loop, length, _callback_, _user_data_);
}


void fso_device_base_audio_player_play_sound_finish (FsoDeviceBaseAudioPlayer* self, GAsyncResult* _res_, GError** error) {
	FSO_DEVICE_BASE_AUDIO_PLAYER_GET_CLASS (self)->play_sound_finish (self, _res_, error);
}


void fso_device_base_audio_player_stop_sound (FsoDeviceBaseAudioPlayer* self, const gchar* name, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	FSO_DEVICE_BASE_AUDIO_PLAYER_GET_CLASS (self)->stop_sound (self, name, _callback_, _user_data_);
}


void fso_device_base_audio_player_stop_sound_finish (FsoDeviceBaseAudioPlayer* self, GAsyncResult* _res_, GError** error) {
	FSO_DEVICE_BASE_AUDIO_PLAYER_GET_CLASS (self)->stop_sound_finish (self, _res_, error);
}


void fso_device_base_audio_player_stop_all_sounds (FsoDeviceBaseAudioPlayer* self, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	FSO_DEVICE_BASE_AUDIO_PLAYER_GET_CLASS (self)->stop_all_sounds (self, _callback_, _user_data_);
}


void fso_device_base_audio_player_stop_all_sounds_finish (FsoDeviceBaseAudioPlayer* self, GAsyncResult* _res_) {
	FSO_DEVICE_BASE_AUDIO_PLAYER_GET_CLASS (self)->stop_all_sounds_finish (self, _res_);
}


FsoDeviceBaseAudioPlayer* fso_device_base_audio_player_construct (GType object_type) {
	FsoDeviceBaseAudioPlayer * self = NULL;
	self = (FsoDeviceBaseAudioPlayer*) g_object_new (object_type, NULL);
	return self;
}


static GObject * fso_device_base_audio_player_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	FsoDeviceBaseAudioPlayer * self;
	GeeHashMap* _tmp0_;
	parent_class = G_OBJECT_CLASS (fso_device_base_audio_player_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = FSO_DEVICE_BASE_AUDIO_PLAYER (obj);
	_tmp0_ = gee_hash_map_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, FSO_DEVICE_TYPE_PLAYING_SOUND, (GBoxedCopyFunc) fso_device_playing_sound_ref, fso_device_playing_sound_unref, NULL, NULL, NULL);
	_g_object_unref0 (self->sounds);
	self->sounds = _tmp0_;
	return obj;
}


static void fso_device_base_audio_player_class_init (FsoDeviceBaseAudioPlayerClass * klass) {
	fso_device_base_audio_player_parent_class = g_type_class_peek_parent (klass);
	FSO_DEVICE_BASE_AUDIO_PLAYER_CLASS (klass)->supportedFormats = fso_device_base_audio_player_real_supportedFormats;
	G_OBJECT_CLASS (klass)->constructor = fso_device_base_audio_player_constructor;
	G_OBJECT_CLASS (klass)->finalize = fso_device_base_audio_player_finalize;
}


static void fso_device_base_audio_player_fso_device_audio_player_interface_init (FsoDeviceAudioPlayerIface * iface) {
	fso_device_base_audio_player_fso_device_audio_player_parent_iface = g_type_interface_peek_parent (iface);
	iface->supportedFormats = (gchar** (*)(FsoDeviceAudioPlayer*, int*)) fso_device_base_audio_player_supportedFormats;
	iface->play_sound = (void (*)(FsoDeviceAudioPlayer*, const gchar*, gint, gint, GError**)) fso_device_base_audio_player_play_sound;
	iface->play_sound_finish = fso_device_base_audio_player_play_sound_finish;
	iface->stop_sound = (void (*)(FsoDeviceAudioPlayer*, const gchar*, GError**)) fso_device_base_audio_player_stop_sound;
	iface->stop_sound_finish = fso_device_base_audio_player_stop_sound_finish;
	iface->stop_all_sounds = (void (*)(FsoDeviceAudioPlayer*)) fso_device_base_audio_player_stop_all_sounds;
	iface->stop_all_sounds_finish = fso_device_base_audio_player_stop_all_sounds_finish;
}


static void fso_device_base_audio_player_instance_init (FsoDeviceBaseAudioPlayer * self) {
}


static void fso_device_base_audio_player_finalize (GObject* obj) {
	FsoDeviceBaseAudioPlayer * self;
	self = FSO_DEVICE_BASE_AUDIO_PLAYER (obj);
	_g_object_unref0 (self->sounds);
	G_OBJECT_CLASS (fso_device_base_audio_player_parent_class)->finalize (obj);
}


GType fso_device_base_audio_player_get_type (void) {
	static volatile gsize fso_device_base_audio_player_type_id__volatile = 0;
	if (g_once_init_enter (&fso_device_base_audio_player_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FsoDeviceBaseAudioPlayerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_device_base_audio_player_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoDeviceBaseAudioPlayer), 0, (GInstanceInitFunc) fso_device_base_audio_player_instance_init, NULL };
		static const GInterfaceInfo fso_device_audio_player_info = { (GInterfaceInitFunc) fso_device_base_audio_player_fso_device_audio_player_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		GType fso_device_base_audio_player_type_id;
		fso_device_base_audio_player_type_id = g_type_register_static (G_TYPE_OBJECT, "FsoDeviceBaseAudioPlayer", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
		g_type_add_interface_static (fso_device_base_audio_player_type_id, FSO_DEVICE_TYPE_AUDIO_PLAYER, &fso_device_audio_player_info);
		g_once_init_leave (&fso_device_base_audio_player_type_id__volatile, fso_device_base_audio_player_type_id);
	}
	return fso_device_base_audio_player_type_id__volatile;
}



