#pragma once

#define MASTER_RIGHT

#define CM_QFTR_DISABLED
#define CM_QLYR_DISABLED
#define CM_QTAP_DISABLED
#define CM_QVER_DISABLED
#define CM_QRGB_DISABLED

#ifdef COMBO_ENABLE
  #define PLODAH_HRM_COMBOS
  #define PLODAH_BRM_COMBOS
  #define PLODAH_COMBOS_BRM_LIMITED
  #define PLODAH_COMBOS_LIMITED
#endif

#define CHORDAL_HOLD

#define PLODAH_BORING_LAYER 1

#ifdef QUICK_TAP_TERM
  #undef QUICK_TAP_TERM
#endif
#define QUICK_TAP_TERM 60

#ifdef FLOW_TAP_TERM
  #undef FLOW_TAP_TERM
#endif
#define FLOW_TAP_TERM 150

#if defined(COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE)
  // #define MSJIGGLER_NOINTRO
  // #define MSJIGGLER_INTRO_TIMEOUT 1200
#endif // COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE

#if defined(TAP_DANCE_ENABLE)
  #define PLODAH_TAPDANCE_TAPHOLD_ENABLE
#endif // TAP_DANCE_ENABLE

#include "configs/backlight-common.h"
#define SPLIT_LED_STATE_ENABLE

#include "plodah.h"
