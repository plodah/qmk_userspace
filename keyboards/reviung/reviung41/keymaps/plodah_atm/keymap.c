/* Copyright 2020 gtips
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY,
    //_COLEMAK,
    _FNA,
    _FNB,
    _FNC,
    //_BASE,
    //_LOWER,
    //_RAISE,
    //_ADJUST,
};

enum {
    TD_ESC_RAGEQUIT,
    // TD_F2,
    // TD_F4,
    // TD_F5,
    // TD_F11,
    // TD_F12,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        P_RAGEQ, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  HRM_AG,  HRM_SA,  HRM_DS,  HRM_FC,  HRM_GG,           HRM_HG,  HRM_JC,  HRM_KS,  HRM_LA,  HRM_CG,  KC_QUOT,
        KC_NUBS, BRM_ZG,  BRM_XA,  BRM_CS,  BRM_VC,  BRM_BG,           BRM_NG,  BRM_MC,  BRM_COS, BRM_DOA, BRM_SLG, QK_REP,
                                            P_HOMFC, P_ENTFB, P_SPCFA, P_ENTFB, P_ENDFC
    ),
    /*
    [_COLEMAK] = LAYOUT(
        P_RAGEQ, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,             KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
        KC_TAB,  HRM_AG,  HRM_RA,  HRM_SS,  HRM_TC,  HRM_DG,           HRM_HG,  HRM_NC,  HRM_ES,  HRM_IA,  HRM_OG,  KC_QUOT,
        KC_NUBS, BRM_ZG,  BRM_XA,  BRM_CS,  BRM_VC,  BRM_BG,           BRM_KG,  BRM_MC,  BRM_COS, BRM_DOA, BRM_SLG, QK_REP,
                                            P_HOMFC, P_ENTFB, P_SPCFA, P_ENTFB, P_ENDFC
    ),
    */
    [_FNA] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        KC_BSPC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS,
        _______, KC_MINS, KC_EQL,  _______, KC_LCBR, KC_LBRC,          KC_RBRC, KC_RCBR, _______, _______, _______, QK_AREP,
                                            _______, _______, _______, _______, KC_APP
    ),

    [_FNB] = LAYOUT(
        _______, _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP,          KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_PSCR, KC_ESC,
        KC_DEL,  _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,          KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_PIPE,
        _______, KC_UNDS, KC_PLUS, _______, _______, _______,          _______, _______, _______, _______, _______, QK_AREP,
                                            _______, _______, _______, _______, KC_APP
    ),

    [_FNC] = LAYOUT(
        KC_CAPS, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),          S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), CM_MSJG,
        KC_VOLU, XXXXXXX, KC_LSCR, MS_BTN2, MS_BTN1, MS_BTN3,          XXXXXXX, KC_LCTL, KC_LSFT, KC_LALT, QK_MAKE, KC_VOLU,
        KC_VOLD, XXXXXXX, XXXXXXX, MS_BTN4, MS_BTN5, KC_LSCR,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD,
                                            _______, _______, _______, _______, _______
    ),
    /*
    [_BASE] = LAYOUT(
        P_RAGEQ, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
                                            KC_LGUI, LOWER,   KC_SPC,  RAISE,   LT(_ADJUST, KC_RALT)
    ),

    [_LOWER] = LAYOUT(
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
        _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_GRV,  KC_TILD,
        _______, KC_ESC,  KC_LGUI, KC_LALT, KC_CAPS, KC_DQUO,          KC_HOME, KC_END,  KC_PGUP, KC_PGDN, KC_PSCR, RSFT_T(KC_SPC),
                                            _______, _______, KC_ENT,  _______, _______
    ),

    [_RAISE] = LAYOUT(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,          KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
        _______, KC_ESC,  KC_RGUI, KC_RALT, KC_CAPS, KC_QUOT,          KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
                                            _______, _______, KC_BSPC, _______, _______
    ),

    [_ADJUST] = LAYOUT(
        UG_VALU, UG_SATU, UG_HUEU, UG_NEXT, XXXXXXX, UG_TOGG,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        UG_VALD, UG_SATD, UG_HUED, UG_PREV, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            _______, _______, XXXXXXX, _______, _______
    ),
    */
};
