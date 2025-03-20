#pragma once

#define PLOOPY_VIAMENUS // needs to be before common
#include "configs/ploopy-common.h"

#define CM_QFTR_DISABLED
#define CM_QLYR_DISABLED
#define CM_QTAP_DISABLED
// #define CM_QVER_DISABLED
#define CM_QRGB_DISABLED

#define BETTER_DRAGSCROLL_TAPDANCE

#ifdef PLOOPY_SCROLL_DEBOUNCE
  #undef PLOOPY_SCROLL_DEBOUNCE
#endif
#define PLOOPY_SCROLL_DEBOUNCE 6

#include "plodah.h"
