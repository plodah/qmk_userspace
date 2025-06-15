#ifdef CHORDAL_HOLD
  #pragma once
  #include <stdbool.h>
  #include <stdint.h>
  #include "action.h"
  #include "action_tapping.h"
  #include "debug.h"

  bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
    uint16_t other_keycode, keyrecord_t* other_record) {
    if (KC_1 <= other_keycode && other_keycode <= QK_BASIC_MAX) {
      dprintf("chordal nonalpha\n");
      return true;
    }
    switch (tap_hold_keycode) {
      case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        dprintf("chordal LT\n");
        return true;
      case QK_MOMENTARY ... QK_MOMENTARY_MAX:
        dprintf("chordal MO\n");
        return true;
      case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
        dprintf("chordal TD\n");
        return true;
        break;
      case HRM_FC:
        if (other_keycode == KC_S || other_keycode == HRM_SA) {
            dprintf("chordal Ctrl S\n");
            return true;
        }
        break;
      case HRM_AG:
      case HRM_GG:
      case HRM_HG:
        if (other_keycode == KC_E) {
            dprintf("chordal Gui E\n");
            return true;
        }
        if (other_keycode == KC_L || other_keycode == HRM_LA) {
            dprintf("chordal Gui L\n");
            return true;
        }
        if (other_keycode == KC_D || other_keycode == HRM_DS) {
            dprintf("chordal Gui D\n");
            return true;
        }
        break;
    }
    dprintf("chordal default\n");
    return get_chordal_hold_default(tap_hold_record, other_record);
  }
#endif // CHORDAL_HOLD
