#include QMK_KEYBOARD_H
#include "plodah.h"
#include "quantum.h"

bool is_alt_tab_active = false; // ADD this near the beginning of keymap.c
uint16_t alt_tab_timer = 0;     // we will be using them soon.

//===========================//
//         TAPDANCE          //
//===========================//
#if ! defined(BORING_LAYER)
#   define BORING_LAYER (-1)
#endif

#if defined(TAP_DANCE_ENABLE) && BORING_LAYER != -1
#include "func/ragequit.c"
tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_RAGEQUIT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rage_quit_fin, rage_quit_rst)
};
#endif

void alt_tab_fwd(void) {
    if (!is_alt_tab_active) {
        is_alt_tab_active = true;
        register_code(KC_LALT);
    }
    alt_tab_timer = timer_read();
    tap_code16(KC_TAB);
}
void alt_tab_back(void) {
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

#if defined ( MODS_ON_KNOB )

bool tab_pressed = false; // ADD this near the beginning of keymap.c
bool ctrl_pressed = false;
bool shift_pressed = false;
bool r_shift_pressed = false;
bool alt_pressed = false;
bool r_alt_pressed = false;

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
                alt_tab_fwd();
            }
            break;
        case PL_ALTTAB_REV:
            if (record->event.pressed) {
                alt_tab_back();
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
            ctrl_pressed = record->event.pressed;
            break;
        case KC_LSFT:
        case KC_RSFT:
            shift_pressed = record->event.pressed;
            break;
        case KC_LALT:
        case KC_RALT:
            alt_pressed = record->event.pressed;
            break;

    /* Encoder Actions */
        case ENC_PRS:
            if (record->event.pressed) {
                if (ctrl_pressed && shift_pressed) {
                    tap_code(KC_MPLY);
                }
                else if (ctrl_pressed && shift_pressed) {

                }
                else if (ctrl_pressed) {
                    rgb_matrix_toggle_noeeprom();
                }
                else if (alt_pressed) {

                }
                else if (shift_pressed) {

                }
                else if (
                    (get_highest_layer(layer_state) % 2 ) == 1
                    && ( get_highest_layer(layer_state) != BORING_LAYER)
                ) {
                    tap_code16(C(KC_F4));
                }
                else if (
                    (get_highest_layer(layer_state) % 2 ) == 0
                    && (get_highest_layer(layer_state) != 0)
                    && ( get_highest_layer(layer_state) != BORING_LAYER)
                ) {
                    tap_code16(A(KC_F4));
                }
                else {
                    tap_code(KC_MUTE);
                }
            }
            break;

        case ENC_CCW:
            if (record->event.pressed) {
                if (ctrl_pressed && shift_pressed) {
                    tap_code(KC_MPRV);
                }
                else if (ctrl_pressed && shift_pressed) {
                    tap_code16(C(KC_RGHT));
                }
                else if (ctrl_pressed) {
                    rgb_matrix_decrease_val_noeeprom();
                }
                else if (alt_pressed) {
                    tap_code(KC_PGUP);
                }
                else if (shift_pressed) {
                    rgb_matrix_decrease_sat_noeeprom();
                }
                else if (
                    (get_highest_layer(layer_state) % 2 ) == 1
                    && ( get_highest_layer(layer_state) != BORING_LAYER)
                ) {
                    tap_code16(C(S(KC_TAB)));
                }
                else if (
                    (get_highest_layer(layer_state) % 2 ) == 0
                    && (get_highest_layer(layer_state) != 0)
                    && ( get_highest_layer(layer_state) != BORING_LAYER)
                ) {
                    alt_tab_back();
                }
                else {
                    tap_code16_delay(KC_VOLD, 2);
                }
            }
            break;

        case ENC_CW:
            if (record->event.pressed) {
                if (ctrl_pressed && shift_pressed) {
                    tap_code(KC_MNXT);
                }
                else if (ctrl_pressed && shift_pressed) {
                    tap_code16(C(KC_LEFT));
                }
                else if (ctrl_pressed) {
                    rgb_matrix_increase_val_noeeprom();
                }
                else if (alt_pressed) {
                    tap_code(KC_PGDN);
                }
                else if (shift_pressed) {
                    rgb_matrix_increase_sat_noeeprom();
                }
                else if (
                    (get_highest_layer(layer_state) % 2 ) == 1
                    && ( get_highest_layer(layer_state) != BORING_LAYER)
                ) {
                    tap_code16(C(KC_TAB));
                }
                else if (
                    (get_highest_layer(layer_state) % 2 ) == 0
                    && (get_highest_layer(layer_state) != 0)
                    && ( get_highest_layer(layer_state) != BORING_LAYER)
                ) {
                    alt_tab_fwd();
                }
                else {
                    tap_code16_delay(KC_VOLU, 2);
                }
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
                alt_tab_fwd();
            }
            break;
        case PL_ALTTAB_REV:
            if (record->event.pressed) {
                alt_tab_back();
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
//===========================//
//       COMMON COMBOS       //
//===========================//
#if ! defined(IS_MOUSE)
const uint16_t PROGMEM qa_combo[] = {KC_Q , KC_A, COMBO_END};
const uint16_t PROGMEM bsz_combo[] = {KC_NUBS, KC_Z, COMBO_END};
const uint16_t PROGMEM zx_combo[] = {KC_Z , KC_X, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X , KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C , KC_V, COMBO_END};
const uint16_t PROGMEM xcv_combo[] = {KC_X , KC_C , KC_V, COMBO_END};

//===========================//
// COMBOS FOR DYNAMIC MACROS //
//===========================//
#if defined(DYNAMIC_MACRO_ENABLE)
const uint16_t PROGMEM _12_combo[] = {KC_1 , KC_2, COMBO_END};
const uint16_t PROGMEM _13_combo[] = {KC_1 , KC_3, COMBO_END};
const uint16_t PROGMEM qw_combo[] = {KC_Q , KC_W, COMBO_END};
const uint16_t PROGMEM qe_combo[] = {KC_Q , KC_E, COMBO_END};
const uint16_t PROGMEM _3e_combo[] = {KC_3 , KC_E, COMBO_END};

combo_t key_combos[] = {
    COMBO(_12_combo, DM_PLY1),
    COMBO(_13_combo, DM_REC1),
    COMBO(qw_combo, DM_PLY2),
    COMBO(qe_combo, DM_REC2),
    COMBO(_3e_combo, DM_RSTP),
    COMBO(qa_combo, C(KC_A)),
    COMBO(bsz_combo, C(KC_Z)),
    COMBO(zx_combo, C(KC_X)),
    COMBO(xc_combo, C(KC_C)),
    COMBO(cv_combo, C(KC_V)),
    COMBO(xcv_combo, C(S(KC_V)))
};

//==============================//
// COMBOS BUT NO DYNAMIC MACROS //
//------------------------------//
#else
combo_t key_combos[] = {
    COMBO(qa_combo, C(KC_A)),
    COMBO(bsz_combo, C(KC_Z)),
    COMBO(zx_combo, C(KC_X)),
    COMBO(xc_combo, C(KC_C)),
    COMBO(cv_combo, C(KC_V)),
    COMBO(xcv_combo, C(S(KC_V)))
};
#endif
//===========================//
//        MOUSE COMBOS       //
//===========================//
#else
    const uint16_t PROGMEM ms1ms2_combo[] = {KC_BTN1 , KC_BTN2, COMBO_END};
    const uint16_t PROGMEM ms1ms4_combo[] = {KC_BTN1 , KC_BTN4, COMBO_END};
    const uint16_t PROGMEM ms2ms4_combo[] = {KC_BTN2 , KC_BTN4, COMBO_END};
    const uint16_t PROGMEM ms1ms5_combo[] = {KC_BTN1 , KC_BTN5, COMBO_END};
    const uint16_t PROGMEM ms2ms5_combo[] = {KC_BTN2 , KC_BTN5, COMBO_END};

    combo_t key_combos[] = {
        COMBO(ms1ms2_combo, DRAG_SCROLL),
        COMBO(ms1ms4_combo, DRAG_SCROLL),
        COMBO(ms2ms4_combo, DRAG_SCROLL),
        COMBO(ms1ms5_combo, C(KC_C)),
        COMBO(ms2ms5_combo, C(KC_V)),
    };
#endif
#endif

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
