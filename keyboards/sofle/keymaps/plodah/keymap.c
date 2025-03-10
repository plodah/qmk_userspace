// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum layers {
    _QWEA,
    _COLA,
    _FNA,
    _FNB,
    _O_QWEA,
    _O_COLE,
    _O_FNA,
    _O_FNB,
    _MOUSE,
};

enum keymap_keycodes {
    // PL_DMAC1,
    // PL_DMAC2,
    PL_ECCC = QK_USER_0,
    PL_ECCW,
    PL_ECPR,
    PL_SCRL,
};

enum {
    TD_ESC_RAGEQUIT,
    TD_F2,
    TD_F4,
    TD_F5,
    TD_F11,
    TD_F12,
};

#define O_FNA MO(_O_FNA)
#define O_FNB MO(_O_FNB)
#define MOUSE MO(_MOUSE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWEA] = LAYOUT(
    P_RAGEQ, KC_1,    P_F2,    KC_3,    P_F4,    P_F5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NUHS,
    KC_BSPC, KC_A,    HRM_SA,  HRM_DS,  HRM_FC,  HRM_GG,                          HRM_HG,  HRM_JC,  HRM_KS,  HRM_LA,  KC_SCLN, KC_QUOT,
    KC_NUBS, HRM_ZG,  KC_X,    KC_C,    KC_V,    KC_B,    PL_ECPR,       PL_ECPR, KC_N,    KC_M,    KC_COMM, KC_DOT,  HRM_SLG, KC_RSFT,
                      MOUSE,   KC_LALT, KC_LCTL, P_ENTFB, P_SPCFA,       P_SPCFA, P_ENTFB, KC_RCTL, KC_RALT, MOUSE
  ),
/*
  [_QWEA] = LAYOUT(
    P_RAGEQ, KC_1,    P_F2,    KC_3,    P_F4,    P_F5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NUHS,
    KC_NUBS, HRM_AG,  HRM_SA,  HRM_DS,  HRM_FC,  HRM_GG,                          HRM_HG,  HRM_JC,  HRM_KS,  HRM_LA,  HRM_CG,  KC_QUOT,
    KC_LSFT, HRM_ZG,  KC_X,    KC_C,    KC_V,    KC_B,    PL_ECPR,       PL_ECPR, KC_N,    KC_M,    KC_COMM, KC_DOT,  HRM_SLG, KC_RSFT,
                      KC_LGUI, KC_LALT, KC_LCTL, P_ENTFB, P_SPCFA,       P_SPCFA, P_ENTFB, KC_RCTL, KC_RALT, KC_RGUI
  ),
*/
/*
  [_QWEA] = LAYOUT(
    P_RAGEQ, KC_1,    P_F2,    KC_3,    P_F4,    P_F5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NUHS,
    KC_NUBS, HRM_AG,  HRM_SA,  HRM_DS,  HRM_FC,  HRM_GG,                          HRM_HG,  HRM_JC,  HRM_KS,  HRM_LA,  HRM_CG,  KC_QUOT,
    KC_LSFT, HRM_ZG,  KC_X,    KC_C,    KC_V,    KC_B,    PL_ECPR,       PL_ECPR, KC_N,    KC_M,    KC_COMM, KC_DOT,  HRM_SLG, KC_RSFT,
                      KC_LGUI, KC_LALT, KC_LCTL, P_ENTFB, P_SPCFA,       P_SPCFA, P_ENTFB, KC_RCTL, KC_RALT, KC_RGUI
  ),
*/

  [_COLA] = LAYOUT(
    P_RAGEQ, KC_1,    P_F2,    KC_3,    P_F4,    P_F5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                            KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_NUHS,
    KC_NUBS, HRM_AG,  HRM_RA,  HRM_SS,  HRM_TC,  HRM_DG,                          HRM_HG,  HRM_NC,  HRM_ES,  HRM_IA,  HRM_OG,  KC_QUOT,
    KC_LSFT, HRM_ZG,  KC_X,    KC_C,    KC_V,    KC_B,    PL_ECPR,       PL_ECPR, KC_K,    KC_M,    KC_COMM, KC_DOT,  HRM_SLG, KC_RSFT,
                      KC_LGUI, KC_LALT, KC_LCTL, P_ENTFB, P_SPCFA,       P_SPCFA, P_ENTFB, KC_RCTL, KC_RALT, KC_RGUI
  ),

  [_FNA] = LAYOUT(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    KC_CAPS, _______, _______, _______, _______, KC_F6,                           KC_F7,   _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, KC_MINS, KC_EQL,  _______, KC_LCBR, KC_LBRC, PL_ECPR,       PL_ECPR, KC_RBRC, KC_RCBR, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______,       _______, _______, _______, _______, KC_APP
  ),

  [_FNB] = LAYOUT(
    KC_BSPC, CM_QVER, CM_QRGB, _______, _______, CM_MSJG,                         CM_MSJG, CM_QLYR, CM_QTAP, QK_MAKE, CM_QFTR, KC_DEL,
    P_TASK,  _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP,                         KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_PSCR, _______,
    _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                         KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
    _______, KC_UNDS, KC_PLUS, _______, P_PSTU,  _______, PL_ECPR,       PL_ECPR, _______, _______, _______, _______, _______, _______,
                      GU_TOGG, _______, _______, _______, _______,       _______, _______, _______, _______, GU_ON
  ),

  [_O_QWEA] = LAYOUT(
    KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
    P_RAGEQ,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,       XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                      KC_LGUI, KC_LALT, KC_LCTL, O_FNA,   KC_ENT,        KC_SPC,  O_FNB,   KC_RCTL, KC_RALT, KC_RGUI
  ),

  [_O_COLE] = LAYOUT(
    KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
    KC_ESC,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                            KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_TAB,   KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                            KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,       XXXXXXX, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                      KC_LGUI, KC_LALT, KC_LCTL, O_FNA,   KC_ENT,        KC_SPC,  O_FNB,   KC_RCTL, KC_RALT, KC_RGUI
  ),

  [_O_FNA] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
    _______, KC_EQL,  KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,       _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                      _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
  ),

  [_O_FNB] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, KC_INS,  KC_PSCR, KC_APP,  XXXXXXX, XXXXXXX,                         KC_PGUP, _______, KC_UP,   _______, _______, KC_BSPC,
    _______, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_CAPS,                         KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  KC_BSPC,
    _______, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, XXXXXXX, _______,       _______, XXXXXXX, _______, XXXXXXX, _______, XXXXXXX, _______,
                      _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
  ),

  [_MOUSE] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_SCRL, KC_SCRL, PL_SCRL, PL_SCRL, KC_SCRL,                         KC_SCRL, PL_SCRL, PL_SCRL, KC_SCRL, KC_SCRL, XXXXXXX,
    XXXXXXX, MS_BTN4, MS_BTN5, MS_BTN2, MS_BTN1, MS_BTN3,                         MS_BTN3, MS_BTN1, MS_BTN2, MS_BTN4, MS_BTN5, XXXXXXX,
    XXXXXXX, MS_BTN4, MS_BTN5, MS_BTN2, MS_BTN1, MS_BTN3, XXXXXXX,       XXXXXXX, MS_BTN3, MS_BTN1, MS_BTN2, MS_BTN4, MS_BTN5, XXXXXXX,
                      _______, MS_BTN2, MS_BTN1, _______, _______,       _______, _______, MS_BTN1, MS_BTN2, _______
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

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _FNA, _FNB, _MOUSE);
}

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWEA] =   { ENCODER_CCW_CW(PL_ECCC, PL_ECCW), ENCODER_CCW_CW(PL_ECCC, PL_ECCW) },
    [_COLA] =   { ENCODER_CCW_CW(PL_ECCC, PL_ECCW), ENCODER_CCW_CW(PL_ECCC, PL_ECCW) },
    [_FNA] =    { ENCODER_CCW_CW(PL_ECCC, PL_ECCW), ENCODER_CCW_CW(PL_ECCC, PL_ECCW) },
    [_FNB] =    { ENCODER_CCW_CW(PL_ECCC, PL_ECCW), ENCODER_CCW_CW(PL_ECCC, PL_ECCW) },

    [_O_QWEA] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),    ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [_O_COLE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),    ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [_O_FNA] =  { ENCODER_CCW_CW(RM_HUED, RM_HUEU),    ENCODER_CCW_CW(RM_SATD, RM_SATU) },
    [_O_FNB] =  { ENCODER_CCW_CW(RM_VALD, RM_VALU),    ENCODER_CCW_CW(RM_PREV, RM_NEXT) },
    [_MOUSE] =  { ENCODER_CCW_CW(MS_WHLU, MS_WHLU),    ENCODER_CCW_CW(MS_WHLU, MS_WHLU) },
};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
