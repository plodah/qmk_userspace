#ifdef OLED_ENABLE
  #if defined (AUTOCORRECT_ENABLE)
    char recAcA[14] = "_____";
    char recAcB[14] = "_____";
    char recAcC[14] = "_____";
  #endif // AUTOCORRECT_ENABLE

bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("L:"), false);

    switch (get_highest_layer(layer_state)) {
          case _QWERTY:
            oled_write_P(PSTR("QWE"), false);
            break;
          case _COLEMAK:
            oled_write_P(PSTR("COL"), false);
            break;
          case _FN_A:
            oled_write_P(PSTR("FnA"), false);
            break;
          case _FN_B:
            oled_write_P(PSTR("FnB"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("??? "), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUMLK") : PSTR("N    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAPLK") : PSTR("C    "), false);
    #if defined (AUTOCORRECT_ENABLE)
      oled_write_P(PSTR("\n"), false);
      oled_write_P(PSTR(recAcA), false);
      oled_write_P(PSTR("\n"), false);
      oled_write_P(PSTR(recAcB), false);
      oled_write_P(PSTR("\n"), false);
      oled_write_P(PSTR(recAcC), false);
    #endif // AUTOCORRECT_ENABLE

    return false;
}
#endif
