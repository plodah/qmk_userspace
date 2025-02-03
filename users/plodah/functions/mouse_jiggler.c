// cannibalised https://getreuer.info/posts/keyboards/macros3/index.html#a-mouse-jiggler to make this.
#if defined(PLODAH_MSJIGGLER_ENABLED) && defined(DEFERRED_EXEC_ENABLE)
  #pragma once
  static deferred_token msJigMainToken = INVALID_DEFERRED_TOKEN;
  static deferred_token msJigIntroToken = INVALID_DEFERRED_TOKEN;
  static deferred_token msJigIntroTimerToken = INVALID_DEFERRED_TOKEN;
  static report_mouse_t msJigReport = {0};

  #if defined(RGB_MATRIX_ENABLE) && defined(PLODAH_MSJIGGLER_INDICATOR_RGBINDEX) && !defined(PLODAH_MSJIGGLER_INDICATOR_HSV)
    #define PLODAH_MSJIGGLER_INDICATOR_HSV HSV_RED
  #endif // PLODAH_MSJIGGLER_INDICATOR_HSV default

  uint32_t jiggler_pattern(uint32_t trigger_time, void* cb_arg, int8_t deltas[], int8_t numdeltas, int8_t phasefraction, int8_t scalex, int8_t scaley, bool randomdelay, int16_t basedelay ) {
    static uint8_t phase = 0;
    msJigReport.x = scalex * deltas[phase];
    msJigReport.y = scaley * deltas[(phase + (numdeltas / phasefraction)) & (numdeltas - 1)];
    host_mouse_send(&msJigReport);
    phase = (phase + 1) & (numdeltas-1);
    if(randomdelay){
      return basedelay + deltas[phase]*basedelay/4 + phase*basedelay/10;
    }
    return basedelay;
  }

  void jiggler_intro_end(void){
    if (msJigIntroToken != INVALID_DEFERRED_TOKEN){
      cancel_deferred_exec(msJigIntroToken);
      msJigIntroToken = INVALID_DEFERRED_TOKEN;
    }
    if (msJigIntroTimerToken != INVALID_DEFERRED_TOKEN){
      cancel_deferred_exec(msJigIntroTimerToken);
      msJigIntroTimerToken = INVALID_DEFERRED_TOKEN;
    }
  }

  // Deltas only work if the length of the array is a power of 2.
  static int8_t circledeltas[32] = {0,-1,-2,-2,-3,-3,-4,-4,-4,-4,-3,-3,-2,-2,-1,0,0,1,2,2,3,3,4,4,4,4,3,3,2,2,1,0};
  static int8_t subtledeltas[16] = {1,-1,1,1,-2,2,-2,-2,2,-2,2,2,-1,1,-1,-1};

  // jiggler_pattern( trigger_time, cb_arg, deltas[], numdeltas, phasefraction, scalex, scaley, randomdelay, basedelay )

  uint32_t jiggler_circle(uint32_t trigger_time, void* cb_arg) {
    return jiggler_pattern(trigger_time, cb_arg, circledeltas, 32, 4, 2, 2, 0, 64 );
  }

  uint32_t jiggler_intro(uint32_t trigger_time, void* cb_arg) {
    return jiggler_pattern(trigger_time, cb_arg, circledeltas, 32, 4, 1, 1, 0, 16 );
  }

  uint32_t jiggler_figure(uint32_t trigger_time, void* cb_arg) {
    return jiggler_pattern(trigger_time, cb_arg, circledeltas, 32, 4, 4, 4, 0, 64 );
  }

  uint32_t jiggler_subtle(uint32_t trigger_time, void* cb_arg) {
    return jiggler_pattern(trigger_time, cb_arg, subtledeltas, 16, 4, 1, 1, 1, 16384 );
  }

  uint32_t jiggler_xline(uint32_t trigger_time, void* cb_arg) {
    return jiggler_pattern(trigger_time, cb_arg, circledeltas, 32, 4, 1, 0, 0, 24 );
  }

  uint32_t jiggler_yline(uint32_t trigger_time, void* cb_arg) {
    return jiggler_pattern(trigger_time, cb_arg, circledeltas, 32, 4, 0, 1, 0, 24 );
  }

  uint32_t jiggler_introtimer(uint32_t trigger_time, void* cb_arg) {
    jiggler_intro_end();
    return 0;
  }

  void jiggler_onclick( uint16_t keycode ) {
    jiggler_intro_end();
    if (
      #if !defined(PLODAH_MSJIGGLER_AUTOSTOP)
        keycode == PL_MSJG &&
      #endif // PLODAH_MSJIGGLER_AUTOSTOP
      msJigMainToken != INVALID_DEFERRED_TOKEN
    ) {
      cancel_deferred_exec(msJigMainToken);
      msJigMainToken = INVALID_DEFERRED_TOKEN;
      msJigReport = (report_mouse_t){};  // Clear the mouse.
      host_mouse_send(&msJigReport);

      #if defined(PLODAH_MSJIGGLER_INTRO)
        msJigIntroToken = defer_exec(1, jiggler_xline, NULL);
        #if defined(PLODAH_MSJIGGLER_INTRO_TIMEOUT)
          msJigIntroTimerToken = defer_exec(PLODAH_MSJIGGLER_INTRO_TIMEOUT, jiggler_introtimer, NULL);
        #endif // PLODAH_MSJIGGLER_INTRO_TIMEOUT
      #endif // PLODAH_MSJIGGLER_INTRO
    }
    else if (keycode == PL_MSJG) {
      #if defined(PLODAH_MSJIGGLER_PATTERN)
        #if PLODAH_MSJIGGLER_PATTERN == 1
          msJigMainToken = defer_exec(1, jiggler_figure, NULL);
        #else // PLODAH_MSJIGGLER_PATTERN == 1
          msJigMainToken = defer_exec(1, jiggler_circle, NULL);
        #endif // PLODAH_MSJIGGLER_PATTERN == 1
      #else // PLODAH_MSJIGGLER_PATTERN
        msJigMainToken = defer_exec(1, jiggler_subtle, NULL);
      #endif // PLODAH_MSJIGGLER_PATTERN

      #if defined(PLODAH_MSJIGGLER_INTRO)
        msJigIntroToken = defer_exec(1, jiggler_intro, NULL);
        #if defined(PLODAH_MSJIGGLER_INTRO_TIMEOUT)
          msJigIntroTimerToken = defer_exec(PLODAH_MSJIGGLER_INTRO_TIMEOUT, jiggler_introtimer, NULL);
        #endif // PLODAH_MSJIGGLER_INTRO_TIMEOUT
      #endif // PLODAH_MSJIGGLER_INTRO
    }
  }
#endif // PLODAH_MSJIGGLER_ENABLED
