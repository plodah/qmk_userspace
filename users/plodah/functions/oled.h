#if defined(OLED_ENABLE)
    #pragma once
    #if !defined(OLED_TIMEOUT)
        #define OLED_TIMEOUT 300000
    #endif // OLED_TIMEOUT
    #if !defined(OLED_UPDATE_INTERVAL)
        #define OLED_UPDATE_INTERVAL 125
    #endif // OLED_UPDATE_INTERVAL

    #if defined(AUTOCORRECT_ENABLE)
        char recAcA[15] = "__________";
        char recAcB[15] = "__________";
        char recAcC[15] = "__________";
    #endif // AUTOCORRECT_ENABLE
#endif // defined(OLED_ENABLE)
