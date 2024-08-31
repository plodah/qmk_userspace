#pragma once

#if defined PLODAH_KNOB_ENHANCEMENTS_ENABLE
    #include "functions/mods_on_knob.c"
#endif // PLODAH_KNOB_ENHANCEMENTS_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

# if defined(PLODAH_TYPINGINDICATOR_RGBINDEX)
    plodah_typingindicator_start();
# endif // PLODAH_TYPINGINDICATOR_RGBINDEX

# if defined(DYNAMIC_MACRO_ENABLE) && defined(PLODAH_DYNAMIC_MACRO_TIMEOUT)
    dynamic_macro_loop_timer = timer_read();
# endif // defined(DYNAMIC_MACRO_ENABLE) && defined(PLODAH_DYNAMIC_MACRO_TIMEOUT)

  switch (keycode) {
#   ifdef PL_VERS
      case PL_VERS:
        if (record->event.pressed) {
          send_string_with_delay (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE, TAP_CODE_DELAY);
        }
        return false;
#   endif // PL_VERS
#   ifdef PL_FEAT
      case PL_FEAT:
        if (record->event.pressed) {
          send_string_with_delay ( "#FEATURES", TAP_CODE_DELAY );
#         ifdef AUTO_SHIFT_ENABLE
            send_string_with_delay (" AUTO_SHIFT_ENABLE", TAP_CODE_DELAY );
#         endif // AUTO_SHIFT_ENABLE
#         ifdef AUTOCORRECT_ENABLE
            send_string_with_delay (" AUTOCORRECT_ENABLE", TAP_CODE_DELAY );
#         endif // AUTOCORRECT_ENABLE
#         ifdef BACKLIGHT_ENABLE
            send_string_with_delay (" BACKLIGHT_ENABLE", TAP_CODE_DELAY );
#         endif // BACKLIGHT_ENABLE
#         ifdef BOOTMAGIC_ENABLE
            send_string_with_delay (" BOOTMAGIC_ENABLE", TAP_CODE_DELAY );
#         endif // BOOTMAGIC_ENABLE
#         ifdef CAPS_WORD_ENABLE
            send_string_with_delay (" CAPS_WORD_ENABLE", TAP_CODE_DELAY );
#         endif // CAPS_WORD_ENABLE
#         ifdef COMBO_ENABLE
            send_string_with_delay (" COMBO_ENABLE", TAP_CODE_DELAY );
#         endif // COMBO_ENABLE
#         ifdef DYNAMIC_MACRO_ENABLE
            send_string_with_delay (" DYNAMIC_MACRO_ENABLE", TAP_CODE_DELAY );
#         endif // DYNAMIC_MACRO_ENABLE
#         ifdef ENCODER_MAP_ENABLE
            send_string_with_delay (" ENCODER_MAP_ENABLE", TAP_CODE_DELAY );
#         endif // ENCODER_MAP_ENABLE
#         ifdef EXTRAKEY_ENABLE
            send_string_with_delay (" EXTRAKEY_ENABLE", TAP_CODE_DELAY );
#         endif // EXTRAKEY_ENABLE
#         ifdef LEADER_ENABLE
            send_string_with_delay (" LEADER_ENABLE", TAP_CODE_DELAY );
#         endif // LEADER_ENABLE
#         ifdef MOUSEKEY_ENABLE
            send_string_with_delay (" MOUSEKEY_ENABLE", TAP_CODE_DELAY );
#         endif // MOUSEKEY_ENABLE
#         ifdef OS_DETECTION_ENABLE
            send_string_with_delay (" OS_DETECTION_ENABLE", TAP_CODE_DELAY );
#         endif // OS_DETECTION_ENABLE
#         ifdef RGBLIGHT_ENABLE
            send_string_with_delay (" RGBLIGHT_ENABLE", TAP_CODE_DELAY );
#         endif // RGBLIGHT_ENABLE
#         ifdef RGB_MATRIX_ENABLE
            send_string_with_delay (" RGB_MATRIX_ENABLE", TAP_CODE_DELAY );
#         endif // RGB_MATRIX_ENABLE
#         ifdef SPACE_CADET_ENABLE
            send_string_with_delay (" SPACE_CADET_ENABLE", TAP_CODE_DELAY );
#         endif // SPACE_CADET_ENABLE
#         ifdef TAP_DANCE_ENABLE
            send_string_with_delay (" TAP_DANCE_ENABLE", TAP_CODE_DELAY );
#         endif // TAP_DANCE_ENABLE
#         ifdef VIA_ENABLE
            send_string_with_delay (" VIA_ENABLE", TAP_CODE_DELAY );
#         endif // VIA_ENABLE
        }
        return false;
#   endif // PL_FEAT
#   ifdef PL_QRGB
      case PL_QRGB:
        if (record->event.pressed) {
#         ifdef RGB_MATRIX_ENABLE
            send_string_with_delay ( "#RGB_MATRIX MODE:", TAP_CODE_DELAY );
            send_string_with_delay ( get_u8_str(rgb_matrix_get_mode(),'0'), TAP_CODE_DELAY );
            send_string_with_delay ( " HUE:", TAP_CODE_DELAY );
            send_string_with_delay ( get_u8_str(rgb_matrix_get_hue(),'0'), TAP_CODE_DELAY );
            send_string_with_delay ( " SAT:", TAP_CODE_DELAY );
            send_string_with_delay ( get_u8_str(rgb_matrix_get_sat(),'0'), TAP_CODE_DELAY );
            send_string_with_delay ( " VAL:", TAP_CODE_DELAY );
            send_string_with_delay ( get_u8_str(rgb_matrix_get_val(),'0'), TAP_CODE_DELAY );
            send_string_with_delay ( " SPD:", TAP_CODE_DELAY );
            send_string_with_delay ( get_u8_str(rgb_matrix_get_speed(),'0'), TAP_CODE_DELAY );
            tap_code (KC_ENT);
#         endif // RGB_MATRIX_ENABLE
#         ifdef RGBLIGHT_ENABLE
            send_string_with_delay ( "#RGBLIGHT MODE:", TAP_CODE_DELAY );
            send_string_with_delay ( get_u8_str(rgblight_get_mode(),'0'), TAP_CODE_DELAY );
            send_string_with_delay ( " HUE:", TAP_CODE_DELAY );
            send_string_with_delay ( get_u8_str(rgblight_get_hue(),'0'), TAP_CODE_DELAY );
            send_string_with_delay ( " SAT:", TAP_CODE_DELAY );
            send_string_with_delay ( get_u8_str(rgblight_get_sat(),'0'), TAP_CODE_DELAY );
            send_string_with_delay ( " VAL:", TAP_CODE_DELAY );
            send_string_with_delay ( get_u8_str(rgblight_get_val(),'0'), TAP_CODE_DELAY );
            send_string_with_delay ( " SPD:", TAP_CODE_DELAY );
            send_string_with_delay ( get_u8_str(rgblight_get_speed(),'0'), TAP_CODE_DELAY );
            tap_code (KC_ENT);
#         endif // RGBLIGHT_ENABLE
#         if ( ! defined RGB_MATRIX_ENABLE ) && ( ! defined RGBLIGHT_ENABLE )
            send_string_with_delay ( "#No RGB on this kb", TAP_CODE_DELAY );
            tap_code (KC_ENT);
#         endif // NO RGB_MATRIX_ENABLE OR RGBLIGHT_ENABLE
        }
        return false;
#   endif // PL_QRGB
#   ifdef PL_ALTTAB
      case PL_ALTTAB:
        if (record->event.pressed) {
          alt_tab_fw();
        }
        return false;
#   endif // PL_ALTTAB
#   ifdef PL_ALTSTAB
      case PL_ALTSTAB:
        if (record->event.pressed) {
          alt_tab_bk();
        }
        return false;
#   endif // PL_ALTSTAB
#   if defined(PLODAH_KNOB_ENHANCEMENTS_ENABLE) || defined(PLODAH_MODS_INDIC_LALT_INDEX) || defined(PLODAH_MODS_INDIC_RALT_INDEX)
      case KC_LALT:
      case KC_RALT:
        alt_pressed = record->event.pressed;
        break;
#   endif // PLODAH_KNOB_ENHANCEMENTS_ENABLE // ALT
#   if defined(PLODAH_KNOB_ENHANCEMENTS_ENABLE) || defined(PLODAH_MODS_INDIC_LCTL_INDEX) || defined(PLODAH_MODS_INDIC_RCTL_INDEX)
      case KC_LCTL:
      case KC_RCTL:
        ctl_pressed = record->event.pressed;
        break;
#   endif // PLODAH_KNOB_ENHANCEMENTS_ENABLE // CTL
#   if defined(PLODAH_KNOB_ENHANCEMENTS_ENABLE) || defined(PLODAH_MODS_INDIC_LSHIFT_INDEX) || defined(PLODAH_MODS_INDIC_RSHIFT_INDEX)
      case KC_LSFT:
      case KC_RSFT:
        sft_pressed = record->event.pressed;
        break;
#   endif // PLODAH_KNOB_ENHANCEMENTS_ENABLE // SFT
#   if defined(PLODAH_KNOB_ENHANCEMENTS_ENABLE)
      /* Encoder Actions */
      case PL_ENC_PRS:
        if (record->event.pressed) {
          enc_prs_act(ctl_pressed, sft_pressed, alt_pressed);
        }
        return false;
      case PL_ENC_CCW:
        if (record->event.pressed) {
          enc_ccw_act(ctl_pressed, sft_pressed, alt_pressed);
        }
        return false;
      case PL_ENC_CW:
        if (record->event.pressed) {
          enc_cw_act(ctl_pressed, sft_pressed, alt_pressed);
        }
        return false;
#   endif  // PLODAH_KNOB_ENHANCEMENTS_ENABLE
#   if defined(PLODAH_REPEATHOLD_RGB) && defined(RGB_MATRIX_ENABLE)
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
#   endif // defined(PLODAH_REPEATHOLD_RGB) && defined(RGB_MATRIX_ENABLE)
  }
  return true;
}
