#pragma once

#define PLODAH_MODS_ON_KNOB
#define PLODAH_BORING_LAYER 1

#define PLODAH_CAPS_INDIC_RGB RGB_MAGENTA
#define PLODAH_LAYER_INDIC_INDEX1 20
#define PLODAH_LAYER_INDIC_RGB RGB_MAGENTA
// #define PLODAH_LAYER_INDIC_ONZERO
// #define PLODAH_LAYER_INDIC_BG_RGB RGB_ORANGE

#define ENABLE_COMPILE_KEYCODE

#define PLODAH_ALT_TAB_DELAY 750

#define BOOTMAGIC_ROW 0
#define BOOTMAGIC_COLUMN 0

#ifdef DYNAMIC_KEYMAP_LAYER_COUNT
#undef DYNAMIC_KEYMAP_LAYER_COUNT
#endif
#define DYNAMIC_KEYMAP_LAYER_COUNT 5

#define DEBOUNCE 20

#define TAPPING_TERM 180
#define TAPPING_TOGGLE 3
#define TAP_CODE_DELAY 12
#define PERMISSIVE_HOLD 3

#if defined (DIP_SWITCH_ENABLE) && defined (PLODAH_BORING_LAYER)
#define dip_switch_update_kb plodah_dip_switch_update_kb
#endif

#if defined (RGB_MATRIX_ENABLE) && defined (CAPS_LOCK_LED_INDEX)
#define rgb_matrix_indicators_advanced_kb plodah_rgb_matrix_indicators_advanced_kb
#endif

/* ------- CAPS_WORD ------- */
#ifdef CAPS_WORD_ENABLE
#  ifdef BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#    undef BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#  endif
#  define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#  ifdef DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#    undef DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#  endif
// #  define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#  ifdef CAPS_WORD_IDLE_TIMEOUT
#    undef CAPS_WORD_IDLE_TIMEOUT
#  endif
#  define CAPS_WORD_IDLE_TIMEOUT 1200
#  ifdef CAPS_WORD_INVERT_ON_SHIFT
#    undef CAPS_WORD_INVERT_ON_SHIFT
#  endif
// #  define CAPS_WORD_INVERT_ON_SHIFT
#endif

/* ------- COMBO ------- */
#ifdef COMBO_ENABLE
#  ifdef COMBO_TERM
#    undef COMBO_TERM
#  endif
#  define COMBO_TERM 35
#endif

/* ------- RGB MATRIX ------- */
#ifdef RGB_MATRIX_ENABLE
#  include "configs/rgbmatrix-effects-few.h"
#  include "configs/rgbmatrix-config.h"
#endif // RGB_MATRIX_ENABLE
