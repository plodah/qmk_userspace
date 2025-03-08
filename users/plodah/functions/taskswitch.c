#if defined(PLODAH_TASKSWITCH_ENABLE)
  #pragma once

  #ifndef PLODAH_TASKSWITCH_DELAY
    #define PLODAH_TASKSWITCH_DELAY 1000
  #endif //PLODAH_TASKSWITCH_DELAY

  // #define PLODAH_TASKSWITCH_FORCE_NDE
  #if defined(DEFERRED_EXEC_ENABLE) && (!defined(PLODAH_TASKSWITCH_FORCE_NDE))
    #define PLODAH_TASKSWITCH_MODE_DE
  #endif // DEFERRED_EXEC_ENABLE

  #if defined(PLODAH_TASKSWITCH_MODE_DE)
    // #pragma message("Deferred Exec TaskSwitch")
    static deferred_token taskSwitchToken = INVALID_DEFERRED_TOKEN;
  #else // PLODAH_TASKSWITCH_MODE_DE
    // #pragma message("Non-Deferred Exec TaskSwitch")
    bool is_pl_taskswitch_active = false;
    uint16_t pl_taskswitch_timer = 0;
  #endif // PLODAH_TASKSWITCH_MODE_DE


  #if defined(PLODAH_TASKSWITCH_MODE_DE)
    uint32_t plodah_taskswitch_reset(uint32_t trigger_time, void *cb_arg) {
        unregister_code(KC_LALT);
        taskSwitchToken = INVALID_DEFERRED_TOKEN;
        // cancel_deferred_exec(taskSwitchToken);
        return 0;
    }
  #else // PLODAH_TASKSWITCH_MODE_DE
    void plodah_taskswitch_check(void) {
      if (is_pl_taskswitch_active) {
        if (timer_elapsed(pl_taskswitch_timer) > PLODAH_TASKSWITCH_DELAY) {
          unregister_code(KC_LALT);
          is_pl_taskswitch_active = false;
        }
      }
    }
  #endif // PLODAH_TASKSWITCH_MODE_DE

  void plodah_taskswitch_start(bool back) {
    #if defined(PLODAH_TASKSWITCH_MODE_DE)
      if (taskSwitchToken != INVALID_DEFERRED_TOKEN) {
        extend_deferred_exec(taskSwitchToken, PLODAH_TASKSWITCH_DELAY);
        //taskSwitchToken = defer_exec(PLODAH_TASKSWITCH_DELAY, plodah_taskswitch_reset, NULL);
      }
      else{
    #else
      pl_taskswitch_timer = timer_read();
      if (!is_pl_taskswitch_active) {
    #endif // PLODAH_TASKSWITCH_MODE_DE
        #if ! defined(IS_MOUSE)
          if (!(get_mods() & MOD_MASK_ALT)){
            dprintf("Not a mouse, no alt");
        #endif // ! defined(IS_MOUSE)
        #if defined(PLODAH_TASKSWITCH_MODE_DE)
          taskSwitchToken = defer_exec(PLODAH_TASKSWITCH_DELAY, plodah_taskswitch_reset, NULL);
        #else // PLODAH_TASKSWITCH_MODE_DE
          is_pl_taskswitch_active = true;
        #endif // PLODAH_TASKSWITCH_MODE_DE
          register_code(KC_LALT);
        #if ! defined(IS_MOUSE)
          }
        #endif // ! defined(IS_MOUSE)
      }
      if(back){
        tap_code16(S(KC_TAB));
      }
      else{
        tap_code16(KC_TAB);
      }
    }
#endif // defined(PLODAH_TASKSWITCH_ENABLE) && defined(DEFERRED_EXEC_ENABLE)
