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
    // PL_DMAC1,
    // PL_DMAC2,
    // PL_ECCC,
    // PL_ECCW,
    // PL_ECPR,
    // PL_MSJG,
    // PL_QFTR,
    // PL_QLYR,
    // PL_QRGB,
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_65_iso_blocker(P_RAGEQ, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_DEL, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_HOME, LT(3,KC_BSPC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT, KC_PGUP, KC_LSFT, KC_NUBS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_PGDN, KC_LCTL, KC_LGUI, KC_LALT, LT(2,KC_SPC), KC_RALT, LT(3,KC_APP), KC_LEFT, KC_DOWN, KC_RGHT),
    [1] = LAYOUT_65_iso_blocker(P_RAGEQ, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_DEL, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_HOME, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT, KC_PGUP, KC_LSFT, KC_NUBS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_PGDN, KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(2), KC_LEFT, KC_DOWN, KC_RGHT),
    [2] = LAYOUT_65_iso_blocker(KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, _______, KC_ENT, KC_PGUP, KC_UP, KC_PGDN, _______, _______, _______, _______, _______, _______, KC_PSCR, _______, _______, KC_END, KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, _______, _______, _______, KC_PGUP, _______, _______, GU_TOGG, _______, KC_SPC, _______, _______, KC_HOME, KC_PGDN, KC_END),
    [3] = LAYOUT_65_iso_blocker(KC_GRV, MC_1, MC_2, MC_3, MC_4, MC_5, MC_6, MC_7, MC_8, PL_QFTR, PL_QRGB, PL_QVER, QK_MAKE, KC_DEL, _______, RM_TOGG, RM_NEXT, RM_VALU, RM_HUEU, RM_SATU, RM_SPDU, _______, _______, _______, _______, KC_PSCR, _______, _______, KC_END, KC_CAPS, RM_PREV, RM_VALD, RM_HUED, RM_SATD, RM_SPDD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, C(S(KC_V)), _______, NK_TOGG, _______, _______, _______, _______, _______, KC_VOLU, _______, _______, GU_TOGG, _______, KC_SPC, _______, _______, KC_HOME, KC_VOLD, KC_END)
};
