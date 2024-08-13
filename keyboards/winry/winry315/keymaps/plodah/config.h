#pragma once
#include "plodah.h"

// #define PLODAH_CAPS_INDIC_RGB RGB_MAGENTA
// #define PLODAH_LAYER_INDIC_INDEX1 6
// #define PLODAH_LAYER_INDIC_RGB RGB_MAGENTA
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
