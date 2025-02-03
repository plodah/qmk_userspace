#include QMK_KEYBOARD_H

enum layers {
    _QWEA,
    _QWEB,
    _FNA,
    _FNB,
};

enum keymap_keycodes {
    PL_TSKA = QK_USER_0,
    PL_TSKB,
    PL_DMAC1,
    PL_DMAC2,
    // PL_DRAG_SCROLL_MOMENTARY,
    // PL_DRAG_SCROLL_TOGGLE,
    PL_ECCC,
    PL_ECCW,
    PL_ECPR,
    PL_MSJG,
    PL_QFTR,
    PL_QLYR,
    PL_QRGB,
    // PL_QTAP,
    PL_QVER,
};

enum {
    TD_ESC_RAGEQUIT,
    TD_F2,
    TD_F4,
    TD_F5,
    TD_F11,
    TD_F12,
};

#define P_RAGEQ TD(TD_ESC_RAGEQUIT)
#define P_F2 TD(TD_F2)
#define P_F4 TD(TD_F4)
#define P_F5 TD(TD_F5)
#define P_F11 TD(TD_F11)
#define P_F12 TD(TD_F12)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_iso_53(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, PL_ECPR,  LT(2,KC_BSPC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT, KC_BSPC, KC_LSFT, KC_NUBS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_BSPC), KC_UP, KC_LCTL, KC_LWIN, KC_LALT, LT(1,KC_SPC), KC_RALT, LT(2,KC_APP), MO(3), KC_LEFT, KC_DOWN, KC_RGHT),
	[1] = LAYOUT_iso_53(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, PL_ECPR,  KC_DEL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC, KC_DEL, _______, _______, _______, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, _______, _______, _______, KC_VOLU, _______, _______, MO(2), KC_SPC, _______, _______, LCA(KC_DEL), KC_HOME, KC_VOLD, KC_END),
	[2] = LAYOUT_iso_53(KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, PL_ECPR,  MC_0, MC_1, MC_2, MC_3, MC_4, MC_5, MC_6, MC_7, MC_8, PL_QFTR, PL_QRGB, PL_QVER, QK_MAKE, KC_BSPC, KC_PSCR, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SPC, _______, _______, LCA(KC_DEL), _______, _______, _______),
	[3] = LAYOUT_iso_53(RM_TOGG, RM_NEXT, RM_VALU, RM_HUEU, RM_SATU, RM_SPDU, _______, _______, _______, _______, KC_PSCR, _______, _______, PL_ECPR,  KC_CAPS, RM_PREV, RM_VALD, RM_HUED, RM_SATD, RM_SPDD, _______, _______, _______, _______, _______, _______, _______, LCA(KC_DEL), KC_PSCR, _______, _______, _______, _______, _______, C(S(KC_V)), _______, NK_TOGG, _______, _______, _______, _______, _______, KC_PGUP, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END)
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
	[0] = {ENCODER_CCW_CW(PL_ECCC, PL_ECCW)},
	[1] = {ENCODER_CCW_CW(PL_ECCC, PL_ECCW)},
	[2] = {ENCODER_CCW_CW(PL_ECCC, PL_ECCW)},
	[3] = {ENCODER_CCW_CW(PL_ECCC, PL_ECCW)}
};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)



