#if defined(DYNAMIC_MACRO_ENABLE)
    #include "dynamic_macros.h"
#endif // defined(DYNAMIC_MACRO_ENABLE)

#if defined(OLED_ENABLE)
    #include "oled.h"
#endif // defined(OLED_ENABLE)

#if (defined(DYNAMIC_MACRO_ENABLE) && defined(PLODAH_DYNAMIC_MACRO_TIMEOUT) && !defined(PLODAH_DYNAMIC_MACRO_TIMEOUT_MODE_DE)) || (defined (OLED_ENABLE))
    void housekeeping_task_user(void) {
        #if defined(DYNAMIC_MACRO_ENABLE) && defined(PLODAH_DYNAMIC_MACRO_TIMEOUT) && !defined(PLODAH_DYNAMIC_MACRO_TIMEOUT_MODE_DE)
            housekeeping_task_plodah_dynamic_macro();
        #endif // defined(DYNAMIC_MACRO_ENABLE) && defined(PLODAH_DYNAMIC_MACRO_TIMEOUT)
        #if defined (OLED_ENABLE)
            housekeeping_task_oled();
        #endif // defined (OLED_ENABLE)
    }
#endif // (defined(DYNAMIC_MACRO_ENABLE) && defined(PLODAH_DYNAMIC_MACRO_TIMEOUT) && !defined(PLODAH_DYNAMIC_MACRO_TIMEOUT_MODE_DE)) || (defined (OLED_ENABLE))
