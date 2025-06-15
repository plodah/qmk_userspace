#if defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE)
    #pragma once
    #if defined(RGB_MATRIX_ENABLE)
        #include "rgb_matrix.h"
    #endif // RGB_MATRIX_ENABLE
    #if defined(RGBLIGHT_ENABLE)
        #include "rgblight.h"
    #endif // RGBLIGHT_ENABLE
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
        HSV target_hsv = {target_h, target_s, target_v};
        return plodah_rgblimit(currenthsv, target_hsv, minval);
    }
#endif // defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE)
