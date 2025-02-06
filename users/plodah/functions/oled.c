#ifdef OLED_ENABLE
  #if defined (AUTOCORRECT_ENABLE)
    char recAcA[15] = "_____";
    char recAcB[15] = "_____";
    char recAcC[15] = "_____";
  #endif // AUTOCORRECT_ENABLE

  #if defined(LAYER_NAMES)
    char *labels[DYNAMIC_KEYMAP_LAYER_COUNT] = LAYER_NAMES;
  #endif // defined(LAYER_NAMES)

  static void layer_display( layer_state_t state ) {
    oled_write_P(PSTR("L:"), false);
    oled_write_P(get_u8_str(get_highest_layer(state), ' '), false);
    #if defined(LAYER_NAMES)
      oled_write_P(labels[get_highest_layer(state)], false);
    #endif // defined(LAYER_NAMES)
  }

  static void locks_display ( led_t state ) {
    oled_write_P(PSTR("C"), state.caps_lock);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("N"), state.num_lock);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("S"), state.scroll_lock);
  }

  static void mods_display ( void ) {

    oled_write_P(PSTR("C"), (get_mods() & MOD_MASK_CTRL));
    oled_write_P(PSTR("A"), (get_mods() & MOD_MASK_ALT));
    oled_write_P(PSTR("G"), (get_mods() & MOD_MASK_GUI));
    oled_write_P(PSTR("S"), (get_mods() & MOD_MASK_SHIFT));
    oled_write_P(PSTR(" "), false);

  }

  const char *autocorrect_display( char* corrected ) {
    char * str;
    char * str2;
    str = malloc(sizeof(char)*10);
    str2 = malloc(sizeof(char)*10);
    strcpy(str, corrected);
    strcat(str, "          ");

    strncpy(str2, str + 0, 10);
    str2[10] = '\0';
    return str2;
    // oled_write_P(PSTR(autocorrect_display(recAcA)), false);
  }

  static void render_sma_logo( bool invert ) {
    static const char PROGMEM sma_logo[] = {
      0x80, 0x81, 0x82, 0x83, 0x84, // 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
      0xa0, 0xa1, 0xa2, 0xa3, 0xa4, // 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
      0xc0, 0xc1, 0xc2, 0xc3, 0xc4, // 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
      //0x00
    };
    oled_write_P(sma_logo, invert);
  }

  bool oled_task_user(void) {

    if ( is_keyboard_master() ){

      render_sma_logo(true);
      locks_display(host_keyboard_led_state());
      mods_display();
      layer_display(layer_state);

      #if defined (AUTOCORRECT_ENABLE)
        oled_write_P(PSTR("\n"), false);
        oled_write_P(PSTR(autocorrect_display(recAcA)), false);
        oled_write_P(PSTR(autocorrect_display(recAcB)), false);
        oled_write_P(PSTR(autocorrect_display(recAcC)), false);
      #endif // AUTOCORRECT_ENABLE
      return false;
    }
    else {
      return true;
    }


  }
#endif
