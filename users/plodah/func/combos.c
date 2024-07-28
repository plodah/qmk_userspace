#pragma once

#if ! defined(IS_MOUSE)
    //===========================//
    //       COMMON COMBOS       //
    //===========================//
    const uint16_t PROGMEM qa_combo[] = {KC_Q , KC_A, COMBO_END};
    const uint16_t PROGMEM bsz_combo[] = {KC_NUBS, KC_Z, COMBO_END};
    const uint16_t PROGMEM zx_combo[] = {KC_Z , KC_X, COMBO_END};
    const uint16_t PROGMEM xc_combo[] = {KC_X , KC_C, COMBO_END};
    const uint16_t PROGMEM cv_combo[] = {KC_C , KC_V, COMBO_END};
    const uint16_t PROGMEM xcv_combo[] = {KC_X , KC_C , KC_V, COMBO_END};

    //===========================//
    // COMBOS FOR DYNAMIC MACROS //
    //===========================//
#   if defined(DYNAMIC_MACRO_ENABLE)
        const uint16_t PROGMEM _12_combo[] = {KC_1 , KC_2, COMBO_END};
        const uint16_t PROGMEM _13_combo[] = {KC_1 , KC_3, COMBO_END};
        const uint16_t PROGMEM qw_combo[] = {KC_Q , KC_W, COMBO_END};
        const uint16_t PROGMEM qe_combo[] = {KC_Q , KC_E, COMBO_END};
        const uint16_t PROGMEM _3e_combo[] = {KC_3 , KC_E, COMBO_END};
#   endif //DYNAMIC_MACRO_ENABLE

    combo_t key_combos[] = {
        COMBO(qa_combo, C(KC_A)),
        COMBO(bsz_combo, C(KC_Z)),
        COMBO(zx_combo, C(KC_X)),
        COMBO(xc_combo, C(KC_C)),
        COMBO(cv_combo, C(KC_V)),
        COMBO(xcv_combo, C(S(KC_V))),
#       if defined(DYNAMIC_MACRO_ENABLE)
            COMBO(_12_combo, DM_PLY1),
            COMBO(_13_combo, DM_REC1),
            COMBO(qw_combo, DM_PLY2),
            COMBO(qe_combo, DM_REC2),
            COMBO(_3e_combo, DM_RSTP),
#       endif //DYNAMIC_MACRO_ENABLE
    };

    //===========================//
    //        MOUSE COMBOS       //
    //===========================//
#else // ! defined(IS_MOUSE)
        const uint16_t PROGMEM ms1ms2_combo[] = {KC_BTN1 , KC_BTN2, COMBO_END};
        const uint16_t PROGMEM ms1ms4_combo[] = {KC_BTN1 , KC_BTN4, COMBO_END};
        const uint16_t PROGMEM ms2ms4_combo[] = {KC_BTN2 , KC_BTN4, COMBO_END};
        const uint16_t PROGMEM ms1ms5_combo[] = {KC_BTN1 , KC_BTN5, COMBO_END};
        const uint16_t PROGMEM ms2ms5_combo[] = {KC_BTN2 , KC_BTN5, COMBO_END};

        combo_t key_combos[] = {
            COMBO(ms1ms2_combo, DRAG_SCROLL),
            COMBO(ms1ms4_combo, DRAG_SCROLL),
            COMBO(ms2ms4_combo, DRAG_SCROLL),
            COMBO(ms1ms5_combo, C(KC_C)),
            COMBO(ms2ms5_combo, C(KC_V)),
        };
#endif // ! defined(IS_MOUSE)
