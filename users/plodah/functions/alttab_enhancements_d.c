static deferred_token altTabToken = INVALID_DEFERRED_TOKEN;

#ifndef PLODAH_ALT_TAB_DELAY
  #define PLODAH_ALT_TAB_DELAY 1000
#endif //PLODAH_ALT_TAB_DELAY

uint32_t plodah_alttab_reset(uint32_t trigger_time, void *cb_arg) {
    unregister_code(KC_LALT);
    altTabToken = INVALID_DEFERRED_TOKEN;
    // cancel_deferred_exec(altTabToken);
    return 0;
}

void plodah_alttab_start(bool back) {
  if (altTabToken != INVALID_DEFERRED_TOKEN) {
    extend_deferred_exec(altTabToken, PLODAH_ALT_TAB_DELAY);
    //altTabToken = defer_exec(PLODAH_ALT_TAB_DELAY, plodah_alttab_reset, NULL);
  }
  else{
    #if ! defined(IS_MOUSE)
      if (!alt_pressed){
    #endif // ! defined(IS_MOUSE)
      altTabToken = defer_exec(PLODAH_ALT_TAB_DELAY, plodah_alttab_reset, NULL);
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
