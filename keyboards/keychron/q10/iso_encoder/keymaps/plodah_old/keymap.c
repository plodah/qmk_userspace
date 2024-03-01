#include QMK_KEYBOARD_H

// clang-format off

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define KC_MC00 QK_MACRO_0
#define KC_MC01 QK_MACRO_1
#define KC_MC02 QK_MACRO_2
#define KC_MC03 QK_MACRO_3
#define KC_MC04 QK_MACRO_4
#define KC_MC05 QK_MACRO_5
#define KC_MC06 QK_MACRO_6
#define KC_MC07 QK_MACRO_7
#define KC_MC08 QK_MACRO_8
#define KC_MC09 QK_MACRO_9
#define KC_MC10 QK_MACRO_10
#define KC_MC11 QK_MACRO_11
#define KC_MC12 QK_MACRO_12
#define KC_MC13 QK_MACRO_13
#define KC_MC14 QK_MACRO_14
#define KC_MC15 QK_MACRO_15

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_iso_90(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,            KC_DEL,
        _______,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_HOME,
        _______,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,                      KC_PGUP,
        _______,  MO(1),    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,             KC_PGDN,
        KC_END,   KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        KC_HOME,  KC_LCTL,  KC_LGUI,            KC_LALT,  LT(1,KC_SPC),   KC_RALT,               LT(2,KC_SPC),         KC_RCTL,                     KC_LEFT,  KC_DOWN,  KC_RGHT),

    [1] = LAYOUT_iso_90(
        RGB_TOG,  _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,   KC_VOLU,  _______,            _______,
        _______,  _______,  KC_P1,    KC_P2,    KC_P3,    KC_P4,    KC_P5,     KC_P6,    KC_P7,    KC_P8,    KC_P9,    KC_P0,    _______,   _______,  _______,            KC_END,
        _______,  RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  KC_PSCR,  _______,   _______,                      _______,
        _______,  KC_CAPS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______, S(C(KC_V)),  _______, _______,  NK_TOGG,  _______,  _______,  _______,   _______,  _______,  KC_VOLU,
        _______,  _______,  GU_TOGG,            _______,  KC_SPC,  _______,                       KC_SPC,            KC_APP,                       KC_HOME,  KC_VOLD,  KC_END),

    [2] = LAYOUT_iso_90(
        _______,  _______,  KC_F13,   KC_F14,   KC_F15,   KC_F16,   KC_F17,   KC_F18,   KC_F19,   KC_F20,   KC_F21,   KC_F22,   KC_F23,   KC_F24,   _______,            _______,
        _______,  KC_MC00,  KC_MC01,  KC_MC02,  KC_MC03,  KC_MC04,  KC_MC05,  KC_MC06,  KC_MC07,  KC_MC08,  KC_MC09,  KC_MC10,  KC_MC11,  KC_MC12,  _______,            KC_END,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PSCR,  _______,  _______,                      _______,
        _______,  KC_CAPS,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,             _______,
        _______,  _______,  _______,  _______,  KC_BTN1,  KC_BTN1,  KC_BTN1,  KC_BTN1,  KC_BTN1,  KC_BTN1,  KC_BTN1,  KC_BTN1,  _______,  _______,  _______,  KC_VOLU,
        _______,  _______,  GU_TOGG,            _______,  KC_SPC,  _______,                   KC_SPC,             KC_APP,                      KC_HOME,  KC_VOLD,  KC_END),

    [3] = LAYOUT_iso_90(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_DEL,
        _______,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_HOME,
        _______,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,                      KC_PGUP,
        _______,  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,             KC_PGDN,
        _______,  KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        _______,  KC_LCTL,  KC_LGUI,            KC_LALT,  KC_SPC,     KC_RALT,                KC_SPC,             KC_RCTL,                     KC_LEFT,  KC_DOWN,  KC_RGHT)
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
	[0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
	[1] = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
	[2] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
	[3] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}
};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
