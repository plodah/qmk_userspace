#include QMK_KEYBOARD_H

enum layers {
    _BASE,
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
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_NO
    )
};

void suspend_power_down_user(void) {
    // Switch off sensor + LED making trackball unable to wake host
    adns5050_power_down();
}

void suspend_wakeup_init_user(void) {
    adns5050_init();
}
