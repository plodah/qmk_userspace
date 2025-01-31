#include QMK_KEYBOARD_H

enum keymap_keycodes {
    PL_ALTTAB = QK_USER_0,
    PL_ALTSTAB,
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        C(KC_C), KC_BTN1, KC_BTN3, KC_BTN2, C(KC_V),
        LT(1, KC_BTN4), LT(1, KC_BTN5), DPI_CONFIG
    ),
    [1] = LAYOUT(
        PL_MSJG, PL_ALTSTAB, _______, PL_ALTTAB, PL_QVER,
        _______, _______, QK_MAKE
    ),
    [2] = LAYOUT(
        _______, _______, _______, _______, _______,
        _______, _______, _______
    )
};


