#pragma once

#define PLODAH_FEAT_KC
#define PLODAH_QRGB_KC

#ifdef PRODUCT
  #undef PRODUCT
#endif // PRODUCT
#define PRODUCT "dztech/dz60v2 | plodahc"

#define PLODAH_BORING_LAYER 1

#define PLODAH_MSJIGGLER_ENABLED

#define BOOTMAGIC_ROW 0
#define BOOTMAGIC_COLUMN 0

#ifdef DYNAMIC_KEYMAP_LAYER_COUNT
  #undef DYNAMIC_KEYMAP_LAYER_COUNT
#endif
#define DYNAMIC_KEYMAP_LAYER_COUNT 5

#include "plodah.h"
