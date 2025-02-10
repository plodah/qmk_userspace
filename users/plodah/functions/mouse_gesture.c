#if defined(PLODAH_MSGESTURE_ENABLE) && defined(DEFERRED_EXEC_ENABLE)

  #define PLODAH_MSGESTURE_TIMEOUT 225
  #define PLODAH_MSGESTURE_DEBOUNCE 25
  #define PLODAH_MSGESTURE_COOLDOWN 800
  #define PLODAH_MSGESTURE_WIGGLES 4
  #define PLODAH_MSGESTURE_THRESHOLD 1800

  typedef struct plodah_msGesture_t {
    deferred_token cooldown;
    deferred_token timeout;
    uint8_t count;
    int16_t accum;
    bool stage;
  } plodah_msGesture_t;

  deferred_token plodah_msGestureSwitchCooldown = INVALID_DEFERRED_TOKEN;
  deferred_token plodah_msGestureSwitchDebounce = INVALID_DEFERRED_TOKEN;

  plodah_msGesture_t plodah_msGesture_X;
  plodah_msGesture_t plodah_msGesture_Y;
  bool plodah_msGestureDebounce = false;
  bool plodah_msGestureCooldown = false;

  plodah_msGesture_t plodah_msGestureReset(plodah_msGesture_t gesture, uint8_t flags){
    if(flags & 0b1000 ){ // 8
        gesture.accum = 0;
    }
    if(flags & 0b100 ){ // 4
        gesture.count = 0;
    }
    if(flags & 0b10){ // 2
        gesture.stage = false;
    }
    if(flags & 0b1){ // 1
      gesture.timeout = INVALID_DEFERRED_TOKEN;
    }
    return gesture;
  }

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

  int8_t plodah_msgesturecheck(report_mouse_t mouse_report) {
    if(plodah_msGestureDebounce || plodah_msGestureCooldown){
        return 0;
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

    if( plodah_msGesture_X.count >= PLODAH_MSGESTURE_WIGGLES ) {
        plodah_msGestureCooldown = true;
        plodah_msGestureSwitchCooldown = defer_exec(PLODAH_MSGESTURE_COOLDOWN, plodah_msgesture_expireCooldown, NULL);
        dprintf("Thats an X Jiggle\n");
        return 1;
    }

    if( plodah_msGesture_Y.count >= PLODAH_MSGESTURE_WIGGLES ) {
        plodah_msGestureCooldown = true;
        plodah_msGestureSwitchCooldown = defer_exec(PLODAH_MSGESTURE_COOLDOWN, plodah_msgesture_expireCooldown, NULL);
        dprintf("Thats a Y Jiggle\n");
        return -1;
    }
    return 0;
  }
#endif
