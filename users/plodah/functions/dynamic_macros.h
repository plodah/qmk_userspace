#if defined(DYNAMIC_MACRO_ENABLE)
    #pragma once
    #include "deferred_exec.h"
    #if (defined(RGB_MATRIX_ENABLE) && defined(PLODAH_DMAC_INDIC_INDEX)) || (defined(PLODAH_DYNAMIC_MACRO_TIMEOUT))
        bool is_dynamic_macro_recording = false;
    #endif // (defined(RGB_MATRIX_ENABLE) && defined(PLODAH_DMAC_INDIC_INDEX)) || (defined(PLODAH_DYNAMIC_MACRO_TIMEOUT))

    // #define PLODAH_DYNAMIC_MACRO_FORCE_NDE // define for debug
    #if defined(DEFERRED_EXEC_ENABLE) && defined(PLODAH_DYNAMIC_MACRO_TIMEOUT) && (!defined(PLODAH_DYNAMIC_MACRO_FORCE_NDE))
        #define PLODAH_DYNAMIC_MACRO_TIMEOUT_MODE_DE
    #endif // DEFERRED_EXEC_ENABLE

    #if defined(PLODAH_DYNAMIC_MACRO_TIMEOUT_MODE_DE)
        // #pragma message("Deferred Exec Dynamic Macro Timeout")
        deferred_token dynamicMacroToken = INVALID_DEFERRED_TOKEN;
    #else
        // #pragma message("Non-DE Dynamic Macro Timeout")
        uint16_t dynamic_macro_timer;
    #endif // PLODAH_DYNAMIC_MACRO_TIMEOUT_MODE_DE

    #if defined(PLODAH_DYNAMIC_MACRO_KCS_ENABLE)
        bool process_record_plodah_dynamic_macros( uint16_t keycode, keyrecord_t *record );
    #endif // PLODAH_DYNAMIC_MACRO_KCS_ENABLE

    #if defined(PLODAH_DYNAMIC_MACRO_TIMEOUT) && !defined(PLODAH_DYNAMIC_MACRO_TIMEOUT_MODE_DE)
        void housekeeping_task_plodah_dynamic_macro(void);
    #endif // defined(PLODAH_DYNAMIC_MACRO_TIMEOUT) && !defined(PLODAH_DYNAMIC_MACRO_TIMEOUT_MODE_DE)
#endif // DYNAMIC_MACRO_ENABLE
