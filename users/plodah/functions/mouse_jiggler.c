// cannibalised https://getreuer.info/posts/keyboards/macros3/index.html#a-mouse-jiggler to make this.
#if defined(PLODAH_MSJIGGLER_ENABLED) && defined(DEFERRED_EXEC_ENABLE)
  #pragma once
  static deferred_token msJigTokenA = INVALID_DEFERRED_TOKEN;
  #if defined(PLODAH_MSJIGGLER_INTRO)
    static deferred_token msJigTokenB = INVALID_DEFERRED_TOKEN;
  #endif // PLODAH_MSJIGGLER_INTRO
  static report_mouse_t msJigReport = {0};

  #if defined(RGB_MATRIX_ENABLE) && defined(PLODAH_MSJIGGLER_INDICATOR_RGBINDEX) && !defined(PLODAH_MSJIGGLER_INDICATOR_HSV)
    #define PLODAH_MSJIGGLER_INDICATOR_HSV HSV_RED
  #endif // PLODAH_MSJIGGLER_INDICATOR_HSV default

  uint32_t jiggler_callback_base(uint32_t trigger_time, void* cb_arg, int8_t deltas[], int8_t numdeltas, int8_t phasefraction, int8_t scale, bool randomdelay, int16_t basedelay ) {
    static uint8_t phase = 0;
    msJigReport.x = scale * deltas[phase];
    msJigReport.y = scale * deltas[(phase + (numdeltas / phasefraction)) & (numdeltas - 1)];
    host_mouse_send(&msJigReport);
    phase = (phase + 1) & (numdeltas-1);
    if(randomdelay){
      return basedelay + deltas[phase]*basedelay/4 + phase*basedelay/10;
    }
    return basedelay;
  }

  // Deltas only work if the length of the array is a power of 2.
  static int8_t circledeltas[32] = {0,-1,-2,-2,-3,-3,-4,-4,-4,-4,-3,-3,-2,-2,-1,0,0,1,2,2,3,3,4,4,4,4,3,3,2,2,1,0};
  static int8_t subtledeltas[16] = {1,-1,1,1,-2,2,-2,-2,2,-2,2,2,-1,1,-1,-1};

  uint32_t jiggler_callback_circle(uint32_t trigger_time, void* cb_arg) {
    // Deltas to move in a circle of radius 20 pixels over 32 frames.
    return jiggler_callback_base(trigger_time, cb_arg, circledeltas, 32, 4, 2, 0, 64 );
  }

  uint32_t jiggler_callback_intro(uint32_t trigger_time, void* cb_arg) {
    // Deltas to move in a circle of radius 20 pixels over 32 frames.
    return jiggler_callback_base(trigger_time, cb_arg, circledeltas, 32, 4, 1, 0, 50 );
  }

  uint32_t jiggler_callback_figure(uint32_t trigger_time, void* cb_arg) {
    // Deltas to move in a circle of radius 20 pixels over 32 frames.
    return jiggler_callback_base(trigger_time, cb_arg, circledeltas, 32, 4, 4, 0, 64 );
  }

  uint32_t jiggler_callback_subtle(uint32_t trigger_time, void* cb_arg) {
    // Deltas to move only 1 or 2 pixels at a time. Sum is 0, so no prevailing movement..
    return jiggler_callback_base(trigger_time, cb_arg, subtledeltas, 16, 4, 1, 1, 16384 );
  }

  void jiggler_onclick( uint16_t keycode ) {
    #ifdef PLODAH_MSJIGGLER_INTRO
      if (msJigTokenB != INVALID_DEFERRED_TOKEN){
        cancel_deferred_exec(msJigTokenB);
        msJigTokenB = INVALID_DEFERRED_TOKEN;
      }
    #endif // PLODAH_MSJIGGLER_INTRO
    if (
      #ifndef PLODAH_MSJIGGLER_AUTOSTOP
        keycode == PL_MSJG &&
      #endif // PLODAH_MSJIGGLER_AUTOSTOP
      msJigTokenA != INVALID_DEFERRED_TOKEN
    ) {
      cancel_deferred_exec(msJigTokenA);
      msJigTokenA = INVALID_DEFERRED_TOKEN;
      #if defined(PLODAH_MSJIGGLER_INTRO)
        cancel_deferred_exec(msJigTokenB);
        msJigTokenB = INVALID_DEFERRED_TOKEN;
      #endif // PLODAH_MSJIGGLER_INTRO
      msJigReport = (report_mouse_t){};  // Clear the mouse.
      host_mouse_send(&msJigReport);
    }
    else if (keycode == PL_MSJG) {
      #ifdef PLODAH_MSJIGGLER_PATTERN
        #if PLODAH_MSJIGGLER_PATTERN == 1
          msJigTokenA = defer_exec(1, jiggler_callback_figure, NULL);
        #else // PLODAH_MSJIGGLER_PATTERN == 1
          msJigTokenA = defer_exec(1, jiggler_callback_circle, NULL);
        #endif // PLODAH_MSJIGGLER_PATTERN == 1
      #else // PLODAH_MSJIGGLER_PATTERN
        msJigTokenA = defer_exec(1, jiggler_callback_subtle, NULL);
        #ifdef PLODAH_MSJIGGLER_INTRO
          msJigTokenB = defer_exec(1, jiggler_callback_intro, NULL);
        #endif // PLODAH_MSJIGGLER_INTRO
      #endif // PLODAH_MSJIGGLER_PATTERN
    }
  }
#endif // PLODAH_MSJIGGLER_ENABLED
