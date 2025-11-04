#if defined(TRI_LAYER_ENABLE) && defined(TRI_LAYER_UNSTRICT)
    layer_state_t layer_state_set_user(layer_state_t state) {
    // return update_tri_layer_state(state, _FNA, _FNB, _FNC);
    // layer_state_t mask123 = ((layer_state_t)1 << _FNA) | ((layer_state_t)1 << _FNB) | ((layer_state_t)1 << _FNC);
    layer_state_t mask12 = ((layer_state_t)1 << _FNA) | ((layer_state_t)1 << _FNB);
    // layer_state_t mask1 = (layer_state_t)1 << _FNA;
    // layer_state_t mask2 = (layer_state_t)1 << _FNB;
    layer_state_t mask3 = (layer_state_t)1 << _FNC;
    // layer_state_t returnstate = state;

    if((state & mask12) == mask12){
        dprintf("tril 3 on \n");
        return state | mask3;
    }
    else if(state & mask12){
        dprintf("tril 3 off \n");
        return state & ~mask3;
    }
    return state;
    }
#endif // defined(TRI_LAYER_ENABLE) && defined(TRI_LAYER_UNSTRICT)
