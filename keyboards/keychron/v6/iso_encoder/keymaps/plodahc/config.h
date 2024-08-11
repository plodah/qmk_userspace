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
#  undef BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#  endif
#  define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#  ifdef DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#  undef DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#  endif
// #  define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#  ifdef CAPS_WORD_IDLE_TIMEOUT
#  undef CAPS_WORD_IDLE_TIMEOUT
#  endif
#  define CAPS_WORD_IDLE_TIMEOUT 1200
#  ifdef CAPS_WORD_INVERT_ON_SHIFT
#  undef CAPS_WORD_INVERT_ON_SHIFT
#  endif
// #  define CAPS_WORD_INVERT_ON_SHIFT
#endif

/* ------- COMBO ------- */
#ifdef COMBO_ENABLE
#  ifdef COMBO_TERM
#  undef COMBO_TERM
#  endif
#  define COMBO_TERM 35
#endif

/* ------- RGB MATRIX ------- */
#ifdef RGB_MATRIX_ENABLE

// #  define ENABLE_RGB_MATRIX_ALPHAS_MODS
// #  define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#  define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
// #  define ENABLE_RGB_MATRIX_BREATHING
// #  define ENABLE_RGB_MATRIX_BAND_SAT
// #  define ENABLE_RGB_MATRIX_BAND_VAL
// #  define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
// #  define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
// #  define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
// #  define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
// #  define ENABLE_RGB_MATRIX_CYCLE_ALL
// #  define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
// #  define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
// #  define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
// #  define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
// #  define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
// #  define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
// #  define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
// #  define ENABLE_RGB_MATRIX_DUAL_BEACON
// #  define ENABLE_RGB_MATRIX_RAINBOW_BEACON
// #  define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
// #  define ENABLE_RGB_MATRIX_FLOWER_BLOOMING
// #  define ENABLE_RGB_MATRIX_RAINDROPS
// #  define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
// #  define ENABLE_RGB_MATRIX_HUE_BREATHING
// #  define ENABLE_RGB_MATRIX_HUE_PENDULUM
// #  define ENABLE_RGB_MATRIX_HUE_WAVE
// #  define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
// #  define ENABLE_RGB_MATRIX_PIXEL_FLOW
// #  define ENABLE_RGB_MATRIX_PIXEL_RAIN
// #  define ENABLE_RGB_MATRIX_STARLIGHT
// #  define ENABLE_RGB_MATRIX_STARLIGHT_DUAL_HUE
#  define ENABLE_RGB_MATRIX_STARLIGHT_DUAL_SAT
#  define ENABLE_RGB_MATRIX_RIVERFLOW

// #  define ENABLE_RGB_MATRIX_TYPING_HEATMAP
// #  define ENABLE_RGB_MATRIX_DIGITAL_RAIN

// #  define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
// #  define ENABLE_RGB_MATRIX_SOLID_REACTIVE
// #  define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
// #  define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
// #  define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
// #  define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
// #  define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
// #  define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
// #  define ENABLE_RGB_MATRIX_SPLASH
// #  define ENABLE_RGB_MATRIX_MULTISPLASH
// #  define ENABLE_RGB_MATRIX_SOLID_SPLASH
// #  define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

#  ifdef RGB_MATRIX_DEFAULT_MODE
#  undef RGB_MATRIX_DEFAULT_MODE
#  endif
#  define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_GRADIENT_LEFT_RIGHT
#  ifdef RGB_MATRIX_DEFAULT_HUE
#  undef RGB_MATRIX_DEFAULT_HUE
#  endif
#  define RGB_MATRIX_DEFAULT_HUE 79
#  ifdef RGB_MATRIX_DEFAULT_SAT
#  undef RGB_MATRIX_DEFAULT_SAT
#  endif
#  define RGB_MATRIX_DEFAULT_SAT 239
#  ifdef RGB_MATRIX_DEFAULT_VAL
#  undef RGB_MATRIX_DEFAULT_VAL
#  endif
#  define RGB_MATRIX_DEFAULT_VAL 167
#  ifdef RGB_MATRIX_DEFAULT_SPD
#  undef RGB_MATRIX_DEFAULT_SPD
#  endif
#  define RGB_MATRIX_DEFAULT_SPD 48

#  ifdef RGB_MATRIX_SLEEP
#  undef RGB_MATRIX_SLEEP
#  endif
#  define RGB_MATRIX_SLEEP
#  ifdef RGB_MATRIX_TIMEOUT
#  undef RGB_MATRIX_TIMEOUT
#  endif
#  define RGB_MATRIX_TIMEOUT 270000
#endif
