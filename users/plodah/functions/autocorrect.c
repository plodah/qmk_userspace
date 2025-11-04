#if defined(AUTOCORRECT_ENABLE)
    #include QMK_KEYBOARD_H
    #include <stdbool.h>
    #include <stdint.h>

    #if defined(OLED_ENABLE)
        #include "functions/oled.h"
    #endif // defined(OLED_ENABLE)

    #if defined(COMMUNITY_MODULE_AUTOCORRECT_RGBFLASH_ENABLE)
        #include "autocorrect_rgbflash.h"
    #endif // COMMUNITY_MODULE_AUTOCORRECT_RGBFLASH_ENABLE

    bool process_autocorrect_user(uint16_t *keycode, keyrecord_t *record, uint8_t *typo_buffer_size, uint8_t *mods) {
        #if defined(PLODAH_BORING_LAYER)
            if( get_highest_layer(layer_state) == PLODAH_BORING_LAYER){
                return false;
            }
        #endif // defined(PLODAH_BORING_LAYER)
        if ((*mods & ~MOD_MASK_SHIFT) != 0) {
            *typo_buffer_size = 0;
            return false;
        }
        switch (*keycode) {
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
                if (!record->tap.count) {
                    return false;
                }
                *keycode &= 0xFF;
                break;
        }
        return true;
    }

    bool apply_autocorrect(uint8_t backspaces, const char *str, char *typo, char *correct) {
        #if defined(OLED_ENABLE)
            apply_autocorrect_oled(backspaces, str, typo, correct);
        #endif // defined(OLED_ENABLE)

        #if defined(COMMUNITY_MODULE_AUTOCORRECT_RGBFLASH_ENABLD)
            apply_autocorrect_autocorrect_rgbflash(backspaces, str, typo, correct);
        #endif // COMMUNITY_MODULE_AUTOCORRECT_RGBFLASH_ENABLE
        return true;
    }
#endif // AUTOCORRECT_ENABLE
