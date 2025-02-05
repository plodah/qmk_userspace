#include QMK_KEYBOARD_H
#include "plodah.h"
#include "quantum.h"

//====================//
//      MOD VARS      //
//====================//
#if defined(PLODAH_KNOB_ENHANCEMENTS_ENABLE) || \
    defined(PLODAH_MODS_INDIC_LCTL_INDEX) || \
    defined(PLODAH_MODS_INDIC_RCTL_INDEX) || \
    defined(PLODAH_DYNAMIC_MACRO_KCS_ENABLE)
  #define CTLPRESSED_REQUIRED
  bool ctl_pressed = false;
#endif // CTL

#if defined(PLODAH_KNOB_ENHANCEMENTS_ENABLE) || \
    defined(PLODAH_MODS_INDIC_LGUI_INDEX) || \
    defined(PLODAH_MODS_INDIC_RGUI_INDEX)
  #define GUIPRESSED_REQUIRED
  bool gui_pressed = false;
#endif // GUI

#if defined(PLODAH_KNOB_ENHANCEMENTS_ENABLE) || \
    defined(PLODAH_TASKSWITCH_ENABLE) || \
    defined(PLODAH_MODS_INDIC_LALT_INDEX) || \
    defined(PLODAH_MODS_INDIC_RALT_INDEX) || \
    defined(PLODAH_DYNAMIC_MACRO_KCS_ENABLE)
  #define ALTPRESSED_REQUIRED
  bool alt_pressed = false;
#endif // ALT

#if defined(PLODAH_KNOB_ENHANCEMENTS_ENABLE) || \
    defined(PLODAH_MODS_INDIC_LSHIFT_INDEX) || \
    defined(PLODAH_MODS_INDIC_RSHIFT_INDEX) || \
    defined(CAPS_WORD_ENABLE)
  #define SFTPRESSED_REQUIRED
  bool sft_pressed = false;
#endif // PLODAH_KNOB_ENHANCEMENTS_ENABLE // SFT

#include "functions/oled.c" // required by autocorrect
#include "functions/rgb.c" // required by autocorrect, process_record

#include "functions/autocorrect.c"
#include "functions/caps_word.c"
#include "functions/debug.c"
#include "functions/dipswitch.c"
#include "functions/dragscroll.c"
#include "functions/dynamic_macros.c"
#include "functions/mouse_jiggler.c"
#include "functions/mouse_wiggle.c"
#include "functions/repeathold_rgb.c"
#include "functions/tapdance.c"
#include "functions/textfns.c"
#include "functions/typing_indicator.c"

#if defined(PLODAH_KNOB_ENHANCEMENTS_ENABLE) && (!defined(PLODAH_TASKSWITCH_ENABLE))
  #define PLODAH_TASKSWITCH_ENABLE
#endif

#include "functions/taskswitch.c"
#include "functions/encoder_actions.c"

#include "functions/pointing_device.c"
#include "functions/led_update_user.c"
#include "functions/process_record_user.c"
#include "functions/combos.c"

#include "functions/matrix_scan.c"
#include "functions/indicators.c" // last pls
