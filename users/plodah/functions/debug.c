#ifdef CONSOLE_ENABLE
    #include "debug.h"
    #pragma once
    void keyboard_post_init_user_debug(void) {
        debug_enable = true;
        // debug_matrix = true;
        // debug_keyboard = true;
        // debug_mouse = true;
    }
#endif // CONSOLE_ENABLE
