#if defined(OLED_ENABLE)
    #pragma once
    #include "oled.h"

    #if defined(LAYER_NAMES)
        char *labels[DYNAMIC_KEYMAP_LAYER_COUNT] = LAYER_NAMES;
    #endif // defined(LAYER_NAMES)

    void oled_layer_display ( uint8_t startrow ) {
        oled_set_cursor(0, startrow);
        oled_write_P(PSTR("L:"), false);
        oled_write_P(get_u8_str(get_highest_layer(layer_state|default_layer_state), ' '), false);
        #if defined(LAYER_NAMES)
            #if defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)
                oled_set_cursor(0, startrow+1);
            #endif // defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)
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
            //oled_write(PSTR(autocorrect_display_row(recAcA)), false);
            //oled_write(PSTR(autocorrect_display_row(recAcB)), false);
            //oled_write(PSTR(autocorrect_display_row(recAcC)), false);
            oled_set_cursor(0, startrow);
            oled_write("          ",false);
            oled_set_cursor(0, startrow);
            oled_write(PSTR(recAcA),false);
            oled_set_cursor(0, startrow + 1*rowsPerWord);
            oled_write("          ",false);
            oled_set_cursor(0, startrow + 1*rowsPerWord);
            oled_write(PSTR(recAcB),false);
            oled_set_cursor(0, startrow + 2*rowsPerWord);
            oled_write("          ",false);
            oled_set_cursor(0, startrow + 2*rowsPerWord);
            oled_write(PSTR(recAcC),false);
            // dprintf("a:%s b:%s c:%s \n", PSTR(autocorrect_display_row(recAcA)),
            //    PSTR(autocorrect_display_row(recAcB)), PSTR(autocorrect_display_row(recAcC)));
        }

        bool apply_autocorrect_oled(uint8_t backspaces, const char *str, char *typo, char *correct) {
            dprintf("corrected: %s \n", typo);
            char strtemp[AUTOCORRECT_OLED_DISPLAY_LENGTH];
            memcpy(strtemp, "              ", AUTOCORRECT_OLED_DISPLAY_LENGTH);

            memcpy(recAcC, recAcB, AUTOCORRECT_OLED_DISPLAY_LENGTH);
            //recAcC[AUTOCORRECT_OLED_DISPLAY_LENGTH] = '\0';
            memcpy(recAcB, recAcA, AUTOCORRECT_OLED_DISPLAY_LENGTH);
            //recAcB[AUTOCORRECT_OLED_DISPLAY_LENGTH] = '\0';
            memcpy(recAcA, strtemp, AUTOCORRECT_OLED_DISPLAY_LENGTH);
            memcpy(recAcA, typo,   AUTOCORRECT_OLED_DISPLAY_LENGTH);
            //recAcA[AUTOCORRECT_OLED_DISPLAY_LENGTH] = '\0';
            return true;
        }

        void keyboard_post_init_user_oled(void) {
            char strtemp[AUTOCORRECT_OLED_DISPLAY_LENGTH];
            memcpy(strtemp, "______________", AUTOCORRECT_OLED_DISPLAY_LENGTH);

            memcpy(recAcA, strtemp, AUTOCORRECT_OLED_DISPLAY_LENGTH);
            //recAcA[AUTOCORRECT_OLED_DISPLAY_LENGTH] = '\0';
            memcpy(recAcB, strtemp, AUTOCORRECT_OLED_DISPLAY_LENGTH);
            //recAcB[AUTOCORRECT_OLED_DISPLAY_LENGTH] = '\0';
            memcpy(recAcC, strtemp, AUTOCORRECT_OLED_DISPLAY_LENGTH);
            //recAcC[AUTOCORRECT_OLED_DISPLAY_LENGTH] = '\0';
        }
    #endif // defined(AUTOCORRECT_ENABLE)

    __attribute__((weak)) bool oled_task_user(void) {
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

            oled_layer_display(14);
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

                #if defined(OLED_DISPLAY_128X64) || defined(OLED_DISPLAY_64X128)
                    oled_set_cursor(0, 7);
                    oled_write_P(dual_logo_10x5, false);
                #else
                    oled_write_P(logo_5x5, true);
                #endif // OLED_DISPLAY_128X64 || OLED_DISPLAY_64X128

                #if defined(SPLIT_LAYER_STATE_ENABLE)
                    oled_layer_display(14);
                #endif // SPLIT_LAYER_STATE_ENABLE

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
