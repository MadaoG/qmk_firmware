
/*
 *  .---------.-------.-------.-------.-------.-------.-------.           .-------.-------.-------.-------.-------.-------.---------.
 *  |    _    |   _   |   _   |   _   |   _   |   _   |   _   |           |   _   |   _   |   _   |   _   |   _   |   _   |    _    |
 *  |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|-------|           |-------|-------|-------|-------|-------|-------|---------|
 *  |    _    |   _   |   _   |   _   |   _   |   _   |       |           |       |   _   |   _   |   _   |   _   |   _   |    _    |
 *  |         |       |       |       |       |       |   _   |           |   _   |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|       |           |       |-------|-------|-------|-------|-------|---------|
 *  |    _    |   _   |   _   |   _   |   _   |   _   |_______|           |_______|   _   |   _   |   _   |   _   |   _   |    _    |
 *  |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
 *  |---------|-------|-------|-------|-------|-------|   _   |           |   _   |-------|-------|-------|-------|-------|---------|
 *  |    _    |   _   |   _   |   _   |   _   |   _   |       |           |       |   _   |   _   |   _   |   _   |   _   |    _    |
 *  |         |       |       |       |       |       |       |           |       |       |       |       |       |       |         |
 *  '---------|-------|-------|-------|-------|-------'-------'           '-------'-------|-------|-------|-------|-------|---------'
 *    |   _   |   _   |   _   |   _   |   _   |                                           |   _   |   _   |   _   |   _   |   _   |
 *    |       |       |       |       |       |                                           |       |       |       |       |       |
 *    '-------'-------'-------'-------'-------'                                           '-------'-------'-------'-------'-------'
 *                                               .-------.-------.     .-------.-------.
 *                                               |   _   |   _   |     |   _   |   _   |
 *                                               |       |       |     |       |       |
 *                                       .-------|-------|-------|     |-------|-------|-------.
 *                                       |       |       |   _   |     |   _   |       |       |
 *                                       |       |       |       |     |       |       |       |
 *                                       |   _   |   _   |-------|     |-------|   _   |   _   |
 *                                       |       |       |   _   |     |   _   |       |       |
 *                                       |       |       |       |     |       |       |       |
 *                                       '-------'-------'-------'     '-------'-------'-------'
 */

 [_] = KEYMAP(

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      /*---*/
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,
 _______,      _______,                         //
 _______,                                       // thumb keys
 _______,      _______,      _______,           //

 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 /*---*/       _______,      _______,      _______,      _______,      _______,      _______,
 _______,      _______,      _______,      _______,      _______,      _______,      _______,
 /*---*/       /*---*/       _______,      _______,      _______,      _______,      _______,
 _______,      _______,                         //
 _______,                                       // thumb keys
 _______,      _______,      _______            //
 ),


// INFO: templates for `process_record_user`

// Custom shift:
        case MGC_SFT_PRC:
            // tap once for os shift
            // hold for shift
            // shift and tap for underscore (including tapping twice)
            {
                if (is_shifted)
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

// oneshot to layer, shift for custom key:
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

// similar, code is slightly different
// TODO: check if both can be unified
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

// similar, code is slightly different
// TODO: check if both can be unified
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

// custom special character
        case MGC_PLS:
            // tap for `+`
            // tap when shifted for ` += `
            // TODO: this is cool, but not usable. I will never remember the
            // combination. Either choose something more useful, ab abandon
            // this magic.
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

// yet another approach to custom tap key (with special characters)
// somewhere in the declarations:
static bool was_shifted = false;
//
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

// tap for key, shift for oneshot to layer
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

