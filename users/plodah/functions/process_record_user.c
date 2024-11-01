#pragma once
#include "functions/rgb.c"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  #if defined(DYNAMIC_MACRO_ENABLE) && defined(PLODAH_DYNAMIC_MACRO_TIMEOUT)
    dynamic_macro_loop_timer = timer_read();
  #endif // defined(DYNAMIC_MACRO_ENABLE) && defined(PLODAH_DYNAMIC_MACRO_TIMEOUT)

  #if defined(PLODAH_TYPINGINDICATOR_RGBINDEX) || defined(PLODAH_MSJIGGLER_ENABLED)
    if (record->event.pressed) {
      #if defined(PLODAH_TYPINGINDICATOR_RGBINDEX)
        plodah_typingindicator_start(keycode);
      #endif // PLODAH_TYPINGINDICATOR_RGBINDEX
      #if defined(PLODAH_MSJIGGLER_ENABLED)
        jiggler_onclick(keycode);
      #endif // PLODAH_MSJIGGLER_ENABLED
    }
  #endif // defined(PLODAH_TYPINGINDICATOR_RGBINDEX) || defined(PLODAH_MSJIGGLER_ENABLED)

  switch (keycode) {
    case PL_VERS:
      if (record->event.pressed) {
        send_string_with_delay ( "\\ " QMK_KEYBOARD "/" QMK_KEYMAP " \" " QMK_VERSION ", Built on: " QMK_BUILDDATE "\n", TAP_CODE_DELAY);
      }
      return false;

    #if defined(PLODAH_FEAT_KC)
      case PL_FEAT:
        if (record->event.pressed) {
          send_string_with_delay ( "\\ FEATURES", TAP_CODE_DELAY );
          #ifdef AUTO_SHIFT_ENABLE
            send_string_with_delay (" AUTO_SHIFT", TAP_CODE_DELAY );
          #endif // AUTO_SHIFT_ENABLE
          #ifdef AUTOCORRECT_ENABLE
            send_string_with_delay (" AUTOCORRECT", TAP_CODE_DELAY );
          #endif // AUTOCORRECT_ENABLE
          #ifdef BACKLIGHT_ENABLE
            send_string_with_delay (" BACKLIGHT", TAP_CODE_DELAY );
          #endif // BACKLIGHT_ENABLE
          #ifdef BOOTMAGIC_ENABLE
            send_string_with_delay (" BOOTMAGIC", TAP_CODE_DELAY );
          #endif // BOOTMAGIC_ENABLE
          #ifdef CAPS_WORD_ENABLE
            send_string_with_delay (" CAPS_WORD", TAP_CODE_DELAY );
          #endif // CAPS_WORD_ENABLE
          #ifdef COMBO_ENABLE
            send_string_with_delay (" COMBO", TAP_CODE_DELAY );
          #endif // COMBO_ENABLE
          #ifdef CONSOLE_ENABLE
            send_string_with_delay (" CONSOLE", TAP_CODE_DELAY );
          #endif // CONSOLE_ENABLE
          #ifdef DEFERRED_EXEC_ENABLE
            send_string_with_delay (" DEFERRED_EXEC", TAP_CODE_DELAY );
          #endif // DEFERRED_EXEC_ENABLE
          #ifdef DYNAMIC_MACRO_ENABLE
            send_string_with_delay (" DYNAMIC_MACRO", TAP_CODE_DELAY );
          #endif // DYNAMIC_MACRO_ENABLE
          #ifdef DYNAMIC_TAPPING_TERM_ENABLE
            send_string_with_delay (" DYNAMIC_TAPPING_TERM", TAP_CODE_DELAY );
          #endif // DYNAMIC_TAPPING_TERM_ENABLE
          #ifdef ENCODER_MAP_ENABLE
            send_string_with_delay (" ENCODER_MAP", TAP_CODE_DELAY );
          #endif // ENCODER_MAP_ENABLE
          #ifdef EXTRAKEY_ENABLE
            send_string_with_delay (" EXTRAKEY", TAP_CODE_DELAY );
          #endif // EXTRAKEY_ENABLE
          #ifdef LEADER_ENABLE
            send_string_with_delay (" LEADER", TAP_CODE_DELAY );
          #endif // LEADER_ENABLE
          #ifdef MOUSEKEY_ENABLE
            send_string_with_delay (" MOUSEKEY", TAP_CODE_DELAY );
          #endif // MOUSEKEY_ENABLE
          #ifdef OS_DETECTION_ENABLE
            send_string_with_delay (" OS_DETECTION", TAP_CODE_DELAY );
          #endif // OS_DETECTION_ENABLE
          #ifdef RGBLIGHT_ENABLE
            send_string_with_delay (" RGBLIGHT", TAP_CODE_DELAY );
          #endif // RGBLIGHT_ENABLE
          #ifdef RGB_MATRIX_ENABLE
            send_string_with_delay (" RGB_MATRIX", TAP_CODE_DELAY );
          #endif // RGB_MATRIX_ENABLE
          #ifdef SPACE_CADET_ENABLE
            send_string_with_delay (" SPACE_CADET", TAP_CODE_DELAY );
          #endif // SPACE_CADET_ENABLE
          #ifdef TAP_DANCE_ENABLE
            send_string_with_delay (" TAP_DANCE", TAP_CODE_DELAY );
          #endif // TAP_DANCE_ENABLE
          #ifdef VIA_ENABLE
            send_string_with_delay (" VIA", TAP_CODE_DELAY );
          #endif // VIA_ENABLE
        }
        return false;
    #endif // defined(PLODAH_FEAT_KC)

    #if defined(PLODAH_QRGB_KC)
      case PL_QRGB:
        if (record->event.pressed) {
            // send_string_with_delay(rgbQuery(), TAP_CODE_DELAY);
            // send_string_with_delay(rgbQuerySmert(), TAP_CODE_DELAY);
            rgbQuerySs();
        }
        return false;
    #endif // defined(PLODAH_QRGB_KC)

    #if defined(PLODAH_ALTTAB_ENHANCEMENTS_ENABLE)
      case PL_ALTTAB:
        if (record->event.pressed) {
          plodah_alt_tab(false);
        }
        return false;
      case PL_ALTSTAB:
        if (record->event.pressed) {
          plodah_alt_tab(true);
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
      case RGB_VAD:
        rgb_vad_pressed = record->event.pressed;
        if (record->event.pressed) {
          repeathold_rgb_timer = timer_read();
        }
        return false;
      case RGB_VAI:
        rgb_vai_pressed = record->event.pressed;
        if (record->event.pressed) {
          repeathold_rgb_timer = timer_read();
        }
        return false;
      case RGB_HUD:
        rgb_hud_pressed = record->event.pressed;
        if (record->event.pressed) {
          repeathold_rgb_timer = timer_read();
        }
        return false;
      case RGB_HUI:
        rgb_hui_pressed = record->event.pressed;
        if (record->event.pressed) {
          repeathold_rgb_timer = timer_read();
        }
        return false;
      case RGB_SAD:
        rgb_sad_pressed = record->event.pressed;
        if (record->event.pressed) {
          repeathold_rgb_timer = timer_read();
        }
        return false;
      case RGB_SAI:
        rgb_sai_pressed = record->event.pressed;
        if (record->event.pressed) {
          repeathold_rgb_timer = timer_read();
        }
        return false;
      case RGB_SPD:
        rgb_spd_pressed = record->event.pressed;
        if (record->event.pressed) {
          repeathold_rgb_timer = timer_read();
        }
        return false;
      case RGB_SPI:
        rgb_spi_pressed = record->event.pressed;
        if (record->event.pressed) {
          repeathold_rgb_timer = timer_read();
        }
        return false;
    #endif // defined(PLODAH_REPEATHOLD_RGB) && defined(RGB_MATRIX_ENABLE)
  }
  return true;
}
