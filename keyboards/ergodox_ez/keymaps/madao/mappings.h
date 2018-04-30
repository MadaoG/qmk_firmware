#if __LANGUAGE__ == 0 // GERMAN

    #include "keymap_extras/keymap_german.h"

    #define ALGR(kc) RALT(kc)
    #define __ALGR   KC_RALT
    #define __Z      DE_Y
    #define __Y      DE_Z
    #define __A      DE_A
    #define __B      DE_B
    #define __C      DE_C
    #define __D      DE_D
    #define __E      DE_E
    #define __F      DE_F
    #define __G      DE_G
    #define __H      DE_H
    #define __I      DE_I
    #define __J      DE_J
    #define __K      DE_K
    #define __L      DE_L
    #define __M      DE_M
    #define __N      DE_N
    #define __O      DE_O
    #define __P      DE_P
    #define __Q      DE_Q
    #define __R      DE_R
    #define __S      DE_S
    #define __T      DE_T
    #define __U      DE_U
    #define __V      DE_V
    #define __W      DE_W
    #define __X      DE_X
    #define __0      DE_0
    #define __1      DE_1
    #define __2      DE_2
    #define __3      DE_3
    #define __4      DE_4
    #define __5      DE_5
    #define __6      DE_6
    #define __7      DE_7
    #define __8      DE_8
    #define __9      DE_9
    #define __DOT    KC_DOT
    #define __COMM   KC_COMM
    #define __SS     KC_MINS
    #define __AE     KC_QUOT
    #define __UE     KC_LBRC
    #define __OE     KC_SCLN
    #define __CIRC   KC_GRAVE      // accent circumflex ^ and ring °
    #define __ACUT   KC_EQL        // accent acute ´ and grave `
    #define __PLUS   KC_RBRC       // + and * and ~
    #define __HASH   KC_BSLS       // # and '
    #define __LESS   KC_NUBS       // < and > and |
    #define __MINS   KC_SLSH       // - and _
    #define __RING   LSFT(DE_CIRC) // °
    #define __EXLM   LSFT(KC_1)    // !
    #define __DQOT   LSFT(KC_2)    // "
    #define __PARA   LSFT(KC_3)    // §
    #define __DLR    LSFT(KC_4)    // $
    #define __PERC   LSFT(KC_5)    // %
    #define __AMPR   LSFT(KC_6)    // &
    #define __SLSH   LSFT(KC_7)    // /
    #define __LPRN   LSFT(KC_8)    // (
    #define __RPRN   LSFT(KC_9)    // )
    #define __EQL    LSFT(KC_0)    // =
    #define __QST    LSFT(DE_SS)   // ?
    #define __GRV    LSFT(DE_ACUT) // `
    #define __ASTR   LSFT(DE_PLUS) // *
    #define __QUOT   LSFT(DE_HASH) // '
    #define __MORE   LSFT(DE_LESS) // >
    #define __COLN   LSFT(KC_DOT)  // :
    #define __SCLN   LSFT(KC_COMM) // ;
    #define __UNDS   LSFT(DE_MINS) // _
    #define __SQ2    ALGR(KC_2)    // ²
    #define __SQ3    ALGR(KC_3)    // ³
    #define __LCBR   ALGR(KC_7)    // {
    #define __LBRC   ALGR(KC_8)    // [
    #define __RBRC   ALGR(KC_9)    // ]
    #define __RCBR   ALGR(KC_0)    // }
    #define __BSLS   ALGR(DE_SS)   // backslash
    #define __AT     ALGR(KC_Q)    // @
    #define __EURO   ALGR(KC_E)    // €
    #define __TILD   ALGR(DE_PLUS) // ~
    #define __PIPE   ALGR(DE_LESS) // |

#elif __LANGUAGE__ == 1 // ENGLISH

    #define __Z    KC_Z
    #define __Y    KC_Y
    #define __A    KC_A
    #define __B    KC_B
    #define __C    KC_C
    #define __D    KC_D
    #define __E    KC_E
    #define __F    KC_F
    #define __G    KC_G
    #define __H    KC_H
    #define __I    KC_I
    #define __J    KC_J
    #define __K    KC_K
    #define __L    KC_L
    #define __M    KC_M
    #define __N    KC_N
    #define __O    KC_O
    #define __P    KC_P
    #define __Q    KC_Q
    #define __R    KC_R
    #define __S    KC_S
    #define __T    KC_T
    #define __U    KC_U
    #define __V    KC_V
    #define __W    KC_W
    #define __X    KC_X
    #define __0    KC_0
    #define __1    KC_1
    #define __2    KC_2
    #define __3    KC_3
    #define __4    KC_4
    #define __5    KC_5
    #define __6    KC_6
    #define __7    KC_7
    #define __8    KC_8
    #define __9    KC_9
    #define __DOT  KC_DOT
    #define __COMM KC_COMM
    #define __SS   KC_SS
    #define __AE   KC_AE
    #define __UE   KC_UE
    #define __OE   KC_OE
    #define __CIRC KC_CIRC
    #define __ACUT KC_ACUT
    #define __PLUS KC_PLUS
    #define __HASH KC_HASH
    #define __LESS KC_LESS
    #define __MINS KC_MINS
    #define __RING KC_RING
    #define __EXLM KC_EXLM
    #define __DQOT KC_DQOT
    #define __PARA KC_PARA
    #define __DLR  KC_DLR
    #define __PERC KC_PERC
    #define __AMPR KC_AMPR
    #define __SLSH KC_SLSH
    #define __LPRN KC_LPRN
    #define __RPRN KC_RPRN
    #define __EQL  KC_EQL
    #define __QST  KC_QST
    #define __GRV  KC_GRV
    #define __ASTR KC_ASTR
    #define __QUOT KC_QUOT
    #define __MORE KC_MORE
    #define __COLN KC_COLN
    #define __SCLN KC_SCLN
    #define __UNDS KC_UNDS
    #define __LCBR KC_LCBR
    #define __LBRC KC_LBRC
    #define __RBRC KC_RBRC
    #define __RCBR KC_RCBR
    #define __BSLS KC_BSLS
    #define __AT   KC_AT
    #define __EURO KC_EURO
    #define __TILD KC_TILD
    #define __PIPE KC_PIPE

#endif
