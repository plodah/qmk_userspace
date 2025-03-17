#pragma once
void pointing_dpi_config_set_value( uint8_t *data );
void pointing_dpi_config_get_value( uint8_t *data );
void pointing_dpi_config_save ( void );
void values_load(void);
void values_save(void);

enum via_pointing_dpi_value {
    id_pointing_dpi_presets = 1,
    id_pointing_dpi_activepreset,
    id_pointing_dpi_multiplier,
    id_pointing_msjiggler_enabled,
    id_pointing_wiggleball_count,
    id_pointing_wiggleball_action_h,
    id_pointing_wiggleball_action_v,
    id_pointing_dragscroll_invert_h,
    id_pointing_dragscroll_invert_v,
    id_pointing_dragscroll_caps,
    id_pointing_dragscroll_num,
    id_pointing_dragscroll_scroll,
};

typedef struct {
    uint8_t pointing_dpi_multiplier;
    uint8_t pointing_wiggleball_count;
    uint8_t pointing_wiggleball_action_h;
    uint8_t pointing_wiggleball_action_v;
    bool pointing_dragscroll_invert_h;
    bool pointing_dragscroll_invert_v;
    bool pointing_dragscroll_caps;
    bool pointing_dragscroll_num;
    bool pointing_dragscroll_scroll;
} pointing_dpi_settings_config;

pointing_dpi_settings_config ploopyvia_config;
