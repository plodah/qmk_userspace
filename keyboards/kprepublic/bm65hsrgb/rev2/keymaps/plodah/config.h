#pragma once
#include "plodah.h"

#define PLODAH_BORING_LAYER 1

#define PLODAH_CAPS_INDIC_RGB 0xAB, 0xAB, 0xFF

#define PLODAH_MODS_INDIC_LALT_INDEX 60   ///ALL INDICES UNCHECKED
#define PLODAH_MODS_INDIC_LCTL_INDEX 58
#define PLODAH_MODS_INDIC_LSHIFT_INDEX 44
#define PLODAH_MODS_INDIC_RALT_INDEX 62
// #define PLODAH_MODS_INDIC_RCTL_INDEX 65
#define PLODAH_MODS_INDIC_RSHIFT_INDEX 55
#define PLODAH_MODS_INDIC_RGB 0xAB, 0xAB, 0xFF

#define PLODAH_LAYER_INDIC_INDEX1 0
#define PLODAH_LAYER_INDIC_RGB 0xAB, 0xAB, 0xFF
// #define PLODAH_LAYER_INDIC_ONZERO
// #define PLODAH_LAYER_INDIC_BG_RGB RGB_ORANGE

/* ------- RGB MATRIX ------- */
#ifdef RGB_MATRIX_ENABLE
#  include "configs/rgbmatrix-effects-none.h"
#endif // RGB_MATRIX_ENABLE

/* ------- RGB LIGHTING ------- */
#ifdef RGBLIGHT_ENABLE
#  include "configs/rgblight-effects-none.h"
#endif // RGBLIGHT_ENABLE
