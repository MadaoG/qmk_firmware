#include QMK_KEYBOARD_H

#define __GERMAN__ 0
#define __ENGLISH__ 1

#define __LANGUAGE__   __GERMAN__
#include "mappings.h"

enum {
    _EN = 0, // english layer
    _GE,     // german layer
    _GH,     // german layer
    _SM,     // symbol layer
    _MV,     // movement layer
    _NM,     // digit layer
    _FN,     // fn keys
    _SH,     // gaming layer
};

// User defined functions which may refer to the above declared layers.
// Hence, including them afterwards.
#include "gauss.h" // defines t
#include "tap_functions.h"
#include "macro_functions.h"

#define MV_WIN MT(MOD_LCTL | MOD_LGUI, KC_ESC)
#define MV_SCRN MT(MOD_LCTL | MOD_LALT, KC_ESC)
#define ALT_Y ALT_T(__Y)
#define SFT_Q SFT_T(__Q)
#define CTL_P CTL_T(__P)
#define ALT_DT ALT_T(__DOT)
#define SFT_CM SFT_T(__COMM)
#define CTL_M CTL_T(__M)
#define OS_SFTL OSM(MOD_LSFT)
#define OS_SFTR OSM(MOD_RSFT)
#define SM_A LT(_SM, (__A))
#define SM_R LT(_SM, (__R))
#define NM_E LT(_NM, (__E))
#define MV_N LT(_MV, (__N))
#define SM_ESC LT(_SM, (KC_ESC))
#define OS_FN OSL(_FN)
#define OS_GE OSL(_GE)
#define is_shifted (keyboard_report->mods & MOD_BIT(KC_LSFT) || \
                   ((get_oneshot_mods() & MOD_BIT(KC_LSFT)) &&  \
                   !has_oneshot_mods_timed_out()))
uint8_t last_layer = _EN;

static bool was_shifted = false;
enum {
    UDS_ESC,
    EQL_DQT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 *  .---------.-------.-------.-------.-------.-------.-------.           .-------.-------.-------.-------.-------.-------.---------.
 *  |         |       |       |       |       |       |       |           |       |       |       |       |       |       |     _SH |
 *  |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|-------|           |-------|-------|-------|-------|-------|-------|---------|
 *  |         |       |  V    |  L    |  C    |  W    |       |           |       |  K    |  H    |  G    |  F    |       |         |
 *  |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|       |           |       |-------|-------|-------|-------|-------|---------|
 *  |   -     |  U    |  I    |  A    |  E    |  O    |_______|           |_______|  S    |  N    |  R    |  T    |  D    |         |
 *  |         |       |       |    _SM|    _NM|       |       |           |       |       |    _MV|    _SM|       |       |  SUPER  |
 *  |---------|-------|-------|-------|-------|-------|       |           |       |-------|-------|-------|-------|-------|---------|
 *  |   =     |  X    |  Y    |  Q    |  P    |  Z    |       |           |       |  B    |  M    |  ,    |  .    |  J    |         |
 *  |     "   |       |    ALT|    SFT|    CTL|       |       |           |       |       |    CTL|    SFT|    ALT|       |         |
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

[_EN] = LAYOUT_ergodox(

 _______,      _______,       _______,       _______,      _______,      _______,      _______,
 _______,      _______,       __V,           __L,          __C,          __W,          _______,
 __MINS,       __U,           __I,           SM_A,         NM_E,         __O,          /*___*/
 EQL_DQT,      __X,           ALT_Y,         SFT_Q,        CTL_P,        __Z,          _______,
 _______,      _______,       _______,       _______,      T_CL,         /*___*/       /*___*/


                                                     /*___*/       TG(_GH),       _______,
                                                     /*___*/       /*___*/        _______,
                                                     OS_SFTL,      KC_TAB,        KC_BSPC,


 _______,      _______,       _______,       _______,      _______,      _______,      TG(_SH),
 _______,      __K,           __H,           __G,          __F,          _______,      _______,
 /*___*/       __S,           MV_N,          SM_R,         __T,          __D,          KC_LGUI,
 _______,      __B,           CTL_M,         SFT_CM,       ALT_DT,       __J,          _______,
 /*___*/       /*___*/        UDS_ESC,       _______,      KC_MUTE,      KC_VOLD,      KC_VOLU,


         _______,      OS_FN,         /*___*/
         _______,      /*___*/        /*___*/
         KC_DEL,       KC_ENT,        KC_SPACE

),

[_GH] = LAYOUT_ergodox(

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

[_GE] = LAYOUT_ergodox(

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      __UE,         _______,      __AE,         _______,       __OE,        /*___*/
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      /*___*/       /*___*/
 _______, _______, _______,
 _______, _______, _______,

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 /*___*/       __SS,         _______,      _______,      _______,      _______,      _______,
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

[_SM] = LAYOUT_ergodox(
 _______,      _______,       _______,       _______,       _______,       _______,       _______,
 _______,      _______,       __HASH,        __LBRC,        __RBRC,        __AT,          _______,
 _______,      __SLSH,        _______,       __LCBR,        __RCBR,        __ASTR,        /*___*/
 _______,      __PIPE,        __BSLS,        __PLUS,        __MINS,        __DLR,         _______,
 _______,      _______,       _______,       _______,       __LESS,
 _______, _______, _______,
 _______, _______, _______,

 _______,      _______,       _______,       _______,       _______,       _______,       _______,
 _______,      __TILD,        __EXLM,        __QST,         __AMPR,        _______,       _______,
 /*___*/       __HAT,         __LPRN,        __RPRN,        _______,       _______,       _______,
 _______,      __PERC,        __DQOT,        __QUOT,        __GRV,         __ACUT,       _______,
 /*___*/       /*___*/        __MORE,       _______,        _______,       _______,       _______,
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

 [_MV] = LAYOUT_ergodox(

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

[_NM] = LAYOUT_ergodox(

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      KC_LGUI,      _______,      _______,      _______,      /*___*/
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,
 _______, _______, _______,
 _______, _______, _______,

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      __HAT,        __7,          __8,          __9,          _______,      _______,
 /*___*/       __DOT,        __4,          __5,          __6,          __COLN,       _______,
 _______,      __COMM,       __1,          __2,          __3,          _______,      _______,
 /*___*/       /*___*/       __0,          _______,      _______,      _______,      _______,
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

[_FN] = LAYOUT_ergodox(

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

[_SH] = LAYOUT_ergodox(

 _______,      __1,          __2,          __3,          __4,          __5,          _______,
 _______,      _______,      __B,          __N,          _______,      _______,      KC_PPLS,
 _______,      _______,      _______,      __I,          KC_BTN1,      M(mc_sh_clicks),
 _______,      _______,      __M,          KC_SPACE,     __Z,          __P,          KC_PMNS,
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
                add_key(shifted ? __UNDS : KC_ESCAPE);
            }
            else {
                del_key(was_shifted ? __UNDS : KC_ESCAPE);
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
                    add_key(shifted ? __DQOT : __0);
                }
                else {
                    unregister_code(KC_LSFT);
                    del_key(was_shifted ? __DQOT : __0);
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
}; // *-*
