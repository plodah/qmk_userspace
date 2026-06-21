#if defined(TRI_LAYER_ENABLE) && defined(TRI_LAYER_UNSTRICT)

    layer_state_t direct_layer_state;
    bool process_record_tri_layer(uint16_t keycode, keyrecord_t *record) {
        layer_state_t this_tri_layer_state = 0;
        switch(keycode){
            case QK_MOMENTARY ... QK_MOMENTARY_MAX: // MO(layer) key.
                this_tri_layer_state = (1 << QK_MOMENTARY_GET_LAYER(keycode));
                break;
            case QK_LAYER_MOD ... QK_LAYER_MOD_MAX: // LM(layer,mod) key.
                this_tri_layer_state = (1 << QK_LAYER_MOD_GET_LAYER(keycode));
                break;
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX: // Layer-tap LT(layer,kc) key.
                this_tri_layer_state = (1 << QK_LAYER_TAP_GET_LAYER(keycode));
                break;
            case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX: // TT(layer) key.
                this_tri_layer_state = (1 << QK_LAYER_TAP_TOGGLE_GET_LAYER(keycode));
                break;
        }
        if(this_tri_layer_state){
            if (record->event.pressed) {
                direct_layer_state = direct_layer_state | this_tri_layer_state;
            }
            else{
                direct_layer_state = direct_layer_state & ~this_tri_layer_state;
            }
            dprintf("process_rec TRI_LAYER %d \n", this_tri_layer_state);
            dprintf("process_rec TRI_LAYER %d \n", direct_layer_state);
        }
        return true;
    }

    layer_state_t newstate;
    layer_state_t mask_fna_fnb = ((layer_state_t)1 << _FNA) | ((layer_state_t)1 << _FNB);
    layer_state_t mask_fnc = (layer_state_t)1 << _FNC;
    bool abc_enabled = false;    

    #if defined(PLODAH_BCD_TRI_LAYER)
        layer_state_t mask_fnb_fnc = ((layer_state_t)1 << _FNB) | ((layer_state_t)1 << _FNC);
        layer_state_t mask_fnd = (layer_state_t)1 << _FND;
        bool bcd_enabled = false;
    #endif // PLODAH_BCD_TRI_LAYER

    #if defined(PLODAH_DUAL_TRI_LAYER)
        layer_state_t mask_raise_lower = ((layer_state_t)1 << _RAISE) | ((layer_state_t)1 << _LOWER);
        layer_state_t mask_adj = (layer_state_t)1 << _ADJUST;
        bool dualtri_enabled = false;
    #endif // PLODAH_DUAL_TRI_LAYER
    layer_state_t layer_state_set_user(layer_state_t state) {
        newstate = state|direct_layer_state;
        #if defined(PLODAH_BCD_TRI_LAYER)
            if((direct_layer_state & mask_fnb_fnc) == mask_fnb_fnc){
                dprintf("TRI_LAYER FND on \n");
                newstate = newstate | mask_fnd;
                bcd_enabled = true;
            }
            if(bcd_enabled && (direct_layer_state & mask_fnb_fnc) != mask_fnb_fnc){
                dprintf("TRI_LAYER FND off \n");
                newstate = newstate & ~mask_fnd;
                bcd_enabled = false;
            }
        #endif // PLODAH_BCD_TRI_LAYER

        if( (direct_layer_state & mask_fna_fnb) == mask_fna_fnb){
            dprintf("TRI_LAYER FNC on \n");
            newstate = newstate | mask_fnc;
            abc_enabled = true;
        }
        else if(abc_enabled){
            dprintf("TRI_LAYER FNC off \n");
            newstate = newstate & ~mask_fnc;
            abc_enabled = false;
        }

        #if defined(PLODAH_DUAL_TRI_LAYER)
            if((direct_layer_state & mask_raise_lower) == mask_raise_lower){
                dprintf("TRI_LAYER ADJUST on \n");
                newstate = newstate | mask_adj;
                dualtri_enabled = true;
            }
            else if(dualtri_enabled){
                dprintf("TRI_LAYER ADJUST off \n");
                newstate = newstate & ~mask_adj;
                dualtri_enabled = false;
            }
        #endif // PLODAH_DUAL_TRI_LAYER
        return newstate;
    }
#endif // defined(TRI_LAYER_ENABLE) && defined(TRI_LAYER_UNSTRICT)

