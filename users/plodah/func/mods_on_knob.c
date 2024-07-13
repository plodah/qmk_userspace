void enc_press_act(bool ctl_pressed, bool sft_pressed, bool alt_pressed) {
    if (ctl_pressed && sft_pressed) {
        //CS
    }
    else if (ctl_pressed && alt_pressed) {
        //CA
    }
    else if (alt_pressed && sft_pressed) {
        //AS
    }
    else if (ctl_pressed) {
        tap_code16(C(KC_F4));
    }
    else if (alt_pressed) {
        tap_code16(A(KC_F4));
    }
    else if (sft_pressed) {
        tap_code(KC_MPLY);
    }
    else if (
        (get_highest_layer(layer_state) % 2 ) == 1
        && ( get_highest_layer(layer_state) != BORING_LAYER)
    ) {
        rgb_matrix_toggle_noeeprom();
    }
    else if (
        (get_highest_layer(layer_state) % 2 ) == 0
        && (get_highest_layer(layer_state) != 0)
        && ( get_highest_layer(layer_state) != BORING_LAYER)
    ) {
        rgb_matrix_toggle_noeeprom();
    }
    else {
        tap_code(KC_MUTE);
    }
}

void enc_ccw_act(bool ctl_pressed, bool sft_pressed, bool alt_pressed) {
    if (ctl_pressed && sft_pressed) {
        tap_code(KC_PGUP);
    }
    else if (ctl_pressed && alt_pressed) {
        //CA
    }
    else if (alt_pressed && sft_pressed) {
        tap_code16(C(KC_RGHT));
    }
    else if (ctl_pressed) {
        tap_code16(C(S(KC_TAB)));
    }
    else if (alt_pressed) {
        alt_tab_bk();
    }
    else if (sft_pressed) {
        tap_code(KC_MPRV);
    }
    else if (
        (get_highest_layer(layer_state) % 2 ) == 1
        && ( get_highest_layer(layer_state) != BORING_LAYER)
    ) {
        rgb_matrix_decrease_sat_noeeprom();
    }
    else if (
        (get_highest_layer(layer_state) % 2 ) == 0
        && (get_highest_layer(layer_state) != 0)
        && ( get_highest_layer(layer_state) != BORING_LAYER)
    ) {
        rgb_matrix_decrease_val_noeeprom();
    }
    else {
        tap_code16_delay(KC_VOLD, 2);
    }
}

void enc_cw_act(bool ctl_pressed, bool sft_pressed, bool alt_pressed) {
    if (ctl_pressed && sft_pressed) {
        tap_code(KC_PGDN);
    }
    else if (ctl_pressed && alt_pressed) {
        //CA
    }
    else if (alt_pressed && sft_pressed) {
        tap_code16(C(KC_LEFT));
    }
    else if (ctl_pressed) {
        tap_code16(C(KC_TAB));
    }
    else if (alt_pressed) {
        alt_tab_fw();
    }
    else if (sft_pressed) {
        tap_code(KC_MNXT);
    }
    else if (
        (get_highest_layer(layer_state) % 2 ) == 1
        && ( get_highest_layer(layer_state) != BORING_LAYER)
    ) {
        rgb_matrix_increase_sat_noeeprom();
    }
    else if (
        (get_highest_layer(layer_state) % 2 ) == 0
        && (get_highest_layer(layer_state) != 0)
        && ( get_highest_layer(layer_state) != BORING_LAYER)
    ) {
        rgb_matrix_increase_val_noeeprom();
    }
    else {
        tap_code16_delay(KC_VOLU, 2);
    }
}
