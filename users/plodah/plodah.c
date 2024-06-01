#include "plodah.h"
#include QMK_KEYBOARD_H

//===========================//
//       CUSTOM KEYCODES     //
//===========================//
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

    case QK_VERS:
        if (record->event.pressed) {
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE);
        }
        break;

    }
    return true;
};

//userspace_config_t userspace_config;

#if defined(COMBO_ENABLE)
//===========================//
//       COMMON COMBOS       //
//===========================//
#if ! defined(IS_MOUSE)
const uint16_t PROGMEM as_combo[] = {KC_A , KC_S, COMBO_END};
const uint16_t PROGMEM bsz_combo[] = {KC_NUBS, KC_Z, COMBO_END};
const uint16_t PROGMEM zx_combo[] = {KC_Z , KC_X, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X , KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C , KC_V, COMBO_END};
const uint16_t PROGMEM xcv_combo[] = {KC_X , KC_C , KC_V, COMBO_END};

//===========================//
// COMBOS FOR DYNAMIC MACROS //
//===========================//
#if defined(DYNAMIC_MACRO_ENABLE)
const uint16_t PROGMEM _12_combo[] = {KC_1 , KC_2, COMBO_END};
const uint16_t PROGMEM _13_combo[] = {KC_1 , KC_3, COMBO_END};
const uint16_t PROGMEM qw_combo[] = {KC_Q , KC_W, COMBO_END};
const uint16_t PROGMEM qe_combo[] = {KC_Q , KC_E, COMBO_END};
const uint16_t PROGMEM _3e_combo[] = {KC_3 , KC_E, COMBO_END};

combo_t key_combos[] = {
    COMBO(_12_combo, DM_PLY1),
    COMBO(_13_combo, DM_REC1),
    COMBO(qw_combo, DM_PLY2),
    COMBO(qe_combo, DM_REC2),
    COMBO(_3e_combo, DM_RSTP),
    COMBO(as_combo, C(KC_A)),
    COMBO(bsz_combo, C(KC_Z)),
    COMBO(zx_combo, C(KC_X)),
    COMBO(xc_combo, C(KC_C)),
    COMBO(cv_combo, C(KC_V)),
    COMBO(xcv_combo, C(S(KC_V)))
};

//==============================//
// COMBOS BUT NO DYNAMIC MACROS //
//------------------------------//
#else
combo_t key_combos[] = {
    COMBO(as_combo, C(KC_A)),
    COMBO(bsz_combo, C(KC_Z)),
    COMBO(zx_combo, C(KC_X)),
    COMBO(xc_combo, C(KC_C)),
    COMBO(cv_combo, C(KC_V)),
    COMBO(xcv_combo, C(S(KC_V)))
};
#endif
//===========================//
//        MOUSE COMBOS       //
//===========================//
#else
    const uint16_t PROGMEM ms1ms2_combo[] = {KC_BTN1 , KC_BTN2, COMBO_END};
    const uint16_t PROGMEM ms1ms4_combo[] = {KC_BTN1 , KC_BTN4, COMBO_END};

    combo_t key_combos[] = {
        COMBO(ms1ms2_combo, DRAG_SCROLL),
        COMBO(ms1ms4_combo, DRAG_SCROLL),
    };
#endif
#endif
