#pragma once

// #define CM_QFTR_DISABLED
#define CM_QLYR_DISABLED
#define CM_QTAP_DISABLED
// #define CM_QVER_DISABLED
// #define CM_QRGB_DISABLED

#ifdef PRODUCT
  #undef PRODUCT
#endif // PRODUCT
#define PRODUCT "KPRepublic BM65 ISO | plodahc"

#define PLODAH_BORING_LAYER 1

#define PLODAH_CAPS_INDIC_HSV 240, 84, 255

#define PLODAH_MODS_INDIC_LALT_INDEX 61
#define PLODAH_MODS_INDIC_LCTL_INDEX 59
#define PLODAH_MODS_INDIC_LSHIFT_INDEX 44
#define PLODAH_MODS_INDIC_RALT_INDEX 63
// #define PLODAH_MODS_INDIC_RCTL_INDEX 66
#define PLODAH_MODS_INDIC_RSHIFT_INDEX 56
#define PLODAH_MODS_INDIC_HSV 240, 84, 255

#define PLODAH_LAYER_INDIC_INDEX1 0
#define PLODAH_LAYER_INDIC_HSV 240, 84, 255
// #define PLODAH_LAYER_INDIC_ONZERO
// #define PLODAH_LAYER_INDIC_BG_HSV HSV_ORANGE

/* ------- RGB MATRIX ------- */
#ifdef RGB_MATRIX_ENABLE
  #include "configs/rgbmatrix-effects-none.h"
#endif // RGB_MATRIX_ENABLE

/* ------- RGB LIGHTING ------- */
#ifdef RGBLIGHT_ENABLE
  #include "configs/rgblight-effects-none.h"
  #define PLODAH_REPEATHOLD_RGB
  // #define PLODAH_REPEATHOLD_RATE 100
#endif // RGBLIGHT_ENABLE

#include "plodah.h"
