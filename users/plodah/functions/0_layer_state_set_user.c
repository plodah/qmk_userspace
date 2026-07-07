#if defined(TRI_LAYER_ENABLE) && defined(TRI_LAYER_UNSTRICT)
    #include "functions/tri_layer.h"
#endif // defined(TRI_LAYER_ENABLE) && defined(TRI_LAYER_UNSTRICT)

#if defined(COMMUNITY_MODULE_SOCD_CLEANER_ENABLE)
    #include "socd_cleaner.h"
#endif // defined(COMMUNITY_MODULE_SOCD_CLEANER_ENABLE)

#if (defined(TRI_LAYER_ENABLE) && defined(TRI_LAYER_UNSTRICT)) || defined(COMMUNITY_MODULE_SOCD_CLEANER_ENABLE)
    layer_state_t layer_state_set_user(layer_state_t state) {
        #if defined(TRI_LAYER_ENABLE) && defined(TRI_LAYER_UNSTRICT)
            state = layer_state_set_tri_layer(state);
        #endif // defined(TRI_LAYER_ENABLED)

        #if defined(COMMUNITY_MODULE_SOCD_CLEANER_ENABLE)
            socd_cleaner_enabled = IS_LAYER_ON_STATE(state, _G_QWERTY);
        #endif // defined(COMMUNITY_MODULE_SOCD_CLEANER_ENABLE)
        return state;
    }
#endif // defined(TRI_LAYER_ENABLE) || defined(COMMUNITY_MODULE_SOCD_CLEANER_ENABLE)
