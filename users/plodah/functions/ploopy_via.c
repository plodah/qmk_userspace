#if defined(VIA_ENABLE) && defined(PLODAH_VIADPI)
    #pragma once

    // #include QMK_KEYBOARD_H
    #include "via.h" // uses EEPROM address, lighting value IDs
    #include "mouse_jiggler.h"
    #include "ploopy_via.h"

    pointing_dpi_settings_config ploopyvia_config = {
        .pointing_dpi_multiplier            = 20,
        .pointing_wiggleball_count          = 4,
        .pointing_wiggleball_action_h       = 0,
        .pointing_wiggleball_action_v       = 0,
        .pointing_dragscroll_invert_h       = false,
        .pointing_dragscroll_invert_v       = false,
        .pointing_dragscroll_caps           = false,
        .pointing_dragscroll_num            = false,
        .pointing_dragscroll_scroll         = false,
    };

    void values_load(void)
    {
        eeprom_read_block( &ploopyvia_config, ((void*)VIA_EEPROM_CUSTOM_CONFIG_ADDR), sizeof(ploopyvia_config) );
    }

    void values_save(void)
    {
        eeprom_update_block( &ploopyvia_config, ((void*)VIA_EEPROM_CUSTOM_CONFIG_ADDR), sizeof(ploopyvia_config) );
    }

    void update_dpi(void) {
        pointing_device_set_cpi(dpi_array[keyboard_config.dpi_config]);
        dprintf("Set CPI %d\n", dpi_array[keyboard_config.dpi_config]);
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
                    pointing_dpi_config_set_value(value_id_and_data);
                    break;
                }
                case id_custom_get_value:
                {
                    pointing_dpi_config_get_value(value_id_and_data);
                    break;
                }
                case id_custom_save:
                {
                    values_save();
                    break;
                }
                default:
                {
                    *command_id = id_unhandled;
                    break;
                }
            }
            return;
        }

        *command_id = id_unhandled;
    }

    void pointing_dpi_config_set_value( uint8_t *data )
    {
        uint8_t *value_id   = &(data[0]);
        uint8_t *value_data = &(data[1]);

        switch ( *value_id )
        {
            case id_pointing_dpi_presets:
                dpi_array[value_data[0]] = (value_data[1]*10) * (ploopyvia_config.pointing_dpi_multiplier/20) ;
                dprintf("pointing_dpi_presets[%d]: %d\n", value_data[0], value_data[1]);
                update_dpi();
                break;

            case id_pointing_dpi_activepreset:
                keyboard_config.dpi_config = *value_data;
                dprintf("pointing_dpi_preset: %d\n", keyboard_config.dpi_config);
                update_dpi();
                break;

            case id_pointing_dpi_multiplier:
                for (int i = 0; i <  5; ++i) {
                    dpi_array[i] = dpi_array[i] / ploopyvia_config.pointing_dpi_multiplier * *value_data;
                }
                ploopyvia_config.pointing_dpi_multiplier = *value_data;
                dprintf("pointing_dpi_multiplier: %d\n", ploopyvia_config.pointing_dpi_multiplier);
                update_dpi();
                break;

            case id_pointing_msjiggler_enabled:
                if( (msJigMainToken != INVALID_DEFERRED_TOKEN) ^ (*value_data) ) {
                    // ^ is an XOR, buddy
                    jiggler_toggle();
                }
                break;

            case id_pointing_wiggleball_count:
                ploopyvia_config.pointing_wiggleball_count = *value_data;
                break;

            case id_pointing_wiggleball_action_h:
                ploopyvia_config.pointing_wiggleball_action_h = *value_data;
                break;

            case id_pointing_wiggleball_action_v:
                ploopyvia_config.pointing_wiggleball_action_v = *value_data;
                break;

            case id_pointing_dragscroll_invert_h:
                ploopyvia_config.pointing_dragscroll_invert_h = *value_data;
                break;

            case id_pointing_dragscroll_invert_v:
                ploopyvia_config.pointing_dragscroll_invert_v = *value_data;
                break;

            case id_pointing_dragscroll_caps:
                ploopyvia_config.pointing_dragscroll_caps = *value_data;
                dprintf("pointing_dragscroll_caps: %d\n", ploopyvia_config.pointing_dragscroll_caps);
                break;

            case id_pointing_dragscroll_num:
                ploopyvia_config.pointing_dragscroll_num = *value_data;
                dprintf("pointing_dragscroll_num: %d\n", ploopyvia_config.pointing_dragscroll_num);
                break;

            case id_pointing_dragscroll_scroll:
                ploopyvia_config.pointing_dragscroll_scroll = *value_data;
                dprintf("pointing_dragscroll_scroll: %d\n", ploopyvia_config.pointing_dragscroll_scroll);
                break;

        }
    }

    void pointing_dpi_config_get_value( uint8_t *data )
    {
        uint8_t *value_id   = &(data[0]);
        uint8_t *value_data = &(data[1]);

        switch ( *value_id )
        {
            case id_pointing_dpi_presets:
                value_data[1] = (dpi_array[value_data[0]] / 10) / (ploopyvia_config.pointing_dpi_multiplier/20)  ;
                break;

            case id_pointing_dpi_activepreset:
                *value_data = keyboard_config.dpi_config;
                break;
            case id_pointing_dpi_multiplier:
                *value_data = ploopyvia_config.pointing_dpi_multiplier;
                break;

            case id_pointing_msjiggler_enabled:
                *value_data = msJigMainToken != INVALID_DEFERRED_TOKEN;
                break;

            case id_pointing_wiggleball_count:
                *value_data = ploopyvia_config.pointing_wiggleball_count;
                break;

            case id_pointing_wiggleball_action_h:
                *value_data = ploopyvia_config.pointing_wiggleball_action_h;
                break;

            case id_pointing_wiggleball_action_v:
                *value_data = ploopyvia_config.pointing_wiggleball_action_v;
                break;

            case id_pointing_dragscroll_invert_h:
                *value_data = ploopyvia_config.pointing_dragscroll_invert_h;
                break;

            case id_pointing_dragscroll_invert_v:
                *value_data = ploopyvia_config.pointing_dragscroll_invert_v;
                break;

            case id_pointing_dragscroll_caps:
                *value_data = ploopyvia_config.pointing_dragscroll_caps;
                break;

            case id_pointing_dragscroll_num:
                *value_data = ploopyvia_config.pointing_dragscroll_num;
                break;

            case id_pointing_dragscroll_scroll:
                *value_data = ploopyvia_config.pointing_dragscroll_scroll;
                break;
        }
    }

#endif // if defined(VIA_ENABLE) && defined(PLODAH_VIADPI)
