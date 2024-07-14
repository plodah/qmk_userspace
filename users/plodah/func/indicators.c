#pragma once

#ifdef LAYER_IND_ONZERO
#  define LAYER_IND_ONZERO_I 1
#else
#  define LAYER_IND_ONZERO_I -1
#endif

#ifndef CAPS_LOCK_LED_INDEX
#  define CAPS_LOCK_LED_INDEX -1
#endif
#ifndef LAYER_IND_GRVINDEX
#  define LAYER_IND_GRVINDEX -1
#endif

void plodah_indicator_handler( uint8_t led_min, uint8_t led_max ){
    if( led_max >= CAPS_LOCK_LED_INDEX && CAPS_LOCK_LED_INDEX >= led_min ) {
        if (host_keyboard_led_state().caps_lock) {
            RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_LED_INDEX, 255, 0, 0);
        } else {
            if ( !rgb_matrix_get_flags() ) {
                RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_LED_INDEX, 0, 0, 0);
            }
        }
    }
    if( led_max >= LAYER_IND_GRVINDEX && LAYER_IND_GRVINDEX >= led_min ) {
        int highlayer = get_highest_layer(layer_state);
        for ( int lindex = 0; lindex < DYNAMIC_KEYMAP_LAYER_COUNT; lindex++ ) {
            if ( highlayer == lindex ) {
                if ( highlayer != 0 || LAYER_IND_ONZERO_I == 1 ) {
                    RGB_MATRIX_INDICATOR_SET_COLOR( (LAYER_IND_GRVINDEX + lindex ) , 255, 0, 0 );
                }
            }
            else {
                if ( !rgb_matrix_get_flags() ) {
                    RGB_MATRIX_INDICATOR_SET_COLOR( (LAYER_IND_GRVINDEX + lindex ), 0, 0, 0 );
                }
            }
        }
    }
}
