#pragma once

#if defined PLODAH_MODS_ON_KNOB
    #include "func/mods_on_knob.c"
#endif // PLODAH_MODS_ON_KNOB

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
#       if defined(PLODAH_MODS_ON_KNOB) || defined(PLODAH_MODS_INDIC_LALT_INDEX) || defined(PLODAH_MODS_INDIC_RALT_INDEX)
            case KC_LALT:
            case KC_RALT:
                alt_pressed = record->event.pressed;
                break;
#       endif // PLODAH_MODS_ON_KNOB // ALT
#       if defined(PLODAH_MODS_ON_KNOB) || defined(PLODAH_MODS_INDIC_LCTL_INDEX) || defined(PLODAH_MODS_INDIC_RCTL_INDEX)
            case KC_LCTL:
            case KC_RCTL:
                ctl_pressed = record->event.pressed;
                break;
#       endif // PLODAH_MODS_ON_KNOB // CTL
#       if defined(PLODAH_MODS_ON_KNOB) || defined(PLODAH_MODS_INDIC_LSHIFT_INDEX) || defined(PLODAH_MODS_INDIC_RSHIFT_INDEX)
            case KC_LSFT:
            case KC_RSFT:
                sft_pressed = record->event.pressed;
                break;
#       endif // PLODAH_MODS_ON_KNOB // SFT
#       if defined(PLODAH_MODS_ON_KNOB)
            /* Encoder Actions */
            case PL_ENC_PRS:
                if ( record->event.pressed ) {
                    enc_prs_act( ctl_pressed, sft_pressed, alt_pressed );
                }
                break;
            case PL_ENC_CCW:
                if ( record->event.pressed ) {
                    enc_ccw_act( ctl_pressed, sft_pressed, alt_pressed );
                }
                break;
            case PL_ENC_CW:
                if ( record->event.pressed ) {
                    enc_cw_act( ctl_pressed, sft_pressed, alt_pressed );
                }
                break;
#       endif  // PLODAH_MODS_ON_KNOB
    }
    return true;
}
