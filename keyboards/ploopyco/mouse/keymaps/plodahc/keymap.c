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
    PL_DRAG_SCROLL_MOMENTARY,
    PL_DRAG_SCROLL_TOGGLE,
    // PL_ECCC,
    // PL_ECCW,
    // PL_ECPR,
    PL_MSJG,
    PL_QFTR,
    PL_QLYR,
    PL_QRGB,
    // PL_QTAP,
    PL_QVER,
};

enum {
    TD_DRAGSCROLL,
};

#define P_MS4FA LT(_FNA, KC_BTN4)
#define P_MS5FA LT(_FNA, KC_BTN5)
#define P_COPY  C(KC_C)
#define P_PASTE C(KC_V)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        P_COPY,  KC_BTN1, KC_BTN3, KC_BTN2, P_PASTE,
        P_MS4FA, P_MS5FA, DPI_CONFIG
    ),
    [_FNA] = LAYOUT(
        PL_MSJG, PL_TSKB, _______, PL_TSKA, PL_QVER,
        _______, _______, QK_MAKE
    ),
    [_FNB] = LAYOUT(
        _______, _______, _______, _______, _______,
        _______, _______, _______
    )
};


