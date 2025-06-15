#if defined(AUTOCORRECT_ENABLE)
    #pragma once
    #include "functions/autocorrect.h"
    #include "functions/oled.h"
    #include <stdint.h>
    #include "action_layer.h"

    #if defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE)
        #if defined(RGB_MATRIX_ENABLE)
            #include "rgb_matrix.h"
        #endif // RGB_MATRIX_ENABLE
        #if defined(RGBLIGHT_ENABLE)
            #include "rgblight.h"
        #endif // RGBLIGHT_ENABLE
        #include "functions/rgb.h"
        // #define PLODAH_AUTOCORRECT_INDICATOR_FORCE_NDE  // define for degug purposes
        #if defined(DEFERRED_EXEC_ENABLE) && (!defined(PLODAH_AUTOCORRECT_INDICATOR_FORCE_NDE))
            #include "deferred_exec.h"
        #endif // DEFERRED_EXEC_ENABLE
        uint8_t autocorrect_indicator_count = 255;

        #if defined(PLODAH_AUTOCORRECT_IND_MODE_DE)
            void plodah_autocorrect_indicator_on(void);
            void plodah_autocorrect_indicator_off(void);
            uint32_t plodah_autocorrect_indicator_on_DE(uint32_t trigger_time, void *cb_arg){
                plodah_autocorrect_indicator_on();
                return 0;
            }
            uint32_t plodah_autocorrect_indicator_off_DE(uint32_t trigger_time, void *cb_arg){
                plodah_autocorrect_indicator_off();
                return 0;
            }
        #endif

        void plodah_autocorrect_indicator_on(void){
            #if defined(RGB_MATRIX_ENABLE)
                HSV indhsv = plodah_rgblimit_ind(rgb_matrix_get_hsv(), PLODAH_AUTOCORRECT_INDICATOR_COLOUR, PLODAH_INDICATOR_MINVAL);
                rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
                rgb_matrix_sethsv_noeeprom(indhsv.h, indhsv.s, indhsv.v);
            #endif // RGB_MATRIX_ENABLE
            #if defined(RGBLIGHT_ENABLE)
                HSV indhsv = {rgblight_get_hue(), rgblight_get_sat(), rgblight_get_val()};
                indhsv = plodah_rgblimit_ind(indhsv, PLODAH_AUTOCORRECT_INDICATOR_COLOUR, PLODAH_INDICATOR_MINVAL);
                rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
                rgblight_sethsv_noeeprom(indhsv.h, indhsv.s, indhsv.v);
            #endif // RGBLIGHT_ENABLE

            #if defined(PLODAH_AUTOCORRECT_IND_MODE_DE)
                autoCorrectIndToken = defer_exec(PLODAH_AUTOCORRECT_INDICATOR_DURATION, plodah_autocorrect_indicator_off_DE, NULL);
            #else // PLODAH_AUTOCORRECT_IND_MODE_DE
                autocorrect_indicator_on = true;
                autocorrect_indicator_timer = timer_read();
            #endif // PLODAH_AUTOCORRECT_IND_MODE_DE
        }

        void plodah_autocorrect_indicator_off(void){
            #if defined(RGB_MATRIX_ENABLE)
                rgb_matrix_reload_from_eeprom();
            #endif // RGB_MATRIX_ENABLE
            #if defined(RGBLIGHT_ENABLE)
                rgblight_reload_from_eeprom();
            #endif // RGBLIGHT_ENABLE

            autocorrect_indicator_count ++;
            #if defined(PLODAH_AUTOCORRECT_IND_MODE_DE)
                if (autocorrect_indicator_count < PLODAH_AUTOCORRECT_INDICATOR_BLINKCOUNT){
                    autoCorrectIndToken = defer_exec(PLODAH_AUTOCORRECT_INDICATOR_DURATION, plodah_autocorrect_indicator_on_DE, NULL);
                }
                else{
                autoCorrectIndToken = INVALID_DEFERRED_TOKEN;
                }
            #else // PLODAH_AUTOCORRECT_IND_MODE_DE
                autocorrect_indicator_on = false;
                autocorrect_indicator_timer = timer_read();
            #endif // PLODAH_AUTOCORRECT_IND_MODE_DE
        }

        #if !defined(PLODAH_AUTOCORRECT_IND_MODE_DE)
            void housekeeping_task_autocorrect_indicator(void){
                if (autocorrect_indicator_count < PLODAH_AUTOCORRECT_INDICATOR_BLINKCOUNT){
                    if (timer_elapsed(autocorrect_indicator_timer) > PLODAH_AUTOCORRECT_INDICATOR_DURATION){
                        if (autocorrect_indicator_on){
                            plodah_autocorrect_indicator_off();
                        }
                        else{
                            plodah_autocorrect_indicator_on();
                        }
                    }
                }
            }
        #endif // ! PLODAH_AUTOCORRECT_IND_MODE_DE
    #endif // defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE)

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
        #if defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE)
            autocorrect_indicator_count = 0;
            #if defined(PLODAH_AUTOCORRECT_IND_MODE_DE)
                autoCorrectIndToken = defer_exec(PLODAH_AUTOCORRECT_INDICATOR_DURATION, plodah_autocorrect_indicator_on_DE, NULL);
            #endif // defined(PLODAH_AUTOCORRECT_IND_MODE_DE)
        #endif // defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE)
        #if defined(OLED_ENABLE)
            strcpy(recAcC, recAcB);
            strcpy(recAcB, recAcA);
            strcpy(recAcA, typo);
        #endif // OLED_ENABLE
        return true;
    }
#endif // AUTOCORRECT_ENABLE
