// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _COLEMAK,
    _FNA,
    _FNB,
    _FNC,
    _O_QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
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
    P_RAGEQ, KC_1,    P_F2,    KC_3,    P_F4,    P_F5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    P_BSCTL, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  HRM_AG,  HRM_SA,  HRM_DS,  HRM_FC,  HRM_GG,           HRM_HG,  HRM_JC,  HRM_KS,  HRM_LA,  HRM_CG,  KC_QUOT,
    KC_NUBS, BRM_ZG,  BRM_XA,  BRM_CS,  BRM_VC,  BRM_BG,           BRM_NG,  BRM_MC,  BRM_COS, BRM_DOA, BRM_SLG, QK_REP,
                               P_HOMFC, P_ENTFB, P_SPCFA,          P_SPCFA, P_ENTFB, P_ENDFC
  ),

  [_COLEMAK] = LAYOUT(
    P_RAGEQ, KC_1,    P_F2,    KC_3,    P_F4,    P_F5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    P_BSCTL, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,             KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_TAB,  HRM_AG,  HRM_RA,  HRM_SS,  HRM_TC,  HRM_DG,           HRM_HG,  HRM_NC,  HRM_ES,  HRM_IA,  HRM_OG,  KC_QUOT,
    KC_NUBS, BRM_ZG,  BRM_XA,  BRM_CS,  BRM_VC,  BRM_BG,           BRM_KG,  BRM_MC,  BRM_COS, BRM_DOA, BRM_SLG, QK_REP,
                               P_HOMFC, P_ENTFB, P_SPCFA,          P_SPCFA, P_ENTFB, P_ENDFC
  ),

  [_FNA] = LAYOUT(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    RM_TOGG, RM_NEXT, RM_VALU, RM_HUEU, RM_SATU, KC_F6,            KC_F7,   RM_SPDU, _______, _______, _______, KC_DEL,
    KC_BSPC, RM_PREV, RM_VALD, RM_HUED, RM_SATD, _______,          _______, RM_SPDD, _______, _______, _______, KC_NUHS,
    _______, KC_MINS, KC_EQL,  _______, KC_LCBR, KC_LBRC,          KC_RBRC, KC_RCBR, _______, CM_MORT, CM_MORH, CM_MORS,
                               _______, _______, _______,          _______, _______, KC_APP
  ),

  [_FNB] = LAYOUT(
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, KC_DEL,
    _______, _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP,          KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_PSCR, KC_DEL,
    KC_DEL,  _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,          KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_PIPE,
    _______, KC_UNDS, KC_PLUS, SH_TOGG, _______, _______,          _______, _______, SH_TOGG, _______, _______, QK_AREP,
                               _______, _______, _______,          _______, _______, KC_APP
  ),

  [_FNC] = LAYOUT(
    KC_CAPS, CM_QVER, CM_QRGB, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, CM_QLYR, CM_QTAP, QK_MAKE, CM_QFTR, CM_MSJG,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_VOLU, XXXXXXX, KC_LSCR, MS_BTN2, MS_BTN1, MS_BTN3,          XXXXXXX, KC_LCTL, KC_LSFT, KC_LALT, QK_MAKE, KC_VOLU,
    KC_VOLD, CM_TTAT, XXXXXXX, MS_BTN4, MS_BTN5, KC_LSCR,          QWERTY,  COLEMAK, O_QWERT, XXXXXXX, XXXXXXX, KC_VOLD,
                               _______, _______, _______,          _______, _______, _______
  ),

  [_O_QWERTY] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_PSCR,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_ESC,
                               KC_LGUI, LOWER,   KC_SPC,           KC_ENT,  RAISE,   KC_RALT
  ),
  [_LOWER] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,            KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  KC_F12,
    KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_LCTL, _______, _______, _______, _______, _______,          KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______,
    KC_LSFT, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
                               _______, _______, _______,          KC_ENT,  _______, _______
  ),
  [_RAISE] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PSCR,
    KC_TAB,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    KC_LCTL, _______, _______, _______, _______, _______,          KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV,
    KC_LSFT, _______, _______, _______, _______, _______,          KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
                               _______, _______, _______,          _______,  _______, _______
  ),
  [_ADJUST] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PSCR,
    QK_BOOT, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
    RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, _______, _______,          _______, _______, _______, _______, _______, _______,
    RM_NEXT, RM_HUED, RM_SATD, RM_VALD, _______, _______,          QWERTY,  COLEMAK, O_QWERT, _______, _______, _______,
                               _______, _______, _______,          _______,  _______, _______
  ),

/*
  [_EMPTY] = LAYOUT(
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
                               _______, _______, _______,          _______, _______, _______
  ),
*/

};

#ifdef SWAP_HANDS_ENABLE
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    // Left   1 0 3 2 5 4 7 6
    {{1, 5}, {0, 5}, {3, 5}, {2, 5}, {5, 5}, {4, 5}, {7, 5}, {6, 5}},
    {{1, 4}, {0, 4}, {3, 4}, {2, 4}, {5, 4}, {4, 4}, {7, 4}, {6, 4}},
    {{1, 3}, {0, 3}, {3, 3}, {2, 3}, {5, 3}, {4, 3}, {7, 3}, {6, 3}},

    // Right  1 0 3 2 5 4 7 6
    {{1, 2}, {0, 2}, {3, 2}, {2, 2}, {5, 2}, {4, 2}, {7, 2}, {6, 2}},
    {{1, 1}, {0, 1}, {3, 1}, {2, 1}, {5, 1}, {4, 1}, {7, 1}, {6, 1}},
    {{1, 0}, {0, 0}, {3, 0}, {2, 0}, {5, 0}, {4, 0}, {7, 0}, {6, 0}},

    // Thumbs  5 4 3 2 1 0
    {{5, 6}, {4, 6}, {3, 6}, {2, 6}, {1, 6}, {0, 6}}
};
#endif
