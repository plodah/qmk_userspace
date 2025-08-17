#include QMK_KEYBOARD_H

enum layers {
    _QWEA,
    _QWEB,
    _FNA,
    _FNB,
};

/*
enum keymap_keycodes {
    // PL_DMAC1,
    // PL_DMAC2,
    PL_ECCC = QK_USER_0,
    PL_ECCW,
    PL_ECPR,
    PL_SCRL,
};
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWEA] = LAYOUT_60_iso_split_bs_rshift(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, XXXXXXX,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
        P_BSPFB, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_HOME,
        KC_LCTL, KC_LGUI, KC_LALT,                            P_SPCFA,                            KC_RALT, P_APPFB, KC_RGUI, KC_RCTL
    ),
    [1] = LAYOUT_60_iso_split_bs_rshift(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, XXXXXXX,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_HOME,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, P_FNA,   KC_RGUI, KC_RCTL
    ),
    [_FNA] = LAYOUT_60_iso_split_bs_rshift(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  XXXXXXX,
        KC_ENT,  KC_PGUP, KC_UP,   KC_PGDN, _______, _______, _______, _______, _______, _______, KC_PSCR, _______, _______,
        KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, MS_BTN1, MS_BTN1, MS_BTN1, MS_BTN1, MS_BTN1, MS_BTN1, MS_BTN1, _______, KC_HOME, KC_UP,   KC_END,
        _______, GU_TOGG, _______,                            KC_SPC,                             _______, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_FNB] = LAYOUT_60_iso_split_bs_rshift(
        KC_GRV,  MC_1,    MC_2,    MC_3,    MC_4,    MC_5,    MC_6,    MC_7,    MC_8,    CM_QFTR, CM_QRGB, CM_QVER, QK_MAKE, KC_MUTE, XXXXXXX,
        _______, _______, KC_VOLU, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, _______, _______,
        KC_CAPS, KC_HOME, KC_VOLD, KC_END,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, P_PSTU,  _______, NK_TOGG, _______, _______, _______, KC_HOME, _______, KC_END,
        _______, GU_TOGG, _______,                            KC_SPC ,                            _______, _______, _______, _______
    )
};
