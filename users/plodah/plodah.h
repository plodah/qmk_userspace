#pragma once

#include "version.h"
#include "configs/customkeys.h"

#if defined(COMMUNITY_MODULE_TASK_SWITCH_ENABLE)  && (! defined(TASKSWITCH_DELAY))
  #define TASKSWITCH_DELAY 600
#endif // defined(COMMUNITY_MODULE_TASK_SWITCH_ENABLE)  && (! defined(TASKSWITCH_DELAY))

#if defined(COMBO_ENABLE) && (! defined(COMBO_TERM))
  #define COMBO_STRICT_TIMER
#endif // COMBO_ENABLE

#if defined(DYNAMIC_MACRO_ENABLE) && (! defined(PLODAH_DYNAMIC_MACRO_TIMEOUT))
  #define PLODAH_DYNAMIC_MACRO_TIMEOUT 2500
#endif // DYNAMIC_MACRO_ENABLE

#define ENABLE_COMPILE_KEYCODE

#if defined(OS_DETECTION_ENABLE) && !defined(OS_DETECTION_KEYBOARD_RESET)
  #define OS_DETECTION_KEYBOARD_RESET
#endif // OS_DETECTION_ENABLE
