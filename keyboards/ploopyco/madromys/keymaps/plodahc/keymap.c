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
#define P_MS5FB LT(_FNB, KC_BTN5)
#define P_DRGTD TD(TD_DRAGSCROLL)
#define P_DRGMO TD(TD_DRAGSCROLL)
#define P_DRGTG PL_DRAG_SCROLL_TOGGLE
#define P_XWIN A(KC_F4)
#define P_XTAB C(KC_F4)
#define P_NTAB C(KC_TAB)
#define P_PTAB S(C(KC_TAB))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        P_MS4FA, P_MS5FB, KC_BTN3, KC_BTN2,
        KC_BTN1,                   P_DRGTD
    ),
    [_FNA] = LAYOUT(
        _______, PL_TSKB, PL_TSKA, P_XWIN,
        DPI_CONFIG,                P_DRGTG
    ),
    [_FNB] = LAYOUT(
        P_XTAB,  _______, P_PTAB,  P_NTAB,
        DPI_CONFIG,                P_DRGTG
    )
};
