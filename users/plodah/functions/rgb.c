#pragma once

#ifdef RGB_MATRIX_ENABLE
  HSV plodah_rgblimit(HSV currenthsv, HSV target_hsv, uint8_t minval){
    HSV output = target_hsv;
    if(minval > currenthsv.v){
        output.v = minval;
    }
    else if(target_hsv.v > currenthsv.v ){
        output.v = currenthsv.v;
    }
    return output;
  }
  HSV plodah_rgblimit_ind(HSV currenthsv, uint8_t target_h, uint8_t target_s, uint8_t target_v, uint8_t minval){
    HSV output = {target_h, target_s, target_v};
    if(minval > currenthsv.v){
        output.v = minval;
    }
    else if(target_v > currenthsv.v ){
        output.v = currenthsv.v;
    }
    return output;
  }
  HSV plodah_rgblimit_i(HSV currenthsv, uint8_t target_h, uint8_t target_s, uint8_t target_v, uint8_t minval){
    HSV target_hsv = {target_h, target_s, target_v};
    return plodah_rgblimit(currenthsv, target_hsv, minval);
  }
#endif // RGB_MATRIX_ENABLE

char* rgbQuery(void){
    //may take 80 bytes more than sending string directly
    char * str;
    str = malloc(sizeof(char)*50);
    #ifdef RGB_MATRIX_ENABLE
        strcpy (str, "\\ RGB_MATRIX:");
        strcat (str, get_u8_str(rgb_matrix_get_mode(), '0'));
        strcat (str, " H:");
        strcat (str, get_u8_str(rgb_matrix_get_hue(), '0'));
        strcat (str, " S:");
        strcat (str, get_u8_str(rgb_matrix_get_sat(), '0'));
        strcat (str, " V:");
        strcat (str, get_u8_str(rgb_matrix_get_val(), '0'));
        strcat (str, " SP:");
        strcat (str, get_u8_str(rgb_matrix_get_speed(), '0'));
        strcat (str, " \n");
    #endif // RGB_MATRIX_ENABLE
    #ifdef RGBLIGHT_ENABLE
        strcpy (str, "\\ RGBLIGHT:");
        strcat (str, get_u8_str(rgblight_get_mode(), '0'));
        strcat (str, " H:");
        strcat (str, get_u8_str(rgblight_get_hue(), '0'));
        strcat (str, " S:");
        strcat (str, get_u8_str(rgblight_get_sat(), '0'));
        strcat (str, " V:");
        strcat (str, get_u8_str(rgblight_get_val(), '0'));
        strcat (str, " SP:");
        strcat (str, get_u8_str(rgblight_get_speed(), '0'));
        strcat (str, " \n");
    #endif // RGBLIGHT_ENABLE
    #if ( ! (defined(RGB_MATRIX_ENABLE) ) || ( defined(RGBLIGHT_ENABLE) ) )
        strcpy (str, "\\ No RGB! \n");
    #endif // NO RGB_MATRIX_ENABLE OR RGBLIGHT_ENABLE
    return str;
}

char * rgbQuerySmert(void)
{
    char * str;
    str = malloc(sizeof(char)*50);
    #ifdef RGB_MATRIX_ENABLE
        snprintf (str, 50, "\\ RGB_MATRIX:%d H:%d S:%d V:%d SP:%d \n", rgb_matrix_get_mode(), rgb_matrix_get_hue(), rgb_matrix_get_sat(), rgb_matrix_get_val(), rgb_matrix_get_speed());
    #endif // RGB_MATRIX_ENABLE
    #ifdef RGBLIGHT_ENABLE
        snprintf (str, 50, "\\ RGBLIGHT:%d H:%d S:%d V:%d SP:%d \n", rgblight_get_mode(), rgblight_get_hue(), rgblight_get_sat(), rgblight_get_val(), rgblight_get_speed());
    #endif // RGBLIGHT_ENABLE
    #if ( ! (defined(RGB_MATRIX_ENABLE) ) || ( defined(RGBLIGHT_ENABLE) ) )
        strcpy (str, "\\ No RGB! \n");
    #endif // NO RGB_MATRIX_ENABLE OR RGBLIGHT_ENABLE
    return str;
}

void rgbQuerySs(void)
{
    #ifdef RGB_MATRIX_ENABLE
        send_string_with_delay ( "\\ RGB_MATRIX:", TAP_CODE_DELAY );
        send_string_with_delay ( get_u8_str(rgb_matrix_get_mode(),'0'), TAP_CODE_DELAY );
        send_string_with_delay ( " H:", TAP_CODE_DELAY );
        send_string_with_delay ( get_u8_str(rgb_matrix_get_hue(),'0'), TAP_CODE_DELAY );
        send_string_with_delay ( " S:", TAP_CODE_DELAY );
        send_string_with_delay ( get_u8_str(rgb_matrix_get_sat(),'0'), TAP_CODE_DELAY );
        send_string_with_delay ( " V:", TAP_CODE_DELAY );
        send_string_with_delay ( get_u8_str(rgb_matrix_get_val(),'0'), TAP_CODE_DELAY );
        send_string_with_delay ( " SP:", TAP_CODE_DELAY );
        send_string_with_delay ( get_u8_str(rgb_matrix_get_speed(),'0'), TAP_CODE_DELAY );
        send_string_with_delay ( " \n", TAP_CODE_DELAY );
    #endif // RGB_MATRIX_ENABLE
    #ifdef RGBLIGHT_ENABLE
        send_string_with_delay ( "\\ RGBLIGHT:", TAP_CODE_DELAY );
        send_string_with_delay ( get_u8_str(rgblight_get_mode(),'0'), TAP_CODE_DELAY );
        send_string_with_delay ( " H:", TAP_CODE_DELAY );
        send_string_with_delay ( get_u8_str(rgblight_get_hue(),'0'), TAP_CODE_DELAY );
        send_string_with_delay ( " S:", TAP_CODE_DELAY );
        send_string_with_delay ( get_u8_str(rgblight_get_sat(),'0'), TAP_CODE_DELAY );
        send_string_with_delay ( " V:", TAP_CODE_DELAY );
        send_string_with_delay ( get_u8_str(rgblight_get_val(),'0'), TAP_CODE_DELAY );
        send_string_with_delay ( " SP:", TAP_CODE_DELAY );
        send_string_with_delay ( get_u8_str(rgblight_get_speed(),'0'), TAP_CODE_DELAY );
        send_string_with_delay ( " \n", TAP_CODE_DELAY );
    #endif // RGBLIGHT_ENABLE
    #if ( ! (defined(RGB_MATRIX_ENABLE) ) || ( defined(RGBLIGHT_ENABLE) ) )
        send_string_with_delay ( "\\ No RGB! \n", TAP_CODE_DELAY );
    #endif // NO RGB_MATRIX_ENABLE OR RGBLIGHT_ENABLE
}
