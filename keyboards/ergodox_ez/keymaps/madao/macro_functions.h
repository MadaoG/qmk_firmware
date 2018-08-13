
#define TAP_KEY(kc) register_code(kc); unregister_code(kc);
#define TAP_TWICE(kc) TAP_KEY(kc); TAP_KEY(kc);
#define i_HAT M(mc_hat)

enum { 
  mc_sh_clicks,
  mc_hat,
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
        case mc_hat:
          TAP_TWICE(KC_GRAVE);
          break;
      }
    }
    return MACRO_NONE;
};
