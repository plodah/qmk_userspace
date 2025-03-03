#if defined(PLOOPY_DRAGSCROLL_SCRLK_ENABLE) || defined(PLOOPY_DRAGSCROLL_CAPLK_ENABLE)
  #pragma once
    bool led_update_user(led_t led_state) {
      dprintf("scr:%d", led_state.scroll_lock);
      plodah_dragscroll_enabled =
      #if defined(PLOOPY_DRAGSCROLL_SCRLK_ENABLE)
        led_state.scroll_lock
        #if defined(PLOOPY_DRAGSCROLL_CAPLK_ENABLE)
          ||
        #endif
      #endif // PLOOPY_DRAGSCROLL_SCRLK_ENABLE

      #if defined(PLOOPY_DRAGSCROLL_CAPLK_ENABLE)
        led_state.caps_lock
      #endif // PLOOPY_DRAGSCROLL_SCRLK_ENABLE
      ;
      return true;
    }
#endif //
