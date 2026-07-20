// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum layers {
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
    P_RAGEQ, KC_1,    P_F2,    KC_3,    P_F4,    P_F5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    P_BSCTL, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  HRM_AG,  HRM_SA,  HRM_DS,  HRM_FC,  HRM_GG,                          HRM_HG,  HRM_JC,  HRM_KS,  HRM_LA,  HRM_CG,  KC_QUOT,
    KC_NUBS, BRM_ZG,  BRM_XA,  BRM_CS,  BRM_VC,  BRM_BG,  PL_ECPR,       PL_ECPR, BRM_NG,  BRM_MC,  BRM_COS, BRM_DOA, BRM_SLG, QK_REP,
                      P_HOMMS, KC_LALT, KC_LCTL, P_ENTNA, P_SPCSY,       P_SPCSY, P_ENTNA, KC_RCTL, KC_RALT, P_ENDMS
  ),

  [_COLEMK] = LAYOUT(
    P_RAGEQ, KC_1,    P_F2,    KC_3,    P_F4,    P_F5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    P_BSCTL, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                            KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_TAB,  HRM_AG,  HRM_RA,  HRM_SS,  HRM_TC,  HRM_DG,                          HRM_HG,  HRM_NC,  HRM_ES,  HRM_IA,  HRM_OG,  KC_QUOT,
    KC_NUBS, BRM_ZG,  BRM_XA,  BRM_CS,  BRM_VC,  BRM_BG,  PL_ECPR,       PL_ECPR, BRM_KG,  BRM_MC,  BRM_COS, BRM_DOA, BRM_SLG, QK_REP,
                      P_HOMMS, KC_LALT, KC_LCTL, P_ENTNA, P_SPCSY,       P_SPCSY, P_ENTNA, KC_RCTL, KC_RALT, P_ENDMS
  ),

  [_G_QWERTY] = LAYOUT(
    P_RAGEQ, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_PSCR,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                            KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    PL_ECPR,       PL_ECPR, KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_ESC,
                      KC_LGUI, KC_LALT, P_NAV,   P_SYM,   KC_ENT,        KC_SPC,  P_MSE,   P_RGB,   KC_RALT, KC_RGUI
  ),

  [_SYM] = LAYOUT(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    _______, _______, _______, _______, _______, KC_F6,                           KC_F7,   _______, _______, _______, _______, KC_DEL,
    KC_BSPC, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, KC_NUHS,
    _______, KC_MINS, KC_EQL,  _______, KC_LCBR, KC_LBRC, PL_ECPR,       PL_ECPR, KC_RBRC, KC_RCBR, _______, _______, _______, QK_AREP,
                      _______, _______, _______, _______, _______,       _______, _______, _______, _______, KC_APP
  ),

  [_NAV] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, KC_DEL,
    _______, _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP,                         KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_PSCR, KC_DEL,
    KC_DEL,  _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                         KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_PIPE,
    _______, KC_UNDS, KC_PLUS, SH_TOGG, KC_LNUM, KC_LCAP, PL_ECPR,       PL_ECPR, KC_LCAP, KC_LNUM, SH_TOGG, _______, _______, QK_AREP,
                      _______, _______, _______, _______, _______,       _______, _______, _______, _______, KC_APP
  ),

  [_MSE] = LAYOUT(
    KC_CAPS, CM_QVER, CM_QRGB, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, CM_QLYR, CM_QTAP, QK_MAKE, CM_QFTR, CM_MSJG,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_LCAP, KC_LNUM, KC_LSCR,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_VOLU, XXXXXXX, KC_LSCR, MS_BTN2, MS_BTN1, MS_BTN3,                         XXXXXXX, KC_LCTL, KC_LSFT, KC_LALT, QK_MAKE, KC_VOLU,
    KC_VOLD, CM_TTAT, XXXXXXX, MS_BTN4, MS_BTN5, KC_LSCR, PL_ECPR,       PL_ECPR, QWERTY,  COLEMAK, G_QWERT, XXXXXXX, XXXXXXX, KC_VOLD,
                      _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
  ),

  [_RGB] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    RM_TOGG, RM_NEXT, RM_HUEU, RM_SATU, RM_VALU, RM_SPDU,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_BRIU, RM_PREV, RM_HUED, RM_SATD, RM_VALD, RM_SPDD,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_BRID, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
  ),

/*
  [_EMPTY] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
  ),
*/

};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY]   = { ENCODER_CCW_CW(PL_ECCC, PL_ECCW),   ENCODER_CCW_CW(PL_ECCC, PL_ECCW) },
    [_COLEMK]   = { ENCODER_CCW_CW(PL_ECCC, PL_ECCW),   ENCODER_CCW_CW(PL_ECCC, PL_ECCW) },
    [_SYM]      = { ENCODER_CCW_CW(PL_ECCC, PL_ECCW),   ENCODER_CCW_CW(PL_ECCC, PL_ECCW) },
    [_NAV]      = { ENCODER_CCW_CW(PL_ECCC, PL_ECCW),   ENCODER_CCW_CW(PL_ECCC, PL_ECCW) },
    [_MSE]      = { ENCODER_CCW_CW(MS_WHLU, MS_WHLU),   ENCODER_CCW_CW(MS_WHLU, MS_WHLU) },
    [_G_QWERTY] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),   ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [_RGB]      = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),   ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    #if defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)
        return OLED_ROTATION_0;
    #else
        if (is_keyboard_master()) {
            return OLED_ROTATION_270;
        }
    #endif // defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)
    return rotation;
}
