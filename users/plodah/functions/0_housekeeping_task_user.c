#if ( defined(AUTOCORRECT_ENABLE) && defined(RGB_MATRIX_ENABLE) && (!defined(AUTOCORRECT_RGBFLASH_MODE_DE)) ) || (defined(PLODAH_TYPINGINDICATOR_RGBINDEX)) || (defined(DYNAMIC_MACRO_ENABLE) && defined(PLODAH_DYNAMIC_MACRO_TIMEOUT) && !defined(PLODAH_DYNAMIC_MACRO_TIMEOUT_MODE_DE)) || (defined(PLODAH_REPEATHOLD_RGB) && defined(RGB_MATRIX_ENABLE))
    #pragma once

    #include "dynamic_macros.h"
    #include "repeathold_rgb.h"
    #if defined(PLODAH_TYPINGINDICATOR_RGBINDEX)
        #include "indicators.h"
    #endif // PLODAH_TYPINGINDICATOR_RGBINDEX

    void housekeeping_task_user(void) {
        #if defined(COMMUNITY_MODULE_AUTOCORRECT_RGBFLASH_ENABLE) && (!defined(AUTOCORRECT_RGBFLASH_MODE_DE))
            housekeeping_task_autocorrect_rgbflash();
        #endif // AUTOCORRECT_ENABLE && RGB_MATRIX_ENABLE
        #if defined(PLODAH_TYPINGINDICATOR_RGBINDEX)
            housekeeping_task_typing_indicator();
        #endif // PLODAH_TYPINGINDICATOR_RGBINDEX
        #if defined(DYNAMIC_MACRO_ENABLE) && defined(PLODAH_DYNAMIC_MACRO_TIMEOUT) && !defined(PLODAH_DYNAMIC_MACRO_TIMEOUT_MODE_DE)
            housekeeping_task_plodah_dynamic_macro();
        #endif // defined(DYNAMIC_MACRO_ENABLE) && defined(PLODAH_DYNAMIC_MACRO_TIMEOUT)
        #if defined(PLODAH_REPEATHOLD_RGB) && defined(RGB_MATRIX_ENABLE)
            housekeeping_task_repeathold_rgb();
        #endif // defined(PLODAH_REPEATHOLD_RGB) && defined(RGB_MATRIX_ENABLE)
    }

#endif // ( defined(AUTOCORRECT_ENABLE) && defined(RGB_MATRIX_ENABLE) ) || (defined(PLODAH_TYPINGINDICATOR_RGBINDEX))
