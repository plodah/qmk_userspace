#if defined(PLODAH_MSGESTURE_ENABLE) && defined(DEFERRED_EXEC_ENABLE)
  #include "mouse_gesture.h"
  #include "mouse_jiggler.h"
  #include "better_dragscroll.h"
  #include "ploopy_via.h"

  void plodah_msGestureUpdate(void){
    #if defined(VIA_ENABLE) && defined(PLOOPY_VIAMENUS)
      plodah_msGesture_X.action = ploopyvia_config.wiggleball_action_h;
      plodah_msGesture_Y.action = ploopyvia_config.wiggleball_action_v;
      gestureCount              = ploopyvia_config.wiggleball_count;
    #else
      plodah_msGesture_X.action = GESTURE_ACTION_DRAGSCROLL;
      plodah_msGesture_Y.action = GESTURE_ACTION_MSJIGGLER;
      gestureCount = PLODAH_MSGESTURE_WIGGLES;
    #endif
  }
  deferred_token plodah_msGestureSwitchCooldown = INVALID_DEFERRED_TOKEN;
  deferred_token plodah_msGestureSwitchDebounce = INVALID_DEFERRED_TOKEN;

  bool plodah_msGestureDebounce = false;
  bool plodah_msGestureCooldown = false;

  void plodah_msGestureResetX(void){
    plodah_msGesture_X.accum = 0;
    plodah_msGesture_X.count = 0;
    plodah_msGesture_X.stage = false;
    plodah_msGesture_X.timeout = INVALID_DEFERRED_TOKEN;
  }

  void plodah_msGestureResetY(void){
    plodah_msGesture_Y.accum = 0;
    plodah_msGesture_Y.count = 0;
    plodah_msGesture_Y.stage = false;
    plodah_msGesture_Y.timeout = INVALID_DEFERRED_TOKEN;
  }

  void plodah_msGestureResetAll(void){
    plodah_msGestureSwitchCooldown = INVALID_DEFERRED_TOKEN;
    plodah_msGestureSwitchDebounce = INVALID_DEFERRED_TOKEN;
    plodah_msGestureResetX();
    plodah_msGestureResetY();
  }

  //
  uint32_t plodah_msgesture_expireXTimeout(uint32_t trigger_time, void* cb_arg){
    plodah_msGesture_X.accum = 0;
    plodah_msGesture_X.count = 0;
    plodah_msGesture_X.stage = false;
    return 0;
  }

  uint32_t plodah_msgesture_expireYTimeout(uint32_t trigger_time, void* cb_arg){
    plodah_msGesture_Y.accum = 0;
    plodah_msGesture_Y.count = 0;
    plodah_msGesture_Y.stage = false;
    return 0;
  }

  uint32_t plodah_msgesture_expireDebounce(uint32_t trigger_time, void* cb_arg){
    plodah_msGestureDebounce = false;
    plodah_msGesture_X.accum = 0;
    plodah_msGesture_Y.accum = 0;
    return 0;
  }

  uint32_t plodah_msgesture_expireCooldown(uint32_t trigger_time, void* cb_arg){
    plodah_msGestureCooldown = false;
    plodah_msGesture_X.accum = 0;
    plodah_msGesture_X.count = 0;
    plodah_msGesture_Y.accum = 0;
    plodah_msGesture_Y.count = 0;
    return 0;
  }

  void plodah_msGestureTriggered(uint8_t action){
    plodah_msGestureCooldown = true;
    plodah_msGestureSwitchCooldown = defer_exec(PLODAH_MSGESTURE_COOLDOWN, plodah_msgesture_expireCooldown, NULL);
    switch(action){
        case GESTURE_ACTION_MSJIGGLER:
          jiggler_toggle();
          break;
        case GESTURE_ACTION_DRAGSCROLL:
          better_dragscroll_toggle(true);
          break;
    }
  }

  report_mouse_t pointing_device_task_mouse_gesture(report_mouse_t mouse_report) {
    if(plodah_msGestureDebounce || plodah_msGestureCooldown){
        return mouse_report;
    }
    plodah_msGesture_X.accum += (10 * mouse_report.x);
    plodah_msGesture_Y.accum += (10 * mouse_report.y);

    if( abs(plodah_msGesture_X.accum) > abs(plodah_msGesture_Y.accum) && abs(plodah_msGesture_X.accum) > PLODAH_MSGESTURE_THRESHOLD ){
        plodah_msGestureSwitchDebounce = defer_exec(PLODAH_MSGESTURE_DEBOUNCE, plodah_msgesture_expireDebounce, NULL);
        if( (abs(plodah_msGesture_X.accum) > PLODAH_MSGESTURE_THRESHOLD && plodah_msGesture_X.count==0 ) || (plodah_msGesture_X.accum > PLODAH_MSGESTURE_THRESHOLD && !plodah_msGesture_X.stage) || (plodah_msGesture_X.accum < -PLODAH_MSGESTURE_THRESHOLD && plodah_msGesture_X.stage) ) {
            plodah_msGesture_X.count++;
            dprintf("==X==> C:%d,%d  acc:%d,%d (%d,%d) \n", plodah_msGesture_X.count, plodah_msGesture_Y.count, plodah_msGesture_X.accum, plodah_msGesture_Y.accum, abs(plodah_msGesture_X.accum), abs(plodah_msGesture_Y.accum) );

            plodah_msGesture_X.stage = plodah_msGesture_X.accum > PLODAH_MSGESTURE_THRESHOLD;
            plodah_msGestureDebounce = true;
            cancel_deferred_exec(plodah_msGesture_X.timeout);
            plodah_msGesture_X.timeout = defer_exec( PLODAH_MSGESTURE_TIMEOUT, plodah_msgesture_expireXTimeout, NULL );
        }
    }

    if( abs(plodah_msGesture_Y.accum) > abs(plodah_msGesture_X.accum) && abs(plodah_msGesture_Y.accum) > PLODAH_MSGESTURE_THRESHOLD ){
        plodah_msGestureSwitchDebounce = defer_exec(PLODAH_MSGESTURE_DEBOUNCE, plodah_msgesture_expireDebounce, NULL);
        if( (abs(plodah_msGesture_Y.accum) > PLODAH_MSGESTURE_THRESHOLD && plodah_msGesture_Y.count==0 ) || (plodah_msGesture_Y.accum > PLODAH_MSGESTURE_THRESHOLD && !plodah_msGesture_Y.stage) || (plodah_msGesture_Y.accum < -PLODAH_MSGESTURE_THRESHOLD && plodah_msGesture_Y.stage) ) {
            plodah_msGesture_Y.count++;
            dprintf("==Y==> C:%d,%d  acc:%d,%d (%d,%d) \n", plodah_msGesture_X.count, plodah_msGesture_Y.count, plodah_msGesture_X.accum, plodah_msGesture_Y.accum, abs(plodah_msGesture_X.accum), abs(plodah_msGesture_Y.accum) );
            plodah_msGesture_Y.stage = plodah_msGesture_Y.accum > PLODAH_MSGESTURE_THRESHOLD;
            plodah_msGestureDebounce = true;
            cancel_deferred_exec(plodah_msGesture_Y.timeout);
            plodah_msGesture_Y.timeout = defer_exec( PLODAH_MSGESTURE_TIMEOUT, plodah_msgesture_expireYTimeout, NULL );
        }
    }

    if( plodah_msGesture_X.count >= gestureCount ) {
        dprintf("X Jiggle a:%d\n", plodah_msGesture_X.action);
        plodah_msGestureTriggered(plodah_msGesture_X.action);
    }

    if( plodah_msGesture_Y.count >= gestureCount ) {
        dprintf("Y Jiggle a:%d\n", plodah_msGesture_Y.action);
        plodah_msGestureTriggered(plodah_msGesture_Y.action);
    }
    return mouse_report;
  }
#endif
