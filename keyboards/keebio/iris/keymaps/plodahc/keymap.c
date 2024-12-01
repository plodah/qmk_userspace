#include QMK_KEYBOARD_H

enum keymap_keycodes {
    PL_ALTTAB = QK_USER_0,
    PL_ALTSTAB,
    PL_QFTR,
    PL_QRGB,
    PL_QVER,
};

enum {
    TD_ESC_RAGEQUIT,
    TD_F5,
    TD_F11,
};

#define P_SPCM2 LT(2,KC_SPC)
#define P_ENTM3 LT(3,KC_ENT)
#define P_ENTAL MT(MOD_LALT, KC_ENT)
#define P_ENALG MT(MOD_RALT, KC_ENT)

#define  P_SALT MT(MOD_LALT, KC_S)
#define  P_DCTL MT(MOD_LCTL, KC_D)
#define  P_FSFT MT(MOD_LSFT, KC_F)
#define  P_LALT MT(MOD_RALT, KC_L)
#define  P_KCTL MT(MOD_RCTL, KC_K)
#define  P_JSFT MT(MOD_RSFT, KC_J)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
         TD(TD_ESC_RAGEQUIT), KC_1, KC_2, KC_3, KC_4, TD(TD_F5),                   KC_6,    KC_7,    KC_8,    KC_9, TD(TD_F11), KC_BSPC,
         KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC,
        KC_LSFT,    KC_A,  P_SALT,  P_DCTL,  P_FSFT,    KC_G,                      KC_H,  P_JSFT,  P_KCTL,  P_LALT, KC_SCLN, KC_QUOT,
        KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, XXXXXXX, XXXXXXX,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
                                            P_ENTAL, P_ENTM3, P_SPCM2, P_SPCM2, P_ENTM3, P_ENALG
    ),
    [1] = LAYOUT(
         TD(TD_ESC_RAGEQUIT), KC_1, KC_2, KC_3, KC_4,   KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
         KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC,
        KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
        KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, XXXXXXX, XXXXXXX,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
                                            P_ENTAL, P_ENTM3, P_SPCM2, P_SPCM2, P_ENTM3, P_ENALG
    ),
    [2] = LAYOUT(
        KC_GRV,  _______, _______, PL_QFTR, PL_QRGB, QK_MAKE,                   QK_MAKE, PL_QVER, _______, KC_MINS,  KC_EQL,  KC_DEL,
        _______, _______,   KC_UP, _______, _______, _______,                   _______, _______, _______,   KC_UP, _______, KC_RBRC,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_LBRC,                   KC_RBRC, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_NUHS,
        _______, KC_NUBS, _______, _______, _______, KC_RCBR, XXXXXXX, XXXXXXX, KC_RCBR, _______, _______, _______, _______, _______,
                                            KC_LGUI,  KC_ENT,  KC_SPC,  KC_SPC,  KC_ENT, KC_RGUI

    ),
    [3] = LAYOUT(
          KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
        BL_TOGG, _______, KC_PGUP, _______, KC_VOLU, _______,                   _______, _______, KC_PGUP, _______, KC_PSCR, KC_VOLU,
          BL_UP, KC_HOME, KC_PGDN, KC_END,  KC_VOLD, _______,                   _______, KC_HOME, KC_PGDN,  KC_END, _______, KC_VOLD,
        BL_DOWN, BL_BRTG, _______, _______, KC_MUTE, _______, XXXXXXX, XXXXXXX, _______, KC_MUTE, _______, _______, _______, CW_TOGG,
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
