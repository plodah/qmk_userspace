#pragma once

// TAPDANCES
#define P_RAGEQ TD(TD_ESC_RAGEQUIT)
#define P_F2 TD(TD_F2)
#define P_F4 TD(TD_F4)
#define P_F5 TD(TD_F5)
#define P_F11 TD(TD_F11)
#define P_F12 TD(TD_F12)

// "Function" KEYS
#define P_SPCFA LT(_FNA, KC_SPC)
#define P_SPCFB LT(_FNA, KC_SPC)
#define P_SPCSP LT(_SUPP, KC_SPC)
#define P_APPFA LT(_FNA, KC_APP)
#define P_APPFB LT(_FNB, KC_APP)
#define P_BSPFA LT(_FNA, KC_BSPC)
#define P_BSPFB LT(_FNB, KC_BSPC)
#define P_ENTFB LT(_FNB, KC_ENT)
#define P_FNA MO(_FNA)
#define P_FNB MO(_FNB)

// GENERAL SHORTCUTS
#define P_COPY C(KC_C)
#define P_PAST C(KC_V)
#define P_PSTU C(S(KC_V))
#define P_TASK G(KC_TAB)
#define P_XWIN A(KC_F4)
#define P_XTAB C(KC_F4)
#define P_NTAB C(KC_TAB)

#define P_RTAB C(S(KC_T))
#define P_PTAB C(S(KC_TAB))
#define P_TMGR LCA(KC_DEL)

#define P_ALAPP RALT_T(KC_APP)
#define P_SFTSL RSFT_T(KC_SLSH)
#define P_RSFTB RSFT_T(KC_BSPC)

// HOME ROW MODS (QWERTY)
#define HRM_AG LGUI_T(KC_A)
#define HRM_SA LALT_T(KC_S)
#define HRM_DS LSFT_T(KC_D)
#define HRM_FC LCTL_T(KC_F)
#define HRM_GG LGUI_T(KC_G)

#define HRM_HG RGUI_T(KC_H)
#define HRM_JC RCTL_T(KC_J)
#define HRM_KS RSFT_T(KC_K)
#define HRM_LA RALT_T(KC_L)
#define HRM_CG RGUI_T(KC_SCLN)

// HOME ROW MODS (COLEMAK)
// #define HRM_AG LGUI_T(KC_A) // SAME AS QWERTY
#define HRM_RA LALT_T(KC_R)
#define HRM_SS LSFT_T(KC_S)
#define HRM_TC LCTL_T(KC_T)
#define HRM_DG LGUI_T(KC_D)
// #define HRM_HG RGUI_T(KC_H) // SAME AS QWERTY
#define HRM_NC RCTL_T(KC_N)
#define HRM_ES RSFT_T(KC_E)
#define HRM_IA RALT_T(KC_I)
#define HRM_OG RGUI_T(KC_O)

// HOME ROW MODS (ADDITIONAL WINKEYS)
#define HRM_ZG LGUI_T(KC_Z)
#define HRM_SLG RGUI_T(KC_SLSH)

// POINTING DEVICES
#define P_MS4FA LT(_FNA, KC_BTN4)
#define P_MS5FA LT(_FNA, KC_BTN5)
#define P_MS5FB LT(_FNB, KC_BTN5)
#define P_DRGTD TD(TD_DRAGSCROLL)
#define P_DRGMO TD(TD_DRAGSCROLL)
#define P_DRGTG PL_DRAG_SCROLL_TOGGLE

// Half Rows
//      _______, _______, _______, _______, _______
#define ___________________________________________ _______, _______, _______, _______, _______
#define ___________________12345___________________ KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ___________________F12345__________________ KC_1,    P_F2,    KC_3,    P_F4,    P_F5
#define ___________________67890___________________ KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define ___________________QWERT___________________ KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define ___________________YUIOP___________________ KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define ___________________ASDFG___________________ KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define ___________________HJKL____________________ KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define ___________________ZXCVB___________________ KC_Z,    KC_X,    KC_C,    KC_V,    KC_B
#define __________________NM_SLSH__________________ KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH
#define __________________NM_DOT__________          KC_N,    KC_M,    KC_COMM, KC_DOT

#define _________________HRM_ASDFG_________________ HRM_AG,  HRM_SA,  HRM_DS,  HRM_FC,  HRM_GG
#define _________________HRM_ASDF__________________ HRM_AG,  HRM_SA,  HRM_DS,  HRM_FC,  KC_G
#define _________________HRM_SDFG__________________ KC_A,    HRM_SA,  HRM_DS,  HRM_FC,  HRM_GG
#define ________________HRM_HJKLC__________________ HRM_HG,  HRM_JC,  HRM_KS,  HRM_LA,  HRM_SLG
#define _________________HRM_HJKL__________________ HRM_HG,  HRM_JC,  HRM_KS,  HRM_LA,  KC_SCLN
#define ________________H_HRM_JKLC_________________ KC_H,    HRM_JC,  HRM_KS,  HRM_LA,  KC_SCLN
#define ________________HRM_Z_XCVB_________________ HRM_ZG,  KC_X,    KC_C,    KC_V,    KC_B
#define ________________NM_HRMPUNCT________________ KC_N,    KC_M,    KC_COMM, KC_DOT,  HRM_CG
