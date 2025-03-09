#pragma once

#if defined COMMUNITY_MODULE_CONFIG_QUERY_ENABLE
    // #define CM_QFTR_DISABLED
    #define CM_QLYR_DISABLED
    #define CM_QTAP_DISABLED
    // #define CM_QVER_DISABLED
    // #define CM_QRGB_DISABLED
#endif // COMMUNITY_MODULE_CONFIG_QUERY_ENABLE

#ifdef PRODUCT
  #undef PRODUCT
#endif // PRODUCT
#define PRODUCT "Keychron Q10 ISO Enc | plodahc"

#define ACHORDION_ENABLE
#define ACHORDION_STREAK

#define PLODAH_KNOB_ENHANCEMENTS_ENABLE
#define PLODAH_BORING_LAYER 1
#define PLODAH_HRM_COMBOS

#define PLODAH_CAPS_INDIC_HSV 240, 84, 255

#define PLODAH_MODS_INDIC_LCTL_INDEX 79
#define PLODAH_MODS_INDIC_LGUI_INDEX 80
#define PLODAH_MODS_INDIC_LALT_INDEX 81
#define PLODAH_MODS_INDIC_LSHIFT_INDEX 63
#define PLODAH_MODS_INDIC_RCTL_INDEX 85
// #define PLODAH_MODS_INDIC_RGUI_INDEX 84 // NO RGUI KEY
#define PLODAH_MODS_INDIC_RALT_INDEX 83
#define PLODAH_MODS_INDIC_RSHIFT_INDEX 76
#define PLODAH_MODS_INDIC_HSV 240, 84, 255
#define PLODAH_GULOCK_INDIC_ENABLE
// #define PLODAH_MODS_INDIC_GUI_DISABLE

#define PLODAH_LAYER_INDIC_INDEX1 16
#define PLODAH_LAYER_INDIC_HSV 240, 84, 255
// #define PLODAH_LAYER_INDIC_ONZERO
// #define PLODAH_LAYER_INDIC_BG_HSV HSV_ORANGE

#ifdef DYNAMIC_MACRO_ENABLE
  #define PLODAH_DMAC_INDIC_INDEX 29
  // #define PLODAH_DMAC_INDIC_HSV HSV_RED
#endif

#define PLODAH_TYPINGINDICATOR_RGBINDEX 45
#define PLODAH_TYPINGINDICATOR_HSV HSV_GOLD
#define PLODAH_TYPINGINDICATOR_DURATION 250

#if defined(COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE)
  // #define MSJIGGLER_NOINTRO
  // #define MSJIGGLER_INTRO_TIMEOUT 1200
  // #define MSJIGGLER_PATTERN 1
  // #define MSJIGGLER_AUTOSTOP
  #define MSJIGGLER_INDICATOR_RGBINDEX 15
  #define MSJIGGLER_INDICATOR_HSV 0x0B, 0xFF, 0xFF
#endif // COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE

#define BOOTMAGIC_ROW 0
#define BOOTMAGIC_COLUMN 1

#ifdef DYNAMIC_KEYMAP_LAYER_COUNT
  #undef DYNAMIC_KEYMAP_LAYER_COUNT
#endif
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

/* ------- RGB MATRIX ------- */
#ifdef RGB_MATRIX_ENABLE
  #include "configs/rgbmatrix-effects-few.h"
  #include "configs/rgbmatrix-config.h"
  #define PLODAH_REPEATHOLD_RGB
  // #define PLODAH_REPEATHOLD_RATE 100
#endif // RGB_MATRIX_ENABLE

#include "plodah.h"
