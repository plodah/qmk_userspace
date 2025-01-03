#include QMK_KEYBOARD_H

enum sofle_layers {
    _QWER,
    _QWERB,
    _FNA,
    _FNB,
};

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

#define P_SPCFA LT(_FNA, KC_SPC)
#define P_ENTFB LT(_FNB, KC_ENT)
#define PL_RAGE TD(TD_ESC_RAGEQUIT)
#define PL_5F5 TD(TD_F5)

#define HRM_SA LALT_T(KC_S)
#define HRM_DS LSFT_T(KC_D)
#define HRM_FC LCTL_T(KC_F)
#define HRM_GG LGUI_T(KC_G)
#define HRM_HG RGUI_T(KC_H)
#define HRM_JS RCTL_T(KC_J)
#define HRM_KA RSFT_T(KC_K)
#define HRM_LC RALT_T(KC_L)

#define HRM_ZG LGUI_T(KC_Z)
#define HRM_SLG RGUI_T(KC_SLSH)

#define PL_RAGE TD(TD_ESC_RAGEQUIT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWER] = LAYOUT(
        PL_RAGE, KC_1,    KC_2,    KC_3,    KC_4,    PL_5F5,                    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NUHS,
        KC_NUBS, KC_A,    HRM_SA,  HRM_DS,  HRM_FC,  HRM_GG,                    HRM_HG,  HRM_JS,  HRM_KA,  HRM_LC,  KC_SCLN, KC_QUOT,
        KC_LSFT, HRM_ZG,  KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  HRM_SLG, KC_RSFT,
                                            KC_LCTL, P_ENTFB, P_SPCFA, P_SPCFA, P_ENTFB, KC_RCTL
    ),
    [_QWERB] = LAYOUT(
        PL_RAGE, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
        KC_NUBS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                            KC_LCTL, P_ENTFB, P_SPCFA, P_SPCFA, P_ENTFB, KC_RCTL
    ),
    [_FNA] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        KC_CAPS, _______, _______, KC_UP,   _______, KC_F6,                     KC_F7,   _______, KC_UP,   KC_MINS, KC_EQL,  _______,
        _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,                   _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
        _______, _______, _______, _______, KC_LBRC, KC_LCBR, XXXXXXX, XXXXXXX, KC_RCBR, KC_RBRC, _______, _______, _______, _______,
                                            KC_LGUI, KC_ENT,  KC_SPC,  KC_SPC,  KC_ENT,  KC_RGUI
    ),
    [_FNB] = LAYOUT(
        KC_BSPC, _______, _______, PL_QFTR, PL_QRGB, QK_MAKE,                   QK_MAKE, PL_QVER, PL_MSJG, KC_MINS, KC_EQL,  KC_DEL,
        BL_TOGG, _______, _______, KC_PGUP, _______, _______,                   _______, _______, KC_PGUP, _______, KC_PSCR, KC_MUTE,
        BL_UP,   _______, KC_HOME, KC_PGDN, KC_END,  _______,                   _______, KC_HOME, KC_PGDN, KC_END,  _______, KC_VOLU,
        BL_DOWN, BL_BRTG, _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, KC_VOLD,
                                            GU_TOGG, KC_ENT,  KC_SPC,  KC_SPC,  KC_ENT,  GU_ON

    )/*,
    [4] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______, _______, _______, _______
    )*/
};
