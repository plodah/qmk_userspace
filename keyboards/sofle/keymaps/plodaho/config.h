#pragma once

#define MASTER_RIGHT
#define ENCODER_DIRECTION_FLIP
#define OLED_DISPLAY_64X128

#ifdef ENCODER_RESOLUTION
  #undef ENCODER_RESOLUTION
#endif //ENCODER_RESOLUTION
#define ENCODER_RESOLUTION 4

#ifdef ENCODER_RESOLUTION_RIGHT
  #undef ENCODER_RESOLUTION_RIGHT
#endif //ENCODER_RESOLUTION_RIGHT
#define ENCODER_RESOLUTION_RIGHT 4

// #define CM_QFTR_DISABLED
// #define CM_QLYR_DISABLED
// #define CM_QTAP_DISABLED
// #define CM_QVER_DISABLED
// #define CM_QRGB_DISABLED

#define LAYER_NAMES { "Qwert", "Colem", "Fn A ", "Fn B ", "Fn C ", "oQwer", "oCole", "Lower", "Raise", "_10__" }

#define CHORDAL_HOLD
#define COMBOFLOW_TERM 100
#define LOCKING_SUPPORT_ENABLE

#define PLODAH_KNOB_ENHANCEMENTS_ENABLE
// #define TASKSWITCH_FORCE_NDE
#define PLODAH_BORING_LAYER _O_QWERTY

#if defined(COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE)
  // #define MSJIGGLER_NOINTRO
  // #define MSJIGGLER_INTRO_TIMEOUT 1200
  // #define MSJIGGLER_PATTERN 1
  // #define MSJIGGLER_AUTOSTOP
  #define MSJIGGLER_INDICATOR_RGBINDEX 43
  #define MSJIGGLER_INDICATOR_HSV 0x0B, 0xFF, 0xFF
#endif // COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE

#if defined(TAP_DANCE_ENABLE)
  #define PLODAH_TAPDANCE_TAPHOLD_ENABLE
#endif // TAP_DANCE_ENABLE

#ifdef COMBO_ENABLE
  #define PLODAH_HRM_COMBOS
  #define PLODAH_BRM_COMBOS
#endif

#ifdef QUICK_TAP_TERM
  #undef QUICK_TAP_TERM
#endif
#define QUICK_TAP_TERM 60

#ifdef FLOW_TAP_TERM
  #undef FLOW_TAP_TERM
#endif
#define FLOW_TAP_TERM 150

#ifdef RGBLIGHT_ENABLE
  #include "configs/rgblight-effects-all.h"
  #include "configs/rgblight-config.h"
  #define PLODAH_REPEATHOLD_RGB
  // #define PLODAH_REPEATHOLD_RATE 100
#endif // RGBLIGHT_ENABLE

#ifdef RGB_MATRIX_ENABLE
#include "configs/rgbmatrix-effects-few.h"
#include "configs/rgbmatrix-config.h"
  #define PLODAH_REPEATHOLD_RGB
  // #define PLODAH_REPEATHOLD_RATE 100
#endif // RGB_MATRIX_ENABLE

#ifdef COMBO_ENABLE
  #define PLODAH_HRM_COMBOS
  #define PLODAH_BRM_COMBOS
#endif

#if defined(DYNAMIC_MACRO_ENABLE)
  #define PLODAH_DYNAMIC_MACRO_KCS_ENABLE
#endif // DYNAMIC_MACRO_ENABLE

#if defined(TRI_LAYER_ENABLE)
  #define TRI_LAYER_UNSTRICT
#endif // TRI_LAYER_ENABLE

#include "plodah.h"
