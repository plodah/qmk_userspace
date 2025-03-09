#if defined(LEADER_ENABLE)
    #pragma once

    #if defined COMMUNITY_MODULE_CONFIG_QUERY_ENABLE
        #include "config_query.h"
    #endif // COMMUNITY_MODULE_CONFIG_QUERY_ENABLE
    #if defined COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE
        #include "mouse_jiggler.h"
    #endif // COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE

    void leader_start_user(void) {

    }

    void leader_end_user(void) {
        if ( leader_sequence_three_keys(KC_Q, KC_M, KC_K) ) {
            SEND_STRING("QMK is awesome.");
        }
        #if defined(COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE)
        else if ( leader_sequence_one_key(KC_J) || leader_sequence_one_key(HRM_JC) ) {
            jiggler_toggle();
        }
        #endif // #if defined(MSJIGGLER_ENABLE)

        #if !defined(CM_QFTR_DISABLED)
            else if ( leader_sequence_two_keys(KC_Q, KC_F) || leader_sequence_two_keys(KC_Q, HRM_FC) ) {
                queryFeaturesSs();
            }
        #endif // !defined(CM_QFTR_DISABLED)
        #if !defined(CM_QLYR_DISABLED)
            else if ( leader_sequence_two_keys(KC_Q, KC_L) || leader_sequence_two_keys(KC_Q, HRM_LA) ) {
                queryLayersSs();
            }
        #endif // !defined(CM_QLYR_DISABLED)
        #if !defined(CM_QTAP_DISABLED)
            else if ( leader_sequence_two_keys(KC_Q, KC_T) ) {
                queryTappingSs();
            }
        #endif // !defined(CM_QTAP_DISABLED)
        #if !defined(CM_QVER_DISABLED)
            else if ( leader_sequence_two_keys(KC_Q, KC_V) ) {
                queryVersionSs();
            }
        #endif // !defined(CM_QVER_DISABLED)
        #if !defined(CM_QRGB_DISABLED)
            else if ( leader_sequence_two_keys(KC_Q, KC_R) ) {
                queryRgbSs();
            }
        #endif // !defined(CM_QRGB_DISABLED)
    }
#endif // defined(LEADER_ENABLE)

// leader_sequence_is(kc, 0, 0, 0, 0)
// leader_sequence_one_key(kc)
// leader_sequence_two_keys(kc, kc)
// leader_sequence_three_keys(kc, kc, kc)
// leader_sequence_four_keys(kc, kc, kc, kc)
// leader_sequence_five_keys(kc, kc, kc, kc, kc)
