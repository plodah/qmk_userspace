#pragma once

#define KC_PL_QFTR
// #define KC_PL_QLYR
#define KC_PL_QRGB
#define KC_PL_QVER

#ifdef PRODUCT
  #undef PRODUCT
#endif // PRODUCT
#define PRODUCT "Keychron V6 ISO Enc | plodahc"

#define PLODAH_KNOB_ENHANCEMENTS_ENABLE
#define PLODAH_BORING_LAYER 1

#define PLODAH_CAPS_INDIC_HSV HSV_MAGENTA

// #define PLODAH_MODS_INDIC_LALT_INDEX 61
// #define PLODAH_MODS_INDIC_LCTL_INDEX 59
// #define PLODAH_MODS_INDIC_LSHIFT_INDEX 44
// #define PLODAH_MODS_INDIC_RALT_INDEX 66
// #define PLODAH_MODS_INDIC_RCTL_INDEX 66
// #define PLODAH_MODS_INDIC_RSHIFT_INDEX 57
// #define PLODAH_MODS_INDIC_HSV 240, 84, 255

#define PLODAH_LAYER_INDIC_INDEX1 20
#define PLODAH_LAYER_INDIC_HSV HSV_MAGENTA
// #define PLODAH_LAYER_INDIC_ONZERO
// #define PLODAH_LAYER_INDIC_BG_HSV HSV_ORANGE

#ifdef DYNAMIC_MACRO_ENABLE
  // #define PLODAH_DMAC_INDIC_INDEX 28
  // #define PLODAH_DMAC_INDIC_HSV HSV_RED
#endif

// #define PLODAH_TYPINGINDICATOR_RGBINDEX 43
// #define PLODAH_TYPINGINDICATOR_HSV 240, 84, 255
// #define PLODAH_TYPINGINDICATOR_DURATION 600

#define BOOTMAGIC_ROW 0
#define BOOTMAGIC_COLUMN 0

#ifdef DYNAMIC_KEYMAP_LAYER_COUNT
  #undef DYNAMIC_KEYMAP_LAYER_COUNT
#endif
#define DYNAMIC_KEYMAP_LAYER_COUNT 5

/* ------- RGB MATRIX ------- */
#ifdef RGB_MATRIX_ENABLE
  #include "configs/rgbmatrix-effects-few.h"
  #include "configs/rgbmatrix-config.h"
  #define PLODAH_REPEATHOLD_RGB
  // #define PLODAH_REPEATHOLD_RATE 100
#endif // RGB_MATRIX_ENABLE

#include "plodah.h"
