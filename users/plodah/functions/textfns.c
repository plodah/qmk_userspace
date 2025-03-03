#pragma once

#if defined(KC_PL_QFTR)
    char* featureQuery(void) {
        //may take 80 bytes more than sending string directly
        char * str;
        str = malloc(sizeof(char)*80);

        strcpy (str, "\\ FEATURES:");

        #ifdef AUTO_SHIFT_ENABLE
            strcat (str, " AUTO_SHIFT");
        #endif // AUTO_SHIFT_ENABLE

        #ifdef AUTOCORRECT_ENABLE
            strcat (str, " AUTOCORRECT");
        #endif // AUTOCORRECT_ENABLE

        #ifdef BACKLIGHT_ENABLE
            strcat (str, " BACKLIGHT");
        #endif // BACKLIGHT_ENABLE

        #ifdef BOOTMAGIC_ENABLE
            strcat (str, " BOOTMAGIC");
        #endif // BOOTMAGIC_ENABLE

        #ifdef CAPS_WORD_ENABLE
            strcat (str, " CAPS_WORD");
        #endif // CAPS_WORD_ENABLE

        #ifdef COMBO_ENABLE
            strcat (str, " COMBO");
        #endif // COMBO_ENABLE

        #ifdef CONSOLE_ENABLE
            strcat (str, " CONSOLE");
        #endif // CONSOLE_ENABLE

        #ifdef DEFERRED_EXEC_ENABLE
            strcat (str, " DEFERRED_EXEC");
        #endif // DEFERRED_EXEC_ENABLE

        #ifdef DYNAMIC_MACRO_ENABLE
            strcat (str, " DYNAMIC_MACRO");
        #endif // DYNAMIC_MACRO_ENABLE

        #ifdef DYNAMIC_TAPPING_TERM_ENABLE
            strcat (str, " DYNAMIC_TAPPING_TERM");
        #endif // DYNAMIC_TAPPING_TERM_ENABLE

        #ifdef ENCODER_MAP_ENABLE
            strcat (str, " ENCODER_MAP");
        #endif // ENCODER_MAP_ENABLE

        #ifdef EXTRAKEY_ENABLE
            strcat (str, " EXTRAKEY");
        #endif // EXTRAKEY_ENABLE

        #ifdef LEADER_ENABLE
            strcat (str, " LEADER");
        #endif // LEADER_ENABLE

        #ifdef MOUSEKEY_ENABLE
            strcat (str, " MOUSEKEY");
        #endif // MOUSEKEY_ENABLE

        #ifdef OLED_ENABLE
            strcat (str, " OLED");
        #endif // OLED_ENABLE

        #ifdef OS_DETECTION_ENABLE
            strcat (str, " OS_DETECTION");
        #endif // OS_DETECTION_ENABLE

        #ifdef RGBLIGHT_ENABLE
            strcat (str, " RGBLIGHT");
        #endif // RGBLIGHT_ENABLE

        #ifdef RGB_MATRIX_ENABLE
            strcat (str, " RGB_MATRIX");
        #endif // RGB_MATRIX_ENABLE

        #ifdef SPACE_CADET_ENABLE
            strcat (str, " SPACE_CADET");
        #endif // SPACE_CADET_ENABLE

        #ifdef TAP_DANCE_ENABLE
            strcat (str, " TAP_DANCE");
        #endif // TAP_DANCE_ENABLE

        #ifdef TRI_LAYER_ENABLE
            strcat (str, " TRI_LAYER");
        #endif // TRI_LAYER_ENABLE

        #ifdef VIA_ENABLE
            strcat (str, " VIA");
        #endif // VIA_ENABLE

        strcat (str, " \n");
        return str;
    }

    void featureQuerySs(void) {
        send_string_with_delay ( "\\ FEATURES:", TAP_CODE_DELAY );
        #ifdef AUTO_SHIFT_ENABLE
            send_string_with_delay (" AUTO_SHIFT", TAP_CODE_DELAY );
        #endif // AUTO_SHIFT_ENABLE

        #ifdef AUTOCORRECT_ENABLE
            send_string_with_delay (" AUTOCORRECT", TAP_CODE_DELAY );
        #endif // AUTOCORRECT_ENABLE

        #ifdef BACKLIGHT_ENABLE
            send_string_with_delay (" BACKLIGHT", TAP_CODE_DELAY );
        #endif // BACKLIGHT_ENABLE

        #ifdef BOOTMAGIC_ENABLE
            send_string_with_delay (" BOOTMAGIC", TAP_CODE_DELAY );
        #endif // BOOTMAGIC_ENABLE

        #ifdef CAPS_WORD_ENABLE
            send_string_with_delay (" CAPS_WORD", TAP_CODE_DELAY );
        #endif // CAPS_WORD_ENABLE

        #ifdef COMBO_ENABLE
            send_string_with_delay (" COMBO", TAP_CODE_DELAY );
        #endif // COMBO_ENABLE

        #ifdef CONSOLE_ENABLE
            send_string_with_delay (" CONSOLE", TAP_CODE_DELAY );
        #endif // CONSOLE_ENABLE

        #ifdef DEFERRED_EXEC_ENABLE
            send_string_with_delay (" DEFERRED_EXEC", TAP_CODE_DELAY );
        #endif // DEFERRED_EXEC_ENABLE

        #ifdef DYNAMIC_MACRO_ENABLE
            send_string_with_delay (" DYNAMIC_MACRO", TAP_CODE_DELAY );
        #endif // DYNAMIC_MACRO_ENABLE

        #ifdef DYNAMIC_TAPPING_TERM_ENABLE
            send_string_with_delay (" DYNAMIC_TAPPING_TERM", TAP_CODE_DELAY );
        #endif // DYNAMIC_TAPPING_TERM_ENABLE

        #ifdef ENCODER_MAP_ENABLE
            send_string_with_delay (" ENCODER_MAP", TAP_CODE_DELAY );
        #endif // ENCODER_MAP_ENABLE

        #ifdef EXTRAKEY_ENABLE
            send_string_with_delay (" EXTRAKEY", TAP_CODE_DELAY );
        #endif // EXTRAKEY_ENABLE

        #ifdef LEADER_ENABLE
            send_string_with_delay (" LEADER", TAP_CODE_DELAY );
        #endif // LEADER_ENABLE

        #ifdef MOUSEKEY_ENABLE
            send_string_with_delay (" MOUSEKEY", TAP_CODE_DELAY );
        #endif // MOUSEKEY_ENABLE

        #ifdef OLED_ENABLE
            send_string_with_delay (" OLED", TAP_CODE_DELAY );
        #endif // OLED_ENABLE

        #ifdef OS_DETECTION_ENABLE
            send_string_with_delay (" OS_DETECTION", TAP_CODE_DELAY );
        #endif // OS_DETECTION_ENABLE

        #ifdef RGBLIGHT_ENABLE
            send_string_with_delay (" RGBLIGHT", TAP_CODE_DELAY );
        #endif // RGBLIGHT_ENABLE

        #ifdef RGB_MATRIX_ENABLE
            send_string_with_delay (" RGB_MATRIX", TAP_CODE_DELAY );
        #endif // RGB_MATRIX_ENABLE

        #ifdef SPACE_CADET_ENABLE
            send_string_with_delay (" SPACE_CADET", TAP_CODE_DELAY );
        #endif // SPACE_CADET_ENABLE

        #ifdef TAP_DANCE_ENABLE
            send_string_with_delay (" TAP_DANCE", TAP_CODE_DELAY );
        #endif // TAP_DANCE_ENABLE

        #ifdef TRI_LAYER_ENABLE
            send_string_with_delay (" TRI_LAYER", TAP_CODE_DELAY );
        #endif // TRI_LAYER_ENABLE

        #ifdef VIA_ENABLE
            send_string_with_delay (" VIA", TAP_CODE_DELAY );
        #endif // VIA_ENABLE
        send_string_with_delay (" \n", TAP_CODE_DELAY );
    }
#endif // KC_PL_QFTR

#if defined(KC_PL_QLYR)
    char* layerQuery(void) {
        char * str;
        str = malloc(sizeof(char)*20);
        strcpy (str, "\\ LYR:");
        strcat (str, get_u8_str(get_highest_layer(layer_state), '0'));
        strcat (str, " DEF");
        strcat (str, get_u8_str(get_highest_layer(default_layer_state), '0'));
        strcat (str, " L|D");
        strcat (str, get_u8_str(get_highest_layer(layer_state | default_layer_state), '0'));
        strcat (str, " \n");
        return str;
    }

    void layerQuerySs(void) {
        send_string_with_delay ( "\\ LYR:", TAP_CODE_DELAY );
        send_string_with_delay ( get_u8_str(get_highest_layer(layer_state), '0'), TAP_CODE_DELAY );
        send_string_with_delay ( " DEF:", TAP_CODE_DELAY );
        send_string_with_delay ( get_u8_str(get_highest_layer(default_layer_state), '0'), TAP_CODE_DELAY );
        send_string_with_delay ( " L|D:", TAP_CODE_DELAY );
        send_string_with_delay ( get_u8_str(get_highest_layer(layer_state | default_layer_state), '0'), TAP_CODE_DELAY );
        send_string_with_delay ( "\n", TAP_CODE_DELAY );
    }
#endif // defined(KC_PL_QLYR)

#if defined(KC_PL_QTAP)
    void tapQuerySs(void) {
        #ifdef TAPPING_TERM
            send_string_with_delay ("TAPPING_TERM:", TAP_CODE_DELAY );
        send_string_with_delay ( get_u16_str(TAPPING_TERM, '0'), TAP_CODE_DELAY );
        #endif // AUTO_SHIFT_ENABLE

        #ifdef QUICK_TAP_TERM
            send_string_with_delay (" QUICK_TAP_TERM:", TAP_CODE_DELAY );
        send_string_with_delay ( get_u16_str(QUICK_TAP_TERM, '0'), TAP_CODE_DELAY );
        #endif // QUICK_TAP_TERM

        #ifdef PERMISSIVE_HOLD
            send_string_with_delay (" PERMISSIVE_HOLD:", TAP_CODE_DELAY );
        #endif // PERMISSIVE_HOLD

        #ifdef HOLD_ON_OTHER_KEY_PRESS
            send_string_with_delay (" HOLD_ON_OTHER_KEY_PRESS", TAP_CODE_DELAY );
        #endif // HOLD_ON_OTHER_KEY_PRESS

        #ifdef RETRO_TAPPING
            send_string_with_delay (" RETRO_TAPPING", TAP_CODE_DELAY );
        #endif // RETRO_TAPPING
        send_string_with_delay ( "\n", TAP_CODE_DELAY );
    }
#endif // defined(KC_PL_QTAP)

#if defined(KC_PL_QVER)
  void verQuerySs(void) {
    send_string_with_delay ( "\\ " QMK_KEYBOARD "/" QMK_KEYMAP " \" " QMK_VERSION ", Built on: " QMK_BUILDDATE "\n", TAP_CODE_DELAY);
  }
#endif // defined(KC_PL_QVER)
