#include QMK_KEYBOARD_H

//#include "quantum.h" // Include the header that defines keyrecord_t
#if defined(PLODAH_KNOB_ENHANCEMENTS_ENABLE)
  #include "encoder_actions.h"
#endif // defined(PLODAH_KNOB_ENHANCEMENTS_ENABLE)
#if defined(OLED_ENABLE)
  #include "oled.h"
#endif // defined(OLED_ENABLE)
#if defined(PLODAH_TAPDANCE_TAPHOLD_ENABLE)
  #include "tapdance.h"
#endif // defined(PLODAH_TAPDANCE_TAPHOLD_ENABLE)
#if defined(PLODAH_DYNAMIC_MACRO_KCS_ENABLE)
  #include "dynamic_macros.h"
#endif // defined(PLODAH_DYNAMIC_MACRO_KCS_ENABLE)
 #if defined(BETTER_DRAGSCROLL)
  #include "better_dragscroll.h"
#endif // defined(BETTER_DRAGSCROLL)
  #if defined(PLODAH_MSGESTURE_ENABLE) && defined(DEFERRED_EXEC_ENABLE)
  #include "mouse_gesture.h"
#endif // defined(PLODAH_MSGESTURE_ENABLE)

#include "tri_layer.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  #if defined(BETTER_DRAGSCROLL)
    if ( ! process_record_better_dragscroll(keycode, record) ) { return false; }
  #endif // defined(BETTER_DRAGSCROLL)

  #if defined(OLED_ENABLE)
    if ( ! process_record_oled(keycode, record) ) { return false; }
  #endif // defined(OLED_ENABLE)

  #if defined(PLODAH_MSGESTURE_ENABLE) && defined(DEFERRED_EXEC_ENABLE)
    process_record_msGesture();
  #endif // defined(PLODAH_MSGESTURE_ENABLE) && defined(DEFERRED_EXEC_ENABLE)

  #ifdef PLODAH_DYNAMIC_MACRO_KCS_ENABLE
    if ( ! process_record_plodah_dynamic_macros(keycode, record) ) { return false; }
  #endif // PLODAH_DYNAMIC_MACRO_KCS_ENABLE

  #ifdef PLODAH_TAPDANCE_TAPHOLD_ENABLE
    if ( ! process_record_tapdance_taphold(keycode, record) ) { return false; }
  #endif // PLODAH_TAPDANCE_TAPHOLD_ENABLE

  #if defined(PLODAH_KNOB_ENHANCEMENTS_ENABLE)
    if ( ! process_record_encoder_actions(keycode, record) ) { return false; }
  #endif  // PLODAH_KNOB_ENHANCEMENTS_ENABLE

  #if defined(TRI_LAYER_ENABLE) && ( defined(PLODAH_TRILAYER_SETONE) || defined(PLODAH_TRILAYER_SETTWO) || defined(PLODAH_TRILAYER_SETTHR) )
    if ( ! process_record_tri_layer(keycode, record) ) { return false; }
  #endif // TRI_LAYER_ENABLE

  return true;
}
