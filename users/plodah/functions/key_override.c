#if defined(KEY_OVERRIDE_ENABLE)
    const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
    #if defined(OS_DETECTION_ENABLE)
        bool os_dependent_override(bool key_down, void *layer) {
            dprintf("os_dependent_override\n");
            if(key_down){
                if(detected_host_os() == OS_WINDOWS){
                    dprintf("win on keydown \n");
                    unregister_mods(MOD_MASK_GUI);
                    return true;
                }
                else{
                    dprintf("non-win on keydown\n");
                    register_code(KC_C);
                    return false;
                }
            }
            else{
                if(detected_host_os() == OS_WINDOWS){
                    //register_mods(MOD_MASK_GUI);
                    return true;
                }
                else{
                    unregister_code(KC_C);
                    return false;
                }
            }
            return false;
        }
        const key_override_t close_window_override = {
                                        .trigger_mods           = MOD_MASK_GUI,
                                        .layers                 = ~0,
                                        .suppressed_mods        = 0,
                                        .options                = ko_options_default,
                                        .negative_mod_mask      = 0,
                                        .custom_action          = os_dependent_override,
                                        .context                = NULL,
                                        .trigger                = KC_C,
                                        .replacement            = A(KC_F4),
                                        .enabled                = NULL};
        const key_override_t close_window_override_BRM = {
                                        .trigger_mods           = MOD_MASK_GUI,
                                        .layers                 = ~0,
                                        .suppressed_mods        = 0,
                                        .options                = ko_options_default,
                                        .negative_mod_mask      = 0,
                                        .custom_action          = os_dependent_override,
                                        .context                = NULL,
                                        .trigger                = BRM_CS,
                                        .replacement            = A(KC_F4),
                                        .enabled                = NULL};
    #endif // defined(OS_DETECTION_ENABLE)
    
    const key_override_t *key_overrides[] = {
        &delete_key_override,
        #if defined(OS_DETECTION_ENABLE)
            &close_window_override,
            &close_window_override_BRM,
        #endif // defined(OS_DETECTION_ENABLE)
    };

#endif // defined(KEY_OVERRIDE_ENABLE)
