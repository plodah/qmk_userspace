#include QMK_KEYBOARD_H
#include "plodah.h"
#include "quantum.h"

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
bool ctl_pressed = false;
bool sft_pressed = false;
bool alt_pressed = false;

//===========================//
//         TAPDANCE          //
//===========================//
#if ! defined(BORING_LAYER)
#   define BORING_LAYER (-1)
#endif

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

#if defined(TAP_DANCE_ENABLE) && BORING_LAYER != -1
#include "func/ragequit.c"
tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_RAGEQUIT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rage_quit_fin, rage_quit_rst)
};
#endif

//===========================//
//       CUSTOM KEYCODES     //
//===========================//
#if defined ( MODS_ON_KNOB )
#include "func/mods_on_knob.c"
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    // Static version keycode
        case PL_VERS:
            if (record->event.pressed) {
                SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE);
            }
            break;
        case PL_ALTTAB:
            if (record->event.pressed) {
                alt_tab_fw();
            }
            break;
        case PL_ALTSTAB:
            if (record->event.pressed) {
                alt_tab_bk();
            }
            break;
        case PL_TEST:
            if (record->event.pressed) {
                SEND_STRING ("Butt with Knobs.");
            }
            break;
    // MOD callback
        case KC_LCTL:
        case KC_RCTL:
            ctl_pressed = record->event.pressed;
            break;
        case KC_LSFT:
        case KC_RSFT:
            sft_pressed = record->event.pressed;
            break;
        case KC_LALT:
        case KC_RALT:
            alt_pressed = record->event.pressed;
            break;
    /* Encoder Actions */
        case ENC_PRS:
            if (record->event.pressed) {
                enc_press_act(ctl_pressed, sft_pressed, alt_pressed);
            }
            break;
        case ENC_CCW:
            if (record->event.pressed) {
                enc_ccw_act(ctl_pressed, sft_pressed, alt_pressed);
            }
            break;
        case ENC_CW:
            if (record->event.pressed) {
                enc_cw_act(ctl_pressed, sft_pressed, alt_pressed);
            }
            break;
    }
    return true;
}
#else
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case PL_VERS:
            if (record->event.pressed) {
                SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE);
            }
            break;
        case PL_ALTTAB:
            if (record->event.pressed) {
                alt_tab_fw();
            }
            break;
        case PL_ALTSTAB:
            if (record->event.pressed) {
                alt_tab_bk();
            }
            break;
        case PL_TEST:
            if (record->event.pressed) {
                SEND_STRING ("Butt without Knobs.");
            }
            break;
    }
    return true;
};
#endif // MODS_ON_KNOB

#ifndef ALT_TAB_DELAY
#  define ALT_TAB_DELAY 1000
#endif

void matrix_scan_user(void) { // The very important timer.
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > ALT_TAB_DELAY) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

#if defined(COMBO_ENABLE)
  #include "func/combos.c"
#endif // COMBO_ENABLE

//===========================//
//    KEYCHRON DIPSWITCH     //
//===========================//
#if defined(DIP_SWITCH_ENABLE) && BORING_LAYER != -1
bool dip_switch_update_user(uint8_t index, bool active) {
    if (index == 0) {
        default_layer_set(1UL << (active ? BORING_LAYER : 0));
    }
    return true;
}
#endif // DIP_SWITCH_ENABLE

//===========================//
//  KEYCHRON CAPS INDICATOR  //
//===========================//
/*
#if defined(RGB_MATRIX_ENABLE) && defined(CAPS_LOCK_LED_INDEX)

bool plodah_rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_user(led_min, led_max)) { return false; }
    // RGB_MATRIX_INDICATOR_SET_COLOR(index, red, green, blue);

    if (host_keyboard_led_state().caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_LED_INDEX, 255, 63, 63);
    } else {
        if (!rgb_matrix_get_flags()) {
           RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_LED_INDEX, 0, 0, 0);
        }
    }
    return true;
}

#endif // CAPS_LOCK_LED_INDEX
*/
