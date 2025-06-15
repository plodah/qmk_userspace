#if defined(AUTOCORRECT_ENABLE)
    #pragma once

    #if defined(DEFERRED_EXEC_ENABLE) && (!defined(PLODAH_AUTOCORRECT_INDICATOR_FORCE_NDE))
        #include "deferred_exec.h"
        #define PLODAH_AUTOCORRECT_IND_MODE_DE
    #endif // DEFERRED_EXEC_ENABLE

    #if defined(PLODAH_AUTOCORRECT_IND_MODE_DE)
        // #pragma message("Deferred Exec Autocorrect")
        deferred_token autoCorrectIndToken = INVALID_DEFERRED_TOKEN;
    #else // PLODAH_AUTOCORRECT_IND_MODE_DE
        bool autocorrect_indicator_on = false;
        uint16_t autocorrect_indicator_timer = 0;
    #endif // PLODAH_AUTOCORRECT_IND_MODE_DE

    #if defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE)

        #ifndef PLODAH_AUTOCORRECT_INDICATOR_DURATION
            #define PLODAH_AUTOCORRECT_INDICATOR_DURATION 200
        #endif //PLODAH_AUTOCORRECT_INDICATOR_DURATION

        #ifndef PLODAH_AUTOCORRECT_INDICATOR_BLINKCOUNT
            #define PLODAH_AUTOCORRECT_INDICATOR_BLINKCOUNT 3
        #endif // PLODAH_AUTOCORRECT_INDICATOR_BLINKCOUNT

        #ifndef PLODAH_AUTOCORRECT_INDICATOR_COLOUR
            #define PLODAH_AUTOCORRECT_INDICATOR_COLOUR HSV_RED
        #endif //PLODAH_AUTOCORRECT_INDICATOR_COLOUR

        #ifndef PLODAH_INDICATOR_MINVAL
            #define PLODAH_INDICATOR_MINVAL 85
        #endif // PLODAH_INDICATOR_MINVAL

        #if !defined(PLODAH_AUTOCORRECT_IND_MODE_DE)
            void housekeeping_task_autocorrect_indicator(void);
        #endif // #if !defined(PLODAH_AUTOCORRECT_IND_MODE_DE)

    #endif // defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE)
#endif // defined(AUTOCORRECT_ENABLE)
