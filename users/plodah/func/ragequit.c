#pragma once

void rage_quit_fin_act(int count){
    if (count >= 5) {
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
        if(count >= 3) {
            SEND_STRING("Nearies");
        }
        else{
            register_code(KC_ESC);
        }
    }
}
void rage_quit_rst_act(int count){
    if(count < 3) {
        unregister_code(KC_ESC);
    }
}
