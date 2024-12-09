#include QMK_KEYBOARD_H

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */
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
	[0] = LAYOUT_iso_53(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, PL_EC_PR, LT(2,KC_BSPC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT, KC_BSPC, KC_LSFT, KC_NUBS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_BSPC), KC_UP, KC_LCTL, KC_LWIN, KC_LALT, LT(1,KC_SPC), KC_RALT, LT(2,KC_APP), MO(3), KC_LEFT, KC_DOWN, KC_RGHT),
	[1] = LAYOUT_iso_53(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, PL_EC_PR, KC_DEL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC, KC_DEL, _______, _______, _______, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, _______, _______, _______, KC_VOLU, _______, _______, MO(2), KC_SPC, _______, _______, LCA(KC_DEL), KC_HOME, KC_VOLD, KC_END),
	[2] = LAYOUT_iso_53(KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, PL_EC_PR, MC_0, MC_1, MC_2, MC_3, MC_4, MC_5, MC_6, MC_7, MC_8, PL_QFTR, PL_QRGB, PL_QVER, QK_MAKE, KC_BSPC, KC_PSCR, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SPC, _______, _______, LCA(KC_DEL), _______, _______, _______),
	[3] = LAYOUT_iso_53(RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, KC_PSCR, _______, _______, PL_EC_PR, KC_CAPS, RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______, _______, _______, LCA(KC_DEL), KC_PSCR, _______, _______, _______, _______, _______, C(S(KC_V)), _______, NK_TOGG, _______, _______, _______, _______, _______, KC_PGUP, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END)
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
	[0] = {ENCODER_CCW_CW(PL_EC_CCW, PL_EC_CW)},
	[1] = {ENCODER_CCW_CW(PL_EC_CCW, PL_EC_CW)},
	[2] = {ENCODER_CCW_CW(PL_EC_CCW, PL_EC_CW)},
	[3] = {ENCODER_CCW_CW(PL_EC_CCW, PL_EC_CW)}
};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)



