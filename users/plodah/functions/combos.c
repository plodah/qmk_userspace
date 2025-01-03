#if defined(COMBO_ENABLE)
  #pragma once
  #if defined(IS_MOUSE)

    const uint16_t PROGMEM pl_combo_ms12[] = {KC_BTN1 , KC_BTN2, COMBO_END};
    const uint16_t PROGMEM pl_combo_ms14[] = {KC_BTN1 , KC_BTN4, COMBO_END};
    const uint16_t PROGMEM pl_combo_ms15[] = {KC_BTN1 , KC_BTN5, COMBO_END};
    const uint16_t PROGMEM pl_combo_ms24[] = {KC_BTN2 , KC_BTN4, COMBO_END};
    const uint16_t PROGMEM pl_combo_ms25[] = {KC_BTN2 , KC_BTN5, COMBO_END};
    const uint16_t PROGMEM pl_combo_ms45[] = {KC_BTN4 , KC_BTN5, COMBO_END};

    combo_t key_combos[] = {
      COMBO(pl_combo_ms12,  DRAG_SCROLL),
      COMBO(pl_combo_ms14,  PL_MSJG),
      COMBO(pl_combo_ms15,  C(KC_C)),
      COMBO(pl_combo_ms24,  DRAG_SCROLL),
      COMBO(pl_combo_ms25,  C(KC_V)),
      COMBO(pl_combo_ms45,  PL_MSJG),
    };

  #else // not IS_MOUSE

    const uint16_t PROGMEM pl_combo_qwop[]  = {KC_Q,    KC_W,    KC_O,    KC_P,    COMBO_END};
    const uint16_t PROGMEM pl_combo_qa[]    = {KC_Q,    KC_A,                      COMBO_END};
    const uint16_t PROGMEM pl_combo_rt[]    = {KC_R,    KC_T,                      COMBO_END};
    const uint16_t PROGMEM pl_combo_ert[]   = {KC_E,    KC_R,    KC_T,             COMBO_END};
    const uint16_t PROGMEM pl_combo_as[]    = {KC_A,    KC_S,                      COMBO_END};
    const uint16_t PROGMEM pl_combo_bsz[]   = {KC_NUBS, KC_Z,                      COMBO_END};
    const uint16_t PROGMEM pl_combo_zx[]    = {KC_Z,    KC_X,                      COMBO_END};
    const uint16_t PROGMEM pl_combo_xc[]    = {KC_X,    KC_C,                      COMBO_END};
    const uint16_t PROGMEM pl_combo_cv[]    = {KC_C,    KC_V,                      COMBO_END};
    const uint16_t PROGMEM pl_combo_xcv[]   = {KC_X,    KC_C,    KC_V,             COMBO_END};
    const uint16_t PROGMEM pl_combo_89[]    = {KC_8,    KC_9,                      COMBO_END};
    const uint16_t PROGMEM pl_combo_90[]    = {KC_9,    KC_0,                      COMBO_END};

    #if defined(PLODAH_HRM_COMBOS)
      const uint16_t PROGMEM pl_combo_as_hrm[]       = {KC_A ,   LALT_T(KC_S), COMBO_END};
      const uint16_t PROGMEM pl_combo_bsz_hrm[]      = {KC_NUBS, LGUI_T(KC_Z), COMBO_END};
      const uint16_t PROGMEM pl_combo_bsz2_hrm[]     = {KC_LSFT, KC_Z,         COMBO_END};
      const uint16_t PROGMEM pl_combo_bsz3_hrm[]     = {KC_LSFT, LGUI_T(KC_Z), COMBO_END};
      const uint16_t PROGMEM pl_combo_zx_hrm[]       = {LGUI_T(KC_Z) , KC_X, COMBO_END};
    #endif // PLODAH_HRM_COMBOS

    #if defined(PLODAH_ALTTAB_ENHANCEMENTS_ENABLE)
      const uint16_t PROGMEM pl_combo_tabq[] = {KC_TAB , KC_Q , COMBO_END};
      const uint16_t PROGMEM pl_combo_tabw[] = {KC_TAB , KC_W , COMBO_END};
    #endif // PLODAH_ALTTAB_ENHANCEMENTS_ENABLE

    #if defined(DYNAMIC_MACRO_ENABLE)
      const uint16_t PROGMEM pl_combo_12[] = {KC_1 , KC_2, COMBO_END};
      const uint16_t PROGMEM pl_combo_13[] = {KC_1 , KC_3, COMBO_END};
      const uint16_t PROGMEM pl_combo_qw[] = {KC_Q , KC_W, COMBO_END};
      const uint16_t PROGMEM pl_combo_qe[] = {KC_Q , KC_E, COMBO_END};
      const uint16_t PROGMEM pl_combo_3e[] = {KC_3 , KC_E, COMBO_END};
    #endif // DYNAMIC_MACRO_ENABLE

    #ifdef CONSOLE_ENABLE
      const uint16_t PROGMEM pl_combo_db[] = {KC_D , KC_B, COMBO_END};
    #endif // CONSOLE_ENABLE

    combo_t key_combos[] = {
      COMBO(pl_combo_qwop,  QK_BOOT    ),
      COMBO(pl_combo_qa,    C(KC_A)    ),
      COMBO(pl_combo_rt,    C(KC_T)    ),
      COMBO(pl_combo_ert,   C(S(KC_T)) ),
      COMBO(pl_combo_as,    C(KC_S)    ),
      COMBO(pl_combo_bsz,   C(KC_Z)    ),
      COMBO(pl_combo_zx,    C(KC_X)    ),
      COMBO(pl_combo_xc,    C(KC_C)    ),
      COMBO(pl_combo_cv,    C(KC_V)    ),
      COMBO(pl_combo_xcv,   C(S(KC_V)) ),
      COMBO(pl_combo_89,    KC_MINS    ),
      COMBO(pl_combo_90,    KC_EQL     ),

    #if defined(PLODAH_HRM_COMBOS)
      COMBO(pl_combo_as_hrm,    C(KC_S)),
      COMBO(pl_combo_bsz_hrm,   C(KC_Z)),
      COMBO(pl_combo_bsz2_hrm,  C(KC_Z)),
      COMBO(pl_combo_bsz3_hrm,  C(KC_Z)),
      COMBO(pl_combo_zx_hrm,    C(KC_X)),
    #endif // PLODAH_HRM_COMBOS

      #if defined(PLODAH_ALTTAB_ENHANCEMENTS_ENABLE)
        COMBO(pl_combo_tabq,    PL_ALTSTAB),
        COMBO(pl_combo_tabw,    PL_ALTTAB),
      #endif // PLODAH_ALTTAB_ENHANCEMENTS_ENABLE

      #if defined(DYNAMIC_MACRO_ENABLE)
        COMBO(pl_combo_12,    DM_PLY1),
        COMBO(pl_combo_13,    DM_REC1),
        COMBO(pl_combo_qw,    DM_PLY2),
        COMBO(pl_combo_qe,    DM_REC2),
        COMBO(pl_combo_3e,    DM_RSTP),
      #endif // DYNAMIC_MACRO_ENABLE

      #ifdef CONSOLE_ENABLE
        COMBO(pl_combo_db,    DB_TOGG),
      #endif // CONSOLE_ENABLE

    };

  #endif // IS_MOUSE

  #if defined(PLODAH_BORING_LAYER )
    bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
      if(layer_state_is(PLODAH_BORING_LAYER)){
        return false;
      }
      return true;
    }
  #endif // PLODAH_BORING_LAYER

#endif // COMBO_ENABLE
