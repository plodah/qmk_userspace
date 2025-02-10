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

/*

#define P_RAGEQ TD(TD_ESC_RAGEQUIT)
#define P_F2 TD(TD_F2)
#define P_F4 TD(TD_F4)
#define P_F5 TD(TD_F5)
#define P_F11 TD(TD_F11)
#define P_F12 TD(TD_F12)

#define P_SPCFA LT(_FNA, KC_SPC)
#define P_SPCFB LT(_FNB, KC_SPC)
#define P_BSPFB LT(_FNB, KC_BSPC)
#define P_APPFB LT(_FNB, KC_APP)
#define P_FNB MO(_FNB)

#define P_PSTU C(S(KC_V))
#define P_RTAB C(S(KC_T))
#define P_XTAB C(KC_F4)
#define P_TASK G(KC_TAB)
#define P_CAD LCA(KC_DEL)
#define P_RSSLS RSFT_T(KC_SLSH)

#define HRM_SA LALT_T(KC_S)
#define HRM_DS LSFT_T(KC_D)
#define HRM_FC LCTL_T(KC_F)
#define HRM_GG LGUI_T(KC_G)
#define HRM_HG RGUI_T(KC_H)
#define HRM_JC RCTL_T(KC_J)
#define HRM_KS RSFT_T(KC_K)
#define HRM_LA RALT_T(KC_L)

#define P_RAGEQ TD(TD_ESC_RAGEQUIT)
*/
