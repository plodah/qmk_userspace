#if defined(DYNAMIC_MACRO_ENABLE)
  #pragma once
  #include "action.h"
  #include "action_util.h"
  #include "debug.h"
  #include "deferred_exec.h"
  #include "dynamic_macros.h"
  #include "keymap.h"
  #include "process_dynamic_macro.h"

  bool dynamic_macro_record_end_user(int8_t direction) {
    #if defined(PLODAH_DYNAMIC_MACRO_TIMEOUT_MODE_DE)
      dynamicMacroToken = INVALID_DEFERRED_TOKEN;
    #endif // PLODAH_DYNAMIC_MACRO_TIMEOUT_MODE_DE
    #if defined(RGB_MATRIX_ENABLE) && defined(PLODAH_DMAC_INDIC_INDEX)
      is_dynamic_macro_recording = false;
    #endif
    return true;
  }

  bool dynamic_macro_record_key_user(int8_t direction, keyrecord_t *record){
    #if defined(PLODAH_DYNAMIC_MACRO_TIMEOUT)
      if(is_dynamic_macro_recording){
        #if defined(PLODAH_DYNAMIC_MACRO_TIMEOUT_MODE_DE)
          extend_deferred_exec(dynamicMacroToken, PLODAH_DYNAMIC_MACRO_TIMEOUT);
        #else //
          dynamic_macro_timer = timer_read();
        #endif //
      }
    #endif // PLODAH_DYNAMIC_MACRO_TIMEOUT
    return true;
  }

  uint32_t dynamic_macro_stop_recording_DE(uint32_t trigger_time, void *cb_arg){
    dynamic_macro_stop_recording();
    return 0;
  }

  bool dynamic_macro_record_start_user(int8_t direction) {
    #if defined(RGB_MATRIX_ENABLE) && defined(PLODAH_DMAC_INDIC_INDEX)
      is_dynamic_macro_recording = true;
    #endif
    #if defined(PLODAH_DYNAMIC_MACRO_TIMEOUT)
      #if defined(PLODAH_DYNAMIC_MACRO_TIMEOUT_MODE_DE)
        dynamicMacroToken = defer_exec(PLODAH_DYNAMIC_MACRO_TIMEOUT, dynamic_macro_stop_recording_DE, NULL);
      #else //
        dynamic_macro_timer = timer_read();
      #endif //
    #endif // PLODAH_DYNAMIC_MACRO_TIMEOUT
    return true;
  }

  #if defined(PLODAH_DYNAMIC_MACRO_TIMEOUT) && !defined(PLODAH_DYNAMIC_MACRO_TIMEOUT_MODE_DE)
  void housekeeping_task_plodah_dynamic_macro(void){
    if (timer_elapsed(dynamic_macro_timer) > PLODAH_DYNAMIC_MACRO_TIMEOUT){
      dynamic_macro_stop_recording();
    }
  }
  #endif // ! PLODAH_DYNAMIC_MACRO_TIMEOUT_MODE_DE
#endif // DYNAMIC_MACRO_ENABLE
