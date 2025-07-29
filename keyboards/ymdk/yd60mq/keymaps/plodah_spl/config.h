#pragma once

// #define CM_QFTR_DISABLED
#define CM_QLYR_DISABLED
#define CM_QTAP_DISABLED
// #define CM_QVER_DISABLED
// #define CM_QRGB_DISABLED

#define CHORDAL_HOLD
#define CHORDAL_HOLD_HANDEDNESS_YD60MQ
#define COMBOFLOW_ENABLE
#define COMBOFLOW_TERM 110

#define PLODAH_BORING_LAYER _QWEB

#ifdef QUICK_TAP_TERM
  #undef QUICK_TAP_TERM
#endif
#define QUICK_TAP_TERM 60

#ifdef FLOW_TAP_TERM
  #undef FLOW_TAP_TERM
#endif
#define FLOW_TAP_TERM 100

#if defined(TAP_DANCE_ENABLE)
  #define PLODAH_TAPDANCE_TAPHOLD_ENABLE
#endif // TAP_DANCE_ENABLE

#ifdef COMBO_ENABLE
  #define PLODAH_HRM_COMBOS
  #define PLODAH_BRM_COMBOS
#endif

/* ------- RGB LIGHTING ------- */
#ifdef RGBLIGHT_ENABLE
  #include "configs/rgblight-effects-few.h"
  #include "configs/rgblight-config.h"
#endif // RGBLIGHT_ENABLE

#include "plodah.h"
