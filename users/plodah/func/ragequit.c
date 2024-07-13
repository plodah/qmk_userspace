void rage_quit_fin(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 7) {
        if(IS_LAYER_ON(BORING_LAYER)) {
            SEND_STRING("Cool.");
            layer_move(0);
        }
        else {
            SEND_STRING("I'm sorry!");
            layer_move(BORING_LAYER);
        }
    }
    else{
        if(state->count >= 3) {
            SEND_STRING("Nearies");
        }
        else{
            register_code(KC_ESC);
        }
    }
};

void rage_quit_rst(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 7) {
        if(IS_LAYER_ON(BORING_LAYER)) {
            //SEND_STRING("Cool.");
            //layer_move(0);
        }
        else {
            //SEND_STRING("I'm sorry!");
            //layer_move(BORING_LAYER);
        }
    }
    else{
        if(state->count >= 3) {
            //SEND_STRING("Nearies");
        }
        else{
            unregister_code(KC_ESC);
        }
    }
};
