#if defined(TRI_LAYER_ENABLE) && defined(TRI_LAYER_UNSTRICT)
    layer_state_t layer_state_set_user(layer_state_t state) {
        layer_state_t mask_fna_fnb = ((layer_state_t)1 << _FNA) | ((layer_state_t)1 << _FNB);
        layer_state_t mask_fnc = (layer_state_t)1 << _FNC;

        #if defined(PLODAH_DUAL_TRI_LAYER)
          layer_state_t mask_raise_lower = ((layer_state_t)1 << _RAISE) | ((layer_state_t)1 << _LOWER);
          layer_state_t mask_adj = (layer_state_t)1 << _ADJUST;
        #endif //

        if((state & mask_fna_fnb) == mask_fna_fnb){
            dprintf("TRI_LAYER FNC on \n");
            return state | mask_fnc;
        }
        else if(state & mask_fna_fnb){
            dprintf("TRI_LAYER FNC off \n");
            return state & ~mask_fnc;
        }
        #if defined(PLODAH_DUAL_TRI_LAYER)
        else if((state & mask_raise_lower) == mask_raise_lower){
            dprintf("TRI_LAYER ADJUST on \n");
            return state | mask_adj;
        }
        else if(state & mask_raise_lower){
            dprintf("TRI_LAYER ADJUST off \n");
            return state & ~mask_adj;
        }
        #endif //
        return state;
    }
#endif // defined(TRI_LAYER_ENABLE) && defined(TRI_LAYER_UNSTRICT)
