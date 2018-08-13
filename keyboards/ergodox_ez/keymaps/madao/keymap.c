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
#include "gauss.h"
#include "tap_functions.h"
#include "macro_functions.h"

#define _______ KC_TRNS
#define ___x___ KC_NO

#define MV_WIN MT(MOD_LCTL | MOD_LGUI, KC_ESC)
#define MV_SCRN MT(MOD_LCTL | MOD_LALT, KC_ESC)
#define ALT_Y ALT_T(i_Y)
#define SFT_Q SFT_T(i_Q)
#define CTL_P CTL_T(i_P)
#define ALT_DT ALT_T(i_DOT)
#define SFT_CM SFT_T(i_COMM)
#define CTL_M CTL_T(i_M)
#define OS_SFTL OSM(MOD_LSFT)
#define SM_A LT(_SM, (i_A))
#define SM_R LT(_SM, (i_R))
#define NM_E LT(_NM, (i_E))
#define MV_N LT(_MV, (i_N))
#define OS_FN OSL(_FN)
#define OS_GE OSL(_GE)
#define is_shifted (keyboard_report->mods & MOD_BIT(KC_LSFT) || \
                   ((get_oneshot_mods() & MOD_BIT(KC_LSFT)) &&  \
                   !has_oneshot_mods_timed_out()))
#define LED_INTERVAL 2500
uint8_t last_layer = _EN;

static bool was_shifted = false;
enum {
    UDS_ESC,
    EQL_DQT,
    MAGIC,
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

 ___x___,      ___x___,       ___x___,       ___x___,      ___x___,      ___x___,      ___x___,
 ___x___,      ___x___,       i_V,           i_L,          i_C,          i_W,          ___x___,
 i_MINS,       i_U,           i_I,           SM_A,         NM_E,         i_O,          /*___*/
 EQL_DQT,      i_X,           ALT_Y,         SFT_Q,        CTL_P,        i_Z,          MAGIC,
 ___x___,      ___x___,       ___x___,       ___x___,      T_CL,         /*___*/       /*___*/


                                                     /*___*/       TG(_GH),       ___x___,
                                                     /*___*/       /*___*/        ___x___,
                                                     OS_SFTL,      KC_TAB,        KC_BSPC,


 ___x___,      ___x___,       ___x___,       ___x___,      ___x___,      ___x___,      TG(_SH),
 ___x___,      i_K,           i_H,           i_G,          i_F,          ___x___,      ___x___,
 /*___*/       i_S,           MV_N,          SM_R,         i_T,          i_D,          KC_LGUI,
 ___x___,      i_B,           CTL_M,         SFT_CM,       ALT_DT,       i_J,          ___x___,
 /*___*/       /*___*/        UDS_ESC,       ___x___,      KC_MUTE,      KC_VOLD,      KC_VOLU,


         ___x___,      OS_FN,         /*___*/
         ___x___,      /*___*/        /*___*/
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
 _______,      i_UE,         _______,      i_AE,         _______,       i_OE,        /*___*/
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      /*___*/       /*___*/
 _______, _______, _______,
 _______, _______, _______,

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 /*___*/       i_SS,         _______,      _______,      _______,      _______,      _______,
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
 _______,      _______,       i_HASH,        i_LBRC,        i_RBRC,        i_AT,          _______,
 _______,      i_SLSH,        _______,       i_LCBR,        i_RCBR,        i_ASTR,        /*___*/
 _______,      i_PIPE,        i_BSLS,        i_PLUS,        i_MINS,        i_DLR,         _______,
 _______,      _______,       _______,       _______,       i_LESS,
 _______, _______, _______,
 _______, _______, _______,

 _______,      _______,       _______,       _______,       _______,       _______,       _______,
 _______,      i_TILD,        i_EXLM,        i_QST,         i_AMPR,        _______,       _______,
 /*___*/       i_HAT,         i_LPRN,        i_RPRN,        _______,       _______,       _______,
 _______,      i_PERC,        i_DQOT,        i_QUOT,        i_GRV,         i_ACUT,       _______,
 /*___*/       /*___*/        i_MORE,       _______,        _______,       _______,       _______,
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
 _______,      i_HAT,        i_7,          i_8,          i_9,          _______,      _______,
 /*___*/       i_DOT,        i_4,          i_5,          i_6,          i_COLN,       _______,
 _______,      i_COMM,       i_1,          i_2,          i_3,          _______,      _______,
 /*___*/       /*___*/       i_0,          _______,      _______,      _______,      _______,
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

 _______,      i_1,          i_2,          i_3,          i_4,          i_5,          _______,
 _______,      _______,      i_B,          i_N,          _______,      _______,      KC_PPLS,
 _______,      _______,      _______,      i_I,          KC_BTN1,      M(mc_sh_clicks),
 _______,      _______,      i_M,          KC_SPACE,     i_Z,          i_P,          KC_PMNS,
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
                add_key(shifted ? i_UNDS : KC_ESCAPE);
            }
            else {
                del_key(was_shifted ? i_UNDS : KC_ESCAPE);
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
                    add_key(shifted ? i_DQOT : i_0);
                }
                else {
                    unregister_code(KC_LSFT);
                    del_key(was_shifted ? i_DQOT : i_0);
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
        case _GE:
          ergodox_set_red(brightness_middle(time, 300));
          ergodox_set_green(brightness_middle(time, 500));
          ergodox_set_blue(brightness_middle(time, 700));
          break;
        case _GH:
          ergodox_set_red(brightness_very_slow(time, 500));
          break;
        case _EN:
          ergodox_set_red(brightness_middle(time, 700));
          ergodox_set_green(brightness_middle(time, 500));
          ergodox_set_blue(brightness_middle(time, 300));
          break;
        case _SM:
          ergodox_set_green(brightness_middle(time, 500));
          break;
        case _MV:
          ergodox_set_blue(brightness_middle(time, 500));
          break;
        case _NM:
          ergodox_set_blue(brightness_middle(time, 500));
          break;
        case _FN:
          ergodox_set_red(brightness_fast(time, 300));
          ergodox_set_green(brightness_fast(time, 500));
          ergodox_set_blue(brightness_fast(time, 700));
          break;
        case _SH:
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
