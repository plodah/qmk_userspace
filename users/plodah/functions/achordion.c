#if defined(COMMUNITY_MODULE_ACHORDION_ENABLE)
    #include "achordion.h"

    bool achordion_chord(uint16_t tap_hold_keycode,
        keyrecord_t* tap_hold_record,
        uint16_t other_keycode,
        keyrecord_t* other_record) {

        // if (KC_1 <= other_keycode && other_keycode <= KC_0) { return true; }
        // if (other_keycode == KC_TAB) { return true; }
        // if (other_keycode == KC_BSPC) { return true; }
        // if (other_keycode == KC_DEL) { return true; }
        // if (other_keycode == KC_ESC) { return true; }
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
        return achordion_opposite_hands(tap_hold_record, other_record);
    }
#endif // COMMUNITY_MODULE_ACHORDION_ENABLE
