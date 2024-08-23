bool rgb_vad_pressed = false;
bool rgb_vai_pressed = false;
bool rgb_hud_pressed = false;
bool rgb_hui_pressed = false;
bool rgb_sad_pressed = false;
bool rgb_sai_pressed = false;
bool rgb_spd_pressed = false;
bool rgb_spi_pressed = false;
uint16_t repeathold_rgb_timer;

void repeathold_rgb_check(void){
    if(timer_elapsed(repeathold_rgb_timer) > PLODAH_REPEATHOLD_RATE){
        if(rgb_vai_pressed){
            rgb_matrix_increase_val();
        }
        if(rgb_vad_pressed){
            rgb_matrix_decrease_val();
        }
        if(rgb_sai_pressed){
            rgb_matrix_increase_sat();
        }
        if(rgb_sad_pressed){
            rgb_matrix_decrease_sat();
        }
        if(rgb_hui_pressed){
            rgb_matrix_increase_hue();
        }
        if(rgb_hud_pressed){
            rgb_matrix_decrease_hue();
        }
        if(rgb_spi_pressed){
            rgb_matrix_increase_speed();
        }
        if(rgb_spd_pressed){
            rgb_matrix_decrease_speed();
        }
        repeathold_rgb_timer = timer_read();
    }
}
