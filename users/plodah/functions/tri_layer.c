#include QMK_KEYBOARD_H
#if defined(TRI_LAYER_ENABLE) && ( defined(PLODAH_TRILAYER_SETONE) || defined(PLODAH_TRILAYER_SETTWO) || defined(PLODAH_TRILAYER_SETTHR) )

    #ifdef PLODAH_TRILAYER_SETONE
        #ifndef PLODAH_TRILAYER_SETONE_A
            #define PLODAH_TRILAYER_SETONE_A 1
        #endif
        #ifndef PLODAH_TRILAYER_SETONE_B
            #define PLODAH_TRILAYER_SETONE_B 2
        #endif
        #ifndef PLODAH_TRILAYER_SETONE_C
            #define PLODAH_TRILAYER_SETONE_C 3
        #endif
    #endif // PLODAH_TRILAYER_SETONE

    #ifdef PLODAH_TRILAYER_SETTWO
        #ifndef PLODAH_TRILAYER_SETTWO_A
            #define PLODAH_TRILAYER_SETTWO_A 2
        #endif
        #ifndef PLODAH_TRILAYER_SETTWO_B
            #define PLODAH_TRILAYER_SETTWO_B 3
        #endif
        #ifndef PLODAH_TRILAYER_SETTWO_C
            #define PLODAH_TRILAYER_SETTWO_C 4
        #endif
    #endif // PLODAH_TRILAYER_SETTWO

    #ifdef PLODAH_TRILAYER_SETTHR
        #ifndef PLODAH_TRILAYER_SETTHR_A
            #define PLODAH_TRILAYER_SETTHR_A 3
        #endif
        #ifndef PLODAH_TRILAYER_SETTHR_B
            #define PLODAH_TRILAYER_SETTHR_B 4
        #endif
        #ifndef PLODAH_TRILAYER_SETTHR_C
            #define PLODAH_TRILAYER_SETTHR_C 5
        #endif
    #endif // PLODAH_TRILAYER_SETTHR

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
    #if defined(PLODAH_TRILAYER_SETONE)
        layer_state_t mask_setoneab = ((layer_state_t)1 << PLODAH_TRILAYER_SETONE_A) | ((layer_state_t)1 << PLODAH_TRILAYER_SETONE_B);
        layer_state_t mask_setonec = (layer_state_t)1 << PLODAH_TRILAYER_SETONE_C;
        bool setone_enabled = false;
    #endif // PLODAH_TRILAYER_SETONE

    #if defined(PLODAH_TRILAYER_SETTWO)
        layer_state_t mask_settwoab = ((layer_state_t)1 << PLODAH_TRILAYER_SETTWO_A) | ((layer_state_t)1 << PLODAH_TRILAYER_SETTWO_B);
        layer_state_t mask_settwoc = (layer_state_t)1 << PLODAH_TRILAYER_SETTWO_C;
        bool settwo_enabled = false;
    #endif // PLODAH_TRILAYER_SETTWO

    #if defined(PLODAH_TRILAYER_SETTHR)
        layer_state_t mask_setthrab = ((layer_state_t)1 << PLODAH_TRILAYER_SETTHR_A) | ((layer_state_t)1 << PLODAH_TRILAYER_SETTHR_B);
        layer_state_t mask_setthrc = (layer_state_t)1 << PLODAH_TRILAYER_SETTHR_C;
        bool setthr_enabled = false;
    #endif // PLODAH_TRILAYER_SETTHR
    
    layer_state_t layer_state_set_tri_layer(layer_state_t state) {
        newstate = state|direct_layer_state;
        #if defined(PLODAH_TRILAYER_SETONE)
            if((direct_layer_state & mask_setoneab) == mask_setoneab){
                dprintf("TRILAYER_SETONE on \n");
                newstate = newstate | mask_setonec;
                setone_enabled = true;
            }
            if(setone_enabled && (direct_layer_state & mask_setoneab) != mask_setoneab){
                dprintf("TRILAYER_SETONE off \n");
                newstate = newstate & ~mask_setonec;
                setone_enabled = false;
            }
        #endif // PLODAH_TRILAYER_SETONE

        #if defined(PLODAH_TRILAYER_SETTWO)
            if((direct_layer_state & mask_settwoab) == mask_settwoab){
                dprintf("TRILAYER_SETTWO on \n");
                newstate = newstate | mask_settwoc;
                settwo_enabled = true;
            }
            if(settwo_enabled && (direct_layer_state & mask_settwoab) != mask_settwoab){
                dprintf("TRILAYER_SETTWO off \n");
                newstate = newstate & ~mask_settwoc;
                settwo_enabled = false;
            }
        #endif // PLODAH_TRILAYER_SETTWO

        #if defined(PLODAH_TRILAYER_SETTHR)
            if((direct_layer_state & mask_setthrab) == mask_setthrab){
                dprintf("TRILAYER_SETTHR on \n");
                newstate = newstate | mask_setthrc;
                setthr_enabled = true;
            }
            if(setthr_enabled && (direct_layer_state & mask_setthrab) != mask_setthrab){
                dprintf("TRILAYER_SETTHR off \n");
                newstate = newstate & ~mask_setthrc;
                setthr_enabled = false;
            }
        #endif // PLODAH_TRILAYER_SETTHR

        return newstate;
    }
#endif // defined(TRI_LAYER_ENABLE) && ( defined(PLODAH_TRILAYER_SETONE) || defined(PLODAH_TRILAYER_SETTWO) || defined(PLODAH_TRILAYER_SETTHR) )

