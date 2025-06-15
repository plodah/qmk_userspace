#if defined(VIA_ENABLE) && defined(PLOOPY_VIAMENUS)
    #pragma once

    // #include QMK_KEYBOARD_H
    #include "better_dragscroll.h"
    #include "via.h"
    #include "mouse_jiggler.h"
    #include "ploopy_via.h"
    #include "mouse_gesture.h"
    void ploopyvia_config_load(void) {
        // ploopyvia_config.raw = eeconfig_read_user();
        eeconfig_read_user_datablock(&ploopyvia_config, 0, EECONFIG_USER_DATA_SIZE);
    }

    void ploopyvia_config_save(void) {
        // eeconfig_update_user(ploopyvia_config.raw);
        eeconfig_update_user_datablock(&ploopyvia_config, 0, EECONFIG_USER_DATA_SIZE);
    }

    void update_dpi(void) {

        for (int i=0; i<5; i++){
            dpi_array[i] = ploopyvia_config.dpi_presets[i];
        }
        pointing_device_set_cpi(dpi_array[keyboard_config.dpi_config]);
        dprintf("Set CPI %d\n", dpi_array[keyboard_config.dpi_config]);
        eeconfig_update_kb(keyboard_config.raw);
    }

    void keyboard_post_init_user_viamenus(void) {
        ploopyvia_config_load();
        if(ploopyvia_config.dpi_multiplier == 0){
            eeconfig_init_user();
        }
        update_dpi();
        plodah_msGestureUpdate();
        led_update_better_dragscroll(host_keyboard_led_state());
        dprintf("keyboard_post_init_user\n");
    }

    void eeconfig_init_user(void) {
        ploopyvia_config = ploopyvia_config_default;
        ploopyvia_config_save();
        dprintf("eeconfig_init_user\n");
    }

    void ploopyvia_config_set_value( uint8_t *data )
    {
        uint8_t *value_id   = &(data[0]);
        uint8_t *value_data = &(data[1]);

        switch ( *value_id )
        {
            case id_ploopystuff_dpi_activepreset:
                keyboard_config.dpi_config = *value_data;
                dprintf("dpi_preset: %d\n", keyboard_config.dpi_config);
                update_dpi();
                break;

            case id_ploopystuff_dpi_multiplier:
                for (int i = 0; i <  5; ++i) {
                    ploopyvia_config.dpi_presets[i] = ploopyvia_config.dpi_presets[i] / ploopyvia_config.dpi_multiplier * *value_data;
                }
                ploopyvia_config.dpi_multiplier = *value_data;
                dprintf("dpi_multiplier: %d\n", ploopyvia_config.dpi_multiplier);
                update_dpi();
                break;

            case id_ploopystuff_msjiggler_enabled:
                if( (msJigMainToken != INVALID_DEFERRED_TOKEN) ^ (*value_data) ) {
                    // ^ is an XOR, buddy
                    jiggler_toggle();
                    dprintf("msjiggler_enabled\n");
                }
                break;

            case id_ploopystuff_pointer_invert_h:
                ploopyvia_config.pointer_invert_h = *value_data;
                dprintf("pointer_invert_h:%d\n", ploopyvia_config.pointer_invert_h);
                break;

            case id_ploopystuff_pointer_invert_v:
                ploopyvia_config.pointer_invert_v = *value_data;
                dprintf("pointer_invert_v:%d\n", ploopyvia_config.pointer_invert_v);
                break;

            case id_ploopystuff_gesture_count:
                ploopyvia_config.gesture_count = *value_data;
                plodah_msGestureUpdate();
                dprintf("gesture_count:%d\n", ploopyvia_config.gesture_count);
                break;

            case id_ploopystuff_gesture_action_h:
                ploopyvia_config.gesture_action_h = *value_data;
                plodah_msGestureUpdate();
                dprintf("gesture_action_h:%d\n", ploopyvia_config.gesture_action_h);
                break;

            case id_ploopystuff_gesture_action_v:
                ploopyvia_config.gesture_action_v = *value_data;
                plodah_msGestureUpdate();
                dprintf("gesture_action_v:%d\n", ploopyvia_config.gesture_action_v);
                break;

            case id_ploopystuff_combos_enabled:
                ploopyvia_config.combos_enabled = *value_data;
                dprintf("combos_enabled:%d\n", ploopyvia_config.combos_enabled);
                break;

            case id_ploopystuff_dragscroll_invert_h:
                ploopyvia_config.dragscroll_invert_h = *value_data;
                dprintf("dragscroll_invert_h:%d\n", ploopyvia_config.dragscroll_invert_h);
                break;

            case id_ploopystuff_dragscroll_invert_v:
                ploopyvia_config.dragscroll_invert_v = *value_data;
                dprintf("dragscroll_invert_v:%d\n", ploopyvia_config.dragscroll_invert_v);
                break;

            case id_ploopystuff_dragscroll_divisor_h:
                ploopyvia_config.dragscroll_divisor_h = *value_data;
                dprintf("dragscroll_divisor_h:%d\n", ploopyvia_config.dragscroll_divisor_h);
                break;

            case id_ploopystuff_dragscroll_divisor_v:
                ploopyvia_config.dragscroll_divisor_v = *value_data;
                dprintf("dragscroll_divisor_v:%d\n", ploopyvia_config.dragscroll_divisor_v);
                break;

            case id_ploopystuff_dragscroll_caps:
                ploopyvia_config.dragscroll_caps = *value_data;
                dprintf("dragscroll_caps: %d\n", ploopyvia_config.dragscroll_caps);
                led_update_better_dragscroll(host_keyboard_led_state());
                break;

            case id_ploopystuff_dragscroll_num:
                ploopyvia_config.dragscroll_num = *value_data;
                dprintf("dragscroll_num: %d\n", ploopyvia_config.dragscroll_num);
                led_update_better_dragscroll(host_keyboard_led_state());
                break;

            case id_ploopystuff_dragscroll_scroll:
                ploopyvia_config.dragscroll_scroll = *value_data;
                dprintf("dragscroll_scroll: %d\n", ploopyvia_config.dragscroll_scroll);
                led_update_better_dragscroll(host_keyboard_led_state());
                break;

            case id_ploopystuff_dragscroll_end_on_keypress:
                ploopyvia_config.dragscroll_end_on_keypress = *value_data;
                dprintf("dragscroll_end_on_keypress: %d\n", ploopyvia_config.dragscroll_end_on_keypress);
                break;

            case id_ploopystuff_dragscroll_permanently:
                ploopyvia_config.dragscroll_permanently = *value_data;
                dprintf("dragscroll_permanently: %d\n", ploopyvia_config.dragscroll_permanently);
                led_update_better_dragscroll(host_keyboard_led_state());
                break;

            case id_ploopystuff_dpi_presets:
                ploopyvia_config.dpi_presets[value_data[0]] = (value_data[1]*10) * (ploopyvia_config.dpi_multiplier/20) ;
                dprintf("dpi_presets[%d]: %d\n", value_data[0], value_data[1]);
                update_dpi();
                break;

            case id_ploopystuff_sniper_a_dpi:
                ploopyvia_config.sniper_a_dpi = ((uint8_t)*value_data*10) * (ploopyvia_config.dpi_multiplier/20);
                dprintf("sniper_a_dpi: %d\n", ploopyvia_config.sniper_a_dpi);
                break;

            case id_ploopystuff_sniper_b_dpi:
                ploopyvia_config.sniper_b_dpi = ((uint8_t)*value_data*10) * (ploopyvia_config.dpi_multiplier/20) ;
                dprintf("sniper_b_dpi: %d\n", ploopyvia_config.sniper_b_dpi);
                break;

            case id_ploopystuff_dragscroll_straighten_sensitivity:
                ploopyvia_config.dragscroll_straighten_sensitivity = *value_data;
                dprintf("dragscroll_straighten_sensitivity: %d\n", ploopyvia_config.dragscroll_straighten_sensitivity);
                break;
        }
    }

    void ploopyvia_config_get_value( uint8_t *data )
    {
        uint8_t *value_id   = &(data[0]);
        uint8_t *value_data = &(data[1]);

        switch ( *value_id )
        {
            case id_ploopystuff_dpi_activepreset:
                *value_data = keyboard_config.dpi_config;
                dprintf("dpi_preset: %d\n", keyboard_config.dpi_config);
                break;

            case id_ploopystuff_dpi_multiplier:
                *value_data = ploopyvia_config.dpi_multiplier;
                dprintf("dpi_multiplier: %d\n", ploopyvia_config.dpi_multiplier);
                break;

            case id_ploopystuff_msjiggler_enabled:
                if(msJigMainToken != INVALID_DEFERRED_TOKEN){
                    dprintf("msjiggler_enabled true \n");
                    *value_data = true;
                }
                else{
                    dprintf("msjiggler_enabled false \n");
                    *value_data = false;
                }
                break;

            case id_ploopystuff_pointer_invert_h:
                *value_data = ploopyvia_config.pointer_invert_h;
                dprintf("pointer_invert_h:%d\n", ploopyvia_config.pointer_invert_h);
                break;

            case id_ploopystuff_pointer_invert_v:
                *value_data = ploopyvia_config.pointer_invert_v;
                dprintf("pointer_invert_v:%d\n", ploopyvia_config.pointer_invert_v);
                break;

            case id_ploopystuff_gesture_count:
                *value_data = ploopyvia_config.gesture_count;
                dprintf("gesture_count:%d\n", ploopyvia_config.gesture_count);
                break;

            case id_ploopystuff_gesture_action_h:
                *value_data = ploopyvia_config.gesture_action_h;
                dprintf("gesture_action_h:%d\n", ploopyvia_config.gesture_action_h);
                break;

            case id_ploopystuff_gesture_action_v:
                *value_data = ploopyvia_config.gesture_action_v;
                dprintf("gesture_action_v:%d\n", ploopyvia_config.gesture_action_v);
                break;

            case id_ploopystuff_combos_enabled:
                *value_data = ploopyvia_config.combos_enabled;
                dprintf("combos_enabled:%d\n", ploopyvia_config.combos_enabled);
                break;

            case id_ploopystuff_dragscroll_invert_h:
                *value_data = ploopyvia_config.dragscroll_invert_h;
                dprintf("dragscroll_invert_h:%d\n", ploopyvia_config.dragscroll_invert_h);
                break;

            case id_ploopystuff_dragscroll_invert_v:
                *value_data = ploopyvia_config.dragscroll_invert_v;
                dprintf("dragscroll_invert_v:%d\n", ploopyvia_config.dragscroll_invert_v);
                break;

            case id_ploopystuff_dragscroll_divisor_h:
                *value_data = ploopyvia_config.dragscroll_divisor_h;
                dprintf("dragscroll_divisor_h:%d\n", ploopyvia_config.dragscroll_divisor_h);
                break;

            case id_ploopystuff_dragscroll_divisor_v:
                *value_data = ploopyvia_config.dragscroll_divisor_v;
                dprintf("dragscroll_divisor_v:%d\n", ploopyvia_config.dragscroll_divisor_v);
                break;

            case id_ploopystuff_dragscroll_caps:
                *value_data = ploopyvia_config.dragscroll_caps;
                dprintf("dragscroll_caps: %d\n", ploopyvia_config.dragscroll_caps);
                break;

            case id_ploopystuff_dragscroll_num:
                *value_data = ploopyvia_config.dragscroll_num;
                dprintf("dragscroll_num: %d\n", ploopyvia_config.dragscroll_num);
                break;

            case id_ploopystuff_dragscroll_scroll:
                *value_data = ploopyvia_config.dragscroll_scroll;
                dprintf("dragscroll_scroll: %d\n", ploopyvia_config.dragscroll_scroll);
                break;

            case id_ploopystuff_dragscroll_end_on_keypress:
                *value_data = ploopyvia_config.dragscroll_end_on_keypress;
                dprintf("dragscroll_end_on_keypress: %d\n", ploopyvia_config.dragscroll_end_on_keypress);
                break;

            case id_ploopystuff_dragscroll_permanently:
                *value_data = ploopyvia_config.dragscroll_permanently;
                dprintf("dragscroll_permanently: %d\n", ploopyvia_config.dragscroll_permanently);
                break;

            case id_ploopystuff_dpi_presets:
                value_data[1] = (ploopyvia_config.dpi_presets[value_data[0]] / 10) / (ploopyvia_config.dpi_multiplier/20)  ;
                dprintf("dpi_presets[%d]: %d\n", value_data[0], ploopyvia_config.dpi_presets[value_data[0]]);
                break;

            case id_ploopystuff_sniper_a_dpi:
                *value_data = (ploopyvia_config.sniper_a_dpi / 10) / (ploopyvia_config.dpi_multiplier/20);
                dprintf("sniper_a_dpi: %d\n", ploopyvia_config.sniper_a_dpi);
                break;

            case id_ploopystuff_sniper_b_dpi:
                *value_data = (ploopyvia_config.sniper_b_dpi / 10 ) / (ploopyvia_config.dpi_multiplier/20);
                dprintf("sniper_b_dpi: %d\n", ploopyvia_config.sniper_b_dpi);
                break;

            case id_ploopystuff_dragscroll_straighten_sensitivity:
                *value_data = ploopyvia_config.dragscroll_straighten_sensitivity;
                dprintf("dragscroll_straighten_sensitivity: %d\n", ploopyvia_config.dragscroll_straighten_sensitivity);
                break;
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
                    ploopyvia_config_set_value(value_id_and_data);
                    break;
                }
                case id_custom_get_value:
                {
                    ploopyvia_config_get_value(value_id_and_data);
                    break;
                }
                case id_custom_save:
                {
                    ploopyvia_config_save();
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
#endif // if defined(VIA_ENABLE) && defined(PLOOPY_VIAMENUS)
