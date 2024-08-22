#pragma once
#include "plodah.h"

#define PLODAH_KNOB_ENHANCEMENTS_ENABLE
#define PLODAH_BORING_LAYER 1

#define PLODAH_CAPS_INDIC_HSV 240, 84, 255

#define PLODAH_MODS_INDIC_LALT_INDEX 81
#define PLODAH_MODS_INDIC_LCTL_INDEX 79
#define PLODAH_MODS_INDIC_LSHIFT_INDEX 63
#define PLODAH_MODS_INDIC_RALT_INDEX 83
#define PLODAH_MODS_INDIC_RCTL_INDEX 85
#define PLODAH_MODS_INDIC_RSHIFT_INDEX 76
#define PLODAH_MODS_INDIC_HSV 240, 84, 255

#define PLODAH_LAYER_INDIC_INDEX1 16
#define PLODAH_LAYER_INDIC_HSV 240, 84, 255
// #define PLODAH_LAYER_INDIC_ONZERO
// #define PLODAH_LAYER_INDIC_BG_HSV HSV_ORANGE

#ifdef DYNAMIC_MACRO_ENABLE
// #  define PLODAH_DMAC_INDIC_INDEX 28
// #  define PLODAH_DMAC_INDIC_HSV HSV_RED
#endif

// #define PLODAH_TYPINGINDICATOR_RGBINDEX 43
// #define PLODAH_TYPINGINDICATOR_HSV 240, 84, 255
// #define PLODAH_TYPINGINDICATOR_DURATION 600

/* ------- RGB MATRIX ------- */
#ifdef RGB_MATRIX_ENABLE
#  include "configs/rgbmatrix-effects-none.h"
#endif // RGB_MATRIX_ENABLE
