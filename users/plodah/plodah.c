#include QMK_KEYBOARD_H
#include "plodah.h"
#include "quantum.h"

#include "functions/oled.c" // required by autocorrect
#include "functions/rgb.c" // required by autocorrect, process_record

#include "functions/autocorrect.c"
#include "functions/caps_word.c"
#include "functions/debug.c"
#include "functions/dipswitch.c"
#include "functions/dragscroll.c"
#include "functions/dynamic_macros.c"
#include "functions/mouse_gesture.c"
#include "functions/mouse_jiggler.c"
#include "functions/repeathold_rgb.c"
#include "functions/tapdance.c"
#include "functions/textfns.c"
#include "functions/typing_indicator.c"

#if defined(PLODAH_KNOB_ENHANCEMENTS_ENABLE) && (!defined(PLODAH_TASKSWITCH_ENABLE))
  #define PLODAH_TASKSWITCH_ENABLE
#endif

#include "functions/taskswitch.c"
#include "functions/encoder_actions.c"

#include "functions/0_pointing_device.c"
#include "functions/led_update_user.c"
#include "functions/0_process_record_user.c"
#include "functions/combos.c"

#include "functions/0_matrix_scan.c"
#include "functions/indicators.c" // last pls
