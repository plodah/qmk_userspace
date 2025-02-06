#if defined(CAPS_WORD_ENABLE)
  #pragma once
  void caps_word_set_user(bool active) {
    #if defined(PLODAH_BORING_LAYER)
      if( get_highest_layer(layer_state | default_layer_state) == PLODAH_BORING_LAYER){
        caps_word_off();
      }
    #endif // defined(PLODAH_BORING_LAYER)
  }
#endif // CAPS_WORD_ENABLE
