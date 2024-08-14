bool is_autocorrect_indicator_active = false;
uint16_t autocorrect_indicator_timer = 0;

#ifndef PLODAH_AUTOCORRECT_INDICATOR_DURATION
# define PLODAH_AUTOCORRECT_INDICATOR_DURATION 600
#endif //PLODAH_AUTOCORRECT_INDICATOR_DURATION

#ifndef PLODAH_AUTOCORRECT_INDICATOR_COLOUR
# define PLODAH_AUTOCORRECT_INDICATOR_COLOUR HSV_RED
#endif //PLODAH_AUTOCORRECT_INDICATOR_COLOUR

void plodah_autocorrect_indicator_start(void) {
  if (!is_autocorrect_indicator_active) {
    is_autocorrect_indicator_active = true;
    HSV curhsv = rgb_matrix_get_hsv();
    HSV indhsv = { PLODAH_AUTOCORRECT_INDICATOR_COLOUR };
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(indhsv.h, indhsv.s, curhsv.v);
  }
  autocorrect_indicator_timer = timer_read();
}

void plodah_autocorrect_indicator_check(void) {
  if (is_autocorrect_indicator_active) {
    if (timer_elapsed(autocorrect_indicator_timer) > PLODAH_AUTOCORRECT_INDICATOR_DURATION) {
        rgb_matrix_reload_from_eeprom();
      is_autocorrect_indicator_active = false;
    }
  }
}
