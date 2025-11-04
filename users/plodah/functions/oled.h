#if defined(OLED_ENABLE)
    #pragma once
    #if !defined(OLED_TIMEOUT)
        #define OLED_TIMEOUT 300000
    #endif // OLED_TIMEOUT
    #if !defined(OLED_UPDATE_INTERVAL)
        #define OLED_UPDATE_INTERVAL 125
    #endif // OLED_UPDATE_INTERVAL

    #if defined(AUTOCORRECT_ENABLE)
        bool apply_autocorrect_oled(uint8_t backspaces, const char *str, char *typo, char *correct);
        void keyboard_post_init_user_oled(void);
        char recAcA[15];
        char recAcB[15];
        char recAcC[15];
    #endif // AUTOCORRECT_ENABLE
#endif // defined(OLED_ENABLE)
