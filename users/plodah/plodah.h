#pragma once

#include QMK_KEYBOARD_H
#include "version.h"

bool process_record_user_kb(uint16_t keycode, keyrecord_t *record);

/*
#define plodah_dip_switch_update_kb
#if defined(DIP_SWITCH_ENABLE) && defined(BORING_LAYER)
#define dip_switch_update_kb plodah_dip_switch_update_kb
#endif
*/
/*
#define plodah_rgb_matrix_indicators_advanced_kb
#if defined(RGB_MATRIX_ENABLE) && defined(CAPS_LOCK_LED_INDEX)
#define rgb_matrix_indicators_advanced_kb plodah_rgb_matrix_indicators_advanced_kb
#endif
*/
