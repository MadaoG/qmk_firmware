#include QMK_KEYBOARD_H

#define __GERMAN__ 0
#define __ENGLISH__ 1

#define __LANGUAGE__   __GERMAN__
#include "mappings.h"

enum {
    _EN_ = 0, // english layer
    _GE_,     // german layer
    _SM_,     // symbol layer
    _MV_,     // movement layer
    _NM_,     // digit layer
    _FN_,     // fn keys
    _SH_,     // gaming layer
};

// User defined functions which may refer to the above declared layers.
// Hence, including them afterwards.
#include "gauss.h"
#include "tap_functions.h"
#include "macro_functions.h"

#define _______ KC_TRNS
#define _xxxxx_ KC_NO

#define MV_WIN MT(MOD_LCTL | MOD_LGUI, KC_ESC)
#define MV_SCRN MT(MOD_LCTL | MOD_LALT, KC_ESC)
#define ALT_Y ALT_T(_Y)
#define SFT_Q SFT_T(_Q)
#define CTL_P CTL_T(_P)
#define ALT_DT ALT_T(_DOT)
#define SFT_CM SFT_T(_COMM)
#define CTL_M CTL_T(_M)
#define OS_SFTL OSM(MOD_LSFT)
#define SM_A LT(_SM_, (_A))
#define SM_R LT(_SM_, (_R))
#define NM_E LT(_NM_, (_E))
#define MV_N LT(_MV_, (_N))
#define OS_FN OSL(_FN_)
#define OS_GE OSL(_GE_)
#define is_shifted (keyboard_report->mods & MOD_BIT(KC_LSFT) || \
                   ((get_oneshot_mods() & MOD_BIT(KC_LSFT)) &&  \
                   !has_oneshot_mods_timed_out()))
#define LED_INTERVAL 2500
uint8_t last_layer = _EN_;

static bool was_shifted = false;
enum {
    UDS_ESC,
    EQL_DQT,
    MAGIC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 *  .---------.-------.-------.-------.-------.-------.-------.           .-------.-------.-------.-------.-------.-------.---------.
 *  |         |       |       |       |       |       |       |           |       |       |       |       |       |       |     _SH_ |
 *  |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|-------|           |-------|-------|-------|-------|-------|-------|---------|
 *  |         |       |  V    |  L    |  C    |  W    |       |           |       |  K    |  H    |  G    |  F    |       |         |
 *  |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|       |           |       |-------|-------|-------|-------|-------|---------|
 *  |   -     |  U    |  I    |  A    |  E    |  O    |_______|           |_______|  S    |  N    |  R    |  T    |  D    |         |
 *  |         |       |       |   _SM_|   _NM_|       |       |           |       |       |   _MV_|   _SM_|       |       |  SUPER  |
 *  |---------|-------|-------|-------|-------|-------|       |           |       |-------|-------|-------|-------|-------|---------|
 *  |   =     |  X    |  Y    |  Q    |  P    |  Z    |       |           |       |  B    |  M    |  ,    |  .    |  J    |         |
 *  |     "   |       |    ALT|    SFT|    CTL|       |       |           |       |       |    CTL|    SFT|    ALT|       |         |
 *  '---------|-------|-------|-------|-------|-------'-------'           '-------'-------|-------|-------|-------|-------|---------'
 *    |       |       |       |       |  :;   |                                           | ESC   |       | VOL M | VOL D | VOL U |
 *    |       |       |       |       |       |                                           |  _    |       |       |       |       |
 *    '-------'-------'-------'-------'-------'                                           '-------'-------'-------'-------'-------'
 *                                               .-------.-------.     .-------.-------.
 *                                               |   _GE_ |       |     |       |   _FN_ |
 *                                               |       |       |     |       |       |
 *                                       .-------|-------|-------|     |-------|-------|-------.
 *                                       |       |       |       |     |       |       |       |
 *                                       |       |       |       |     |       |       |       |
 *                                       | SHIFT |  TAB  |-------|     |-------| ENTER | SPACE |
 *                                       |       |       | BACK  |     | DEL   |       |       |
 *                                       |       |       | SPACE |     |       |       |       |
 *                                       '-------'-------'-------'     '-------'-------'-------'
 */

[_EN_] = LAYOUT_ergodox(

 _______,      _______,       _______,       _______,      _______,      _______,      _______,
 _______,      _______,       _V,            _L,           _C,           _W,           _______,
 _MINS,        _U,            _I,            SM_A,         NM_E,         _O,           /*___*/
 EQL_DQT,      _X,            ALT_Y,         SFT_Q,        CTL_P,        _Z,           MAGIC,
 _______,      _______,       _______,       _______,      T_CL,         /*___*/       /*___*/


                                                     /*___*/       _______,       _______,
                                                     /*___*/       /*___*/        _______,
                                                     OS_SFTL,      KC_TAB,        KC_BSPC,


 _______,      _______,       _______,       _______,      _______,      _______,      TG(_SH_),
 _______,      _K,            _H,            _G,           _F,           _______,      _______,
 /*___*/       _S,            MV_N,          SM_R,         _T,           _D,           KC_LGUI,
 _______,      _B,            CTL_M,         SFT_CM,       ALT_DT,       _J,           OS_GE,
 /*___*/       /*___*/        UDS_ESC,       _______,      KC_MUTE,      KC_VOLD,      KC_VOLU,


         _______,      OS_FN,         /*___*/
         _______,      /*___*/        /*___*/
         KC_DEL,       KC_ENT,        KC_SPACE

),

[_GE_] = LAYOUT_ergodox(

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _UE,         _______,      _AE,         _______,      _OE,            /*___*/
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      /*___*/       /*___*/
 _______, _______, _______,
 _______, _______, _______,

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 /*___*/       _SS,         _______,      _______,      _______,      _______,       _______,
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
 *  |         |       |  /    |  [    |  ]    |  @    |       |     |       |  ~    |  !    |  ?    |  &    |       |         |
 *  |         |       |       |       |       |       |       |     |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|       |     |       |-------|-------|-------|-------|-------|---------|
 *  |         |       |  |    |  {    |  }    |  *    |_______|     |_______|  ^    |  (    |  )    |  #    |       |         |
 *  |         |       |       |       |       |       |       |     |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|       |     |       |-------|-------|-------|-------|-------|---------|
 *  |         |       |  \    |  +    |  -    |  $    |       |     |       |  %    |  "    |  '    |  `    |  ´    |         |
 *  |         |       |       |       |       |       |       |     |       |       |       |       |       |       |         |
 *  '---------|-------|-------|-------|-------|-------'-------'     '-------'-------|-------|-------|-------|-------|---------'
 *    |       |       |       |       |  <    |                                     |  >    |       |       |       |       |
 *    |       |       |       |       |       |                                     |       |       |       |       |       |
 *    '-------'-------'-------'-------'-------'                                     '-------'-------'-------'-------'-------'
 */

[_SM_] = LAYOUT_ergodox(
 _______,      _______,       _______,       _______,       _______,       _______,       _______,
 _______,      _______,       _SLSH,        _LBRC,        _RBRC,        _AT,              _______,
 _______,      _______,       _PIPE,        _LCBR,        _RCBR,        _ASTR,            /*___*/
 _______,      _______,       _BSLS,        _PLUS,        _MINS,        _DLR,             _______,
 _______,      _______,       _______,       _______,       _LESS,
 _______, _______, _______,
 _______, _______, _______,

 _______,      _______,       _______,       _______,       _______,       _______,       _______,
 _______,      _TILD,        _EXLM,        _QST,         _AMPR,        _______,           _______,
 /*___*/       _HAT,         _LPRN,        _RPRN,        _HASH,        _______,           _______,
 _______,      _PERC,        _DQOT,        _QUOT,        _BKTK,        _TICK,             _______,
 /*___*/       /*___*/        _MORE,        _______,       _______,       _______,        _______,
 _______, _______, _______,
 _______, _______, _______
),

/*
 *  .---------.-------.-------.-------.-------.-------.-------.     .---
 *  |         |       |       |       |       |       |       |     |
 *  |         |       |       |       |       |       |       |     |
 *  |---------|-------|-------|-------|-------|-------|-------|     |---
 *  |         |       |       |  UP   |       |       |       |     |
 *  |         |       |       |       |       |       |       |     |
 *  |---------|-------|-------|-------|-------|-------|       |     |
 *  |         | START | LEFT  | DOWN  | RIGHT |  END  |_______|     |___
 *  |         |       |       |       |       |       |       |     |
 *  |---------|-------|-------|-------|-------|-------|       |     |
 *  |         |       | PAGE  |       | PAGE  |       |       |     |
 *  |         |       |   UP  |       |  DOWN |       |       |     |
 *  '---------|-------|-------|-------|-------|-------'-------'     '---
 *    |       |       |       |       |       |
 *    |       |       |       |       |       |
 *    '-------'-------'-------'-------'-------'
 */

 [_MV_] = LAYOUT_ergodox(

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
 *      |       |      |       |       |       |       |       |       |         |
 *  ----|       |      |       |-------|-------|-------|-------|-------|---------|
 *      |       |      |       |   ,   |   1   |   2   |   3   |       |         |
 *      |       |      |       |       |       |       |       |       |         |
 *  ----'-------'      '-------'-------|-------|-------|-------|-------|---------'
 *                                     |   0   |       |       |       |       |
 *                                     |       |       |       |       |       |
 *                                     '-------'-------'-------'-------'-------'
 */

[_NM_] = LAYOUT_ergodox(

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      KC_LGUI,      _______,      _______,      _______,      /*___*/
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,
 _______, _______, _______,
 _______, _______, _______,

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _HAT,         _7,           _8,           _9,           _______,       _______,
 /*___*/       _DOT,         _4,           _5,           _6,           _COLN,         _______,
 _______,      _COMM,        _1,           _2,           _3,           _______,       _______,
 /*___*/       /*___*/       _0,           _______,      _______,      _______,      _______,
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

[_FN_] = LAYOUT_ergodox(

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

[_SH_] = LAYOUT_ergodox(

 _______,      _1,           _2,           _3,           _4,           _5,           _______,
 _______,      _______,      _B,           _N,           _______,      _______,      KC_PPLS,
 _______,      _______,      _______,      _I,           KC_BTN1,      M(mc_sh_clicks),
 _______,      _______,      _M,           KC_SPACE,     _Z,           _P,           KC_PMNS,
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
        case MAGIC: {
            if (record->event.pressed) {
                if is_shifted {
                    // OS_GE;
                    // register_code(KC_LSFT);
                    // unregister_code(KC_LSFT);
                    // register_code(KC_1);
                    // unregister_code(KC_1);
                    // unregister_code(KC_LSFT);
                } else {
                    register_code(KC_2);
                    unregister_code(KC_2);
                    // register_code(KC_DOT);
                    // unregister_code(KC_DOT);
                }
            } else {
                // unregister_code(KC_1);
                // unregister_code(KC_LSFT);
                // unregister_code(KC_DOT);
            }
            return false;
        };

        case KC_DOT: {
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
        };

        case UDS_ESC: {
            uint8_t shifted = is_shifted;

            if (record->event.pressed) {
                was_shifted  = shifted;
                add_key(shifted ? _UNDS : KC_ESCAPE);
            }
            else {
                del_key(was_shifted ? _UNDS : KC_ESCAPE);
            }

            send_keyboard_report();
            return false;
        };

        case EQL_DQT: {
            uint8_t shifted = is_shifted;

            #if __LANGUAGE__ == __GERMAN__
                if (record->event.pressed) {
                    was_shifted  = shifted;
                    register_code(KC_LSFT);
                    add_key(shifted ? _DQOT : _0);
                }
                else {
                    unregister_code(KC_LSFT);
                    del_key(was_shifted ? _DQOT : _0);
                }
            #elif __LANGUAGE__ == __ENGLISH__
            #endif

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
    uint16_t time = timer_read() % LED_INTERVAL;

    if (layer == last_layer) {
      // update leds
      switch (layer) {
        case _GE_:
          ergodox_set_red(brightness_middle(time, 300));
          ergodox_set_green(brightness_middle(time, 500));
          ergodox_set_blue(brightness_middle(time, 700));
          break;
        case _EN_:
          ergodox_set_red(brightness_middle(time, 700));
          ergodox_set_green(brightness_middle(time, 500));
          ergodox_set_blue(brightness_middle(time, 300));
          break;
        case _SM_:
          ergodox_set_green(brightness_middle(time, 500));
          break;
        case _MV_:
          ergodox_set_blue(brightness_middle(time, 500));
          break;
        case _NM_:
          ergodox_set_blue(brightness_middle(time, 500));
          break;
        case _FN_:
          ergodox_set_red(brightness_fast(time, 300));
          ergodox_set_green(brightness_fast(time, 500));
          ergodox_set_blue(brightness_fast(time, 700));
          break;
        case _SH_:
          ergodox_set_red(brightness_middle(time, 500));
          ergodox_set_green(brightness_fast(time, 250) + brightness_fast(time, 750));
          ergodox_set_blue(brightness_middle(time, 0) + brightness_middle(time, 999));
          break;
        default:
          ergodox_board_led_off();
      }

    } else {
      last_layer = layer;
      // init leds
      ergodox_board_led_off();
      ergodox_right_led_1_off();
      ergodox_right_led_2_off();
      ergodox_right_led_3_off();
    }
}; // *-*
