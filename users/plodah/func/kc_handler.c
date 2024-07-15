#pragma once

#if defined MODS_ON_KNOB
    #include "func/mods_on_knob.c"
#endif // MODS_ON_KNOB

bool kc_handler( uint16_t keycode, keyrecord_t *record ) {
    switch (keycode) {
    // Static version keycode
        case PL_VERS:
            if ( record->event.pressed ) {
                SEND_STRING ( QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE );
            }
            break;
        case PL_ALTTAB:
            if ( record->event.pressed ) {
                alt_tab_fw();
            }
            break;
        case PL_ALTSTAB:
            if ( record->event.pressed ) {
                alt_tab_bk();
            }
            break;
        case PL_TEST:
            if ( record->event.pressed ) {
                SEND_STRING ( "Butt with Knobs." );
            }
            break;
#       ifdef MODS_ON_KNOB
        // MOD callback
            case KC_LCTL:
            case KC_RCTL:
                ctl_pressed = record->event.pressed;
                break;
            case KC_LSFT:
            case KC_RSFT:
                sft_pressed = record->event.pressed;
                break;
            case KC_LALT:
            case KC_RALT:
                alt_pressed = record->event.pressed;
                break;
            /* Encoder Actions */
            case ENC_PRS:
                if ( record->event.pressed ) {
                    enc_prs_act( ctl_pressed, sft_pressed, alt_pressed );
                }
                break;
            case ENC_CCW:
                if ( record->event.pressed ) {
                    enc_ccw_act( ctl_pressed, sft_pressed, alt_pressed );
                }
                break;
            case ENC_CW:
                if ( record->event.pressed ) {
                    enc_cw_act( ctl_pressed, sft_pressed, alt_pressed );
                }
                break;
#       endif  // MODS_ON_KNOB
    }
    return true;
}
