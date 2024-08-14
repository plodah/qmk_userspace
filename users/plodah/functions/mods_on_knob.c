#pragma once
uint8_t current_layer;
uint8_t mod_state;

void enc_prs_act(bool ctl_pressed, bool sft_pressed, bool alt_pressed) {
    current_layer = get_highest_layer(layer_state);
    mod_state = get_mods();

    if (ctl_pressed && alt_pressed && sft_pressed) {
        unregister_mods(mod_state);
        //CAS
        register_mods(mod_state);
    }
    else if (ctl_pressed && alt_pressed) {
        unregister_mods(mod_state);
        tap_code16(C(KC_0));
        tap_code16(C(KC_P0));
        register_mods(mod_state);
    }
    else if (alt_pressed && sft_pressed) {
        unregister_mods(mod_state);
        //AS
        register_mods(mod_state);
    }
    else if (sft_pressed && ctl_pressed) {
        unregister_mods(mod_state);
        //CS
        register_mods(mod_state);
    }
    else if (ctl_pressed) {
        unregister_mods(mod_state);
        tap_code16(C(KC_F4));
        register_mods(mod_state);
    }
    else if (alt_pressed) {
        unregister_mods(mod_state);
        tap_code16(A(KC_F4));
        register_mods(mod_state);
    }
    else if (sft_pressed) {
        unregister_mods(mod_state);
        tap_code(KC_MPLY);
        register_mods(mod_state);
    }
    else if (
        ((current_layer + PLODAH_LAYEROFFSET) % 2  == 1)
#       if defined(PLODAH_BORING_LAYER)
        && (current_layer != PLODAH_BORING_LAYER)
#       endif // PLODAH_BORING_LAYER
   ) {
        rgb_matrix_toggle();
    }
    else if (
        ((current_layer + PLODAH_LAYEROFFSET) % 2  == 0)
        && (current_layer != 0)
#       if defined(PLODAH_BORING_LAYER)
        && (current_layer != PLODAH_BORING_LAYER)
#       endif // PLODAH_BORING_LAYER
   ) {
        rgb_matrix_toggle();
    }
    else {
        unregister_mods(mod_state);
        tap_code(KC_MUTE);
        register_mods(mod_state);
    }
}

void enc_ccw_act(bool ctl_pressed, bool sft_pressed, bool alt_pressed) {
    current_layer = get_highest_layer(layer_state);
    mod_state = get_mods();

    if (ctl_pressed && alt_pressed && sft_pressed) {
        unregister_mods(mod_state);
        tap_code16(C(KC_LEFT));
        register_mods(mod_state);
    }
    else if (ctl_pressed && alt_pressed) {
        unregister_mods(mod_state);
        tap_code16(C(KC_MINS));
        register_mods(mod_state);
    }
    else if (alt_pressed && sft_pressed) {
        unregister_mods(mod_state);
        tap_code16(KC_LEFT);
        register_mods(mod_state);
    }
    else if (sft_pressed && ctl_pressed) {
        unregister_mods(mod_state);
        tap_code(KC_PGUP);
        register_mods(mod_state);
    }
    else if (ctl_pressed) {
        unregister_mods(mod_state);
        tap_code16(C(KC_PGUP));
        register_mods(mod_state);
    }
    else if (alt_pressed) {
        alt_tab_bk();
    }
    else if (sft_pressed) {
        unregister_mods(mod_state);
        tap_code(KC_MPRV);
        register_mods(mod_state);
    }
    else if (
        ((current_layer + PLODAH_LAYEROFFSET) % 2  == 1)
#       if defined(PLODAH_BORING_LAYER)
        && (current_layer != PLODAH_BORING_LAYER)
#       endif // PLODAH_BORING_LAYER
   ) {
        rgb_matrix_decrease_sat();
    }
    else if (
        ((current_layer + PLODAH_LAYEROFFSET) % 2  == 0)
        && (current_layer != 0)
#       if defined(PLODAH_BORING_LAYER)
        && (current_layer != PLODAH_BORING_LAYER)
#       endif // PLODAH_BORING_LAYER
   ) {
        rgb_matrix_decrease_val();
    }
    else {
        unregister_mods(mod_state);
        tap_code16_delay(KC_VOLD, 2);
        register_mods(mod_state);
    }
}

void enc_cw_act(bool ctl_pressed, bool sft_pressed, bool alt_pressed) {
    current_layer = get_highest_layer(layer_state);
    mod_state = get_mods();

    if (ctl_pressed && alt_pressed && sft_pressed) {
        unregister_mods(mod_state);
        tap_code16(C(KC_RGHT));
        register_mods(mod_state);
    }
    else if (ctl_pressed && alt_pressed) {
        unregister_mods(mod_state);
        tap_code16(C(KC_EQL));
        register_mods(mod_state);
    }
    else if (alt_pressed && sft_pressed) {
        unregister_mods(mod_state);
        tap_code16(KC_RGHT);
        register_mods(mod_state);
    }
    else if (sft_pressed && ctl_pressed) {
        unregister_mods(mod_state);
        tap_code(KC_PGDN);
        register_mods(mod_state);
    }
    else if (ctl_pressed) {
        unregister_mods(mod_state);
        tap_code16(C(KC_PGDN));
        register_mods(mod_state);
    }
    else if (alt_pressed) {
        alt_tab_fw();
    }
    else if (sft_pressed) {
        unregister_mods(mod_state);
        tap_code(KC_MNXT);
        register_mods(mod_state);
    }
    else if (
        ((current_layer + PLODAH_LAYEROFFSET) % 2  == 1)
#       if defined(PLODAH_BORING_LAYER)
        && (current_layer != PLODAH_BORING_LAYER)
#       endif // PLODAH_BORING_LAYER
   ) {
        rgb_matrix_increase_sat();
    }
    else if (
        ((current_layer + PLODAH_LAYEROFFSET) % 2  == 0)
        && (current_layer != 0)
#       if defined(PLODAH_BORING_LAYER)
        && (current_layer != PLODAH_BORING_LAYER)
#       endif // PLODAH_BORING_LAYER
   ) {
        rgb_matrix_increase_val();
    }
    else {
        unregister_mods(mod_state);
        tap_code16_delay(KC_VOLU, 2);
        register_mods(mod_state);
    }
}
