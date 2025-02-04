#pragma once

#define KC_PL_QFTR
#define KC_PL_QLYR
#define KC_PL_QRGB
#define KC_PL_QVER

#define PLODAH_TASKSWITCH_FORCE_NDE
#define PLODAH_DYNAMIC_MACRO_FORCE_NDE

#if defined(PRODUCT)
  #undef PRODUCT
#endif // PRODUCT
#define PRODUCT "dztech/dz60v2 | plodahc"

#define PLODAH_BORING_LAYER _QWEB

#if defined(DEFERRED_EXEC_ENABLE)
  #define PLODAH_MSJIGGLER_ENABLED
  #define PLODAH_MSJIGGLER_INTRO
  // #define PLODAH_MSJIGGLER_INTRO_TIMEOUT 1200
#endif // DEFERRED_EXEC_ENABLE

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
#define DYNAMIC_KEYMAP_LAYER_COUNT 5

/* ------- RGB LIGHTING ------- */
#ifdef RGBLIGHT_ENABLE
  #include "configs/rgblight-effects-few.h"
  #define PLODAH_REPEATHOLD_RGB
  // #define PLODAH_REPEATHOLD_RATE 100
#endif // RGBLIGHT_ENABLE

#include "plodah.h"
