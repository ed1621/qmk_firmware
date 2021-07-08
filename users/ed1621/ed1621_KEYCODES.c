#include "ed1621.h"

uint16_t prior_keycode = KC_NO;
uint16_t prior_keydown = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool return_state = true;


    if (record->event.pressed) {
        switch(get_highest_layer(default_layer_state)) {
            case _HANDSDOWN:
                switch (keycode) {
                    #if defined (HANDSDOWN_ELAN) || defined (HANDSDOWN_ALT_TX)
                        case KC_M: // IF KC_F or KC_G precedes within ADAPTIVE_TERM, then send L to avoid row jump.
                                    if (((prior_keycode == KC_F)||(prior_keycode == KC_G)) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
                                        tap_code(KC_L); // quickly typing "fm" yields "fl" || "gm" yields "gl"
                                        return_state = false; // don't do more with this record.
                                }
                            break;
                        case KC_F: // IF KC_M precedes within ADAPTIVE_TERM, then send B to avoid row jump.
                                    if ((prior_keycode == KC_M) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
                                        tap_code(KC_B); // quickly typing "mf" yields "mb"
                                        return_state = false; // don't do more with this record.
                                    }
                            break;
                        #ifdef HANDSDOWN_ELAN
                            case KC_D: // IF KC_B precedes, then send L bc hand moved out of home block.
                                if ((prior_keycode == KC_B) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
                                    tap_code(KC_L); // quickly typing "bx" yields "bl"
                                    return_state = false; // don't do more with this record.
                                }
                                break;

                        #endif
                        #ifdef HANDSDOWN_ALT_TX
                            case KC_G: // IF KC_V precedes, then send L bc hand moved out of home block.
                                if ((prior_keycode == KC_V) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
                                    tap_code(KC_L); // quickly typing "vg" yields "vl"
                                    return_state = false; // don't do more with this record.
                                }
                                break;
                        #endif
                    #endif
                }
                break;
        }

        switch (keycode) {
            case LAMBDA:
                if (keyboard_report->mods & MOD_BIT (KC_LSFT)) {
                    clear_mods();
                    SEND_STRING("->");
                }
                else {
                    SEND_STRING("=>");
                }
                break;
            case MAC_SLEEP:
                tap_code16(A(G(KC_EJCT)));
                break;
            case MAC_LOCK:
                tap_code16(C(G(KC_Q)));
                break;
        } // end switch (keycode)

        prior_keycode = keycode;
        prior_keydown = timer_read(); // (re)start prior timingk
    } // end if(record->event.pressed)
    return return_state;
};
