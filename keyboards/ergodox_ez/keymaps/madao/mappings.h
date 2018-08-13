#if __LANGUAGE__ == __GERMAN__

    #include "keymap_extras/keymap_german.h"

    #define ALGR(kc) RALT(kc)
    #define i_ALGR   KC_RALT
    #define i_Z      DE_Z
    #define i_Y      DE_Y
    #define i_A      DE_A
    #define i_B      DE_B
    #define i_C      DE_C
    #define i_D      DE_D
    #define i_E      DE_E
    #define i_F      DE_F
    #define i_G      DE_G
    #define i_H      DE_H
    #define i_I      DE_I
    #define i_J      DE_J
    #define i_K      DE_K
    #define i_L      DE_L
    #define i_M      DE_M
    #define i_N      DE_N
    #define i_O      DE_O
    #define i_P      DE_P
    #define i_Q      DE_Q
    #define i_R      DE_R
    #define i_S      DE_S
    #define i_T      DE_T
    #define i_U      DE_U
    #define i_V      DE_V
    #define i_W      DE_W
    #define i_X      DE_X
    #define i_0      DE_0
    #define i_1      DE_1
    #define i_2      DE_2
    #define i_3      DE_3
    #define i_4      DE_4
    #define i_5      DE_5
    #define i_6      DE_6
    #define i_7      DE_7
    #define i_8      DE_8
    #define i_9      DE_9
    #define i_DOT    KC_DOT
    #define i_COMM   KC_COMM
    #define i_SS     KC_MINS
    #define i_AE     KC_QUOT
    #define i_UE     KC_LBRC
    #define i_OE     KC_SCLN
    #define i_CIRC   KC_GRAVE      // accent circumflex ^ and ring °
    #define i_ACUT   KC_EQL        // accent acute ´ and grave `
    #define i_PLUS   KC_RBRC       // + and * and ~
    #define i_HASH   KC_BSLS       // # and '
    #define i_LESS   KC_NUBS       // < and > and |
    #define i_MINS   KC_SLSH       // - and _
    #define i_RING   LSFT(DE_CIRC) // °
    #define i_EXLM   LSFT(KC_1)    // !
    #define i_DQOT   LSFT(KC_2)    // "
    #define i_PARA   LSFT(KC_3)    // §
    #define i_DLR    LSFT(KC_4)    // $
    #define i_PERC   LSFT(KC_5)    // %
    #define i_AMPR   LSFT(KC_6)    // &
    #define i_SLSH   LSFT(KC_7)    // /
    #define i_LPRN   LSFT(KC_8)    // (
    #define i_RPRN   LSFT(KC_9)    // )
    #define i_EQL    LSFT(KC_0)    // =
    #define i_QST    LSFT(DE_SS)   // ?
    #define i_GRV    LSFT(DE_ACUT) // `
    #define i_ASTR   LSFT(DE_PLUS) // *
    #define i_QUOT   LSFT(DE_HASH) // '
    #define i_MORE   LSFT(DE_LESS) // >
    #define i_COLN   LSFT(KC_DOT)  // :
    #define i_SCLN   LSFT(KC_COMM) // ;
    #define i_UNDS   LSFT(DE_MINS) // /_
    #define i_SQ2    ALGR(KC_2)    // ²
    #define i_SQ3    ALGR(KC_3)    // ³
    #define i_LCBR   ALGR(KC_7)    // {
    #define i_LBRC   ALGR(KC_8)    // [
    #define i_RBRC   ALGR(KC_9)    // ]
    #define i_RCBR   ALGR(KC_0)    // }
    #define i_BSLS   ALGR(DE_SS)   // backslash
    #define i_AT     ALGR(KC_Q)    // @
    #define i_EURO   ALGR(KC_E)    // €
    #define i_TILD   ALGR(DE_PLUS) // ~
    #define i_PIPE   ALGR(DE_LESS) // |

#elif __LANGUAGE__ == __ENGLISH__

    #define i_Z    KC_Z
    #define i_Y    KC_Y
    #define i_A    KC_A
    #define i_B    KC_B
    #define i_C    KC_C
    #define i_D    KC_D
    #define i_E    KC_E
    #define i_F    KC_F
    #define i_G    KC_G
    #define i_H    KC_H
    #define i_I    KC_I
    #define i_J    KC_J
    #define i_K    KC_K
    #define i_L    KC_L
    #define i_M    KC_M
    #define i_N    KC_N
    #define i_O    KC_O
    #define i_P    KC_P
    #define i_Q    KC_Q
    #define i_R    KC_R
    #define i_S    KC_S
    #define i_T    KC_T
    #define i_U    KC_U
    #define i_V    KC_V
    #define i_W    KC_W
    #define i_X    KC_X
    #define i_0    KC_0
    #define i_1    KC_1
    #define i_2    KC_2
    #define i_3    KC_3
    #define i_4    KC_4
    #define i_5    KC_5
    #define i_6    KC_6
    #define i_7    KC_7
    #define i_8    KC_8
    #define i_9    KC_9
    #define i_DOT  KC_DOT
    #define i_COMM KC_COMM
    #define i_SS   KC_SS
    #define i_AE   KC_AE
    #define i_UE   KC_UE
    #define i_OE   KC_OE
    #define i_CIRC KC_CIRC
    #define i_ACUT KC_ACUT
    #define i_PLUS KC_PLUS
    #define i_HASH KC_HASH
    #define i_LESS KC_LESS
    #define i_MINS KC_MINS
    #define i_RING KC_RING
    #define i_EXLM KC_EXLM
    #define i_DQOT KC_DQOT
    #define i_PARA KC_PARA
    #define i_DLR  KC_DLR
    #define i_PERC KC_PERC
    #define i_AMPR KC_AMPR
    #define i_SLSH KC_SLSH
    #define i_LPRN KC_LPRN
    #define i_RPRN KC_RPRN
    #define i_EQL  KC_EQL
    #define i_QST  KC_QST
    #define i_GRV  KC_GRV
    #define i_ASTR KC_ASTR
    #define i_QUOT KC_QUOT
    #define i_MORE KC_MORE
    #define i_COLN KC_COLN
    #define i_SCLN KC_SCLN
    #define i_UNDS KC_UNDS
    #define i_LCBR KC_LCBR
    #define i_LBRC KC_LBRC
    #define i_RBRC KC_RBRC
    #define i_RCBR KC_RCBR
    #define i_BSLS KC_BSLS
    #define i_AT   KC_AT
    #define i_EURO KC_EURO
    #define i_TILD KC_TILD
    #define i_PIPE KC_PIPE

#endif
