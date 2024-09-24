#pragma once
uint8_t mod_state;

void enc_act(int keycode, bool ctl_pressed, bool gui_pressed, bool alt_pressed, bool sft_pressed) {
    mod_state = get_mods() & (~MOD_MASK_GUI);

    if( keycode != (PL_ENC_PRS & 0xff) && !(mod_state == MOD_MASK_ALT || mod_state == MOD_BIT(KC_LALT) || mod_state == MOD_BIT(KC_RALT))){
        unregister_mods(mod_state);
    }

    if (ctl_pressed && alt_pressed && sft_pressed) {
        //CAS
        switch (keycode) {
            case PL_ENC_CCW & 0xff:
                tap_code16(C(KC_LEFT));
                break;
            case PL_ENC_CW & 0xff:
                tap_code16(C(KC_RGHT));
                break;
            case PL_ENC_PRS & 0xff:
            default:
                break;
        }
    }

    else if (ctl_pressed && alt_pressed) {
        //CA
        switch (keycode) {
            case PL_ENC_CCW & 0xff:
                tap_code16(C(KC_MINS));
                break;
            case PL_ENC_CW & 0xff:
                tap_code16(C(KC_EQL));
                break;
            case PL_ENC_PRS & 0xff:
            default:
                tap_code16(C(KC_0));
                tap_code16(C(KC_P0));
                break;
        }
    }
    else if (ctl_pressed && sft_pressed) {
        //CS
        switch (keycode) {
            case PL_ENC_CCW & 0xff:
                tap_code(KC_PGUP);
                break;
            case PL_ENC_CW & 0xff:
                tap_code(KC_PGDN);
                break;
            case PL_ENC_PRS & 0xff:
            default:
                break;
        }
    }
    else if (alt_pressed && sft_pressed) {
        //AS
        switch (keycode) {
            case PL_ENC_CCW & 0xff:
                tap_code(KC_LEFT);
                break;
            case PL_ENC_CW & 0xff:
                tap_code(KC_RGHT);
                break;
            case PL_ENC_PRS & 0xff:
            default:
                tap_code(KC_ENT);
                break;
        }
    }

    else if (ctl_pressed) {
        //C
        switch (keycode) {
            case PL_ENC_CCW & 0xff:
                tap_code16(C(KC_PGUP));
                break;
            case PL_ENC_CW & 0xff:
                tap_code16(C(KC_PGDN));
                break;
            case PL_ENC_PRS & 0xff:
            default:
                tap_code16(C(KC_F4));
                break;
        }
    }
    else if (gui_pressed) {
        //G
        switch (keycode) {
            case PL_ENC_CCW & 0xff:
                tap_code16(S(KC_SPC));
                break;
            case PL_ENC_CW & 0xff:
                tap_code(KC_SPC);
                break;
            case PL_ENC_PRS & 0xff:
            default:
                break;
        }
    }
    else if (alt_pressed) {
        //A
        switch (keycode) {
            case PL_ENC_CCW & 0xff:
                plodah_alt_tab(true);
                break;
            case PL_ENC_CW & 0xff:
                plodah_alt_tab(false);
                break;
            case PL_ENC_PRS & 0xff:
            default:
                tap_code16(A(KC_F4));
                break;
        }
    }
    else if (sft_pressed) {
        //S
        switch (keycode) {
            case PL_ENC_CCW & 0xff:
                tap_code(KC_MPRV);
                break;
            case PL_ENC_CW & 0xff:
                tap_code(KC_MNXT);
                break;
            case PL_ENC_PRS & 0xff:
            default:
                tap_code(KC_MPLY);
                break;
        }
    }
    else if (
        ((get_highest_layer(layer_state) + PLODAH_LAYEROFFSET) % 2  == 1)
#       if defined(PLODAH_BORING_LAYER)
        && (get_highest_layer(layer_state) != PLODAH_BORING_LAYER)
#       endif // PLODAH_BORING_LAYER
   ) {
        // ODD & NOT BORING
        switch (keycode) {
            case PL_ENC_CCW & 0xff:
                rgb_matrix_decrease_sat();
                break;
            case PL_ENC_CW & 0xff:
                rgb_matrix_increase_sat();
                break;
            case PL_ENC_PRS & 0xff:
            default:
                rgb_matrix_toggle();
                break;
        }
    }
    else if (
        ((get_highest_layer(layer_state) + PLODAH_LAYEROFFSET) % 2  == 0)
        && (get_highest_layer(layer_state) != 0)
#       if defined(PLODAH_BORING_LAYER)
        && (get_highest_layer(layer_state) != PLODAH_BORING_LAYER)
#       endif // PLODAH_BORING_LAYER
   ) {
        // EVEN, NONZERO & NOT BORING
        switch (keycode) {
            case PL_ENC_CCW & 0xff:
                rgb_matrix_decrease_val();
                break;
            case PL_ENC_CW & 0xff:
                rgb_matrix_increase_val();
                break;
            case PL_ENC_PRS & 0xff:
            default:
                rgb_matrix_toggle();
                break;
        }
    }
    else {
        // ELSE
        switch (keycode) {
            case PL_ENC_CCW & 0xff:
                tap_code16_delay(KC_VOLD, 2);
                break;
            case PL_ENC_CW & 0xff:
                tap_code16_delay(KC_VOLU, 2);
                break;
            case PL_ENC_PRS & 0xff:
            default:
                tap_code(KC_MUTE);
                break;
        }
    }
    //if( keycode != (PL_ENC_PRS & 0xff) && !(mod_state == MOD_MASK_ALT || mod_state == MOD_BIT(KC_LALT) || mod_state == MOD_BIT(KC_RALT))){
        register_mods(mod_state);
    //}
}
