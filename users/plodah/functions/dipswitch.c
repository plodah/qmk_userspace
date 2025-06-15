#if PLODAH_BORING_LAYER > 0 && defined(DIP_SWITCH_ENABLE)
    #pragma once
    bool dip_switch_update_user(uint8_t index, bool active) {
        if (index == 0) {
            //default_layer_set(active ? PLODAH_BORING_LAYER : 0);
            layer_move(active ? PLODAH_BORING_LAYER : 0);
        }
        return false;
    }
#endif // DIP_SWITCH_ENABLE
