#pragma once
#include <stdbool.h>
#include <stdint.h>
#include "quantum.h" // Include the header that defines keyrecord_t

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  #if defined(PLODAH_TYPINGINDICATOR_RGBINDEX)
    process_record_typing_indicator(keycode, record);
  #endif // PLODAH_TYPINGINDICATOR_RGBINDEX

  #if defined(BETTER_DRAGSCROLL)
    process_record_better_dragscroll(keycode, record);
  #endif // defined(BETTER_DRAGSCROLL)

  #if defined(PLODAH_MSGESTURE_ENABLE) && defined(DEFERRED_EXEC_ENABLE)
    process_record_msGesture();
  #endif // defined(PLODAH_MSGESTURE_ENABLE) && defined(DEFERRED_EXEC_ENABLE)

  #ifdef PLODAH_DYNAMIC_MACRO_KCS_ENABLE
    if ( ! process_record_plodah_dynamic_macros(keycode, record) ) {
      return false;
    }
  #endif // PLODAH_DYNAMIC_MACRO_KCS_ENABLE

  #ifdef PLODAH_TAPDANCE_TAPHOLD_ENABLE
    if ( ! process_record_tapdance_taphold(keycode, record) ) {
      return false;
    }
  #endif // PLODAH_TAPDANCE_TAPHOLD_ENABLE

  #if defined(PLODAH_KNOB_ENHANCEMENTS_ENABLE)
    if ( ! process_record_encoder_actions(keycode, record) ) {
      return false;
    }
  #endif  // PLODAH_KNOB_ENHANCEMENTS_ENABLE

  #if defined(PLODAH_REPEATHOLD_RGB) && (defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE))
    process_record_repeathold_rgb(keycode, record);
  #endif // defined(PLODAH_REPEATHOLD_RGB) && (defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE))

  switch (keycode) {

    #if defined(KC_PL_SCRL)
      case PL_SCRL:
        tap_code(KC_SCRL);
        return false;
    #endif // defined(KC_PL_SCRL)

  }
  return true;
}
