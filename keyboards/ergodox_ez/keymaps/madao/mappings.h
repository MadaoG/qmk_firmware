#if __LANGUAGE__ == __GERMAN__

    #include "keymap_extras/keymap_german.h"

    #define ALGR(kc) RALT(kc)
    #define _ALGR   KC_RALT
    #define _Z      DE_Z
    #define _Y      DE_Y
    #define _A      DE_A
    #define _B      DE_B
    #define _C      DE_C
    #define _D      DE_D
    #define _E      DE_E
    #define _F      DE_F
    #define _G      DE_G
    #define _H      DE_H
    #define _I      DE_I
    #define _J      DE_J
    #define _K      DE_K
    #define _L      DE_L
    #define _M      DE_M
    #define _N      DE_N
    #define _O      DE_O
    #define _P      DE_P
    #define _Q      DE_Q
    #define _R      DE_R
    #define _S      DE_S
    #define _T      DE_T
    #define _U      DE_U
    #define _V      DE_V
    #define _W      DE_W
    #define _X      DE_X
    #define _0      DE_0
    #define _1      DE_1
    #define _2      DE_2
    #define _3      DE_3
    #define _4      DE_4
    #define _5      DE_5
    #define _6      DE_6
    #define _7      DE_7
    #define _8      DE_8
    #define _9      DE_9
    #define _DOT    KC_DOT
    #define _COMM   KC_COMM
    #define _SS     KC_MINS
    #define _AE     KC_QUOT
    #define _UE     KC_LBRC
    #define _OE     KC_SCLN
    #define _CIRC   KC_GRAVE      // accent circumflex ^ and ring °
    #define _ACUT   KC_EQL        // accent acute ´ and grave `
    #define _PLUS   KC_RBRC       // + and * and ~
    #define _HASH   KC_BSLS       // # and '
    #define _LESS   KC_NUBS       // < and > and |
    #define _MINS   KC_SLSH       // - and _
    #define _RING   LSFT(DE_CIRC) // °
    #define _EXLM   LSFT(KC_1)    // !
    #define _DQOT   LSFT(KC_2)    // "
    #define _PARA   LSFT(KC_3)    // §
    #define _DLR    LSFT(KC_4)    // $
    #define _PERC   LSFT(KC_5)    // %
    #define _AMPR   LSFT(KC_6)    // &
    #define _SLSH   LSFT(KC_7)    // /
    #define _LPRN   LSFT(KC_8)    // (
    #define _RPRN   LSFT(KC_9)    // )
    #define _EQL    LSFT(KC_0)    // =
    #define _QST    LSFT(DE_SS)   // ?
    #define _GRV    LSFT(DE_ACUT) // `
    #define _ASTR   LSFT(DE_PLUS) // *
    #define _QUOT   LSFT(DE_HASH) // '
    #define _MORE   LSFT(DE_LESS) // >
    #define _COLN   LSFT(KC_DOT)  // :
    #define _SCLN   LSFT(KC_COMM) // ;
    #define _UNDS   LSFT(DE_MINS) // /_
    #define _SQ2    ALGR(KC_2)    // ²
    #define _SQ3    ALGR(KC_3)    // ³
    #define _LCBR   ALGR(KC_7)    // {
    #define _LBRC   ALGR(KC_8)    // [
    #define _RBRC   ALGR(KC_9)    // ]
    #define _RCBR   ALGR(KC_0)    // }
    #define _BSLS   ALGR(DE_SS)   // backslash
    #define _AT     ALGR(KC_Q)    // @
    #define _EURO   ALGR(KC_E)    // €
    #define _TILD   ALGR(DE_PLUS) // ~
    #define _PIPE   ALGR(DE_LESS) // |

#elif __LANGUAGE__ == __ENGLISH__

    #define _Z    KC_Z
    #define _Y    KC_Y
    #define _A    KC_A
    #define _B    KC_B
    #define _C    KC_C
    #define _D    KC_D
    #define _E    KC_E
    #define _F    KC_F
    #define _G    KC_G
    #define _H    KC_H
    #define _I    KC_I
    #define _J    KC_J
    #define _K    KC_K
    #define _L    KC_L
    #define _M    KC_M
    #define _N    KC_N
    #define _O    KC_O
    #define _P    KC_P
    #define _Q    KC_Q
    #define _R    KC_R
    #define _S    KC_S
    #define _T    KC_T
    #define _U    KC_U
    #define _V    KC_V
    #define _W    KC_W
    #define _X    KC_X
    #define _0    KC_0
    #define _1    KC_1
    #define _2    KC_2
    #define _3    KC_3
    #define _4    KC_4
    #define _5    KC_5
    #define _6    KC_6
    #define _7    KC_7
    #define _8    KC_8
    #define _9    KC_9
    #define _DOT  KC_DOT
    #define _COMM KC_COMM
    #define _SS   KC_SS
    #define _AE   KC_AE
    #define _UE   KC_UE
    #define _OE   KC_OE
    #define _CIRC KC_CIRC
    #define _ACUT KC_ACUT
    #define _PLUS KC_PLUS
    #define _HASH KC_HASH
    #define _LESS KC_LESS
    #define _MINS KC_MINS
    #define _RING KC_RING
    #define _EXLM KC_EXLM
    #define _DQOT KC_DQOT
    #define _PARA KC_PARA
    #define _DLR  KC_DLR
    #define _PERC KC_PERC
    #define _AMPR KC_AMPR
    #define _SLSH KC_SLSH
    #define _LPRN KC_LPRN
    #define _RPRN KC_RPRN
    #define _EQL  KC_EQL
    #define _QST  KC_QST
    #define _GRV  KC_GRV
    #define _ASTR KC_ASTR
    #define _QUOT KC_QUOT
    #define _MORE KC_MORE
    #define _COLN KC_COLN
    #define _SCLN KC_SCLN
    #define _UNDS KC_UNDS
    #define _LCBR KC_LCBR
    #define _LBRC KC_LBRC
    #define _RBRC KC_RBRC
    #define _RCBR KC_RCBR
    #define _BSLS KC_BSLS
    #define _AT   KC_AT
    #define _EURO KC_EURO
    #define _TILD KC_TILD
    #define _PIPE KC_PIPE

#endif
