#pragma once

#define KC_PL_QFTR
// #define KC_PL_QLYR
#define KC_PL_QRGB
#define KC_PL_QVER

#if defined(PRODUCT)
  #undef PRODUCT
#endif // PRODUCT
#define PRODUCT "dztech/dz60v2 | plodahc"

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

#if defined(DYNAMIC_KEYMAP_LAYER_COUNT)
  #undef DYNAMIC_KEYMAP_LAYER_COUNT
#endif
#define DYNAMIC_KEYMAP_LAYER_COUNT 5

#include "plodah.h"
