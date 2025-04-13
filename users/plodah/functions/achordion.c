#if defined(COMMUNITY_MODULE_ACHORDION_ENABLE)
    #include "achordion.h"

    bool achordion_chord(uint16_t tap_hold_keycode,
        keyrecord_t* tap_hold_record,
        uint16_t other_keycode,
        keyrecord_t* other_record) {

        if (KC_1 <= other_keycode && other_keycode <= QK_BASIC_MAX) {
            dprintf("chordal nonalpha\n");
            return true;
        }
        switch (tap_hold_keycode) {
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
                dprintf("Achordion LT\n");
                return true;
            case QK_MOMENTARY ... QK_MOMENTARY_MAX:
                dprintf("Achordion MO\n");
                return true;
            case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
                dprintf("Achordion TD\n");
                return true;
            case HRM_FC:
                if (other_keycode == KC_S || other_keycode == HRM_SA) {
                    dprintf("Achordion Ctrl S\n");
                    return true;
                }
                break;
            case HRM_AG:
            case HRM_GG:
            case HRM_HG:
                if (other_keycode == KC_E) {
                    dprintf("Achordion Gui E\n");
                    return true;
                }
                if (other_keycode == KC_L || other_keycode == HRM_LA) {
                    dprintf("Achordion Gui L\n");
                    return true;
                }
                if (other_keycode == KC_D || other_keycode == HRM_DS) {
                    dprintf("Achordion Gui D\n");
                    return true;
                }
                break;

        }
        return achordion_opposite_hands(tap_hold_record, other_record);
    }
#endif // COMMUNITY_MODULE_ACHORDION_ENABLE
