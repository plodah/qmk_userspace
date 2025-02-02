#if defined(PLODAH_REPEATHOLD_RGB) && defined(RGB_MATRIX_ENABLE)
  #pragma once
  #include <stdbool.h>
  int8_t rgb_va_state = -1;
  int8_t rgb_hu_state = -1;
  int8_t rgb_sa_state = -1;
  int8_t rgb_sp_state = -1;
  uint16_t repeathold_rgb_timer;

  void repeathold_rgb_start(int8_t keycode, bool pressed) {
    switch(keycode){
      case RM_HUEU & 0xff:
      case RM_HUED & 0xff:
        if(pressed){rgb_hu_state = keycode & 0x1;}
        else{rgb_hu_state = -1;}
        break;

      case RM_SATU & 0xff:
      case RM_SATD & 0xff:
        if(pressed){rgb_sa_state = keycode & 0x1;}
        else{rgb_sa_state = -1;}
        break;

      case RM_VALU & 0xff:
      case RM_VALD & 0xff:
        if(pressed){rgb_va_state = keycode & 0x1;}
        else{rgb_va_state = -1;}
        break;

      case RM_SPDU & 0xff:
      case RM_SPDD & 0xff:
        if(pressed){rgb_sp_state = keycode & 0x1;}
        else{rgb_sp_state = -1;}
        break;

    }
    repeathold_rgb_timer = timer_read();
  }

  void repeathold_rgb_check(void){
    if(timer_elapsed(repeathold_rgb_timer) > PLODAH_REPEATHOLD_RATE){
      if(rgb_va_state == 1){
        rgb_matrix_increase_val();
      }
      if(rgb_va_state == 0){
        rgb_matrix_decrease_val();
      }
      if(rgb_sa_state == 1){
        rgb_matrix_increase_sat();
      }
      if(rgb_sa_state == 0){
        rgb_matrix_decrease_sat();
      }
      if(rgb_hu_state == 1){
        rgb_matrix_increase_hue();
      }
      if(rgb_hu_state == 0){
        rgb_matrix_decrease_hue();
      }
      if(rgb_sp_state == 1){
        rgb_matrix_increase_speed();
      }
      if(rgb_sp_state == 0){
        rgb_matrix_decrease_speed();
      }
      repeathold_rgb_timer = timer_read();
    }
  }
#endif // defined(PLODAH_REPEATHOLD_RGB) && defined(RGB_MATRIX_ENABLE)
