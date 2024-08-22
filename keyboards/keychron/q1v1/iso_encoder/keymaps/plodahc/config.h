#pragma once
#include "plodah.h"

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

#define PLODAH_LAYER_INDIC_INDEX1 15
#define PLODAH_LAYER_INDIC_HSV HSV_MAGENTA
// #define PLODAH_LAYER_INDIC_ONZERO
// #define PLODAH_LAYER_INDIC_BG_HSV HSV_ORANGE

#ifdef DYNAMIC_MACRO_ENABLE
// #  define PLODAH_DMAC_INDIC_INDEX 28
// #  define PLODAH_DMAC_INDIC_HSV HSV_RED
#endif

// #define PLODAH_TYPINGINDICATOR_RGBINDEX 43
// #define PLODAH_TYPINGINDICATOR_HSV 240, 84, 255
// #define PLODAH_TYPINGINDICATOR_DURATION 600

#define BOOTMAGIC_ROW 0
#define BOOTMAGIC_COLUMN 0

#ifdef DYNAMIC_KEYMAP_LAYER_COUNT
#  undef DYNAMIC_KEYMAP_LAYER_COUNT
#endif
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

#if defined (DIP_SWITCH_ENABLE) && defined (PLODAH_BORING_LAYER)
#  define dip_switch_update_kb plodah_dip_switch_update_kb
#endif //DIP_SWITCH_ENABLE

/* ------- RGB MATRIX ------- */
#ifdef RGB_MATRIX_ENABLE
#  include "configs/rgbmatrix-effects-few.h"
#  include "configs/rgbmatrix-config.h"
#endif // RGB_MATRIX_ENABLE
