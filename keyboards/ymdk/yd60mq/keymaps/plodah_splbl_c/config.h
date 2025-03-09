#pragma once

#if defined COMMUNITY_MODULE_CONFIG_QUERY_ENABLE
    // #define CM_QFTR_DISABLED
    #define CM_QLYR_DISABLED
    #define CM_QTAP_DISABLED
    // #define CM_QVER_DISABLED
    // #define CM_QRGB_DISABLED
#endif // COMMUNITY_MODULE_CONFIG_QUERY_ENABLE

#ifdef PRODUCT
  #undef PRODUCT
#endif // PRODUCT
#define PRODUCT "YMDK yd60mq | plodah_splbl"

#define ACHORDION_ENABLE
#define ACHORDION_STREAK

#define PLODAH_BORING_LAYER 1
#define BOOTMAGIC_ROW 0
#define BOOTMAGIC_COLUMN 0

#ifdef DYNAMIC_KEYMAP_LAYER_COUNT
  #undef DYNAMIC_KEYMAP_LAYER_COUNT
#endif
#define DYNAMIC_KEYMAP_LAYER_COUNT 5

/* ------- RGB LIGHTING ------- */
#ifdef RGBLIGHT_ENABLE
  #include "configs/rgblight-effects-none.h"
#endif // RGBLIGHT_ENABLE

#include "plodah.h"
