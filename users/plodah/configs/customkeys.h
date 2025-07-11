#pragma once

// TAPDANCES
#ifdef TAP_DANCE_ENABLE
  #define P_RAGEQ TD(TD_ESC_RAGEQUIT)
  #define P_F2 TD(TD_F2)
  #define P_F4 TD(TD_F4)
  #define P_F5 TD(TD_F5)
  #define P_F11 TD(TD_F11)
  #define P_F12 TD(TD_F12)
#else // TAP_DANCE_ENABLE
  #define P_RAGEQ KC_ESC
  #define P_F2 KC_2
  #define P_F4 KC_4
  #define P_F5 KC_5
  #define P_F11 KC_MINS
  #define P_F12 KC_EQL
#endif // TAP_DANCE_ENABLE

// "Function" KEYS
#define P_SPCFA LT(_FNA, KC_SPC)
#define P_SPCFB LT(_FNB, KC_SPC)
#define P_SPCSP LT(_SUPP, KC_SPC)
#define P_APPFA LT(_FNA, KC_APP)
#define P_APPFB LT(_FNB, KC_APP)
#define P_BSPFA LT(_FNA, KC_BSPC)
#define P_BSPFB LT(_FNB, KC_BSPC)
#define P_ENTFA LT(_FNA, KC_ENT)
#define P_ENTFB LT(_FNB, KC_ENT)
#define P_HOMFC LT(_FNC, KC_HOME)
#define P_ENDFC LT(_FNC, KC_END)
#define P_FNA MO(_FNA)
#define P_FNB MO(_FNB)
#define P_FNC MO(_FNC)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)

// ModTaps
#define P_DOTAL MT(MOD_RALT,KC_PDOT)
#define P_BSCTL LCTL_T(KC_BSPC)
#define P_SLSFT RSFT_T(KC_SLSH)
#define P_APPAL RALT_T(KC_APP)
#define P_RSFTB RSFT_T(KC_BSPC)

// GENERAL SHORTCUTS
#define P_SALL C(KC_A)
#define P_COPY C(KC_C)
#define P_CUT  C(KC_X)
#define P_PAST C(KC_V)
#define P_PSTU C(S(KC_V))
#define P_PSTM G(KC_V)
#define P_UNDO C(KC_Z)
#define P_REDO C(KC_Y)
#define P_TASK G(KC_TAB)
#define P_XWIN A(KC_F4)
#define P_XTAB C(KC_F4)
#define P_NTAB C(KC_TAB)

// #define P_RTAB C(S(KC_T))
// #define P_PTAB C(S(KC_TAB))
#define P_RTAB C(KC_PGUP)
#define P_PTAB C(KC_PGDN)
#define P_TMGR LCA(KC_DEL)

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

// BOTTOM ROW MODS (QWERTY)
#define BRM_ZG LGUI_T(KC_Z)
#define BRM_XA LALT_T(KC_X)
#define BRM_CS LSFT_T(KC_C)
#define BRM_VC LCTL_T(KC_V)
#define BRM_BG LGUI_T(KC_B)

#define BRM_NG RGUI_T(KC_N)
#define BRM_MC RCTL_T(KC_M)
#define BRM_COS RSFT_T(KC_COMM)
#define BRM_DOA RALT_T(KC_DOT)
#define BRM_SLG RGUI_T(KC_SLSH)

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

// Z ROW MODS (COLEMAK)
// #define BRM_ZG LGUI_T(KC_Z) // SAME AS QWERTY
// #define BRM_XA LALT_T(KC_X) // SAME AS QWERTY
// #define BRM_CS LSFT_T(KC_C) // SAME AS QWERTY
// #define BRM_VC LCTL_T(KC_V) // SAME AS QWERTY
// #define BRM_BG LGUI_T(KC_B) // SAME AS QWERTY

#define BRM_KG RGUI_T(KC_K)
// #define BRM_MC RCTL_T(KC_M) // SAME AS QWERTY
// #define BRM_COS RSFT_T(KC_COMM) // SAME AS QWERTY
// #define BRM_DOA RALT_T(KC_DOT) // SAME AS QWERTY
// #define BRM_SLG RGUI_T(KC_SLSH) // SAME AS QWERTY

// POINTING DEVICES
#define P_MS4FA LT(_FNA, KC_BTN4)
#define P_MS5FA LT(_FNA, KC_BTN5)
#define P_MS5FB LT(_FNB, KC_BTN5)
#define P_DRGTD TD(TD_DRAGSCROLL)
#define P_DRGMO TD(TD_DRAGSCROLL)
#define P_DRGTG BETTER_DRAG_SCROLL_SNIPER_A_TOGGLE

#define P_SNMOA BETTER_DRAG_SCROLL_SNIPER_A_MOMENTARY
#define P_SNTGA BETTER_DRAG_SCROLL_SNIPER_A_TOGGLE
#define P_SNMOB BETTER_DRAG_SCROLL_SNIPER_B_MOMENTARY
#define P_SNTGB BETTER_DRAG_SCROLL_SNIPER_B_TOGGLE
#define P_DRGVL BETTER_DRAG_VOLUME_MOMENTARY
