#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _MOUSE,
    _NUMPAD,
    _OBS,
    _RGB,
    _MACROS,
    _CLICKER,
    _EMPTY,
    _EMPTY2,
    _FUNC
};

/*
enum keymap_keycodes {
    // PL_DMAC1,
    // PL_DMAC2,
    PL_ECCC = QK_USER_0,
    PL_ECCW,
    PL_ECPR,
};
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_all(
                 P_XTAB,  KC_MUTE, P_XWIN,
        KC_ESC,  KC_TAB,  KC_LSFT, KC_BSPC, KC_DEL,
        P_SALL,  P_CUT,   P_UNDO,  P_REDO,  KC_ENT,
        P_COPY,  P_PAST,  P_PSTU,  P_PSTM,  MO(9)
    ),
    [_MOUSE] = LAYOUT_all(
                 MS_BTN1, MS_BTN1, MS_BTN2,
        MS_BTN1, MS_BTN1, MS_UP,   MS_BTN2, MS_BTN2,
        MS_BTN1, MS_LEFT, MS_BTN1, MS_RGHT, MS_BTN2,
        MS_BTN1, MS_BTN1, MS_DOWN, MS_BTN2, LT(9, MS_BTN2)
    ),
    [_NUMPAD] = LAYOUT_all(
                 _______, KC_ENT,  KC_TAB,
        KC_BSPC, KC_P9,   KC_P6,   KC_P3,   P_DOTAL,
        KC_TAB,  KC_P8,   KC_P5,   KC_P2,   KC_P0,
        KC_ENT,  KC_P7,   KC_P4,   KC_P1,   LT(9, KC_P0)
    ),
    [_OBS] = LAYOUT_all(
                 _______, _______, _______,
        KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,
        A(KC_F13), A(KC_F14), A(KC_F15), A(KC_F16), A(KC_F17),
        S(KC_F13), S(KC_F14), S(KC_F15), S(KC_F16), MO(9)
    ),
    [_RGB] = LAYOUT_all(
                 RM_PREV, RM_TOGG, RM_NEXT,
        RM_NEXT, RM_VALU, RM_HUEU, RM_SATU, RM_SPDU,
        RM_PREV, RM_VALD, RM_HUED, RM_SATD, RM_SPDD,
        _______, _______, _______, _______, MO(9)
    ),
    [_MACROS] = LAYOUT_all(
                 MC_14,   KC_NO,   MC_15,
        MC_0,    MC_1,    MC_2,    MC_3,    MC_4,
        MC_5,    MC_6,    MC_7,    MC_8,    _______,
        _______, _______, QK_MAKE, CM_MSJG, MO(9)),
    [_CLICKER] = LAYOUT_all(
                 MS_BTN2, MS_BTN2, MS_BTN2,
        MS_BTN1, MS_BTN1, MS_BTN1, MS_BTN1, MS_BTN1,
        MS_BTN1, MS_BTN1, MS_BTN1, MS_BTN1, MS_BTN1,
        MS_BTN1, MS_BTN1, MS_BTN1, MS_BTN1, LT(9, MS_BTN1)
    ),
    [_EMPTY] = LAYOUT_all(
                 _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, MO(9)
    ),
    [_EMPTY2] = LAYOUT_all(
                 _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, MO(9)
    ),
    [_FUNC] = LAYOUT_all(
                 _______, _______, _______,
        DF(0),   DF(1),   DF(2),   DF(3),   DF(4),
        DF(5),   DF(6),   DF(7),   DF(8),   DF(9),
        CM_MSJG, KC_NUM,  _______, _______, MO(9)
    )
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = {
        ENCODER_CCW_CW( P_RTAB, P_PTAB),
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
        ENCODER_CCW_CW(CM_TSKP, CM_TSKN)
    },
    [_MOUSE] = {
        ENCODER_CCW_CW( _______, _______),
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______)
    },
    [_NUMPAD] = {
        ENCODER_CCW_CW( _______, _______),
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______)
    },
    [_OBS] = {
        ENCODER_CCW_CW( _______, _______),
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______)
    },
    [_RGB] = {
        ENCODER_CCW_CW( RM_HUED, RM_HUEU),
        ENCODER_CCW_CW(RM_VALD, RM_VALU),
        ENCODER_CCW_CW(RM_SATD, RM_SATU)
    },
    [_MACROS] = {
        ENCODER_CCW_CW( _______, _______),
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______)
    },
    [_CLICKER] = {
        ENCODER_CCW_CW( _______, _______),
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______)
    },
    [_EMPTY] = {
        ENCODER_CCW_CW( _______, _______),
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______)
    },
    [_EMPTY2] = {
        ENCODER_CCW_CW( _______, _______),
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______)
    },
    [_FUNC] = {
        ENCODER_CCW_CW( _______, _______),
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______)
    }
};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
