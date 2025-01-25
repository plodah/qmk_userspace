#pragma once

#include "configs/ploopy-common.h"

#ifdef PLOOPY_DPI_OPTIONS
  #undef PLOOPY_DPI_OPTIONS
#endif
#define PLOOPY_DPI_OPTIONS { 1000, 1200, 1500, 1800, 2100 }

#ifdef PLOOPY_DRAGSCROLL_DIVISOR_H
  #undef PLOOPY_DRAGSCROLL_DIVISOR_H
#endif
#define PLOOPY_DRAGSCROLL_DIVISOR_H 8

#ifdef PLOOPY_DRAGSCROLL_DIVISOR_V
  #undef PLOOPY_DRAGSCROLL_DIVISOR_V
#endif
#define PLOOPY_DRAGSCROLL_DIVISOR_V 8

#include "plodah.h"
