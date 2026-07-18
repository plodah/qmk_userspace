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
    _COLEMK,
    _G_QWERTY,
    _SYM,
    _NAV,
    _MSE,
    _RGB,
};

enum {
    TD_ESC_RAGEQUIT,
    TD_F2,
    TD_F4,
    TD_F5,
    TD_F11,
    TD_F12,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        P_RAGEQ, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  HRM_AG,  HRM_SA,  HRM_DS,  HRM_FC,  HRM_GG,           HRM_HG,  HRM_JC,  HRM_KS,  HRM_LA,  HRM_CG,  KC_QUOT,
        P_BSSH,  BRM_ZG,  BRM_XA,  BRM_CS,  BRM_VC,  BRM_BG,           BRM_NG,  BRM_MC,  BRM_COS, BRM_DOA, BRM_SLG, QK_REP,
                                            P_HOMMS, P_ENTNA, P_SPCSY, P_ENTNA, P_ENDMS
    ),

    [_COLEMK] = LAYOUT(
        P_RAGEQ, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,             KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
        KC_TAB,  HRM_AG,  HRM_RA,  HRM_SS,  HRM_TC,  HRM_DG,           HRM_HG,  HRM_NC,  HRM_ES,  HRM_IA,  HRM_OG,  KC_QUOT,
        P_BSSH,  BRM_ZG,  BRM_XA,  BRM_CS,  BRM_VC,  BRM_BG,           BRM_KG,  BRM_MC,  BRM_COS, BRM_DOA, BRM_SLG, QK_REP,
                                            P_HOMMS, P_ENTNA, P_SPCSY, P_ENTNA, P_ENDMS
    ),

    [_G_QWERTY] = LAYOUT(
        P_RAGEQ, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LCTL,
                                            P_NAV,   P_SYM,   KC_SPC,  KC_ENT,  P_MSE
    ),

    [_SYM] = LAYOUT(
        KC_GRV,  KC_1,    P_F2,    KC_3,    P_F4,    P_F5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS,
        XXXXXXX, KC_MINS, KC_EQL,  XXXXXXX, KC_LCBR, KC_LBRC,          KC_RBRC, KC_RCBR, XXXXXXX, CM_MORT, CM_MORH, CM_MORS,
                                            KC_APP,  _______, _______, _______, KC_APP
    ),

    [_NAV] = LAYOUT(
        KC_CAPS, XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_PGUP,          KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_PSCR, KC_ESC,
        KC_VOLU, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,          KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_VOLU,
        KC_VOLD, KC_UNDS, KC_PLUS, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD,
                                            _______, _______, _______, _______, _______
    ),

    [_MSE] = LAYOUT(
        XXXXXXX, XXXXXXX, KC_INT2, KC_LCAP, XXXXXXX, KC_LSCR,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CM_MSJG,
        XXXXXXX, KC_LNUM, KC_LSCR, MS_BTN2, MS_BTN1, MS_BTN3,          MS_BTN3, MS_BTN1, MS_BTN2, KC_LSCR, KC_LNUM, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, MS_BTN4, MS_BTN5, KC_LSCR,          KC_LSCR, MS_BTN4, MS_BTN5, XXXXXXX, XXXXXXX, XXXXXXX,
                                            _______, _______, _______, _______, _______
    ),

    [_RGB] = LAYOUT(
        UG_TOGG, UG_NEXT, UG_HUEU, UG_SATU, UG_VALU, UG_SPDU,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_BRIU, UG_PREV, UG_HUED, UG_SATD, UG_VALD, UG_SPDD,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_BRID, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            _______, _______, _______, _______, _______
    ),

/*
    [_BLANK] = LAYOUT(
        _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______, _______, _______
    ),
*/

};

#ifdef SWAP_HANDS_ENABLE
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    // Left
    {{5, 3}, {4, 3}, {3, 3}, {2, 3}, {1, 3}, {0, 3}},
    {{5, 4}, {4, 4}, {3, 4}, {2, 4}, {1, 4}, {0, 4}},
    {{5, 5}, {4, 5}, {3, 5}, {2, 5}, {1, 5}, {0, 5}},

    // Right
    {{5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}},
    {{5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}},
    {{5, 2}, {4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}},

    // Thumbs
    {{4, 6}, {3, 6}, {2, 6}, {1, 6}, {0, 6}}
};
#endif
