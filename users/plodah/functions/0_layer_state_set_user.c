#if defined(TRI_LAYER_ENABLE) && ( defined(PLODAH_TRILAYER_SETONE) || defined(PLODAH_TRILAYER_SETTWO) || defined(PLODAH_TRILAYER_SETTHR) )
    #include "functions/tri_layer.h"
#endif // defined(TRI_LAYER_ENABLE) && ( defined(PLODAH_TRILAYER_SETONE) || defined(PLODAH_TRILAYER_SETTWO) || defined(PLODAH_TRILAYER_SETTHR) )

#if defined(COMMUNITY_MODULE_SOCD_CLEANER_ENABLE)
    #include "socd_cleaner.h"
#endif // defined(COMMUNITY_MODULE_SOCD_CLEANER_ENABLE)

#if (defined(TRI_LAYER_ENABLE) && ( defined(PLODAH_TRILAYER_SETONE) || defined(PLODAH_TRILAYER_SETTWO) || defined(PLODAH_TRILAYER_SETTHR) ))
    layer_state_t layer_state_set_user(layer_state_t state) {
        #if defined(TRI_LAYER_ENABLE) && ( defined(PLODAH_TRILAYER_SETONE) || defined(PLODAH_TRILAYER_SETTWO) || defined(PLODAH_TRILAYER_SETTHR) )
            state = layer_state_set_tri_layer(state);
        #endif // defined(TRI_LAYER_ENABLED)
        return state;
    }
#endif // defined(TRI_LAYER_ENABLE)

#if defined(COMMUNITY_MODULE_SOCD_CLEANER_ENABLE)
    layer_state_t default_layer_state_set_user(layer_state_t state) {
        socd_cleaner_enabled = IS_LAYER_ON_STATE(state, _G_QWERTY);
        return state;
    }
#endif // defined(COMMUNITY_MODULE_SOCD_CLEANER_ENABLE)
