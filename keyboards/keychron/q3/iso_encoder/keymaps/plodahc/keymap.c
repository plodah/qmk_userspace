#include QMK_KEYBOARD_H

enum keymap_keycodes {
    PL_ALTTAB = QK_USER_0,
    PL_ALTSTAB,
    PL_EC_CCW,
    PL_EC_CW,
    PL_EC_PR,
    PL_QFTR,
    PL_QRGB,
    PL_QVER,
};

enum {
    TD_ESC_RAGEQUIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_tkl_f13_iso(TD(TD_ESC_RAGEQUIT), KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, PL_EC_PR, LCA(KC_DEL), KC_MPLY, RGB_TOG, KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_PSCR, KC_HOME, KC_PGUP, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_DEL, KC_END, KC_PGDN, LT(3,KC_BSPC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT, KC_LSFT, KC_NUBS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_LCTL, KC_LGUI, KC_LALT, LT(2,KC_SPC), KC_RALT, KC_RGUI, LT(3,KC_APP), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),
	[1] = LAYOUT_tkl_f13_iso(TD(TD_ESC_RAGEQUIT), KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_MUTE, KC_PSCR, KC_F13, RGB_TOG, KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_INS, KC_HOME, KC_PGUP, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_DEL, KC_END, KC_PGDN, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT, KC_LSFT, KC_NUBS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_RGUI, MO(3), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),
    [2] = LAYOUT_tkl_f13_iso(_______, KC_BRID, KC_BRIU, G(KC_TAB), G(KC_E), RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, PL_EC_PR, C(KC_F4), C(S(KC_T)), _______, _______, KC_P1, KC_P2, KC_P3, KC_P4, KC_P5, KC_P6, KC_P7, KC_P8, KC_P9, KC_P0, _______, _______, KC_DEL, KC_INS, _______, _______, KC_ENT, KC_PGUP, KC_UP, KC_PGDN, _______, _______, _______, _______, _______, _______, KC_PSCR, _______, _______, _______, _______, _______, KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, _______, _______, CW_TOGG, KC_PGUP, _______, GU_TOGG, _______, KC_SPC, _______, GU_TOGG, _______, _______, KC_HOME, KC_PGDN, KC_END),
    [3] = LAYOUT_tkl_f13_iso(_______, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24, PL_EC_PR, C(KC_F4), C(S(KC_T)), _______, MC_0, MC_1, MC_2, MC_3, MC_4, MC_5, MC_6, MC_7, MC_8, PL_QFTR, PL_QRGB, PL_QVER, QK_MAKE, _______, KC_INS, _______, _______, RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, KC_PSCR, _______, _______, _______, DF(3), _______, KC_CAPS, RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, DM_RSTP, DM_REC1, DM_REC2, _______, _______, _______, _______, _______, _______, _______, _______, C(S(KC_V)), _______, NK_TOGG, _______, _______, DM_PLY1, DM_PLY2, _______, KC_VOLU, _______, GU_TOGG, _______, KC_SPC, _______, GU_TOGG, _______, _______, KC_HOME, KC_VOLD, KC_END)
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
	[0] = {ENCODER_CCW_CW(PL_EC_CCW, PL_EC_CW)},
	[1] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
	[2] = {ENCODER_CCW_CW(PL_EC_CCW, PL_EC_CW)},
	[3] = {ENCODER_CCW_CW(PL_EC_CCW, PL_EC_CW)}
};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
