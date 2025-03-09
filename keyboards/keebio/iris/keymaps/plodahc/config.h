#pragma once

#define MASTER_RIGHT

#if defined COMMUNITY_MODULE_CONFIG_QUERY_ENABLE
    #define CM_QFTR_DISABLED
    #define CM_QLYR_DISABLED
    #define CM_QTAP_DISABLED
    #define CM_QVER_DISABLED
    #define CM_QRGB_DISABLED
#endif // COMMUNITY_MODULE_CONFIG_QUERY_ENABLE

#ifdef PRODUCT
  #undef PRODUCT
#endif // PRODUCT
#define PRODUCT "Keebio Iris rev2 | plodahc"

#define ACHORDION_ENABLE
// #define ACHORDION_STREAK

#define PLODAH_BORING_LAYER 1

#if defined(COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE)
  // #define MSJIGGLER_NOINTRO
  // #define MSJIGGLER_INTRO_TIMEOUT 1200
#endif // COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE

#if defined(TAP_DANCE_ENABLE)
  #define PLODAH_TAPDANCE_TAPHOLD_ENABLE
#endif // TAP_DANCE_ENABLE

#define BOOTMAGIC_ROW 5
#define BOOTMAGIC_COLUMN 0

#include "configs/backlight-common.h"
#define SPLIT_LED_STATE_ENABLE
#define PLODAH_TASKSWITCH_ENABLE

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
// #define DYNAMIC_KEYMAP_LAYER_COUNT 4

#include "plodah.h"
