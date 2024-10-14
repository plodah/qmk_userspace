#pragma once
// cannibalised https://getreuer.info/posts/keyboards/macros3/index.html#a-mouse-jiggler to make this.
static deferred_token token = INVALID_DEFERRED_TOKEN;
static report_mouse_t report = {0};

#if defined(RGB_MATRIX_ENABLE) && defined(PLODAH_MSJIGGLER_INDICATOR_RGBINDEX) && !defined(PLODAH_MSJIGGLER_INDICATOR_HSV)
  #define PLODAH_MSJIGGLER_INDICATOR_HSV HSV_RED
#endif // PLODAH_MSJIGGLER_INDICATOR_HSV default

uint32_t jiggler_callback_base(uint32_t trigger_time, void* cb_arg, int8_t deltas[], int8_t numdeltas, bool randomdelay, int16_t basedelay ) {
  static uint8_t phase = 0;
  report.x = deltas[phase];
  report.y = deltas[(phase + (numdeltas / 4)) & (numdeltas - 1)];
  host_mouse_send(&report);
  phase = (phase + 1) & (numdeltas-1);
  if(randomdelay){
    return basedelay + deltas[phase]*basedelay/4 + phase*basedelay/10;
  }
  return basedelay;
}

// Deltas only work if the length of the array is a power of 2.
uint32_t jiggler_callback_circle(uint32_t trigger_time, void* cb_arg) {
  // Deltas to move in a circle of radius 20 pixels over 32 frames.
  static int8_t circledeltas[32] = {0,-1,-2,-2,-3,-3,-4,-4,-4,-4,-3,-3,-2,-2,-1,0,0,1,2,2,3,3,4,4,4,4,3,3,2,2,1,0};
  return jiggler_callback_base(trigger_time, cb_arg, circledeltas, 32, 0, 40 );
}

uint32_t jiggler_callback_subtle(uint32_t trigger_time, void* cb_arg) {
  // Deltas to move only 1 or 2 pixels at a time. Sum is 0, so no prevailing movement..
  static int8_t subtledeltas[16] = {1,-1,1,1,-2,2,-2,-2,2,-2,2,2,-1,1,-1,-1};
  return jiggler_callback_base(trigger_time, cb_arg, subtledeltas, 16, 1, 10000 );
}

void jiggler_onclick( uint16_t keycode ) {
  if (
    #ifndef PLODAH_MSJIGGLER_AUTOSTOP
      keycode == PL_MSJIG &&
    #endif // PLODAH_MSJIGGLER_AUTOSTOP
    token
  ) {
    cancel_deferred_exec(token);
    token = INVALID_DEFERRED_TOKEN;
    report = (report_mouse_t){};  // Clear the mouse.
    host_mouse_send(&report);
  }
  else if (keycode == PL_MSJIG) {
    #ifdef PLODAH_MSJIGGLER_UNSUBTLE
      token = defer_exec(1, jiggler_callback_circle, NULL);
    #else // PLODAH_MSJIGGLER_UNSUBTLE
      token = defer_exec(1, jiggler_callback_subtle, NULL);
    #endif // PLODAH_MSJIGGLER_UNSUBTLE
  }
}
