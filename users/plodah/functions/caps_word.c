#if defined(CAPS_WORD_ENABLE)
  #pragma once
  void caps_word_set_user(bool active) {
    dprintf("caps_word_set_user\n");
    #if defined(PLODAH_BORING_LAYER)
      if( get_highest_layer(layer_state | default_layer_state) == PLODAH_BORING_LAYER){
        dprintf("caps_word_off on boring layer\n");
        caps_word_off();
      }
      else{
        dprintf("caps_word_on this is not boring layer\n");
      }
    #endif // defined(PLODAH_BORING_LAYER)
  }
#endif // CAPS_WORD_ENABLE
