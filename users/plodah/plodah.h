#pragma once
#include "version.h"

#ifndef PLODAH_LAYEROFFSET
  #define PLODAH_LAYEROFFSET 0
#endif // PLODAH_LAYEROFFSET

#if defined(PLODAH_ALTTAB_ENHANCEMENTS_ENABLE)  && (! defined(PLODAH_ALT_TAB_DELAY))
  #define PLODAH_ALT_TAB_DELAY 750
#endif // PLODAH_ALTTAB_ENHANCEMENTS_ENABLE

// #define PLODAH_REPEATHOLD_RGB
#if defined(PLODAH_REPEATHOLD_RGB) && (! defined(PLODAH_REPEATHOLD_RATE))
  #define PLODAH_REPEATHOLD_RATE 125
#endif // defined(PLODAH_REPEATHOLD_RGB) && (! defined(PLODAH_REPEATHOLD_RATE))

#if defined(COMBO_ENABLE) && (! defined(COMBO_TERM))
  #define COMBO_TERM 35
#endif // COMBO_ENABLE

#ifndef DEBOUNCE
  #define DEBOUNCE 20
#endif // DEBOUNCE

#if defined(DYNAMIC_MACRO_ENABLE) && (! defined(PLODAH_DYNAMIC_MACRO_TIMEOUT))
  #define PLODAH_DYNAMIC_MACRO_TIMEOUT 2500
#endif // DYNAMIC_MACRO_ENABLE

#ifndef TAPPING_TERM
  #define TAPPING_TERM 180
#endif // TAPPING_TERM

#ifndef TAPPING_TOGGLE
  #define TAPPING_TOGGLE 3
#endif // TAPPING_TOGGLE

#ifndef TAP_CODE_DELAY
  #define TAP_CODE_DELAY 8
#endif // TAP_CODE_DELAY

#ifndef PERMISSIVE_HOLD
  #define PERMISSIVE_HOLD
#endif // PERMISSIVE_HOLD

#define ENABLE_COMPILE_KEYCODE

#if defined(CAPS_WORD_ENABLE)
  #ifndef BOTH_SHIFTS_TURNS_ON_CAPS_WORD
    #define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
  #endif // BOTH_SHIFTS_TURNS_ON_CAPS_WORD

  #ifndef DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
    // #define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
  #endif // DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

  #ifndef CAPS_WORD_IDLE_TIMEOUT
    #define CAPS_WORD_IDLE_TIMEOUT 1200
  #endif // CAPS_WORD_IDLE_TIMEOUT

  #ifndef CAPS_WORD_INVERT_ON_SHIFT
    #define CAPS_WORD_INVERT_ON_SHIFT
  #endif // CAPS_WORD_INVERT_ON_SHIFT
#endif // CAPS_WORD_ENABLE
