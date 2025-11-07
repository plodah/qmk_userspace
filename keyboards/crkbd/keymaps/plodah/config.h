/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

#pragma once

// #define CM_QFTR_DISABLED
// #define CM_QLYR_DISABLED
// #define CM_QTAP_DISABLED
// #define CM_QVER_DISABLED
// #define CM_QRGB_DISABLED
#define KC_PL_SCRL

// #define TASKSWITCH_FORCE_NDE
// #define PLODAH_DYNAMIC_MACRO_FORCE_NDE

#define TURBO_FIRE_KEY_A MS_BTN1
#define CHORDAL_HOLD
#define COMBOFLOW_TERM 100

#define PLODAH_BORING_LAYER _BASE

#ifdef QUICK_TAP_TERM
  #undef QUICK_TAP_TERM
#endif
#define QUICK_TAP_TERM 60

#ifdef FLOW_TAP_TERM
  #undef FLOW_TAP_TERM
#endif
#define FLOW_TAP_TERM 100

#define CAPS_LOCK_LED_INDEX 25
#define PLODAH_CAPS_INDIC_HSV HSV_MAGENTA

#define PLODAH_MODS_INDIC_LCTL_INDEX 11
#define PLODAH_MODS_INDIC_LGUI_INDEX 22
#define PLODAH_MODS_INDIC_LALT_INDEX 19
#define PLODAH_MODS_INDIC_LSHIFT_INDEX 16
#define PLODAH_MODS_INDIC_RCTL_INDEX 38
#define PLODAH_MODS_INDIC_RGUI_INDEX 49
#define PLODAH_MODS_INDIC_RALT_INDEX 46
#define PLODAH_MODS_INDIC_RSHIFT_INDEX 43
#define PLODAH_MODS_INDIC_HSV 240, 84, 255
#define PLODAH_GULOCK_INDIC_ENABLE

#define PLODAH_LAYER_INDIC_INDEXES { 23, 18, 17, 10, 9, 36, 37, 44, 45, 50 }
#define PLODAH_LAYER_INDIC_HSV HSV_MAGENTA
// #define PLODAH_LAYER_INDIC_ONZERO
// #define PLODAH_LAYER_INDIC_BG_HSV HSV_ORANGE

#ifdef DYNAMIC_MACRO_ENABLE
  #define PLODAH_DMAC_INDIC_INDEX 51
  #define PLODAH_DMAC_INDIC_HSV HSV_RED
#endif

#define PLODAH_TYPINGINDICATOR_RGBINDEX 52
#define PLODAH_TYPINGINDICATOR_HSV 240, 84, 255
#define PLODAH_TYPINGINDICATOR_DURATION 600

#if defined(COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE)
  // #define MSJIGGLER_NOINTRO
  // #define MSJIGGLER_INTRO_TIMEOUT 1200
#endif // COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE

#if defined(TAP_DANCE_ENABLE)
  #define PLODAH_TAPDANCE_TAPHOLD_ENABLE
#endif // TAP_DANCE_ENABLE

#ifdef COMBO_ENABLE
  #define PLODAH_HRM_COMBOS
  #define PLODAH_BRM_COMBOS
#endif

#if defined(DYNAMIC_MACRO_ENABLE)
  #define PLODAH_DYNAMIC_MACRO_KCS_ENABLE
#endif // DYNAMIC_MACRO_ENABLE

#ifdef RGB_MATRIX_ENABLE
  #include "configs/rgbmatrix-effects-many.h"
  #include "configs/rgbmatrix-config.h"
  #define PLODAH_REPEATHOLD_RGB
  // #define PLODAH_REPEATHOLD_RATE 100
#endif // RGB_MATRIX_ENABLE

#if defined(TRI_LAYER_ENABLE)
  #define TRI_LAYER_UNSTRICT
#endif // TRI_LAYER_ENABLE

#include "plodah.h"
