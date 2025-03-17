#pragma once

#include "configs/ploopy-common.h"

#define BETTER_DRAGSCROLL_TAPDANCE

#ifdef PLOOPY_SCROLL_DEBOUNCE
  #undef PLOOPY_SCROLL_DEBOUNCE
#endif
#define PLOOPY_SCROLL_DEBOUNCE 6

#include "plodah.h"
