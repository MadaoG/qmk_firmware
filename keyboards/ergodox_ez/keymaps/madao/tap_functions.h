
enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  TRIPLE_TAP = 5,
  TRIPLE_HOLD = 6,
  DOUBLE_SINGLE_TAP = 7
};

typedef struct {
  bool is_press_action;
  int state;
} tap;

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
  else return 8;
}

static tap xtap_state = {
  .is_press_action = true,
  .state = 0
};

void x_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP:        register_code(KC_X); break;
    case SINGLE_HOLD:       register_code(KC_LCTRL); break;
    case DOUBLE_TAP:        register_code(KC_ESC); break;
    case DOUBLE_HOLD:       register_code(KC_LALT); break;
    case DOUBLE_SINGLE_TAP: register_code(KC_X); unregister_code(KC_X); register_code(KC_X);
  }
}

void x_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP:        unregister_code(KC_X); break;
    case SINGLE_HOLD:       unregister_code(KC_LCTRL); break;
    case DOUBLE_TAP:        unregister_code(KC_ESC); break;
    case DOUBLE_HOLD:       unregister_code(KC_LALT);
    case DOUBLE_SINGLE_TAP: unregister_code(KC_X);
  }
  xtap_state.state = 0;
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

#define k_bq TD(td_bq)
#define k_elg TD(td_elg)
#define k_uag TD(td_uag)
#define k_bsp TD(td_bsp)
#define k_sh TD(td_sh)
#define k_pbbl TD(td_pbbl)
#define k_pbbr TD(td_pbbr)
#define k_dat TD(td_dat)
#define k_pa TD(td_pa)
#define k_pm TD(td_pm)
#define k_dq TD(td_dq)
#define k_sq TD(td_sq)

#define k_ae TD(td_ge_ae)
#define k_oe TD(td_ge_oe)
#define k_ue TD(td_ge_ue)
#define k_ss TD(td_ge_ss)

#define k_dc TD(td_dc)
#define k_to TD(td_to)

#define k_tbt TD(td_tbt)
#define k_dt TD(td_dt)