#pragma once

#define ENABLE_COMPILE_KEYCODE
#define PLODAH_BORING_LAYER 4

#define PLODAH_ALT_TAB_DELAY 750

#define BOOTMAGIC_ROW 0
#define BOOTMAGIC_COLUMN 0

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 1200
#define CAPS_WORD_INVERT_ON_SHIFT

#define COMBO_TERM 35

#define DEBOUNCE 20

#ifdef DYNAMIC_KEYMAP_LAYER_COUNT
#undef DYNAMIC_KEYMAP_LAYER_COUNT
#endif
#define DYNAMIC_KEYMAP_LAYER_COUNT 5

#define TAPPING_TERM 180
#define TAPPING_TOGGLE 3
#define PERMISSIVE_HOLD 3

