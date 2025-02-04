#if defined(PLODAH_REPEATHOLD_RGB) && (defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE))
  #pragma once
  #include <stdbool.h>

  uint16_t repeathold_rgb_timer;

  #if defined(RGB_MATRIX_ENABLE)
    int8_t rm_va_state = -1;
    int8_t rm_hu_state = -1;
    int8_t rm_sa_state = -1;
    int8_t rm_sp_state = -1;
  #endif // defined(RGB_MATRIX_ENABLE)

  #if defined(RGBLIGHT_ENABLE)
    int8_t ug_va_state = -1;
    int8_t ug_hu_state = -1;
    int8_t ug_sa_state = -1;
    int8_t ug_sp_state = -1;
  #endif // defined(RGBLIGHT_ENABLE)

  void repeathold_rgb_start(int8_t keycode, bool pressed) {
    switch(keycode){
      #if defined(RGB_MATRIX_ENABLE)
        case RM_HUEU & 0xff:
        case RM_HUED & 0xff:
          if(pressed){rm_hu_state = keycode & 0x1;}
          else{rm_hu_state = -1;}
          break;

        case RM_SATU & 0xff:
        case RM_SATD & 0xff:
          if(pressed){rm_sa_state = keycode & 0x1;}
          else{rm_sa_state = -1;}
          break;

        case RM_VALU & 0xff:
        case RM_VALD & 0xff:
          if(pressed){rm_va_state = keycode & 0x1;}
          else{rm_va_state = -1;}
          break;

        case RM_SPDU & 0xff:
        case RM_SPDD & 0xff:
          if(pressed){rm_sp_state = keycode & 0x1;}
          else{rm_sp_state = -1;}
          break;
      #endif // RGB_MATRIX_ENABLE

      #if defined(RGBLIGHT_ENABLE)
        case UG_HUEU & 0xff:
        case UG_HUED & 0xff:
          if(pressed){ug_hu_state = keycode & 0x1;}
          else{ug_hu_state = -1;}
          break;

        case UG_SATU & 0xff:
        case UG_SATD & 0xff:
          if(pressed){ug_sa_state = keycode & 0x1;}
          else{ug_sa_state = -1;}
          break;

        case UG_VALU & 0xff:
        case UG_VALD & 0xff:
          if(pressed){ug_va_state = keycode & 0x1;}
          else{ug_va_state = -1;}
          break;

        case UG_SPDU & 0xff:
        case UG_SPDD & 0xff:
          if(pressed){ug_sp_state = keycode & 0x1;}
          else{ug_sp_state = -1;}
          break;
      #endif // defined(RGBLIGHT_ENABLE)

    }
    repeathold_rgb_timer = timer_read();
  }

  void repeathold_rgb_check(void){
    if(timer_elapsed(repeathold_rgb_timer) > PLODAH_REPEATHOLD_RATE){
      #if defined(RGB_MATRIX_ENABLE)
        if(rm_va_state == 1){
          rgb_matrix_increase_val();
        }
        if(rm_va_state == 0){
          rgb_matrix_decrease_val();
        }
        if(rm_sa_state == 1){
          rgb_matrix_increase_sat();
        }
        if(rm_sa_state == 0){
          rgb_matrix_decrease_sat();
        }
        if(rm_hu_state == 1){
          rgb_matrix_increase_hue();
        }
        if(rm_hu_state == 0){
          rgb_matrix_decrease_hue();
        }
        if(rm_sp_state == 1){
          rgb_matrix_increase_speed();
        }
        if(rm_sp_state == 0){
          rgb_matrix_decrease_speed();
        }
      #endif // defined(RGB_MATRIX_ENABLE)

      #if defined(RGBLIGHT_ENABLE)
        if(ug_va_state == 1){
          rgblight_increase_val();
        }
        if(ug_va_state == 0){
          rgblight_decrease_val();
        }
        if(ug_sa_state == 1){
          rgblight_increase_sat();
        }
        if(ug_sa_state == 0){
          rgblight_decrease_sat();
        }
        if(ug_hu_state == 1){
          rgblight_increase_hue();
        }
        if(ug_hu_state == 0){
          rgblight_decrease_hue();
        }
        if(ug_sp_state == 1){
          rgblight_increase_speed();
        }
        if(ug_sp_state == 0){
          rgblight_decrease_speed();
        }
      #endif // defined(RGBLIGHT_ENABLE)

      repeathold_rgb_timer = timer_read();
    }
  }
#endif // defined(PLODAH_REPEATHOLD_RGB) && defined(RGB_MATRIX_ENABLE)
