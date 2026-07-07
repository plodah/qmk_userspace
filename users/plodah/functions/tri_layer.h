#pragma once
#include QMK_KEYBOARD_H

bool process_record_tri_layer(uint16_t keycode, keyrecord_t *record);
layer_state_t layer_state_set_tri_layer(layer_state_t state);
