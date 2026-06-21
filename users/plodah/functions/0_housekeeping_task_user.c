#if ( defined(AUTOCORRECT_ENABLE) && defined(RGB_MATRIX_ENABLE) && (!defined(AUTOCORRECT_RGBFLASH_MODE_DE)) ) || (defined(PLODAH_TYPINGINDICATOR_RGBINDEX)) || (defined(DYNAMIC_MACRO_ENABLE) && defined(PLODAH_DYNAMIC_MACRO_TIMEOUT) && !defined(PLODAH_DYNAMIC_MACRO_TIMEOUT_MODE_DE)) || (defined(PLODAH_REPEATHOLD_RGB) && defined(RGB_MATRIX_ENABLE))
    #pragma once

    #include "dynamic_macros.h"
    #if defined(PLODAH_TYPINGINDICATOR_RGBINDEX)
        #include "indicators.h"
    #endif // PLODAH_TYPINGINDICATOR_RGBINDEX
    #if defined(OLED_ENABLE)
        #include "oled.h"
    #endif // defined(OLED_ENABLE)

    void housekeeping_task_user(void) {
        #if defined(PLODAH_TYPINGINDICATOR_RGBINDEX)
            housekeeping_task_typing_indicator();
        #endif // PLODAH_TYPINGINDICATOR_RGBINDEX
        #if defined(DYNAMIC_MACRO_ENABLE) && defined(PLODAH_DYNAMIC_MACRO_TIMEOUT) && !defined(PLODAH_DYNAMIC_MACRO_TIMEOUT_MODE_DE)
            housekeeping_task_plodah_dynamic_macro();
        #endif // defined(DYNAMIC_MACRO_ENABLE) && defined(PLODAH_DYNAMIC_MACRO_TIMEOUT)
        #if defined (OLED_ENABLE)
            housekeeping_task_oled();
        #endif // defined (OLED_ENABLE)
    }

#endif // ( defined(AUTOCORRECT_ENABLE) && defined(RGB_MATRIX_ENABLE) ) || (defined(PLODAH_TYPINGINDICATOR_RGBINDEX))
