#pragma once

// ##########################################
// ##                TOP ROW               ##
// ##########################################
#if ! defined(PLODAH_COMBOS_LIMITED)
    const uint16_t PROGMEM pl_combo_0bsp[]   = {KC_0,     KC_BSPC,                COMBO_END};
    const uint16_t PROGMEM pl_combo_eqbsp[]  = {KC_EQL,   KC_BSPC,                COMBO_END};

    const uint16_t PROGMEM pl_combo_qwop[]   = {KC_Q,     KC_W,   KC_O,   KC_P,   COMBO_END};
    const uint16_t PROGMEM pl_combo_wr[]     = {KC_W,     KC_R,                   COMBO_END};
    const uint16_t PROGMEM pl_combo_et[]     = {KC_E,     KC_T,                   COMBO_END};
    const uint16_t PROGMEM pl_combo_ert[]    = {KC_E,     KC_R,   KC_T,           COMBO_END};
    const uint16_t PROGMEM pl_combo_ip[]     = {KC_I,     KC_P,                   COMBO_END};

    const uint16_t PROGMEM pl_combo_capa[]   = {P_BSPFA,  KC_A,                   COMBO_END};
    const uint16_t PROGMEM pl_combo_capa2[]  = {P_BSPFB,  KC_A,                   COMBO_END};
    const uint16_t PROGMEM pl_combo_capa3[]  = {KC_NUBS,  KC_A,                   COMBO_END};
    const uint16_t PROGMEM pl_combo_taba[]   = {KC_TAB,   KC_A,                   COMBO_END};
    const uint16_t PROGMEM pl_combo_bspa[]   = {KC_BSPC,  KC_A,                   COMBO_END};
#endif // ! defined(PLODAH_COMBOS_LIMITED)

// ##########################################
// ##               HOME ROW               ##
// ##########################################
#if ! defined(PLODAH_COMBOS_LIMITED)
    const uint16_t PROGMEM pl_combo_as[]     = {KC_A,     KC_S,                   COMBO_END};
    const uint16_t PROGMEM pl_combo_df[]     = {KC_D,     KC_F,                   COMBO_END};
    const uint16_t PROGMEM pl_combo_fg[]     = {KC_F,     KC_G,                   COMBO_END};
    const uint16_t PROGMEM pl_combo_gh[]     = {KC_G,     KC_H,                   COMBO_END};
    const uint16_t PROGMEM pl_combo_hj[]     = {KC_H,     KC_J,                   COMBO_END};
    const uint16_t PROGMEM pl_combo_mk[]     = {KC_M,     KC_K,                   COMBO_END};

    #if defined(PLODAH_HRM_COMBOS)
        const uint16_t PROGMEM pl_combo_capa_hrm[]    = {P_BSPFA, HRM_AG, COMBO_END};
        const uint16_t PROGMEM pl_combo_capa_hrm2[]   = {P_BSPFB, HRM_AG, COMBO_END};
        const uint16_t PROGMEM pl_combo_capa_hrm3[]   = {KC_NUBS, HRM_AG, COMBO_END};
        const uint16_t PROGMEM pl_combo_taba_hrm[]    = {KC_TAB,  HRM_AG, COMBO_END};

        const uint16_t PROGMEM pl_combo_as_hrm[]      = {HRM_AG,  HRM_SA, COMBO_END};
        const uint16_t PROGMEM pl_combo_df_hrm[]      = {HRM_DS,  HRM_FC, COMBO_END};
        const uint16_t PROGMEM pl_combo_fg_hrm[]      = {HRM_FC,  HRM_GG, COMBO_END};
        const uint16_t PROGMEM pl_combo_gh_hrm[]      = {HRM_GG,  HRM_HG, COMBO_END};
        const uint16_t PROGMEM pl_combo_hj_hrm[]      = {HRM_HG,  HRM_JC, COMBO_END};

        const uint16_t PROGMEM pl_combo_mk_hrm[]      = {BRM_MC,  HRM_KS, COMBO_END};
        const uint16_t PROGMEM pl_combo_mk_hrm2[]     = {KC_M,    HRM_KS, COMBO_END};

        const uint16_t PROGMEM pl_combo_bsz_hrm[]     = {KC_NUBS, BRM_ZG, COMBO_END};
        const uint16_t PROGMEM pl_combo_bsz2_hrm[]    = {KC_LSFT, BRM_ZG, COMBO_END};

        #if defined(PLODAH_HRM_COMBOS_EXCESSIVE)
            const uint16_t PROGMEM pl_combo_bspa_hrm[]    = {KC_BSPC, HRM_AG, COMBO_END};
            const uint16_t PROGMEM pl_combo_as_hrm2[]     = {KC_A ,   HRM_SA, COMBO_END};
            const uint16_t PROGMEM pl_combo_as_hrm3[]     = {HRM_AG,  KC_S,   COMBO_END};
            const uint16_t PROGMEM pl_combo_df_hrm2[]     = {KC_D ,   HRM_FC, COMBO_END};
            const uint16_t PROGMEM pl_combo_df_hrm3[]     = {HRM_DS,  KC_F,   COMBO_END};
            const uint16_t PROGMEM pl_combo_fg_hrm2[]     = {KC_F ,   HRM_GG, COMBO_END};
            const uint16_t PROGMEM pl_combo_fg_hrm3[]     = {HRM_FC,  KC_G,   COMBO_END};
            const uint16_t PROGMEM pl_combo_gh_hrm2[]     = {KC_G,    HRM_HG, COMBO_END};
            const uint16_t PROGMEM pl_combo_gh_hrm3[]     = {HRM_GG,  KC_H,   COMBO_END};
            const uint16_t PROGMEM pl_combo_hj_hrm2[]     = {KC_H,    HRM_JC, COMBO_END};
            const uint16_t PROGMEM pl_combo_hj_hrm3[]     = {HRM_HG,  KC_J,   COMBO_END};
            // const uint16_t PROGMEM pl_combo_dk_hrm[]      = {HRM_DS,  HRM_KS, COMBO_END};
            const uint16_t PROGMEM pl_combo_mk_hrm3[]     = {BRM_MC,  KC_K,   COMBO_END};
        #endif // PLODAH_HRM_COMBOS_EXCESSIVE
    #endif // defined(PLODAH_HRM_COMBOS)
#endif // !defined(PLODAH_COMBOS_LIMITED)

// ##########################################
// ##              BOTTOM ROW              ##
// ##########################################
#if !defined(PLODAH_COMBOS_LIMITED) && !defined(PLODAH_BRM_COMBOS)
    const uint16_t PROGMEM pl_combo_lsz[]   = {KC_LSFT, KC_Z,                   COMBO_END};
    const uint16_t PROGMEM pl_combo_bsz[]   = {KC_NUBS, KC_Z,                  COMBO_END};
    const uint16_t PROGMEM pl_combo_zx[]    = {KC_Z,    KC_X,                   COMBO_END};
    const uint16_t PROGMEM pl_combo_xc[]    = {KC_X,    KC_C,                   COMBO_END};
    const uint16_t PROGMEM pl_combo_cv[]    = {KC_C,    KC_V,                   COMBO_END};
    const uint16_t PROGMEM pl_combo_zxc[]   = {KC_Z,    KC_X,   KC_C,           COMBO_END};
    const uint16_t PROGMEM pl_combo_xcv[]   = {KC_X,    KC_C,   KC_V,           COMBO_END};
#endif // !defined(PLODAH_COMBOS_LIMITED) && !defined(PLODAH_BRM_COMBOS)
#if ! defined(PLODAH_COMBOS_LIMITED)
    const uint16_t PROGMEM pl_combo_vb[]     = {KC_V,    KC_B,                    COMBO_END};
#endif // ! defined(PLODAH_COMBOS_LIMITED)

#if defined(PLODAH_BRM_COMBOS)
    const uint16_t PROGMEM pl_combo_lsz_brm[]     = {KC_LSFT, BRM_ZG,  COMBO_END};
    const uint16_t PROGMEM pl_combo_zxc_brm[]     = {BRM_ZG,  BRM_XA,  BRM_CS,  COMBO_END};
    const uint16_t PROGMEM pl_combo_xcv_brm[]     = {BRM_XA,  BRM_CS,  BRM_VC,  COMBO_END};

    const uint16_t PROGMEM pl_combo_zx_brm[]      = {BRM_ZG,  BRM_XA,  COMBO_END};
    const uint16_t PROGMEM pl_combo_xc_brm[]      = {BRM_XA,  BRM_CS,  COMBO_END};
    const uint16_t PROGMEM pl_combo_cv_brm[]      = {BRM_CS,  BRM_VC,  COMBO_END};
    const uint16_t PROGMEM pl_combo_vb_brm[]      = {BRM_VC,  BRM_BG,  COMBO_END};

    #if defined(PLODAH_BRM_COMBOS_EXCESSIVE)
        const uint16_t PROGMEM pl_combo_zx_brm2[]     = {KC_Z,    BRM_XA,  COMBO_END};
        const uint16_t PROGMEM pl_combo_zx_brm3[]     = {BRM_ZG,  KC_X,    COMBO_END};
        const uint16_t PROGMEM pl_combo_xc_brm2[]     = {KC_X,    BRM_CS,  COMBO_END};
        const uint16_t PROGMEM pl_combo_xc_brm3[]     = {BRM_XA,  KC_C,    COMBO_END};
        const uint16_t PROGMEM pl_combo_cv_brm2[]     = {KC_C,    BRM_VC,  COMBO_END};
        const uint16_t PROGMEM pl_combo_cv_brm3[]     = {BRM_CS,  KC_V,    COMBO_END};

        const uint16_t PROGMEM pl_combo_zxc_brm2[]    = {KC_Z,    BRM_XA,  BRM_CS,  COMBO_END};
        const uint16_t PROGMEM pl_combo_zxc_brm3[]    = {BRM_ZG,  KC_X,    BRM_CS,  COMBO_END};
        const uint16_t PROGMEM pl_combo_zxc_brm4[]    = {BRM_ZG,  BRM_XA,  KC_C,    COMBO_END};
        const uint16_t PROGMEM pl_combo_zxc_brm5[]    = {KC_Z,    KC_X,    BRM_CS,  COMBO_END};
        const uint16_t PROGMEM pl_combo_zxc_brm6[]    = {KC_Z,    BRM_XA,  KC_C,    COMBO_END};
        const uint16_t PROGMEM pl_combo_zxc_brm7[]    = {BRM_ZG,  KC_X,    KC_C,    COMBO_END};

        const uint16_t PROGMEM pl_combo_xcv_brm2[]    = {KC_X,    BRM_CS,  BRM_VC,  COMBO_END};
        const uint16_t PROGMEM pl_combo_xcv_brm3[]    = {BRM_XA,  KC_C,    BRM_VC,  COMBO_END};
        const uint16_t PROGMEM pl_combo_xcv_brm4[]    = {BRM_XA,  BRM_CS,  KC_V,    COMBO_END};
        const uint16_t PROGMEM pl_combo_xcv_brm5[]    = {KC_X,    KC_C,    BRM_VC,  COMBO_END};
        const uint16_t PROGMEM pl_combo_xcv_brm6[]    = {KC_X,    BRM_CS,  KC_V,    COMBO_END};
        const uint16_t PROGMEM pl_combo_xcv_brm7[]    = {BRM_XA,  KC_C,    KC_V,    COMBO_END};

        const uint16_t PROGMEM pl_combo_vb_brm2[]     = {KC_V,    BRM_BG,  COMBO_END};
        const uint16_t PROGMEM pl_combo_vb_brm3[]     = {BRM_VC,  KC_B,    COMBO_END};
    #endif // defined(PLODAH_BRM_COMBOS_EXCESSIVE)
#endif // defined(PLODAH_BRM_COMBOS)

const uint16_t PROGMEM pl_combo_volud[] = {KC_VOLU, KC_VOLD,                COMBO_END};
const uint16_t PROGMEM pl_combo_cad[]    = {KC_C,     KC_A,     KC_D,         COMBO_END};

#if defined(PLODAH_HRM_COMBOS) && !defined(PLODAH_BRM_COMBOS)
    const uint16_t PROGMEM pl_combo_cad_hrm[]    = {KC_C,  HRM_AG, HRM_DS, COMBO_END};
#endif // defined(PLODAH_HRM_COMBOS)
#if defined(PLODAH_BRM_COMBOS) && !defined(PLODAH_HRM_COMBOS)
    const uint16_t PROGMEM pl_combo_cad_brm[]    = {BRM_CS, KC_A, KC_D, COMBO_END};
#endif // defined(PLODAH_BRM_COMBOS)
#if defined(PLODAH_HRM_COMBOS) && defined(PLODAH_BRM_COMBOS)
    const uint16_t PROGMEM pl_combo_cad_hbrm[]    = {BRM_CS, HRM_AG, HRM_DS, COMBO_END};
#endif // defined(PLODAH_HRM_COMBOS) && defined(PLODAH_BRM_COMBOS)

#if defined(PLODAH_HRM_COMBOS_EXCESSIVE)
    const uint16_t PROGMEM pl_combo_cad_hrm2[]    = {KC_C,  KC_A,   HRM_DS, COMBO_END};
    const uint16_t PROGMEM pl_combo_cad_hrm3[]    = {KC_C,  HRM_AG, KC_D,   COMBO_END};
#endif // defined(PLODAH_HRM_COMBOS_EXCESSIVE) && defined(PLODAH_BRM_COMBOS_EXCESSIVE)
#if defined(PLODAH_HRM_COMBOS_EXCESSIVE) && defined(PLODAH_BRM_COMBOS_EXCESSIVE)
    const uint16_t PROGMEM pl_combo_cad_hbrm2[]    = {BRM_CS, HRM_AG, KC_D, COMBO_END};
    const uint16_t PROGMEM pl_combo_cad_hbrm3[]    = {BRM_CS, KC_A, HRM_DS, COMBO_END};
#endif // defined(PLODAH_HRM_COMBOS_EXCESSIVE) && defined(PLODAH_BRM_COMBOS_EXCESSIVE)

#if defined(COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE) && ! defined(PLODAH_COMBOS_LIMITED)
    const uint16_t PROGMEM pl_combo_mj[] = {KC_M , KC_J, COMBO_END};
    #if defined(PLODAH_HRM_COMBOS_EXCESSIVE)
        const uint16_t PROGMEM pl_combo_mj_hrm[] = {KC_M , HRM_JC, COMBO_END};
    #endif // PLODAH_HRM_COMBOS_EXCESSIVE
    #if defined(PLODAH_BRM_COMBOS_EXCESSIVE)
        const uint16_t PROGMEM pl_combo_mj_brm[] = {BRM_MC , KC_C, COMBO_END};
    #endif // PLODAH_BRM_COMBOS_EXCESSIVE
    #if defined(PLODAH_HRM_COMBOS) && defined(PLODAH_BRM_COMBOS)
        const uint16_t PROGMEM pl_combo_mj_hbrm[] = {BRM_MC , HRM_JC, COMBO_END};
    #endif // defined(PLODAH_HRM_COMBOS) && defined(PLODAH_BRM_COMBOS)
#endif // COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE && ! defined(PLODAH_COMBOS_LIMITED)

#if defined(COMMUNITY_MODULE_TASK_SWITCH_ENABLE)
    const uint16_t PROGMEM pl_combo_escq[] = {KC_ESC , KC_Q , COMBO_END};
    const uint16_t PROGMEM pl_combo_escw[] = {KC_ESC , KC_W , COMBO_END};

    const uint16_t PROGMEM pl_combo_tabq[] = {KC_TAB , KC_Q , COMBO_END};
    const uint16_t PROGMEM pl_combo_tabw[] = {KC_TAB , KC_W , COMBO_END};

    const uint16_t PROGMEM pl_combo_bsctlq[] = {P_BSCTL , KC_Q , COMBO_END};
    const uint16_t PROGMEM pl_combo_bsctlw[] = {P_BSCTL , KC_W , COMBO_END};

    #if defined(TAP_DANCE_ENABLE)
        const uint16_t PROGMEM pl_combo_ragq[] = {P_RAGEQ, KC_Q , COMBO_END};
        const uint16_t PROGMEM pl_combo_ragw[] = {P_RAGEQ, KC_W , COMBO_END};
    #endif // defined(TAP_DANCE_ENABLE)

#endif // COMMUNITY_MODULE_TASK_SWITCH_ENABLE

#if defined(LEADER_ENABLE)
    const uint16_t PROGMEM pl_combo_sf[]     = {KC_S,     KC_F,                   COMBO_END};
    const uint16_t PROGMEM pl_combo_jl[]     = {KC_J,     KC_L,                   COMBO_END};
    #if defined(PLODAH_HRM_COMBOS)
        const uint16_t PROGMEM pl_combo_sf_hrm[]     = {HRM_SA,   HRM_FC, COMBO_END};
        const uint16_t PROGMEM pl_combo_jl_hrm[]     = {HRM_JC,   HRM_LA, COMBO_END};
    #endif // defined(PLODAH_HRM_COMBOS)
    #if defined(PLODAH_HRM_COMBOS_EXCESSIVE)
        const uint16_t PROGMEM pl_combo_sf_hrm2[]    = {HRM_SA,   KC_F,   COMBO_END};
        const uint16_t PROGMEM pl_combo_sf_hrm3[]    = {KC_S,     HRM_FC, COMBO_END};
        const uint16_t PROGMEM pl_combo_jl_hrm2[]    = {HRM_JC,   KC_L,   COMBO_END};
        const uint16_t PROGMEM pl_combo_jl_hrm3[]    = {KC_J,     HRM_LA, COMBO_END};
    #endif // defined(PLODAH_HRM_COMBOS_EXCESSIVE)
#endif // defined(LEADER_ENABLE)

#if defined(DYNAMIC_MACRO_ENABLE)
    const uint16_t PROGMEM pl_combo_12[]  = {KC_1 , KC_2, COMBO_END};
    const uint16_t PROGMEM pl_combo_13[]  = {KC_1 , KC_3, COMBO_END};
    const uint16_t PROGMEM pl_combo_qw[]  = {KC_Q , KC_W, COMBO_END};
    const uint16_t PROGMEM pl_combo_qe[]  = {KC_Q , KC_E, COMBO_END};
    const uint16_t PROGMEM pl_combo_3e[]  = {KC_3 , KC_E, COMBO_END};
    #if defined(PLODAH_TAPDANCE_TAPHOLD_ENABLE)
        const uint16_t PROGMEM pl_combo_1F2[] = {KC_1 , TD(TD_F2), COMBO_END};
    #endif // defined(PLODAH_TAPDANCE_TAPHOLD_ENABLE)
#endif // DYNAMIC_MACRO_ENABLE

#if defined(CONSOLE_ENABLE)
    const uint16_t PROGMEM pl_combo_db[] = {KC_D , KC_B, COMBO_END};
    #if defined(PLODAH_HRM_COMBOS) && !defined(PLODAH_BRM_COMBOS)
        const uint16_t PROGMEM pl_combo_db_hrm[] = {HRM_DS , KC_B, COMBO_END};
    #endif // defined(PLODAH_HRM_COMBOS)
    #if defined(PLODAH_BRM_COMBOS) && !defined(PLODAH_HRM_COMBOS)
        const uint16_t PROGMEM pl_combo_db_brm[] = {KC_D , BRM_BG, COMBO_END};
    #endif // defined(PLODAH_BRM_COMBOS)
    #if defined(PLODAH_HRM_COMBOS) && defined(PLODAH_BRM_COMBOS)
        const uint16_t PROGMEM pl_combo_db_hbrm[] = {HRM_DS , BRM_BG, COMBO_END};
    #endif // defined(PLODAH_HRM_COMBOS) && defined(PLODAH_BRM_COMBOS)
#endif // defined(CONSOLE_ENABLE)

combo_t key_combos[] = {

    // ##########################################
    // ##                TOP ROW               ##
    // ##########################################

    #if ! defined(PLODAH_COMBOS_LIMITED)
        COMBO(pl_combo_0bsp,  KC_DEL     ),
        COMBO(pl_combo_eqbsp, KC_DEL     ),

        COMBO(pl_combo_qwop,  QK_BOOT    ),
        COMBO(pl_combo_wr,    C(KC_F5)   ),
        COMBO(pl_combo_et,    C(KC_T)    ),
        COMBO(pl_combo_ert,   C(S(KC_T)) ),
        COMBO(pl_combo_ip,    KC_PSCR    ),

        COMBO(pl_combo_capa,  C(KC_A)    ),
        COMBO(pl_combo_capa2, C(KC_A)    ),
        COMBO(pl_combo_capa3, C(KC_A)    ),
        COMBO(pl_combo_taba,  C(KC_A)    ),
        COMBO(pl_combo_bspa,  C(KC_A)    ),
    #endif // ! defined(PLODAH_COMBOS_LIMITED)

    // ##########################################
    // ##               HOME ROW               ##
    // ##########################################
    #if ! defined(PLODAH_COMBOS_LIMITED)
        COMBO(pl_combo_as,    C(KC_S)    ),
        COMBO(pl_combo_df,    C(KC_F)    ),
        COMBO(pl_combo_fg,    C(KC_G)    ),
        COMBO(pl_combo_gh,    C(KC_H)    ),
        COMBO(pl_combo_hj,    C(KC_J)    ),
        COMBO(pl_combo_mk,    QK_MAKE    ),

        #if defined(PLODAH_HRM_COMBOS)
            COMBO(pl_combo_capa_hrm,    C(KC_A)),
            COMBO(pl_combo_capa_hrm2,   C(KC_A)),
            COMBO(pl_combo_capa_hrm3,   C(KC_A)),
            COMBO(pl_combo_taba_hrm,    C(KC_A)),

            COMBO(pl_combo_as_hrm,      C(KC_S)),
            COMBO(pl_combo_df_hrm,      C(KC_F)),
            COMBO(pl_combo_fg_hrm,      C(KC_G)),
            COMBO(pl_combo_gh_hrm,      C(KC_H)),
            COMBO(pl_combo_hj_hrm,      C(KC_J)),

            COMBO(pl_combo_mk_hrm,      QK_MAKE),
            COMBO(pl_combo_mk_hrm2,     QK_MAKE),

            COMBO(pl_combo_bsz_hrm,     C(KC_Z)),
            COMBO(pl_combo_bsz2_hrm,    C(KC_Z)),

            #if defined(PLODAH_HRM_COMBOS_EXCESSIVE)
                COMBO(pl_combo_bspa_hrm,    C(KC_A)),
                COMBO(pl_combo_as_hrm2,     C(KC_S)),
                COMBO(pl_combo_as_hrm3,     C(KC_S)),
                COMBO(pl_combo_df_hrm2,     C(KC_F)),
                COMBO(pl_combo_df_hrm3,     C(KC_F)),
                COMBO(pl_combo_fg_hrm2,     C(KC_G)),
                COMBO(pl_combo_fg_hrm3,     C(KC_G)),
                COMBO(pl_combo_gh_hrm2,     C(KC_H)),
                COMBO(pl_combo_gh_hrm3,     C(KC_H)),
                COMBO(pl_combo_hj_hrm2,     C(KC_J)),
                COMBO(pl_combo_hj_hrm3,     C(KC_J)),
                // COMBO(pl_combo_dk_hrm,      CW_TOGG),
                COMBO(pl_combo_mk3_hrm,     QK_MAKE),
            #endif // PLODAH_HRM_COMBOS_EXCESSIVE
        #endif // defined(PLODAH_HRM_COMBOS)
    #endif // !defined(PLODAH_COMBOS_LIMITED)

    // ##########################################
    // ##              BOTTOM ROW              ##
    // ##########################################

    #if !defined(PLODAH_COMBOS_LIMITED) && !defined(PLODAH_BRM_COMBOS)
        COMBO(pl_combo_lsz,   C(KC_Z)    ),
        COMBO(pl_combo_bsz,   C(KC_Z)    ),
        COMBO(pl_combo_zx,    C(KC_X)    ),
        COMBO(pl_combo_xc,    C(KC_C)    ),
        COMBO(pl_combo_cv,    C(KC_V)    ),
        COMBO(pl_combo_zxc,   C(S(KC_C)) ),
        COMBO(pl_combo_xcv,   C(S(KC_V)) ),
    #endif // !defined(PLODAH_COMBOS_LIMITED) && !defined(PLODAH_BRM_COMBOS)

    #if ! defined(PLODAH_COMBOS_LIMITED)
        COMBO(pl_combo_vb,    C(KC_B)    ),
    #endif // ! defined(PLODAH_COMBOS_LIMITED)

    #if defined(PLODAH_BRM_COMBOS)
        COMBO(pl_combo_lsz_brm,     C(KC_Z)),
        COMBO(pl_combo_zxc_brm,   C(S(KC_C))),
        COMBO(pl_combo_xcv_brm,   C(S(KC_V))),

        COMBO(pl_combo_zx_brm,      C(KC_X)),
        COMBO(pl_combo_xc_brm,      C(KC_C)),
        COMBO(pl_combo_cv_brm,      C(KC_V)),
        COMBO(pl_combo_vb_brm,      C(KC_B)),

        #if defined(PLODAH_HRM_COMBOS_EXCESSIVE)
        // #if ! (defined(PLODAH_COMBOS_LIMITED) || defined(PLODAH_COMBOS_BRM_LIMITED))
            COMBO(pl_combo_zx_brm2,     C(KC_X)),
            COMBO(pl_combo_zx_brm3,     C(KC_X)),
            COMBO(pl_combo_xc_brm2,     C(KC_C)),
            COMBO(pl_combo_xc_brm3,     C(KC_C)),
            COMBO(pl_combo_cv_brm2,     C(KC_V)),
            COMBO(pl_combo_cv_brm3,     C(KC_V)),

            COMBO(pl_combo_zxc_brm2,  C(S(KC_C))),
            COMBO(pl_combo_zxc_brm3,  C(S(KC_C))),
            COMBO(pl_combo_zxc_brm4,  C(S(KC_C))),
            COMBO(pl_combo_zxc_brm5,  C(S(KC_C))),
            COMBO(pl_combo_zxc_brm6,  C(S(KC_C))),
            COMBO(pl_combo_zxc_brm7,  C(S(KC_C))),

            COMBO(pl_combo_xcv_brm2,  C(S(KC_V))),
            COMBO(pl_combo_xcv_brm3,  C(S(KC_V))),
            COMBO(pl_combo_xcv_brm4,  C(S(KC_V))),
            COMBO(pl_combo_xcv_brm5,  C(S(KC_V))),
            COMBO(pl_combo_xcv_brm6,  C(S(KC_V))),
            COMBO(pl_combo_xcv_brm7,  C(S(KC_V))),

            COMBO(pl_combo_vb_brm2,     C(KC_B)),
            COMBO(pl_combo_vb_brm3,     C(KC_B)),
        // #endif // ! (defined(PLODAH_COMBOS_LIMITED) || defined(PLODAH_COMBOS_BRM_LIMITED))
        #endif // defined(PLODAH_HRM_COMBOS_EXCESSIVE)
    #endif // defined(PLODAH_BRM_COMBOS)

    COMBO(pl_combo_volud, KC_MUTE ),
    COMBO(pl_combo_cad,   LCA(KC_DEL)),

    #if defined(PLODAH_HRM_COMBOS) && !defined(PLODAH_BRM_COMBOS)
        COMBO(pl_combo_cad_hrm,     LCA(KC_DEL)),
    #endif // defined(PLODAH_HRM_COMBOS)
    #if defined(PLODAH_BRM_COMBOS) && !defined(PLODAH_HRM_COMBOS)
        COMBO(pl_combo_cad_brm,     LCA(KC_DEL)),
    #endif // defined(PLODAH_BRM_COMBOS)
    #if defined(PLODAH_HRM_COMBOS) && defined(PLODAH_BRM_COMBOS)
        COMBO(pl_combo_cad_hbrm,      LCA(KC_DEL)),
    #endif // defined(PLODAH_HRM_COMBOS) && defined(PLODAH_BRM_COMBOS)

    #if defined(PLODAH_HRM_COMBOS_EXCESSIVE)
        COMBO(pl_combo_cad_hrm2,    LCA(KC_DEL)),
        COMBO(pl_combo_cad_hrm3,    LCA(KC_DEL)),
    #endif // defined(PLODAH_HRM_COMBOS_EXCESSIVE) && defined(PLODAH_BRM_COMBOS_EXCESSIVE)
    #if defined(PLODAH_HRM_COMBOS_EXCESSIVE) && defined(PLODAH_BRM_COMBOS_EXCESSIVE)
        COMBO(pl_combo_cad_hbrm2,     LCA(KC_DEL)),
        COMBO(pl_combo_cad_hbrm3,     LCA(KC_DEL)),
    #endif // defined(PLODAH_HRM_COMBOS_EXCESSIVE) && defined(PLODAH_BRM_COMBOS_EXCESSIVE)

    #if defined(COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE) && ! defined(PLODAH_COMBOS_LIMITED)
        COMBO(pl_combo_mj,     CM_MSJG),
        #if defined(PLODAH_HRM_COMBOS_EXCESSIVE)
            COMBO(pl_combo_mj_hrm, CM_MSJG),
        #endif // PLODAH_HRM_COMBOS_EXCESSIVE
        #if defined(PLODAH_BRM_COMBOS_EXCESSIVE)
            COMBO(pl_combo_mj_brm, CM_MSJG),
        #endif // PLODAH_BRM_COMBOS_EXCESSIVE
        #if defined(PLODAH_HRM_COMBOS) && defined(PLODAH_BRM_COMBOS)
            COMBO(pl_combo_mj_hbrm, CM_MSJG),
        #endif // defined(PLODAH_HRM_COMBOS) && defined(PLODAH_BRM_COMBOS)
    #endif // defined(COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE) && ! defined(PLODAH_COMBOS_LIMITED)

    #if defined(COMMUNITY_MODULE_TASK_SWITCH_ENABLE)
        COMBO(pl_combo_escq,    CM_TSKP),
        COMBO(pl_combo_escw,    CM_TSKN),
        #if defined(TAP_DANCE_ENABLE)
            COMBO(pl_combo_ragq,    CM_TSKP),
            COMBO(pl_combo_ragw,    CM_TSKN),
        #endif // defined(TAP_DANCE_ENABLE)
        COMBO(pl_combo_tabq,    CM_TSKP),
        COMBO(pl_combo_tabw,    CM_TSKN),
        COMBO(pl_combo_bsctlq,    CM_TSKP),
        COMBO(pl_combo_bsctlw,    CM_TSKN),
    #endif // COMMUNITY_MODULE_TASK_SWITCH_ENABLE

    #if defined(LEADER_ENABLE)
        COMBO(pl_combo_sf,  QK_LEAD),
        COMBO(pl_combo_jl,  QK_LEAD),
        #if defined(PLODAH_HRM_COMBOS)
            COMBO(pl_combo_sf_hrm,      QK_LEAD),
            COMBO(pl_combo_jl_hrm,      QK_LEAD),
        #endif // defined(PLODAH_HRM_COMBOS)
        #if defined(PLODAH_HRM_COMBOS_EXCESSIVE)
            COMBO(pl_combo_sf_hrm2,     QK_LEAD),
            COMBO(pl_combo_sf_hrm3,     QK_LEAD),
            COMBO(pl_combo_jl_hrm2,     QK_LEAD),
            COMBO(pl_combo_jl_hrm3,     QK_LEAD),
        #endif // defined(PLODAH_HRM_COMBOS_EXCESSIVE)
    #endif // defined(LEADER_ENABLE)

    #if defined(DYNAMIC_MACRO_ENABLE)
        COMBO(pl_combo_12,    DM_PLY1),
        COMBO(pl_combo_13,    DM_REC1),
        COMBO(pl_combo_qw,    DM_PLY2),
        COMBO(pl_combo_qe,    DM_REC2),
        COMBO(pl_combo_3e,    DM_RSTP),
        #if defined(PLODAH_TAPDANCE_TAPHOLD_ENABLE)
            COMBO(pl_combo_1F2,   DM_PLY1),
        #endif // defined(PLODAH_TAPDANCE_TAPHOLD_ENABLE)
    #endif // DYNAMIC_MACRO_ENABLE

    #if defined(CONSOLE_ENABLE)
        COMBO(pl_combo_db,    DB_TOGG),
        #if defined(PLODAH_HRM_COMBOS) && !defined(PLODAH_BRM_COMBOS)
            COMBO(pl_combo_db_hrm,    DB_TOGG),
        #endif // defined(PLODAH_HRM_COMBOS)
        #if defined(PLODAH_BRM_COMBOS) && !defined(PLODAH_HRM_COMBOS)
            COMBO(pl_combo_db_brm,    DB_TOGG),
        #endif // defined(PLODAH_BRM_COMBOS)
        #if defined(PLODAH_HRM_COMBOS) && defined(PLODAH_BRM_COMBOS)
            COMBO(pl_combo_db_hbrm,    DB_TOGG),
        #endif // defined(PLODAH_HRM_COMBOS) && defined(PLODAH_BRM_COMBOS)
    #endif // defined(CONSOLE_ENABLE)
};
