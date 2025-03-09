#pragma once

#if defined COMMUNITY_MODULE_CONFIG_QUERY_ENABLE
    // #define CM_QFTR_DISABLED
    #define CM_QLYR_DISABLED
    #define CM_QTAP_DISABLED
    // #define CM_QVER_DISABLED
    // #define CM_QRGB_DISABLED
#endif // COMMUNITY_MODULE_CONFIG_QUERY_ENABLE

#define PLODAH_KNOB_ENHANCEMENTS_ENABLE
#define PLODAH_BORING_LAYER 1

#define PLODAH_CAPS_INDIC_HSV HSV_MAGENTA

#define PLODAH_MODS_INDIC_LCTL_INDEX 58
#define PLODAH_MODS_INDIC_LGUI_INDEX 59
#define PLODAH_MODS_INDIC_LALT_INDEX 60
#define PLODAH_MODS_INDIC_LSHIFT_INDEX 44
#define PLODAH_MODS_INDIC_RCTL_INDEX 64
// #define PLODAH_MODS_INDIC_RGUI_INDEX 64
#define PLODAH_MODS_INDIC_RALT_INDEX 62
#define PLODAH_MODS_INDIC_RSHIFT_INDEX 56
#define PLODAH_MODS_INDIC_HSV 240, 84, 255
#define PLODAH_GULOCK_INDIC_ENABLE
// #define PLODAH_MODS_INDIC_GUI_DISABLE

#define PLODAH_LAYER_INDIC_INDEX1 0
#define PLODAH_LAYER_INDIC_HSV HSV_MAGENTA
// #define PLODAH_LAYER_INDIC_ONZERO
// #define PLODAH_LAYER_INDIC_BG_HSV HSV_ORANGE

#ifdef DYNAMIC_MACRO_ENABLE
  #define PLODAH_DMAC_INDIC_INDEX 28
  // #define PLODAH_DMAC_INDIC_HSV HSV_RED
#endif

#define PLODAH_TYPINGINDICATOR_RGBINDEX 43
#define PLODAH_TYPINGINDICATOR_HSV HSV_MAGENTA
#define PLODAH_TYPINGINDICATOR_DURATION 600

#if defined(DEFERRED_EXEC_ENABLE)
  #define PLODAH_MSJIGGLER_ENABLE
  #define PLODAH_MSJIGGLER_INTRO
  // #define PLODAH_MSJIGGLER_INTRO_TIMEOUT 1200
  // #define PLODAH_MSJIGGLER_PATTERN 1
  // #define PLODAH_MSJIGGLER_AUTOSTOP
  #define PLODAH_MSJIGGLER_INDICATOR_RGBINDEX 28
  #define PLODAH_MSJIGGLER_INDICATOR_HSV 0x0B, 0xFF, 0xFF
#endif // DEFERRED_EXEC_ENABLE

/* ------- RGB MATRIX ------- */
#ifdef RGB_MATRIX_ENABLE
  // #include "configs/rgbmatrix-effects-none.h"
  #include "configs/rgbmatrix-effects-all.h"
  #define PLODAH_REPEATHOLD_RGB
  // #define PLODAH_REPEATHOLD_RATE 100
#endif // RGB_MATRIX_ENABLE

#include "plodah.h"
