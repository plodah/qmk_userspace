#if defined(LEADER_ENABLE)
  #pragma once

  void leader_start_user(void) {

  }

  void leader_end_user(void) {
    if ( leader_sequence_three_keys(KC_Q, KC_M, KC_K) ) {
        SEND_STRING("QMK is awesome.");
    }
    #if defined(PLODAH_MSJIGGLER_ENABLE)
    else if ( leader_sequence_one_key(KC_J) || leader_sequence_one_key(HRM_JC) ) {
        pl_jiggler_toggle();
      }
    #endif // #if defined(PLODAH_MSJIGGLER_ENABLE)

    #if defined(KC_PL_QFTR)
      else if ( leader_sequence_two_keys(KC_Q, KC_F) || leader_sequence_two_keys(KC_Q, HRM_FC) ) {
        featureQuerySs();
      }
    #endif // defined(KC_PL_QFTR)

    #if defined(KC_PL_QLYR)
      else if ( leader_sequence_two_keys(KC_Q, KC_L) || leader_sequence_two_keys(KC_Q, HRM_LA) ) {
        layerQuerySs();
      }
    #endif // defined(KC_PL_QLYR)

    #if defined(KC_PL_QRGB)
      else if ( leader_sequence_two_keys(KC_Q, KC_R) ) {
        rgbQuerySs();
      }
    #endif // defined(KC_PL_QRGB)

    #if defined(KC_PL_QTAP)
      else if ( leader_sequence_two_keys(KC_Q, KC_T) ) {
        tapQuerySs();
      }
    #endif // defined(KC_PL_QTAP)

    #if defined(KC_PL_QVER)
      else if ( leader_sequence_two_keys(KC_Q, KC_V) ) {
        verQuerySs();
      }
    #endif // defined(KC_PL_QVER)
  }

#endif // defined(LEADER_ENABLE)

// leader_sequence_is(kc, 0, 0, 0, 0)
// leader_sequence_one_key(kc)
// leader_sequence_two_keys(kc, kc)
// leader_sequence_three_keys(kc, kc, kc)
// leader_sequence_four_keys(kc, kc, kc, kc)
// leader_sequence_five_keys(kc, kc, kc, kc, kc)
