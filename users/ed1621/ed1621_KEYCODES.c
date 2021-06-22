//
// Created by Ed Martinez on 6/7/21.
//
// uint16_t prior_keycode = KC_NO;
// uint16_t prior_keydown = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool return_state = true;

    switch (keycode) {
        case LAMBDA:
            if (record->event.pressed) {
                if (keyboard_report->mods & MOD_BIT (KC_LSFT)) {
                    clear_mods();
                    SEND_STRING("->");
                }
                else {
                    SEND_STRING("=>");
                }
            }
            break;
        // case KC_M: // IF KC_F or KC_G precedes within ADAPTIVE_TERM, then send L to avoid row jump.
        //     if (((prior_keycode == KC_F)||(prior_keycode == KC_G)) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
        //         tap_code(KC_L); // quickly typing "fm" yields "fl"
        //         return_state = false; // don't do more with this record.
        //     }
        //     break;
        // case KC_F: // IF KC_M precedes within ADAPTIVE_TERM, then send B to avoid row jump.
        //     if ((prior_keycode == KC_M) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
        //         tap_code(KC_B); // quickly typing "fm" yields "fl"
        //         return_state = false; // don't do more with this record.
        //     }
        //     break;
        // case KC_D: // IF KC_B precedes, then send L bc hand moved out of home block.
        //     if ((prior_keycode == KC_B) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
        //         tap_code(KC_L); // quickly typing "bd" yields "bl"
        //         return_state = false; // don't do more with this record.
        //     }
        //     break;
    }
    // prior_keycode = keycode;
    // prior_keydown = timer_read();
    return return_state;
};
