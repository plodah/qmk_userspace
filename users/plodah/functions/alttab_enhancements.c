bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

#ifndef PLODAH_ALT_TAB_DELAY
# define PLODAH_ALT_TAB_DELAY 1000
#endif //PLODAH_ALT_TAB_DELAY

void alt_tab_fw(void) {
  if (!is_alt_tab_active) {
    is_alt_tab_active = true;
    register_code(KC_LALT);
  }
  alt_tab_timer = timer_read();
  tap_code16(KC_TAB);
}
void alt_tab_bk(void) {
  if (!is_alt_tab_active) {
    is_alt_tab_active = true;
    register_code(KC_LALT);
  }
  alt_tab_timer = timer_read();
  tap_code16(S(KC_TAB));
}
void plodah_alttab_check(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > PLODAH_ALT_TAB_DELAY) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}
