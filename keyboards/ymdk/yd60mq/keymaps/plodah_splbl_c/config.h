#pragma once
#include "plodah.h"

#define PLODAH_FEAT_KC
#define PLODAH_QRGB_KC

#ifdef PRODUCT
# undef PRODUCT
# define PRODUCT "YMDK yd60mq | plodah_splbl"
#endif // PRODUCT

#define PLODAH_BORING_LAYER 1
#define BOOTMAGIC_ROW 0
#define BOOTMAGIC_COLUMN 0

#ifdef DYNAMIC_KEYMAP_LAYER_COUNT
#  undef DYNAMIC_KEYMAP_LAYER_COUNT
#endif
#define DYNAMIC_KEYMAP_LAYER_COUNT 5

/* ------- RGB LIGHTING ------- */
#ifdef RGBLIGHT_ENABLE
#  include "configs/rgblight-effects-none.h"
#endif // RGBLIGHT_ENABLE
