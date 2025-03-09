#pragma once

#if defined(COMMUNITY_MODULE_CONFIG_QUERY_ENABLE)
    // #define CM_QFTR_DISABLED
    #define CM_QLYR_DISABLED
    #define CM_QTAP_DISABLED
    // #define CM_QVER_DISABLED
    // #define CM_QRGB_DISABLED
#endif // COMMUNITY_MODULE_CONFIG_QUERY_ENABLE

// #define PLODAH_CAPS_INDIC_HSV HSV_MAGENTA
// #define PLODAH_LAYER_INDIC_INDEX1 6
#define PLODAH_LAYER_INDIC_INDEXES { 6, 11, 12, 17, 18, 7, 10, 13, 16, 19 }
#define PLODAH_LAYER_INDIC_HSV HSV_RED
// #define PLODAH_LAYER_INDIC_ONZERO
// #define PLODAH_LAYER_INDIC_BG_HSV HSV_ORANGE

#if defined(COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE)
  // #define MSJIGGLER_NOINTRO
  // #define MSJIGGLER_INTRO_TIMEOUT 1200
  // #define MSJIGGLER_PATTERN 1
  // #define MSJIGGLER_AUTOSTOP
  // #define MSJIGGLER_INDICATOR_RGBINDEX 20
  // #define MSJIGGLER_INDICATOR_HSV 0x0B, 0xFF, 0xFF
#endif // COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE

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
