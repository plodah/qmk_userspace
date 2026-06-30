#include QMK_KEYBOARD_H
#if defined(COMBO_ENABLE)
    #if defined(IS_MOUSE)
        #include "combos_mse.h"
    #else
        #include "combos_kbd.h"
    #endif

    #if defined(PLODAH_BORING_LAYER)
        bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
                if(layer_state_is(PLODAH_BORING_LAYER)){
                    return false;
                }
            return true;
        }
    #endif // PLODAH_BORING_LAYER
#endif // COMBO_ENABLE
