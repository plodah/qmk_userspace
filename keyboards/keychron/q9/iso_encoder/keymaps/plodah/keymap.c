#include QMK_KEYBOARD_H

enum layers {
    _QWEA,
    _SUPP,
    _FNA,
    _FNB,
};

enum keymap_keycodes {
    PL_DMAC1 = QK_USER_0,
    PL_DMAC2,
    PL_ECCC,
    PL_ECCW,
    PL_ECPR,
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
	[_QWEA] = LAYOUT_iso_53(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, PL_ECPR,
        P_BSPFA, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,  KC_BSPC,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, P_RSFTB, KC_UP,
        KC_LCTL, KC_LWIN, KC_LALT,                            P_SPCSP,                   KC_RALT, P_APPFA, P_FNB,   KC_LEFT, KC_DOWN, KC_RGHT
    ),
	[_SUPP] = LAYOUT_iso_53(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  PL_ECPR,
        KC_DEL,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC, KC_DEL,
        _______, _______, _______, MS_BTN1, MS_BTN1, MS_BTN1, MS_BTN1, MS_BTN1, MS_BTN1, MS_BTN1, _______, _______, _______, KC_VOLU,
        _______, _______, P_FNA,                              KC_SPC,                    _______, _______, P_TMGR,  KC_HOME, KC_VOLD, KC_END
    ),
	[_FNA] = LAYOUT_iso_53(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  PL_ECPR,
        MC_0,    MC_1,    MC_2,    MC_3,    MC_4,    MC_5,    MC_6,    MC_7,    MC_8,    CM_QFTR, CM_QRGB, CM_QVER, QK_MAKE, KC_BSPC, KC_PSCR,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            KC_SPC,                    _______, _______, P_TMGR,  _______, _______, _______
    ),
	[_FNB] = LAYOUT_iso_53(
        RM_TOGG, RM_NEXT, RM_VALU, RM_HUEU, RM_SATU, RM_SPDU, _______, _______, _______, _______, KC_PSCR, _______, _______, PL_ECPR,
        KC_CAPS, RM_PREV, RM_VALD, RM_HUED, RM_SATD, RM_SPDD, _______, _______, _______, _______, _______, _______, _______, P_TMGR,  KC_PSCR,
        _______, _______, _______, _______, _______, P_PSTU,  _______, NK_TOGG, _______, _______, _______, _______, _______, KC_PGUP,
        _______, _______, _______,                            _______,                   _______, _______, _______, KC_HOME, KC_PGDN, KC_END
    ),
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWEA] = {ENCODER_CCW_CW(PL_ECCC, PL_ECCW)},
    [_SUPP] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FNA]  = {ENCODER_CCW_CW(PL_ECCC, PL_ECCW)},
    [_FNB]  = {ENCODER_CCW_CW(PL_ECCC, PL_ECCW)},
};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
