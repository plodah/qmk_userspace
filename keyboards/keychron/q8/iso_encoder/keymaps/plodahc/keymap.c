#include QMK_KEYBOARD_H

enum kcq8_layers {
    _QWER,
    _QWERB,
    _FNA,
    _FNB,
};

enum keymap_keycodes {
    PL_ALTTAB = QK_USER_0,
    PL_ALTSTAB,
    PL_EC_CCW,
    PL_EC_CW,
    PL_EC_PR,
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

#define PL_RAGE TD(TD_ESC_RAGEQUIT)

#define P_SPCFA LT(_FNA, KC_SPC)
#define P_BSPFB LT(_FNB, KC_BSPC)
#define P_APPFB LT(_FNB, KC_APP)

#define PL_RAGE TD(TD_ESC_RAGEQUIT)
#define PL_PSTU C(S(KC_V))
#define PL_5F5 TD(TD_F5)
#define PL_11FE TD(TD_F11)

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




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWER] = LAYOUT_iso_70(
        PL_RAGE, KC_1,    KC_2,    KC_3,    KC_4,    PL_5F5,           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    PL_11FE, KC_EQL,  KC_BSPC, PL_EC_PR,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_END,
        P_BSPFB, KC_A,    HRM_SA,  HRM_DS,  HRM_FC,  HRM_GG,           HRM_HG,  HRM_JS,  HRM_KA,  HRM_LC,  KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,  KC_HOME,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,
        KC_LCTL, KC_LWIN,          KC_LALT,          P_SPCFA, P_APPFB, P_APPFB,          P_SPCFA,          KC_RALT,          KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_QWERB] = LAYOUT_iso_70(
        PL_RAGE, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,             KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_MUTE,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,             KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_END,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,             KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,  KC_HOME,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,
        KC_LCTL, KC_LWIN,          KC_LALT,          KC_SPC,  MO(3),   MO(2),            KC_SPC,           KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_FNA] = LAYOUT_iso_70(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,            KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  PL_EC_PR,
        KC_ENT,  KC_PGUP, KC_UP,   KC_PGDN, _______, _______, _______,          _______, _______, _______, KC_PSCR, _______, _______,          KC_PGUP,
        KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT,  _______, _______,          _______, _______, _______, _______, _______, _______, _______, KC_PGDN,
        _______, _______, _______, _______, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, _______, _______, CW_TOGG, KC_PGUP,
        _______, GU_TOGG,          _______,          KC_SPC,  _______, _______,          KC_SPC,           _______,          KC_HOME, KC_PGDN, KC_END
    ),
    [_FNB] = LAYOUT_iso_70(
        KC_GRV,  MC_1,    MC_2,    MC_3,    MC_4,    MC_5,    MC_6,             MC_7,    MC_8,    PL_QFTR, PL_QRGB, PL_QVER, QK_MAKE, _______, PL_EC_PR,
        RM_TOGG, RM_NEXT, RM_VALU, RM_HUEU, RM_SATU, RM_SPDU, _______,          _______, _______, _______, KC_PSCR, _______, _______,          PL_MSJG,
        _______, RM_PREV, RM_VALD, RM_HUED, RM_SATD, RM_SPDD, _______,          _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, PL_PSTU, _______, _______, NK_TOGG, _______, _______, _______, _______, _______, KC_VOLU,
        _______, GU_TOGG,          _______,          KC_SPC,  _______, _______,          KC_SPC,           _______,          KC_HOME, KC_PGDN, KC_END
    )
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWER]  = {ENCODER_CCW_CW(PL_EC_CCW,  PL_EC_CW)},
    [_QWERB] = {ENCODER_CCW_CW(KC_VOLD,    KC_VOLU)},
    [_FNA]   = {ENCODER_CCW_CW(PL_EC_CCW,  PL_EC_CW)},
    [_FNB]   = {ENCODER_CCW_CW(PL_EC_CCW,  PL_EC_CW)}
};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
