// {{{ SETUP
/* #include "ergodox.h" */
#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "keymap_extras/keymap_german.h"
#include "mousekey.h"
#include "gauss.h" // defines t
#include "tap_functions.h"

#define   _EN   0    // english layer
#define   _GE   1    // german layer
#define   _SM   2    // symbol layer
#define   _NSM  3
#define   _MV   4    // movement layer
#define   _NM   5    // digit layer
#define   _FN   6    // fn keys
#define   _GM   7    // gaming layer
#define   _MS   8    // mouse layer

#define   _BS   _EN  // setting the base layer

#define _______ KC_TRNS
#define mv_win MT(MOD_LCTL | MOD_LGUI, KC_ESC)
#define HAT M(1)

uint8_t last_layer = _BS; // check if layer was changed

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
  td_dc,

  td_ge_ue,
  td_ge_ae,
  td_ge_oe,
  td_ge_ss,

  td_to,
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
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|       |           |       |-------|-------|-------|-------|-------|---------|
    |         |   u   |   i   |   a   |   e   |   o   |_______|           |_______|   s   |   n   |   r   |   t   |   d   |         |
    |         |       |       |  _sm  |  _nm  |       |       |           |       |       |  _mv  |  _sm  |       |       |         |
    |---------|-------|-------|-------|-------|-------|       |           |       |-------|-------|-------|-------|-------|---------|
    |   osm   |   x   |   y   |   q   |   p   |   z   |       |           |       |   b   |   m   |   ,   |   .   |   j   |   osm   |
    |  l_sft  |       |  alt  | shift |  ctrl |       |       |           |       |       |  ctrl | shift |  alt  |       |  r_sft  |
    '---------|-------|-------|-------|-------|---------------'           '---------------|-------|-------|-------|-------|---------'
      |       | super |       |       |   :;  |                                           |  esc  |       |       |       |       |
      |       |       |       |       |       |                                           |       |       |       |       |       |
      '---------------------------------------'                                           '---------------------------------------'
                                                 .---------------.     .---------------.
                                                 |       | vol   |     |       |       |
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

 _______,            _______,            _______,          _______,           _______,          _______,            _______,
 TG(_MS),            _______,            DE_V,             DE_L,              DE_C,             DE_W,               _______,
 _______,            k_ue,               DE_I,             k_ae,              LT(_NM,DE_E),     k_oe,               /*---*/
 _______,            DE_X,               ALT_T(DE_Y),      SFT_T(DE_Q),       CTL_T(DE_P),      DE_Z,               _______,
 _______,            KC_LGUI,            _______,          _______,           TD(CT_CLN),       /*---*/             /*---*/
 //
 TO(_EN),            KC_VOLU,                              //
 KC_VOLD,                                                  // thumb      eys
 KC_TAB,             KC_BSPC,            KC_MUTE,          //
 //
 //
 _______,            _______,            _______,          _______,           _______,          _______,            TG(_GM),
 _______,            DE_K,               DE_H,             DE_G,              DE_F,             _______,            _______,
 /*---*/             k_ss,               LT(_MV,DE_N),     LT(_SM,DE_R),      DE_T,             DE_D,               _______,
 _______,            DE_B,               CTL_T(DE_M),      SFT_T(DE_COMM),    ALT_T(DE_DOT),    DE_J,               OSM(MOD_RSFT),
 /*---*/             /*---*/             KC_ESC,           _______,           _______,          _______,            _______,
 //
 _______,            _______,                              //
 _______,                                                  // thumb      eys
 KC_DEL,             KC_ENTER,           KC_SPACE          //
),

[_EN] = KEYMAP(

 _______,            _______,            _______,          _______,           _______,          _______,            _______,
 TG(_MS),            _______,            DE_V,             DE_L,              DE_C,             DE_W,               _______,
 _______,            DE_U,               DE_I,             LT(_NSM,DE_A),     LT(_NM,DE_E),     DE_O,               /*---*/
 OSM(MOD_LSFT),      DE_X,               ALT_T(DE_Y),      SFT_T(DE_Q),       CTL_T(DE_P),      DE_Z,               _______,
 _______,            KC_LGUI,            KC_UP,            MO(_FN),           TD(CT_CLN),       /*---*/             /*---*/
 //
 TO(_GE),            KC_VOLU,                              //
 KC_VOLD,                                                  // thumb      eys
 KC_TAB,             KC_BSPC,            KC_MUTE,          //
 //
 //
 _______,            _______,            _______,          _______,           _______,          _______,            TG(_GM),
 _______,            DE_K,               DE_H,             DE_G,              DE_F,             _______,            KC_NO,
 /*---*/             DE_S,               LT(_MV,DE_N),     LT(_NSM,DE_R),     DE_T,             DE_D,               _______,
 _______,            DE_B,               CTL_T(DE_M),      SFT_T(DE_COMM),    ALT_T(DE_DOT),    DE_J,               OSM(MOD_RSFT),
 /*---*/             /*---*/             KC_ESC,           _______,           _______,          _______,            KC_NO,
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
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      DE_LCBR,      DE_RCBR,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
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
     |         |       |       |  up   |       |       |       |         |       |   _   |   _   |   _   |   _   |   _   |    _    |
     |         |       |       |       |       |       |       |         |   _   |       |       |       |       |       |         |
     |---------|-------|-------|-------|-------|-------|       |         |       |-------|-------|-------|-------|-------|---------|
     |         | start | left  | down  | right |  end  |_______|         |_______|   _   |   _   |   _   |   _   |   _   |    _    |
     |         |       |       |       |       |       |       |         |       |       |       |       |       |       |         |
     |---------|-------|-------|-------|-------|-------|       |         |   _   |-------|-------|-------|-------|-------|---------|
     |         |       | page  |       | page  |       |       |         |       |   _   |   _   |   _   |   _   |   _   |    _    |
     |         |       |   up  |       |  down |       |       |         |       |       |       |       |       |       |         |
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
 _______,      _______,      _______,      KC_UP,        _______,      _______,      _______,
 _______,      KC_HOME,      KC_LEFT,      KC_DOWN,      KC_RGHT,      KC_END,       /*---*/
 _______,      _______,      KC_PGUP,      _______,      KC_PGDN,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,
 _______,      _______,                         //
 _______,                                       // thumb keys
 _______,      _______,      _______,           //

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 /*---*/       _______,      _______,      mv_win,       _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 /*---*/       /*---*/       _______,      _______,      _______,      _______,      _______,
 _______,      _______,                         //
 _______,                                       // thumb keys
 _______,      _______,      _______            //
 ),
// }}}

/* {{{ LAYER: NUMBERS
     .---------.-------.-------.-------.-------.-------.-------.          .---------------------------------------------------------.
     |         |       |       |       |       |       |       |          |       |       |       |       |       |       |         |
     |         |       |       |       |       |       |       |          |       |       |       |       |       |       |         |
     |---------|-------|-------|-------|-------|-------|-------|          |-------|-------|-------|-------|-------|-------|---------|
     |         |       |       |       |       |       |       |          |       |   ^   |   7   |   8   |   9   |       |         |
     |         |       |       |       |       |       |       |          |       |       |       |       |       |       |         |
     |---------|-------|-------|-------|-------|-------|       |          |       |-------|-------|-------|-------|-------|---------|
     |         |       |       |       |       |       |_______|          |_______|   .   |   4   |   5   |   6   |   :   |         |
     |         |       |       |       |       |       |       |          |       |   ,   |       |       |       |       |         |
     |---------|-------|-------|-------|-------|-------|       |          |       |-------|-------|-------|-------|-------|---------|
     |         |       |       |       |       |       |       |          |       |   +   |   1   |   2   |   3   |   *   |         |
     |         |       |       |       |       |       |       |          |       |   -   |       |       |       |   /   |         |
     '---------|-------|-------|-------|-------|---------------'          '---------------|-------|-------|-------|-------|---------'
       |       |       |       |       |       |                                          |   0   |       |       |       |       |
       |       |       |       |       |       |                                          |       |       |       |       |       |
       '-------'-------'-------'-------'-------'                                          '---------------------------------------'
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

[_NM] = KEYMAP(

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      KC_LGUI,      _______,      _______,      _______,      /*---*/
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,
 _______,      _______,                         //
 _______,                                       // thumb keys
 _______,      _______,      _______,           //

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      HAT,          DE_7,         DE_8,         DE_9,         _______,      _______,
 /*---*/       k_dc,         DE_4,         DE_5,         DE_6,         DE_COLN,      _______,
 _______,      k_pm,         DE_1,         DE_2,         DE_3,         k_to,         _______,
 /*---*/       /*---*/       DE_0,         _______,      _______,      _______,      _______,
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
    |    _    |   _   |   _   |   up  |   _   |   _   |       |           |       |   _   |   _   |   _   |   _   |   _   |    _    |
    |         |       |       |       |       |       |   _   |           |   _   |       |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|       |           |       |-------|-------|-------|-------|-------|---------|
    |    _    |   _   |  left |  down | right |   _   |_______|           |_______|   _   | left  | middle| right |   _   |    _    |
    |         |       |       |       |       |       |       |           |       |       |  click|  click|  click|       |         |
    |---------|-------|-------|-------|-------|-------|   _   |           |   _   |-------|-------|-------|-------|-------|---------|
    |    _    |   _   | wh_l  | wh_u  | wh_d  | wh_r  |       |           |       |   _   |  slow | medium|  fast |   _   |    _    |
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
 _______,      _______,      KC_WH_L,      KC_WH_U,      KC_WH_D,      KC_WH_R,      _______,
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
 _______,      _______,      _______            //
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

};
//  }}}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    /* ! Ä  § $ % / ä )= ( ` , ß . - Ö ö ; ' : _ " ü #  + & ? ^ Ü ' * ° */ 
    /* ! \" # $ % & ' () * + , - . / : ; < = > ? @ [ \\ ] ^ _ ` { | } ~ */
    if (record->event.pressed) {
//        switch(keycode) {
//
//        }
    }
    return true;
};


qk_tap_dance_action_t tap_dance_actions[] = {
  [CT_CLN]  = ACTION_TAP_DANCE_DOUBLE(DE_COLN, DE_SCLN),
  [DQ_T]    = ACTION_TAP_DANCE_DOUBLE(DE_DQOT, M(2)),
  [Q_BT]    = ACTION_TAP_DANCE_DOUBLE(DE_QUOT, DE_GRV),
  [td_dc]   = ACTION_TAP_DANCE_DOUBLE(DE_DOT, DE_COMM),

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

  [td_ge_ae]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_ge_ae_finished, th_ge_ae_reset),
  [td_ge_oe]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_ge_oe_finished, th_ge_oe_reset),
  [td_ge_ue]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_ge_ue_finished, th_ge_ue_reset),
  [td_ge_ss]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_ge_ss_finished, th_ge_ss_reset),

  [td_to]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_to_finished,   th_to_reset),
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
