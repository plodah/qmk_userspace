#if defined(AUTOCORRECT_ENABLE)
  #pragma once
  #if defined(RGB_MATRIX_ENABLE)

    bool autocorrect_indicator_on = false;
    uint8_t autocorrect_indicator_count = 255;
    uint16_t autocorrect_indicator_timer = 0;
    HSV indhsv;

    #ifndef PLODAH_AUTOCORRECT_INDICATOR_DURATION
      #define PLODAH_AUTOCORRECT_INDICATOR_DURATION 200
    #endif //PLODAH_AUTOCORRECT_INDICATOR_DURATION

    #ifndef PLODAH_AUTOCORRECT_INDICATOR_BLINKCOUNT
      #define PLODAH_AUTOCORRECT_INDICATOR_BLINKCOUNT 3
    #endif // PLODAH_AUTOCORRECT_INDICATOR_BLINKCOUNT

    #ifndef PLODAH_AUTOCORRECT_INDICATOR_COLOUR
      #define PLODAH_AUTOCORRECT_INDICATOR_COLOUR HSV_RED
    #endif //PLODAH_AUTOCORRECT_INDICATOR_COLOUR

    #ifndef PLODAH_INDICATOR_MINVAL
      #define PLODAH_INDICATOR_MINVAL 85
    #endif // PLODAH_INDICATOR_MINVAL

    void plodah_autocorrect_indicator_on(void){
      autocorrect_indicator_on = true;
      rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
      HSV indhsv = { PLODAH_AUTOCORRECT_INDICATOR_COLOUR };
      indhsv = plodah_rgblimit(rgb_matrix_get_hsv(), indhsv, PLODAH_INDICATOR_MINVAL);
      rgb_matrix_sethsv_noeeprom(indhsv.h, indhsv.s, indhsv.v);
      autocorrect_indicator_timer = timer_read();
    }

    void plodah_autocorrect_indicator_off(void){
      autocorrect_indicator_count ++;
      autocorrect_indicator_on = false;
      rgb_matrix_reload_from_eeprom();
      autocorrect_indicator_timer = timer_read();
    }

    void plodah_autocorrect_indicator_start(void){
      autocorrect_indicator_count = 0;
    }

    void plodah_autocorrect_indicator_check(void){
      if (autocorrect_indicator_count < PLODAH_AUTOCORRECT_INDICATOR_BLINKCOUNT){
        if (timer_elapsed(autocorrect_indicator_timer) > PLODAH_AUTOCORRECT_INDICATOR_DURATION){
          if (autocorrect_indicator_on){
            plodah_autocorrect_indicator_off();
          }
          else{
            plodah_autocorrect_indicator_on();
          }
        }
      }
    }
  #endif // RGB_MATRIX_ENABLE

  bool process_autocorrect_user(uint16_t *keycode, keyrecord_t *record, uint8_t *typo_buffer_size, uint8_t *mods) {
    #if defined(PLODAH_BORING_LAYER)
      if( get_highest_layer(layer_state) == PLODAH_BORING_LAYER){
        return false;
      }
    #endif // defined(PLODAH_BORING_LAYER)
    if ((*mods & ~MOD_MASK_SHIFT) != 0) {
      *typo_buffer_size = 0;
      return false;
    }
    switch (*keycode) {
      case QK_MOD_TAP ... QK_MOD_TAP_MAX:
      case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        if (!record->tap.count) {
          return false;
        }
        *keycode &= 0xFF;
        break;
    }
    return true;
  }

  bool apply_autocorrect(uint8_t backspaces, const char *str, char *typo, char *correct) {
    #if defined(RGB_MATRIX_ENABLE)
      plodah_autocorrect_indicator_start();
    #endif // RGB_MATRIX_ENABLE
    return true;
  }
#endif // AUTOCORRECT_ENABLE
