#if (defined(PLODAH_ALTTAB_ENHANCEMENTS_ENABLE)) || ( defined(AUTOCORRECT_ENABLE) && defined(RGB_MATRIX_ENABLE) ) || (defined(PLODAH_TYPINGINDICATOR_RGBINDEX)) || (defined(PLODAH_REPEATHOLD_RGB) && defined(RGB_MATRIX_ENABLE))
void matrix_scan_user(void) {
  #if defined(PLODAH_ALTTAB_ENHANCEMENTS_ENABLE) && (!defined(PLODAH_ALTTAB_ENHANCEMENTS_MODE_DE))
    plodah_alttab_check();
  #endif // PLODAH_ALTTAB_ENHANCEMENTS_ENABLE
  #if defined(AUTOCORRECT_ENABLE) && defined(RGB_MATRIX_ENABLE) && (!defined(PLODAH_AUTOCORRECT_IND_MODE_DE))
    plodah_autocorrect_indicator_check();
  #endif // AUTOCORRECT_ENABLE && RGB_MATRIX_ENABLE
  #if defined (PLODAH_TYPINGINDICATOR_RGBINDEX)
    plodah_typingindicator_check();
  #endif // PLODAH_TYPINGINDICATOR_RGBINDEX
  #if defined(DYNAMIC_MACRO_ENABLE) && defined(PLODAH_DYNAMIC_MACRO_TIMEOUT)
    if (timer_elapsed(dynamic_macro_loop_timer) > PLODAH_DYNAMIC_MACRO_TIMEOUT){
        dynamic_macro_stop_recording();
    }
  #endif // defined(DYNAMIC_MACRO_ENABLE) && defined(PLODAH_DYNAMIC_MACRO_TIMEOUT)
  #if defined(PLODAH_REPEATHOLD_RGB) && defined(RGB_MATRIX_ENABLE)
    repeathold_rgb_check();
  #endif // defined(PLODAH_REPEATHOLD_RGB) && defined(RGB_MATRIX_ENABLE)
}
#endif // (defined(PLODAH_ALTTAB_ENHANCEMENTS_ENABLE)) || ( defined(AUTOCORRECT_ENABLE) && defined(RGB_MATRIX_ENABLE) ) || (defined(PLODAH_TYPINGINDICATOR_RGBINDEX))
