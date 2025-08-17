#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _FNA,
    _FNB,
};

enum keymap_keycodes {
    KB_DPI_CONFIG       = QK_KB_0,
    KB_DRAG_SCROLL,
    BETTER_DRAG_SCROLL_MOMENTARY,
    BETTER_DRAG_SCROLL_TOGGLE,
    PL_MSJG,
    PL_TSKN,
    PL_TSKP,
    BETTER_DRAG_SCROLL_SNIPER_A_MOMENTARY,
    BETTER_DRAG_SCROLL_SNIPER_A_TOGGLE,
    BETTER_DRAG_SCROLL_SNIPER_B_MOMENTARY,
    BETTER_DRAG_SCROLL_SNIPER_B_TOGGLE,
    BETTER_DRAG_VOLUME_MOMENTARY,
};

enum {
    TD_DRAGSCROLL,
};

#define P_DRGTD TD(TD_DRAGSCROLL)
#define P_DPI DPI_CONFIG

#ifdef P_DRGMO
  #undef P_DRGMO
#endif //P_DRGMO
#define P_DRGMO BETTER_DRAG_SCROLL_MOMENTARY
#ifdef P_DRGTG
  #undef P_DRGTG
#endif //P_DRGTG
#define P_DRGTG BETTER_DRAG_SCROLL_TOGGLE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        P_MS4FA, P_MS5FB, MS_BTN3, MS_BTN2,
        MS_BTN1,                   TD(TD_DRAGSCROLL)
    ),
    [_FNA] = LAYOUT(
        _______, PL_TSKP, PL_TSKN, _______,
        DPI_CONFIG,                P_DRGTG
    ),
    [_FNB] = LAYOUT(
        P_DRGVL, _______, _______, P_SNTGA,
        PL_MSJG,                   P_DRGTG
    )
};
