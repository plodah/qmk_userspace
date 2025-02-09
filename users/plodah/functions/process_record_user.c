#pragma once

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  #if defined(PLODAH_TYPINGINDICATOR_RGBINDEX) || defined(PLODAH_DRAGSCROLL) || (defined(PLODAH_MSJIGGLER_ENABLE) && defined(DEFERRED_EXEC_ENABLE))
    if (record->event.pressed) {
      #if defined(PLODAH_TYPINGINDICATOR_RGBINDEX)
        plodah_typingindicator_start(keycode);
      #endif // PLODAH_TYPINGINDICATOR_RGBINDEX
      #if defined(PLODAH_DRAGSCROLL)
        pl_dragscroll_everypress(keycode);
      #endif // PLODAH_DRAGSCROLL
      #if defined(PLODAH_MSJIGGLER_ENABLE) && defined(DEFERRED_EXEC_ENABLE)
        jiggler_onclick(keycode);
      #endif // PLODAH_MSJIGGLER_ENABLE
    }
  #endif // defined(PLODAH_TYPINGINDICATOR_RGBINDEX) || (defined(PLODAH_MSJIGGLER_ENABLE) && defined(DEFERRED_EXEC_ENABLE))

  #if defined(PLODAH_MSJIGGLER_ENABLE) && defined(DEFERRED_EXEC_ENABLE)
    jiggle_delay(90);
  #endif // PLODAH_MSJIGGLER_ENABLE

  #if defined(PLODAH_MSGESTURE_ENABLE) && defined(DEFERRED_EXEC_ENABLE)
    plodah_msGestureResetAll();
  #endif // defined(PLODAH_MSGESTURE_ENABLE) && defined(DEFERRED_EXEC_ENABLE)

  switch (keycode) {

    #if defined(KC_PL_QFTR)
      case PL_QFTR:
        if (record->event.pressed) {
            featureQuerySs();
        }
        return false;
    #endif // defined(KC_PL_QFTR)

    #if defined(KC_PL_QLYR)
      case PL_QLYR:
        if (record->event.pressed) {
            // send_string_with_delay(layerQuery(), TAP_CODE_DELAY);
            layerQuerySs();
        }
        return false;
    #endif // defined(KC_PL_QLYR)

    #if defined(KC_PL_QRGB)
      case PL_QRGB:
        if (record->event.pressed) {
            // send_string_with_delay(rgbQuery(), TAP_CODE_DELAY);
            // send_string_with_delay(rgbQuerySmert(), TAP_CODE_DELAY);
            rgbQuerySs();
        }
        return false;
    #endif // defined(KC_PL_QRGB)

    #if defined(KC_PL_QTAP)
      case PL_QTAP:
        if (record->event.pressed) {
            tapQuerySs();
        }
        return false;
    #endif // defined(KC_PL_QTAP)

    #if defined(KC_PL_QVER)
      case PL_QVER:
        if (record->event.pressed) {
          send_string_with_delay ( "\\ " QMK_KEYBOARD "/" QMK_KEYMAP " \" " QMK_VERSION ", Built on: " QMK_BUILDDATE "\n", TAP_CODE_DELAY);
        }
        return false;
    #endif // defined(KC_PL_QVER)

    #ifdef PLODAH_DYNAMIC_MACRO_KCS_ENABLE
      case PL_DMAC1 ... PL_DMAC2:
        return dynamic_macros_process_record_user( keycode, record );
    #endif // PLODAH_DYNAMIC_MACRO_KCS_ENABLE

    #ifdef PLODAH_TAPDANCE_TAPHOLD_ENABLE
      case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
        return tap_dance_process_record_user( keycode, record );
    #endif // PLODAH_TAPDANCE_TAPHOLD_ENABLE

    #if defined(PLODAH_TASKSWITCH_ENABLE)
      case PL_TSKA:
        if (record->event.pressed) {
          plodah_taskswitch_start(false);
        }
        return false;
      case PL_TSKB:
        if (record->event.pressed) {
          plodah_taskswitch_start(true);
        }
        return false;
    #endif  // defined(PLODAH_TASKSWITCH_ENABLE)

    #if defined(PLODAH_KNOB_ENHANCEMENTS_ENABLE)
      case PL_ECCC:
      case PL_ECCW:
      case PL_ECPR:
        if (record->event.pressed) {
          enc_act(keycode & 0xff/*, ctl_pressed, gui_pressed, alt_pressed, sft_pressed*/);
          return true;
        }
        return false;
    #endif  // PLODAH_KNOB_ENHANCEMENTS_ENABLE

    #if defined(PLODAH_REPEATHOLD_RGB) && defined(RGB_MATRIX_ENABLE)
      case RM_HUED:
      case RM_HUEU:
      case RM_SATD:
      case RM_SATU:
      case RM_VALD:
      case RM_VALU:
      case RM_SPDD:
      case RM_SPDU:
        repeathold_rgb_start(keycode & 0xff, record->event.pressed);
        return true;
    #endif // defined(PLODAH_REPEATHOLD_RGB) && defined(RGB_MATRIX_ENABLE)

    #if defined(PLODAH_REPEATHOLD_RGB) && defined(RGBLIGHT_ENABLE)
      case UG_HUEU:
      case UG_HUED:
      case UG_SATU:
      case UG_SATD:
      case UG_VALU:
      case UG_VALD:
      case UG_SPDU:
      case UG_SPDD:
        repeathold_rgb_start(keycode & 0xff, record->event.pressed);
        return true;
    #endif // defined(PLODAH_REPEATHOLD_RGB) && defined(RGBLIGHT_ENABLE)

    #if defined(PLODAH_DRAGSCROLL)
      case PL_DRAG_SCROLL_MOMENTARY:
        pl_dragscroll_momentary(record->event.pressed);
        return true;
      case PL_DRAG_SCROLL_TOGGLE:
        pl_dragscroll_toggle(record->event.pressed);
        return true;
    #endif // PLODAH_DRAGSCROLL

  }
  return true;
}
