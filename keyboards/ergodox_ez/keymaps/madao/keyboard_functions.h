
uint8_t last_layer = _BS;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    /* ! Ä  § $ % / ä )= ( ` , ß . - Ö ö ; ' : _ " ü #  + & ? ^ Ü ' * ° */ 
    /* ! \" # $ % & ' () * + , - . / : ; < = > ? @ [ \\ ] ^ _ ` { | } ~ */
    return true;
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {

    if (record->event.pressed) {
      switch(id) {
        case mc_sh_clicks:
          for (int i = 0; i < 25; i++) {
            mousekey_on(KC_BTN1);
            mousekey_send();
            wait_ms(10);
            mousekey_off(KC_BTN1);
            mousekey_send();
            wait_ms(10);
          }
          break;
        case mc_hat:
          TAP_TWICE(KC_GRAVE);
          break;
      }
    }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);
    t++; if (t >= 1000) t = 0;

    if (layer == last_layer) {
      // update leds
      switch (layer) {
        case _GE:
          ergodox_set_red(brightness_middle(300));
          ergodox_set_green(brightness_middle(500));
          ergodox_set_blue(brightness_middle(700));
          break;
        case _EN:
          ergodox_set_red(brightness_middle(700));
          ergodox_set_green(brightness_middle(500));
          ergodox_set_blue(brightness_middle(300));
          break;
        case _SM:
          ergodox_set_green(brightness_middle(500));
          break;
        case _MV:
          ergodox_set_blue(brightness_middle(500));
          break;
        case _NM:
          ergodox_set_blue(brightness_middle(500));
          break;
        case _FN:
          ergodox_set_red(brightness_fast(300));
          ergodox_set_green(brightness_fast(500));
          ergodox_set_blue(brightness_fast(700));
          break;
        case _SH:
          ergodox_set_red(brightness_middle(500));
          ergodox_set_green(brightness_fast(250) + brightness_fast(750));
          ergodox_set_blue(brightness_middle(0) + brightness_middle(999));
          break;
        case _MS:
          ergodox_set_red(brightness_middle(500));
          ergodox_set_green(brightness_middle(500));
          break;
        default:
          ergodox_board_led_off();
      }

    } else {
      last_layer = layer;
      t = 0;
      // init leds
      ergodox_board_led_off();
      ergodox_right_led_1_off();
      ergodox_right_led_2_off();
      ergodox_right_led_3_off();
    }
};

