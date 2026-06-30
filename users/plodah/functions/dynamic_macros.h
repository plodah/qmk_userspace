#if defined(DYNAMIC_MACRO_ENABLE)
    #pragma once
    #include "deferred_exec.h"
    #include QMK_KEYBOARD_H

    // #define PLODAH_DYNAMIC_MACRO_FORCE_NDE // define for debug
    #if defined(DEFERRED_EXEC_ENABLE) && defined(PLODAH_DYNAMIC_MACRO_TIMEOUT) && (!defined(PLODAH_DYNAMIC_MACRO_FORCE_NDE))
        #define PLODAH_DYNAMIC_MACRO_TIMEOUT_MODE_DE
    #endif // DEFERRED_EXEC_ENABLE

    #if defined(PLODAH_DYNAMIC_MACRO_TIMEOUT) && !defined(PLODAH_DYNAMIC_MACRO_TIMEOUT_MODE_DE)
        void housekeeping_task_plodah_dynamic_macro(void);
    #endif // defined(PLODAH_DYNAMIC_MACRO_TIMEOUT) && !defined(PLODAH_DYNAMIC_MACRO_TIMEOUT_MODE_DE)
#endif // DYNAMIC_MACRO_ENABLE
