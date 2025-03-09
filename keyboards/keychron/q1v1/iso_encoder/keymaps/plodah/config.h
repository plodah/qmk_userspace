#pragma once

#if defined COMMUNITY_MODULE_CONFIG_QUERY_ENABLE
    #define CM_QFTR_DISABLED
    #define CM_QLYR_DISABLED
    #define CM_QTAP_DISABLED
    // #define CM_QVER_DISABLED
    #define CM_QRGB_DISABLED
#endif // COMMUNITY_MODULE_CONFIG_QUERY_ENABLE

#define PLODAH_KNOB_ENHANCEMENTS_ENABLE
#define PLODAH_TASKSWITCH_FORCE_NDE
#define PLODAH_DYNAMIC_MACRO_FORCE_NDE
#define PLODAH_AUTOCORRECT_INDICATOR_FORCE_NDE
#define PLODAH_BORING_LAYER 1

#define PLODAH_CAPS_INDIC_HSV HSV_MAGENTA

// #define PLODAH_MODS_INDIC_LCTL_INDEX 73
#define PLODAH_MODS_INDIC_LGUI_INDEX 74
// #define PLODAH_MODS_INDIC_LALT_INDEX 75
#define PLODAH_MODS_INDIC_LSHIFT_INDEX 59
// #define PLODAH_MODS_INDIC_RCTL_INDEX 79
// #define PLODAH_MODS_INDIC_RGUI_INDEX 78
// #define PLODAH_MODS_INDIC_RALT_INDEX 77
#define PLODAH_MODS_INDIC_RSHIFT_INDEX 71
#define PLODAH_MODS_INDIC_HSV 240, 84, 255
#define PLODAH_GULOCK_INDIC_ENABLE
#define PLODAH_MODS_INDIC_GUI_DISABLE

#define PLODAH_LAYER_INDIC_INDEX1 15
#define PLODAH_LAYER_INDIC_HSV HSV_MAGENTA
// #define PLODAH_LAYER_INDIC_ONZERO
// #define PLODAH_LAYER_INDIC_BG_HSV HSV_ORANGE

#ifdef DYNAMIC_MACRO_ENABLE
  #define PLODAH_DMAC_INDIC_INDEX 29
  #define PLODAH_DMAC_INDIC_HSV HSV_RED
#endif

// #define PLODAH_TYPINGINDICATOR_RGBINDEX 29
// #define PLODAH_TYPINGINDICATOR_HSV HSV_RED
// #define PLODAH_TYPINGINDICATOR_DURATION 300

#if defined(COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE)
  #define MSJIGGLER_NOINTRO
  // #define MSJIGGLER_INTRO_TIMEOUT 1200
  // #define MSJIGGLER_PATTERN 1
  // #define MSJIGGLER_AUTOSTOP
  #define MSJIGGLER_INDICATOR_RGBINDEX 43
  #define MSJIGGLER_INDICATOR_HSV 0x0B, 0xFF, 0xFF
#endif // COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE

/* ------- RGB MATRIX ------- */
#ifdef RGB_MATRIX_ENABLE
  #include "configs/rgbmatrix-effects-none.h"
  // #define PLODAH_REPEATHOLD_RGB
  // #define PLODAH_REPEATHOLD_RATE 100
#endif // RGB_MATRIX_ENABLE

#include "plodah.h"
