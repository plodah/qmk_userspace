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

  bool process_record_typing_indicator(uint16_t keycode, keyrecord_t *record){
    // Some madness to include layer taps / mod taps
    // QK_MOD_TAP        = 0x2000,
    // QK_MOD_TAP_MAX    = 0x3FFF,
    // QK_LAYER_TAP      = 0x4000,
    // QK_LAYER_TAP_MAX  = 0x4FFF,
    if(
        record->event.pressed && (keycode & 0x00FF) >= KC_A && (keycode & 0x00FF) <= KC_SLASH &&
        ( IS_QK_BASIC(keycode) || IS_QK_MOD_TAP(keycode) || IS_QK_LAYER_TAP(keycode) )
    ) {
      plodah_typingindicator_timer = timer_read();
      plodah_typingindicator_active = true;
    }
    return true;
  }

  void housekeeping_task_typing_indicator(void){
    if(plodah_typingindicator_active){
      if(timer_elapsed(plodah_typingindicator_timer) > PLODAH_TYPINGINDICATOR_DURATION){
        plodah_typingindicator_active = false;
      }
    }
  }
#endif // PLODAH_TYPINGINDICATOR_RGBINDEX
