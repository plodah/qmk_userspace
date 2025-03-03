#ifdef CHORDAL_HOLD
  #pragma once
  bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
    uint16_t other_keycode, keyrecord_t* other_record) {
    if (KC_1 <= other_keycode && other_keycode <= QK_BASIC_MAX) { return true; }
    switch (tap_hold_keycode) {
      case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        return true;
      case HRM_HG:
        if (other_keycode == KC_L || other_keycode == HRM_LA) { return true; }
        break;
      case HRM_FC:
        if (other_keycode == KC_S || other_keycode == HRM_SA) { return true; }
        break;
      case HRM_AG:
        if (other_keycode == KC_E) { return true; }
        break;
      case HRM_GG:
        if (other_keycode == KC_D) { return true; }
        break;
    }
    return get_chordal_hold_default(tap_hold_record, other_record);
  }
#endif // CHORDAL_HOLD
