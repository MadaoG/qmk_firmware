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

enum { 
  mc_sh_clicks,
  mc_hat,
};
