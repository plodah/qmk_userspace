#pragma once

#define MASTER_RIGHT
#define ENCODER_DIRECTION_FLIP

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
#define KC_PL_SCRL

#define LAYER_NAMES { "Qwert", "Colem", "Fn A ", "Fn B ", "Fn C ", "oQwer", "oCole", "Lower", "Raise", "_10__" }

#define CHORDAL_HOLD
#define COMBOFLOW_ENABLE
#define COMBOFLOW_TERM 110

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

#if defined(DYNAMIC_MACRO_ENABLE)
  #define PLODAH_DYNAMIC_MACRO_KCS_ENABLE
#endif // DYNAMIC_MACRO_ENABLE

#include "plodah.h"
