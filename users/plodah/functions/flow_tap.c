#if defined(FLOW_TAP_TERM)
    #include "action.h"
    #include "action_util.h"
    #include "debug.h"
    #include "quantum_keycodes.h"

    bool is_flow_tap_key_plodah(uint16_t keycode, bool isprev) {
        // The question that the return value answers is
        if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
            return false; // Disable Flow Tap on hotkeys.
        }

        // if ((get_mods() & MOD_MASK_SHIFT) != 0) {
        if ( IS_QK_MOD_TAP(keycode) && (QK_MOD_TAP_GET_MODS(keycode) & MOD_MASK_SHIFT) ) {
            dprintf("Shift MT; no flow \n");
            return false;
        }

        switch (get_tap_keycode(keycode)) {
            case KC_SPC:
                if(isprev){
                    return true;
                }
                return false;
            case KC_ENT:
                if(isprev){
                    return true;
                }
                return false;
            case KC_A ... KC_Z:
            case KC_DOT:
            case KC_COMM:
            case KC_SCLN:
            case KC_SLSH:
                return true;
        }
        return false;
    }

    uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record, uint16_t prev_keycode) {
        uint16_t returnval = 0;
        if (is_flow_tap_key_plodah(keycode, false) && is_flow_tap_key_plodah(prev_keycode, true)) {
            returnval = FLOW_TAP_TERM;
        }
        return returnval;
    }

#endif // defined(FLOW_TAP_TERM)
