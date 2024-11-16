#include QMK_KEYBOARD_H
#include "plodah.h"
#include "quantum.h"

//====================//
//      MOD VARS      //
//====================//
#if defined(PLODAH_KNOB_ENHANCEMENTS_ENABLE) || defined(PLODAH_MODS_INDIC_LCTL_INDEX) || defined(PLODAH_MODS_INDIC_RCTL_INDEX)
  bool ctl_pressed = false;
#endif // PLODAH_KNOB_ENHANCEMENTS_ENABLE // CTL
#if defined(PLODAH_KNOB_ENHANCEMENTS_ENABLE) || defined(PLODAH_MODS_INDIC_LGUI_INDEX) || defined(PLODAH_MODS_INDIC_RGUI_INDEX)
  bool gui_pressed = false;
#endif // PLODAH_KNOB_ENHANCEMENTS_ENABLE // GUI
#if defined(PLODAH_KNOB_ENHANCEMENTS_ENABLE) || defined(PLODAH_ALTTAB_ENHANCEMENTS_ENABLE) || defined(PLODAH_MODS_INDIC_LALT_INDEX) || defined(PLODAH_MODS_INDIC_RALT_INDEX)
  bool alt_pressed = false;
#endif // PLODAH_KNOB_ENHANCEMENTS_ENABLE // ALT
#if defined(PLODAH_KNOB_ENHANCEMENTS_ENABLE) || defined(PLODAH_MODS_INDIC_LSHIFT_INDEX) || defined(PLODAH_MODS_INDIC_RSHIFT_INDEX) || defined(CAPS_WORD_ENABLE)
  bool sft_pressed = false;
#endif // PLODAH_KNOB_ENHANCEMENTS_ENABLE // SFT

#include "functions/rgb.c" // required by autocorrect, process_record
#include "functions/autocorrect.c"
#include "functions/caps_word.c"
#include "functions/debug.c"
#include "functions/dipswitch.c"
#include "functions/dynamic_macros.c"
#include "functions/mouse_jiggler.c"
#include "functions/repeathold_rgb.c"
#include "functions/tapdance.c"
#include "functions/textfns.c"
#include "functions/typing_indicator.c"

#if defined(PLODAH_KNOB_ENHANCEMENTS_ENABLE) && (!defined(PLODAH_ALTTAB_ENHANCEMENTS_ENABLE))
  #define PLODAH_ALTTAB_ENHANCEMENTS_ENABLE
#endif

#include "functions/alttab_enhancements.c"
#include "functions/encoder_actions.c"

#include "functions/process_record_user.c"
#include "functions/combos.c"

#include "functions/matrix_scan.c"
#include "functions/indicators.c" // last pls
