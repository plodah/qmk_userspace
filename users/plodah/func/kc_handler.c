#pragma once

bool kc_handler(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case PL_VERS:
            if (record->event.pressed) {
                SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE);
            }
            break;
        case PL_ALTTAB:
            if (record->event.pressed) {
                alt_tab_fw();
            }
            break;
        case PL_ALTSTAB:
            if (record->event.pressed) {
                alt_tab_bk();
            }
            break;
        case PL_TEST:
            if (record->event.pressed) {
                SEND_STRING ("Butt without Knobs.");
            }
            break;
    }
    return true;
}
