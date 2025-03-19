#pragma once

#define PLOOPY_VIAMENUS // needs to be before common
#include "configs/ploopy-common.h"

#define BETTER_DRAGSCROLL_TAPDANCE

#ifdef PLOOPY_DPI_OPTIONS
  #undef PLOOPY_DPI_OPTIONS
#endif
#define PLOOPY_DPI_OPTIONS { 1000, 1250, 1500, 2000, 2500 }
#ifdef PLOOPY_DPI_DEFAULT
  #undef PLOOPY_DPI_DEFAULT
#endif
#define PLOOPY_DPI_DEFAULT 2

#ifdef PLOOPY_DRAGSCROLL_DIVISOR_H
  #undef PLOOPY_DRAGSCROLL_DIVISOR_H
#endif
#define PLOOPY_DRAGSCROLL_DIVISOR_H 8

#ifdef PLOOPY_DRAGSCROLL_DIVISOR_V
  #undef PLOOPY_DRAGSCROLL_DIVISOR_V
#endif
#define PLOOPY_DRAGSCROLL_DIVISOR_V 8

#include "plodah.h"
