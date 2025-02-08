#if defined(PLODAH_MSGESTURE_ENABLE) && defined(DEFERRED_EXEC_ENABLE)

  #define PLODAH_MSGESTURE_TIMEOUT 225
  #define PLODAH_MSGESTURE_DEBOUNCE 25
  #define PLODAH_MSGESTURE_COOLDOWN 800
  #define PLODAH_MSGESTURE_WIGGLES 4
  #define PLODAH_MSGESTURE_THRESHOLD 1800

  deferred_token plodah_msGestureSwitchCooldown = INVALID_DEFERRED_TOKEN;
  deferred_token plodah_msGestureSwitchDebounce = INVALID_DEFERRED_TOKEN;
  deferred_token plodah_msGestureShakeXTimeout = INVALID_DEFERRED_TOKEN;
  deferred_token plodah_msGestureShakeYTimeout = INVALID_DEFERRED_TOKEN;

  uint8_t plodah_msGestureXCount = 0;
  uint8_t plodah_msGestureYCount = 0;
  int16_t plodah_msGestureXAccum = 0;
  int16_t plodah_msGestureYAccum = 0;
  bool plodah_msGestureXDirection = false;
  bool plodah_msGestureYDirection = false;
  bool plodah_msGestureDebounce = false;
  bool plodah_msGestureCooldown = false;

  void plodah_msgesturereset(void){
    plodah_msGestureSwitchCooldown = INVALID_DEFERRED_TOKEN;
    plodah_msGestureSwitchDebounce = INVALID_DEFERRED_TOKEN;
    plodah_msGestureShakeXTimeout = INVALID_DEFERRED_TOKEN;
    plodah_msGestureShakeYTimeout = INVALID_DEFERRED_TOKEN;
    plodah_msGestureXCount = 0;
    plodah_msGestureYCount = 0;
    plodah_msGestureXAccum = 0;
    plodah_msGestureYAccum = 0;
    plodah_msGestureXDirection = false;
    plodah_msGestureYDirection = false;
  }

  uint32_t plodah_msgesture_expireXTimeout(uint32_t trigger_time, void* cb_arg){
    plodah_msGestureXCount = 0;
    plodah_msGestureXAccum = 0;
    plodah_msGestureXDirection = false;
    return 0;
  }

  uint32_t plodah_msgesture_expireYTimeout(uint32_t trigger_time, void* cb_arg){
    plodah_msGestureYCount = 0;
    plodah_msGestureYAccum = 0;
    plodah_msGestureYDirection = false;
    return 0;
  }

  uint32_t plodah_msgesture_expireDebounce(uint32_t trigger_time, void* cb_arg){
    plodah_msGestureXAccum = 0;
    plodah_msGestureYAccum = 0;
    plodah_msGestureDebounce = false;
    return 0;
  }

  uint32_t plodah_msgesture_expireCooldown(uint32_t trigger_time, void* cb_arg){
    plodah_msGestureCooldown = false;
    plodah_msGestureXCount = 0;
    plodah_msGestureYCount = 0;
    plodah_msGestureXAccum = 0;
    plodah_msGestureYAccum = 0;
    return 0;
  }

  int8_t plodah_msgesturecheck(report_mouse_t mouse_report) {
    if(plodah_msGestureDebounce || plodah_msGestureCooldown){
        return 0;
    }
    plodah_msGestureXAccum += (10 * mouse_report.x);
    plodah_msGestureYAccum += (10 * mouse_report.y);

    if( abs(plodah_msGestureXAccum) > abs(plodah_msGestureYAccum) && abs(plodah_msGestureXAccum) > PLODAH_MSGESTURE_THRESHOLD ){
        plodah_msGestureSwitchDebounce = defer_exec(PLODAH_MSGESTURE_DEBOUNCE, plodah_msgesture_expireDebounce, NULL);
        if( (abs(plodah_msGestureXAccum) > PLODAH_MSGESTURE_THRESHOLD && plodah_msGestureXCount==0 ) || (plodah_msGestureXAccum > PLODAH_MSGESTURE_THRESHOLD && !plodah_msGestureXDirection) || (plodah_msGestureXAccum < -PLODAH_MSGESTURE_THRESHOLD && plodah_msGestureXDirection) ) {
            plodah_msGestureXCount++;
            dprintf("==X==> C:%d,%d  acc:%d,%d (%d,%d) \n", plodah_msGestureXCount, plodah_msGestureYCount, plodah_msGestureXAccum, plodah_msGestureYAccum, abs(plodah_msGestureXAccum), abs(plodah_msGestureYAccum) );
            plodah_msGestureXDirection = plodah_msGestureXAccum > PLODAH_MSGESTURE_THRESHOLD;
            plodah_msGestureDebounce = true;
            cancel_deferred_exec(plodah_msGestureShakeXTimeout);
            plodah_msGestureShakeXTimeout = defer_exec( PLODAH_MSGESTURE_TIMEOUT, plodah_msgesture_expireXTimeout, NULL );
        }
    }

    if( abs(plodah_msGestureYAccum) > abs(plodah_msGestureXAccum) && abs(plodah_msGestureYAccum) > PLODAH_MSGESTURE_THRESHOLD ){
        plodah_msGestureSwitchDebounce = defer_exec(PLODAH_MSGESTURE_DEBOUNCE, plodah_msgesture_expireDebounce, NULL);
        if( (abs(plodah_msGestureYAccum) > PLODAH_MSGESTURE_THRESHOLD && plodah_msGestureYCount==0 ) || (plodah_msGestureYAccum > PLODAH_MSGESTURE_THRESHOLD && !plodah_msGestureYDirection) || (plodah_msGestureYAccum < -PLODAH_MSGESTURE_THRESHOLD && plodah_msGestureYDirection) ) {
            plodah_msGestureYCount++;
            dprintf("==Y==> C:%d,%d  acc:%d,%d (%d,%d) \n", plodah_msGestureXCount, plodah_msGestureYCount, plodah_msGestureXAccum, plodah_msGestureYAccum, abs(plodah_msGestureXAccum), abs(plodah_msGestureYAccum) );
            plodah_msGestureYDirection = plodah_msGestureYAccum > PLODAH_MSGESTURE_THRESHOLD;
            plodah_msGestureDebounce = true;
            cancel_deferred_exec(plodah_msGestureShakeYTimeout);
            plodah_msGestureShakeYTimeout = defer_exec( PLODAH_MSGESTURE_TIMEOUT, plodah_msgesture_expireYTimeout, NULL );
        }
    }

    if( plodah_msGestureXCount >= PLODAH_MSGESTURE_WIGGLES ) {
        plodah_msGestureCooldown = true;
        plodah_msGestureSwitchCooldown = defer_exec(PLODAH_MSGESTURE_COOLDOWN, plodah_msgesture_expireCooldown, NULL);
        dprintf("Thats an X Jiggle\n");
        return 1;
    }

    if( plodah_msGestureYCount >= PLODAH_MSGESTURE_WIGGLES ) {
        plodah_msGestureCooldown = true;
        plodah_msGestureSwitchCooldown = defer_exec(PLODAH_MSGESTURE_COOLDOWN, plodah_msgesture_expireCooldown, NULL);
        dprintf("Thats a Y Jiggle\n");
        return -1;
    }
    return 0;
  }
#endif
