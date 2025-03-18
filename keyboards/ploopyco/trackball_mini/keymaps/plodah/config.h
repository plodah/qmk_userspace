#pragma once

#include "configs/ploopy-common.h"

#define PLODAH_VIADPI
#define VIA_EEPROM_CUSTOM_CONFIG_SIZE 9

#define BETTER_DRAGSCROLL_TAPDANCE

#ifdef PLOOPY_SCROLL_DEBOUNCE
  #undef PLOOPY_SCROLL_DEBOUNCE
#endif
#define PLOOPY_SCROLL_DEBOUNCE 6

#include "plodah.h"
