#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _FNA,
    _FNB,
};

enum keymap_keycodes {
    // PL_DMAC1,
    // PL_DMAC2,
    BETTER_DRAG_SCROLL_MOMENTARY = QK_USER_0,
    BETTER_DRAG_SCROLL_TOGGLE,
    // PL_ECCC,
    // PL_ECCW,
    // PL_ECPR,
};

enum {
    TD_DRAGSCROLL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_BTN1, KC_BTN3, P_MS4FA, KC_BTN2, P_MS5FA
    ),
    [_FNA] = LAYOUT(
        _______, DPI_CONFIG, _______, CM_TSKP, CM_TSKN
    )
};
