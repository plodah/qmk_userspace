#pragma once

#include "process_tap_dance.h"
#include "keymap_introspection.h"

#if defined(BETTER_DRAGSCROLL_TAPDANCE)
    void dragscrolltd_fin(tap_dance_state_t *state, void *user_data);
    void dragscrolltd_rst(tap_dance_state_t *state, void *user_data);
#endif // defined(BETTER_DRAGSCROLL_TAPDANCE)

#if defined(PLODAH_BORING_LAYER)
    void rage_quit_fin(tap_dance_state_t *state, void *user_data);
    void rage_quit_rst(tap_dance_state_t *state, void *user_data);
#endif // defined(PLODAH_BORING_LAYER)

#if defined(PLODAH_TAPDANCE_TAPHOLD_ENABLE)
    typedef struct {
        uint16_t tap;
        uint16_t hold;
        uint16_t held;
    } tap_dance_tap_hold_t;
    bool process_record_tapdance_taphold(uint16_t keycode, keyrecord_t *record);
    void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data);
    void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data);
    #define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }
#endif // defined(PLODAH_TAPDANCE_TAPHOLD_ENABLE)
