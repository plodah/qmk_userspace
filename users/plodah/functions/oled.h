#include QMK_KEYBOARD_H
#if defined(OLED_ENABLE)
    #pragma once

    #if !defined(OLED_TIMEOUT)
        #define OLED_TIMEOUT (5 * 60 * 1000) // 5 minutes
    #endif // OLED_TIMEOUT
    #if !defined(OLED_UPDATE_INTERVAL)
        #define OLED_UPDATE_INTERVAL 125
    #endif // OLED_UPDATE_INTERVAL

    bool is_oled_enabled;
    void housekeeping_task_oled(void);
    bool process_record_oled(uint16_t keycode, keyrecord_t *record);
    bool shutdown_oled(bool jump_to_bootloader);

    #if defined(AUTOCORRECT_ENABLE)
        #if !defined(AUTOCORRECT_OLED_DISPLAY_COUNT)
            #define AUTOCORRECT_OLED_DISPLAY_COUNT 3
        #endif // AUTOCORRECT_OLED_DISPLAY_COUNT
        #if !defined(AUTOCORRECT_OLED_DISPLAY_LENGTH)
            #define AUTOCORRECT_OLED_DISPLAY_LENGTH 5
        #endif
        bool apply_autocorrect_oled(uint8_t backspaces, const char *str, char *typo, char *correct);
        void keyboard_post_init_user_oled(void);
        char recAc[AUTOCORRECT_OLED_DISPLAY_COUNT][15];
    #endif // AUTOCORRECT_ENABLE
#endif // defined(OLED_ENABLE)
