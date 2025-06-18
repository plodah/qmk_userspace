#pragma once

#define CM_QFTR_DISABLED
#define CM_QLYR_DISABLED
#define CM_QTAP_DISABLED
#define CM_QVER_DISABLED
#define CM_QRGB_DISABLED
#define KC_PL_SCRL

#define CHORDAL_HOLD

#define PLODAH_BORING_LAYER _BASE
#define TASKSWITCH_FORCE_NDE
#define PLODAH_AUTOCORRECT_INDICATOR_FORCE_NDE

#if defined(COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE)
  // #define MSJIGGLER_NOINTRO
  // #define MSJIGGLER_INTRO_TIMEOUT 1200
  #define MSJIGGLER_LOW_RESOLUTION
#endif // COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE

#if defined(TAP_DANCE_ENABLE)
  #define PLODAH_TAPDANCE_TAPHOLD_ENABLE
#endif // TAP_DANCE_ENABLE

#ifdef COMBO_ENABLE
    #define PLODAH_HRM_COMBOS
    #define PLODAH_BRM_COMBOS
    #define COMBOFLOW_ENABLE
    #define COMBOFLOW_TERM 110
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

/* ------- RGB LIGHTING ------- */
#ifdef RGBLIGHT_ENABLE
  #include "configs/rgblight-effects-fewer.h"
  #include "configs/rgblight-config-fewer.h"
  #define PLODAH_REPEATHOLD_RGB
  // #define PLODAH_REPEATHOLD_RATE 100
#endif // RGBLIGHT_ENABLE

#include "plodah.h"
