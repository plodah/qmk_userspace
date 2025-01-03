#if defined(PLODAH_TYPINGINDICATOR_RGBINDEX)
  #pragma once
  bool plodah_typingindicator_active = false;
  uint16_t plodah_typingindicator_timer = 0;

  #ifndef PLODAH_TYPINGINDICATOR_HSV
    #define PLODAH_TYPINGINDICATOR_HSV HSV_RED
  #endif //PLODAH_TYPINGINDICATOR_HSV

  #ifndef PLODAH_TYPINGINDICATOR_DURATION
    #define PLODAH_TYPINGINDICATOR_DURATION 1000
  #endif //PLODAH_TYPINGINDICATOR_DURATION

  void plodah_typingindicator_start(uint16_t keycode){
    if( keycode >= KC_A && keycode <= KC_SLASH ){
      plodah_typingindicator_timer = timer_read();
      plodah_typingindicator_active = true;
    }
  }

  void plodah_typingindicator_check(void){
    if(plodah_typingindicator_active){
      if(timer_elapsed(plodah_typingindicator_timer) > PLODAH_TYPINGINDICATOR_DURATION){
        plodah_typingindicator_active = false;
      }
    }
  }
#endif // PLODAH_TYPINGINDICATOR_RGBINDEX
