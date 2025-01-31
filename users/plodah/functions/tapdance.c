#if defined(TAP_DANCE_ENABLE)
  #pragma once

  #ifdef PLODAH_TAPDANCE_TAPHOLD_ENABLE

    typedef struct {
      uint16_t tap;
      uint16_t hold;
      uint16_t held;
    } tap_dance_tap_hold_t;

    void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
      tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;
      if (state->pressed) {
        if (state->count == 1
          #ifndef PERMISSIVE_HOLD
            && !state->interrupted
          #endif
        ) {
          register_code16(tap_hold->hold);
          tap_hold->held = tap_hold->hold;
        }
        else {
          register_code16(tap_hold->tap);
          tap_hold->held = tap_hold->tap;
        }
      }
    }

    void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
      tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;
      if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
      }
    }

    #define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }
  #endif // PLODAH_TAPDANCE_TAPHOLD_ENABLE

  #if defined(PLODAH_DRAGSCROLL_TAPDANCE)
    void dragscrolltd_fin(tap_dance_state_t *state, void *user_data){
      dprintf("fin; pressed:%d $dcount:%d \n", state->pressed, state->count);
      if(state->count >= 2){
        pl_dragscroll_toggle(true);
      }
      else{
        pl_dragscroll_momentary(true);
      }
    }
    void dragscrolltd_rst(tap_dance_state_t *state, void *user_data){
      if(state->count < 2){
        pl_dragscroll_momentary(false);
      }
    }
  #endif // PLODAH_DRAGSCROLL_TAPDANCE

  #if defined(PLODAH_BORING_LAYER)
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
  #endif // PLODAH_BORING_LAYER

  tap_dance_action_t tap_dance_actions[] = {
    #if defined(PLODAH_DRAGSCROLL_TAPDANCE)
      [TD_DRAGSCROLL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dragscrolltd_fin, dragscrolltd_rst),
    #endif // PLODAH_DRAGSCROLL_TAPDANCE

    #if defined(PLODAH_BORING_LAYER)
      [TD_ESC_RAGEQUIT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rage_quit_fin, rage_quit_rst),
    #endif // PLODAH_BORING_LAYER

    #if defined(PLODAH_TAPDANCE_TAPHOLD_ENABLE)
      [TD_F5] = ACTION_TAP_DANCE_TAP_HOLD(KC_5, KC_F5),
      [TD_F11] = ACTION_TAP_DANCE_TAP_HOLD(KC_MINS, KC_F11),
    #endif // DYNAMIC_MACRO_ENABLE
  };

  #if defined(PLODAH_TAPDANCE_TAPHOLD_ENABLE)
    bool tap_dance_process_record_user(uint16_t keycode, keyrecord_t *record) {
      tap_dance_action_t *action;
      switch (keycode) {
      // list all tap dance keycodes with tap-hold configurations
        case TD(TD_F5):
        case TD(TD_F11):
          action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
          if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
          }
      }
      return true;
    }
  #endif // PLODAH_TAPDANCE_TAPHOLD_ENABLE
#endif // TAP_DANCE_ENABLE
