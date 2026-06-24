#ifdef CHORDAL_HOLD
    #pragma once
    #include <stdbool.h>
    #include <stdint.h>
    #include "action.h"
    #include "action_tapping.h"
    #include "debug.h"

    bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
        uint16_t other_keycode, keyrecord_t* other_record) {
        if (KC_1 <= other_keycode && other_keycode <= QK_BASIC_MAX) {
            #if defined(DEBUG_CHORDAL_HOLD)
                dprintf("chordal nonalpha\n");
            #endif // DEBUG_CHORDAL_HOLD
            return true;
        }
        switch (tap_hold_keycode) {
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            case QK_MOMENTARY ... QK_MOMENTARY_MAX:
            case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
                #if defined(DEBUG_CHORDAL_HOLD)
                    dprintf("chordal LT/MO/TD true\n");
                #endif // DEBUG_CHORDAL_HOLD
                return true;
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
                switch(QK_MOD_TAP_GET_MODS(tap_hold_keycode)){
                    case MOD_BIT(KC_LCTL):
                    case MOD_BIT(KC_RCTL):
                        if (other_keycode == KC_S || other_keycode == HRM_SA) {
                            #if defined(DEBUG_CHORDAL_HOLD)
                                dprintf("chordal Ctrl S\n");
                            #endif // DEBUG_CHORDAL_HOLD
                            return true;
                        }
                        if (other_keycode == KC_W) {
                            #if defined(DEBUG_CHORDAL_HOLD)
                                dprintf("chordal Ctrl W\n");
                            #endif // DEBUG_CHORDAL_HOLD
                            return true;
                        }
                        break;

                    case MOD_BIT(KC_LSFT):
                    case MOD_BIT(KC_RSFT):
                        break;

                    case MOD_BIT(KC_LALT):
                    case MOD_BIT(KC_RALT):
                        break;

                    case MOD_BIT(KC_LGUI):
                    case MOD_BIT(KC_RGUI):
                        if (other_keycode == KC_E) {
                            #if defined(DEBUG_CHORDAL_HOLD)
                                dprintf("chordal Gui E\n");
                            #endif // DEBUG_CHORDAL_HOLD
                            return true;
                        }
                        if (other_keycode == KC_L || other_keycode == HRM_LA) {
                            #if defined(DEBUG_CHORDAL_HOLD)
                                dprintf("chordal Gui L\n");
                            #endif // DEBUG_CHORDAL_HOLD
                            return true;
                        }
                        if (other_keycode == KC_D || other_keycode == HRM_DS) {
                            #if defined(DEBUG_CHORDAL_HOLD)
                                dprintf("chordal Gui D\n");
                            #endif // DEBUG_CHORDAL_HOLD
                            return true;
                        }
                        break;
                }
                break;
        }
        #if defined(DEBUG_CHORDAL_HOLD)
            dprintf("chordal default\n");
        #endif // DEBUG_CHORDAL_HOLD
        return get_chordal_hold_default(tap_hold_record, other_record);
    }

    #ifdef CHORDAL_HOLD_HANDEDNESS_YD60MQ
        char chordal_hold_handedness(keypos_t key) {
            char answer='*';
            switch(key.col){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                    answer='L';
                    break;
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                    answer='R';
                    break;
                case 6:
                    switch(key.row){
                        case 0:
                        case 1:
                        case 2:
                            answer='R';
                            break;
                        case 3:
                            answer='L';
                            break;
                        case 4:
                            answer='*';
                            break;
                    }
                    break;
                case 7:
                    switch(key.row){
                        case 0:
                        case 1:
                        case 2:
                        case 3:
                            answer='R';
                            break;
                        case 4:
                            answer='*';
                            break;
                    }
                    break;
            }
            #if defined(DEBUG_CHORDAL_HOLD)
                dprintf("CH Hand %u:%u %c\n", key.row, key.col, answer);
            #endif // DEBUG_CHORDAL_HOLD
            return answer;
        }
    #endif // CHORDAL_HOLD_HANDEDNESS_YD60MQ

    #ifdef CHORDAL_HOLD_HANDEDNESS_REVIUNG41
        char chordal_hold_handedness(keypos_t key) {
            char answer='*';
            switch(key.row){
                case 0:
                case 1:
                case 2:
                    answer='L';
                    break;
                case 3:
                case 4:
                case 5:
                    answer='R';
                    break;
                case 6:
                    switch(key.col){
                        case 0:
                        case 1:
                            answer='L';
                            break;
                        case 2:
                            answer='*';
                            break;
                        case 3:
                        case 4:
                            answer='R';
                            break;
                    }
            }
            #if defined(DEBUG_CHORDAL_HOLD)
                dprintf("CH Hand %u:%u %c\n", key.row, key.col, answer);
            #endif // DEBUG_CHORDAL_HOLD
            return answer;
        }
    #endif // CHORDAL_HOLD_HANDEDNESS_REVIUNG41

#endif // CHORDAL_HOLD
