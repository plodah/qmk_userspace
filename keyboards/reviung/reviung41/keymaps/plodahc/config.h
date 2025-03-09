#pragma once

#if defined COMMUNITY_MODULE_CONFIG_QUERY_ENABLE
    // #define CM_QFTR_DISABLED
    // #define CM_QLYR_DISABLED
    // #define CM_QTAP_DISABLED
    // #define CM_QVER_DISABLED
    // #define CM_QRGB_DISABLED
#endif // COMMUNITY_MODULE_CONFIG_QUERY_ENABLE
#define KC_PL_SCRL

// #define TASKSWITCH_FORCE_NDE
// #define PLODAH_DYNAMIC_MACRO_FORCE_NDE
#define PLODAH_HRM_COMBOS

#if defined(PRODUCT)
  #undef PRODUCT
#endif // PRODUCT
#define PRODUCT "reviung41 | plodahc"

// #define ACHORDION_ENABLE
// #define ACHORDION_STREAK
#define CHORDAL_HOLD

#define PLODAH_BORING_LAYER _BASE

#if defined(COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE)
  // #define MSJIGGLER_NOINTRO
  // #define MSJIGGLER_INTRO_TIMEOUT 1200
#endif // COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE

#if defined(TAP_DANCE_ENABLE)
  #define PLODAH_TAPDANCE_TAPHOLD_ENABLE
#endif // TAP_DANCE_ENABLE

#if defined(DYNAMIC_MACRO_ENABLE)
  #define PLODAH_DYNAMIC_MACRO_KCS_ENABLE
#endif // DYNAMIC_MACRO_ENABLE

#define BOOTMAGIC_ROW 0
#define BOOTMAGIC_COLUMN 0

#if defined(DYNAMIC_KEYMAP_LAYER_COUNT)
  #undef DYNAMIC_KEYMAP_LAYER_COUNT
#endif
#define DYNAMIC_KEYMAP_LAYER_COUNT 8

/* ------- RGB LIGHTING ------- */
#ifdef RGBLIGHT_ENABLE
  #include "configs/rgblight-effects-few.h"
  #define PLODAH_REPEATHOLD_RGB
  // #define PLODAH_REPEATHOLD_RATE 100
#endif // RGBLIGHT_ENABLE

#include "plodah.h"
