#if defined(PLODAH_ALTTAB_ENHANCEMENTS_ENABLE) && !defined(DEFERRED_EXEC_ENABLE)
  #pragma once
  #pragma message("Non-Deferred Exec AltTab")
  bool is_alt_tab_active = false;
  uint16_t alt_tab_timer = 0;

  #ifndef PLODAH_ALT_TAB_DELAY
    #define PLODAH_ALT_TAB_DELAY 1000
  #endif //PLODAH_ALT_TAB_DELAY

  void plodah_alttab_start(bool back) {
    if (!is_alt_tab_active) {
      #if ! defined(IS_MOUSE)
        if (!alt_pressed){
      #endif // ! defined(IS_MOUSE)
          is_alt_tab_active = true;
          register_code(KC_LALT);
      #if ! defined(IS_MOUSE)
        }
      #endif // ! defined(IS_MOUSE)
    }
    alt_tab_timer = timer_read();
    if(back){
      tap_code16(S(KC_TAB));
    }
    else{
      tap_code16(KC_TAB);
    }
  }

  void plodah_alttab_check(void) {
    if (is_alt_tab_active) {
      if (timer_elapsed(alt_tab_timer) > PLODAH_ALT_TAB_DELAY) {
        unregister_code(KC_LALT);
        is_alt_tab_active = false;
      }
    }
  }
#endif // PLODAH_ALTTAB_ENHANCEMENTS_ENABLE
