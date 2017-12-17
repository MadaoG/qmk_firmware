// {{{ SETUP
/* #include "ergodox.h" */
#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "keymap_extras/keymap_german.h"
#include "mousekey.h"
#include "gauss.h" // defines t

// #define   _BS   0    // base layer
#define   _EN   0    // english layer
#define   _GE   1    // german layer
#define   _SM   2    // symbol layer
#define   _NSM  3
#define   _MV   4    // movement layer
#define   _NM   5    // digit layer
#define   _NS   6    // symbols for digit layer
#define   _FN   7    // fn keys
#define   _GM   8    // gaming layer
#define   _MS   9    // mouse layer
#define   _TM   10    // tmux layer
#define   _D    11   // empty (dumb) layer, may be useful as first reference


#define   _BS   _EN  // setting the base layer

#define _______ KC_TRNS

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

uint8_t last_layer = _BS; // check if layer was changed
 
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

// single quote
void th_dq_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP:  unregister_code(KC_2); unregister_code(KC_LSFT); break;
  }
  xtap_state.state = 0;
}

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



enum {
  // CT_CLN = SAFE_RANGE,
  CT_CLN,
  Q_BT,
  DQ_T,
  X_TAP_DANCE,
  X_TAP_TEST,

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
};
// }}}

// {{{ ALL LAYERS
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* {{{ LAYER: BASE

    .---------------------------------------------------------.           .---------------------------------------------------------.
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |   _GM   |
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|-------|           |-------|-------|-------|-------|-------|-------|---------|
    | tg _ms  |       |   v   |   l   |   c   |   w   |       |           |       |   k   |   h   |   g   |   f   |       |         |
    |         |       |       |       |       |       |   :   |           |   @   |       |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|       |           |       |-------|-------|-------|-------|-------|---------|
    |         |   u   |   i   |   a   |   e   |   o   |_______|           |_______|   s   |   n   |   r   |   t   |   d   |         |
    |         |       |       |  _sm  |  _nm  |       |       |           |       |       |  _mv  |  _sm  |       |       |         |
    |---------|-------|-------|-------|-------|-------|   _   |           |   \   |-------|-------|-------|-------|-------|---------|
    |   osm   |   x   |   y   |   q   |   p   |   z   |       |           |       |   b   |   m   |   ,   |   .   |   j   |   osm   |
    |  l_sft  |       |  alt  | shift |  ctrl |       |       |           |       |       |  ctrl | shift |  alt  |       |  r_sft  |
    '---------|-------|-------|-------|-------|---------------'           '---------------|-------|-------|-------|-------|---------'
      |       | super |   up  |       |   :;  |                                           |  esc  |       |       |       |       |
      |  _d   |       |       |  _fn  |       |                                           |       |  _tm  |       |       |       |
      '---------------------------------------'                                           '---------------------------------------'
                                                 .---------------.     .---------------.
                                                 |       | vol   |     | r_sft | lock  |
                                                 |  _en  |   up  |     |       |       |
                                         .-------|-------|-------|     |-------|-------|-------.
                                         |       |       | vol   |     |       |       |       |
                                         |       | back- |  down |     |       |       |       |
                                         |  tab  | space |-------|     |-------| enter | space |
                                         |       |       | vol   |     |  del  |       |       |
                                         |       |       |  mute |     |       |       |       |
                                         '-----------------------'     '-----------------------'
 */
[_GE] = KEYMAP(

 _______,            DE_1,               DE_2,             DE_3,              DE_4,             DE_5,               DE_ACUT,
 TG(_MS),            DE_X,               DE_V,             DE_L,              DE_C,             DE_W,               DE_COLN,
 _______,            DE_U,               DE_I,             LT(_SM,DE_A),      LT(_NM,DE_E),     DE_O,               /*---*/
 _______,            DE_UE,              ALT_T(DE_OE),     SFT_T(DE_AE),      CTL_T(DE_P),      DE_Z,               DE_UNDS,
 TG(_D),             KC_LGUI,            KC_UP,            MO(_FN),           TD(CT_CLN),       /*---*/             /*---*/
 //
 TO(_EN),            KC_VOLU,                              //
 KC_VOLD,                                                  // thumb      eys
 KC_TAB,             KC_BSPC,            KC_MUTE,          //
 //
 //
 DE_GRV,             DE_6,               DE_7,             DE_8,              DE_9,             DE_0,               TG(_GM),
 DE_AT,              DE_K,               DE_H,             DE_G,              DE_F,             DE_Q,               DE_SS,
 /*---*/             DE_S,               LT(_MV,DE_N),     LT(_SM,DE_R),      DE_T,             DE_D,               LT(_SM, DE_Y),
 DE_BSLS,            DE_B,               CTL_T(DE_M),      SFT_T(DE_COMM),    ALT_T(DE_DOT),    DE_J,               OSM(MOD_RSFT),
 /*---*/             /*---*/             KC_ESC,           TG(_TM),           _______,          _______,            KC_NO,
 //
 _______,            _______,                              //
 _______,                                                  // thumb      eys
 KC_DEL,             KC_ENTER,           KC_SPACE          //
),

[_EN] = KEYMAP(

 _______,            _______,            _______,          _______,           _______,          _______,            _______,
 TG(_MS),            _______,            DE_V,             DE_L,              DE_C,             DE_W,               _______,
 _______,            DE_U,               DE_I,             LT(_SM,DE_A),      LT(_NM,DE_E),     DE_O,               /*---*/
 OSM(MOD_LSFT),      DE_X,               ALT_T(DE_Y),      SFT_T(DE_Q),       CTL_T(DE_P),      DE_Z,               _______,
 TG(_D),             KC_LGUI,            KC_UP,            MO(_FN),           TD(CT_CLN),       /*---*/             /*---*/
 //
 TO(_GE),            KC_VOLU,                              //
 KC_VOLD,                                                  // thumb      eys
 KC_TAB,             KC_BSPC,            KC_MUTE,          //
 //
 //
 _______,            _______,            _______,          _______,           _______,          _______,            TG(_GM),
 _______,            DE_K,               DE_H,             DE_G,              DE_F,             _______,            KC_NO,
 /*---*/             DE_S,               LT(_MV,DE_N),     LT(_SM,DE_R),      DE_T,             DE_D,               _______,
 _______,            DE_B,               CTL_T(DE_M),      SFT_T(DE_COMM),    ALT_T(DE_DOT),    DE_J,               OSM(MOD_RSFT),
 /*---*/             /*---*/             KC_ESC,           TG(_NSM),           TD(X_TAP_DANCE),          TD(X_TAP_TEST),            KC_NO,
 //
 _______,            _______,                              //
 _______,                                                  // thumb      eys
 KC_DEL,             KC_ENTER,           KC_SPACE          //
),

// }}}

/* {{{ LAYER: SYMBOLS
    .---------------------------------------------------------.           .---------------------------------------------------------.
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|-------|           |-------|-------|-------|-------|-------|-------|---- ----|
    |         |       |   _   |   [   |   ]   |   ^   |       |           |       |   !   |   <   |   >   |   =   |   &   |         |
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|       |           |       |-------|-------|-------|-------|-------|---------|
    |         |   \   |   /   |   {   |   }   |   *   |_______|           |_______|   ?   |   (   |   )   |   -   |   @   |         |
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|       |           |       |-------|-------|-------|-------|-------|---------|
    |         |   #   |   $   |   |   |   ~   |       |       |           |       |   +   |   %   |   "   |   '   |   ;   |         |
    |         |       |       |       |       |       |       |           |       |       |       |   ´   |   `   |       |         |
    '---------|-------|-------|-------|-------|---------------'           '---------------|-------|-------|-------|-------|---------'
      |       |       |       |       |       |                                           |       |       |       |       |       |
      |       |       |       |       |       |                                           |       |       |       |       |       |
      '---------------------------------------'                                           '---------------------------------------'
                                                 .-------.-------.     .-------.-------.
                                                 |       |       |     |       |       |
                                                 |       |       |     |       |       |
                                         .-------|-------|-------|     |-------|-------|-------.
                                         |       |       |       |     |       |       |       |
                                         |       |       |       |     |       |       |       |
                                         |       |       |-------|     |-------|       |       |
                                         |       |       |       |     |       |       |       |
                                         |       |       |       |     |       |       |       |
                                         '-----------------------'     '-----------------------'
 */

[_NSM] = KEYMAP(
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      DE_UNDS,      DE_LBRC,      DE_RBRC,      M(1),      _______,
 _______,      DE_BSLS,      DE_SLSH,      DE_LCBR,      DE_RCBR,      DE_ASTR,
 _______,      DE_HASH,      DE_DLR,       DE_PIPE,      DE_TILD,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,
 _______,      _______,
 _______,
 _______,      _______,      _______,

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      k_bq,         k_elg,        k_uag,        k_bsp,        _______,      _______,
 /*---*/       k_sh,         k_pbbl,       k_pbbr,       k_dat,        _______,      _______,
 _______,      k_pa,         k_pm,         k_dq,         k_sq,         _______,      _______,
 /*---*/       /*---*/       _______,      _______,      _______,      _______,      _______,
 _______,      _______,
 _______,
 _______,      _______,      _______
),

[_SM] = KEYMAP(
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      DE_UNDS,      DE_LBRC,      DE_RBRC,      M(1),      _______,
 _______,      DE_BSLS,      DE_SLSH,      DE_LCBR,      DE_RCBR,      DE_ASTR,
 _______,      DE_HASH,      DE_DLR,       DE_PIPE,      DE_TILD,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,
 _______,      _______,
 _______,
 _______,      _______,      _______,

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      DE_EXLM,      DE_LESS,      DE_MORE,      DE_EQL,       DE_AMPR,      _______,
 /*---*/       DE_QST,       DE_LPRN,      DE_RPRN,      DE_MINS,      DE_AT,        _______,
 _______,      DE_PLUS,      DE_PERC,      TD(DQ_T),     TD(Q_BT),     DE_SCLN,      _______,
 /*---*/       /*---*/       _______,      _______,      _______,      _______,      _______,
 _______,      _______,
 _______,
 _______,      _______,      _______
),
// }}}

/* {{{ LAYER: MOVEMENTS
     .---------------------------------------------------------.         .-------.-------.-------.-------.-------.-------.---------.
     |         |       |       |       |       |       |       |         |   _   |   _   |   _   |   _   |   _   |   _   |    _    |
     |         |       |       |       |       |       |       |         |       |       |       |       |       |       |         |
     |---------|-------|-------|-------|-------|-------|-------|         |-------|-------|-------|-------|-------|-------|---------|
     |         | page  | back  |  up   |  del  | page  |       |         |       |   _   |   _   |   _   |   _   |   _   |    _    |
     |         |   up  |  space|       |       |  down |       |         |   _   |       |       |       |       |       |         |
     |---------|-------|-------|-------|-------|-------|       |         |       |-------|-------|-------|-------|-------|---------|
     |         | start | left  | down  | right |  end  |_______|         |_______|   _   |   _   |   _   |   _   |   _   |    _    |
     |         |       |       |       |       |       |       |         |       |       |       |       |       |       |         |
     |---------|-------|-------|-------|-------|-------|       |         |   _   |-------|-------|-------|-------|-------|---------|
     |         |       |       | prev  | next  |       |       |         |       |   _   |   _   |   _   |   _   |   _   |    _    |
     |         |       |       |       |       |       |       |         |       |       |       |       |       |       |         |
     '---------|-------|-------|-------|-------|---------------'         '---------------|-------|-------|-------|-------|---------'
       |       |       |       |       |       |                                         |   _   |   _   |   _   |   _   |   _   |
       |       |       |       |       |       |                                         |       |       |       |       |       |
       '---------------------------------------'                                         '-------'-------'-------'-------'-------'
                                                 .-------.-------.     .-------.-------.
                                                 |   _   |   _   |     |   _   |   _   |
                                                 |       |       |     |       |       |
                                         .-------|-------|-------|     |-------|-------|-------.
                                         |       |       |   _   |     |   _   |       |       |
                                         |       |       |       |     |       |       |       |
                                         |   _   |   _   |-------|     |-------|   _   |   _   |
                                         |       |       |   _   |     |   _   |       |       |
                                         |       |       |       |     |       |       |       |
                                         '-------'-------'-------'     '-------'-------'-------'
 */

 [_MV] = KEYMAP(

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      KC_PGUP,      KC_BSPC,      KC_UP,        KC_DEL,       KC_PGDN,      _______,
 _______,      KC_HOME,      KC_LEFT,      KC_DOWN,      KC_RGHT,      KC_END,       /*---*/
 _______,      _______,      _______,      KC_MPRV,      KC_MNXT,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,
 _______,      _______,                         //
 _______,                                       // thumb keys
 _______,      _______,      _______,           //

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 /*---*/       _______,      _______,      MT(MOD_LCTL | MOD_LGUI, KC_ESC),      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 /*---*/       /*---*/       _______,      _______,      _______,      _______,      _______,
 _______,      _______,                         //
 _______,                                       // thumb keys
 _______,      _______,      _______            //
 ),
// }}}

/* {{{ LAYER: NUMBERS
     .---------.-------.-------.-------.-------.-------.-------.          .---------------------------------------------------------.
     |         |       |       |       |       |       |       |          |       |       |   (   |   *   |   )   |       |         |
     |         |       |       |       |       |       |       |          |       |       |       |       |       |       |         |
     |---------|-------|-------|-------|-------|-------|-------|          |-------|-------|-------|-------|-------|-------|---------|
     |         |       |       |       |       |       |       |          |       |   +   |   7   |   8   |   9   |   -   |         |
     |         |       |       |       |       |       |       |          |       |       |       |       |       |       |         |
     |---------|-------|-------|-------|-------|-------|       |          |       |-------|-------|-------|-------|-------|---------|
     |         |       |       |       |       |       |_______|          |_______|   .   |   4   |   5   |   6   |   :   |         |
     |         |       |       |       |       |       |       |          |       |       |       |       |       |       |         |
     |---------|-------|-------|-------|-------|-------|       |          |       |-------|-------|-------|-------|-------|---------|
     |         |       |       |       |       |       |       |          |       |   ,   |   1   |   2   |   3   |   /   |         |
     |         |       |       |       |       |       |       |          |       |       |       |       |       |       |         |
     '---------|-------|-------|-------|-------|---------------'          '---------------|-------|-------|-------|-------|---------'
       |       |       |       |       |       |                                          |   [   |       |   ]   |       |       |
       |       |       |       |       |       |                                          |       |       |       |       |       |
       '-------'-------'-------'-------'-------'                                          '---------------------------------------'
                                                 .-------.-------.     .-------.-------.
                                                 |       |       |     |       |       |
                                                 |       |       |     |       |       |
                                         .-------|-------|-------|     |-------|-------|-------.
                                         |       |       |       |     |       |       |       |
                                         |       |       |       |     |       |       |       |
                                         |       |       |-------|     |-------|       |   0   |
                                         |       |       |       |     |       |       |       |
                                         |       |       |       |     |       |       |       |
                                         '-----------------------'     '-----------------------'
 */

[_NM] = KEYMAP(

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      KC_LGUI,      OSL(_NS),     _______,      _______,      /*---*/
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,
 _______,      _______,                         //
 _______,                                       // thumb keys
 _______,      _______,      _______,           //

 _______,      _______,      DE_LPRN,      DE_ASTR,      DE_RPRN,      _______,      _______,
 _______,      DE_PLUS,      DE_7,         DE_8,         DE_9,         DE_MINS,      _______,
 /*---*/       DE_DOT,       DE_4,         DE_5,         DE_6,         DE_COLN,      _______,
 _______,      DE_COMM,      DE_1,         DE_2,         DE_3,         DE_SLSH,      _______,
 /*---*/       /*---*/       DE_LBRC,      _______,      DE_RBRC,      _______,      _______,
 _______,      _______,                         //
 _______,                                       // thumb keys
 _______,      KC_SPACE,     DE_0               //
),
// }}}

/* {{{ LAYER: NUMBERS SUPPORT SYMBOLS
    .---------.-------.-------.-------.-------.-------.-------.           .-------.-------.-------.-------.-------.-------.---------.
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|-------|           |-------|-------|-------|-------|-------|-------|---------|
    |         |       |       |       |       |       |       |           |       |       |   {   |   }   |       |       |         |
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|       |           |       |-------|-------|-------|-------|-------|---------|
    |         |       |       |       |       |       |_______|           |_______|       |   (   |   )   |       |       |         |
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|       |           |       |-------|-------|-------|-------|-------|---------|
    |         |       |       |       |       |       |       |           |       |       |   [   |   ]   |       |       |         |
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    '---------|-------|-------|-------|-------|---------------'           '---------------|-------|-------|-------|-------|---------'
      |       |       |       |       |       |                                           |       |       |       |       |       |
      |       |       |       |       |       |                                           |       |       |       |       |       |
      '-------'-------'-------'-------'-------'                                           '-------'-------'-------'-------'-------'
                                                 .-------.-------.     .-------.-------.
                                                 |       |       |     |       |       |
                                                 |       |       |     |       |       |
                                         .-------|-------|-------|     |-------|-------|-------.
                                         |       |       |       |     |       |       |       |
                                         |       |       |       |     |       |       |       |
                                         |       |       |-------|     |-------|       |       |
                                         |       |       |       |     |       |       |       |
                                         |       |       |       |     |       |       |       |
                                         '-------'-------'-------'     '-------'-------'-------'
 */

 [_NS] = KEYMAP(
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      /*---*/
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,
 _______,      _______,                         //
 _______,                                       // thumb keys
 _______,      _______,      _______,           //

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      DE_LCBR,      DE_RCBR,      _______,      _______,      _______,
 /*---*/       _______,      DE_LPRN,      DE_RPRN,      _______,      _______,      _______,
 _______,      _______,      DE_LBRC,      DE_RBRC,      _______,      _______,      _______,
 /*---*/       /*---*/       _______,      _______,      _______,      _______,      _______,
 _______,      _______,                         //
 _______,                                       // thumb keys
 _______,      _______,      _______            //
 ),
// }}}

/* {{{ LAYER: FUNCTION KEYS
    .---------.-------.-------.-------.-------.-------.-------.           .---------------------------------------------------------.
    |         |       |       |       |       |       |       |           |       |       |  F10  |  F11  |  F12  |       |         |
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|-------|           |-------|-------|-------|-------|-------|-------|---------|
    |         |       |       |       |       |       |       |           |       |       |  F7   |  F8   |  F9   |       |         |
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|       |           |       |-------|-------|-------|-------|-------|---------|
    |         |       |       |       |       |       |_______|           |_______|       |  F4   |  F5   |  F6   |       |         |
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|       |           |       |-------|-------|-------|-------|-------|---------|
    |         |       |       |       |       |       |       |           |       |       |  F1   |  F2   |  F3   |       |         |
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    '---------|-------|-------|-------|-------|---------------'           '---------------|-------|-------|-------|-------|---------'
      |       |       |       |       |       |                                           |       |       |       |       |       |
      |       |       |       |       |       |                                           |       |       |       |       |       |
      '-------'-------'-------'-------'-------'                                           '---------------------------------------'
                                                 .-------.-------.     .-------.-------.
                                                 |       |       |     |       |       |
                                                 |       |       |     |       |       |
                                         .-------|-------|-------|     |-------|-------|-------.
                                         |       |       |       |     |       |       |       |
                                         |       |       |       |     |       |       |       |
                                         |       |       |-------|     |-------|       |       |
                                         |       |       |       |     |       |       |       |
                                         |       |       |       |     |       |       |       |
                                         '-----------------------'     '-----------------------'
 */
[_FN] = KEYMAP(

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      /*---*/
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,
 _______,      _______,                         //
 _______,                                       // thumb keys
 _______,      _______,      _______,           //

 _______,      _______,      KC_F10,       KC_F11,       KC_F12,       _______,      _______,
 _______,      _______,      KC_F7,        KC_F8,        KC_F9,        _______,      _______,
 /*---*/       _______,      KC_F4,        KC_F5,        KC_F6,        _______,      _______,
 _______,      _______,      KC_F1,        KC_F2,        KC_F3,        _______,      _______,
 /*---*/       /*---*/       _______,      _______,      _______,      _______,      _______,
 _______,      _______,                         //
 _______,                                       // thumb keys
 _______,      _______,      _______            //
),
// }}}

/* {{{ LAYER: MOUSE
    .---------.-------.-------.-------.-------.-------.-------.           .-------.-------.-------.-------.-------.-------.---------.
    |    _    |   _   |   _   |   _   |   _   |   _   |   _   |           |   _   |   _   |   _   |   _   |   _   |   _   |    _    |
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|-------|           |-------|-------|-------|-------|-------|-------|---------|
    |    _    |   _   |   _   |   _   |   _   |   _   |       |           |       |   _   |   _   |   _   |   _   |   _   |    _    |
    |         |       |       |       |       |       |   _   |           |   _   |       |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|       |           |       |-------|-------|-------|-------|-------|---------|
    |    _    |   _   |   _   |   _   |   _   |   _   |_______|           |_______|   _   |   _   |   _   |   _   |   _   |    _    |
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|   _   |           |   _   |-------|-------|-------|-------|-------|---------|
    |    _    |   _   |   _   |   _   |   _   |   _   |       |           |       |   _   |   _   |   _   |   _   |   _   |    _    |
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    '---------|-------|-------|-------|-------|---------------'           '---------------|-------|-------|-------|-------|---------'
      |   _   |   _   |   _   |   _   |   _   |                                           |   _   |   _   |   _   |   _   |   _   |
      |       |       |       |       |       |                                           |       |       |       |       |       |
      '-------'-------'-------'-------'-------'                                           '-------'-------'-------'-------'-------'
                                                 .-------.-------.     .-------.-------.
                                                 |   _   |   _   |     |   _   |   _   |
                                                 |       |       |     |       |       |
                                         .-------|-------|-------|     |-------|-------|-------.
                                         |       |       |   _   |     |   _   |       |       |
                                         |       |       |       |     |       |       |       |
                                         |   _   |   _   |-------|     |-------|   _   |   _   |
                                         |       |       |   _   |     |   _   |       |       |
                                         |       |       |       |     |       |       |       |
                                         '-------'-------'-------'     '-------'-------'-------'
 */

[_MS] = KEYMAP(
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      KC_MS_U,      _______,      _______,      _______,
 _______,      _______,      KC_MS_L,      KC_MS_D,      KC_MS_R,      _______,      /*---*/
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,
 _______,      _______,                         //
 _______,                                       // thumb keys
 _______,      _______,      _______,           //

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 /*---*/       _______,      KC_BTN1,      KC_BTN2,      KC_BTN3,      _______,      _______,
 _______,      _______,      KC_ACL0,      KC_ACL1,      KC_ACL2,      _______,      _______,
 /*---*/       /*---*/       _______,      _______,      _______,      _______,      _______,
 _______,      _______,                         //
 _______,                                       // thumb keys
 _______,      _______,      KC_RALT            //
),
//  }}}

/* {{{ LAYER: GAMING
    .---------.-------.-------.-------.-------.-------.-------.           .-------.-------.-------.-------.-------.-------.---------.
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|-------|           |-------|-------|-------|-------|-------|-------|---------|
    |         |       |   b   |   n   |       |       |       |           |       |       |       |       |       |       |         |
    |         |       |       |       |       |       |   +   |           |       |       |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|       |           |       |-------|-------|-------|-------|-------|---------|
    |         |       |       |       | left  |repeat |_______|           |_______|       |       |       |       |       |         |
    |         |       |       |       |  click| click |       |           |       |       |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|   -   |           |       |-------|-------|-------|-------|-------|---------|
    |         |       |   m   | space |   z   |   p   |       |           |       |       |       |       |       |       |         |
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    '---------|-------|-------|-------|-------|---------------'           '---------------|-------|-------|-------|-------|---------'
      |       |       |       |       |       |                                           |       |       |       |       |       |
      |       |       |       |       |       |                                           |       |       |       |       |       |
      '-------'-------'-------'-------'-------'                                           '-------'-------'-------'-------'-------'
                                                 .-------.-------.     .-------.-------.
                                                 |       |       |     |       |       |
                                                 |       |       |     |       |       |
                                         .-------|-------|-------|     |-------|-------|-------.
                                         |       |       |       |     |       |       |       |
                                         |       |       |       |     |       |       |       |
                                         |       |       |-------|     |-------|       |       |
                                         |       |       |       |     |       |       |       |
                                         |       |       |       |     |       |       |       |
                                         '-----------------------'     '-----------------------'
 */
[_GM] = KEYMAP(

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      DE_B,         DE_N,         _______,      _______,      KC_PPLS,
 _______,      _______,      _______,      _______,      KC_BTN1,      M(0),
 _______,      _______,      DE_M,         KC_SPACE,     DE_Z,         DE_P,         KC_PMNS,
 _______,      _______,      _______,      _______,      _______,
 _______,      _______,                         //
 _______,                                       // thumb keys
 _______,      _______,      _______,           //

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 /*---*/       _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 /*---*/       /*---*/       _______,      _______,      _______,      _______,      _______,
 _______,      _______,                         //
 _______,                                       // thumb keys
 _______,      _______,      _______            //
),
//  }}}

/*
    .---------.-------.-------.-------.-------.-------.-------.           .-------.-------.-------.-------.-------.-------.---------.
    |    _    |   _   |   _   |   _   |   _   |   _   |   _   |           |   _   |   _   |   _   |   _   |   _   |   _   |    _    |
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|-------|           |-------|-------|-------|-------|-------|-------|---------|
    |    _    |   _   |   _   |   _   |   _   |   _   |       |           |       |   _   |   _   |   _   |   _   |   _   |    _    |
    |         |       |       |       |       |       |   _   |           |   _   |       |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|       |           |       |-------|-------|-------|-------|-------|---------|
    |    _    |   _   |   _   |   _   |   _   |   _   |_______|           |_______|   _   |   _   |   _   |   _   |   _   |    _    |
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|   _   |           |   _   |-------|-------|-------|-------|-------|---------|
    |    _    |   _   |   _   |   _   |   _   |   _   |       |           |       |   _   |   _   |   _   |   _   |   _   |    _    |
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    '---------|-------|-------|-------|-------|---------------'           '---------------|-------|-------|-------|-------|---------'
      |   _   |   _   |   _   |   _   |   _   |                                           |   _   |   _   |   _   |   _   |   _   |
      |       |       |       |       |       |                                           |       |       |       |       |       |
      '-------'-------'-------'-------'-------'                                           '-------'-------'-------'-------'-------'
                                                 .-------.-------.     .-------.-------.
                                                 |   _   |   _   |     |   _   |   _   |
                                                 |       |       |     |       |       |
                                         .-------|-------|-------|     |-------|-------|-------.
                                         |       |       |   _   |     |   _   |       |       |
                                         |       |       |       |     |       |       |       |
                                         |   _   |   _   |-------|     |-------|   _   |   _   |
                                         |       |       |   _   |     |   _   |       |       |
                                         |       |       |       |     |       |       |       |
                                         '-------'-------'-------'     '-------'-------'-------'
 */

// [_TM] = KEYMAP(
//
// _______,      _______,      _______,      _______,      _______,      _______,      _______,
// _______,      _______,      _______,      tm_up,        _______,      _______,      _______,
// _______,      _______,      tm_left,      tm_down,      tm_right,     _______,      /*---*/
// _______,      _______,      _______,      _______,      _______,      _______,      _______,
// _______,      _______,      _______,      _______,      _______,
// _______,      _______,                         //
// _______,                                       // thumb keys
// _______,      _______,      _______,           //
//
// _______,      _______,      _______,      _______,      _______,      _______,      _______,
// _______,      _______,      _______,      _______,      _______,      _______,      _______,
// /*---*/       _______,      _______,      _______,      _______,      _______,      _______,
// _______,      _______,      _______,      _______,      _______,      _______,      _______,
// /*---*/       /*---*/       _______,      _______,      _______,      _______,      _______,
// _______,      _______,                         //
// _______,                                       // thumb keys
// _______,      _______,      _______            //
// ),
 
 

/* {{{ LAYER: DUMMY
    .---------.-------.-------.-------.-------.-------.-------.           .-------.-------.-------.-------.-------.-------.---------.
    |    _    |   _   |   _   |   _   |   _   |   _   |   _   |           |   _   |   _   |   _   |   _   |   _   |   _   |    _    |
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|-------|           |-------|-------|-------|-------|-------|-------|---------|
    |    _    |   _   |   _   |   _   |   _   |   _   |       |           |       |   _   |   _   |   _   |   _   |   _   |    _    |
    |         |       |       |       |       |       |   _   |           |   _   |       |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|       |           |       |-------|-------|-------|-------|-------|---------|
    |    _    |   _   |   _   |   _   |   _   |   _   |_______|           |_______|   _   |   _   |   _   |   _   |   _   |    _    |
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|   _   |           |   _   |-------|-------|-------|-------|-------|---------|
    |    _    |   _   |   _   |   _   |   _   |   _   |       |           |       |   _   |   _   |   _   |   _   |   _   |    _    |
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    '---------|-------|-------|-------|-------|---------------'           '---------------|-------|-------|-------|-------|---------'
      |   _   |   _   |   _   |   _   |   _   |                                           |   _   |   _   |   _   |   _   |   _   |
      |       |       |       |       |       |                                           |       |       |       |       |       |
      '-------'-------'-------'-------'-------'                                           '-------'-------'-------'-------'-------'
                                                 .-------.-------.     .-------.-------.
                                                 |   _   |   _   |     |   _   |   _   |
                                                 |       |       |     |       |       |
                                         .-------|-------|-------|     |-------|-------|-------.
                                         |       |       |   _   |     |   _   |       |       |
                                         |       |       |       |     |       |       |       |
                                         |   _   |   _   |-------|     |-------|   _   |   _   |
                                         |       |       |   _   |     |   _   |       |       |
                                         |       |       |       |     |       |       |       |
                                         '-----------------------'     '-----------------------'
 */

[_D] = KEYMAP(
 KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
 KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
 KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      /*---*/
 KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
 _______,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
 KC_NO,      KC_NO,                         //
 KC_NO,                                       // thumb keys
 KC_NO,      KC_NO,      KC_NO,           //

 KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
 KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
 /*---*/       KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
 KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
 /*---*/       /*---*/       KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
 KC_NO,      KC_NO,                         //
 KC_NO,                                       // thumb keys
 KC_NO,      KC_NO,      KC_NO            //
),
//  }}}

};
//  }}}

// led functions {{{
// }}}

// }}}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    /* ! Ä  § $ % / ä )= ( ` , ß . - Ö ö ; ' : _ " ü #  + & ? ^ Ü ' * ° */ 
    /* ! \" # $ % & ' () * + , - . / : ; < = > ? @ [ \\ ] ^ _ ` { | } ~ */
    if (record->event.pressed) {
//        switch(keycode) {
//          case tm_left:
//                SEND_STRING(SS_LCTRL("b")"> resiye/pane /L");
//                return false; break;
//          case tm_right:
//                SEND_STRING(SS_LCTRL("b")"> resiye/pane /R");
//                return false; break;
//          case tm_up:
//                SEND_STRING(SS_LCTRL("b")"> resiye/pane /U");
//                return false; break;
//          case tm_down:
//                SEND_STRING(SS_LCTRL("b")"> resiye/pane /D");
//                return false; break;
//        }
    }
    return true;
};


qk_tap_dance_action_t tap_dance_actions[] = {
  [CT_CLN]  = ACTION_TAP_DANCE_DOUBLE(DE_COLN, DE_SCLN),
  [DQ_T]    = ACTION_TAP_DANCE_DOUBLE(DE_DQOT, M(2)),
  [Q_BT]    = ACTION_TAP_DANCE_DOUBLE(DE_QUOT, DE_GRV),

  [td_elg]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_elg_finished,  th_elg_reset),
  [td_pbbl] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_pbbl_finished, th_pbbl_reset),
  [td_pbbr] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_pbbr_finished, th_pbbr_reset),
  [td_elg]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_elg_finished,  th_elg_reset),
  [td_uag]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_uag_finished,  th_uag_reset),
  [td_bq]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_bq_finished,   th_bq_reset),
  [td_bsp]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_bsp_finished,  th_bsp_reset),
  [td_sh]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_sh_finished,   th_sh_reset),
  [td_dat]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_dat_finished,  th_dat_reset),
  [td_pa]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_pa_finished,   th_pa_reset),
  [td_pm]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_pm_finished,   th_pm_reset),
  [td_dq]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_dq_finished,   th_dq_reset),
  [td_sq]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_sq_finished,   th_sq_reset),
};



const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {

    if (record->event.pressed) {
      switch(id) {
        case 0:
          for (int i = 0; i < 25; i++) {
            mousekey_on(KC_BTN1);
            mousekey_send();
            wait_ms(10);
            mousekey_off(KC_BTN1);
            mousekey_send();
            wait_ms(10);
          }
          break;

        case 1:
          register_code(DE_CIRC);
          unregister_code(DE_CIRC);
          register_code(DE_CIRC);
          unregister_code(DE_CIRC);
          break;

        case 2:
          register_code(DE_ACUT);
          unregister_code(DE_ACUT);
          register_code(DE_ACUT);
          unregister_code(DE_ACUT);
          break;

        case 3:
          // register_code(DE_GRV);
          // unregister_code(DE_GRV);
          // register_code(DE_GRV);
          // unregister_code(DE_GRV);
          break;
      }
    }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

LEADER_EXTERNS();
// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);
    t++; if (t >= 1000) { t = 0; }

    if (layer == last_layer) {
      // update leds
      switch (layer) {
        case _GE:
          ergodox_set_red(brightness_middle(300));
          ergodox_set_green(brightness_middle(500));
          ergodox_set_blue(brightness_middle(700));
          break;
        case _EN:
          ergodox_set_red(brightness_middle(700));
          ergodox_set_green(brightness_middle(500));
          ergodox_set_blue(brightness_middle(300));
          break;
        case _SM:
          ergodox_set_green(brightness_middle(500));
          break;
        case _MV:
          ergodox_set_blue(brightness_middle(500));
          break;
        case _NM:
          ergodox_set_blue(brightness_middle(500));
          break;
        case _NS:
          ergodox_set_blue(brightness_very_fast_double(250, 750));
          break;
        case _FN:
          ergodox_set_red(brightness_fast(300));
          ergodox_set_green(brightness_fast(500));
          ergodox_set_blue(brightness_fast(700));
          break;
        case _GM:
          ergodox_set_red(brightness_fast(700));
          ergodox_set_green(brightness_fast(500));
          ergodox_set_blue(brightness_fast(300));
          break;
        case _MS:
          ergodox_set_red(brightness_middle(500));
          ergodox_set_green(brightness_middle(500));
          break;
        case _TM:
          ergodox_set_red(10);
          break;
        case _D :
          ergodox_set_red(brightness_very_fast(450));
          ergodox_set_green(brightness_very_fast(500));
          ergodox_set_blue(brightness_very_fast(550));
          // pass
          break;
        default:
          ergodox_board_led_off();
      }

    } else {
      last_layer = layer;
      t = 0;
      // init leds
      ergodox_board_led_off();
      ergodox_right_led_1_off();
      ergodox_right_led_2_off();
      ergodox_right_led_3_off();
    }
};
