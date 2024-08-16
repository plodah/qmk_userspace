bool autocorrect_indicator_on = false;
uint8_t autocorrect_indicator_count = 255;
uint16_t autocorrect_indicator_timer = 0;
HSV curhsv;
HSV indhsv;
uint8_t useval;


#ifndef PLODAH_AUTOCORRECT_INDICATOR_DURATION
# define PLODAH_AUTOCORRECT_INDICATOR_DURATION 200
#endif //PLODAH_AUTOCORRECT_INDICATOR_DURATION

#ifndef PLODAH_AUTOCORRECT_INDICATOR_BLINKCOUNT
# define PLODAH_AUTOCORRECT_INDICATOR_BLINKCOUNT 3
#endif // PLODAH_AUTOCORRECT_INDICATOR_BLINKCOUNT

#ifndef PLODAH_AUTOCORRECT_INDICATOR_COLOUR
# define PLODAH_AUTOCORRECT_INDICATOR_COLOUR HSV_RED
#endif //PLODAH_AUTOCORRECT_INDICATOR_COLOUR

#ifndef PLODAH_AUTOCORRECT_INDICATOR_MINVAL
# define PLODAH_AUTOCORRECT_INDICATOR_MINVAL 85
#endif // PLODAH_AUTOCORRECT_INDICATOR_MINVAL

void plodah_autocorrect_indicator_on(void){
  HSV indhsv = { PLODAH_AUTOCORRECT_INDICATOR_COLOUR };
  if(PLODAH_AUTOCORRECT_INDICATOR_MINVAL > curhsv.v){
    useval = PLODAH_AUTOCORRECT_INDICATOR_MINVAL;
  }
  else{
    useval = curhsv.v;
  }
  autocorrect_indicator_on = true;
  rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
  rgb_matrix_sethsv_noeeprom(indhsv.s, indhsv.s, useval);
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
  if (autocorrect_indicator_count == 0){
    curhsv = rgb_matrix_get_hsv();
  }
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
