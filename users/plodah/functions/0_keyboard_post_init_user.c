#include QMK_KEYBOARD_H
#if defined(CONSOLE_ENABLE)
    #include "debug.h"
#endif // defined(CONSOLE_ENABLE)

#if (defined(VIA_ENABLE) && defined(PLOOPY_VIAMENUS))
    #include "ploopy_via.h"
#endif // (defined(VIA_ENABLE) && defined(PLOOPY_VIAMENUS))

#if defined(OLED_ENABLE) && defined(AUTOCORRECT_ENABLE)
    #include "oled.h"
#endif // defined(OLED_ENABLE) && defined(AUTOCORRECT_ENABLE)

#if defined(CONSOLE_ENABLE) || (defined(VIA_ENABLE) && defined(PLOOPY_VIAMENUS)) || (defined(OLED_ENABLE) && defined(AUTOCORRECT_ENABLE))
    void keyboard_post_init_user(void) {
        #ifdef CONSOLE_ENABLE
            keyboard_post_init_user_debug();
        #endif // CONSOLE_ENABLE
        #if defined(VIA_ENABLE) && defined(PLOOPY_VIAMENUS)
            keyboard_post_init_user_viamenus();
        #endif // defined(VIA_ENABLE) && defined(PLOOPY_VIAMENUS)
        #if defined(OLED_ENABLE) && defined(AUTOCORRECT_ENABLE)
            keyboard_post_init_user_oled();
        #endif // defined(OLED_ENABLE) && defined(AUTOCORRECT_ENABLE)
    }
#endif // CONSOLE_ENABLE
