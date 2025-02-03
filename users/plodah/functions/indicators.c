#if defined(RGB_MATRIX_ENABLE)
  #pragma once
  #if ( defined(PLODAH_MODS_INDIC_LCTL_INDEX) || defined(PLODAH_MODS_INDIC_RCTL_INDEX) || defined(PLODAH_MODS_INDIC_LGUI_INDEX) || defined(PLODAH_MODS_INDIC_RGUI_INDEX) || defined(PLODAH_MODS_INDIC_LALT_INDEX) || defined(PLODAH_MODS_INDIC_RALT_INDEX) || defined(PLODAH_MODS_INDIC_LSHIFT_INDEX) || defined(PLODAH_MODS_INDIC_RSHIFT_INDEX) ) && (!defined(PLODAH_MODS_INDIC_HSV))
    #define PLODAH_MODS_INDIC_HSV HSV_WHITE
  #endif // PLODAH_MODS_INDIC_HSV

  #if ( (defined(PLODAH_MODS_INDIC_LGUI_INDEX) || defined(PLODAH_MODS_INDIC_RGUI_INDEX)) && defined(PLODAH_GULOCK_INDIC_ENABLE) && (!defined(PLODAH_GULOCK_INDIC_HSV)) )
    #define PLODAH_GULOCK_INDIC_HSV HSV_RED
  #endif // PLODAH_GULOCK_INDIC_HSV

  #if (defined(PLODAH_DMAC_INDIC_INDEX)) && (!defined(PLODAH_DMAC_INDIC_HSV))
    #define PLODAH_DMAC_INDIC_HSV HSV_RED
  #endif // PLODAH_DMAC_INDIC_HSV

  #if (defined(CAPS_LOCK_LED_INDEX)) && (! defined(PLODAH_CAPS_INDIC_HSV))
    #define PLODAH_CAPS_INDIC_HSV HSV_RED
  #endif // PLODAH_CAPS_INDIC_HSV

  #if (defined(PLODAH_LAYER_INDIC_INDEX1)) && (!defined(PLODAH_LAYER_INDIC_HSV))
    #define PLODAH_LAYER_INDIC_HSV HSV_YELLOW
  #endif // PLODAH_LAYER_INDIC_HSV

  #ifndef PLODAH_INDICATOR_MINVAL
    #define PLODAH_INDICATOR_MINVAL 85
  #endif // PLODAH_INDICATOR_MINVAL

  bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_user()) {
      return false;
    }
    return true;
  }
  //  declare a bunch of variables once rather than every time their function is called
  #if defined(CAPS_LOCK_LED_INDEX)
    RGB capsrgb;
  #endif // CAPS_LOCK_LED_INDEX

  #if defined(PLODAH_LAYER_INDIC_INDEX1) || defined(PLODAH_LAYER_INDIC_INDEXES)
    RGB layrrgb;
    #if defined(PLODAH_LAYER_INDIC_BG_HSV)
      RGB laybrgb;
    #endif //  PLODAH_LAYER_INDIC_BG_HSV
  #endif // defined(PLODAH_LAYER_INDIC_INDEX1) || defined(PLODAH_LAYER_INDIC_INDEXES)

  #if defined(DYNAMIC_MACRO_ENABLE) && defined(PLODAH_DMAC_INDIC_INDEX)
    RGB dmacrgb;
  #endif // defined(DYNAMIC_MACRO_ENABLE) && defined(PLODAH_DMAC_INDIC_INDEX)

  #if defined(PLODAH_TYPINGINDICATOR_RGBINDEX)
    RGB typnrgb;
  #endif // defined(PLODAH_TYPINGINDICATOR_RGBINDEX)

  #if defined(PLODAH_MSJIGGLER_ENABLED) && defined(DEFERRED_EXEC_ENABLE) && defined(PLODAH_MSJIGGLER_INDICATOR_RGBINDEX)
    RGB msjigrgb;
  #endif // defined(PLODAH_MSJIGGLER_ENABLED) && defined(DEFERRED_EXEC_ENABLE) && defined(PLODAH_MSJIGGLER_INDICATOR_RGBINDEX)

  #if ( defined(PLODAH_MODS_INDIC_LALT_INDEX) || defined(PLODAH_MODS_INDIC_RALT_INDEX) || defined(PLODAH_MODS_INDIC_LCTL_INDEX) || defined(PLODAH_MODS_INDIC_RCTL_INDEX) || defined(PLODAH_MODS_INDIC_LSHIFT_INDEX) || defined(PLODAH_MODS_INDIC_RSHIFT_INDEX) )
    RGB modsrgb;
  #endif // ( defined(PLODAH_MODS_INDIC_LALT_INDEX) || defined(PLODAH_MODS_INDIC_RALT_INDEX) || defined(PLODAH_MODS_INDIC_LCTL_INDEX) || defined(PLODAH_MODS_INDIC_RCTL_INDEX) || defined(PLODAH_MODS_INDIC_LSHIFT_INDEX) || defined(PLODAH_MODS_INDIC_RSHIFT_INDEX) )

  #if (defined(PLODAH_MODS_INDIC_LGUI_INDEX) || defined(PLODAH_MODS_INDIC_RGUI_INDEX)) && defined(PLODAH_GULOCK_INDIC_ENABLE)
    RGB guilockrgb;
  #endif // defined(PLODAH_GULOCK_INDIC_ENABLE)


  bool rgb_matrix_indicators_user(void) {
    #if defined(CAPS_LOCK_LED_INDEX)
      if (host_keyboard_led_state().caps_lock){
        capsrgb = hsv_to_rgb( plodah_rgblimit_ind( rgb_matrix_get_hsv(), PLODAH_CAPS_INDIC_HSV, PLODAH_INDICATOR_MINVAL ) );
        rgb_matrix_set_color(CAPS_LOCK_LED_INDEX, capsrgb.r, capsrgb.g, capsrgb.b);
      }
      else {
        if (!rgb_matrix_get_flags()) {
          rgb_matrix_set_color(CAPS_LOCK_LED_INDEX, RGB_OFF);
        }
      }
    #endif // CAPS_LOCK_LED_INDEX

    #if defined(PLODAH_LAYER_INDIC_INDEX1) || defined(PLODAH_LAYER_INDIC_INDEXES)

      #if defined(PLODAH_LAYER_INDIC_INDEXES)
        uint8_t layer_ind[] = PLODAH_LAYER_INDIC_INDEXES;
      #endif // PLODAH_LAYER_INDIC_INDEXES

      layrrgb = hsv_to_rgb( plodah_rgblimit_ind( rgb_matrix_get_hsv(), PLODAH_LAYER_INDIC_HSV, PLODAH_INDICATOR_MINVAL ) );
      #if defined(PLODAH_LAYER_INDIC_BG_HSV)
        laybrgb = hsv_to_rgb( plodah_rgblimit_ind( rgb_matrix_get_hsv(), PLODAH_LAYER_INDIC_BG_HSV, PLODAH_INDICATOR_MINVAL ) );
      #endif // PLODAH_LAYER_INDIC_BG_HSV

      int highlayer = get_highest_layer(layer_state | default_layer_state);
      for (int lindex = 0; lindex < DYNAMIC_KEYMAP_LAYER_COUNT; lindex++) {
        #if defined(PLODAH_LAYER_INDIC_INDEXES)
          int thisindex = layer_ind[lindex];
        #else
          int thisindex = (lindex + PLODAH_LAYER_INDIC_INDEX1);
        #endif // PLODAH_LAYER_INDIC_INDEXES
        if (!rgb_matrix_get_flags()) {
          rgb_matrix_set_color(thisindex, RGB_OFF);
        }
        #if defined(PLODAH_LAYER_INDIC_ONZERO)
          if (highlayer == lindex) {
            rgb_matrix_set_color(thisindex, layrrgb.r, layrrgb.g, layrrgb.b);
          }
          else {
          #if defined(PLODAH_LAYER_INDIC_BG_HSV)
              if (highlayer != lindex) {
                rgb_matrix_set_color(thisindex, laybrgb.r, laybrgb.g, laybrgb.b);
              }
          #endif // PLODAH_LAYER_INDIC_BG_HSV
          }
        #else // PLODAH_LAYER_INDIC_ONZERO
          if (highlayer == lindex && lindex != 0) {
            rgb_matrix_set_color(thisindex, layrrgb.r, layrrgb.g, layrrgb.b);
          }
          else {
          #if defined(PLODAH_LAYER_INDIC_BG_HSV)
            if (highlayer != lindex && lindex != 0) {
              rgb_matrix_set_color(thisindex, laybrgb.r, laybrgb.g, laybrgb.b);
            }
          #endif // PLODAH_LAYER_INDIC_BG_HSV
          }
        #endif // PLODAH_LAYER_INDIC_ONZERO
      }
    #endif // PLODAH_LAYER_INDIC_INDEX1

    #if defined(DYNAMIC_MACRO_ENABLE) && defined(PLODAH_DMAC_INDIC_INDEX)
      dmacrgb = hsv_to_rgb( plodah_rgblimit_ind( rgb_matrix_get_hsv(), PLODAH_DMAC_INDIC_HSV, PLODAH_INDICATOR_MINVAL ) );
      if (!rgb_matrix_get_flags()) {
        rgb_matrix_set_color(PLODAH_DMAC_INDIC_INDEX, RGB_OFF);
      }
      if (is_dynamic_macro_recording) {
        rgb_matrix_set_color(PLODAH_DMAC_INDIC_INDEX, dmacrgb.r, dmacrgb.g, dmacrgb.b);
      }
    #endif // DYNAMIC_MACRO_ENABLE && PLODAH_DMAC_INDIC_INDEX

    #if defined(PLODAH_TYPINGINDICATOR_RGBINDEX)
      typnrgb = hsv_to_rgb( plodah_rgblimit_ind( rgb_matrix_get_hsv(), PLODAH_TYPINGINDICATOR_HSV, PLODAH_INDICATOR_MINVAL ) );
      if(!rgb_matrix_get_flags()){
        rgb_matrix_set_color(PLODAH_TYPINGINDICATOR_RGBINDEX, RGB_OFF);
      }
      if(plodah_typingindicator_active){
        rgb_matrix_set_color(PLODAH_TYPINGINDICATOR_RGBINDEX, typnrgb.r, typnrgb.g, typnrgb.b);
      }
    #endif // PLODAH_TYPINGINDICATOR_RGBINDEX
    #if defined(PLODAH_MSJIGGLER_ENABLED) && defined(DEFERRED_EXEC_ENABLE) && defined(PLODAH_MSJIGGLER_INDICATOR_RGBINDEX)
      msjigrgb = hsv_to_rgb( plodah_rgblimit_ind( rgb_matrix_get_hsv(), PLODAH_MSJIGGLER_INDICATOR_HSV, PLODAH_INDICATOR_MINVAL ) );
      if(!rgb_matrix_get_flags()){
        rgb_matrix_set_color(PLODAH_MSJIGGLER_INDICATOR_RGBINDEX, RGB_OFF);
      }
      #if defined(PLODAH_MSJIGGLER_INTRO)
      if(msJigIntroToken != INVALID_DEFERRED_TOKEN){
        rgb_matrix_set_color(PLODAH_MSJIGGLER_INDICATOR_RGBINDEX, RGB_RED);
      }
      else
      #endif //PLODAH_MSJIGGLER_INTRO
      if(msJigMainToken != INVALID_DEFERRED_TOKEN){
        rgb_matrix_set_color(PLODAH_MSJIGGLER_INDICATOR_RGBINDEX, msjigrgb.r, msjigrgb.g, msjigrgb.b);
      }
    #endif // defined(PLODAH_MSJIGGLER_ENABLED) && defined(DEFERRED_EXEC_ENABLE) && PLODAH_MSJIGGLER_INDICATOR_RGBINDEX
    #if ( defined(PLODAH_MODS_INDIC_LALT_INDEX) || defined(PLODAH_MODS_INDIC_RALT_INDEX) || defined(PLODAH_MODS_INDIC_LCTL_INDEX) || defined(PLODAH_MODS_INDIC_RCTL_INDEX) || defined(PLODAH_MODS_INDIC_LSHIFT_INDEX) || defined(PLODAH_MODS_INDIC_RSHIFT_INDEX) )
      modsrgb = hsv_to_rgb( plodah_rgblimit_ind( rgb_matrix_get_hsv(), PLODAH_MODS_INDIC_HSV, PLODAH_INDICATOR_MINVAL ) );
    #endif // PLODAH_MODS_INDIC_LALT_INDEX

    #if defined(PLODAH_MODS_INDIC_LCTL_INDEX) || defined(PLODAH_MODS_INDIC_RCTL_INDEX)
      if (!rgb_matrix_get_flags()) {
        #if defined(PLODAH_MODS_INDIC_LCTL_INDEX)
          rgb_matrix_set_color(PLODAH_MODS_INDIC_LCTL_INDEX, RGB_OFF);
        #endif // defined(PLODAH_MODS_INDIC_LCTL_INDEX)
        #if defined(PLODAH_MODS_INDIC_RCTL_INDEX)
          rgb_matrix_set_color(PLODAH_MODS_INDIC_RCTL_INDEX, RGB_OFF);
        #endif // defined(PLODAH_MODS_INDIC_RCTL_INDEX)
      }
      if (ctl_pressed) {
        #if defined(PLODAH_MODS_INDIC_LCTL_INDEX)
          rgb_matrix_set_color(PLODAH_MODS_INDIC_LCTL_INDEX, modsrgb.r, modsrgb.g, modsrgb.b);
        #endif // defined(PLODAH_MODS_INDIC_LCTL_INDEX)
        #if defined(PLODAH_MODS_INDIC_RCTL_INDEX)
          rgb_matrix_set_color(PLODAH_MODS_INDIC_RCTL_INDEX, modsrgb.r, modsrgb.g, modsrgb.b);
        #endif // defined(PLODAH_MODS_INDIC_RCTL_INDEX)
      }
    #endif // PLODAH_MODS_INDIC_LCTL_INDEX

    #if defined(PLODAH_MODS_INDIC_LALT_INDEX) || defined(PLODAH_MODS_INDIC_RALT_INDEX)
      if (!rgb_matrix_get_flags()) {
        #if defined(PLODAH_MODS_INDIC_LALT_INDEX)
          rgb_matrix_set_color(PLODAH_MODS_INDIC_LALT_INDEX, RGB_OFF);
        #endif  // PLODAH_MODS_INDIC_LALT_INDEX
        #if defined(PLODAH_MODS_INDIC_RALT_INDEX)
          rgb_matrix_set_color(PLODAH_MODS_INDIC_RALT_INDEX, RGB_OFF);
        #endif  // PLODAH_MODS_INDIC_RALT_INDEX
      }
      if (alt_pressed) {
        #if defined(PLODAH_MODS_INDIC_LALT_INDEX)
          rgb_matrix_set_color(PLODAH_MODS_INDIC_LALT_INDEX, modsrgb.r, modsrgb.g, modsrgb.b);
        #endif  // PLODAH_MODS_INDIC_LALT_INDEX
        #if defined(PLODAH_MODS_INDIC_RALT_INDEX)
          rgb_matrix_set_color(PLODAH_MODS_INDIC_RALT_INDEX, modsrgb.r, modsrgb.g, modsrgb.b);
        #endif  // PLODAH_MODS_INDIC_RALT_INDEX
      }
    #endif // PLODAH_MODS_INDIC_LALT_INDEX

    #if defined(PLODAH_MODS_INDIC_LSHIFT_INDEX) || defined(PLODAH_MODS_INDIC_RSHIFT_INDEX)
      if (!rgb_matrix_get_flags()) {
        #if defined(PLODAH_MODS_INDIC_LSHIFT_INDEX)
          rgb_matrix_set_color(PLODAH_MODS_INDIC_LSHIFT_INDEX, RGB_OFF);
        #endif  // PLODAH_MODS_INDIC_LSHIFT_INDEX
        #if defined(PLODAH_MODS_INDIC_RSHIFT_INDEX)
          rgb_matrix_set_color(PLODAH_MODS_INDIC_RSHIFT_INDEX, RGB_OFF);
        #endif  // PLODAH_MODS_INDIC_RSHIFT_INDEX
      }
      #if defined(CAPS_WORD_ENABLE)
       if (sft_held || sft_pressed) {
      #else // CAPS_WORD_ENABLE
       if (sft_pressed) {
      #endif // CAPS_WORD_ENABLE
        #if defined(PLODAH_MODS_INDIC_LSHIFT_INDEX)
          rgb_matrix_set_color(PLODAH_MODS_INDIC_LSHIFT_INDEX, modsrgb.r, modsrgb.g, modsrgb.b);
        #endif  // PLODAH_MODS_INDIC_LSHIFT_INDEX
        #if defined(PLODAH_MODS_INDIC_RSHIFT_INDEX)
          rgb_matrix_set_color(PLODAH_MODS_INDIC_RSHIFT_INDEX, modsrgb.r, modsrgb.g, modsrgb.b);
        #endif  // PLODAH_MODS_INDIC_RSHIFT_INDEX
      }
    #endif // PLODAH_MODS_INDIC_LSHIFT_INDEX

    #if (defined(PLODAH_MODS_INDIC_LGUI_INDEX) || defined(PLODAH_MODS_INDIC_RGUI_INDEX)) && (defined(PLODAH_GULOCK_INDIC_ENABLE) || !defined(PLODAH_MODS_INDIC_GUI_DISABLE) )
      if (!rgb_matrix_get_flags()) {
        #if defined(PLODAH_MODS_INDIC_LGUI_INDEX)
          rgb_matrix_set_color(PLODAH_MODS_INDIC_LGUI_INDEX, RGB_OFF);
        #endif  // PLODAH_MODS_INDIC_LGUI_INDEX
        #if defined(PLODAH_MODS_INDIC_RGUI_INDEX)
          rgb_matrix_set_color(PLODAH_MODS_INDIC_RGUI_INDEX, RGB_OFF);
        #endif  // PLODAH_MODS_INDIC_RGUI_INDEX
      }
      #if !defined(PLODAH_MODS_INDIC_GUI_DISABLE)
        if ( gui_pressed ) {
          #if defined(PLODAH_MODS_INDIC_LGUI_INDEX)
            rgb_matrix_set_color(PLODAH_MODS_INDIC_LGUI_INDEX, modsrgb.r, modsrgb.g, modsrgb.b);
          #endif  // PLODAH_MODS_INDIC_LGUI_INDEX
          #if defined(PLODAH_MODS_INDIC_RGUI_INDEX)
            rgb_matrix_set_color(PLODAH_MODS_INDIC_RGUI_INDEX, modsrgb.r, modsrgb.g, modsrgb.b);
          #endif  // PLODAH_MODS_INDIC_RGUI_INDEX
        }
      #endif // PLODAH_MODS_INDIC_GUI_DISABLE
      #if defined(PLODAH_GULOCK_INDIC_ENABLE)
        guilockrgb = hsv_to_rgb( plodah_rgblimit_ind( rgb_matrix_get_hsv(), PLODAH_GULOCK_INDIC_HSV, PLODAH_INDICATOR_MINVAL ) );
        if ( keymap_config.no_gui ) {
          #if defined(PLODAH_MODS_INDIC_LGUI_INDEX)
            rgb_matrix_set_color(PLODAH_MODS_INDIC_LGUI_INDEX, guilockrgb.r, guilockrgb.g, guilockrgb.b);
          #endif  // PLODAH_MODS_INDIC_LGUI_INDEX
          #if defined(PLODAH_MODS_INDIC_RGUI_INDEX)
            rgb_matrix_set_color(PLODAH_MODS_INDIC_RGUI_INDEX, guilockrgb.r, guilockrgb.g, guilockrgb.b);
          #endif  // PLODAH_MODS_INDIC_RGUI_INDEX
        }
      #endif // defined(PLODAH_GULOCK_INDIC_ENABLE)
    #endif // PLODAH_MODS_INDIC_LGUI_INDEX

    return false;
  }
#endif // RGB_MATRIX_ENABLE
