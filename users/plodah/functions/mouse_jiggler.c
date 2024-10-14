#pragma once

static deferred_token token = INVALID_DEFERRED_TOKEN;
static report_mouse_t report = {0};

#if defined(RGB_MATRIX_ENABLE) && defined(PLODAH_MSJIGGLER_INDICATOR_RGBINDEX) && !defined(PLODAH_MSJIGGLER_INDICATOR_HSV)
  #define PLODAH_MSJIGGLER_INDICATOR_HSV HSV_RED
#endif // PLODAH_MSJIGGLER_INDICATOR_HSV default

uint32_t jiggler_callback_circle(uint32_t trigger_time, void* cb_arg) {
  // Deltas to move in a circle of radius 20 pixels over 32 frames.
  static const int8_t deltas[32] = {
      0, -1, -2, -2, -3, -3, -4, -4, -4, -4, -3, -3, -2, -2, -1, 0,
      0, 1, 2, 2, 3, 3, 4, 4, 4, 4, 3, 3, 2, 2, 1, 0};
  static uint8_t phase = 0;
  // Get x delta from table and y delta by rotating a quarter cycle.
  report.x = deltas[phase];
  report.y = deltas[(phase + 8) & 31];
  phase = (phase + 1) & 31;
  host_mouse_send(&report);
  return 16;  // Call the callback every 16 ms.
}

uint32_t jiggler_callback_subtle(uint32_t trigger_time, void* cb_arg) {
  static const int8_t deltas[16] = { 1, -1, 1, 1, -2, 2, -2, -2, 2, -2, 2, 2, -1, 1, -1, -1 }; // paradiddle
  static uint8_t phase = 0;
  report.x = deltas[phase];
  report.y = deltas[(phase + 8) & 15];
  phase = (phase + 1) & 15;
  host_mouse_send(&report);
  return 15000 + deltas[phase]*4000 + phase*100;
}

void jiggler_onclick( uint16_t keycode ) {
  if (
    #ifndef PLODAH_MSJIGGLER_AUTOSTOP
      keycode == PL_MSJIG &&
    #endif // PLODAH_MSJIGGLER_AUTOSTOP
    token
  ) {
    // If jiggler is currently running, stop when any key is pressed.
    cancel_deferred_exec(token);
    token = INVALID_DEFERRED_TOKEN;
    report = (report_mouse_t){};  // Clear the mouse.
    host_mouse_send(&report);
  }
  else if (keycode == PL_MSJIG) {
    #ifdef PLODAH_MSJIGGLER_UNSUBTLE
      token = defer_exec(1, jiggler_callback_circle, NULL);  // Schedule callback.
    #else
      token = defer_exec(1, jiggler_callback_subtle, NULL);  // Schedule callback.
    #endif // jiggle patterns
  }
}
