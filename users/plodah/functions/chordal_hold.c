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
            dprintf("chordal nonalpha\n");
            return true;
        }
        switch (tap_hold_keycode) {
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
                dprintf("chordal LT\n");
                return true;
            case QK_MOMENTARY ... QK_MOMENTARY_MAX:
              dprintf("chordal MO\n");
              return true;
            case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
                dprintf("chordal TD\n");
                return true;
                break;
            case HRM_FC:
            case HRM_JC:
            case BRM_VC:
            case BRM_MC:
                if (other_keycode == KC_S || other_keycode == HRM_SA) {
                    dprintf("chordal Ctrl S\n");
                    return true;
                }
                if (other_keycode == KC_W) {
                    dprintf("chordal Ctrl S\n");
                    return true;
                }
                break;
            case HRM_AG:
            case HRM_GG:
            case HRM_HG:
            case HRM_CG:
            case BRM_ZG:
            case BRM_BG:
            case BRM_NG:
            case BRM_SLG:
                if (other_keycode == KC_E) {
                    dprintf("chordal Gui E\n");
                    return true;
                }
                if (other_keycode == KC_L || other_keycode == HRM_LA) {
                    dprintf("chordal Gui L\n");
                    return true;
                }
                if (other_keycode == KC_D || other_keycode == HRM_DS) {
                    dprintf("chordal Gui D\n");
                    return true;
                }
                break;
            case HRM_SA:
            case HRM_LA:
            case BRM_XA:
            case BRM_DOA:
                break;
            case HRM_DS:
            case HRM_KS:
            case BRM_CS:
            case BRM_COS:
                break;
        }
        dprintf("chordal default\n");
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
            dprintf("CH Hand %u:%u %c\n", key.row, key.col, answer);
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
            dprintf("CH Hand %u:%u %c\n", key.row, key.col, answer);
            return answer;
        }
    #endif // CHORDAL_HOLD_HANDEDNESS_REVIUNG41

#endif // CHORDAL_HOLD
