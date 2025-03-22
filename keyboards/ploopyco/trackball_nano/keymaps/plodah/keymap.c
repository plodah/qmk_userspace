#include QMK_KEYBOARD_H

enum layers {
    _BASE,
};

enum keymap_keycodes {
    BETTER_DRAG_SCROLL_MOMENTARY = QK_USER_0,
    BETTER_DRAG_SCROLL_TOGGLE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_BTN1
    )
};

void suspend_power_down_user(void) {
    // Switch off sensor + LED making trackball unable to wake host
    adns5050_power_down();
}

void suspend_wakeup_init_user(void) {
    adns5050_init();
}
