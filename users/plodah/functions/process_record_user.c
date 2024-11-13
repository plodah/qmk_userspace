#pragma once

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  #if defined(PLODAH_TYPINGINDICATOR_RGBINDEX) || defined(PLODAH_MSJIGGLER_ENABLED)
    if (record->event.pressed) {
      #if defined(PLODAH_TYPINGINDICATOR_RGBINDEX)
        plodah_typingindicator_start(keycode);
      #endif // PLODAH_TYPINGINDICATOR_RGBINDEX
      #if defined(PLODAH_MSJIGGLER_ENABLED)
        if (record->event.pressed) {
          jiggler_onclick(keycode);
        }
      #endif // PLODAH_MSJIGGLER_ENABLED
    }
  #endif // defined(PLODAH_TYPINGINDICATOR_RGBINDEX) || defined(PLODAH_MSJIGGLER_ENABLED)

  switch (keycode) {
    #if defined(KC_PL_QFTR)
      case PL_QFTR:
        if (record->event.pressed) {
            featureQuerySs();
        }
        return false;
    #endif // defined(KC_PL_QFTR)

    #if defined(KC_PL_QLYR)
      case PL_QLYR:
        if (record->event.pressed) {
            // send_string_with_delay(layerQuery(), TAP_CODE_DELAY);
            layerQuerySs();
        }
        return false;
    #endif // defined(KC_PL_QLYR)

    #if defined(KC_PL_QRGB)
      case PL_QRGB:
        if (record->event.pressed) {
            // send_string_with_delay(rgbQuery(), TAP_CODE_DELAY);
            // send_string_with_delay(rgbQuerySmert(), TAP_CODE_DELAY);
            rgbQuerySs();
        }
        return false;
    #endif // defined(KC_PL_QRGB)

    #if defined(KC_PL_QVER)
      case PL_QVER:
        if (record->event.pressed) {
          send_string_with_delay ( "\\ " QMK_KEYBOARD "/" QMK_KEYMAP " \" " QMK_VERSION ", Built on: " QMK_BUILDDATE "\n", TAP_CODE_DELAY);
        }
        return false;
    #endif // defined(KC_PL_QVER)

    #if defined(PLODAH_ALTTAB_ENHANCEMENTS_ENABLE)
      case PL_ALTTAB:
        if (record->event.pressed) {
          plodah_alttab_start(false);
        }
        return false;
      case PL_ALTSTAB:
        if (record->event.pressed) {
          plodah_alttab_start(true);
        }
        return false;
    #endif  // defined(PLODAH_ALTTAB_ENHANCEMENTS_ENABLE)

    #if defined(PLODAH_KNOB_ENHANCEMENTS_ENABLE) || defined(PLODAH_MODS_INDIC_LCTL_INDEX) || defined(PLODAH_MODS_INDIC_RCTL_INDEX)
      case KC_LCTL:
      case KC_RCTL:
        ctl_pressed = record->event.pressed;
        break;
    #endif // PLODAH_KNOB_ENHANCEMENTS_ENABLE // CTL

    #if defined(PLODAH_KNOB_ENHANCEMENTS_ENABLE) || defined(PLODAH_MODS_INDIC_LGUI_INDEX) || defined(PLODAH_MODS_INDIC_RGUI_INDEX)
      case KC_LGUI:
      case KC_RGUI:
        gui_pressed = record->event.pressed;
        break;
    #endif // PLODAH_KNOB_ENHANCEMENTS_ENABLE // GUI

    #if defined(PLODAH_KNOB_ENHANCEMENTS_ENABLE) || defined(PLODAH_MODS_INDIC_LALT_INDEX) || defined(PLODAH_MODS_INDIC_RALT_INDEX)
      case KC_LALT:
      case KC_RALT:
        alt_pressed = record->event.pressed;
        break;
    #endif // PLODAH_KNOB_ENHANCEMENTS_ENABLE // ALT

    #if defined(PLODAH_KNOB_ENHANCEMENTS_ENABLE) || defined(PLODAH_MODS_INDIC_LSHIFT_INDEX) || defined(PLODAH_MODS_INDIC_RSHIFT_INDEX)
      case KC_LSFT:
      case KC_RSFT:
        sft_pressed = record->event.pressed;
        break;
    #endif // PLODAH_KNOB_ENHANCEMENTS_ENABLE // SFT

    #if defined(PLODAH_KNOB_ENHANCEMENTS_ENABLE)
      case PL_ENC_CCW:
      case PL_ENC_CW:
      case PL_ENC_PRS:
        if (record->event.pressed) {
          enc_act(keycode & 0xff, ctl_pressed, gui_pressed, alt_pressed, sft_pressed);
        }
        return false;
    #endif  // PLODAH_KNOB_ENHANCEMENTS_ENABLE

    #if defined(PLODAH_REPEATHOLD_RGB) && defined(RGB_MATRIX_ENABLE)
      case RGB_HUD:
      case RGB_HUI:
      case RGB_SAD:
      case RGB_SAI:
      case RGB_VAD:
      case RGB_VAI:
      case RGB_SPD:
      case RGB_SPI:
        repeathold_rgb_start(keycode & 0xff, record->event.pressed);
        return true;
    #endif // defined(PLODAH_REPEATHOLD_RGB) && defined(RGB_MATRIX_ENABLE)
  }
  return true;
}
