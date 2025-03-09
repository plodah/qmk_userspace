#pragma once

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  #if defined(PLODAH_TYPINGINDICATOR_RGBINDEX) || defined(PLODAH_DRAGSCROLL)
    if (record->event.pressed) {
      #if defined(PLODAH_TYPINGINDICATOR_RGBINDEX)
        plodah_typingindicator_start(keycode);
      #endif // PLODAH_TYPINGINDICATOR_RGBINDEX
      #if defined(PLODAH_DRAGSCROLL)
        pl_dragscroll_everypress(keycode);
      #endif // defined(PLODAH_TYPINGINDICATOR_RGBINDEX) || defined(PLODAH_DRAGSCROLL)
    }
  #endif // defined(PLODAH_TYPINGINDICATOR_RGBINDEX)

  #if defined(PLODAH_MSGESTURE_ENABLE) && defined(DEFERRED_EXEC_ENABLE)
    plodah_msGestureResetAll();
  #endif // defined(PLODAH_MSGESTURE_ENABLE) && defined(DEFERRED_EXEC_ENABLE)

  #if defined(ACHORDION_ENABLE)
    if (!process_achordion(keycode, record)) { return false; }
  #endif // ACHORDION_ENABLE

  switch (keycode) {

    #if defined(KC_PL_SCRL)
      case PL_SCRL:
        tap_code(KC_SCRL);
        return false;
    #endif // defined(KC_PL_SCRL)

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
