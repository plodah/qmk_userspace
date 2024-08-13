#include QMK_KEYBOARD_H
#include "plodah.h"
#include "quantum.h"

#if defined(PLODAH_MODS_ON_KNOB) && (! defined(PLODAH_ALTTAB_ENABLE))
#  define PLODAH_ALTTAB_ENABLE
#endif // PLODAH_ALTTAB_ENABLE

#if defined(PLODAH_ALTTAB_ENABLE)
  bool is_alt_tab_active = false;
  uint16_t alt_tab_timer = 0;
#endif  // PLODAH_ALTTAB_ENABLE

#if defined(PLODAH_MODS_ON_KNOB) || defined(PLODAH_MODS_INDIC_LALT_INDEX) || defined(PLODAH_MODS_INDIC_RALT_INDEX)
    bool alt_pressed = false;
#endif // PLODAH_MODS_ON_KNOB
#if defined(PLODAH_MODS_ON_KNOB) || defined(PLODAH_MODS_INDIC_LCTL_INDEX) || defined(PLODAH_MODS_INDIC_RCTL_INDEX)
    bool ctl_pressed = false;
#endif // PLODAH_MODS_ON_KNOB
#if defined(PLODAH_MODS_ON_KNOB) || defined(PLODAH_MODS_INDIC_LSHIFT_INDEX) || defined(PLODAH_MODS_INDIC_RSHIFT_INDEX)
    bool sft_pressed = false;
#endif // PLODAH_MODS_ON_KNOB
#if defined CAPS_WORD_ENABLE
    bool sft_held = false;
#endif

//===========================//
//         TAPDANCE          //
//===========================//
#if ! defined(PLODAH_BORING_LAYER)
#   define PLODAH_BORING_LAYER (-1)
#endif

#if PLODAH_BORING_LAYER > 0 && defined(TAP_DANCE_ENABLE)
#include "functions/ragequit.c"
void rage_quit_fin(tap_dance_state_t *state, void *user_data) {
    rage_quit_fin_act(state->count);
};
void rage_quit_rst(tap_dance_state_t *state, void *user_data) {
    rage_quit_rst_act(state->count);
};
tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_RAGEQUIT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rage_quit_fin, rage_quit_rst)
};
#endif

//===========================//
//          ALT TAB          //
//===========================//
#if defined(PLODAH_ALTTAB_ENABLE)
    void alt_tab_fw(void) {
        if (!is_alt_tab_active) {
            is_alt_tab_active = true;
            register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        tap_code16(KC_TAB);
    }
    void alt_tab_bk(void) {
        if (!is_alt_tab_active) {
            is_alt_tab_active = true;
            register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        tap_code16(S(KC_TAB));
    }
#endif // PLODAH_ALTTAB_ENABLE

//===========================//
//       CUSTOM KEYCODES     //
//===========================//
#if defined PLODAH_MODS_ON_KNOB
    #include "functions/mods_on_knob.c"
#endif // PLODAH_MODS_ON_KNOB
#include "functions/kc_handler.c"
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return kc_handler(keycode, record);
}

//===========================//
//          ALT TAB          //
//===========================//
#if defined(PLODAH_ALTTAB_ENABLE)
#  ifndef PLODAH_ALT_TAB_DELAY
#    define PLODAH_ALT_TAB_DELAY 1000
#  endif
  void matrix_scan_user(void) { // The very important timer.
    if (is_alt_tab_active) {
      if (timer_elapsed(alt_tab_timer) > PLODAH_ALT_TAB_DELAY) {
        unregister_code(KC_LALT);
        is_alt_tab_active = false;
      }
    }
  }
#endif // PLODAH_ALTTAB_ENABLE

//===========================//
//          COMBOS           //
//===========================//
#if defined(COMBO_ENABLE)
  #include "functions/combos.c"
#endif // COMBO_ENABLE

//===========================//
//    KEYCHRON DIPSWITCH     //
//===========================//
#if PLODAH_BORING_LAYER > 0 && defined(DIP_SWITCH_ENABLE)
bool dip_switch_update_user(uint8_t index, bool active) {
    if (index == 0) {
        //default_layer_set(active ? PLODAH_BORING_LAYER : 0);
        layer_move(active ? PLODAH_BORING_LAYER : 0);
    }
    return true;
}
#endif // DIP_SWITCH_ENABLE

//==================//
//  CAPS INDICATOR  //
//==================//
#if defined(RGB_MATRIX_ENABLE)
#   ifndef PLODAH_MODS_INDIC_RGB
#       define PLODAH_MODS_INDIC_RGB RGB_RED
#   endif
    #include "functions/indicators.c"
    bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
        if (!rgb_matrix_indicators_user( )) {
            return false;
        }
        return true;
    }
    bool rgb_matrix_indicators_user( ) {
        return plodah_indicator_handler( );
    }
#endif // RGB_MATRIX_ENABLE

//==================//
//    CAPS_WORD     //
//==================//
#if defined( CAPS_WORD_ENABLE )
    void caps_word_set_user(bool active) {
        if (active) {
            sft_held = true;
        } else {
            sft_held = false;
        }
    }
#endif // CAPS_WORD_ENABLE
