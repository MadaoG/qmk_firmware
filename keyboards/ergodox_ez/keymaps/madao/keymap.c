#include QMK_KEYBOARD_H

enum {
    _EN_ = 0, // english layer
    _SF_,     // safety layer (safety first!)
    _GE_,     // german layer
    _SM_,     // symbol layer
    _MV_,     // movement layer
    _NM_,     // digit layer
    _FN_,     // fn keys
    _WK_,     // Wanikani layer
};

#define __LANGUAGE__   LG__GERMAN__
// User defined functions which may refer to the above declared layers.
// Hence, including them afterwards.
#include "gauss.h"
#include "mappings.h"
#include "macro_functions.h"
uint8_t last_layer = _EN_;

// static bool was_shifted = false;
static bool tap_nm = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 *  .---------.-------.-------.-------.-------.-------.-------.           .-------.-------.-------.-------.-------.-------.---------.
 *  |  SF     |       |       | PLAY  |       |       |       |           |       |       |       | C-F   | F11   |       |         |
 *  |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|-------|           |-------|-------|-------|-------|-------|-------|---------|
 *  |         |       |  V    |  L    |  C    |  W    |       |           |       |  K    |  H    |  G    |  F    |       |         |
 *  |         |       |       |       |       |       |  WK   |           |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|       |           |       |-------|-------|-------|-------|-------|---------|
 *  |   -     |  U    |  I    |  A    |  E    |  O    |_______|           |_______|  S    |  N    |  R    |  T    |  D    |  SUPER  |
 *  |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|       |           |       |-------|-------|-------|-------|-------|---------|
 *  |   =     |  X    |  Y    |  Q    |  P    |  Z    |       |           |       |  B    |  M    |  ,    |  .    |  J    |  LAYER  |
 *  |         |       |    ALT|    SFT|    CTL|       |       |           |       |       |    CTL|    SFT|    ALT|       |         |
 *  '---------|-------|-------|-------|-------|-------'-------'           '-------'-------|-------|-------|-------|-------|---------'
 *    |       |       |       |       |  NM   |                                           |  SM   | OS_GE | VOL M | VOL D | VOL U |
 *    |       |       |       |       |       |                                           |       |       |       |       |       |
 *    '-------'-------'-------'-------'-------'                                           '-------'-------'-------'-------'-------'
 *                                               .-------.-------.     .-------.-------.
 *                                               |       |       |     |       | FN    |
 *                                               |       |       |     |       |       |
 *                                       .-------|-------|-------|     |-------|-------|-------.
 *                                       |       |       |       |     | DEL   |       |       |
 *                                       | SHIFT |  TAB  |       |     |       | ENTER | SPACE |
 *                                       |       |       |-------|     |-------|       |       |
 *                                       |       |       | BACK  |     | ESC   |       |    _  |
 *                                       |       |       | SPACE |     |   DEL |       |       |
 *                                       '-------'-------'-------'     '-------'-------'-------'
 */


[_EN_] = LAYOUT_ergodox_wrapper(  // english layer

 TG_SF,        _______,      _______,      KC_MPLY,      _______,      _______,      _______,
 _______,      _CR,          _V,           _L,           _C,           _W,           TG_WK,
 _MINS,        _U,           _I,           _A,           _E,           _O,           /*___*/
 _EQL,         _X,           ALT_Y,        SFT_Q,        CTL_P,        _Z,           _CR,
 _______,      _______,      _______,      _______,      _S_NM,        /*___*/       /*___*/


                                                     /*___*/       _______,       _______,
                                                     /*___*/       /*___*/        _______,
                                                     OS_SFT,       _TAB,          _BSPACE,


 _______,      _______,      _______,      _C_F,         _F11,         _______,      _______,
 _______,      _K,           _H,           _G,           _F,           _______,      _______,
 /*___*/       _S,           MV_N,         _R,           _T,           _D,           _LGUI,
 _______,      _B,           CTL_M,        SFT_CM,       ALT_DT,       _J,           _CHLY,
 /*___*/       /*___*/       _S_SM,        OS_GE,        _MUTE,        _VOLD,        _VOLU,


         _______,      OS_FN,       /*___*/
         _DEL,         /*___*/      /*___*/
         _ESC_D,       _CR,         _M_SP

),

[_SF_] = LAYOUT_ergodox_wrapper(  // safety layer

 TO_EN,        _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      /*___*/
 _______,      _______,      _______,      _______,      _______,      _______,      _ESC,
 _______,      _______,      _______,      _______,      OS_NM,

 /*___*/      _______,      _______,
 /*___*/      /*___*/       _______,
 OS_SFT,      _TAB,         _BSPACE,

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 /*___*/       _______,      _______,      _______,      _______,      _______,      _______,
 _ESC,         _______,      _______,      _______,      _______,      _______,      _______,
 /*___*/       /*___*/       OS_SM,        _______,      _______,      _______,      _______,

 _______,      _______,      /*___*/
  /*___*/      /*___*/       _______,
 _DEL,         _ENTER,       _SPACE
 ),

#if __LANGUAGE__ == __GERMAN__
[_GE_] = LAYOUT_ergodox_wrapper(  // german layer

     EMPTY_TOP_ROW,
     EMPTY_TOP_ROW,
 _______,      _UE,      _______,      _AE,         _______,      _OE,          /*___*/
     EMPTY_TOP_ROW,
     EMPTY_BOTTOM_ROW,

     THUMBS,

     EMPTY_TOP_ROW,
     EMPTY_TOP_ROW,
 /*___*/      _SS,      _______,      _______,      _______,      _______,      _______,
     EMPTY_TOP_ROW,
     EMPTY_BOTTOM_ROW,

     THUMBS

),
#elif __LANGUAGE__ == LG__ENGLISH__
#endif

/*
 *  .---------.-------.-------.-------.-------.-------.-------.     .-------.-------.-------.-------.-------.-------.---------.
 *  |         |       |       |       |       |       |       |     |       |       |       |       |       |       |         |
 *  |         |       |       |       |       |       |       |     |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|-------|     |-------|-------|-------|-------|-------|-------|---------|
 *  |         |  <    |  /    |  [    |  ]    |  @    |       |     |       |  ~    |  !    |  ?    |       |  >    |         |
 *  |         |       |       |       |       |       |       |     |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|       |     |       |-------|-------|-------|-------|-------|---------|
 *  |         |  <    |  |    |  {    |  }    |  *    |_______|     |_______|  ^    |  (    |  )    |  >    |  #    |         |
 *  |         |       |       |       |       |       |       |     |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|       |     |       |-------|-------|-------|-------|-------|---------|
 *  |         |       |  \    |  +    |  -    |  $    |       |     |       |  %    |  "    |  '    |  `    |  ´    |         |
 *  |         |       |       |       |       |       |       |     |       |       |       |       |       |       |         |
 *  '---------|-------|-------|-------|-------|-------'-------'     '-------'-------|-------|-------|-------|-------|---------'
 *    |       |       |       |       |  &    |                                     |       |       |       |       |       |
 *    |       |       |       |       |       |                                     |       |       |       |       |       |
 *    '-------'-------'-------'-------'-------'                                     '-------'-------'-------'-------'-------'
 *                                              .-------.-------. .-------.-------.
 *                                              |       |       | |       |       |
 *                                              |       |       | |       |       |
 *                                      .-------|-------|-------| |-------|-------|-------.
 *                                      |       |       |       | |       |       |       |
 *                                      |  <    |  >    |       | |       |       |       |
 *                                      |       |       |-------| |-------|       |       |
 *                                      |       |       |       | |       |       |       |
 *                                      |       |       |       | |       |       |       |
 *                                      '-------'-------'-------' '-------'-------'-------'
 */

[_SM_] = LAYOUT_ergodox_wrapper(  // symbol layer

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _LESS,        _SLSH,        _LBRC,        _RBRC,        _AT,          _______,
 _______,      _LESS,        _PIPE,        _LCBR,        _RCBR,        _ASTR,        /*___*/
 _______,      _______,      _BSLS,        _PLUS,        _MINS,        _DLR,         _______,
 _______,      _______,      _______,      _______,      _AMPR,

 /*___*/      _______,      _______,
 /*___*/      /*___*/       _______,
 _LESS,       _MORE,        _______,

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _TILD,        _EXLM,        _QST,         _______,      _MORE,        _______,
 /*___*/       _HAT,         _LPRN,        _RPRN,        _MORE,        _HASH,        _______,
 _______,      _PERC,        _DQOT,        _QUOT,        _BKTK,        _TICK,        _______,
 /*___*/       /*___*/       _______,      _______,      _______,      _______,      _______,
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

[_MV_] = LAYOUT_ergodox_wrapper(  // movement layer

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      KC_UP,        _______,      _______,      _______,
 _______,      KC_HOME,      KC_LEFT,      KC_DOWN,      KC_RGHT,      KC_END,       /*___*/
 _______,      _______,      KC_PGUP,      _______,      KC_PGDN,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,
 THUMBS,

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      MV_PRG,       _______,      _______,      _______,
 /*___*/       _______,      _______,      MV_WIN,       MV_SCRN,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 /*___*/       /*___*/       _______,      _______,      _______,      _______,      _______,
 THUMBS
 ),

/*
 *  .---------.-------.-------.-------.-------.-------.-------.      .---------------------------------------------------------.
 *  |         |       |       |       |       |       |       |      |       |       |       |       |       |       |         |
 *  |         |       |       |       |       |       |       |      |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|-------|      |-------|-------|-------|-------|-------|-------|---------|
 *  |         |       | _     |  :    |  ;    |       |       |      |       |       |  7    |  8    |  9    |       |         |
 *  |         |       |       |       |       |       |       |      |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|       |      |       |-------|-------|-------|-------|-------|---------|
 *  |         |       | .     |  +    |  -    |  ^    |_______|      |_______|       |  4    |  5    |  6    |       |         |
 *  |         |       |       |       |       |       |       |      |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|       |      |       |-------|-------|-------|-------|-------|---------|
 *  |         |       | ,     |  *    |  /    |       |       |      |       |       |  1    |  2    |  3    |       |         |
 *  |         |       |       |       |       |       |       |      |       |       |       |       |       |       |         |
 *  '---------|-------|-------|-------|-------|-------'-------'      '-------'-------|-------|-------|-------|-------|---------'
 *    |       |       |       |       |       |                                      |  0    |       |       |       |       |
 *    |       |       |       |       |       |                                      |       |       |       |       |       |
 *    '-------'-------'-------'-------'-------'                                      '-------'-------'-------'-------'-------'
 */

[_NM_] = LAYOUT_ergodox_wrapper(  // digit layer

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _UNDS,        _COLN,        _SCLN,        _______,      _______,
 _______,      _______,      _DOT,         _PLUS,        _MINS,        _HAT,         /*___*/
 _______,      _______,      _COMM,        _ASTR,        _SLSH,        _______,      _______,
 _______,      _______,      _______,      _______,      _TTNM,
 THUMBS,

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _7,           _8,           _9,           _______,      _______,
 /*___*/       _______,      _4,           _5,           _6,           _______,      _______,
 _______,      _______,      _1,           _2,           _3,           _______,      _______,
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

[_FN_] = LAYOUT_ergodox_wrapper(  // fn keys

        EMPTY_HALF,

 _______,      _______,      KC_F10,       KC_F11,       KC_F12,       _______,      _______,
 _______,      _______,      KC_F7,        KC_F8,        KC_F9,        _______,      _______,
 /*___*/       _______,      KC_F4,        KC_F5,        KC_F6,        _______,      _______,
 _______,      _______,      KC_F1,        KC_F2,        KC_F3,        _______,      _______,
 /*___*/       /*___*/       _______,      _______,      _______,      _______,      _______,
 THUMBS
),

/*
 *  .---------.-------.-------.-------.-------.-------.-------.
 *  |         |       |       |       |       |       |       |
 *  |         |       |       |       |       |       |       |
 *  |---------|-------|-------|-------|-------|-------|-------|
 *  |         |       |       | UP    |       |       |       |
 *  |         |       |       |       |       |       |       |
 *  |---------|-------|-------|-------|-------|-------|       |
 *  |         |       | LEFT  | DOWN  | RIGHT |       |_______|
 *  |         |       |       |       |       |       |       |
 *  |---------|-------|-------|-------|-------|-------|       |
 *  |         |       | CLICK | VOL D | VOL U |       |       |
 *  |         |       |       |       |       |       |       |
 *  '---------|-------|-------|-------|-------|-------'-------'
 *    |       |       |       |       |  J    |
 *    |       |       |       |       |       |
 *    '-------'-------'-------'-------'-------'
 */

 [_WK_] = LAYOUT_ergodox_wrapper(

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      TO_EN,        _UP,          _______,      _______,      _______,
 _______,      _______,      _LEFT,        _DOWN,        _RIGHT,       _______,      /*---*/
 _______,      _______,      _CLICK,       _VOLD,        _VOLU,        _______,      _______,
 _______,      _______,      _______,      _______,      _J,

 THUMBS,

 EMPTY_HALF

 ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t os_mod;
    uint8_t s_mod;
    switch (keycode)
    {

        case _TTNM:
            // WIP
            {
                if (record->event.pressed) {
                    if (!tap_nm) {
                        // set layer to _NM_
                        layer_on(_NM_);
                        tap_nm = !tap_nm;
                    }
                    else
                    {
                        layer_on(_NM_);
                        tap_nm = !tap_nm;
                    }
                }
                return false;
            };

        case MGC_SPC:
            // tap for <space>, shift for `_`
            {
                if (is_shifted)
                {
                    if (record->event.pressed)
                    {
#if __LANGUAGE__ == LG__GERMAN__
                        TAP_KEY(DE_MINS);
#elif __LANGUAGE__ == LG__ENGLISH__
                        // clear_all_mods();
                        TAP_KEY(KC_MINS);
#endif
                    }
                    else
                    {
                    }
                }
                else
                {
                    if (record->event.pressed)
                    {
                        register_code(_SPACE);
                    }
                    else
                    {
                        unregister_code(_SPACE);
                    }
                }
                return false;
            };

        case MGC_ESC_DEL:
            // tap for `esc`, shift for `del`
            // TODO: buggy, works only one time
            {
                if (is_shifted)
                {
                    // save mods
                    os_mod = IS_SHIFTED_OS;
                    s_mod = IS_SHIFTED_LSFT;

                    // clear all mods so we can use all keys we like
                    clear_all_mods();
                    if (record->event.pressed)
                    {
#if __LANGUAGE__ == LG__GERMAN__
                        TAP_KEY(_DEL);
#elif __LANGUAGE__ == LG__ENGLISH__
                        TAP_KEY(_DEL);
#endif
                        // set the mods again. Otherwise this would not work
                        // when the os-shift is hold down
                        set_oneshot_mods(os_mod);
                        set_mods(s_mod);
                    }
                    else
                    {
                    }
                }
                else
                {
                    if (record->event.pressed)
                    {
                        register_code(_ESC);
                    }
                    else
                    {
                        unregister_code(_ESC);
                        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
                    }
                }
                return false;
            };

        case CTRL_F:
            {
                if (record->event.pressed)
                {
                    register_code(KC_LCTRL);
                    register_code(_F);
                }
                else
                {
                    unregister_code(_F);
                    unregister_code(KC_LCTRL);
                }
                return false;
            }

        case MGC_TEST:
            {
                if (is_shifted)
                {
                    os_mod = IS_SHIFTED_OS;
                    s_mod = IS_SHIFTED_LSFT;
                    clear_all_mods();

                    if (record->event.pressed)
                    {

                        // TAP1; // toggle
                        os_mod = IS_SHIFTED_OS;
                        s_mod = IS_SHIFTED_LSFT;
                        clear_all_mods();

#if __LANGUAGE__ == LG__GERMAN__
                        register_code(KC_LSFT);
                        register_code(KC_3); // toggle
#elif __LANGUAGE__ == LG__ENGLISH__
                        TAP_SFT(KC_3); // toggle
#endif
                        set_oneshot_mods(os_mod);
                        set_mods(s_mod);
                    }
                    else
                    {
                        // this never happens!
                    }
                }
                else
                {
                    if (record->event.pressed)
                    {
                        // TAP3; // toggle
                        register_code(_ENTER); // toggle
                    }
                    else
                    {
                        // UNTAP3; // toggle
                        // UNTAP1; // toggle
                        unregister_code(_ENTER); // toggle
                        unregister_code(KC_3); // toggle
                        unregister_code(KC_LSFT);
                    }
                }
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
            case _EN_:
                break;
            case _GE_:
                ergodox_set_red(brightness_middle(time, 300));
                ergodox_set_green(brightness_middle(time, 500));
                ergodox_set_blue(brightness_middle(time, 700));
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
            case _WK_:
                ergodox_set_red(brightness_middle(time, 400) + brightness_middle(time, 700));
                ergodox_set_green(brightness_middle(time, 500));
                ergodox_set_blue(brightness_middle(time, 300) + brightness_fast(time, 600));
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

// use this for layout pattern:
// \v^ *$\n *\zs((\S{2,},|\/\*___\*\/)\s*){4,}
// then, e.g. `g//normal gaip*l` for realigning
