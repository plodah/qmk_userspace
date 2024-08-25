#include QMK_KEYBOARD_H
#include "plodah.h"
#include "quantum.h"

//====================//
//      MOD VARS      //
//====================//
#if defined(PLODAH_KNOB_ENHANCEMENTS_ENABLE) || defined(PLODAH_MODS_INDIC_LALT_INDEX) || defined(PLODAH_MODS_INDIC_RALT_INDEX)
  bool alt_pressed = false;
#endif // PLODAH_KNOB_ENHANCEMENTS_ENABLE
#if defined(PLODAH_KNOB_ENHANCEMENTS_ENABLE) || defined(PLODAH_MODS_INDIC_LCTL_INDEX) || defined(PLODAH_MODS_INDIC_RCTL_INDEX)
  bool ctl_pressed = false;
#endif // PLODAH_KNOB_ENHANCEMENTS_ENABLE
#if defined(PLODAH_KNOB_ENHANCEMENTS_ENABLE) || defined(PLODAH_MODS_INDIC_LSHIFT_INDEX) || defined(PLODAH_MODS_INDIC_RSHIFT_INDEX)
  bool sft_pressed = false;
#endif // PLODAH_KNOB_ENHANCEMENTS_ENABLE
#if defined CAPS_WORD_ENABLE
  bool sft_held = false;
#endif // CAPS_WORD_ENABLE

#if defined(DYNAMIC_MACRO_ENABLE)
  uint16_t dynamic_macro_loop_timer;
# if defined (RGB_MATRIX_ENABLE) && defined (PLODAH_DMAC_INDIC_INDEX)
    bool is_dynamic_macro_recording = false;
# endif // DYNAMIC_MACRO_ENABLE
#endif //  RGB_MATRIX_ENABLE && PLODAH_DMAC_INDIC_INDEX

#if defined(PLODAH_REPEATHOLD_RGB) && defined(RGB_MATRIX_ENABLE)
# include "functions/repeathold_rgb.c"
#endif // defined(PLODAH_REPEATHOLD_RGB) && defined(RGB_MATRIX_ENABLE)

//===================//
//      ALT TAB      //
//===================//
#if defined(PLODAH_KNOB_ENHANCEMENTS_ENABLE) && (! defined(PLODAH_ALTTAB_ENHANCEMENTS_ENABLE))
#  define PLODAH_ALTTAB_ENHANCEMENTS_ENABLE
#endif // PLODAH_ALTTAB_ENHANCEMENTS_ENABLE
#if defined(PLODAH_ALTTAB_ENHANCEMENTS_ENABLE)
# include "functions/alttab_enhancements.c"
#endif // PLODAH_ALTTAB_ENHANCEMENTS_ENABLE

//=======================//
//      AUTOCORRECT      //
//=======================//
#if defined(AUTOCORRECT_ENABLE)
# include "functions/autocorrect_indicator.c"
#endif // AUTOCORRECT_ENABLE

//====================//
//      TAPDANCE      //
//====================//
#if defined(PLODAH_BORING_LAYER) && defined(TAP_DANCE_ENABLE)
# include "functions/ragequit.c"
  tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_RAGEQUIT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rage_quit_fin, rage_quit_rst)
  };
#endif

//============================//
//      TYPING INDICATOR      //
//============================//
#if defined(PLODAH_TYPINGINDICATOR_RGBINDEX)
# include "functions/typing_indicator.c"
#endif // PLODAH_TYPINGINDICATOR_RGBINDEX

//===========================//
//      CUSTOM KEYCODES      //
//===========================//
#if defined PLODAH_KNOB_ENHANCEMENTS_ENABLE
# include "functions/mods_on_knob.c"
#endif // PLODAH_KNOB_ENHANCEMENTS_ENABLE
#include "functions/process_record_user.c"

//==================//
//      COMBOS      //
//==================//
#if defined(COMBO_ENABLE)
# include "functions/combos.c"
#endif // COMBO_ENABLE

//========================//
//      LAYER CHANGE      //
//========================//
#if defined(PLODAH_BORING_LAYER )
layer_state_t layer_state_set_user(layer_state_t state) {
    # if defined(PLODAH_BORING_LAYER )
      plodah_layerchange_comboactions(state);
    # endif // PLODAH_BORING_LAYER
  return state;
}
#endif // PLODAH_BORING_LAYER

//==============================//
//      KEYCHRON DIPSWITCH      //
//==============================//
#if PLODAH_BORING_LAYER > 0 && defined(DIP_SWITCH_ENABLE)
  bool dip_switch_update_user(uint8_t index, bool active) {
    if (index == 0) {
      //default_layer_set(active ? PLODAH_BORING_LAYER : 0);
      layer_move(active ? PLODAH_BORING_LAYER : 0);
    }
    return true;
  }
#endif // DIP_SWITCH_ENABLE

//=======================//
//      MATRIX SCAN      //
//=======================//
#if (defined(PLODAH_ALTTAB_ENHANCEMENTS_ENABLE)) || ( defined(AUTOCORRECT_ENABLE) && defined(RGB_MATRIX_ENABLE) ) || (defined(PLODAH_TYPINGINDICATOR_RGBINDEX)) || (defined(PLODAH_REPEATHOLD_RGB) && defined(RGB_MATRIX_ENABLE))
void matrix_scan_user(void) {
# if defined(PLODAH_ALTTAB_ENHANCEMENTS_ENABLE)
    plodah_alttab_check();
# endif // PLODAH_ALTTAB_ENHANCEMENTS_ENABLE
# if defined(AUTOCORRECT_ENABLE) && defined(RGB_MATRIX_ENABLE)
    plodah_autocorrect_indicator_check();
# endif // AUTOCORRECT_ENABLE && RGB_MATRIX_ENABLE
# if defined (PLODAH_TYPINGINDICATOR_RGBINDEX)
    plodah_typingindicator_check();
# endif // PLODAH_TYPINGINDICATOR_RGBINDEX
# if defined(DYNAMIC_MACRO_ENABLE) && defined(PLODAH_DYNAMIC_MACRO_TIMEOUT)
    if (timer_elapsed(dynamic_macro_loop_timer) > PLODAH_DYNAMIC_MACRO_TIMEOUT){
        dynamic_macro_stop_recording();
    }
# endif // defined(DYNAMIC_MACRO_ENABLE) && defined(PLODAH_DYNAMIC_MACRO_TIMEOUT)
# if defined(PLODAH_REPEATHOLD_RGB) && defined(RGB_MATRIX_ENABLE)
    repeathold_rgb_check();
# endif // defined(PLODAH_REPEATHOLD_RGB) && defined(RGB_MATRIX_ENABLE)
}
#endif // (defined(PLODAH_ALTTAB_ENHANCEMENTS_ENABLE)) || ( defined(AUTOCORRECT_ENABLE) && defined(RGB_MATRIX_ENABLE) ) || (defined(PLODAH_TYPINGINDICATOR_RGBINDEX))

//==========================//
//      CAPS INDICATOR      //
//==========================//
#if defined(RGB_MATRIX_ENABLE)
# include "functions/indicators.c"
  bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_user()) {
      return false;
    }
    return true;
  }
  bool rgb_matrix_indicators_user() {
    return plodah_indicator_handler();
  }
#endif // RGB_MATRIX_ENABLE

//==================//
//    CAPS_WORD     //
//==================//
#if defined(CAPS_WORD_ENABLE)
  void caps_word_set_user(bool active) {
    if (active) {
      sft_held = true;
    } else {
      sft_held = false;
    }
  }
#endif // CAPS_WORD_ENABLE

//==========================//
//      DYNAMIC MACROS      //
//==========================//
#if defined(DYNAMIC_MACRO_ENABLE)
  bool dynamic_macro_record_start_user(int8_t direction) {
    #if defined (RGB_MATRIX_ENABLE) && defined (PLODAH_DMAC_INDIC_INDEX)
      is_dynamic_macro_recording = true;
    #endif
    # if defined(PLODAH_DYNAMIC_MACRO_TIMEOUT)
      dynamic_macro_loop_timer = timer_read();
    # endif // PLODAH_DYNAMIC_MACRO_TIMEOUT
    return true;
  }
  bool dynamic_macro_record_end_user(int8_t direction) {
    #if defined (RGB_MATRIX_ENABLE) && defined (PLODAH_DMAC_INDIC_INDEX)
      is_dynamic_macro_recording = false;
    #endif
    return true;
  }
#endif // DYNAMIC_MACRO_ENABLE
