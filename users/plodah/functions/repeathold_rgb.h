#if defined(PLODAH_REPEATHOLD_RGB) && (defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE))
    #pragma once
    #include <stdbool.h>
    #include <stdint.h>
    #include <stdbool.h>
    #include <stdint.h>
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

    bool process_record_repeathold_rgb(uint16_t keycode, keyrecord_t *record);
    void housekeeping_task_repeathold_rgb(void);

#endif // #if defined(PLODAH_REPEATHOLD_RGB) && (defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE))
