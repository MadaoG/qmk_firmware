#include QMK_KEYBOARD_H

#define __LANGUAGE__   LG__GERMAN__
#include "mappings.h"
#include "gauss.h"
#include "tap_functions.h"

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
#include "macro_functions.h"

uint8_t last_layer = _EN_;

static bool was_shifted = false;
enum {
    UDS_ESC,
    EQL_DQT,
    MGC_SFT_SM,
    MGC_SM_ESC,
    MGC_SFT_US,
    MGC_SFT_ESC,
};

void clear_all_mods(void) {
    clear_mods();
    clear_oneshot_mods();
    clear_weak_mods();
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 *  .---------.-------.-------.-------.-------.-------.-------.           .-------.-------.-------.-------.-------.-------.---------.
 *  |         |       |       |       |       |       |       |           |       |       |       |       |       |       |     _SH_|
 *  |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|-------|           |-------|-------|-------|-------|-------|-------|---------|
 *  |         |       |  V    |  L    |  C    |  W    |       |           |       |  K    |  H    |  G    |  F    |       |         |
 *  |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|       |           |       |-------|-------|-------|-------|-------|---------|
 *  |   -     |  U    |  I    |  A    |  E    |  O    |_______|           |_______|  S    |  N    |  R    |  T    |  D    |         |
 *  |    CAPS |       |       |   _SM_|   _NM_|       |       |           |       |       |   _MV_|   _SM_|       |       |  SUPER  |
 *  |---------|-------|-------|-------|-------|-------|       |           |       |-------|-------|-------|-------|-------|---------|
 *  |   =     |  X    |  Y    |  Q    |  P    |  Z    |       |           |       |  B    |  M    |  ,    |  .    |  J    |  OS_GE  |
 *  |     "   |       |    ALT|    SFT|    CTL|       |       |           |       |       |    CTL|    SFT|    ALT|       |         |
 *  '---------|-------|-------|-------|-------|-------'-------'           '-------'-------|-------|-------|-------|-------|---------'
 *    |       |       |       |       |  :;   |                                           | ESC   | OS_GE | VOL M | VOL D | VOL U |
 *    |       |       |       |       |       |                                           |  _    |       |       |       |       |
 *    '-------'-------'-------'-------'-------'                                           '-------'-------'-------'-------'-------'
 *                                               .-------.-------.     .-------.-------.
 *                                               |   _GE_|       |     |       |   _FN_|
 *                                               |       |       |     |       |       |
 *                                       .-------|-------|-------|     |-------|-------|-------.
 *                                       |       |       |       |     |       |       |       |
 *                                       |       |       |       |     |       |       |       |
 *                                       | SHIFT |  TAB  |-------|     |-------| ENTER | SPACE |
 *                                       |  OS_SM|       | BACK  |     | DEL   |       |       |
 *                                       |       |       | SPACE |     |       |       |       |
 *                                       '-------'-------'-------'     '-------'-------'-------'
 */

[_EN_] = LAYOUT_ergodox_wrapper(

    EMPTY_TOP_ROW,
 _______,      _______,       _V,            _L,           _C,           _W,           _______,
 _MINS,        _U,            _I,            SM_A,         NM_E,         _O,           /*___*/
 EQL_DQT,      _X,            ALT_Y,         SFT_Q,        CTL_P,        _Z,           _ESC,
 _______,      _______,       _______,       _______,      T_CL,         /*___*/       /*___*/


                                                     /*___*/       _______,       _______,
                                                     /*___*/       /*___*/        _______,
                                                     MGC_SFT_US,    KC_TAB,        KC_BSPC,


 _______,      _______,       _______,       _______,      _______,      _______,      TG(_SH_),
 _______,      _K,            _H,            _G,           _F,           _______,      _______,
 /*___*/       _S,            MV_N,          SM_R,         _T,           _D,           KC_LGUI,
 _______,      _B,            CTL_M,         SFT_CM,       ALT_DT,       _J,           OS_GE,

 /*___*/       /*___*/        MGC_SM_ESC,        OS_GE,        KC_MUTE,      KC_VOLD,      KC_VOLU,


         _______,      OS_FN,         /*___*/
         _______,      /*___*/        /*___*/
         KC_DEL,       KC_ENT,        KC_SPACE

),

[_GE_] = LAYOUT_ergodox_wrapper(

     EMPTY_TOP_ROW, EMPTY_TOP_ROW,

 _______,      _UE,          _______,      _AE,          _______,      _OE,          /*___*/

     EMPTY_TOP_ROW, EMPTY_BOTTOM_ROW, THUMBS,

     EMPTY_TOP_ROW, EMPTY_TOP_ROW,

 /*___*/       _SS,          _______,      _______,      _______,      _______,      _______,

     EMPTY_TOP_ROW, EMPTY_BOTTOM_ROW, THUMBS

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

[_SM_] = LAYOUT_ergodox_wrapper(
 _______,      _______,       _______,       _______,       _______,       _______,       _______,
 _______,      _______,       _SLSH,         _LBRC,         _RBRC,         _AT,           _______,
 _______,      _UNDS,         _PIPE,         _LCBR,         _RCBR,         _ASTR,         /*___*/
 _______,      _______,       _BSLS,         _PLUS,         _MINS,         _DLR,          _______,
 _______,      _______,       _______,       _______,       _LESS,
 THUMBS,

 _______,      _______,       _______,       _______,       _______,       _______,       _______,
 _______,      _TILD,         _EXLM,         _QST,          _AMPR,         _______,       _______,
 /*___*/       _HAT,          _LPRN,         _RPRN,         _HASH,         _______,       _______,
 _______,      _PERC,         _DQOT,         _QUOT,         _BKTK,         _TICK,         _______,
 /*___*/       /*___*/        _MORE,         _______,       _______,       _______,       _______,
 THUMBS
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

 [_MV_] = LAYOUT_ergodox_wrapper(

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      KC_UP,        _______,      _______,      _______,
 _______,      KC_HOME,      KC_LEFT,      KC_DOWN,      KC_RGHT,      KC_END,       /*___*/
 _______,      _______,      KC_PGUP,      _______,      KC_PGDN,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,
 THUMBS,

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 /*___*/       _______,      _______,      MV_WIN,       MV_SCRN,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 /*___*/       /*___*/       _______,      _______,      _______,      _______,      _______,
 THUMBS
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

[_NM_] = LAYOUT_ergodox_wrapper(

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      KC_LGUI,      _______,      _______,      _______,      /*___*/
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,
 THUMBS,

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _HAT,         _7,           _8,           _9,           _______,       _______,
 /*___*/       _DOT,         _4,           _5,           _6,           _COLN,         _______,
 _______,      _COMM,        _1,           _2,           _3,           _______,       _______,
 /*___*/       /*___*/       _0,           _______,      _______,      _______,      _______,
 THUMBS
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

[_FN_] = LAYOUT_ergodox_wrapper(

        EMPTY_HALF,

 _______,      _______,      KC_F10,       KC_F11,       KC_F12,       _______,      _______,
 _______,      _______,      KC_F7,        KC_F8,        KC_F9,        _______,      _______,
 /*___*/       _______,      KC_F4,        KC_F5,        KC_F6,        _______,      _______,
 _______,      _______,      KC_F1,        KC_F2,        KC_F3,        _______,      _______,
 /*___*/       /*___*/       _______,      _______,      _______,      _______,      _______,
 THUMBS
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

[_SH_] = LAYOUT_ergodox_wrapper(

 _______,      _1,           _2,           _3,           _4,           _5,           _______,
 _______,      _______,      _B,           _N,           _______,      _______,      KC_PPLS,
 _______,      _______,      _______,      _I,           KC_BTN1,      M(mc_sh_clicks),
 _______,      _______,      _M,           KC_SPACE,     _Z,           _P,           KC_PMNS,
 _______,      _______,      _______,      _______,      _______,
 THUMBS,

    EMPTY_HALF
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        // case MGC_SFT_SM:
        //     return true;
        //     // tap or hold for shift
        //     // tap when shifted for os to sm layer
        //     {
        //         if is_shifted // second tap: change to _SM_
        //         {
        //             clear_mods();
        //             if (record->event.pressed)
        //             {
        //                 set_oneshot_layer(_SM_, ONESHOT_START);
        //             }
        //             else
        //             {
        //                 clear_oneshot_layer_state(ONESHOT_PRESSED);
        //             }
        //         }
        //         else // first tap
        //         {
        //             if (record->event.pressed)
        //             {
        //                 set_mods(MOD_BIT(KC_LSFT));
        //                 set_oneshot_mods(MOD_LSFT);
        //             }
        //             else
        //             {
        //                 clear_oneshot_layer_state(ONESHOT_PRESSED);
        //                 clear_mods();
        //             }
        //         }
        //         return false;
        //     };

        case MGC_SFT_US:
            // tap once for os shift
            // hold for shift
            // shift and tap for underscore (including tapping twice)
            {
                if is_shifted // second tap: change to _SM_
                {
                    clear_mods();
                    if (record->event.pressed)
                    {
#if __LANGUAGE__ == LG__GERMAN__
                        register_code(KC_LSFT);
                        TAP_KEY(DE_MINS);
                        unregister_code(KC_LSFT);
#elif __LANGUAGE__ == LG__ENGLISH__
                        TAP_KEY(_UNDS);
#endif
                    }
                }
                else // first tap
                {
                    if (record->event.pressed)
                    {
                        clear_mods();
                        set_mods(MOD_BIT(KC_LSFT));
                        set_oneshot_mods(MOD_LSFT);
                    }
                    else
                    {
                        clear_oneshot_layer_state(ONESHOT_PRESSED);
                        clear_mods();
                    }
                }
                return false;
            };

        // case MGC_SFT_ESC:
        //     return true;
        //     // tap once for os shift
        //     // hold for shift
        //     // shift and tap for esc
        //     {
        //         if is_shifted // second tap: change to _SM_
        //         {
        //             clear_mods();
        //             if (record->event.pressed)
        //             {
        //                 TAP_KEY(_ESC);
        //             }
        //         }
        //         else // first tap
        //         {
        //             if (record->event.pressed)
        //             {
        //                 set_mods(MOD_BIT(KC_LSFT));
        //                 set_oneshot_mods(MOD_LSFT);
        //             }
        //             else
        //             {
        //                 clear_oneshot_layer_state(ONESHOT_PRESSED);
        //                 clear_mods();
        //             }
        //         }
        //         return false;
        //     };

        case MGC_SM_ESC:
            // tap or hold for sm layer
            // tap when shifted for esc
            {
            send_keyboard_report();
                if is_shifted
                {
                    if (record->event.pressed)
                    {
                        clear_oneshot_layer_state(ONESHOT_PRESSED);
                        clear_all_mods();
                        TAP_KEY(_ESC);
                        register_code(KC_LSFT);
                    }
                    else
                    {
                        // will land here from `esc`, always
                        // NOTE: will land here from oneshot commands if
                        //   - hold magic key
                        //   - tap and hold random key, eg `f`
                        //   - release magic key
                        //   - release `f`
                        clear_oneshot_layer_state(ONESHOT_PRESSED);
                        clear_all_mods();
                    }
                }
                else
                {
                    clear_all_mods();
                    clear_keys();
                    if (record->event.pressed)
                    {
                        set_oneshot_layer(_SM_, ONESHOT_START);
                    }
                    else
                    {
                        clear_oneshot_layer_state(ONESHOT_PRESSED);
                    }
                }
                return false;
            };

        case _MINS: {
                        if (record->event.pressed) {
                            if is_shifted {
                                clear_oneshot_mods();
                                clear_mods();
                                TAP_KEY(_CAPS);
                                return false;
                            } else {
                                TAP_KEY(_MINS);
                                return false;
                            }
                        }
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

#if __LANGUAGE__ == LG__GERMAN__
                          if (record->event.pressed) {
                              was_shifted  = shifted;
                              register_code(KC_LSFT);
                              add_key(shifted ? _DQOT : _0);
                          }
                          else {
                              unregister_code(KC_LSFT);
                              del_key(was_shifted ? _DQOT : _0);
                          }
#elif __LANGUAGE__ == LG__ENGLISH__
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
          ergodox_set_red(brightness_middle(time, 400) + brightness_middle(time, 700));
          ergodox_set_green(brightness_middle(time, 500));
          ergodox_set_blue(brightness_middle(time, 300) + brightness_fast(time, 600));
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
