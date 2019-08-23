
#define _HAT M(mc_hat)
#define _TICK M(mc_tick)
#define _BKTK M(mc_backtick)
#define _CHLY M(mc_change_layout)

enum { 
  mc_sh_clicks,
  mc_hat,
  mc_tick,
  mc_backtick,
  mc_change_layout,
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {

    if (record->event.pressed) {
      switch(id) {
        case mc_sh_clicks:
          for (int i = 0; i < 25; i++) {
            // mousekey_on(KC_BTN1);
            // mousekey_send();
            // wait_ms(10);
            // mousekey_off(KC_BTN1);
            // mousekey_send();
            // wait_ms(10);
          }
          break;
        case mc_tick:
            #if __LANGUAGE__ == __GERMAN__
          TAP_TWICE(KC_EQL);
            #endif
          break;
        case mc_backtick:
            #if __LANGUAGE__ == __GERMAN__
          register_code(KC_LSFT);
          TAP_TWICE(DE_ACUT);
          unregister_code(KC_LSFT);
            #endif
          break;
        case mc_hat:
          TAP_TWICE(KC_GRAVE);
          break;
        case mc_change_layout:
          register_code(KC_LGUI);
          register_code(KC_SPACE);
          unregister_code(KC_SPACE);
          unregister_code(KC_LGUI);
      }
    }
    return MACRO_NONE;
};

qk_tap_dance_action_t tap_dance_actions[] = {

};
