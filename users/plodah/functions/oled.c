#include QMK_KEYBOARD_H
#if defined(OLED_ENABLE)
    #include "oled.h"
    #include "oled_imgs.h"

    void housekeeping_task_oled ( void ) {
        if (last_input_activity_elapsed() < OLED_TIMEOUT) {
            is_oled_enabled = true;
        }
        else {
            is_oled_enabled = false;
        }
    }
    
    void oled_layer_display ( uint8_t startrow ) {
        oled_set_cursor(0, startrow);
        oled_write_P(PSTR("L:"), false);
        oled_write_P(get_u8_str(get_highest_layer(layer_state|default_layer_state), ' '), false);
        #if defined(LAYER_NAMES)
            char *labels[DYNAMIC_KEYMAP_LAYER_COUNT] = LAYER_NAMES;
            oled_set_cursor(0, startrow+1);
            #if defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)
                oled_write_P(PSTR("          "), false);
            #else
                oled_write_P(PSTR("     "), false );
            #endif // defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)
            oled_set_cursor(0, startrow+1);
            oled_write_P(labels[get_highest_layer(layer_state|default_layer_state)], false);
        #endif // defined(LAYER_NAMES)
    }

    void oled_locks_display ( uint8_t startrow ) {
        oled_set_cursor(0, startrow);
        #if defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)
            oled_write_P(PSTR(" C "), host_keyboard_led_state().caps_lock);
        #else
            oled_write_P(PSTR("C"), host_keyboard_led_state().caps_lock);
            oled_write_P(PSTR(" "), false);
        #endif // defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)

        #if defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)
            oled_write_P(PSTR(" N "), host_keyboard_led_state().num_lock);
        #else
            oled_write_P(PSTR("N"), host_keyboard_led_state().num_lock);
            oled_write_P(PSTR(" "), false);
        #endif // defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)
        #if defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)
            oled_write_P(PSTR(" S "), host_keyboard_led_state().scroll_lock);
        #else
            oled_write_P(PSTR("S"), host_keyboard_led_state().scroll_lock);
        #endif // defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)
    }

    void oled_mods_display ( uint8_t startrow ) {
        oled_set_cursor(0, startrow);
        #if defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)
            oled_write_P(PSTR(" "), false);
        #endif // defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)
        oled_write_P(PSTR("C"), (get_mods() & MOD_MASK_CTRL));
        #if defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)
            oled_write_P(PSTR(" "), false);
        #endif // defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)
        oled_write_P(PSTR("S"), (get_mods() & MOD_MASK_SHIFT));
        #if defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)
            oled_write_P(PSTR(" "), false);
        #endif // defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)
        oled_write_P(PSTR("A"), (get_mods() & MOD_MASK_ALT));
        #if defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)
            oled_write_P(PSTR(" "), false);
        #endif // defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)
        oled_write_P(PSTR("G"), (get_mods() & MOD_MASK_GUI));
    }

    void oled_hand_display (uint8_t startrow, uint8_t startcol ) {
        oled_set_cursor(startcol, startrow);
        bool isSwapped = false;
        #ifdef SWAP_HANDS_ENABLE
            isSwapped = is_swap_hands_on();
        #endif // SWAP_HANDS_ENABLE

        #if defined( SPLIT_KEYBOARD)
            bool isLeft;
            isLeft = is_keyboard_master() ^ isSwapped;
            #if defined(MASTER_RIGHT)
                isLeft = !isLeft;
            #endif //MASTER_RIGHT
            if(isLeft) {
                oled_write_P(PSTR("L"), isSwapped);
            } else {
                oled_write_P(PSTR("R"), isSwapped);
            }
        #else
            oled_write_P(PSTR("-"), isSwapped);
        #endif
    }

    #if defined( COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE )
        #include "mouse_jiggler.h"
        void oled_jiggler_display (uint8_t startrow, uint8_t startcol ) {
            oled_set_cursor (startcol, startrow);
            if(jiggler_get_state()){
                oled_write("J", true);
            } else {
                oled_write("-", false);
            }
        }
    #endif // defined( COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE )

    char     oled_keylog_key_name = ' ';
    uint16_t oled_keylog_last_keycode;
    uint8_t  oled_keylog_last_row;
    uint8_t  oled_keylog_last_col;

    static const char PROGMEM code_to_name[60] = {' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\', '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

    void set_keylog(uint16_t keycode, keyrecord_t *record) {
        // save the row and column (useful even if we can't find a keycode to show)
        oled_keylog_last_row = record->event.key.row;
        oled_keylog_last_col = record->event.key.col;

        oled_keylog_key_name     = ' ';
        oled_keylog_last_keycode = keycode;
        if (IS_QK_MOD_TAP(keycode)) {
            if (record->tap.count) {
                keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
            } else {
                keycode = 0xE0 + biton(QK_MOD_TAP_GET_MODS(keycode) & 0xF) + biton(QK_MOD_TAP_GET_MODS(keycode) & 0x10);
            }
        } else if (IS_QK_LAYER_TAP(keycode) && record->tap.count) {
            keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
        } else if (IS_QK_MODS(keycode)) {
            keycode = QK_MODS_GET_BASIC_KEYCODE(keycode);
        } else if (IS_QK_ONE_SHOT_MOD(keycode)) {
            keycode = 0xE0 + biton(QK_ONE_SHOT_MOD_GET_MODS(keycode) & 0xF) + biton(QK_ONE_SHOT_MOD_GET_MODS(keycode) & 0x10);
        }
        if (keycode > ARRAY_SIZE(code_to_name)) {
            return;
        }

        // update keylog
        oled_keylog_key_name = pgm_read_byte(&code_to_name[keycode]);
    }

    const char *depad_str(const char *depad_str, char depad_char) {
        while (*depad_str == depad_char)
            ++depad_str;
        return depad_str;
    }

    void oled_render_keylog(void) {
        oled_write_char('0' + oled_keylog_last_row, false);
        oled_write_P(PSTR("x"), false);
        oled_write_char('0' + oled_keylog_last_col, false);
        oled_write_P(PSTR(", k"), false);
        const char *last_keycode_str = get_u16_str(oled_keylog_last_keycode, ' ');
        oled_write(depad_str(last_keycode_str, ' '), false);
        oled_write_P(PSTR(":"), false);
        oled_write_char(oled_keylog_key_name, false);
        oled_advance_page(true);
    }

    #if defined(AUTOCORRECT_ENABLE)
        void oled_autocorrect_display(uint8_t startrow) {
            #if defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)
                uint8_t rowsPerWord = 1;
            #else
                uint8_t rowsPerWord = 2;
            #endif // defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)

            // I should make this a loop later.

            for(int8_t i = 0; i < AUTOCORRECT_OLED_DISPLAY_COUNT; i++){
                oled_set_cursor(0, startrow + i*rowsPerWord);
                oled_write("          ",false);
                oled_set_cursor(0, startrow + i*rowsPerWord);
                oled_write(recAc[i], false);
            }
        }

        bool apply_autocorrect_oled(uint8_t backspaces, const char *str, char *typo, char *correct) {
            dprintf("corrected: %s \n", typo);
            char strtemp[AUTOCORRECT_OLED_DISPLAY_LENGTH];
            memcpy(strtemp, "              ", AUTOCORRECT_OLED_DISPLAY_LENGTH);
            int8_t j;
            for(int8_t i = 0; i < AUTOCORRECT_OLED_DISPLAY_COUNT; i++){
                j = AUTOCORRECT_OLED_DISPLAY_COUNT - 1 - i;
                if(j==0){
                    memcpy(recAc[j], strtemp, AUTOCORRECT_OLED_DISPLAY_LENGTH);
                    memcpy(recAc[j], typo, AUTOCORRECT_OLED_DISPLAY_LENGTH);
                }
                else{
                    memcpy(recAc[j], recAc[j-1], AUTOCORRECT_OLED_DISPLAY_LENGTH);
                }
            }
            return true;
        }

        void keyboard_post_init_user_oled(void) {
            char strtemp[AUTOCORRECT_OLED_DISPLAY_LENGTH];
            memcpy(strtemp, "______________", AUTOCORRECT_OLED_DISPLAY_LENGTH);
            for(int8_t i = 0; i < AUTOCORRECT_OLED_DISPLAY_COUNT; i++){
                memcpy(recAc[i], strtemp, AUTOCORRECT_OLED_DISPLAY_LENGTH);
            }
        }
    #endif // defined(AUTOCORRECT_ENABLE)

    #if defined(OS_DETECTION_ENABLE)
        #if defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)
            static char *os_names[] = {
                [OS_UNSURE]  = "Unknown",
                [OS_LINUX]   = "Linux",
                [OS_WINDOWS] = "Windows",
                [OS_MACOS]   = "MacOS",
                [OS_IOS]     = "iOS",
            };
        #else
            static char *os_names[] = {
                [OS_UNSURE]  = "dk",
                [OS_LINUX]   = "LX",
                [OS_WINDOWS] = "WN",
                [OS_MACOS]   = "MC",
                [OS_IOS]     = "IO",
            };
        #endif // OLED_DISPLAY_128x64

        void oled_os_display ( uint8_t startrow ) {
            oled_set_cursor(0, startrow);
            if( is_keyboard_master() ){
                oled_write_P(PSTR("OS:"), false);
                oled_write_P(os_names[detected_host_os()], true);
            }
            else{
                #if defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)
                    oled_write_P("OS: n/a", false);
                #else
                    oled_write_P("OS:xx", false);
                #endif // #if defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)
            }
        }

    #endif // OS_DETECTION_ENABLE

    #if defined(WPM_ENABLE)
        void oled_wpm_display ( uint8_t startrow ) {
            oled_set_cursor(0, startrow);
            #if defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)
                oled_write_P(PSTR("WPM: "), false);
            #else
                oled_write_P(PSTR("W:"), false);
            #endif // OLED_DISPLAY_128X64
            oled_write_P(get_u8_str(get_current_wpm(), ' '), false);

        }
    #endif // WPM_ENABLE

    #if defined(DEBUG_MATRIX_SCAN_RATE)
        void oled_matrix_scan_rate_display ( uint8_t startrow ) {
            oled_set_cursor(0, startrow);
            #if defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)
                oled_write_P(PSTR("Scan:"), false);
            //#else
            //    oled_write_P(PSTR(""), false);
            #endif // OLED_DISPLAY_128X64
            oled_write_P(get_u16_str(get_matrix_scan_rate(), ' '), false);

        }
    #endif // DEBUG_MATRIX_SCAN_RATE

    __attribute__((weak)) bool oled_task_user(void) {
        
        // Other stuff in oled_task_user() prevents OLED idle timer from working.
        // So it is re-implemented here.
        #ifndef OLED_DISABLE_TIMEOUT
            if ( !is_oled_enabled ) {
                oled_off();
                return false;
            }
        #endif
        oled_on();

        if ( is_keyboard_master() ){
            #if defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)
                oled_write_P(logo_10x5, false);
            #else
                oled_write_P(logo_5x5, false);
            #endif // OLED_DISPLAY_128X64 || OLED_DISPLAY_64X128

            oled_locks_display(4);

            oled_mods_display(5);
            #if defined(AUTOCORRECT_ENABLE)
                oled_autocorrect_display(7);
            #endif // AUTOCORRECT_ENABLE

            #if defined(DEBUG_MATRIX_SCAN_RATE)
                oled_matrix_scan_rate_display(11);
            #endif // DEBUG_MATRIX_SCAN_RATE

            #if defined (COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE)
                #if defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)
                    oled_jiggler_display(4, 9);
                #else // if defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)
                    oled_jiggler_display(11,0);
                #endif // OLED_DISPLAY_128X64
            #endif // COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE

            #if defined(WPM_ENABLE)
                oled_wpm_display(12);
            #endif // WPM_ENABLE

            oled_layer_display(13);
            #if defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)
                oled_hand_display(13, 9);
            #else
                oled_hand_display(5, 4);
            #endif

            #if defined(OS_DETECTION_ENABLE)
                oled_os_display(15);
            #endif // OS_DETECTION_ENABLE

            return false;
        }
        else {
            #if defined(SPLIT_LED_STATE_ENABLE) || defined(SPLIT_MODS_ENABLE) || defined(SPLIT_LAYER_STATE_ENABLE)
                #if defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)
                    oled_write_P(logo_10x5, true);
                #else
                    oled_write_P(logo_5x5, true);
                #endif // OLED_DISPLAY_128X64 || OLED_DISPLAY_64X128

                #if defined(SPLIT_LED_STATE_ENABLE)
                    oled_locks_display(4);
                #endif // SPLIT_LED_STATE_ENABLE

                #if defined(SPLIT_MODS_ENABLE)
                    oled_mods_display(5);
                #endif // SPLIT_MODS_ENABLE

                oled_set_cursor(0, 7);
                #if defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)
                    oled_write_P(dual_logo_10x5, false);
                #else
                    oled_write_P(logo_5x5, true);
                #endif // OLED_DISPLAY_128X64 || OLED_DISPLAY_64X128

                #if defined(DEBUG_MATRIX_SCAN_RATE)
                    oled_matrix_scan_rate_display(11);
                #endif // DEBUG_MATRIX_SCAN_RATE

                #if defined(WPM_ENABLE)
                    oled_wpm_display(12);
                #endif // WPM_ENABLE

                #if defined(SPLIT_LAYER_STATE_ENABLE)
                    oled_layer_display(13);
                #endif // SPLIT_LAYER_STATE_ENABLE

                #if defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)
                    oled_hand_display(13, 9);
                #else
                    oled_hand_display(5, 4);
                #endif

                #if defined(OS_DETECTION_ENABLE)
                    oled_os_display(15);
                #endif // OS_DETECTION_ENABLE

                return false;
            #else
                return true;
            #endif // SPLIT_LED_STATE_ENABLE || SPLIT_MODS_ENABLE || SPLIT_LAYER_STATE_ENABLE
        }
    }

    bool process_record_oled(uint16_t keycode, keyrecord_t *record) {
        if (record->event.pressed) {
            set_keylog(keycode, record);
        }
        return true;
    }

    void oled_render_boot(bool bootloader) {
        oled_clear();
        for (int i = 0; i < 16; i++) {
            oled_set_cursor(0, i);
            if (bootloader) {
                oled_write_P(PSTR("Awaiting New Firmware "), false);
            } else {
                oled_write_P(PSTR("Rebooting "), false);
            }
        }
        oled_render_dirty(true);
    }

    bool shutdown_oled(bool jump_to_bootloader) {
        oled_render_boot(jump_to_bootloader);
        return true;
    }
#endif // defined(OLED_ENABLE)
