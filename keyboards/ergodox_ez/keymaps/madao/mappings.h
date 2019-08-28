
#define _______ KC_TRNS
#define _xxxxx_ KC_NO

#define TAP_KEY(kc) \
    register_code(kc); \
    unregister_code(kc);

#define TAP_RECORD(kc) \
    if (record->event.pressed) {register_code(kc);} else {unregister_code(kc);}

#define TAP_SFT(kc) register_code(KC_LSFT); TAP_KEY(kc); unregister_code(KC_LSFT);
#define TAP_TWICE(kc) TAP_KEY(kc); TAP_KEY(kc);

enum {
    UDS_ESC = SAFE_RANGE,
    _TTNM,
    EQL_DQT,
    MGC_SFT_SM,
    MGC_SM_ESC,
    MGC_SM_US,
    MGC_SFT_PRC,
    MGC_SFT_US,
    MGC_SFT_ESC,
    MGC_PLS,
    MGC_NM_SCL,
    MGC_SPC_ESC,
    MGC_ESC_DEL,
    MGC_SPC,
    MGC_TEST,
    CTRL_F,
    _CLICK,
};

#define M_S_SM  MGC_SFT_SM
#define M_SM_E  MGC_SM_ESC
#define M_SM_U  MGC_SM_US
#define M_S_P   MGC_SFT_PRC
#define M_S_U   MGC_SFT_US
#define M_S_E   MGC_SFT_ESC
#define M_PLS   MGC_PLS
#define M_NM_SC MGC_NM_SCL
#define M_SP_E  MGC_SPC_ESC
#define _M_SP   MGC_SPC
#define _ESC_D  MGC_ESC_DEL
#define _C_F    CTRL_F

#define MV_WIN  MT(MOD_LCTL | MOD_LGUI, KC_ESC)
#define MV_SCRN MT(MOD_LCTL | MOD_LALT, KC_ESC)
#define MV_PRG  MT(MOD_LCTL | MOD_LALT | MOD_LSFT, KC_ESC)
#define ALT_Y   ALT_T(_Y)
#define SFT_Q   SFT_T(_Q)
#define CTL_P   CTL_T(_P)
#define ALT_DT  ALT_T(_DOT)
#define SFT_CM  SFT_T(_COMM)
#define CTL_M   CTL_T(_M)
#define OS_SFT  OSM(MOD_LSFT)
#define SM_A    LT(_SM_,(_A))
#define SM_R    LT(_SM_,(_R))
#define NM_E    LT(_NM_,(_E))
#define MV_N    LT(_MV_,(_N))
#define _S_FN   OSL(_FN_)
#define _S_GE   OSL(_GE_)
#define _S_NM   OSL(_NM_)
#define _S_SM   OSL(_SM_)
#define OS_FN   OSL(_FN_)
#define OS_GE   OSL(_GE_)
#define OS_NM   OSL(_NM_)
#define OS_SM   OSL(_SM_)
#define TG_SF   TG(_SF_)
#define TG_WK   TG(_WK_)
#define _TO_EN  TO(_EN_)

#define _ESC    KC_ESC
#define _TAB    KC_TAB
#define _SPACE  KC_SPACE
#define _ENTER  KC_ENTER
#define _CR     KC_ENTER
#define _DEL    KC_DELETE
#define _BSPACE KC_BSPACE
#define _LGUI   KC_LGUI
#define _VOLU   KC_VOLU
#define _VOLD   KC_VOLD
#define _MUTE   KC_MUTE

#define _UP     KC_UP
#define _DOWN   KC_DOWN
#define _LEFT   KC_LEFT
#define _RIGHT  KC_RGHT
#define _CLICK  KC_BTN1

#if __LANGUAGE__ == LG__GERMAN__

    #include "keymap_extras/keymap_german.h"

    #define _0           DE_0
    #define _1           DE_1
    #define _2           DE_2
    #define _3           DE_3
    #define _4           DE_4
    #define _5           DE_5
    #define _6           DE_6
    #define _7           DE_7
    #define _8           DE_8
    #define _9           DE_9
    #define _A           DE_A
    #define _B           DE_B
    #define _C           DE_C
    #define _D           DE_D
    #define _E           DE_E
    #define _F           DE_F
    #define _G           DE_G
    #define _H           DE_H
    #define _I           DE_I
    #define _J           DE_J
    #define _K           DE_K
    #define _L           DE_L
    #define _M           DE_M
    #define _N           DE_N
    #define _O           DE_O
    #define _P           DE_P
    #define _Q           DE_Q
    #define _R           DE_R
    #define _S           DE_S
    #define _T           DE_T
    #define _U           DE_U
    #define _V           DE_V
    #define _W           DE_W
    #define _X           DE_X
    #define _Y           DE_Y
    #define _Z           DE_Z
    #define ALGR(kc)     RALT(kc)
    #define _ACUT        KC_EQL        // accent acute ´ and grave `
    #define _AE          KC_QUOT
    #define _ALGR        KC_RALT
    #define _AMPR        LSFT(KC_6)    // &
    #define _ASTR        LSFT(DE_PLUS) // *
    #define _AT          ALGR(KC_Q)    // @
    #define _BSLS        ALGR(DE_SS)   // backslash
    #define _CAPS        KC_CAPS
    #define _CIRC        KC_GRAVE      // accent circumflex ^ and ring °
    #define _COLN        LSFT(KC_DOT)  // :
    #define _COMM        KC_COMM
    #define _DLR         LSFT(KC_4)    // $
    #define _DOT         KC_DOT
    #define _DQOT        LSFT(KC_2)    // "
    #define _EQL         LSFT(KC_0)    // =
    #define _EURO        ALGR(KC_E)    // €
    #define _EXLM        LSFT(KC_1)    // !
    #define _GRV         LSFT(DE_ACUT) // `
    #define _HASH        KC_BSLS       // # and '
    #define _LBRC        ALGR(KC_8)    // [
    #define _LCBR        ALGR(KC_7)    // {
    #define _LESS        KC_NUBS       // < and > and |
    #define _LPRN        LSFT(KC_8)    // (
    #define _MINS        KC_SLSH       // - and _
    #define _MORE        LSFT(DE_LESS) // >
    #define _OE          KC_SCLN
    #define _PARA        LSFT(KC_3)    // §
    #define _PERC        LSFT(KC_5)    // %
    #define _PIPE        ALGR(DE_LESS) // |
    #define _PLUS        KC_RBRC       // + and * and ~
    #define _QST         LSFT(DE_SS)   // ?
    #define _QUOT        LSFT(DE_HASH) // '
    #define _RBRC        ALGR(KC_9)    // ]
    #define _RCBR        ALGR(KC_0)    // }
    #define _RING        LSFT(DE_CIRC) // °
    #define _RPRN        LSFT(KC_9)    // )
    #define _SCLN        LSFT(KC_COMM) // ;
    #define _SLSH        LSFT(KC_7)    // /
    #define _SQ2         ALGR(KC_2)    // ²
    #define _SQ3         ALGR(KC_3)    // ³
    #define _SS          KC_MINS
    #define _TILD        ALGR(DE_PLUS) // ~
    #define _UE          KC_LBRC
    #define _UNDS        LSFT(DE_MINS) // /_

#elif __LANGUAGE__ == LG__ENGLISH__

    #define _0           KC_0
    #define _1           KC_1
    #define _2           KC_2
    #define _3           KC_3
    #define _4           KC_4
    #define _5           KC_5
    #define _6           KC_6
    #define _7           KC_7
    #define _8           KC_8
    #define _9           KC_9
    #define _A           KC_A
    #define _B           KC_B
    #define _C           KC_C
    #define _D           KC_D
    #define _E           KC_E
    #define _F           KC_F
    #define _G           KC_G
    #define _H           KC_H
    #define _I           KC_I
    #define _J           KC_J
    #define _K           KC_K
    #define _L           KC_L
    #define _M           KC_M
    #define _N           KC_N
    #define _O           KC_O
    #define _P           KC_P
    #define _Q           KC_Q
    #define _R           KC_R
    #define _S           KC_S
    #define _T           KC_T
    #define _U           KC_U
    #define _V           KC_V
    #define _W           KC_W
    #define _X           KC_X
    #define _Y           KC_Y
    #define _Z           KC_Z

    #define _ACUT        KC_ACUT
    #define _AMPR        KC_AMPR
    #define _ASTR        KC_ASTR
    #define _AT          KC_AT
    #define _BSLS        KC_BSLS
    #define _CAPS        KC_CAPS
    #define _CIRC        KC_CIRC
    #define _COLN        KC_COLN
    #define _COMM        KC_COMM
    #define _DLR         KC_DLR
    #define _DOT         KC_DOT
    #define _DQOT        LSFT(KC_QUOT)
    #define _EQL         KC_EQL
    #define _EURO        KC_EURO
    #define _EXLM        KC_EXLM
    #define _GRV         KC_GRV
    #define _HASH        KC_HASH       // shifted
    #define _LBRC        KC_LBRC
    #define _LCBR        LSFT(KC_LBRC)
    #define _LESS        LSFT(KC_COMM)
    #define _LPRN        KC_LPRN
    #define _MINS        KC_MINS
    #define _MORE        LSFT(KC_DOT)
    #define _PARA        KC_PARA
    #define _PERC        KC_PERC
    #define _PIPE        LSFT(KC_BSLS)
    #define _PLUS        LSFT(KC_EQL)
    #define _QST         LSFT(KC_SLSH)
    #define _QUOT        KC_QUOT
    #define _RBRC        KC_RBRC
    #define _RCBR        LSFT(KC_RBRC)
    #define _RING        KC_RING
    #define _RPRN        KC_RPRN
    #define _SCLN        KC_SCLN
    #define _SLSH        KC_SLSH
    #define _SS          KC_SS
    #define _TILD        LSFT(KC_GRV)
    #define _UNDS        LSFT(KC_MINS)

#endif

#define _F1  KC_F1
#define _F2  KC_F2
#define _F3  KC_F3
#define _F4  KC_F4
#define _F5  KC_F5
#define _F6  KC_F6
#define _F7  KC_F7
#define _F8  KC_F8
#define _F9  KC_F9
#define _F10 KC_F10
#define _F11 KC_F11
#define _F12 KC_F12
#define _F13 KC_F13
#define _F14 KC_F14
#define _F15 KC_F15
#define _F16 KC_F16
#define _F17 KC_F17
#define _F18 KC_F18
#define _F19 KC_F19
#define _F20 KC_F20
#define _F21 KC_F21
#define _F22 KC_F22
#define _F23 KC_F23
#define _F24 KC_F24


#define TAP1    register_code(_1)
#define TAP2    register_code(_2)
#define TAP3    register_code(_3)
#define TAP4    register_code(_4)

#define UNTAP1    unregister_code(_1)
#define UNTAP2    unregister_code(_2)
#define UNTAP3    unregister_code(_3)
#define UNTAP4    unregister_code(_4)
void clear_all_mods(void) {
    clear_mods();
    clear_oneshot_mods();
    clear_weak_mods();
}

