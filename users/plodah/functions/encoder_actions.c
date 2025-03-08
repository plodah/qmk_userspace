#if defined(PLODAH_KNOB_ENHANCEMENTS_ENABLE)
  #pragma once
  #if defined COMMUNITY_MODULE_TASK_SWITCH_ENABLE
    #include "task_switch.h"
  #endif // COMMUNITY_MODULE_TASK_SWITCH_ENABLE

  void enc_act(int keycode) {
    uint8_t mod_state;
    uint8_t enc_layer;
    // Exclude GUI from MOD state. unregister_mods() & register_mods() calls later
    // including them will opens/closes Windows start menu
    mod_state = get_mods();
    if( get_highest_layer(layer_state | default_layer_state) > 0 ){
      enc_layer = 2 - ((get_highest_layer(layer_state | default_layer_state)) % 2);
    }
    else {
      enc_layer = 0;
    }
    #if defined(PLODAH_BORING_LAYER)
      if( (get_highest_layer(layer_state | default_layer_state) == PLODAH_BORING_LAYER) ){ enc_layer = 0; }
    #endif // PLODAH_BORING_LAYER

    // If mod state is specifically Alt only; don't unregister it.
    if( keycode != (PL_ECPR & 0xff) && !(mod_state == MOD_MASK_ALT || mod_state == MOD_BIT(KC_LALT) || mod_state == MOD_BIT(KC_RALT))){
      // Never unregister GUI as that causes start menu to collapse/appear
      del_mods(mod_state & MOD_MASK_CSA);
    }

    if (mod_state & MOD_MASK_CTRL && mod_state & MOD_MASK_SHIFT && mod_state & MOD_MASK_ALT) {
      //CSA
      switch (keycode) {
        case PL_ECCC & 0xff:
          tap_code16(C(KC_LEFT));
          break;
        case PL_ECCW & 0xff:
          tap_code16(C(KC_RGHT));
          break;
        case PL_ECPR & 0xff:
        default:
          break;
      }
    }

    else if (mod_state & MOD_MASK_CTRL && mod_state & MOD_MASK_SHIFT && mod_state & MOD_MASK_GUI) {
      //CSG
      #ifdef RGB_MATRIX_ENABLE
        switch (keycode) {
          case PL_ECCC & 0xff:
            rgb_matrix_decrease_speed();
            break;
          case PL_ECCW & 0xff:
            rgb_matrix_increase_speed();
            break;
          case PL_ECPR & 0xff:
          default:
            rgb_matrix_toggle();
            break;
        }
      #endif // RGB_MATRIX_ENABLE
    }

      else if (mod_state & MOD_MASK_CTRL && mod_state & MOD_MASK_ALT && mod_state & MOD_MASK_GUI) {
        //CAG
        #ifdef RGB_MATRIX_ENABLE
          switch (keycode) {
            case PL_ECCC & 0xff:
              rgb_matrix_decrease_hue();
              break;
            case PL_ECCW & 0xff:
              rgb_matrix_increase_hue();
              break;
            case PL_ECPR & 0xff:
            default:
              rgb_matrix_toggle();
              break;
          }
        #endif // RGB_MATRIX_ENABLE
      }

      else if (mod_state & MOD_MASK_CTRL && mod_state & MOD_MASK_ALT) {
        //CA
        switch (keycode) {
          case PL_ECCC & 0xff:
            tap_code16(C(KC_MINS));
            break;
          case PL_ECCW & 0xff:
            tap_code16(C(KC_EQL));
            break;
          case PL_ECPR & 0xff:
          default:
            tap_code16(C(KC_0));
            tap_code16(C(KC_P0));
            break;
        }
      }

      else if (mod_state & MOD_MASK_CTRL && mod_state & MOD_MASK_SHIFT) {
        //CS
        switch (keycode) {
          case PL_ECCC & 0xff:
            tap_code(KC_PGUP);
            break;
          case PL_ECCW & 0xff:
            tap_code(KC_PGDN);
            break;
          case PL_ECPR & 0xff:
          default:
            break;
        }
      }

      else if (mod_state & MOD_MASK_SHIFT && mod_state & MOD_MASK_ALT) {
        //SA
        switch (keycode) {
          case PL_ECCC & 0xff:
            tap_code(KC_LEFT);
            break;
          case PL_ECCW & 0xff:
            tap_code(KC_RGHT);
            break;
          case PL_ECPR & 0xff:
          default:
            tap_code(KC_ENT);
            break;
        }
      }

      else if (mod_state & MOD_MASK_CTRL) {
        //C
        switch (keycode) {
          case PL_ECCC & 0xff:
            tap_code16(C(KC_PGUP));
            break;
          case PL_ECCW & 0xff:
            tap_code16(C(KC_PGDN));
            break;
          case PL_ECPR & 0xff:
          default:
            tap_code16(C(KC_F4));
            break;
        }
      }

      else if (mod_state & MOD_MASK_GUI) {
        //G
        switch (keycode) {
          case PL_ECCC & 0xff:
            tap_code16(S(KC_SPC));
            break;
          case PL_ECCW & 0xff:
            tap_code(KC_SPC);
            break;
          case PL_ECPR & 0xff:
          default:
            break;
        }
      }

      else if (mod_state & MOD_MASK_ALT) {
        //A
        switch (keycode) {
          case PL_ECCC & 0xff:
            #if defined(PLODAH_TASKSWITCH_ENABLE)
              plodah_taskswitch_start(true);
            #endif
            #if defined(COMMUNITY_MODULE_TASK_SWITCH_ENABLE)
              taskswitch_start(true);
            #endif
            break;
          case PL_ECCW & 0xff:
            #if defined(PLODAH_TASKSWITCH_ENABLE)
              plodah_taskswitch_start(false);
            #endif
            #if defined(COMMUNITY_MODULE_TASK_SWITCH_ENABLE)
              taskswitch_start(false);
            #endif
            break;
          case PL_ECPR & 0xff:
          default:
            tap_code16(A(KC_F4));
            break;
        }
      }

      else if (mod_state & MOD_MASK_SHIFT) {
        //S
        switch (keycode) {
          case PL_ECCC & 0xff:
            tap_code(KC_MPRV);
            break;
          case PL_ECCW & 0xff:
            tap_code(KC_MNXT);
            break;
          case PL_ECPR & 0xff:
          default:
            tap_code(KC_MPLY);
            break;
        }
      }

      else if ( enc_layer == 1 ) {
        // ODD & NOT BORING
        #ifdef RGB_MATRIX_ENABLE
          switch (keycode) {
            case PL_ECCC & 0xff:
              rgb_matrix_decrease_sat();
              break;
            case PL_ECCW & 0xff:
              rgb_matrix_increase_sat();
              break;
            case PL_ECPR & 0xff:
            default:
              rgb_matrix_toggle();
              break;
          }
        #endif // RGB_MATRIX_ENABLE
      }

      else if ( enc_layer == 2 ) {
        // EVEN, NONZERO & NOT BORING
        #ifdef RGB_MATRIX_ENABLE
          switch (keycode) {
            case PL_ECCC & 0xff:
              rgb_matrix_decrease_val();
              break;
            case PL_ECCW & 0xff:
              rgb_matrix_increase_val();
              break;
            case PL_ECPR & 0xff:
            default:
              rgb_matrix_toggle();
              break;
          }
        #endif // RGB_MATRIX_ENABLE
      }

      else {
        // ELSE
        switch (keycode) {
          case PL_ECCC & 0xff:
            tap_code16_delay(KC_VOLD, 2);
            break;
          case PL_ECCW & 0xff:
            tap_code16_delay(KC_VOLU, 2);
            break;
          case PL_ECPR & 0xff:
          default:
            tap_code(KC_MUTE);
            break;
        }
      }
      register_mods(mod_state);
  }
#endif // PLODAH_KNOB_ENHANCEMENTS_ENABLE
