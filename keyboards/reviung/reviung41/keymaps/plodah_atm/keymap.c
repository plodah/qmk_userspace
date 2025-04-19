/* Copyright 2020 gtips
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

enum layer_names {
    _QWEA,
    _FNA,
    _FNB,
    _FNC,
};

enum {
    TD_ESC_RAGEQUIT,
    TD_F2,
    TD_F4,
    TD_F5,
    TD_F11,
    TD_F12,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWEA] = LAYOUT(
        P_RAGEQ, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    HRM_SA,  HRM_DS,  HRM_FC,  HRM_GG,           HRM_HG,  HRM_JC,  HRM_KS,  HRM_LA,  KC_SCLN, KC_QUOT,
        KC_NUBS, ZRM_ZG,  ZRM_XA,  ZRM_CS,  ZRM_VC,  KC_B,             KC_N,    ZRM_MC,  ZRM_COS, ZRM_DOA, ZRM_SLG, KC_NUHS,
                                            P_HOMFC, P_ENTFB, P_SPCFA, P_ENTFB, KC_END
      ),

  [_FNA] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    KC_BSPC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS,
    _______, KC_MINS, KC_EQL,  _______, KC_LCBR, KC_LBRC,          KC_RBRC, KC_RCBR, _______, _______, _______, CW_TOGG,
                                        _______, _______, _______, _______, _______
  ),

  [_FNB] = LAYOUT(
    _______, _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP,          KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_PSCR, KC_ESC,
    KC_DEL,  _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,          KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_PIPE,
    _______, KC_UNDS, KC_PLUS, _______, _______, _______,          _______, _______, _______, _______, _______, CW_TOGG,
                                        _______, _______, _______, _______, _______
  ),

  [_FNC] = LAYOUT(
    KC_CAPS, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),          S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), _______,
    KC_VOLU, XXXXXXX, PL_SCRL, MS_BTN2, MS_BTN1, MS_BTN3,          XXXXXXX, KC_LCTL, KC_LSFT, KC_LALT, QK_MAKE, KC_VOLU,
    KC_VOLD, _______, XXXXXXX, MS_BTN4, MS_BTN5, PL_SCRL,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD,
                                        _______, _______, _______, _______, _______
  ),

};

layer_state_t layer_state_set_user(layer_state_t state) {
  // return update_tri_layer_state(state, _FNA, _FNB, _FNC);
  // layer_state_t mask123 = ((layer_state_t)1 << _FNA) | ((layer_state_t)1 << _FNB) | ((layer_state_t)1 << _FNC);
  layer_state_t mask12 = ((layer_state_t)1 << _FNA) | ((layer_state_t)1 << _FNB);
  // layer_state_t mask1 = (layer_state_t)1 << _FNA;
  // layer_state_t mask2 = (layer_state_t)1 << _FNB;
  layer_state_t mask3 = (layer_state_t)1 << _FNC;
  // layer_state_t returnstate = state;

  if((state & mask12) == mask12){
    dprintf("tril 3 on \n");
    return state | mask3;
  }
  else if(state & mask12){
    dprintf("tril 3 off \n");
    return state & ~mask3;
  }
   return state;
}

char chordal_hold_handedness(keypos_t key) {
    char answer='*';
    switch(key.row){
        case 0:
        case 1:
        case 2:
            answer='L';
            break;
        case 3:
        case 4:
        case 5:
            answer='R';
            break;
        case 6:
            switch(key.col){
                case 0:
                case 1:
                    answer='L';
                    break;
                case 2:
                    answer='*';
                    break;
                case 3:
                case 4:
                    answer='R';
                    break;
            }
    }
    dprintf("CH Hand %u:%u %c\n", key.row, key.col, answer);
    return answer;
}
