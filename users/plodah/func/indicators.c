#pragma once

bool plodah_indicator_handler( void ) {
#   ifdef CAPS_LOCK_LED_INDEX
    if ( host_keyboard_led_state( ).caps_lock ) {
#       ifdef PLODAH_CAPS_INDIC_RGB
            rgb_matrix_set_color( CAPS_LOCK_LED_INDEX, PLODAH_CAPS_INDIC_RGB );
#       else // PLODAH_CAPS_INDICATOR_R/G/B
            rgb_matrix_set_color( CAPS_LOCK_LED_INDEX, RGB_RED );
#       endif // PLODAH_CAPS_INDICATOR_R/G/B
    } else {
        if ( !rgb_matrix_get_flags( ) ) {
            rgb_matrix_set_color( CAPS_LOCK_LED_INDEX, RGB_OFF );
        }
    }
#   endif
#   ifdef PLODAH_LAYER_INDIC_GRVINDEX
#       ifdef PLODAH_LAYER_INDIC_ONZERO
            bool onzero = true;
#       else
            bool onzero = false;
#       endif
        int highlayer = get_highest_layer( layer_state );
        for ( int lindex = 0; lindex < DYNAMIC_KEYMAP_LAYER_COUNT; lindex++ ) {
            int thisindex = ( lindex + PLODAH_LAYER_INDIC_GRVINDEX );
            if ( !rgb_matrix_get_flags( ) ) {
                rgb_matrix_set_color( thisindex, RGB_OFF );
            }
            if ( highlayer == lindex && ( lindex != 0 || onzero ) ) {
#               ifdef PLODAH_LAYER_INDIC_RGB
                    rgb_matrix_set_color( thisindex, PLODAH_LAYER_INDIC_RGB );
#               else //PLODAH_LAYER_INDIC_RGB
                    rgb_matrix_set_color( thisindex, RGB_RED );
#               endif //PLODAH_LAYER_INDIC_RGB
            }
            else {
#               ifdef PLODAH_LAYER_INDIC_BG_RGB
                    if ( highlayer != lindex && ( lindex != 0 || onzero ) ) {
                        rgb_matrix_set_color( thisindex, PLODAH_LAYER_INDIC_BG_RGB );
                    }
#               endif
            }
        }

#   endif //PLODAH_LAYER_INDIC_GRVINDEX
    return false;
}
