#if defined(COMBO_ENABLE)
    #pragma once

    #if defined(IS_MOUSE)
        #include "combos_mse.h"
    #else // not IS_MOUSE
        #include "combos_kbd.h"
    #endif // IS_MOUSE => ELSE

    #if defined(PLODAH_BORING_LAYER)
        bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
                if(layer_state_is(PLODAH_BORING_LAYER)){
                    return false;
                }
            return true;
        }
    #endif // PLODAH_BORING_LAYER

    //uint16_t combocount = sizeof(key_combos);
    //#define COMBOCOUNT combocount
    //#pragma message "Number of declared combos is: " XSTR(combocount)

    #endif // COMBO_ENABLE
