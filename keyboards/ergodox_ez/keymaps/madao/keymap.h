
#define   _EN   0    // english layer
#define   _GE   1    // german layer
#define   _SM   2    // symbol layer
#define   _MV   3    // movement layer
#define   _NM   4    // digit layer
#define   _FN   5    // fn keys
#define   _SH   6    // gaming layer
#define   _MS   7    // mouse layer

#define   _BS   _EN  // setting the base layer

#define MV_WIN MT(MOD_LCTL | MOD_LGUI, KC_ESC)
#define HAT M(mc_hat)

#define ALT_Y ALT_T(DE_Y)
#define SFT_Q SFT_T(DE_Q)
#define CTL_P CTL_T(DE_P)
#define ALT_DT ALT_T(DE_DOT)
#define SFT_CM SFT_T(DE_COMM)
#define CTL_M CTL_T(DE_M)
#define OS_SFTL OSM(MOD_LSFT)
#define OS_SFTR OSM(MOD_RSFT)

#define SM_A LT(_SM, (DE_A))
#define SM_R LT(_SM, (DE_R))
#define NM_E LT(_NM, (DE_E))
#define MV_N LT(_MV, (DE_N))

#define TAP_KEY(kc) register_code(kc); unregister_code(kc);
#define TAP_TWICE(kc) TAP_KEY(kc); TAP_KEY(kc);

#define T_BQ   TD(td_bq)
#define T_ELG  TD(td_elg)
#define T_UAG  TD(td_uag)
#define T_BSP  TD(td_bsp)
#define T_SH   TD(td_sh)
#define T_PBBL TD(td_pbbl)
#define T_PBBR TD(td_pbbr)
#define T_DAT  TD(td_dat)
#define T_PA   TD(td_pa)
#define T_PM   TD(td_pm)
#define T_DQ   TD(td_dq)
#define T_SQ   TD(td_sq)
#define T_AE   TD(td_ge_ae)
#define T_OE   TD(td_ge_oe)
#define T_UE   TD(td_ge_ue)
#define T_SS   TD(td_ge_ss)
#define T_DC   TD(td_dc)
#define T_TO   TD(td_to)
#define T_TBT  TD(td_tbt)
#define T_DT   TD(td_dt)
#define T_CL TD(CL_SCL)

enum {
  CL_SCL,
  td_pbbl,
  td_pbbr,
  td_elg,
  td_uag,
  td_bq,
  td_bsp,
  td_sh,
  td_dat,
  td_pa,
  td_pm,
  td_dq,
  td_sq,
  td_dc,
  td_ge_ue,
  td_ge_ae,
  td_ge_oe,
  td_ge_ss,
  td_to,
  td_tbt,
  td_dt,
};

enum { 
  mc_sh_clicks,
  mc_hat,
};

