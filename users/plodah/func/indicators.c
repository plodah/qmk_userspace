#pragma once

void plodah_indicator_handler( uint8_t led_min, uint8_t led_max ) {
#   ifdef CAPS_LOCK_LED_INDEX
    if ( led_max >= CAPS_LOCK_LED_INDEX && CAPS_LOCK_LED_INDEX >= led_min ) {
        if ( host_keyboard_led_state( ).caps_lock ) {
            RGB_MATRIX_INDICATOR_SET_COLOR( CAPS_LOCK_LED_INDEX, 255, 0, 0 );
        } else {
            if ( !rgb_matrix_get_flags( ) ) {
                RGB_MATRIX_INDICATOR_SET_COLOR( CAPS_LOCK_LED_INDEX, 0, 0, 0 );
            }
        }
    }
#   endif
#   ifdef LAYER_IND_GRVINDEX
    //if ( led_max >= ( LAYER_IND_GRVINDEX + DYNAMIC_KEYMAP_LAYER_COUNT ) && LAYER_IND_GRVINDEX >= led_min ) {
    //if ( led_max >= ( LAYER_IND_GRVINDEX + DYNAMIC_KEYMAP_LAYER_COUNT ) ) {
    //if ( LAYER_IND_GRVINDEX >= led_min ) {
#       ifdef LAYER_IND_ONZERO
            bool onzero = true;
#       else
            bool onzero = false;
#       endif

        int highlayer = get_highest_layer( layer_state );
        for ( int lindex = 0; lindex < DYNAMIC_KEYMAP_LAYER_COUNT; lindex++ ) {
            int thisindex = ( lindex + LAYER_IND_GRVINDEX );
            if ( highlayer == lindex && ( lindex != 0 || onzero ) ) {
                RGB_MATRIX_INDICATOR_SET_COLOR( thisindex, 255, 0, 0 );
            }
            else {
#               ifdef LAYER_IND_BACKGROUND
                    if ( highlayer != lindex && ( lindex != 0 || onzero ) ) {
                        RGB_MATRIX_INDICATOR_SET_COLOR( thisindex, 0, 255, 255 );
                    }
#               endif
            }
        }
    //}
#   endif //LAYER_IND_GRVINDEX
}
