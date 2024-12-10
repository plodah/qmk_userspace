#include QMK_KEYBOARD_H

enum keymap_keycodes {
    PL_ALTTAB = QK_USER_0,
    PL_ALTSTAB,
    PL_MSJG,
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
#define PL_RAGE TD(TD_ESC_RAGEQUIT)

#define HRM_AG MT(MOD_LGUI, KC_A)
#define HRM_SA MT(MOD_LALT, KC_S)
#define HRM_DC MT(MOD_LCTL, KC_D)
#define HRM_FS MT(MOD_LSFT, KC_F)
#define HRM_LA MT(MOD_RALT, KC_L)
#define HRM_KC MT(MOD_RCTL, KC_K)
#define HRM_JS MT(MOD_RSFT, KC_J)
#define HRM_CG MT(MOD_RGUI, KC_SCLN)

#define PL_RAGE TD(TD_ESC_RAGEQUIT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        PL_RAGE, KC_1,    KC_2,    KC_3,    KC_4,    TD(TD_F5),                 KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
        KC_NUBS, HRM_AG,  HRM_SA,  HRM_DC,  HRM_FS,  KC_G,                      KC_H,    HRM_JS,  HRM_KC,  HRM_LA,  HRM_CG,  KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                            KC_LCTL, P_ENTM3, P_SPCM2, P_SPCM2, P_ENTM3, KC_RCTL
    ),
    [1] = LAYOUT(
        PL_RAGE, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
        KC_NUBS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                            KC_LCTL, P_ENTM3, P_SPCM2, P_SPCM2, P_ENTM3, KC_RCTL
    ),
    [2] = LAYOUT(
        KC_GRV,  _______, _______, PL_QFTR, PL_QRGB, QK_MAKE,                   QK_MAKE, PL_QVER, PL_MSJG, KC_MINS, KC_EQL,  KC_DEL,
        _______, _______,   KC_UP, _______, _______, _______,                   _______, _______, _______, KC_UP,   _______, KC_RBRC,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_LBRC,                   KC_RBRC, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_NUHS,
        _______, KC_NUBS, _______, _______, _______, KC_RCBR, XXXXXXX, XXXXXXX, KC_RCBR, _______, _______, _______, _______, _______,
                                            KC_LGUI, KC_ENT,  KC_SPC,  KC_SPC,  KC_ENT,  KC_RGUI

    ),
    [3] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        BL_TOGG, _______, KC_PGUP, _______, KC_VOLU, _______,                   _______, _______, KC_PGUP, _______, KC_PSCR, KC_VOLU,
        BL_UP,   KC_HOME, KC_PGDN, KC_END,  KC_VOLD, _______,                   _______, KC_HOME, KC_PGDN, KC_END,  _______, KC_VOLD,
        BL_DOWN, BL_BRTG, _______, _______, KC_MUTE, _______, XXXXXXX, XXXXXXX, _______, KC_MUTE, _______, _______, _______, CW_TOGG,
                                            KC_LGUI, KC_ENT,  KC_SPC,  KC_SPC,  KC_ENT,  KC_RGUI
    )/*,
    [4] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______, _______, _______, _______
    )*/
};
