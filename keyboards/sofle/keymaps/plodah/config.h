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

#if defined(COMMUNITY_MODULE_CONFIG_QUERY_ENABLE)
    // #define CM_QFTR_DISABLED
    // #define CM_QLYR_DISABLED
    // #define CM_QTAP_DISABLED
    // #define CM_QVER_DISABLED
    // #define CM_QRGB_DISABLED
#endif // COMMUNITY_MODULE_CONFIG_QUERY_ENABLE
#define KC_PL_SCRL

#define LAYER_NAMES { "Qwert", "Colem", "Fn A ", "Fn B ", "oQwer", "oCole", "oFn A", "oFn B", "Mouse", "Tenth" }

#ifdef PRODUCT
  #undef PRODUCT
#endif // PRODUCT
#define PRODUCT "Sofle | plodahc"

// #define ACHORDION_ENABLE
// #define ACHORDION_STREAK
#define CHORDAL_HOLD

#define PLODAH_KNOB_ENHANCEMENTS_ENABLE
// #define TASKSWITCH_FORCE_NDE
#define PLODAH_BORING_LAYER _O_QWEA

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

#define BOOTMAGIC_ROW 5
#define BOOTMAGIC_COLUMN 0

#ifdef COMBO_ENABLE
  #ifdef COMBO_TERM
    #undef COMBO_TERM
  #endif
  #define COMBO_TERM 50
  #define PLODAH_HRM_COMBOS
#endif

#ifdef TAPPING_TERM
  #undef TAPPING_TERM
#endif
#define TAPPING_TERM 240

#ifdef QUICK_TAP_TERM
  #undef QUICK_TAP_TERM
#endif
#define QUICK_TAP_TERM 60

#ifdef DYNAMIC_KEYMAP_LAYER_COUNT
  #undef DYNAMIC_KEYMAP_LAYER_COUNT
#endif
#define DYNAMIC_KEYMAP_LAYER_COUNT 12

#include "plodah.h"
