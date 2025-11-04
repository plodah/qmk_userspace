#if defined(KEY_OVERRIDE_ENABLE)
    const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

    const key_override_t *key_overrides[] = {
        &delete_key_override,
    };
#endif // defined(KEY_OVERRIDE_ENABLE)