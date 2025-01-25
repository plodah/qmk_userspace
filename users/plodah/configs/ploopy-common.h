
#define IS_MOUSE
#define PLODAH_ALTTAB_ENHANCEMENTS_ENABLE

#if defined(DEFERRED_EXEC_ENABLE)
  #define PLODAH_MSJIGGLER_ENABLED
  #define PLODAH_MSJIGGLER_INTRO
  // #define PLODAH_MSJIGGLER_INTRO_TIMEOUT 1200
  // #define PLODAH_MSJIGGLER_PATTERN 1
  // #define PLODAH_MSJIGGLER_AUTOSTOP
  #define PLODAH_MSJIGGLER_INDICATOR_RGBINDEX 43
  #define PLODAH_MSJIGGLER_INDICATOR_HSV 0x0B, 0xFF, 0xFF
#endif // DEFERRED_EXEC_ENABLE

#define KC_PL_QFTR
// #define KC_PL_QLYR
#define KC_PL_QRGB
#define KC_PL_QVER

#ifdef PLOOPY_SCROLL_BUTTON_DEBOUNCE
  #undef PLOOPY_SCROLL_BUTTON_DEBOUNCE
#endif
#define PLOOPY_SCROLL_BUTTON_DEBOUNCE 50

#ifdef PLOOPY_SCROLL_DEBOUNCE
  #undef PLOOPY_SCROLL_DEBOUNCE
#endif
#define PLOOPY_SCROLL_DEBOUNCE 10

#ifdef PLOOPY_IGNORE_SCROLL_CLICK
  #undef PLOOPY_IGNORE_SCROLL_CLICK
#endif
#define PLOOPY_IGNORE_SCROLL_CLICK

#ifdef PLOOPY_DPI_OPTIONS
  #undef PLOOPY_DPI_OPTIONS
#endif
#define PLOOPY_DPI_OPTIONS { 300, 433, 567, 700 }

#ifdef PLOOPY_DPI_DEFAULT
  #undef PLOOPY_DPI_DEFAULT
#endif
#define PLOOPY_DPI_DEFAULT 1

#ifdef PLOOPY_DRAGSCROLL_INVERT
  #undef PLOOPY_DRAGSCROLL_INVERT
#endif
#define PLOOPY_DRAGSCROLL_INVERT 1

#ifdef PLOOPY_DRAGSCROLL_MOMENTARY
  #undef PLOOPY_DRAGSCROLL_MOMENTARY
#endif
#define PLOOPY_DRAGSCROLL_MOMENTARY 1

#ifdef PLOOPY_DRAGSCROLL_DIVISOR_H
  #undef PLOOPY_DRAGSCROLL_DIVISOR_H
#endif
#define PLOOPY_DRAGSCROLL_DIVISOR_H 4

#ifdef PLOOPY_DRAGSCROLL_DIVISOR_V
  #undef PLOOPY_DRAGSCROLL_DIVISOR_V
#endif
#define PLOOPY_DRAGSCROLL_DIVISOR_V 4

/* ------- RGB LIGHTING ------- */
#ifdef RGBLIGHT_ENABLE
  #include "configs/rgblight-effects-none.h"
#endif // RGBLIGHT_ENABLE
