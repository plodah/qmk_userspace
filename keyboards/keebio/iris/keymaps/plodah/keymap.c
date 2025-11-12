#include QMK_KEYBOARD_H

enum sofle_layers {
    _QWERTY,
    _QWEB,
    _FNA,
    _FNB,
    _FNC,
};

/*
enum keymap_keycodes {
    // PL_DMAC1 = QK_USER_0,
    // PL_DMAC2,
    // PL_ECCC,
    // PL_ECCW,
    // PL_ECPR
};
*/

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
        P_RAGEQ, KC_1,    P_F2,    KC_3,    P_F4,    P_F5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        P_BSCTL, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  HRM_AG,  HRM_SA,  HRM_DS,  HRM_FC,  HRM_GG,                    HRM_HG,  HRM_JC,  HRM_KS,  HRM_LA,  HRM_CG,  KC_QUOT,
        KC_NUBS, BRM_ZG,  BRM_XA,  BRM_CS,  BRM_VC,  BRM_BG,  XXXXXXX, XXXXXXX, BRM_NG,  BRM_MC,  BRM_COS, BRM_DOA, BRM_SLG, QK_REP,
                                            P_HOMFC, P_ENTFB, P_SPCFA, P_SPCFA, P_ENTFB, P_ENDFC
    ),
    [_QWEB] = LAYOUT(
        P_RAGEQ, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
        KC_NUBS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                            KC_LCTL, P_ENTFB, P_SPCFA, P_SPCFA, P_ENTFB, KC_RCTL
    ),
    [_FNA] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        KC_DEL,  _______, _______, _______, _______, KC_F6,                     KC_F7,   _______, _______, _______, _______, KC_DEL,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, KC_NUHS,
        _______, KC_MINS, KC_EQL,  _______, KC_LCBR, KC_LBRC, XXXXXXX, XXXXXXX, KC_RBRC, KC_RCBR, _______, _______, _______, QK_AREP,
                                            _______, _______, _______, _______, _______, KC_APP
    ),
    [_FNB] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, KC_DEL,
        _______, _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_PSCR, KC_DEL,
        KC_DEL,  _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_PIPE,
        _______, KC_UNDS, KC_PLUS, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, QK_AREP,
                                            _______, _______, _______, _______, _______,  KC_APP

    ),

    [_FNC] = LAYOUT(
        KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CM_MSJG,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_VOLU, XXXXXXX, KC_LSCR, MS_BTN2, MS_BTN1, MS_BTN3,                   XXXXXXX, KC_LCTL, KC_LSFT, KC_LALT, QK_MAKE, KC_VOLU,
        KC_VOLD, XXXXXXX, XXXXXXX, MS_BTN4, MS_BTN5, KC_LSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD,
                                            _______, _______, _______, _______, _______, _______

    )/*,
    [4] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______, _______, _______, _______
    )*/
};
