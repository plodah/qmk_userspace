// cannibalised https://getreuer.info/posts/keyboards/macros3/index.html#a-mouse-jiggler to make this.

#include <stdbool.h>
#include "quantum.h"
#include "mouse_jiggler.h"

uint32_t jiggler_pattern(int8_t deltas[], int8_t numdeltas, int8_t phasefraction, int8_t scalex, int8_t scaley, bool randomdelay, int16_t basedelay ) {
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

// jiggler_pattern( deltas[], numdeltas, phasefraction, scalex, scaley, randomdelay, basedelay )
uint32_t jiggler_circle(uint32_t trigger_time, void* cb_arg) {
  return jiggler_pattern(circledeltas, 32, 4, 2, 2, 0, 64 );
}

uint32_t jiggler_square(uint32_t trigger_time, void* cb_arg) {
  return jiggler_pattern(squaredeltas, 16, 4, 2, 2, 0, 64 );
}

uint32_t jiggler_intro(uint32_t trigger_time, void* cb_arg) {
  return jiggler_pattern(circledeltas, 32, 4, 1, 1, 0, 16 );
}

uint32_t jiggler_figure(uint32_t trigger_time, void* cb_arg) {
  return jiggler_pattern(circledeltas, 32, 4, 4, 4, 0, 64 );
}

uint32_t jiggler_subtle(uint32_t trigger_time, void* cb_arg) {
  return jiggler_pattern(subtledeltas, 16, 4, 1, 1, 1, 16384 );
}

uint32_t jiggler_xline(uint32_t trigger_time, void* cb_arg) {
  return jiggler_pattern(circledeltas, 32, 4, 1, 0, 0, 24 );
}

uint32_t jiggler_yline(uint32_t trigger_time, void* cb_arg) {
  return jiggler_pattern(circledeltas, 32, 4, 0, 1, 0, 24 );
}

uint32_t jiggler_introtimer(uint32_t trigger_time, void* cb_arg) {
  jiggler_intro_end();
  return 0;
}

void jiggler_end(void){
  dprintf("jiggler_end\n");
  cancel_deferred_exec(msJigMainToken);
  msJigReport = (report_mouse_t){};  // Clear the mouse.
  host_mouse_send(&msJigReport);
  #if defined(MSJIGGLER_INTRO)
    msJigIntroToken = defer_exec(1, jiggler_xline, NULL);
    #if defined(MSJIGGLER_INTRO_TIMEOUT)
      msJigIntroTimerToken = defer_exec(MSJIGGLER_INTRO_TIMEOUT, jiggler_introtimer, NULL);
    #endif // MSJIGGLER_INTRO_TIMEOUT
  #endif // MSJIGGLER_INTRO
  msJigMainToken = INVALID_DEFERRED_TOKEN;
}

void jiggler_start(void){
  dprintf("jiggler_start\n");
  #if defined(MSJIGGLER_PATTERN)
    #if MSJIGGLER_PATTERN == 1
      msJigMainToken = defer_exec(1, jiggler_figure, NULL);
    #else // MSJIGGLER_PATTERN == 1
      msJigMainToken = defer_exec(1, jiggler_circle, NULL);
    #endif // MSJIGGLER_PATTERN == 1
  #else // MSJIGGLER_PATTERN
    msJigMainToken = defer_exec(1, jiggler_subtle, NULL);
  #endif // MSJIGGLER_PATTERN
  #if defined(MSJIGGLER_INTRO)
    msJigIntroToken = defer_exec(1, jiggler_intro, NULL);
    #if defined(MSJIGGLER_INTRO_TIMEOUT)
      msJigIntroTimerToken = defer_exec(MSJIGGLER_INTRO_TIMEOUT, jiggler_introtimer, NULL);
    #endif // MSJIGGLER_INTRO_TIMEOUT
  #endif // MSJIGGLER_INTRO
}

void jiggler_toggle(void){
  dprintf("jiggler_toggle %d\n", msJigMainToken);
  jiggler_intro_end();
  if (msJigMainToken != INVALID_DEFERRED_TOKEN){
    jiggler_end();
  }
  else{
    jiggler_start();
  }
}

void jiggle_delay(uint16_t delay_sec){
    if( msJigMainToken != INVALID_DEFERRED_TOKEN ){
        extend_deferred_exec(msJigMainToken, delay_sec*1000 );
    }
}

bool process_record_mouse_jiggler(uint16_t keycode, keyrecord_t *record) {
    if (
        #if defined(MSJIGGLER_AUTOSTOP)
            msJigMainToken != INVALID_DEFERRED_TOKEN ||
        #endif // MSJIGGLER_AUTOSTOP
        keycode == COMMUNITY_MODULE_MOUSE_JIGGLER_TOGGLE &&
        record->event.pressed
    ) {
      jiggler_toggle();
    }

    // delay for 10 seconds when any key is pressed.
    // don't need simulated action while real actions are going.
    jiggle_delay(10);
    return true;
}

report_mouse_t pointing_device_task_mouse_jiggler(report_mouse_t mouse_report) {
    if( mouse_report.x != 0 || mouse_report.y != 0 ){
        jiggle_delay(5);
    }
    return mouse_report;
}
