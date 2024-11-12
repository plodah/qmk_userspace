#if defined(DYNAMIC_MACRO_ENABLE)
  #pragma once
  bool dynamic_macro_record_start_user(int8_t direction) {
    #if defined (RGB_MATRIX_ENABLE) && defined (PLODAH_DMAC_INDIC_INDEX)
      is_dynamic_macro_recording = true;
    #endif
    #if defined(PLODAH_DYNAMIC_MACRO_TIMEOUT)
      dynamic_macro_loop_timer = timer_read();
    #endif // PLODAH_DYNAMIC_MACRO_TIMEOUT
    return true;
  }
  bool dynamic_macro_record_end_user(int8_t direction) {
    #if defined (RGB_MATRIX_ENABLE) && defined (PLODAH_DMAC_INDIC_INDEX)
      is_dynamic_macro_recording = false;
    #endif
    return true;
  }
  void plodah_dynamic_macro_check(void){
    if (timer_elapsed(dynamic_macro_loop_timer) > PLODAH_DYNAMIC_MACRO_TIMEOUT){
      dynamic_macro_stop_recording();
    }
  }
#endif // DYNAMIC_MACRO_ENABLE
