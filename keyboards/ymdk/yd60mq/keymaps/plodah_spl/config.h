#pragma once
#include "plodah.h"

#define KC_PL_QFTR
#define KC_PL_QRGB
#define KC_PL_QVER

#define PLODAH_BORING_LAYER 1

/* ------- RGB LIGHTING ------- */
#ifdef RGBLIGHT_ENABLE
  #include "configs/rgblight-effects-none.h"
#endif // RGBLIGHT_ENABLE
