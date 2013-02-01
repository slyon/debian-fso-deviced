/* testsoundsystem.c generated by valac 0.16.1, the Vala compiler
 * generated from testsoundsystem.vala, do not modify */

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
#include <fsodevice.h>
#include <stdlib.h>
#include <string.h>

#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _fso_device_mixer_control_unref0(var) ((var == NULL) ? NULL : (var = (fso_device_mixer_control_unref (var), NULL)))



void test_controls (void);
void test_mixer (void);
void _vala_main (gchar** args, int args_length1);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);


static gpointer _fso_device_mixer_control_ref0 (gpointer self) {
	return self ? fso_device_mixer_control_ref (self) : NULL;
}


void test_controls (void) {
	FsoDeviceSoundDevice* _tmp0_ = NULL;
	FsoDeviceSoundDevice* sd;
	FsoDeviceSoundDevice* _tmp1_;
	gint _tmp2_ = 0;
	FsoDeviceMixerControl** _tmp3_ = NULL;
	FsoDeviceMixerControl** controls;
	gint controls_length1;
	gint _controls_size_;
	FsoDeviceMixerControl** _tmp4_;
	gint _tmp4__length1;
	FsoDeviceMixerControl** _tmp5_;
	gint _tmp5__length1;
	FsoDeviceSoundDevice* _tmp10_;
	FsoDeviceMixerControl** _tmp11_;
	gint _tmp11__length1;
	GError * _inner_error_ = NULL;
	_tmp0_ = fso_device_sound_device_create ("hw:0", &_inner_error_);
	sd = _tmp0_;
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp1_ = sd;
	_tmp3_ = fso_device_sound_device_allMixerControls (_tmp1_, &_tmp2_, &_inner_error_);
	controls = _tmp3_;
	controls_length1 = _tmp2_;
	_controls_size_ = controls_length1;
	if (_inner_error_ != NULL) {
		_g_object_unref0 (sd);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp4_ = controls;
	_tmp4__length1 = controls_length1;
	g_debug ("testsoundsystem.vala:29: # of controls = %d", _tmp4__length1);
	_tmp5_ = controls;
	_tmp5__length1 = controls_length1;
	{
		FsoDeviceMixerControl** control_collection = NULL;
		gint control_collection_length1 = 0;
		gint _control_collection_size_ = 0;
		gint control_it = 0;
		control_collection = _tmp5_;
		control_collection_length1 = _tmp5__length1;
		for (control_it = 0; control_it < _tmp5__length1; control_it = control_it + 1) {
			FsoDeviceMixerControl* _tmp6_;
			FsoDeviceMixerControl* control = NULL;
			_tmp6_ = _fso_device_mixer_control_ref0 (control_collection[control_it]);
			control = _tmp6_;
			{
				FsoDeviceMixerControl* _tmp7_;
				gchar* _tmp8_ = NULL;
				gchar* _tmp9_;
				_tmp7_ = control;
				_tmp8_ = fso_device_mixer_control_to_string (_tmp7_);
				_tmp9_ = _tmp8_;
				g_debug ("testsoundsystem.vala:32: Control: %s", _tmp9_);
				_g_free0 (_tmp9_);
				_fso_device_mixer_control_unref0 (control);
			}
		}
	}
	_tmp10_ = sd;
	_tmp11_ = controls;
	_tmp11__length1 = controls_length1;
	fso_device_sound_device_setAllMixerControls (_tmp10_, _tmp11_, _tmp11__length1, &_inner_error_);
	if (_inner_error_ != NULL) {
		controls = (_vala_array_free (controls, controls_length1, (GDestroyNotify) fso_device_mixer_control_unref), NULL);
		_g_object_unref0 (sd);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	controls = (_vala_array_free (controls, controls_length1, (GDestroyNotify) fso_device_mixer_control_unref), NULL);
	_g_object_unref0 (sd);
}


void test_mixer (void) {
	FsoDeviceSoundDevice* _tmp0_ = NULL;
	FsoDeviceSoundDevice* sd;
	guint8 _tmp1_ = 0U;
	guint8 mainvolume;
	guint8 _tmp2_;
	gchar* _tmp3_ = NULL;
	gchar* _tmp4_;
	gchar* _tmp5_ = NULL;
	gchar* _tmp6_;
	guint8 _tmp7_ = 0U;
	guint8 _tmp8_;
	gchar* _tmp9_ = NULL;
	gchar* _tmp10_;
	gchar* _tmp11_ = NULL;
	gchar* _tmp12_;
	GError * _inner_error_ = NULL;
	_tmp0_ = fso_device_sound_device_create ("hw:0", &_inner_error_);
	sd = _tmp0_;
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp1_ = fso_device_sound_device_volumeForIndex (sd, (guint) 0);
	mainvolume = _tmp1_;
	_tmp2_ = mainvolume;
	_tmp3_ = g_strdup_printf ("%hhu", _tmp2_);
	_tmp4_ = _tmp3_;
	_tmp5_ = g_strconcat ("mainvolume now ", _tmp4_, NULL);
	_tmp6_ = _tmp5_;
	g_debug ("testsoundsystem.vala:44: %s", _tmp6_);
	_g_free0 (_tmp6_);
	_g_free0 (_tmp4_);
	fso_device_sound_device_setVolumeForIndex (sd, (guint) 0, (guint8) 42);
	_tmp7_ = fso_device_sound_device_volumeForIndex (sd, (guint) 0);
	mainvolume = _tmp7_;
	_tmp8_ = mainvolume;
	_tmp9_ = g_strdup_printf ("%hhu", _tmp8_);
	_tmp10_ = _tmp9_;
	_tmp11_ = g_strconcat ("mainvolume now ", _tmp10_, NULL);
	_tmp12_ = _tmp11_;
	g_debug ("testsoundsystem.vala:47: %s", _tmp12_);
	_g_free0 (_tmp12_);
	_g_free0 (_tmp10_);
	_g_object_unref0 (sd);
}


void _vala_main (gchar** args, int args_length1) {
	g_test_init (&args_length1, &args, NULL);
	g_test_run ();
}


int main (int argc, char ** argv) {
	g_type_init ();
	_vala_main (argv, argc);
	return 0;
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



