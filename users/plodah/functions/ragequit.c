#pragma once

void rage_quit_fin(tap_dance_state_t *state, void *user_data){
  if(state->count >= 5){
    if(IS_LAYER_ON(PLODAH_BORING_LAYER)){
      send_string_with_delay ("Cool.", TAP_CODE_DELAY);
      layer_move(0);
    }
    else{
      send_string_with_delay ("I'm sorry!", TAP_CODE_DELAY);
      layer_move(PLODAH_BORING_LAYER);
    }
  }
  else{
    if(state->count >= 3){
      send_string_with_delay ("Nearies", TAP_CODE_DELAY);
    }
    else{
      register_code(KC_ESC);
    }
  }
};

void rage_quit_rst(tap_dance_state_t *state, void *user_data){
  if(state->count < 3){
    unregister_code(KC_ESC);
  }
};
