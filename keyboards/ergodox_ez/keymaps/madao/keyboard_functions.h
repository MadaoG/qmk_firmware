
uint8_t last_layer = _BS;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    /* ! Ä  § $ % / ä )= ( ` , ß . - Ö ö ; ' : _ " ü #  + & ? ^ Ü ' * ° */ 
    /* ! \" # $ % & ' () * + , - . / : ; < = > ? @ [ \\ ] ^ _ ` { | } ~ */
    return true;
};


qk_tap_dance_action_t tap_dance_actions[] = {
  [CL_SCL]  = ACTION_TAP_DANCE_DOUBLE(DE_COLN, DE_SCLN),

  // [td_elg]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_elg_finished,  th_elg_reset),
  // [td_pbbl] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_pbbl_finished, th_pbbl_reset),
  // [td_pbbr] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_pbbr_finished, th_pbbr_reset),
  // [td_elg]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_elg_finished,  th_elg_reset),
  // [td_uag]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_uag_finished,  th_uag_reset),
  [td_bq]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_bq_finished,   th_bq_reset),
  // [td_bsp]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_bsp_finished,  th_bsp_reset),
  // [td_sh]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_sh_finished,   th_sh_reset),
  // [td_dat]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_dat_finished,  th_dat_reset),
  // [td_pa]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_pa_finished,   th_pa_reset),
  // [td_pm]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_pm_finished,   th_pm_reset),
  // [td_dq]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_dq_finished,   th_dq_reset),
  // [td_sq]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_sq_finished,   th_sq_reset),

  [td_ge_ae]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_ge_ae_finished, th_ge_ae_reset),
  [td_ge_oe]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_ge_oe_finished, th_ge_oe_reset),
  [td_ge_ue]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_ge_ue_finished, th_ge_ue_reset),
  [td_ge_ss]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_ge_ss_finished, th_ge_ss_reset),

  [td_to]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_to_finished,   th_to_reset),

  [td_dt]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_dt_finished,   th_dt_reset),
  [td_tbt]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th_tbt_finished,  th_tbt_reset),
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

