#if defined(PLODAH_MSWIGGLE_ENABLE) && defined(DEFERRED_EXEC_ENABLE)

  #define PLODAH_MSWIGGLE_TIMEOUT 225
  #define PLODAH_MSWIGGLE_DEBOUNCE 25
  #define PLODAH_MSWIGGLE_COOLDOWN 800
  #define PLODAH_MSWIGGLE_WIGGLES 4
  #define PLODAH_MSWIGGLE_THRESHOLD 1800

  deferred_token msWglSwitchCooldown = INVALID_DEFERRED_TOKEN;
  deferred_token msWglSwitchDebounce = INVALID_DEFERRED_TOKEN;
  deferred_token msWglShakeXTimeout = INVALID_DEFERRED_TOKEN;
  deferred_token msWglShakeYTimeout = INVALID_DEFERRED_TOKEN;

  uint8_t msWglXCount = 0;
  uint8_t msWglYCount = 0;
  int16_t msWglXAccum = 0;
  int16_t msWglYAccum = 0;
  bool msWglXDirection = false;
  bool msWglYDirection = false;
  bool msWglDebounce = false;
  bool msWglCooldown = false;

  void plodah_wigglereset(void){
    msWglSwitchCooldown = INVALID_DEFERRED_TOKEN;
    msWglSwitchDebounce = INVALID_DEFERRED_TOKEN;
    msWglShakeXTimeout = INVALID_DEFERRED_TOKEN;
    msWglShakeYTimeout = INVALID_DEFERRED_TOKEN;
    msWglXCount = 0;
    msWglYCount = 0;
    msWglXAccum = 0;
    msWglYAccum = 0;
    msWglXDirection = false;
    msWglYDirection = false;
  }

  uint32_t plodah_wiggle_expireXTimeout(uint32_t trigger_time, void* cb_arg){
    msWglXCount = 0;
    msWglXAccum = 0;
    msWglXDirection = false;
    return 0;
  }

  uint32_t plodah_wiggle_expireYTimeout(uint32_t trigger_time, void* cb_arg){
    msWglYCount = 0;
    msWglYAccum = 0;
    msWglYDirection = false;
    return 0;
  }

  uint32_t plodah_wiggle_expireDebounce(uint32_t trigger_time, void* cb_arg){
    msWglXAccum = 0;
    msWglYAccum = 0;
    msWglDebounce = false;
    return 0;
  }

  uint32_t plodah_wiggle_expireCooldown(uint32_t trigger_time, void* cb_arg){
    msWglCooldown = false;
    msWglXCount = 0;
    msWglYCount = 0;
    msWglXAccum = 0;
    msWglYAccum = 0;
    return 0;
  }

  int8_t plodah_wigglecheck(report_mouse_t mouse_report) {
    if(msWglDebounce || msWglCooldown){
        return 0;
    }
    msWglXAccum += (10 * mouse_report.x);
    msWglYAccum += (10 * mouse_report.y);

    if( abs(msWglXAccum) > abs(msWglYAccum) && abs(msWglXAccum) > PLODAH_MSWIGGLE_THRESHOLD ){
        msWglSwitchDebounce = defer_exec(PLODAH_MSWIGGLE_DEBOUNCE, plodah_wiggle_expireDebounce, NULL);
        if( (abs(msWglXAccum) > PLODAH_MSWIGGLE_THRESHOLD && msWglXCount==0 ) || (msWglXAccum > PLODAH_MSWIGGLE_THRESHOLD && !msWglXDirection) || (msWglXAccum < -PLODAH_MSWIGGLE_THRESHOLD && msWglXDirection) ) {
            msWglXCount++;
            dprintf("==X==> C:%d,%d  acc:%d,%d (%d,%d) \n", msWglXCount, msWglYCount, msWglXAccum, msWglYAccum, abs(msWglXAccum), abs(msWglYAccum) );
            msWglXDirection = msWglXAccum > PLODAH_MSWIGGLE_THRESHOLD;
            msWglDebounce = true;
            cancel_deferred_exec(msWglShakeXTimeout);
            msWglShakeXTimeout = defer_exec( PLODAH_MSWIGGLE_TIMEOUT, plodah_wiggle_expireXTimeout, NULL );
        }
    }

    if( abs(msWglYAccum) > abs(msWglXAccum) && abs(msWglYAccum) > PLODAH_MSWIGGLE_THRESHOLD ){
        msWglSwitchDebounce = defer_exec(PLODAH_MSWIGGLE_DEBOUNCE, plodah_wiggle_expireDebounce, NULL);
        if( (abs(msWglYAccum) > PLODAH_MSWIGGLE_THRESHOLD && msWglYCount==0 ) || (msWglYAccum > PLODAH_MSWIGGLE_THRESHOLD && !msWglYDirection) || (msWglYAccum < -PLODAH_MSWIGGLE_THRESHOLD && msWglYDirection) ) {
            msWglYCount++;
            dprintf("==Y==> C:%d,%d  acc:%d,%d (%d,%d) \n", msWglXCount, msWglYCount, msWglXAccum, msWglYAccum, abs(msWglXAccum), abs(msWglYAccum) );
            msWglYDirection = msWglYAccum > PLODAH_MSWIGGLE_THRESHOLD;
            msWglDebounce = true;
            cancel_deferred_exec(msWglShakeYTimeout);
            msWglShakeYTimeout = defer_exec( PLODAH_MSWIGGLE_TIMEOUT, plodah_wiggle_expireYTimeout, NULL );
        }
    }

    if( msWglXCount >= PLODAH_MSWIGGLE_WIGGLES ) {
        msWglCooldown = true;
        msWglSwitchCooldown = defer_exec(PLODAH_MSWIGGLE_COOLDOWN, plodah_wiggle_expireCooldown, NULL);
        dprintf("Thats an X Jiggle\n");
        return 1;
    }

    if( msWglYCount >= PLODAH_MSWIGGLE_WIGGLES ) {
        msWglCooldown = true;
        msWglSwitchCooldown = defer_exec(PLODAH_MSWIGGLE_COOLDOWN, plodah_wiggle_expireCooldown, NULL);
        dprintf("Thats a Y Jiggle\n");
        return -1;
    }
    return 0;
  }
#endif
