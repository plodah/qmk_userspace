/* Copyright 2025 Plodah
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

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _FNA,
    _FNB,
};

enum keymap_keycodes {
    KB_DPI_CONFIG       = QK_KB_0,
    KB_DRAG_SCROLL,
    BETTER_DRAG_SCROLL_MOMENTARY,
    BETTER_DRAG_SCROLL_TOGGLE,
    PL_MSJG,
    PL_TSKN,
    PL_TSKP,
    BETTER_DRAG_SCROLL_SNIPER_A_MOMENTARY,
    BETTER_DRAG_SCROLL_SNIPER_A_TOGGLE,
    BETTER_DRAG_SCROLL_SNIPER_B_MOMENTARY,
    BETTER_DRAG_SCROLL_SNIPER_B_TOGGLE,
    BETTER_DRAG_VOLUME_MOMENTARY,
};

enum {
    TD_DRAGSCROLL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        MS_BTN1, MS_BTN3, P_MS4FA, MS_BTN2, P_MS5FB
    ),
    [_FNA] = LAYOUT(
        _______, DPI_CONFIG, _______, PL_TSKP, PL_TSKN
    ),
    [_FNB] = LAYOUT(
        _______, _______, _______, _______, _______
    )
};
