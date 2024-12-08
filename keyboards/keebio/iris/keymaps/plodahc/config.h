#pragma once

#define KC_PL_QFTR
// #define KC_PL_QLYR
#define KC_PL_QRGB
#define KC_PL_QVER

#ifdef PRODUCT
  #undef PRODUCT
#endif // PRODUCT
#define PRODUCT "Keebio Iris rev2 | plodahc"

#define PLODAH_BORING_LAYER 1

#if defined(DEFERRED_EXEC_ENABLE)
  #define PLODAH_MSJIGGLER_ENABLED
  #define PLODAH_MSJIGGLER_INTRO
  // #define PLODAH_MSJIGGLER_INTRO_TIMEOUT 1200
#endif // DEFERRED_EXEC_ENABLE

#if defined(TAP_DANCE_ENABLE)
  #define PLODAH_TAPDANCE_TAPHOLD_ENABLE
#endif // TAP_DANCE_ENABLE

#define BOOTMAGIC_ROW 0
#define BOOTMAGIC_COLUMN 0

#include "configs/backlight-common.h"
#define SPLIT_LED_STATE_ENABLE

#ifdef COMBO_ENABLE
  #ifdef COMBO_TERM
    #undef COMBO_TERM
  #endif
  #define COMBO_TERM 50
#endif

#ifdef DYNAMIC_KEYMAP_LAYER_COUNT
  #undef DYNAMIC_KEYMAP_LAYER_COUNT
#endif
// #define DYNAMIC_KEYMAP_LAYER_COUNT 4

#include "plodah.h"
