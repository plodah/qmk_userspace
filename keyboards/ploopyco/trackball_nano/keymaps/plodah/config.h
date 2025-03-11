#pragma once

#include "configs/ploopy-common.h"

#define PLOOPY_DRAGSCROLL_SCRLK_ENABLE
// #define PLODAH_MSGESTURE_ENABLE

#ifdef PLOOPY_DPI_OPTIONS
  #undef PLOOPY_DPI_OPTIONS
#endif
#define PLOOPY_DPI_OPTIONS { 225 }

#ifdef PLOOPY_DPI_DEFAULT
  #undef PLOOPY_DPI_DEFAULT
#endif
#define PLOOPY_DPI_DEFAULT 0

#ifdef PLOOPY_DRAGSCROLL_INVERT
  #undef PLOOPY_DRAGSCROLL_INVERT
#endif
#define PLOOPY_DRAGSCROLL_INVERT 1

#ifdef PLOOPY_DRAGSCROLL_DIVISOR_V
  #undef PLOOPY_DRAGSCROLL_DIVISOR_V
#endif
#define PLOOPY_DRAGSCROLL_DIVISOR_V 8

#ifdef PLOOPY_DRAGSCROLL_DIVISOR_H
  #undef PLOOPY_DRAGSCROLL_DIVISOR_H
#endif
#define PLOOPY_DRAGSCROLL_DIVISOR_H 8

#ifdef PLODAH_DRAGSCROLL_INVERT
  #undef PLODAH_DRAGSCROLL_INVERT
#endif
#define PLODAH_DRAGSCROLL_INVERT 1

#ifdef PLODAH_DRAGSCROLL_DIVISOR_V
  #undef PLODAH_DRAGSCROLL_DIVISOR_V
#endif
#define PLODAH_DRAGSCROLL_DIVISOR_V 8

#ifdef PLODAH_DRAGSCROLL_DIVISOR_H
  #undef PLODAH_DRAGSCROLL_DIVISOR_H
#endif
#define PLODAH_DRAGSCROLL_DIVISOR_H 8

#include "plodah.h"
