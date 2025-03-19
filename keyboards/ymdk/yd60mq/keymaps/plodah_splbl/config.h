#pragma once

// #define CM_QFTR_DISABLED
#define CM_QLYR_DISABLED
#define CM_QTAP_DISABLED
// #define CM_QVER_DISABLED
// #define CM_QRGB_DISABLED

#define PLODAH_BORING_LAYER 1

/* ------- RGB LIGHTING ------- */
#ifdef RGBLIGHT_ENABLE
  #include "configs/rgblight-effects-none.h"
#endif // RGBLIGHT_ENABLE

#include "plodah.h"
