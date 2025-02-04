#pragma once

#define KC_PL_QFTR
// #define KC_PL_QLYR
#define KC_PL_QRGB
#define KC_PL_QVER

#define PLODAH_BORING_LAYER 1

#if defined(DEFERRED_EXEC_ENABLE)
  #define PLODAH_MSJIGGLER_ENABLE
  #define PLODAH_MSJIGGLER_INTRO
  // #define PLODAH_MSJIGGLER_INTRO_TIMEOUT 1200
#endif // DEFERRED_EXEC_ENABLE

#include "plodah.h"
