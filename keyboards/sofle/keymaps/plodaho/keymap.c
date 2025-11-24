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
    _O_COLEMAK,
    _LOWER,
    _RAISE,
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
    KC_TAB,  HRM_AG,  HRM_SA,  HRM_DS,  HRM_FC,  HRM_GG,                          HRM_HG,  HRM_JC,  HRM_KS,  HRM_LA,  HRM_CG, KC_QUOT,
    KC_NUBS, BRM_ZG,  BRM_XA,  BRM_CS,  BRM_VC,  BRM_BG,  PL_ECPR,       PL_ECPR, BRM_NG,  BRM_MC,  BRM_COS, BRM_DOA, BRM_SLG, QK_REP,
                      P_HOMFC, KC_LALT, KC_LCTL, P_ENTFB, P_SPCFA,       P_SPCFA, P_ENTFB, KC_RCTL, KC_RALT, P_ENDFC
  ),

  [_COLEMAK] = LAYOUT(
    P_RAGEQ, KC_1,    P_F2,    KC_3,    P_F4,    P_F5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                            KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_NUBS, HRM_AG,  HRM_RA,  HRM_SS,  HRM_TC,  HRM_DG,                          HRM_HG,  HRM_NC,  HRM_ES,  HRM_IA,  HRM_OG,  KC_QUOT,
    KC_LSFT, BRM_ZG,  KC_X,    KC_C,    KC_V,    KC_B,    PL_ECPR,       PL_ECPR, KC_K,    KC_M,    KC_COMM, KC_DOT,  BRM_SLG, QK_REP,
                      KC_LGUI, KC_LALT, KC_LCTL, P_ENTFB, P_SPCFA,       P_SPCFA, P_ENTFB, KC_RCTL, KC_RALT, KC_RGUI
  ),

  [_FNA] = LAYOUT(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    KC_CAPS, _______, _______, _______, _______, KC_F6,                           KC_F7,   _______, _______, _______, _______, KC_DEL,
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, KC_NUHS,
    _______, KC_MINS, KC_EQL,  _______, KC_LCBR, KC_LBRC, PL_ECPR,       PL_ECPR, KC_RBRC, KC_RCBR, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______,       _______, _______, _______, _______, KC_APP
  ),

  [_FNB] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, KC_DEL,
    P_TASK,  _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP,                         KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_PSCR, KC_DEL,
    _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                         KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_PIPE,
    _______, KC_UNDS, KC_PLUS, _______, P_PSTU,  _______, PL_ECPR,       PL_ECPR, _______, _______, _______, _______, _______, _______,
                      GU_TOGG, _______, _______, _______, _______,       _______, _______, _______, _______, GU_ON
  ),

  [_FNC] = LAYOUT(
    XXXXXXX, CM_QVER, CM_QRGB, XXXXXXX, XXXXXXX, CM_MSJG,                         CM_MSJG, CM_QLYR, CM_QTAP, QK_MAKE, CM_QFTR, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_LSCR, MS_BTN2, MS_BTN1, MS_BTN3,                         XXXXXXX, KC_LCTL, KC_LSFT, KC_LALT, QK_MAKE, XXXXXXX,
    XXXXXXX, CM_TTAT, XXXXXXX, MS_BTN4, MS_BTN5, KC_LSCR, _______,       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
  ),

  [_O_QWERTY] = LAYOUT(
    KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
    P_RAGEQ,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,       XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                      KC_LGUI, KC_LALT, KC_LCTL, LOWER,   KC_ENT,        KC_SPC,  RAISE,   KC_RCTL, KC_RALT, KC_RGUI
  ),

  [_O_COLEMAK] = LAYOUT(
    KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
    KC_ESC,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                            KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_TAB,   KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                            KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,       XXXXXXX, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                      KC_LGUI, KC_LALT, KC_LCTL, LOWER,   KC_ENT,        KC_SPC,  RAISE,   KC_RCTL, KC_RALT, KC_RGUI
  ),

  [_LOWER] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
    _______, KC_EQL,  KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,       _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                      _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
  ),

  [_RAISE] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, KC_INS,  KC_PSCR, KC_APP,  XXXXXXX, XXXXXXX,                         KC_PGUP, _______, KC_UP,   _______, _______, KC_BSPC,
    _______, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_CAPS,                         KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  KC_BSPC,
    _______, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, XXXXXXX, _______,       _______, XXXXXXX, _______, XXXXXXX, _______, XXXXXXX, _______,
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
    [_QWERTY] =   { ENCODER_CCW_CW(PL_ECCC, PL_ECCW), ENCODER_CCW_CW(PL_ECCC, PL_ECCW) },
    [_COLEMAK] =   { ENCODER_CCW_CW(PL_ECCC, PL_ECCW), ENCODER_CCW_CW(PL_ECCC, PL_ECCW) },
    [_FNA] =    { ENCODER_CCW_CW(PL_ECCC, PL_ECCW), ENCODER_CCW_CW(PL_ECCC, PL_ECCW) },
    [_FNB] =    { ENCODER_CCW_CW(PL_ECCC, PL_ECCW), ENCODER_CCW_CW(PL_ECCC, PL_ECCW) },
    [_FNC] =  { ENCODER_CCW_CW(MS_WHLU, MS_WHLU),    ENCODER_CCW_CW(MS_WHLU, MS_WHLU) },

    [_O_QWERTY] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),    ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [_O_COLEMAK] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),    ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [_LOWER] =  { ENCODER_CCW_CW(RM_HUED, RM_HUEU),    ENCODER_CCW_CW(RM_SATD, RM_SATU) },
    [_RAISE] =  { ENCODER_CCW_CW(RM_VALD, RM_VALU),    ENCODER_CCW_CW(RM_PREV, RM_NEXT) },
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
