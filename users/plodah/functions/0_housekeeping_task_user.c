#if ( defined(AUTOCORRECT_ENABLE) && defined(RGB_MATRIX_ENABLE) && (!defined(PLODAH_AUTOCORRECT_IND_MODE_DE)) ) || (defined(PLODAH_TYPINGINDICATOR_RGBINDEX)) || (defined(DYNAMIC_MACRO_ENABLE) && defined(PLODAH_DYNAMIC_MACRO_TIMEOUT) && !defined(PLODAH_DYNAMIC_MACRO_TIMEOUT_MODE_DE)) || (defined(PLODAH_REPEATHOLD_RGB) && defined(RGB_MATRIX_ENABLE))
void housekeeping_task_user(void) {
  #if defined(AUTOCORRECT_ENABLE) && defined(RGB_MATRIX_ENABLE) && (!defined(PLODAH_AUTOCORRECT_IND_MODE_DE))
    plodah_autocorrect_indicator_check();
  #endif // AUTOCORRECT_ENABLE && RGB_MATRIX_ENABLE
  #if defined(PLODAH_TYPINGINDICATOR_RGBINDEX)
    plodah_typingindicator_check();
  #endif // PLODAH_TYPINGINDICATOR_RGBINDEX
  #if defined(DYNAMIC_MACRO_ENABLE) && defined(PLODAH_DYNAMIC_MACRO_TIMEOUT) && !defined(PLODAH_DYNAMIC_MACRO_TIMEOUT_MODE_DE)
    plodah_dynamic_macro_check();
  #endif // defined(DYNAMIC_MACRO_ENABLE) && defined(PLODAH_DYNAMIC_MACRO_TIMEOUT)
  #if defined(PLODAH_REPEATHOLD_RGB) && defined(RGB_MATRIX_ENABLE)
    repeathold_rgb_check();
  #endif // defined(PLODAH_REPEATHOLD_RGB) && defined(RGB_MATRIX_ENABLE)
}
#endif // ( defined(AUTOCORRECT_ENABLE) && defined(RGB_MATRIX_ENABLE) ) || (defined(PLODAH_TYPINGINDICATOR_RGBINDEX))
