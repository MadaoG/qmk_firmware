#define T_CL   TD(CL_SCL)   // colon and semicolon

enum {
    CL_SCL,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [CL_SCL] = ACTION_TAP_DANCE_DOUBLE(DE_COLN, DE_SCLN),
};
