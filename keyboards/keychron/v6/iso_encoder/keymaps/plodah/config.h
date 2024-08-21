#pragma once
#include "plodah.h"

#define PLODAH_KNOB_ENHANCEMENTS_ENABLE
#define PLODAH_BORING_LAYER 1

#define PLODAH_CAPS_INDIC_RGB RGB_MAGENTA

// #define PLODAH_MODS_INDIC_LALT_INDEX 61
// #define PLODAH_MODS_INDIC_LCTL_INDEX 59
// #define PLODAH_MODS_INDIC_LSHIFT_INDEX 44
// #define PLODAH_MODS_INDIC_RALT_INDEX 66
// #define PLODAH_MODS_INDIC_RCTL_INDEX 66
// #define PLODAH_MODS_INDIC_RSHIFT_INDEX 57
// #define PLODAH_MODS_INDIC_RGB 0xAB, 0xAB, 0xFF

#define PLODAH_LAYER_INDIC_INDEX1 20
#define PLODAH_LAYER_INDIC_RGB RGB_MAGENTA
// #define PLODAH_LAYER_INDIC_ONZERO
// #define PLODAH_LAYER_INDIC_BG_RGB RGB_ORANGE

#ifdef DYNAMIC_MACRO_ENABLE
// #  define PLODAH_DMAC_INDIC_INDEX 28
// #  define PLODAH_DMAC_INDIC_RGB RGB_RED
#endif

// #define PLODAH_TYPINGINDICATOR_RGBINDEX 43
// #define PLODAH_TYPINGINDICATOR_RGBCOLOR 0xAB, 0xAB, 0xFF
// #define PLODAH_TYPINGINDICATOR_DURATION 600

/* ------- RGB MATRIX ------- */
#ifdef RGB_MATRIX_ENABLE
#  include "configs/rgbmatrix-effects-none.h"
#endif // RGB_MATRIX_ENABLE
