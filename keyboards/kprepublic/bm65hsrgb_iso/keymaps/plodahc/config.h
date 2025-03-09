#pragma once

#if defined(COMMUNITY_MODULE_CONFIG_QUERY_ENABLE)
    // #define CM_QFTR_DISABLED
    #define CM_QLYR_DISABLED
    #define CM_QTAP_DISABLED
    // #define CM_QVER_DISABLED
    // #define CM_QRGB_DISABLED
#endif // COMMUNITY_MODULE_CONFIG_QUERY_ENABLE

#ifdef PRODUCT
  #undef PRODUCT
#endif // PRODUCT
#define PRODUCT "KPRepublic BM65 ISO | plodahc"

#define PLODAH_BORING_LAYER 1

#define PLODAH_CAPS_INDIC_HSV HSV_MAGENTA
#define PLODAH_LAYER_INDIC_INDEX1 15
#define PLODAH_LAYER_INDIC_HSV HSV_MAGENTA
// #define PLODAH_LAYER_INDIC_ONZERO
// #define PLODAH_LAYER_INDIC_BG_HSV HSV_ORANGE
#define BOOTMAGIC_ROW 0
#define BOOTMAGIC_COLUMN 0

#ifdef DYNAMIC_KEYMAP_LAYER_COUNT
  #undef DYNAMIC_KEYMAP_LAYER_COUNT
#endif
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

/* ------- RGB MATRIX ------- */
#ifdef RGB_MATRIX_ENABLE
  #include "configs/rgbmatrix-effects-few.h"
  #include "configs/rgbmatrix-config.h"
#endif // RGB_MATRIX_ENABLE

/* ------- RGB LIGHTING ------- */
#ifdef RGBLIGHT_ENABLE
  #include "configs/rgblight-effects-few.h"
  #define PLODAH_REPEATHOLD_RGB
  // #define PLODAH_REPEATHOLD_RATE 100
#endif // RGBLIGHT_ENABLE

#include "plodah.h"
