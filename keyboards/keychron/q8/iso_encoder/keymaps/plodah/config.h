#pragma once

#if defined(COMMUNITY_MODULE_CONFIG_QUERY_ENABLE)
    // #define CM_QFTR_DISABLED
    // #define CM_QLYR_DISABLED
    // #define CM_QTAP_DISABLED
    // #define CM_QVER_DISABLED
    // #define CM_QRGB_DISABLED
#endif // COMMUNITY_MODULE_CONFIG_QUERY_ENABLE

#define PLODAH_HRM_COMBOS

#define PLODAH_KNOB_ENHANCEMENTS_ENABLE
#define PLODAH_BORING_LAYER 1
#define PLODAH_CAPS_INDIC_HSV 240, 84, 255

#define PLODAH_MODS_INDIC_LCTL_INDEX 59
#define PLODAH_MODS_INDIC_LGUI_INDEX 60
#define PLODAH_MODS_INDIC_LALT_INDEX 61
#define PLODAH_MODS_INDIC_LSHIFT_INDEX 44
// #define PLODAH_MODS_INDIC_RCTL_INDEX 66 // NO RCTL KEY
// #define PLODAH_MODS_INDIC_RGUI_INDEX 66 // NO RGUI KEY
#define PLODAH_MODS_INDIC_RALT_INDEX 66
#define PLODAH_MODS_INDIC_RSHIFT_INDEX 57
#define PLODAH_MODS_INDIC_HSV 240, 84, 255
#define PLODAH_GULOCK_INDIC_ENABLE
// #define PLODAH_MODS_INDIC_GUI_DISABLE

#define PLODAH_LAYER_INDIC_INDEX1 0
#define PLODAH_LAYER_INDIC_HSV 240, 84, 255
// #define PLODAH_LAYER_INDIC_ONZERO
// #define PLODAH_LAYER_INDIC_BG_HSV HSV_ORANGE

#ifdef DYNAMIC_MACRO_ENABLE
  #define PLODAH_DMAC_INDIC_INDEX 28
  // #define PLODAH_DMAC_INDIC_HSV HSV_RED
#endif

#define PLODAH_ACHORDIONINDICATOR_HSV HSV_MAGENTA
#define PLODAH_TYPINGINDICATOR_RGBINDEX 43
#define PLODAH_TYPINGINDICATOR_HSV HSV_GOLD
#define PLODAH_TYPINGINDICATOR_DURATION 250

#if defined(COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE)
  // #define MSJIGGLER_NOINTRO
  // #define MSJIGGLER_INTRO_TIMEOUT 1200
  // #define MSJIGGLER_PATTERN 1
  // #define MSJIGGLER_AUTOSTOP
  #define MSJIGGLER_INDICATOR_RGBINDEX 43
  #define MSJIGGLER_INDICATOR_HSV 0x0B, 0xFF, 0xFF
#endif // COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE

#if defined(TAP_DANCE_ENABLE)
  #define PLODAH_TAPDANCE_TAPHOLD_ENABLE
#endif // TAP_DANCE_ENABLE

/* ------- RGB MATRIX ------- */
#ifdef RGB_MATRIX_ENABLE
  #include "configs/rgbmatrix-effects-many.h"
  #include "configs/rgbmatrix-config.h"
  #define PLODAH_REPEATHOLD_RGB
  // #define PLODAH_REPEATHOLD_RATE 100
#endif // RGB_MATRIX_ENABLE

#include "plodah.h"
