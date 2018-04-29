#include QMK_KEYBOARD_H
#include "keymap_extras/keymap_german.h"
#include "mousekey.h"

#define   _EN   0    // english layer
#define   _GE   1    // german layer
#define   _GH   2    // german layer
#define   _SM   3    // symbol layer
#define   _MV   4    // movement layer
#define   _NM   5    // digit layer
#define   _FN   6    // fn keys
#define   _SH   7    // gaming layer
#define   _MS   8    // mouse layer

#define   _BS   _EN  // setting the base layer

// User defined functions which may refer to the above declared layers.
// Hence, including them afterwards.
#include "gauss.h" // defines t
#include "tap_functions.h"
#include "macro_functions.h"

#define MV_WIN MT(MOD_LCTL | MOD_LGUI, KC_ESC)
#define MV_SCRN MT(MOD_LCTL | MOD_LALT, KC_ESC)
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
#define SM_ESC LT(_SM, (KC_ESC))
#define OS_FN OSL(_FN)
#define OS_GE OSL(_GE)
#define is_shifted (keyboard_report->mods & MOD_BIT(KC_LSFT) || \
                   ((get_oneshot_mods() & MOD_BIT(KC_LSFT)) &&  \
                   !has_oneshot_mods_timed_out()))
uint8_t last_layer = _BS;

static bool grave_uds_was_shifted = false;
enum {
    UDS_ESC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 *  .---------.-------.-------.-------.-------.-------.-------.           .-------.-------.-------.-------.-------.-------.---------.
 *  |         |       |       |       |       |       |       |           |       |       |       |       |       |       |     _SH |
 *  |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|-------|           |-------|-------|-------|-------|-------|-------|---------|
 *  |         |       |  V    |  L    |  C    |  W    |       |           |       |  K    |  H    |  G    |  F    |       |     _MS |
 *  |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|       |           |       |-------|-------|-------|-------|-------|---------|
 *  |   =     |  U    |  I    |  A    |  E    |  O    |_______|           |_______|  S    |  N    |  R    |  T    |  D    |         |
 *  |         |       |       |    _SM|    _NM|       |       |           |       |       |    _MV|    _SM|       |       |  SUPER  |
 *  |---------|-------|-------|-------|-------|-------|       |           |       |-------|-------|-------|-------|-------|---------|
 *  |         |  X    |  Y    |  Q    |  P    |  Z    |       |           |       |  B    |  M    |  ,    |  .    |  J    |         |
 *  |         |       |    ALT|    SFT|    CTL|       |       |           |       |       |    CTL|    SFT|    ALT|       |         |
 *  '---------|-------|-------|-------|-------|-------'-------'           '-------'-------|-------|-------|-------|-------|---------'
 *    |       |       |       |       |  :;   |                                           | ESC   |       | VOL M | VOL D | VOL U |
 *    |       |       |       |       |       |                                           |  _    |       |       |       |       |
 *    '-------'-------'-------'-------'-------'                                           '-------'-------'-------'-------'-------'
 *                                               .-------.-------.     .-------.-------.
 *                                               |   _GE |       |     |       |   _FN |
 *                                               |       |       |     |       |       |
 *                                       .-------|-------|-------|     |-------|-------|-------.
 *                                       |       |       |       |     |       |       |       |
 *                                       |       |       |       |     |       |       |       |
 *                                       | SHIFT |  TAB  |-------|     |-------| ENTER | SPACE |
 *                                       |       |       | BACK  |     | DEL   |       |       |
 *                                       |       |       | SPACE |     |       |       |       |
 *                                       '-------'-------'-------'     '-------'-------'-------'
 */

[_EN] = KEYMAP(

 _______,      _______,       _______,       _______,      _______,      _______,      _______,
 _______,      _______,       DE_V,          DE_L,         DE_C,         DE_W,         _______,
 DE_EQL,       DE_U,          DE_I,          SM_A,         NM_E,         DE_O,         /*___*/
 _______,      DE_X,          ALT_Y,         SFT_Q,        CTL_P,        DE_Z,         TD(CT_LBP),
 _______,      _______,       _______,       _______,      T_CL,         /*___*/       /*___*/


                                                     /*___*/       TG(_GH),       _______,
                                                     /*___*/       /*___*/        _______,
                                                     OS_SFTL,      KC_TAB,        KC_BSPC,


 _______,      _______,       _______,       _______,      _______,      _______,      TG(_SH),
 _______,      DE_K,          DE_H,          DE_G,         DE_F,         _______,      TG(_MS),
 /*___*/       DE_S,          MV_N,          SM_R,         DE_T,         DE_D,         KC_LGUI,
 _______,      DE_B,          CTL_M,         SFT_CM,       ALT_DT,       DE_J,         _______,
 /*___*/       /*___*/        UDS_ESC,       _______,      KC_MUTE,      KC_VOLD,      KC_VOLU,


         _______,      OS_FN,         /*___*/
         _______,      /*___*/        /*___*/
         KC_DEL,       KC_ENT,        KC_SPACE

),

[_GH] = KEYMAP(

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      /*___*/
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      OS_GE,        /*___*/       /*___*/
 _______, _______, _______,
 _______, _______, _______,

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 /*___*/       _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 /*___*/       /*___*/       _______,      _______,      _______,      _______,      _______,
 _______, _______, _______,
 _______, _______, _______

),

[_GE] = KEYMAP(

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      DE_UE,        _______,      DE_AE,        _______,      DE_OE,        /*___*/
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      /*___*/       /*___*/
 _______, _______, _______,
 _______, _______, _______,

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 /*___*/       DE_SS,        _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 /*___*/       /*___*/       _______,      _______,      _______,      _______,      _______,
 _______, _______, _______,
 _______, _______, _______

),

/*
 *  .---------.-------.-------.-------.-------.-------.-------.     .-------.-------.-------.-------.-------.-------.---------.
 *  |         |       |       |       |       |       |       |     |       |       |       |       |       |       |         |
 *  |         |       |       |       |       |       |       |     |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|-------|     |-------|-------|-------|-------|-------|-------|---------|
 *  |         |       |  #    |  [    |  ]    |  @    |       |     |       |  ~    |  !    |  ?    |  &    |       |         |
 *  |         |       |       |       |       |       |       |     |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|       |     |       |-------|-------|-------|-------|-------|---------|
 *  |         |  /    |       |  {    |  }    |  *    |_______|     |_______|  ^    |  (    |  )    |       |       |         |
 *  |         |       |       |       |       |       |       |     |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|       |     |       |-------|-------|-------|-------|-------|---------|
 *  |         |  |    |  \    |  +    |  -    |  $    |       |     |       |  %    |  "    |  '    |  `    |  ´    |         |
 *  |         |       |       |       |       |       |       |     |       |       |       |       |       |       |         |
 *  '---------|-------|-------|-------|-------|-------'-------'     '-------'-------|-------|-------|-------|-------|---------'
 *    |       |       |       |       |  <    |                                     |  >    |       |       |       |       |
 *    |       |       |       |       |       |                                     |       |       |       |       |       |
 *    '-------'-------'-------'-------'-------'                                     '-------'-------'-------'-------'-------'
 */

[_SM] = KEYMAP(
 _______,      _______,       _______,       _______,       _______,       _______,       _______,
 _______,      _______,       DE_HASH,       DE_LBRC,       DE_RBRC,       DE_AT,         _______,
 _______,      DE_SLSH,       _______,       DE_LCBR,       DE_RCBR,       DE_ASTR,       /*___*/
 _______,      DE_PIPE,       DE_BSLS,       DE_PLUS,       DE_MINS,       DE_DLR,        _______,
 _______,      _______,       _______,       _______,       DE_LESS,
 _______, _______, _______,
 _______, _______, _______,

 _______,      _______,       _______,       _______,       _______,       _______,       _______,
 _______,      DE_TILD,       DE_EXLM,       DE_QST,        DE_AMPR,       _______,       _______,
 /*___*/       HAT,           DE_LPRN,       DE_RPRN,       _______,       _______,       _______,
 _______,      DE_PERC,       DE_DQOT,       DE_QUOT,       DE_GRV,        DE_ACUT,       _______,
 /*___*/       /*___*/        DE_MORE,       _______,       _______,       _______,       _______,
 _______, _______, _______,
 _______, _______, _______
),

/*
 *  .---------.-------.-------.-------.-------.-------.-------.     .-------.-------.-------.-------.-------.-------.---------.
 *  |         |       |       |       |       |       |       |     |       |       |       |       |       |       |         |
 *  |         |       |       |       |       |       |       |     |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|-------|     |-------|-------|-------|-------|-------|-------|---------|
 *  |         |       |       |  UP   |       |       |       |     |       |       |       |       |       |       |         |
 *  |         |       |       |       |       |       |       |     |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|       |     |       |-------|-------|-------|-------|-------|---------|
 *  |         | START | LEFT  | DOWN  | RIGHT |  END  |_______|     |_______|       |       |       |       |       |         |
 *  |         |       |       |       |       |       |       |     |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|       |     |       |-------|-------|-------|-------|-------|---------|
 *  |         |       | PAGE  |       | PAGE  |       |       |     |       |       |       |       |       |       |         |
 *  |         |       |   UP  |       |  DOWN |       |       |     |       |       |       |       |       |       |         |
 *  '---------|-------|-------|-------|-------|-------'-------'     '-------'-------|-------|-------|-------|-------|---------'
 *    |       |       |       |       |       |                                     |       |       |       |       |       |
 *    |       |       |       |       |       |                                     |       |       |       |       |       |
 *    '-------'-------'-------'-------'-------'                                     '-------'-------'-------'-------'-------'
 */

 [_MV] = KEYMAP(

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      KC_UP,        _______,      _______,      _______,
 _______,      KC_HOME,      KC_LEFT,      KC_DOWN,      KC_RGHT,      KC_END,       /*___*/
 _______,      _______,      KC_PGUP,      _______,      KC_PGDN,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,
 _______, _______, _______,
 _______, _______, _______,

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 /*___*/       _______,      _______,      MV_WIN,       MV_SCRN,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 /*___*/       /*___*/       _______,      _______,      _______,      _______,      _______,
 _______, _______, _______,
 _______, _______, _______
 ),

/*
 *  ----.-------.      .---------------------------------------------------------.
 *      |       |      |       |       |       |       |       |       |         |
 *      |       |      |       |       |       |       |       |       |         |
 *  ----|-------|      |-------|-------|-------|-------|-------|-------|---------|
 *      |       |      |       |   ^   |   7   |   8   |   9   |       |         |
 *      |       |      |       |       |       |       |       |       |         |
 *  ----|       |      |       |-------|-------|-------|-------|-------|---------|
 *      |_______|      |_______|   .   |   4   |   5   |   6   |   :   |         |
 *      |       |      |       |   ,   |       |       |       |       |         |
 *  ----|       |      |       |-------|-------|-------|-------|-------|---------|
 *      |       |      |       |   +   |   1   |   2   |   3   |   *   |         |
 *      |       |      |       |   -   |       |       |       |   /   |         |
 *  ----'-------'      '-------'-------|-------|-------|-------|-------|---------'
 *                                     |   0   |       |       |       |       |
 *                                     |       |       |       |       |       |
 *                                     '-------'-------'-------'-------'-------'
 */

[_NM] = KEYMAP(

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      KC_LGUI,      _______,      _______,      _______,      /*___*/
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,
 _______, _______, _______,
 _______, _______, _______,

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      HAT,          DE_7,         DE_8,         DE_9,         _______,      _______,
 /*___*/       T_DC,         DE_4,         DE_5,         DE_6,         DE_COLN,      _______,
 _______,      T_PM,         DE_1,         DE_2,         DE_3,         T_TO,         _______,
 /*___*/       /*___*/       DE_0,         _______,      _______,      _______,      _______,
 _______, _______, _______,
 _______, _______, _______
),

/*
 *  ----.-------.     .---------------------------------------------------------.
 *      |       |     |       |       |  F10  |  F11  |  F12  |       |         |
 *      |       |     |       |       |       |       |       |       |         |
 *  ----|-------|     |-------|-------|-------|-------|-------|-------|---------|
 *      |       |     |       |       |  F7   |  F8   |  F9   |       |         |
 *      |       |     |       |       |       |       |       |       |         |
 *  ----|       |     |       |-------|-------|-------|-------|-------|---------|
 *      |_______|     |_______|       |  F4   |  F5   |  F6   |       |         |
 *      |       |     |       |       |       |       |       |       |         |
 *  ----|       |     |       |-------|-------|-------|-------|-------|---------|
 *      |       |     |       |       |  F1   |  F2   |  F3   |       |         |
 *      |       |     |       |       |       |       |       |       |         |
 *  ----'-------'     '-------'-------|-------|-------|-------|-------|---------'
 *                                    |       |       |       |       |       |
 *                                    |       |       |       |       |       |
 *                                    '-------'-------'-------'-------'-------'
 */

[_FN] = KEYMAP(

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      /*___*/
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,
 _______, _______, _______,
 _______, _______, _______,

 _______,      _______,      KC_F10,       KC_F11,       KC_F12,       _______,      _______,
 _______,      _______,      KC_F7,        KC_F8,        KC_F9,        _______,      _______,
 /*___*/       _______,      KC_F4,        KC_F5,        KC_F6,        _______,      _______,
 _______,      _______,      KC_F1,        KC_F2,        KC_F3,        _______,      _______,
 /*___*/       /*___*/       _______,      _______,      _______,      _______,      _______,
 _______, _______, _______,
 _______, _______, _______
),

/*
 *  .---------.-------.-------.-------.-------.-------.-------.     .-------.-------.-------.-------.-------.-------.---------.
 *  |         |       |       |       |       |       |       |     |       |       |       |       |       |       |         |
 *  |         |       |       |       |       |       |       |     |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|-------|     |-------|-------|-------|-------|-------|-------|---------|
 *  |         |       |       |   UP  |       |       |       |     |       |       |       |       |       |       |         |
 *  |         |       |       |       |       |       |       |     |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|       |     |       |-------|-------|-------|-------|-------|---------|
 *  |         |       |  LEFT |  DOWN | RIGHT |       |_______|     |_______|       | LEFT  | MIDDLE| RIGHT |       |         |
 *  |         |       |       |       |       |       |       |     |       |       |  CLICK|  CLICK|  CLICK|       |         |
 *  |---------|-------|-------|-------|-------|-------|       |     |       |-------|-------|-------|-------|-------|---------|
 *  |         |       | WH_L  | WH_U  | WH_D  | WH_R  |       |     |       |       |  SLOW | MEDIUM|  FAST |       |         |
 *  |         |       |       |       |       |       |       |     |       |       |       |       |       |       |         |
 *  '---------|-------|-------|-------|-------|-------'-------'     '-------'-------|-------|-------|-------|-------|---------'
 *    |       |       |       |       |       |                                     |       |       |       |       |       |
 *    |       |       |       |       |       |                                     |       |       |       |       |       |
 *    '-------'-------'-------'-------'-------'                                     '-------'-------'-------'-------'-------'
 */

[_MS] = KEYMAP(
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      KC_MS_U,      _______,      _______,      _______,
 _______,      _______,      KC_MS_L,      KC_MS_D,      KC_MS_R,      _______,      /*___*/
 _______,      _______,      KC_WH_L,      KC_WH_U,      KC_WH_D,      KC_WH_R,      _______,
 _______,      _______,      _______,      _______,      _______,
 _______, _______, _______,
 _______, _______, _______,

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 /*___*/       _______,      KC_BTN1,      KC_BTN2,      KC_BTN3,      _______,      _______,
 _______,      _______,      KC_ACL0,      KC_ACL1,      KC_ACL2,      _______,      _______,
 /*___*/       /*___*/       _______,      _______,      _______,      _______,      _______,
 _______, _______, _______,
 _______, _______, _______
),

/*
    .---------.-------.-------.-------.-------.-------.-------.     .-------.---
    |         |  1    |  2    |  3    |  4    |  5    |       |     |       |
    |         |       |       |       |       |       |       |     |       |
    |---------|-------|-------|-------|-------|-------|-------|     |-------|---
    |         |       |  B    |  N    |       |       |       |     |       |
    |         |       |       |       |       |       |   +   |     |       |
    |---------|-------|-------|-------|-------|-------|       |     |       |---
    |         |       |       |  I    |LEFT   |REPEAT |_______|     |_______|
    |         |       |       |       | CLICK | CLICK |       |     |       |
    |---------|-------|-------|-------|-------|-------|   -   |     |       |---
    |         |       |  M    | SPACE |  Z    |  P    |       |     |       |
    |         |       |       |       |       |       |       |     |       |
    '---------|-------|-------|-------|-------|-------'-------'     '-------'---
      |       |       |       |       |       |
      |       |       |       |       |       |
      '-------'-------'-------'-------'-------'
 */

[_SH] = KEYMAP(

 _______,      DE_1,         DE_2,         DE_3,         DE_4,         DE_5,         _______,
 _______,      _______,      DE_B,         DE_N,         _______,      _______,      KC_PPLS,
 _______,      _______,      _______,      DE_I,         KC_BTN1,      M(mc_sh_clicks),
 _______,      _______,      DE_M,         KC_SPACE,     DE_Z,         DE_P,         KC_PMNS,
 _______,      _______,      _______,      _______,      _______,
 _______, _______, _______,
 _______, _______, _______,

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 /*___*/       _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 /*___*/       /*___*/       _______,      _______,      _______,      _______,      _______,
 _______, _______, _______,
 _______, _______, _______
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    /* ! Ä  § $ % / ä )= ( ` , ß . - Ö ö ; ' : _ " ü #  + & ? ^ Ü ' * ° */
    /* ! \" # $ % & ' () * + , - . / : ; < = > ? @ [ \\ ] ^ _ ` { | } ~ */
    switch (keycode) {
        case KC_DOT:
            if (record->event.pressed) {
                if is_shifted {
                    register_code(KC_LSFT);
                    register_code(KC_1);
                    unregister_code(KC_1);
                    unregister_code(KC_LSFT);
                } else {
                    register_code(KC_DOT);
                    unregister_code(KC_DOT);
                }
            } else {
                unregister_code(KC_1);
                unregister_code(KC_LSFT);
                unregister_code(KC_DOT);
            }
            return false;

        case UDS_ESC: {
            uint8_t shifted = is_shifted;

            if (record->event.pressed) {
                grave_uds_was_shifted  = shifted;
                add_key(shifted ? DE_UNDS : KC_ESCAPE);
            }
            else {
                del_key(grave_uds_was_shifted  ? DE_UNDS : KC_ESCAPE);
            }

        send_keyboard_report();
        return false;
        };
    };

    return true;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);
    t++; if (t >= 1000) t = 0;

    if (layer == last_layer) {
      // update leds
      switch (layer) {
        case _GE:
          ergodox_set_red(brightness_middle(300));
          ergodox_set_green(brightness_middle(500));
          ergodox_set_blue(brightness_middle(700));
          break;
        case _GH:
          ergodox_set_red(brightness_very_slow(500));
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
          ergodox_set_green(brightness_fast(250) + brightness_fast(750));
          ergodox_set_blue(brightness_middle(0) + brightness_middle(999));
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

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case KC_7:
//       if ((record->event.pressed) && (shift is active)) {
//         unregister_code(KC_LSFT);
//         register_code(KC_QUOT);
//       } else {
//         unregister_code(KC_QUOT);
//         register_code(KC_LSFT);
//       }
//       return false;
//   }
// }
