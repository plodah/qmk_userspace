/* Copyright 2021 Colin Lam (Ploopy Corporation)
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifdef PLOOPY_SCROLL_DEBOUNCE
#  undef PLOOPY_SCROLL_DEBOUNCE
#endif
#define PLOOPY_SCROLL_DEBOUNCE 5

#ifdef PLOOPY_SCROLL_BUTTON_DEBOUNCE
#  undef PLOOPY_SCROLL_BUTTON_DEBOUNCE
#endif
#define PLOOPY_SCROLL_BUTTON_DEBOUNCE 50

#ifdef PLOOPY_DPI_OPTIONS
#  undef PLOOPY_DPI_OPTIONS
#endif
#define PLOOPY_DPI_OPTIONS { 300, 450, 600, 750 }

#ifdef PLOOPY_DPI_DEFAULT
#  undef PLOOPY_DPI_DEFAULT
#endif
#define PLOOPY_DPI_DEFAULT 1

#ifdef PLOOPY_DRAGSCROLL_FIXED
#  undef PLOOPY_DRAGSCROLL_FIXED
#endif
#define PLOOPY_DRAGSCROLL_FIXED 1

#ifdef PLOOPY_DRAGSCROLL_DPI
#  undef PLOOPY_DRAGSCROLL_DPI
#endif
//#define PLOOPY_DRAGSCROLL_DPI 75

#ifdef PLOOPY_DRAGSCROLL_DIVISOR_H
#  undef PLOOPY_DRAGSCROLL_DIVISOR_H
#endif
#define PLOOPY_DRAGSCROLL_DIVISOR_H 8

#ifdef PLOOPY_DRAGSCROLL_DIVISOR_V
#  undef PLOOPY_DRAGSCROLL_DIVISOR_V
#endif
#define PLOOPY_DRAGSCROLL_DIVISOR_V 8

#ifdef PLOOPY_DRAGSCROLL_MOMENTARY
#  undef PLOOPY_DRAGSCROLL_MOMENTARY
#endif
#define PLOOPY_DRAGSCROLL_MOMENTARY 1

#ifdef PLOOPY_DRAGSCROLL_INVERT
#  undef PLOOPY_DRAGSCROLL_INVERT
#endif
#define PLOOPY_DRAGSCROLL_INVERT 1
