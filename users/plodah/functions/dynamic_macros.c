#if defined(DYNAMIC_MACRO_ENABLE)
  #pragma once

  #if (defined (RGB_MATRIX_ENABLE) && defined (PLODAH_DMAC_INDIC_INDEX)) || (defined(PLODAH_DYNAMIC_MACRO_TIMEOUT))
    bool is_dynamic_macro_recording = false;
  #endif // DYNAMIC_MACRO_ENABLE

  // #define PLODAH_DYNAMIC_MACRO_FORCE_NDE
  #if defined(DEFERRED_EXEC_ENABLE) && defined(PLODAH_DYNAMIC_MACRO_TIMEOUT) && (!defined(PLODAH_DYNAMIC_MACRO_FORCE_NDE))
    #define PLODAH_DYNAMIC_MACRO_TIMEOUT_MODE_DE
  #endif // DEFERRED_EXEC_ENABLE

  #if defined(PLODAH_DYNAMIC_MACRO_TIMEOUT_MODE_DE)
    // #pragma message("Deferred Exec Dynamic Macro Timeout")
    deferred_token dynamicMacroToken = INVALID_DEFERRED_TOKEN;
  #else
    // #pragma message("Non-DE Dynamic Macro Timeout")
    uint16_t dynamic_macro_timer;
  #endif // PLODAH_DYNAMIC_MACRO_TIMEOUT_MODE_DE

  bool dynamic_macro_record_end_user(int8_t direction) {
    #if defined(PLODAH_DYNAMIC_MACRO_TIMEOUT_MODE_DE)
      dynamicMacroToken = INVALID_DEFERRED_TOKEN;
    #endif // PLODAH_DYNAMIC_MACRO_TIMEOUT_MODE_DE
    #if defined (RGB_MATRIX_ENABLE) && defined (PLODAH_DMAC_INDIC_INDEX)
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
    #if defined (RGB_MATRIX_ENABLE) && defined (PLODAH_DMAC_INDIC_INDEX)
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


  #ifdef PLODAH_DYNAMIC_MACRO_KCS_ENABLE
    bool dynamic_macros_process_record_user( uint16_t keycode, keyrecord_t *record ) {
      /*
        QK_DYNAMIC_MACRO_RECORD_START_1 = 0x7C53,
        QK_DYNAMIC_MACRO_RECORD_START_2 = 0x7C54,
        QK_DYNAMIC_MACRO_RECORD_STOP = 0x7C55,
        QK_DYNAMIC_MACRO_PLAY_1 = 0x7C56,
        QK_DYNAMIC_MACRO_PLAY_2 = 0x7C57,
      */
      if(!record->event.pressed){
        uint16_t fwkeycode = QK_DYNAMIC_MACRO_PLAY_1;
        if( keycode == PL_DMAC2 ) {
          fwkeycode ++;
        }
        if( ctl_pressed || alt_pressed ) {
          fwkeycode -=3;
          ctl_pressed = 0;
          alt_pressed = 0;
        }
        #ifdef CONSOLE_ENABLE
          uprintf("DM:%u\n", fwkeycode);
        #endif
        return process_dynamic_macro( fwkeycode, record );
        }
      return true;
    }
  #endif // PLODAH_DYNAMIC_MACRO_KCS_ENABLE

  #if defined(PLODAH_DYNAMIC_MACRO_TIMEOUT) && !defined(PLODAH_DYNAMIC_MACRO_TIMEOUT_MODE_DE)
  void plodah_dynamic_macro_check(void){
    if (timer_elapsed(dynamic_macro_timer) > PLODAH_DYNAMIC_MACRO_TIMEOUT){
      dynamic_macro_stop_recording();
    }
  }
  #endif // ! PLODAH_DYNAMIC_MACRO_TIMEOUT_MODE_DE
#endif // DYNAMIC_MACRO_ENABLE
