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
};

enum {
    TD_DRAGSCROLL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        P_COPY,  KC_BTN1, KC_BTN3, KC_BTN2, P_PSTU,
        P_MS4FA, P_MS5FA, DPI_CONFIG
    ),
    [_FNA] = LAYOUT(
        PL_MSJG, PL_TSKB, _______, PL_TSKA, CM_QVER,
        _______, _______, QK_MAKE
    ),
    [_FNB] = LAYOUT(
        _______, _______, _______, _______, _______,
        _______, _______, _______
    )
};


