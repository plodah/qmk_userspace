#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif


/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

enum keymap_keycodes {
    PL_ALTTAB = QK_USER_0,
    PL_ALTSTAB,
    PL_MSJG,
    PL_QFTR,
    PL_QLYR,
    PL_QRGB,
    PL_QVER,
};

enum {
    TD_ESC_RAGEQUIT,
    TD_F5,
    TD_F11,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_60_b_iso(
        TD(TD_ESC_RAGEQUIT), KC_1, KC_2, KC_3, KC_4, TD(TD_F5), KC_6, KC_7, KC_8, KC_9, KC_0, TD(TD_F11), KC_EQL, KC_NO, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,
        LT(3,KC_BSPC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_SLSH), KC_UP, KC_SLSH,
        KC_LCTL, KC_LGUI, KC_LALT, LT(2,KC_SPC), LT(3,KC_SPC), LT(2,KC_SPC), MT(MOD_RALT,KC_APP), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT_60_b_iso(
        TD(TD_ESC_RAGEQUIT), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_NO, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,
        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_RSFT, KC_UP, KC_SLSH,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, MO(2), KC_SPC, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [2] = LAYOUT_60_b_iso(
        KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_DEL,
        KC_ENT, KC_PGUP, KC_UP, KC_PGDN, _______, _______, _______, _______, _______, _______, KC_PSCR, _______, _______,
        KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, _______, CW_TOGG, KC_PGUP, _______,
        _______, GU_TOGG, _______, KC_SPC, KC_SPC , KC_SPC, _______, _______, KC_HOME, KC_PGDN, KC_END
    ),
    [3] = LAYOUT_60_b_iso(
        KC_GRV, MC_1, MC_2, MC_3, MC_4, MC_5, MC_6, PL_QFTR, PL_QLYR, PL_QRGB, PL_QVER, PL_MSJG, QK_MAKE, KC_NO, KC_DEL,
        BL_TOGG, BL_BRTG, BL_UP, _______, _______, RGB_SPI, _______, _______, _______, _______, KC_PSCR, _______, _______,
        KC_CAPS, BL_BRTG, BL_DOWN, _______, _______, RGB_SPD, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, C(S(KC_V)), _______, NK_TOGG, _______, _______, _______, _______, KC_VOLU, _______,
        _______, GU_TOGG, _______, KC_SPC, KC_SPC , KC_SPC, KC_APP, _______, KC_HOME, KC_VOLD, KC_END
    ),
    /*
    [4] = LAYOUT_60_b_iso(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_NO, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______ , _______, _______, _______, _______, _______, _______
    )
    */
};
