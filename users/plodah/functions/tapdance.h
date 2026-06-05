#pragma once

#include "process_tap_dance.h"
#include "keymap_introspection.h"

#if defined(PLODAH_TAPDANCE_TAPHOLD_ENABLE)
    typedef struct {
        uint16_t tap;
        uint16_t hold;
        uint16_t held;
    } tap_dance_tap_hold_t;
    bool process_record_tapdance_taphold(uint16_t keycode, keyrecord_t *record);
#endif // PLODAH_TAPDANCE_TAPHOLD_ENABLE

#if defined(BETTER_DRAGSCROLL_TAPDANCE)

#endif // BETTER_DRAGSCROLL_TAPDANCE

#if defined(PLODAH_BORING_LAYER)

#endif // PLODAH_BORING_LAYER

#if defined(PLODAH_TAPDANCE_MOAR_ENABLE)
    typedef enum {
        TD_NONE,
        TD_UNKNOWN,
        TD_SINGLE_TAP,
        TD_SINGLE_HOLD,
        TD_DOUBLE_TAP,
        TD_DOUBLE_HOLD,
        TD_DOUBLE_SINGLE_TAP, // Send two single taps
        TD_TRIPLE_TAP,
        TD_TRIPLE_HOLD
    } td_state_t;

    typedef struct {
        bool is_press_action;
        td_state_t state;
    } td_tap_t;

    td_state_t cur_dance(tap_dance_state_t *state);
    void x_finished(tap_dance_state_t *state, void *user_data);
    void x_reset(tap_dance_state_t *state, void *user_data);
#endif // PLODAH_TAPDANCE_MOAR_ENABLE
