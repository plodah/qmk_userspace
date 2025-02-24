#pragma once

#define KC_PL_QFTR
// #define KC_PL_QLYR
#define KC_PL_QRGB
#define KC_PL_QVER
#define PLODAH_TASKSWITCH_ENABLE

// #define PLODAH_CAPS_INDIC_HSV HSV_MAGENTA
// #define PLODAH_LAYER_INDIC_INDEX1 6
#define PLODAH_LAYER_INDIC_INDEXES { 6, 11, 12, 17, 18, 7, 10, 13, 16, 19 }
#define PLODAH_LAYER_INDIC_HSV HSV_RED
// #define PLODAH_LAYER_INDIC_ONZERO
// #define PLODAH_LAYER_INDIC_BG_HSV HSV_ORANGE

#if defined(DEFERRED_EXEC_ENABLE)
  #define PLODAH_MSJIGGLER_ENABLE
  #define PLODAH_MSJIGGLER_INTRO
  // #define PLODAH_MSJIGGLER_INTRO_TIMEOUT 1200
  // #define PLODAH_MSJIGGLER_PATTERN 1
  // #define PLODAH_MSJIGGLER_AUTOSTOP
  #define PLODAH_MSJIGGLER_INDICATOR_RGBINDEX 20
  #define PLODAH_MSJIGGLER_INDICATOR_HSV 0x0B, 0xFF, 0xFF
#endif // DEFERRED_EXEC_ENABLE

/* ------- RGB MATRIX ------- */
#ifdef RGB_MATRIX_ENABLE
  #include "configs/rgbmatrix-effects-none.h"
  #define PLODAH_REPEATHOLD_RGB
  // #define PLODAH_REPEATHOLD_RATE 100
#endif // RGB_MATRIX_ENABLE

/* ------- RGB LIGHTING ------- */
#ifdef RGBLIGHT_ENABLE
  #include "configs/rgblight-effects-none.h"
#endif // RGBLIGHT_ENABLE

#include "plodah.h"
