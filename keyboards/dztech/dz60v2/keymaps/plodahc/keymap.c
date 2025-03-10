#include QMK_KEYBOARD_H

enum layers {
    _QWEA,
    _QWEB,
    _FNA,
    _FNB,
    //_QWEHRM,
};

enum keymap_keycodes {
    PL_DMAC1 = QK_USER_0,
    PL_DMAC2,
    // PL_ECCC,
    // PL_ECCW,
    // PL_ECPR
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
    [_QWEA] = LAYOUT_60_b_iso(
        P_RAGEQ, KC_1,    P_F2,    KC_3,    P_F4,    P_F5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    P_F11,   P_F12,   XXXXXXX, KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
        P_BSPFB, KC_A,    KC_S,    HRM_DS,  HRM_FC,  KC_G,    KC_H,    HRM_JC,  HRM_KS,  KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  P_SFTSL,          KC_UP,   KC_SLSH,
        KC_LCTL, KC_LGUI, KC_LALT,          P_SPCFA,          P_SPCFB,          P_SPCFA,          P_ALAPP, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_QWEB] = LAYOUT_60_b_iso(
        P_RAGEQ, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXXXXX, KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSFT,          KC_UP,   KC_SLSH,
        KC_LCTL, KC_LGUI, KC_LALT,          KC_SPC,           P_FNA,            KC_SPC,           KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_FNA] = LAYOUT_60_b_iso(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, KC_DEL,
        KC_ENT,  KC_PGUP, KC_UP,   KC_PGDN, _______, _______, _______, _______, _______, _______, KC_PSCR, _______, _______,
        KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, _______, CW_TOGG,          KC_PGUP, _______,
        _______, GU_TOGG, _______,          KC_SPC,           KC_SPC,           KC_SPC,           _______, _______, KC_HOME, KC_PGDN, KC_END
    ),
    [_FNB] = LAYOUT_60_b_iso(
        KC_GRV, PL_DMAC1, PL_DMAC2, MC_3,   MC_4,    MC_5,    MC_6,    MC_7,    MC_8,    CM_QLYR, CM_QVER, CM_MSJG, QK_MAKE, XXXXXXX, KC_DEL,
        BL_TOGG, BL_BRTG, BL_UP,   _______, _______, _______, _______, _______, _______, _______, KC_PSCR, _______, _______,
        KC_CAPS, BL_BRTG, BL_DOWN, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, P_PSTU,  _______, NK_TOGG, _______, _______, _______, _______,          KC_VOLU, _______,
        _______, GU_TOGG, _______,          KC_SPC,           KC_SPC,           KC_SPC,           KC_APP,  _______, KC_HOME, KC_VOLD, KC_END
    ),
    /*
    [_QWEHRM] = LAYOUT_60_b_iso(
        P_RAGEQ, KC_1,    P_F2,    KC_3,    P_F4,    P_F5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    P_F11,   P_F12,   XXXXXXX, KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
        P_BSPFB, HRM_AG,  HRM_SA,  HRM_DS,  HRM_FC,  HRM_GG,  HRM_HG,  HRM_JC,  HRM_KS,  HRM_LA,  HRM_CG,  KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  P_SFTSL,          KC_UP,   KC_SLSH,
        KC_LCTL, KC_LGUI, KC_LALT,          P_SPCFA,          P_SPCFB,          P_SPCFA,          P_ALAPP, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    */
    /*
    [4] = LAYOUT_60_b_iso(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,          _______,          _______,          _______,          _______, _______, _______, _______, _______
    )
    */
};
