#include QMK_KEYBOARD_H
#include "plodah.h"
#include "quantum.h"

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
#if defined PLODAH_MODS_ON_KNOB
    bool ctl_pressed = false;
    bool sft_pressed = false;
    bool alt_pressed = false;
#endif // PLODAH_MODS_ON_KNOB

//===========================//
//         TAPDANCE          //
//===========================//
#if ! defined(PLODAH_BORING_LAYER)
#   define PLODAH_BORING_LAYER (-1)
#endif

#if PLODAH_BORING_LAYER > 0 && defined(TAP_DANCE_ENABLE)
#include "func/ragequit.c"
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

//===========================//
//       CUSTOM KEYCODES     //
//===========================//
#if defined PLODAH_MODS_ON_KNOB
    #include "func/mods_on_knob.c"
#endif // PLODAH_MODS_ON_KNOB
#include "func/kc_handler.c"
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return kc_handler(keycode, record);
}

//===========================//
//          ALT TAB          //
//===========================//
#ifndef PLODAH_ALT_TAB_DELAY
#  define PLODAH_ALT_TAB_DELAY 1000
#endif
void matrix_scan_user(void) { // The very important timer.
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > PLODAH_ALT_TAB_DELAY) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

//===========================//
//          COMBOS           //
//===========================//
#if defined(COMBO_ENABLE)
  #include "func/combos.c"
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
    #include "func/indicators.c"
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
