#pragma once
#include "functions/rgb.c"
HSV curhsv;
#if ( defined(PLODAH_MODS_INDIC_LALT_INDEX) || defined(PLODAH_MODS_INDIC_RALT_INDEX) || defined(PLODAH_MODS_INDIC_LCTL_INDEX) || defined(PLODAH_MODS_INDIC_RCTL_INDEX) || defined(PLODAH_MODS_INDIC_LSHIFT_INDEX) || defined(PLODAH_MODS_INDIC_RSHIFT_INDEX) ) && (!defined(PLODAH_MODS_INDIC_HSV))
# define PLODAH_MODS_INDIC_HSV HSV_WHITE
#endif

#if (defined(PLODAH_DMAC_INDIC_INDEX)) && (!defined(PLODAH_DMAC_INDIC_HSV))
# define PLODAH_DMAC_INDIC_HSV HSV_RED
#endif

#if (defined(CAPS_LOCK_LED_INDEX)) && (! defined(PLODAH_CAPS_INDIC_HSV))
# define PLODAH_CAPS_INDIC_HSV HSV_RED
#endif

#if (defined(PLODAH_LAYER_INDIC_INDEX1)) && (!defined(PLODAH_LAYER_INDIC_HSV))
# define PLODAH_LAYER_INDIC_HSV HSV_YELLOW
#endif

#ifndef PLODAH_INDICATOR_MINVAL
# define PLODAH_INDICATOR_MINVAL 85
#endif // PLODAH_INDICATOR_MINVAL

bool plodah_indicator_handler(void) {
  curhsv = rgb_matrix_get_hsv();
# ifdef CAPS_LOCK_LED_INDEX
    HSV capshsv = { PLODAH_CAPS_INDIC_HSV };
    if (host_keyboard_led_state().caps_lock){
      capshsv = plodah_rgblimit(curhsv, capshsv, PLODAH_INDICATOR_MINVAL);
      RGB capsrgb = hsv_to_rgb(capshsv);
      rgb_matrix_set_color(CAPS_LOCK_LED_INDEX, capsrgb.r, capsrgb.g, capsrgb.b);
    }
    else {
      if (!rgb_matrix_get_flags()) {
        rgb_matrix_set_color(CAPS_LOCK_LED_INDEX, RGB_OFF);
      }
    }
# endif //CAPS_LOCK_LED_INDEX

# ifdef PLODAH_LAYER_INDIC_INDEX1
    bool onzero = false;
    HSV layrhsv = { PLODAH_LAYER_INDIC_HSV };
    layrhsv = plodah_rgblimit(curhsv, layrhsv, PLODAH_INDICATOR_MINVAL);
    RGB layrrgb = hsv_to_rgb(layrhsv);
#   ifdef PLODAH_LAYER_INDIC_BG_HSV
      HSV laybhsv = { PLODAH_LAYER_INDIC_BG_HSV };
      laybhsv = plodah_rgblimit(curhsv, laybhsv, PLODAH_INDICATOR_MINVAL);
      RGB laybrgb = hsv_to_rgb(laybhsv);
#   endif

#   ifdef PLODAH_LAYER_INDIC_ONZERO
      onzero = true;
#   endif

  int highlayer = get_highest_layer(layer_state);
  for (int lindex = 0; lindex < DYNAMIC_KEYMAP_LAYER_COUNT; lindex++) {
    int thisindex = (lindex + PLODAH_LAYER_INDIC_INDEX1);
    if (!rgb_matrix_get_flags()) {
      rgb_matrix_set_color(thisindex, RGB_OFF);
    }
    if (highlayer == lindex && (lindex != 0 || onzero)) {
      rgb_matrix_set_color(thisindex, layrrgb.r, layrrgb.g, layrrgb.b);
    }
    else {
#     ifdef PLODAH_LAYER_INDIC_BG_HSV
        if (highlayer != lindex && (lindex != 0 || onzero)) {
          rgb_matrix_set_color(thisindex, laybrgb.r, laybrgb.g, laybrgb.b);
        }
#     endif
    }
  }
# endif //PLODAH_LAYER_INDIC_INDEX1

# if defined(DYNAMIC_MACRO_ENABLE) && defined (PLODAH_DMAC_INDIC_INDEX)
    HSV dmachsv = { PLODAH_DMAC_INDIC_HSV };
    dmachsv = plodah_rgblimit(curhsv, dmachsv, PLODAH_INDICATOR_MINVAL);
    RGB dmacrgb = hsv_to_rgb(dmachsv);

    if (!rgb_matrix_get_flags()) {
      rgb_matrix_set_color(PLODAH_DMAC_INDIC_INDEX, RGB_OFF);
    }
    if (is_dynamic_macro_recording) {
      rgb_matrix_set_color(PLODAH_DMAC_INDIC_INDEX, dmacrgb.r, dmacrgb.g, dmacrgb.b);
    }
# endif // DYNAMIC_MACRO_ENABLE && PLODAH_DMAC_INDIC_INDEX

# ifdef PLODAH_TYPINGINDICATOR_RGBINDEX
    HSV typnhsv = { PLODAH_TYPINGINDICATOR_HSV };
    typnhsv = plodah_rgblimit(curhsv, typnhsv, PLODAH_INDICATOR_MINVAL);
    RGB typnrgb = hsv_to_rgb(typnhsv);

    if(!rgb_matrix_get_flags()){
      rgb_matrix_set_color(PLODAH_TYPINGINDICATOR_RGBINDEX, RGB_OFF);
    }
    if(plodah_typingindicator_active){
      rgb_matrix_set_color(PLODAH_TYPINGINDICATOR_RGBINDEX, typnrgb.r, typnrgb.g, typnrgb.b);
    }
# endif // PLODAH_TYPINGINDICATOR_RGBINDEX

#if ( defined(PLODAH_MODS_INDIC_LALT_INDEX) || defined(PLODAH_MODS_INDIC_RALT_INDEX) || defined(PLODAH_MODS_INDIC_LCTL_INDEX) || defined(PLODAH_MODS_INDIC_RCTL_INDEX) || defined(PLODAH_MODS_INDIC_LSHIFT_INDEX) || defined(PLODAH_MODS_INDIC_RSHIFT_INDEX) )
    HSV modshsv = { PLODAH_MODS_INDIC_HSV };
    modshsv = plodah_rgblimit(curhsv, modshsv, PLODAH_INDICATOR_MINVAL);
    RGB modsrgb = hsv_to_rgb(modshsv);
#endif

# ifdef PLODAH_MODS_INDIC_LALT_INDEX
    if (!rgb_matrix_get_flags()) {
      rgb_matrix_set_color(PLODAH_MODS_INDIC_LALT_INDEX, RGB_OFF);
    }
    if (alt_pressed) {
      rgb_matrix_set_color(PLODAH_MODS_INDIC_LALT_INDEX, modsrgb.r, modsrgb.g, modsrgb.b);
    }
# endif // PLODAH_MODS_INDIC_LALT_INDEX

# ifdef PLODAH_MODS_INDIC_RALT_INDEX
    if (!rgb_matrix_get_flags()) {
      rgb_matrix_set_color(PLODAH_MODS_INDIC_RALT_INDEX, RGB_OFF);
    }
    if (alt_pressed) {
      rgb_matrix_set_color(PLODAH_MODS_INDIC_RALT_INDEX, modsrgb.r, modsrgb.g, modsrgb.b);
    }
# endif // PLODAH_MODS_INDIC_RALT_INDEX

# ifdef PLODAH_MODS_INDIC_LCTL_INDEX
    if (!rgb_matrix_get_flags()) {
      rgb_matrix_set_color(PLODAH_MODS_INDIC_LCTL_INDEX, RGB_OFF);
    }
    if (ctl_pressed) {
      rgb_matrix_set_color(PLODAH_MODS_INDIC_LCTL_INDEX, modsrgb.r, modsrgb.g, modsrgb.b);
    }
# endif // PLODAH_MODS_INDIC_LCTL_INDEX

# ifdef PLODAH_MODS_INDIC_RCTL_INDEX
    if (!rgb_matrix_get_flags()) {
      rgb_matrix_set_color(PLODAH_MODS_INDIC_RCTL_INDEX, RGB_OFF);
    }
    if (ctl_pressed) {
      rgb_matrix_set_color(PLODAH_MODS_INDIC_RCTL_INDEX, modsrgb.r, modsrgb.g, modsrgb.b);
    }
# endif // PLODAH_MODS_INDIC_RCTL_INDEX

# ifdef PLODAH_MODS_INDIC_LSHIFT_INDEX
    if (!rgb_matrix_get_flags()) {
      rgb_matrix_set_color(PLODAH_MODS_INDIC_LSHIFT_INDEX, RGB_OFF);
    }
    if (sft_pressed || sft_held) {
      rgb_matrix_set_color(PLODAH_MODS_INDIC_LSHIFT_INDEX, modsrgb.r, modsrgb.g, modsrgb.b);
    }
# endif // PLODAH_MODS_INDIC_LSHIFT_INDEX

# ifdef PLODAH_MODS_INDIC_RSHIFT_INDEX
    if (!rgb_matrix_get_flags()) {
      rgb_matrix_set_color(PLODAH_MODS_INDIC_RSHIFT_INDEX, RGB_OFF);
    }
    if (sft_pressed || sft_held) {
      rgb_matrix_set_color(PLODAH_MODS_INDIC_RSHIFT_INDEX, modsrgb.r, modsrgb.g, modsrgb.b);
    }
# endif // PLODAH_MODS_INDIC_RSHIFT_INDEX
  return false;
}
