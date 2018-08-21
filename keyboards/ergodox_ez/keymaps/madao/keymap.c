#include QMK_KEYBOARD_H

#define __LANGUAGE__   LG__GERMAN__
#include "mappings.h"
#include "gauss.h"
#include "tap_functions.h"

enum {
    _EN_ = 0, // english layer
    _SF_,     // safety layer (safety first!)
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
    UDS_ESC = SAFE_RANGE,
    EQL_DQT,
    MGC_SFT_SM,
    MGC_SM_ESC,
    MGC_SM_US,
    MGC_SFT_PRC,
    MGC_SFT_US,
    MGC_SFT_ESC,
    MGC_PLS,
    MGC_NM_SCL,
    MGC_MNS,
    MGC_SPC_ESC,
    MGC_CR_CL,
    TMUX_LDR,
};

#define M_S_SM  MGC_SFT_SM
#define M_SM_E  MGC_SM_ESC
#define M_SM_U  MGC_SM_US
#define M_S_P   MGC_SFT_PRC
#define M_S_U   MGC_SFT_US
#define M_S_E   MGC_SFT_ESC
#define M_PLS   MGC_PLS
#define M_NM_SC MGC_NM_SCL
#define M_MNS   MGC_MNS
#define M_SP_E  MGC_SPC_ESC
#define M_CR_CL MGC_CR_CL

void clear_all_mods(void) {
    clear_mods();
    clear_oneshot_mods();
    clear_weak_mods();
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 *  .---------.-------.-------.-------.-------.-------.-------.           .-------.-------.-------.-------.-------.-------.---------.
 *  |  SF     |       |       |       |       |       |       |           |       |       |       |       |       |       |     _SH_|
 *  |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|-------|           |-------|-------|-------|-------|-------|-------|---------|
 *  |         |       |  V    |  L    |  C    |  W    |       |           |       |  K    |  H    |  G    |  F    |       |         |
 *  |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|       |           |       |-------|-------|-------|-------|-------|---------|
 *  |   -     |  U    |  I    |  A    |  E    |  O    |_______|           |_______|  S    |  N    |  R    |  T    |  D    |         |
 *  |    CAPS |       |       |       |       |       |       |           |       |       |       |       |       |       |  SUPER  |
 *  |---------|-------|-------|-------|-------|-------|       |           |       |-------|-------|-------|-------|-------|---------|
 *  |   =     |  X    |  Y    |  Q    |  P    |  Z    |       |           |       |  B    |  M    |  ,    |  .    |  J    |         |
 *  |s    "   |       |    ALT|    SFT|    CTL|       |       |           |       |       |    CTL|    SFT|    ALT|       |         |
 *  '---------|-------|-------|-------|-------|-------'-------'           '-------'-------|-------|-------|-------|-------|---------'
 *    |       |       |       |       |  NM   |                                           |  SM   | OS_GE | VOL M | VOL D | VOL U |
 *    |       |       |       |       |s   ;  |                                           |s   _  |       |       |       |       |
 *    '-------'-------'-------'-------'-------'                                           '-------'-------'-------'-------'-------'
 *                                               .-------.-------.     .-------.-------.
 *                                               |       |       |     |       | FN    |
 *                                               |       |       |     |       |       |
 *                                       .-------|-------|-------|     |-------|-------|-------.
 *                                       |       |       |       |     |       |       |       |
 *                                       | SHIFT |  TAB  |       |     |       | ENTER | SPACE |
 *                                       |       |       |-------|     |-------|       |       |
 *                                       |s  %   |       | BACK  |     | DEL   |s  :   |s <esc>|
 *                                       |       |       | SPACE |     |       |       |       |
 *                                       '-------'-------'-------'     '-------'-------'-------'
 */

[_EN_] = LAYOUT_ergodox_wrapper(

 TG_SF,        _______,       _______,       _______,      _______,      _______,      _______,
 _______,      _______,       _V,            _L,           _C,           _W,           _______,
 M_MNS,        _U,            _I,            _A,           _E,           _O,           /*___*/
 EQL_DQT,      _X,            ALT_Y,         SFT_Q,        CTL_P,        _Z,           _______,
 _______,      _______,       _______,       _______,      M_NM_SC,     /*___*/       /*___*/


                                                     /*___*/       _______,       _______,
                                                     /*___*/       /*___*/        _______,
                                                     M_S_P,        _TAB,          _BSPACE,


 _______,      _______,       _______,       _______,      _______,      _______,      TG_SH,
 _______,      _K,            _H,            _G,           _F,           _______,      _______,
 /*___*/       _S,            MV_N,          _R,           _T,           _D,           _LGUI,
 _______,      _B,            CTL_M,         SFT_CM,       ALT_DT,       _J,           _______,
 /*___*/       /*___*/        M_SM_U,        OS_GE,        _MUTE,        _VOLD,        _VOLU,


         _______,      OS_FN,         /*___*/
         _______,      /*___*/        /*___*/
         _DEL,         M_CR_CL,       M_SP_E

),

 [_SF_] = LAYOUT_ergodox_wrapper(

 TO_EN,        _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      /*---*/
 _______,      _______,      _______,      _______,      _______,      _______,      _ESC,
 _______,      _______,      _______,      _______,      OS_NM,
 _______,      _______,
 _______,
 OS_SFT,       _TAB,         _BSPACE,

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 /*---*/       _______,      _______,      _______,      _______,      _______,      _______,
 _ESC,         _______,      _______,      _______,      _______,      _______,      _______,
 /*---*/       /*---*/       OS_SM,        _______,      _______,      _______,      _______,
 _______,      _______,
 _______,
 _DEL,         _ENTER,       _SPACE
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
 _______,      _______,       _BSLS,         MGC_PLS,       _MINS,         _DLR,          _______,
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
 *  .---------.-------.-------.-------.-------.-------.-------.      .---------------------------------------------------------.
 *  |         |       |       |       |       |       |       |      |       |       |       |       |       |       |         |
 *  |         |       |       |       |       |       |       |      |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|-------|      |-------|-------|-------|-------|-------|-------|---------|
 *  |         |       |       |       |       |       |       |      |       |   ^   |   7   |   8   |   9   |       |         |
 *  |         |       |       |       |       |       |       |      |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|       |      |       |-------|-------|-------|-------|-------|---------|
 *  |         |       | GUI   |  ,    |  .    |       |_______|      |_______|   .   |   4   |   5   |   6   |   :   |         |
 *  |         |       |       |       |       |       |       |      |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|       |      |       |-------|-------|-------|-------|-------|---------|
 *  |         |       |       |       |       |       |       |      |       |   ,   |   1   |   2   |   3   |       |         |
 *  |         |       |       |       |       |       |       |      |       |       |       |       |       |       |         |
 *  '---------|-------|-------|-------|-------|-------'-------'      '-------'-------|-------|-------|-------|-------|---------'
 *    |       |       |       |       |       |                                      |   0   |       |       |       |       |
 *    |       |       |       |       |       |                                      |       |       |       |       |       |
 *    '-------'-------'-------'-------'-------'                                      '-------'-------'-------'-------'-------'
 */

[_NM_] = LAYOUT_ergodox_wrapper(

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      KC_LGUI,      _COMM,        _DOT,         _______,      /*___*/
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,
 THUMBS,

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _HAT,         _7,           _8,           _9,           _______,      _______,
 /*___*/       _DOT,         _4,           _5,           _6,           _COLN,        _______,
 _______,      _COMM,        _1,           _2,           _3,           _______,      _______,
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
    switch (keycode)
    {

        case MGC_SFT_PRC:
            // tap once for os shift
            // hold for shift
            // shift and tap for underscore (including tapping twice)
            {
                if (is_shifted) // second tap: change to _SM_
                {
                    clear_mods();
                    if (record->event.pressed)
                    {
#if __LANGUAGE__ == LG__GERMAN__
                        register_code(KC_LSFT);
                        register_code(KC_5);
#elif __LANGUAGE__ == LG__ENGLISH__
#endif
                    }
                    else
                    {
                        unregister_code(KC_5);
                        unregister_code(KC_LSFT);
                    }
                }
                else
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

        // case MGC_SFT_US:
        //     // tap once for os shift
        //     // hold for shift
        //     // shift and tap for underscore (including tapping twice)
        //     {
        //         if (is_shifted) // second tap: change to _SM_
        //         {
        //             clear_mods();
        //             if (record->event.pressed)
        //             {
// #if __LANGUAGE__ == LG__GERMAN__
        //                 register_code(KC_LSFT);
        //                 TAP_KEY(DE_MINS);
        //                 unregister_code(KC_LSFT);
// #elif __LANGUAGE__ == LG__ENGLISH__
        //                 TAP_KEY(_UNDS);
// #endif
        //             }
        //         }
        //         else // first tap
        //         {
        //             if (record->event.pressed)
        //             {
        //                 clear_mods();
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

            // case MGC_SFT_ESC:
            //     return true;
            //     // tap once for os shift
            //     // hold for shift
            //     // shift and tap for esc
            //     {
            //         if (is_shifted) // second tap: change to _SM_
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
                if (is_shifted)
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

        case MGC_SM_US:
            // tap or hold for sm layer
            // tap when shifted for underscore
            {
                // send_keyboard_report();
                if (is_shifted)
                {
                    if (record->event.pressed)
                    {
                        clear_oneshot_layer_state(ONESHOT_PRESSED);
#if __LANGUAGE__ == LG__GERMAN__
                        register_code(DE_MINS);
#elif __LANGUAGE__ == LG__ENGLISH__
#endif
                    }
                    else
                    {
                        unregister_code(DE_MINS);
                        // NOTE: we can land here from the lower branch.
                        // clear the oneshot layer to catch side effects
                        clear_oneshot_layer_state(ONESHOT_PRESSED);
                    }
                }
                else
                {
                    if (record->event.pressed)
                    {
                        set_oneshot_layer(_SM_, ONESHOT_START);
                    }
                    else
                    {
                        clear_all_mods();
#if __LANGUAGE__ == LG__GERMAN__
                        // NOTE: we can land here from the upper branch
                        // unregister, otherwise key would be seen as
                        // pressed
                        unregister_code(DE_MINS);
#elif __LANGUAGE__ == LG__ENGLISH__
#endif
                        clear_oneshot_layer_state(ONESHOT_PRESSED);
                    }
                }
                return false;
            };

        case MGC_NM_SCL:
            // tap or hold for sm layer
            // tap when shifted for semicolom
            {
                if (is_shifted)
                {
                    if (record->event.pressed)
                    {
                        clear_oneshot_layer_state(ONESHOT_PRESSED);
#if __LANGUAGE__ == LG__GERMAN__
                        register_code(KC_COMM);
#elif __LANGUAGE__ == LG__ENGLISH__
#endif
                    }
                    else
                    {
                        unregister_code(KC_COMM);
                        clear_oneshot_layer_state(ONESHOT_PRESSED);
                    }
                }
                else
                {
                    if (record->event.pressed)
                    {
                        set_oneshot_layer(_NM_, ONESHOT_START);
                    }
                    else
                    {
                        unregister_code(KC_COMM);
                        clear_all_mods();
                        clear_oneshot_layer_state(ONESHOT_PRESSED);
                    }
                }
                return false;
            };

        case MGC_PLS:
            // tap for `+`
            // tap when shifted for ` += `
            {
                if (is_shifted)
                {
                    clear_all_mods();
                    if (record->event.pressed)
                    {
#if __LANGUAGE__ == LG__GERMAN__
                        TAP_KEY(_SPACE); // space
                        TAP_KEY(_PLUS);  // +
                        TAP_SFT(_0);     // =
                        TAP_KEY(_SPACE); // space
#elif __LANGUAGE__ == LG__ENGLISH__
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
                        register_code(_PLUS);
                    }
                    else
                    {
                        unregister_code(_PLUS);
                        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
                    }
                }
                return false;
            };

        case MGC_SPC_ESC:
            // tap for ` `
            // tap when shifted for esc
            {
                if (is_shifted)
                {
                    if (record->event.pressed)
                    {
#if __LANGUAGE__ == LG__GERMAN__
                        clear_all_mods();
                        TAP_KEY(_ESC);
#elif __LANGUAGE__ == LG__ENGLISH__
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

        case MGC_CR_CL:
            // tap for enter
            // tap when shifted for colon
            {
                if (is_shifted)
                {
                    if (record->event.pressed)
                    {
#if __LANGUAGE__ == LG__GERMAN__
                        register_code(KC_DOT);
#elif __LANGUAGE__ == LG__ENGLISH__
#endif
                    }
                    else
                    {
                        unregister_code(KC_DOT);
                    }
                }
                else
                {
                    if (record->event.pressed)
                    {
                        register_code(_ENTER);
                    }
                    else
                    {
                        unregister_code(KC_DOT);
                        unregister_code(_ENTER);
                    }
                }
                return false;
            };

        case TMUX_LDR:
            // does not work yet
            {
                if (record->event.pressed)
                {
                    register_code(KC_RCTL);
                    register_code(_SPACE);
                }
                else
                {
                    unregister_code(_SPACE);
                    unregister_code(KC_RCTL);
                }
            }

        case MGC_MNS:
            {
                if (record->event.pressed) {
                    if (is_shifted) {
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

        case KC_DOT:
            {
                if (record->event.pressed) {
                    if (is_shifted) {
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

        case UDS_ESC:
            {
                uint8_t shifted = (is_shifted);
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

        case EQL_DQT:
            {
                uint8_t shifted = (is_shifted);
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

        case MGC_SFT_SM:
            return true;
            // tap or hold for shift
            // tap when shifted for os to sm layer
            {
                if (is_shifted) // second tap: change to _SM_
                {
                    clear_mods();
                    if (record->event.pressed)
                    {
                        set_oneshot_layer(_SM_, ONESHOT_START);
                    }
                    else
                    {
                        clear_oneshot_layer_state(ONESHOT_PRESSED);
                    }
                }
                else // first tap
                {
                    if (record->event.pressed)
                    {
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
