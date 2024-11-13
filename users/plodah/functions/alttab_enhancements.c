#if defined(PLODAH_ALTTAB_ENHANCEMENTS_ENABLE)
  #pragma once

  #ifndef PLODAH_ALT_TAB_DELAY
    #define PLODAH_ALT_TAB_DELAY 1000
  #endif //PLODAH_ALT_TAB_DELAY

  // #define PLODAH_ALTTAB_ENHANCEMENTS_FORCE_NDE
  #if defined(DEFERRED_EXEC_ENABLE) && (!defined(PLODAH_ALTTAB_ENHANCEMENTS_FORCE_NDE))
    #define PLODAH_ALTTAB_ENHANCEMENTS_MODE_DE
  #endif // DEFERRED_EXEC_ENABLE

  #if defined(PLODAH_ALTTAB_ENHANCEMENTS_MODE_DE)
    // #pragma message("Deferred Exec AltTab")
    static deferred_token altTabToken = INVALID_DEFERRED_TOKEN;
  #else // PLODAH_ALTTAB_ENHANCEMENTS_MODE_DE
    // #pragma message("Non-Deferred Exec AltTab")
    bool is_alt_tab_active = false;
    uint16_t alt_tab_timer = 0;
  #endif // PLODAH_ALTTAB_ENHANCEMENTS_MODE_DE


  #if defined(PLODAH_ALTTAB_ENHANCEMENTS_MODE_DE)
    uint32_t plodah_alttab_reset(uint32_t trigger_time, void *cb_arg) {
        unregister_code(KC_LALT);
        altTabToken = INVALID_DEFERRED_TOKEN;
        // cancel_deferred_exec(altTabToken);
        return 0;
    }
  #else // PLODAH_ALTTAB_ENHANCEMENTS_MODE_DE
    void plodah_alttab_check(void) {
      if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > PLODAH_ALT_TAB_DELAY) {
          unregister_code(KC_LALT);
          is_alt_tab_active = false;
        }
      }
    }
  #endif // PLODAH_ALTTAB_ENHANCEMENTS_MODE_DE

    void plodah_alttab_start(bool back) {

    #if defined(PLODAH_ALTTAB_ENHANCEMENTS_MODE_DE)
      if (altTabToken != INVALID_DEFERRED_TOKEN) {
        extend_deferred_exec(altTabToken, PLODAH_ALT_TAB_DELAY);
        //altTabToken = defer_exec(PLODAH_ALT_TAB_DELAY, plodah_alttab_reset, NULL);
      }
      else{
    #else
      if (!is_alt_tab_active) {
    #endif // PLODAH_ALTTAB_ENHANCEMENTS_MODE_DE
        #if ! defined(IS_MOUSE)
          if (!alt_pressed){
        #endif // ! defined(IS_MOUSE)
        #if defined(PLODAH_ALTTAB_ENHANCEMENTS_MODE_DE)
          altTabToken = defer_exec(PLODAH_ALT_TAB_DELAY, plodah_alttab_reset, NULL);
        #else // PLODAH_ALTTAB_ENHANCEMENTS_MODE_DE
          is_alt_tab_active = true;
        #endif // PLODAH_ALTTAB_ENHANCEMENTS_MODE_DE
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
#endif // defined(PLODAH_ALTTAB_ENHANCEMENTS_ENABLE) && defined(DEFERRED_EXEC_ENABLE)
