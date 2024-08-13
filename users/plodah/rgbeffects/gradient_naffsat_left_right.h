RGB_MATRIX_EFFECT(GRADIENT_SAT_LEFT_RIGHT)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
  bool GRADIENT_SAT_LEFT_RIGHT(effect_params_t* params){
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    HSV hsv = rgb_matrix_config.hsv;
    uint8_t scale = scale8(128, rgb_matrix_config.speed);
    for (uint8_t i = led_min; i < led_max; i++){
      RGB_MATRIX_TEST_LED_FLAGS();
      hsv.s   = rgb_matrix_config.hsv.s - (scale * g_led_config.point[i].x >> 5);
      RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
      rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
  }
#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
