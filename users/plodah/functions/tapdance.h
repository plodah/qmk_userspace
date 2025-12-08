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
