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
#if !defined(DEBUG_MATRIX_SCAN_RATE)
#define DEBUG_MATRIX_SCAN_RATE
#endif // DEBUG_MATRIX_SCAN_RATE

#if !defined(OLED_FONT_H)
  #undef OLED_FONT_H
#endif // OLED_FONT_H
#define OLED_FONT_H "glcdfont.c"
#define OLED_DISPLAY_64X128
#define AUTOCORRECT_OLED_DISPLAY_LENGTH 10
#define AUTOCORRECT_OLED_DISPLAY_COUNT 4
#define NO_USB_STARTUP_CHECK
#define MASTER_RIGHT

// #define CM_QFTR_DISABLED
// #define CM_QLYR_DISABLED
// #define CM_QTAP_DISABLED
// #define CM_QVER_DISABLED
// #define CM_QRGB_DISABLED

#define LAYER_NAMES { "Qwerty", "Colemak", "G_Qwerty", "Symbols ", "Nav", "Mouse", "RGB", "dunno?" }
#define _FNA _SYM
#define _FNB _NAV
#define _FNC _MSE
#define _FND _RGB

// #define TASKSWITCH_FORCE_NDE
// #define PLODAH_DYNAMIC_MACRO_FORCE_NDE

#define COMBOFLOW_TERM 100
#define TURBO_FIRE_KEY_A MS_BTN1

#define PLODAH_BORING_LAYER _G_QWERTY

#ifdef QUICK_TAP_TERM
  #undef QUICK_TAP_TERM
#endif
#define QUICK_TAP_TERM 60

#define PLODAH_RGBINDICATORS_CAPS_INDEX 24
#define PLODAH_RGBINDICATORS_CAPS_HSV HSV_RED
#define PLODAH_RGBINDICATORS_NUM_INDEX 6
#define PLODAH_RGBINDICATORS_NUM_INVERT
#define PLODAH_RGBINDICATORS_NUM_HSV HSV_ORANGE
#define PLODAH_RGBINDICATORS_SCRL_INDEX 13
#define PLODAH_RGBINDICATORS_SCRL_HSV HSV_YELLOW

#define PLODAH_RGBINDICATORS_MOD_LCTL_INDEX 11
#define PLODAH_RGBINDICATORS_MOD_LGUI_INDEX 22
#define PLODAH_RGBINDICATORS_MOD_LALT_INDEX 19
#define PLODAH_RGBINDICATORS_MOD_LSHIFT_INDEX 16
#define PLODAH_RGBINDICATORS_MOD_RCTL_INDEX 38
#define PLODAH_RGBINDICATORS_MOD_RGUI_INDEX 49
#define PLODAH_RGBINDICATORS_MOD_RALT_INDEX 46
#define PLODAH_RGBINDICATORS_MOD_RSHIFT_INDEX 43
#define PLODAH_RGBINDICATORS_MODS_HSV HSV_PINK
#define PLODAH_RGBINDICATORS_GUILOCK_ENABLE

#define PLODAH_RGBINDICATORS_LAYER_INDEXES { 24, 23, 18, 17, 10, 9, 8, 7 }
#define PLODAH_RGBINDICATORS_LAYER_HSV HSV_MAGENTA
#define PLODAH_RGBINDICATORS_LAYER_STARTING 2
// #define PLODAH_RGBINDICATORS_LAYER_BG_HSV HSV_ORANGE

#ifdef DYNAMIC_MACRO_ENABLE
  #define PLODAH_RGBINDICATORS_DYNMACRO_INDEX 26
  #define PLODAH_RGBINDICATORS_DYNMACRO_HSV HSV_RED
#endif

#define PLODAH_RGBINDICATORS_TYPING_INDEX 25
#define PLODAH_RGBINDICATORS_TYPING_HSV 240, 84, 255
#define PLODAH_RGBINDICATORS_TYPING_DURATION 600

#if defined(COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE)
  // #define MSJIGGLER_NOINTRO
  // #define MSJIGGLER_INTRO_TIMEOUT 1200
  // #define MSJIGGLER_PATTERN 1
  // #define MSJIGGLER_AUTOSTOP
  #define PLODAH_RGBINDICATORS_MSJIGGLER_INDEX 26
  #define PLODAH_RGBINDICATORS_MSJIGGLER_HSV 0x0B, 0xFF, 0xFF
#endif // COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE

#if defined(TAP_DANCE_ENABLE)
  #define PLODAH_TAPDANCE_TAPHOLD_ENABLE
#endif // TAP_DANCE_ENABLE

#ifdef COMBO_ENABLE
  #define PLODAH_COMBOS_COLEMAK
  #define PLODAH_COMBOS_F67
  #define PLODAH_HRM_COMBOS
  #define PLODAH_BRM_COMBOS
  #define PLODAH_HRM_COMBOS_EXCESSIVE
  #define PLODAH_BRM_COMBOS_EXCESSIVE
#endif

#ifdef RGB_MATRIX_ENABLE
  #define RGB_MATRIX_DEFAULT_VAL 42
  #include "configs/rgbmatrix-effects-many.h"
  #include "configs/rgbmatrix-config.h"
  #define PLODAH_REPEATHOLD_RATE 125
#endif // RGB_MATRIX_ENABLE

#if defined(TRI_LAYER_ENABLE)
  #define TRI_LAYER_UNSTRICT
  #define PLODAH_BCD_TRI_LAYER
#endif // TRI_LAYER_ENABLE

#include "plodah.h"
