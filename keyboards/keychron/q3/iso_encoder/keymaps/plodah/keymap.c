#include QMK_KEYBOARD_H

enum layers {
    _QWEA,
    _QWEB,
    _FNA,
    _FNB,
};

enum keymap_keycodes {
    // PL_DMAC1,
    // PL_DMAC2,
    PL_ECCC = QK_USER_0,
    PL_ECCW,
    PL_ECPR
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
	[_QWEA] = LAYOUT_tkl_f13_iso(
        P_RAGEQ, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  PL_ECPR,     P_TMGR,  KC_MPLY, RM_TOGG,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,     KC_PSCR, KC_HOME, KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,              KC_DEL,  KC_END,  KC_PGDN,
        P_BSPFB, HRM_AG,  HRM_SA,  HRM_DS,  HRM_FC,  HRM_GG,  HRM_HG,  HRM_JC,  HRM_KS,  HRM_LA,  HRM_CG,  KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                       KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                            P_SPCFA,                            KC_RALT, KC_RGUI, P_APPFB, KC_RCTL,     KC_LEFT, KC_DOWN, KC_RGHT
    ),
	[_QWEB] = LAYOUT_tkl_f13_iso(
        P_RAGEQ, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_MUTE,     KC_PSCR, KC_F13,  RM_TOGG,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL, KC_BSPC,      KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,              KC_DEL,  KC_END,  KC_PGDN,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                       KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI, P_FNB,   KC_RCTL,     KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_FNA] = LAYOUT_tkl_f13_iso(
        _______, KC_BRID, KC_BRIU, P_TASK,  G(KC_E), RM_VALD, RM_VALU, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, PL_ECPR,     P_XTAB,  P_RTAB,  _______,
        _______, KC_P1,   KC_P2,   KC_P3,   KC_P4,   KC_P5,   KC_P6,   KC_P7,   KC_P8,   KC_P9,   KC_P0,   _______, _______, KC_DEL,      KC_INS,  _______, _______,
        KC_ENT,  KC_PGUP, KC_UP,   KC_PGDN, _______, _______, _______, _______, _______, _______, KC_PSCR, _______, _______,              _______, _______, _______,
        KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, _______, _______, _______,                       KC_PGUP,
        _______, GU_TOGG, _______,                            KC_SPC,                             _______, GU_TOGG, _______, _______,     KC_HOME, KC_PGDN, KC_END
    ),
    [_FNB] = LAYOUT_tkl_f13_iso(
        _______, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  PL_ECPR,     P_XTAB,  P_RTAB,  _______,
        MC_0,    MC_1,    MC_2,    MC_3,    MC_4,    MC_5,    MC_6,    MC_7,    MC_8,    CM_QFTR, CM_QRGB, CM_QVER, QK_MAKE, _______,     KC_INS, _______, _______,
        RM_TOGG, RM_NEXT, RM_VALU, RM_HUEU, RM_SATU, RM_SPDU, _______, _______, _______, _______, KC_PSCR, _______, _______,              _______, _______, _______,
        KC_CAPS, RM_PREV, RM_VALD, RM_HUED, RM_SATD, RM_SPDD, _______, _______, DM_RSTP, DM_REC1, DM_REC2, _______, _______, _______,
        _______, _______, _______, _______, _______, P_PSTU,  _______, NK_TOGG, _______, _______, DM_PLY1, DM_PLY2, _______,                       KC_VOLU,
        _______, GU_TOGG, _______,                            KC_SPC,                             _______, GU_TOGG, _______, _______,     KC_HOME, KC_VOLD, KC_END
    )
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWEA] = {ENCODER_CCW_CW(PL_ECCC, PL_ECCW)},
    [_QWEB] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FNA]  = {ENCODER_CCW_CW(PL_ECCC, PL_ECCW)},
    [_FNB]  = {ENCODER_CCW_CW(PL_ECCC, PL_ECCW)},
};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
