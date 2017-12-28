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
#define   _MV   3    // movement layer
#define   _NM   4    // digit layer
#define   _FN   5    // fn keys
#define   _SH   6    // gaming layer
#define   _MS   7    // mouse layer

#define   _BS   _EN  // setting the base layer

#define MV_WIN MT(MOD_LCTL | MOD_LGUI, KC_ESC)
#define HAT M(1)

#define ALT_Y ALT_T(DE_Y)
#define SFT_Q SFT_T(DE_Q)
#define CTL_P CTL_T(DE_P)
#define ALT_DT ALT_T(DE_DOT)
#define SFT_CM SFT_T(DE_COMM)
#define CTL_M CTL_T(DE_M)
#define OS_SFTL OSM(MOD_LSFT)
#define OS_SFTR OSM(MOD_RSFT)

#define L_SM(kc) LT(_SM, (kc))
#define L_MV(kc) LT(_MV, (kc))
#define L_NM(kc) LT(_NM, (kc))

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

  td_tbt,
  td_dt,
};

enum { mc_sh_clicks };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
    .---------------------------------------------------------.           .---------------------------------------------------------.
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |     _SH |
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|-------|           |-------|-------|-------|-------|-------|-------|---------|
    |         |       |  V    |  L    |  C    |  W    |       |           |       |  K    |  H    |  G    |  F    |       |     _MS |
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|       |           |       |-------|-------|-------|-------|-------|---------|
    |         |  U    |  I    |  A    |  E    |  O    |_______|           |_______|  S    |  N    |  R    |  T    |  D    |         |
    |         |       |       |    _SM|    _NM|       |       |           |       |       |    _MV|    _SM|       |       |         |
    |---------|-------|-------|-------|-------|-------|       |           |       |-------|-------|-------|-------|-------|---------|
    |         |  X    |  Y    |  Q    |  P    |  Z    |       |           |       |  B    |  M    |  ,    |  .    |  J    |         |
    | OS LSFT |       |    ALT|    SFT|    CTL|       |       |           |       |       |    CTL|    SFT|    ALT|       | OS RSFT |
    '---------|-------|-------|-------|-------|---------------'           '---------------|-------|-------|-------|-------|---------'
      |       | SUPER |       |       |  :;   |                                           | ESC   |       |       |       |       |
      |       |       |       |       |       |                                           |       |       |       |       |       |
      '---------------------------------------'                                           '---------------------------------------'
                                                 .---------------.     .---------------.
                                                 |   _EN | VOL U |     |       |       |
                                                 |       |       |     |       |       |
                                         .-------|-------|-------|     |-------|-------|-------.
                                         |       |       | VOL D |     |       |       |       |
                                         |       |       |       |     |       |       |       |
                                         |  TAB  | BACK  |-------|     |-------| ENTER | SPACE |
                                         |       | SPACE | VOL M |     | DEL   |       |       |
                                         |       |       |       |     |       |       |       |
                                         '-----------------------'     '-----------------------'
 */

[_EN] = KEYMAP(

 _______,            _______,            _______,          _______,           _______,          _______,            _______,
 _______,            _______,            DE_V,             DE_L,              DE_C,             DE_W,               _______,
 _______,            DE_U,               DE_I,             L_SM(DE_A),        L_NM(DE_E),       DE_O,               /*---*/
 OS_SFTL,            DE_X,               ALT_Y,            SFT_Q,             CTL_P,            DE_Z,               _______,
 _______,            KC_LGUI,            KC_UP,            MO(_FN),           TD(CT_CLN),       /*---*/             /*---*/
 //
 TO(_GE),            KC_VOLU,                              //
 KC_VOLD,                                                  // thumb keys
 KC_TAB,             KC_BSPC,            KC_MUTE,          //
 //
 //
 _______,            _______,            _______,          _______,           _______,          _______,            TG(_SH),
 _______,            DE_K,               DE_H,             DE_G,              DE_F,             _______,            TG(_MS),
 /*---*/             DE_S,               L_MV(DE_N),       L_SM(DE_R),        DE_T,             DE_D,               _______,
 _______,            DE_B,               CTL_M,            SFT_CM,            ALT_DT,           DE_J,               OS_SFTR,
 /*---*/             /*---*/             KC_ESC,           _______,           _______,          _______,            KC_NO,
 //
 _______,            _______,                              //
 _______,                                                  // thumb keys
 KC_DEL,             KC_ENTER,           KC_SPACE          //
),

[_GE] = KEYMAP(

 _______,            _______,            _______,          _______,           _______,          _______,            _______,
 _______,            _______,            DE_V,             DE_L,              DE_C,             DE_W,               _______,
 _______,            k_ue,               DE_I,             k_ae,              L_NM(DE_E),       k_oe,               /*---*/
 OS_SFTL,            DE_X,               ALT_Y,            SFT_Q,             CTL_P,            DE_Z,               _______,
 _______,            KC_LGUI,            _______,          _______,           TD(CT_CLN),       /*---*/             /*---*/
 //
 TO(_EN),            KC_VOLU,                              //
 KC_VOLD,                                                  // thumb keys
 KC_TAB,             KC_BSPC,            KC_MUTE,          //
 //
 //
 _______,            _______,            _______,          _______,           _______,          _______,            TG(_SH),
 _______,            DE_K,               DE_H,             DE_G,              DE_F,             _______,            TG(_MS),
 /*---*/             k_ss,               L_MV(DE_N),       L_SM(DE_R),        DE_T,             DE_D,               _______,
 _______,            DE_B,               CTL_M,            SFT_CM,            ALT_DT,           DE_J,               OS_SFTR,
 /*---*/             /*---*/             KC_ESC,           _______,           _______,          _______,            _______,
 //
 _______,            _______,                              //
 _______,                                                  // thumb keys
 KC_DEL,             KC_ENTER,           KC_SPACE          //
),

/* 
    .---------------------------------------------------------.           .---------------------------------------------------------.
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|-------|           |-------|-------|-------|-------|-------|-------|---------|
    |         |       |   #   |   [   |   ]   |   @   |       |           |       |   !   |   "   |   '   |   &   |       |         |
    |         |       |       |       |       |       |       |           |       |   ?   |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|       |           |       |-------|-------|-------|-------|-------|---------|
    |         |   <   |   >   |   {   |   }   |   ^   |_______|           |_______|   *   |   _   |   +   |   -   |   /   |         |
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|       |           |       |-------|-------|-------|-------|-------|---------|
    |         |   |   |   \   |   (   |   )   |   $   |       |           |       |   %   |   =   |   ,   |   .   |   ´   |         |
    |         |       |       |       |       |   ~   |       |           |       |       |       |       |       |   `   |         |
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

[_SM] = KEYMAP(
 _______,      _______,       _______,       _______,       _______,       _______,       _______,
 _______,      _______,       DE_HASH,       DE_LBRC,       DE_RBRC,       DE_AT,         _______,
 _______,      DE_LESS,       DE_MORE,       DE_LCBR,       DE_RCBR,       HAT,
 _______,      DE_PIPE,       DE_BSLS,       DE_LPRN,       DE_RPRN,       k_dt,          _______,
 _______,      _______,       _______,       _______,       _______,      
 _______,      _______,      
 _______,     
 _______,      _______,       _______,      

 _______,      _______,       _______,       _______,       _______,       _______,       _______,
 _______,      k_bq,          DE_DQOT,       DE_QUOT,       DE_AMPR,       _______,       _______,
 /*---*/       DE_ASTR,       DE_UNDS,       DE_PLUS,       DE_MINS,       DE_SLSH,       _______,
 _______,      DE_PERC,       DE_EQL,        DE_COMM,       DE_DOT,        k_tbt,         _______,
 /*---*/       /*---*/        _______,       _______,       _______,       _______,       _______,
 _______,      _______,      
 _______,     
 _______,      _______,       _______
),

/* 
     .---------------------------------------------------------.         .-------.-------.-------.-------.-------.-------.---------.
     |         |       |       |       |       |       |       |         |   _   |   _   |   _   |   _   |   _   |   _   |    _    |
     |         |       |       |       |       |       |       |         |       |       |       |       |       |       |         |
     |---------|-------|-------|-------|-------|-------|-------|         |-------|-------|-------|-------|-------|-------|---------|
     |         |       |       |  UP   |       |       |       |         |       |   _   |   _   |   _   |   _   |   _   |    _    |
     |         |       |       |       |       |       |       |         |   _   |       |       |       |       |       |         |
     |---------|-------|-------|-------|-------|-------|       |         |       |-------|-------|-------|-------|-------|---------|
     |         | START | LEFT  | DOWN  | RIGHT |  END  |_______|         |_______|   _   |   _   |   _   |   _   |   _   |    _    |
     |         |       |       |       |       |       |       |         |       |       |       |       |       |       |         |
     |---------|-------|-------|-------|-------|-------|       |         |   _   |-------|-------|-------|-------|-------|---------|
     |         |       | PAGE  |       | PAGE  |       |       |         |       |   _   |   _   |   _   |   _   |   _   |    _    |
     |         |       |   UP  |       |  DOWN |       |       |         |       |       |       |       |       |       |         |
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
 /*---*/       _______,      _______,      MV_WIN,       _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 /*---*/       /*---*/       _______,      _______,      _______,      _______,      _______,
 _______,      _______,                         //
 _______,                                       // thumb keys
 _______,      _______,      _______            //
 ),

/* 
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

/* 
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

/* 
    .---------.-------.-------.-------.-------.-------.-------.           .-------.-------.-------.-------.-------.-------.---------.
    |    _    |   _   |   _   |   _   |   _   |   _   |   _   |           |   _   |   _   |   _   |   _   |   _   |   _   |    _    |
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|-------|           |-------|-------|-------|-------|-------|-------|---------|
    |    _    |   _   |   _   |   UP  |   _   |   _   |       |           |       |   _   |   _   |   _   |   _   |   _   |    _    |
    |         |       |       |       |       |       |   _   |           |   _   |       |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|       |           |       |-------|-------|-------|-------|-------|---------|
    |    _    |   _   |  LEFT |  DOWN | RIGHT |   _   |_______|           |_______|   _   | LEFT  | MIDDLE| RIGHT |   _   |    _    |
    |         |       |       |       |       |       |       |           |       |       |  CLICK|  CLICK|  CLICK|       |         |
    |---------|-------|-------|-------|-------|-------|   _   |           |   _   |-------|-------|-------|-------|-------|---------|
    |    _    |   _   | WH_L  | WH_U  | WH_D  | WH_R  |       |           |       |   _   |  SLOW | MEDIUM|  FAST |   _   |    _    |
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

/* 
    .---------.-------.-------.-------.-------.-------.-------.           .-------.-------.-------.-------.-------.-------.---------.
    |         |   1   |   2   |   3   |   4   |   5   |       |           |       |       |       |       |       |       |         |
    |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|-------|           |-------|-------|-------|-------|-------|-------|---------|
    |         |       |   b   |   n   |       |       |       |           |       |       |       |       |       |       |         |
    |         |       |       |       |       |       |   +   |           |       |       |       |       |       |       |         |
    |---------|-------|-------|-------|-------|-------|       |           |       |-------|-------|-------|-------|-------|---------|
    |         |       |       |   i   | left  |repeat |_______|           |_______|       |       |       |       |       |         |
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
[_SH] = KEYMAP(

 _______,      DE_1,         DE_2,         DE_3,         DE_4,         DE_5,         _______,
 _______,      _______,      DE_B,         DE_N,         _______,      _______,      KC_PPLS,
 _______,      _______,      _______,      DE_I,         KC_BTN1,      M(mc_sh_clicks),
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

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    /* ! Ä  § $ % / ä )= ( ` , ß . - Ö ö ; ' : _ " ü #  + & ? ^ Ü ' * ° */ 
    /* ! \" # $ % & ' () * + , - . / : ; < = > ? @ [ \\ ] ^ _ ` { | } ~ */
    return true;
};


qk_tap_dance_action_t tap_dance_actions[] = {
  [CT_CLN]  = ACTION_TAP_DANCE_DOUBLE(DE_COLN, DE_SCLN),

  // [td_elg]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_elg_finished,  th_elg_reset),
  // [td_pbbl] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_pbbl_finished, th_pbbl_reset),
  // [td_pbbr] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_pbbr_finished, th_pbbr_reset),
  // [td_elg]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_elg_finished,  th_elg_reset),
  // [td_uag]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_uag_finished,  th_uag_reset),
  [td_bq]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_bq_finished,   th_bq_reset),
  // [td_bsp]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_bsp_finished,  th_bsp_reset),
  // [td_sh]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_sh_finished,   th_sh_reset),
  // [td_dat]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_dat_finished,  th_dat_reset),
  // [td_pa]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_pa_finished,   th_pa_reset),
  // [td_pm]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_pm_finished,   th_pm_reset),
  // [td_dq]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_dq_finished,   th_dq_reset),
  // [td_sq]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_sq_finished,   th_sq_reset),

  [td_ge_ae]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_ge_ae_finished, th_ge_ae_reset),
  [td_ge_oe]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_ge_oe_finished, th_ge_oe_reset),
  [td_ge_ue]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_ge_ue_finished, th_ge_ue_reset),
  [td_ge_ss]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_ge_ss_finished, th_ge_ss_reset),

  [td_to]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_to_finished,   th_to_reset),

  [td_dt]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_dt_finished,   th_dt_reset),
  [td_tbt]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_tbt_finished,  th_tbt_reset),
};



const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {

    if (record->event.pressed) {
      switch(id) {
        case mc_sh_clicks:
          for (int i = 0; i < 25; i++) {
            mousekey_on(KC_BTN1);
            mousekey_send();
            wait_ms(10);
            mousekey_off(KC_BTN1);
            mousekey_send();
            wait_ms(10);
          }
          break;
      }
    }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

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
        case _SH:
          ergodox_set_red(brightness_middle(500));
          ergodox_set_green(brightness_middle(250));
          ergodox_set_green(brightness_middle(750));
          ergodox_set_blue(brightness_middle(1));
          ergodox_set_blue(brightness_middle(999));
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
