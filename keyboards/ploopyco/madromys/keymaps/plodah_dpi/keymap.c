#include QMK_KEYBOARD_H
#include "via.h" // uses EEPROM address, lighting value IDs

enum layers {
    _BASE,
    _FNA,
    _FNB,
};

enum keymap_keycodes {
    // PL_DMAC1,
    // PL_DMAC2,
    PL_DRAG_SCROLL_MOMENTARY = QK_USER_0,
    PL_DRAG_SCROLL_TOGGLE,
    // PL_ECCC,
    // PL_ECCW,
    // PL_ECPR,
};

enum {
    TD_DRAGSCROLL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        P_MS4FA, P_MS5FB, KC_BTN3, KC_BTN2,
        KC_BTN1,                   P_DRGTD
    ),
    [_FNA] = LAYOUT(
        _______, CM_TSKP, CM_TSKN, P_XWIN,
        DPI_CONFIG,                P_DRGTG
    ),
    [_FNB] = LAYOUT(
        P_XTAB,  _______, P_PTAB,  P_NTAB,
        DPI_CONFIG,                P_DRGTG
    )
};

#if defined(PLODAH_VIADPI) && defined(VIA_ENABLE)

void pointingdpi_config_set_value( uint8_t *data );
void pointingdpi_config_get_value( uint8_t *data );
void pointingdpi_config_save ( void );
void values_load(void);
void values_save(void);

enum via_pointingdpi_value {
    id_pointingdpi_presets = 1,
    id_pointingdpi_activepreset,
    id_pointingdpi_multiplier,
};

typedef struct {
    uint8_t pointingdpi_presets[5];
    uint8_t pointingdpi_activepreset;
    uint8_t pointingdpi_multiplier;
} pointingdpi_settings_config;

pointingdpi_settings_config g_config = {
    .pointingdpi_presets = {20, 30, 40, 60, 80},
    .pointingdpi_activepreset = 2,
    .pointingdpi_multiplier = 20,
};

void values_load(void)
{
    eeprom_read_block( &g_config, ((void*)VIA_EEPROM_CUSTOM_CONFIG_ADDR), sizeof(g_config) );
}

void values_save(void)
{
    eeprom_update_block( &g_config, ((void*)VIA_EEPROM_CUSTOM_CONFIG_ADDR), sizeof(g_config) );
}

void update_dpi(void) {
    //dpi_array[]
    pointing_device_set_cpi(g_config.pointingdpi_presets[g_config.pointingdpi_activepreset] * g_config.pointingdpi_multiplier * 0.5);
}

void via_init_kb(void)
{
    // If the EEPROM has the magic, the data is good.
    // OK to load from EEPROM
    if (via_eeprom_is_valid()) {
        values_load();
        update_dpi();
    } else	{
        values_save();
        // DO NOT set EEPROM valid here, let caller do this
    }
}

void via_custom_value_command_kb(uint8_t *data, uint8_t length) {
    // data = [ command_id, channel_id, value_id, value_data ]
    uint8_t *command_id        = &(data[0]);
    uint8_t *channel_id        = &(data[1]);
    uint8_t *value_id_and_data = &(data[2]);

    if ( *channel_id == id_custom_channel ) {
        switch ( *command_id )
        {
            case id_custom_set_value:
            {
                pointingdpi_config_set_value(value_id_and_data);
                break;
            }
            case id_custom_get_value:
            {
                pointingdpi_config_get_value(value_id_and_data);
                break;
            }
            case id_custom_save:
            {
                values_save();
                break;
            }
            default:
            {
                // Unhandled message.
                *command_id = id_unhandled;
                break;
            }
        }
        return;
    }

    // Return the unhandled state
    *command_id = id_unhandled;

    // DO NOT call raw_hid_send(data,length) here, let caller do this
}

void pointingdpi_config_set_value( uint8_t *data )
{
    // data = [ value_id, value_data ]
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);

    switch ( *value_id )
    {
        case id_pointingdpi_presets:
            g_config.pointingdpi_presets[value_data[0]] = value_data[1];
            dprintf("pointingdpi_presets[%d]: %d\n", value_data[0], value_data[1]);
            update_dpi();
            break;
        case id_pointingdpi_activepreset:
            g_config.pointingdpi_activepreset = *value_data;
            dprintf("pointingdpi_multiplier: %d\n", g_config.pointingdpi_multiplier);
            update_dpi();
            break;
        case id_pointingdpi_multiplier:
            g_config.pointingdpi_multiplier = *value_data;
            dprintf("pointingdpi_multiplier: %d\n", g_config.pointingdpi_multiplier);
            update_dpi();
            break;
    }
}

void pointingdpi_config_get_value( uint8_t *data )
{
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);

    switch ( *value_id )
    {
        case id_pointingdpi_presets:
            //*value_data = g_config.pointingdpi_presets;
            value_data[1] = g_config.pointingdpi_presets[value_data[0]];
            break;
        case id_pointingdpi_activepreset:
            *value_data = g_config.pointingdpi_activepreset;
            break;
        case id_pointingdpi_multiplier:
            *value_data = g_config.pointingdpi_multiplier;
            break;
    }
}

#endif // defined(PLODAH_VIADPI) && defined(VIA_ENABLE)
