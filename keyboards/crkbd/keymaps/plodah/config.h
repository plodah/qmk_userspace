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

#define TURBO_FIRE_KEY_A KC_BTN1
#define CHORDAL_HOLD
#define COMBOFLOW_ENABLE
#define COMBOFLOW_TERM 110

#define PLODAH_BORING_LAYER _BASE

#ifdef QUICK_TAP_TERM
  #undef QUICK_TAP_TERM
#endif
#define QUICK_TAP_TERM 60

#ifdef FLOW_TAP_TERM
  #undef FLOW_TAP_TERM
#endif
#define FLOW_TAP_TERM 100

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

#include "plodah.h"
