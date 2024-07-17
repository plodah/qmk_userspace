bool apply_autocorrect(uint8_t backspaces, const char *str, char *typo, char *correct) {

#   ifdef CONSOLE_ENABLE
        printf("'%s' was corrected to '%s'\n", typo, correct);
#   endif

#   ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
        rgb_matrix_reload_from_eeprom()

#   endif // RGB_MATRIX_ENABLE
    return true;
}
//deferred exec
//also, look up my diablo macro
