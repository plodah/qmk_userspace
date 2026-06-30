#pragma once
#include <stdbool.h>
#include <stdint.h>
#include "quantum.h" // Include the header that defines keyrecord_t
#include "encoder_actions.h"
#include "oled.h"
#include "tapdance.h"
#include "tri_layer.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  #if defined(PLODAH_TYPINGINDICATOR_RGBINDEX)
    if ( ! process_record_typing_indicator(keycode, record) ) { return false; }
  #endif // PLODAH_TYPINGINDICATOR_RGBINDEX

  #if defined(BETTER_DRAGSCROLL)
    if ( ! process_record_better_dragscroll(keycode, record) ) { return false; }
  #endif // defined(BETTER_DRAGSCROLL)

  #if defined(OLED_ENABLE)
    if ( ! process_record_oled(keycode, record) ) { return false; }
  #endif // defined(OLED_ENABLE)

  #if defined(PLODAH_MSGESTURE_ENABLE) && defined(DEFERRED_EXEC_ENABLE)
    process_record_msGesture();
  #endif // defined(PLODAH_MSGESTURE_ENABLE) && defined(DEFERRED_EXEC_ENABLE)

  #ifdef PLODAH_TAPDANCE_TAPHOLD_ENABLE
    if ( ! process_record_tapdance_taphold(keycode, record) ) { return false; }
  #endif // PLODAH_TAPDANCE_TAPHOLD_ENABLE

  #if defined(PLODAH_KNOB_ENHANCEMENTS_ENABLE)
    if ( ! process_record_encoder_actions(keycode, record) ) { return false; }
  #endif  // PLODAH_KNOB_ENHANCEMENTS_ENABLE

  #if defined(TRI_LAYER_ENABLE) && defined(TRI_LAYER_UNSTRICT)
    if ( ! process_record_tri_layer(keycode, record) ) { return false; }
  #endif // TRI_LAYER_ENABLE

  return true;
}
