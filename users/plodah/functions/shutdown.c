#include QMK_KEYBOARD_H
#include "oled.h"

#if defined(OLED_ENABLE)
    bool shutdown_user(bool jump_to_bootloader) {
        shutdown_oled(jump_to_bootloader);
        return true;
    }
#endif // defined(OLED_ENABLE)
