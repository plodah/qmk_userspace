#include QMK_KEYBOARD_H
#include "plodah.h"
#include "quantum.h"

#include "functions/oled.c" // required by autocorrect
#include "functions/rgb.c" // required by autocorrect, process_record

#include "functions/achordion.c"
#include "functions/autocorrect.c"
#include "functions/caps_word.c"
#include "functions/chordal_hold.c"
#include "functions/debug.c"
#include "functions/dipswitch.c"
#include "functions/better_dragscroll.c"
#include "functions/dynamic_macros.c"
#include "functions/mouse_gesture.c"
#include "functions/ploopy_via.c"
#include "functions/repeathold_rgb.c"
#include "functions/tapdance.c"
#include "functions/typing_indicator.c"

#include "functions/encoder_actions.c"
#include "functions/leader.c"

#include "functions/0_pointing_device_task_user.c"
#include "functions/0_process_record_user.c"
#include "functions/led_update_user.c"
#include "functions/combos.c"

#include "functions/0_housekeeping_task_user.c"
#include "functions/indicators.c" // last pls
