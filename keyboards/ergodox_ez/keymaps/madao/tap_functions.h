
// Not all of these are active.
// Uncomment new ones below in qk_tap_dance_action_t

#define T_BQ   TD(td_bq)    // bang and questionmark
#define T_ELG  TD(td_elg)   // equal, less, greater
#define T_UAG  TD(td_uag)   // underscore, accent, grave (tick and backtick)
#define T_BSP  TD(td_bsp)   // backslash, slash and pipe
#define T_SH   TD(td_sh)    // star and hat
#define T_PBBL TD(td_pbbl)  // left parenthesis, brackets and braces
#define T_PBBR TD(td_pbbr)  // right parenthesis, brackets and braces
#define T_DAT  TD(td_dat)   // dollar, at, tilde
#define T_PA   TD(td_pa)    // percent and ampersand
#define T_PM   TD(td_pm)    // plus and minus
#define T_DQ   TD(td_dq)    // double quote
#define T_SQ   TD(td_sq)    // single quote
#define T_AE   TD(td_ge_ae) // german ae
#define T_OE   TD(td_ge_oe) // german oe
#define T_UE   TD(td_ge_ue) // german ue
#define T_SS   TD(td_ge_ss) // german ss
#define T_TO   TD(td_to)    // times, over
#define T_TBT  TD(td_tbt)   // tick and backtick
#define T_DT   TD(td_dt)    // dollar and tilde
#define T_CL   TD(CL_SCL)   // colon and semicolon
#define T_DC   TD(td_dc)    // dot and comma

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
  SINGLE_TAP,
  SINGLE_HOLD,
  DOUBLE_TAP,
  DOUBLE_HOLD,
  TRIPLE_TAP,
  TRIPLE_HOLD,
  DOUBLE_SINGLE_TAP,
  MAGIC_TAP,
};

typedef struct {
  bool is_press_action;
  int state;
} tap;

static tap xtap_state = {
  .is_press_action = true,
  .state = 0
};

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || state->pressed==0) return SINGLE_TAP;
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  else if (state->count == 3) {
    if (state->pressed) return TRIPLE_HOLD;
    else return TRIPLE_TAP;
  }
  else return MAGIC_TAP;
}

void th_pbbl_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP:  register_code(KC_LSFT); register_code(KC_8); break;
    case DOUBLE_TAP:  register_code(KC_RALT); register_code(KC_8); break;
    case SINGLE_HOLD:  register_code(KC_RALT); register_code(KC_7); break;
  }
}

void th_pbbl_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP:  unregister_code(KC_8); unregister_code(KC_LSFT); break;
    case DOUBLE_TAP:  unregister_code(KC_8); unregister_code(KC_RALT); break;
    case SINGLE_HOLD:  unregister_code(KC_7); unregister_code(KC_RALT); break;
  }
  xtap_state.state = 0;
}

void th_pbbr_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP:  register_code(KC_LSFT); register_code(KC_9); break;
    case DOUBLE_TAP:  register_code(KC_RALT); register_code(KC_9); break;
    case SINGLE_HOLD:  register_code(KC_RALT); register_code(KC_0); break;
  }
}

void th_pbbr_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP:  unregister_code(KC_9); unregister_code(KC_LSFT); break;
    case DOUBLE_TAP:  unregister_code(KC_9); unregister_code(KC_RALT); break;
    case SINGLE_HOLD:  unregister_code(KC_0); unregister_code(KC_RALT); break;
  }
  xtap_state.state = 0;
}

// = ,  >  and  <
void th_elg_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP:  register_code(KC_LSFT); register_code(KC_0); break;
    case DOUBLE_TAP:  register_code(DE_LESS); break;
    case SINGLE_HOLD: register_code(KC_LSFT); register_code(DE_LESS); break;
  }
}

void th_elg_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP:  unregister_code(KC_0); unregister_code(KC_LSFT); break;
    case DOUBLE_TAP:  unregister_code(DE_LESS); break;
    case SINGLE_HOLD: unregister_code(DE_LESS); unregister_code(KC_LSFT); break;
  }
  xtap_state.state = 0;
}

// _, 
void th_uag_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP:  register_code(KC_LSFT); register_code(DE_MINS); break;
    case DOUBLE_TAP:  register_code(DE_ACUT); break;
    case SINGLE_HOLD: register_code(KC_LSFT); register_code(DE_ACUT); break;
  }
}

void th_uag_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP:  unregister_code(DE_MINS); unregister_code(KC_LSFT); break;
    case DOUBLE_TAP:  unregister_code(DE_ACUT); break;
    case SINGLE_HOLD: unregister_code(DE_ACUT); unregister_code(KC_LSFT); break;
  }
  xtap_state.state = 0;
}

// bang and questionmark
void th_bq_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP:  register_code(KC_LSFT); register_code(KC_1); break;
    case SINGLE_HOLD: register_code(KC_LSFT); register_code(KC_MINS); break;
    case DOUBLE_TAP:  register_code(KC_LSFT); register_code(KC_MINS); break;
  }
}

void th_bq_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP:  unregister_code(KC_1); unregister_code(KC_LSFT); break;
    case SINGLE_HOLD: unregister_code(KC_MINS); unregister_code(KC_LSFT); break;
    case DOUBLE_TAP:  unregister_code(KC_MINS); unregister_code(KC_LSFT); break;
  }
  xtap_state.state = 0;
}

// backslash, slash and pipe
void th_bsp_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP:  register_code(KC_RALT); register_code(KC_MINS); break;
    case SINGLE_HOLD: register_code(KC_LSFT); register_code(KC_7); break;
    case DOUBLE_TAP:  register_code(KC_RALT); register_code(KC_NUBS); break;
  }
}

void th_bsp_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP:  unregister_code(KC_MINS); unregister_code(KC_RALT); break;
    case SINGLE_HOLD: unregister_code(KC_7); unregister_code(KC_LSFT); break;
    case DOUBLE_TAP:  unregister_code(KC_NUBS); unregister_code(KC_RALT); break;
  }
  xtap_state.state = 0;
}

// star and hat
void th_sh_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP:  register_code(KC_LSFT); register_code(KC_RBRC); break;
    case SINGLE_HOLD: register_code(KC_GRAVE); break;
    case DOUBLE_TAP:  register_code(KC_GRAVE); break;
  }
}

void th_sh_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP:  unregister_code(KC_RBRC); unregister_code(KC_LSFT); break;
    case SINGLE_HOLD: unregister_code(KC_GRAVE); register_code(KC_GRAVE); unregister_code(KC_GRAVE); break;
    case DOUBLE_TAP: unregister_code(KC_GRAVE); register_code(KC_GRAVE); unregister_code(KC_GRAVE); break;
  }
  xtap_state.state = 0;
}

// dollar, at and tilde
void th_dat_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP:  register_code(KC_LSFT); register_code(KC_4); break;
    case DOUBLE_TAP:  register_code(KC_RALT); register_code(KC_RBRC); break;
    case SINGLE_HOLD: register_code(KC_RALT); register_code(KC_Q); break;
  }
}

void th_dat_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP:  unregister_code(KC_4); unregister_code(KC_LSFT); break;
    case DOUBLE_TAP:  unregister_code(KC_RBRC); unregister_code(KC_RALT); break;
    case SINGLE_HOLD: unregister_code(KC_Q); unregister_code(KC_RALT); break;
  }
  xtap_state.state = 0;
}

// percent and 'and'
void th_pa_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP:  register_code(KC_LSFT); register_code(KC_5); break;
    case DOUBLE_TAP:  register_code(KC_LSFT); register_code(KC_6); break;
    case SINGLE_HOLD: register_code(KC_LSFT); register_code(KC_6); break;
  }
}

void th_pa_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP:  unregister_code(KC_5); unregister_code(KC_LSFT); break;
    case DOUBLE_TAP:  unregister_code(KC_6); unregister_code(KC_LSFT); break;
    case SINGLE_HOLD: unregister_code(KC_6); unregister_code(KC_LSFT); break;
  }
  xtap_state.state = 0;
}

// plus and minus
void th_pm_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP:  register_code(KC_RBRC); break;
    case DOUBLE_TAP:  register_code(KC_SLSH); break;
    case SINGLE_HOLD: register_code(KC_SLSH); break;
  }
}

void th_pm_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP:  unregister_code(KC_RBRC); break;
    case DOUBLE_TAP:  unregister_code(KC_SLSH); break;
    case SINGLE_HOLD: unregister_code(KC_SLSH); break;
  }
  xtap_state.state = 0;
}

// double quote
void th_dq_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP:  register_code(KC_LSFT); register_code(KC_2); break;
  }
}

void th_dq_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP:  unregister_code(KC_2); unregister_code(KC_LSFT); break;
  }
  xtap_state.state = 0;
}

// single quote
void th_sq_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP:  register_code(KC_LSFT); register_code(KC_BSLS); break;
  }
}

void th_sq_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP:  unregister_code(KC_BSLS); unregister_code(KC_LSFT); break;
  }
  xtap_state.state = 0;
}

// german ue
void th_ge_ue_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP:  register_code(DE_U); break;
    case DOUBLE_TAP:  register_code(DE_UE); break;
  }
}

void th_ge_ue_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP:  unregister_code(DE_U); break;
    case DOUBLE_TAP:  unregister_code(DE_UE); break;
  }
  xtap_state.state = 0;
}

// german ae
void th_ge_ae_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP:  register_code(DE_A); break;
    case DOUBLE_TAP:  register_code(DE_AE); break;
  }
}

void th_ge_ae_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP:  unregister_code(DE_A); break;
    case DOUBLE_TAP:  unregister_code(DE_AE); break;
  }
  xtap_state.state = 0;
}

// german oe
void th_ge_oe_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP:  register_code(DE_O); break;
    case DOUBLE_TAP:  register_code(DE_OE); break;
  }
}

void th_ge_oe_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP:  unregister_code(DE_O); break;
    case DOUBLE_TAP:  unregister_code(DE_OE); break;
  }
  xtap_state.state = 0;
}

// german ss
void th_ge_ss_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP:  register_code(DE_S); break;
    case DOUBLE_TAP:  register_code(DE_SS); break;
    case DOUBLE_SINGLE_TAP: register_code(DE_S); break;
  }
}

void th_ge_ss_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP:  unregister_code(DE_S); break;
    case DOUBLE_TAP:  unregister_code(DE_SS); break;
    case DOUBLE_SINGLE_TAP: unregister_code(DE_S); register_code(DE_S); unregister_code(DE_S); break;
  }
  xtap_state.state = 0;
}

// times, over
void th_to_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP:  register_code(KC_LSFT); register_code(KC_RBRC); break;
    case DOUBLE_TAP:  register_code(KC_LSFT); register_code(KC_7); break;
  }
}

void th_to_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP:  unregister_code(KC_RBRC); unregister_code(KC_LSFT); break;
    case DOUBLE_TAP:  unregister_code(KC_7); unregister_code(KC_LSFT); break;
  }
  xtap_state.state = 0;
}

// tick and backtick
void th_tbt_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP:  register_code(DE_ACUT); break;
    case DOUBLE_TAP:  register_code(KC_LSFT); register_code(DE_ACUT); break;
  }
}

void th_tbt_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP:  unregister_code(DE_ACUT); register_code(DE_ACUT); unregister_code(DE_ACUT); break;
    case DOUBLE_TAP:  unregister_code(DE_ACUT); unregister_code(KC_LSFT); 
                      register_code(KC_LSFT);   register_code(DE_ACUT); 
                      unregister_code(DE_ACUT); unregister_code(KC_LSFT); break;
  }
  xtap_state.state = 0;
}

// dollar and tilde
void th_dt_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP:  register_code(KC_LSFT); register_code(KC_4); break;
    case DOUBLE_TAP:  register_code(KC_RALT); register_code(KC_RBRC); break;
  }
}

void th_dt_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP:  unregister_code(KC_4); unregister_code(KC_LSFT); break;
    case DOUBLE_TAP:  unregister_code(KC_RBRC); unregister_code(KC_RALT); break;
  }
  xtap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {

  // [td_elg]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_elg_finished,  th_elg_reset),
  // [td_pbbl] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_pbbl_finished, th_pbbl_reset),
  // [td_pbbr] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_pbbr_finished, th_pbbr_reset),
  // [td_elg]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_elg_finished,  th_elg_reset),
  // [td_uag]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_uag_finished,  th_uag_reset),
  // [td_bsp]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_bsp_finished,  th_bsp_reset),
  // [td_sh]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_sh_finished,   th_sh_reset),
  // [td_dat]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_dat_finished,  th_dat_reset),
  // [td_pa]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_pa_finished,   th_pa_reset),
  // [td_dq]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_dq_finished,   th_dq_reset),
  // [td_sq]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_sq_finished,   th_sq_reset),

  [CL_SCL]   = ACTION_TAP_DANCE_DOUBLE(DE_COLN, DE_SCLN),
  [td_dc]    = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_COMM),
  [td_pm]    = ACTION_TAP_DANCE_DOUBLE(DE_PLUS, DE_MINS),
  [td_bq]    = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_bq_finished,   th_bq_reset),
  [td_ge_ae] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_ge_ae_finished, th_ge_ae_reset),
  [td_ge_oe] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_ge_oe_finished, th_ge_oe_reset),
  [td_ge_ue] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_ge_ue_finished, th_ge_ue_reset),
  [td_ge_ss] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_ge_ss_finished, th_ge_ss_reset),
  [td_to]    = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_to_finished,   th_to_reset),
  [td_dt]    = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_dt_finished,   th_dt_reset),
  [td_tbt]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_tbt_finished,  th_tbt_reset),
};
