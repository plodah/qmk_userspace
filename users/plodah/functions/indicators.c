#pragma once

#if ( defined(PLODAH_MODS_INDIC_LALT_INDEX) || defined(PLODAH_MODS_INDIC_RALT_INDEX) || defined(PLODAH_MODS_INDIC_LCTL_INDEX) || defined(PLODAH_MODS_INDIC_RCTL_INDEX) || defined(PLODAH_MODS_INDIC_LSHIFT_INDEX) || defined(PLODAH_MODS_INDIC_RSHIFT_INDEX) ) && (!defined(PLODAH_MODS_INDIC_RGB))
# define PLODAH_MODS_INDIC_RGB RGB_WHITE
#endif

#if (defined(PLODAH_DMAC_INDIC_INDEX)) && (!defined(PLODAH_DMAC_INDIC_RGB))
# define PLODAH_DMAC_INDIC_RGB RGB_RED
#endif

#if (defined(CAPS_LOCK_LED_INDEX)) && (! defined(PLODAH_CAPS_INDIC_RGB))
# define PLODAH_CAPS_INDIC_RGB RGB_RED
#endif

#if (defined(PLODAH_LAYER_INDIC_INDEX1)) && (!defined(PLODAH_LAYER_INDIC_RGB))
# define PLODAH_LAYER_INDIC_RGB RGB_YELLOW
#endif

bool plodah_indicator_handler(void) {
# ifdef CAPS_LOCK_LED_INDEX
    if (host_keyboard_led_state().caps_lock){
#     ifdef PLODAH_CAPS_INDIC_RGB
        rgb_matrix_set_color(CAPS_LOCK_LED_INDEX, PLODAH_CAPS_INDIC_RGB);
#     else // PLODAH_CAPS_INDICATOR_R/G/B
        rgb_matrix_set_color(CAPS_LOCK_LED_INDEX, RGB_RED);
#     endif // PLODAH_CAPS_INDICATOR_R/G/B
    }
    else {
      if (!rgb_matrix_get_flags()) {
        rgb_matrix_set_color(CAPS_LOCK_LED_INDEX, RGB_OFF);
      }
    }
# endif //CAPS_LOCK_LED_INDEX

# ifdef PLODAH_LAYER_INDIC_INDEX1
#   ifdef PLODAH_LAYER_INDIC_ONZERO
      bool onzero = true;
#   else
      bool onzero = false;
#   endif
  int highlayer = get_highest_layer(layer_state);
  for (int lindex = 0; lindex < DYNAMIC_KEYMAP_LAYER_COUNT; lindex++) {
    int thisindex = (lindex + PLODAH_LAYER_INDIC_INDEX1);
    if (!rgb_matrix_get_flags()) {
      rgb_matrix_set_color(thisindex, RGB_OFF);
    }
    if (highlayer == lindex && (lindex != 0 || onzero)) {
#     ifdef PLODAH_LAYER_INDIC_RGB
        rgb_matrix_set_color(thisindex, PLODAH_LAYER_INDIC_RGB);
#     else //PLODAH_LAYER_INDIC_RGB
        rgb_matrix_set_color(thisindex, RGB_RED);
#     endif //PLODAH_LAYER_INDIC_RGB
    }
    else {
#     ifdef PLODAH_LAYER_INDIC_BG_RGB
        if (highlayer != lindex && (lindex != 0 || onzero)) {
          rgb_matrix_set_color(thisindex, PLODAH_LAYER_INDIC_BG_RGB);
        }
#     endif
    }
  }
# endif //PLODAH_LAYER_INDIC_INDEX1

# if defined(DYNAMIC_MACRO_ENABLE) && defined (PLODAH_DMAC_INDIC_INDEX)
    if (!rgb_matrix_get_flags()) {
      rgb_matrix_set_color(PLODAH_DMAC_INDIC_INDEX, RGB_OFF);
    }
    if (is_dynamic_macro_recording) {
      rgb_matrix_set_color(PLODAH_DMAC_INDIC_INDEX, PLODAH_DMAC_INDIC_RGB);
    }
# endif // DYNAMIC_MACRO_ENABLE && PLODAH_DMAC_INDIC_INDEX

# ifdef PLODAH_TYPINGINDICATOR_RGBINDEX
    if(!rgb_matrix_get_flags()){
      rgb_matrix_set_color(PLODAH_TYPINGINDICATOR_RGBINDEX, RGB_OFF);
    }
    if(plodah_typingindicator_active){
      rgb_matrix_set_color(PLODAH_TYPINGINDICATOR_RGBINDEX, PLODAH_TYPINGINDICATOR_RGBCOLOR);
    }
# endif // PLODAH_TYPINGINDICATOR_RGBINDEX

# ifdef PLODAH_MODS_INDIC_LALT_INDEX
    if (!rgb_matrix_get_flags()) {
      rgb_matrix_set_color(PLODAH_MODS_INDIC_LALT_INDEX, RGB_OFF);
    }
    if (alt_pressed) {
      rgb_matrix_set_color(PLODAH_MODS_INDIC_LALT_INDEX, PLODAH_MODS_INDIC_RGB);
    }
# endif // PLODAH_MODS_INDIC_LALT_INDEX

# ifdef PLODAH_MODS_INDIC_RALT_INDEX
    if (!rgb_matrix_get_flags()) {
      rgb_matrix_set_color(PLODAH_MODS_INDIC_RALT_INDEX, RGB_OFF);
    }
    if (alt_pressed) {
      rgb_matrix_set_color(PLODAH_MODS_INDIC_RALT_INDEX, PLODAH_MODS_INDIC_RGB);
    }
# endif // PLODAH_MODS_INDIC_RALT_INDEX

# ifdef PLODAH_MODS_INDIC_LCTL_INDEX
    if (!rgb_matrix_get_flags()) {
      rgb_matrix_set_color(PLODAH_MODS_INDIC_LCTL_INDEX, RGB_OFF);
    }
    if (ctl_pressed) {
      rgb_matrix_set_color(PLODAH_MODS_INDIC_LCTL_INDEX, PLODAH_MODS_INDIC_RGB);
    }
# endif // PLODAH_MODS_INDIC_LCTL_INDEX

# ifdef PLODAH_MODS_INDIC_RCTL_INDEX
    if (!rgb_matrix_get_flags()) {
      rgb_matrix_set_color(PLODAH_MODS_INDIC_RCTL_INDEX, RGB_OFF);
    }
    if (ctl_pressed) {
      rgb_matrix_set_color(PLODAH_MODS_INDIC_RCTL_INDEX, PLODAH_MODS_INDIC_RGB);
    }
# endif // PLODAH_MODS_INDIC_RCTL_INDEX

# ifdef PLODAH_MODS_INDIC_LSHIFT_INDEX
    if (!rgb_matrix_get_flags()) {
      rgb_matrix_set_color(PLODAH_MODS_INDIC_LSHIFT_INDEX, RGB_OFF);
    }
    if (sft_pressed || sft_held) {
      rgb_matrix_set_color(PLODAH_MODS_INDIC_LSHIFT_INDEX, PLODAH_MODS_INDIC_RGB);
    }
# endif // PLODAH_MODS_INDIC_LSHIFT_INDEX

# ifdef PLODAH_MODS_INDIC_RSHIFT_INDEX
    if (!rgb_matrix_get_flags()) {
      rgb_matrix_set_color(PLODAH_MODS_INDIC_RSHIFT_INDEX, RGB_OFF);
    }
    if (sft_pressed || sft_held) {
      rgb_matrix_set_color(PLODAH_MODS_INDIC_RSHIFT_INDEX, PLODAH_MODS_INDIC_RGB);
    }
# endif // PLODAH_MODS_INDIC_RSHIFT_INDEX
  return false;
}
