#pragma once

#define PLODAH_VIADPI

#include "configs/ploopy-common.h"

#ifdef PRODUCT
  #undef PRODUCT
#endif // PRODUCT
#define PRODUCT "PloopyCo Thumb | plodah"

#include "plodah.h"
