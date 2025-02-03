#include QMK_KEYBOARD_H

enum layers {
    _BASE,
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
    PL_DRAG_SCROLL_MOMENTARY,
    PL_DRAG_SCROLL_TOGGLE,
    PL_MSJG,
    PL_QFTR,
    PL_QRGB,
    PL_QVER,
};

enum {
    TD_DRAGSCROLL,
};

#define P_MS4F1 LT(1, KC_BTN4)
#define P_MS5F1 LT(2, KC_BTN5)
#define P_COPY  C(KC_C)
#define P_PASTE C(KC_V)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        P_COPY,  KC_BTN1, KC_BTN3, KC_BTN2, P_PASTE,
        P_MS4F1, P_MS5F1, DPI_CONFIG
    ),
    [1] = LAYOUT(
        PL_MSJG, PL_TSKB, _______, PL_TSKA, PL_QVER,
        _______, _______, QK_MAKE
    ),
    [2] = LAYOUT(
        _______, _______, _______, _______, _______,
        _______, _______, _______
    )
};


