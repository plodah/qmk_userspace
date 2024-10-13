#pragma once
#include "plodah.h"

#define PLODAH_FEAT_KC
#define PLODAH_QRGB_KC

#define PLODAH_BORING_LAYER 1

/* ------- RGB LIGHTING ------- */
#ifdef RGBLIGHT_ENABLE
  #include "configs/rgblight-effects-none.h"
#endif // RGBLIGHT_ENABLE
