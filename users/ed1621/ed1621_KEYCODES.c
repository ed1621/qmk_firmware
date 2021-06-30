#include "ed1621.h"

uint16_t prior_keycode = KC_NO;
uint16_t prior_keydown = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool return_state = true;

    if (record->event.pressed) {
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

            #if defined (HANDSDOWN_ELAN) || defined (HANDSDOWN_ALT_TX)
                case KC_M: // IF KC_F or KC_G precedes within ADAPTIVE_TERM, then send L to avoid row jump.
                            if (((prior_keycode == KC_F)||(prior_keycode == KC_G)) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
                                tap_code(KC_L); // quickly typing "fm" yields "fl"
                                return_state = false; // don't do more with this record.
                        }
                    break;
                case KC_F: // IF KC_M precedes within ADAPTIVE_TERM, then send B to avoid row jump.
                            if ((prior_keycode == KC_M) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
                                tap_code(KC_B); // quickly typing "fm" yields "fl"
                                return_state = false; // don't do more with this record.
                            }
                    break;
                #ifdef HANDSDOWN_ELAN
                    case KC_X: // IF KC_B precedes, then send L bc hand moved out of home block.
                            if ((prior_keycode == KC_B) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
                                tap_code(KC_L); // quickly typing "bx" yields "bl"
                                return_state = false; // don't do more with this record.
                            }
                    break;
                #endif
            #elif defined (HANDSDOWN_ROLL)
                case HDR_QUESTION:
                    if (keyboard_report->mods & MOD_BIT (KC_LSFT)) {
                        clear_mods();
                        SEND_STRING("!");
                    }
                    else {
                        SEND_STRING("?");
                    }
                    break;
                case HDR_DQT:
                    if (keyboard_report->mods & MOD_BIT (KC_LSFT)) {
                        clear_mods();
                        SEND_STRING("@");
                    }
                    else {
                        SEND_STRING("\"");
                    }
                    break;
                case HDR_MINS:
                    if (keyboard_report->mods & MOD_BIT (KC_LSFT)) {
                        clear_mods();
                        SEND_STRING("+");
                    }
                    else if (keyboard_report->mods & MOD_BIT (KC_LALT)) {
                        clear_mods();
                        SEND_STRING("&");
                    }
                    else {
                        SEND_STRING("-");
                    }
                    break;
                case HDR_SLSH:
                    if (keyboard_report->mods & MOD_BIT (KC_LSFT)) {
                        clear_mods();
                        SEND_STRING("|");
                    }
                    else if (keyboard_report->mods & MOD_BIT (KC_LALT)) {
                        clear_mods();
                        SEND_STRING("%");
                    }
                    else {
                        SEND_STRING("/");
                    }
                    break;
                case HDR_QUOT:
                    if (keyboard_report->mods & MOD_BIT (KC_LSFT)) {
                        clear_mods();
                        SEND_STRING("#");
                    }
                    else if (keyboard_report->mods & MOD_BIT (KC_LALT)) {
                        clear_mods();
                        SEND_STRING("`");
                    }
                    else {
                        SEND_STRING("'");
                    }
                    break;
                case HDR_COMM:
                    if (keyboard_report->mods & MOD_BIT (KC_LSFT)) {
                        clear_mods();
                        SEND_STRING(";");
                    }
                    else if (keyboard_report->mods & MOD_BIT (KC_LALT)) {
                        clear_mods();
                        SEND_STRING("_");
                    }
                    else {
                        SEND_STRING(",");
                    }
                    break;
                case HDR_DOT:
                    if (keyboard_report->mods & MOD_BIT (KC_LSFT)) {
                        clear_mods();
                        SEND_STRING(":");
                    }
                    else if (keyboard_report->mods & MOD_BIT (KC_LALT)) {
                        clear_mods();
                        SEND_STRING("...");
                    }
                    else {
                        SEND_STRING(".");
                    }
                    break;
           #endif
            } // end switch (keycode)

        // if (IS_LAYER_ON(_HANDSDOWN)) {

        // }

        prior_keycode = keycode;
        prior_keydown = timer_read(); // (re)start prior timingk
    } // end if(record->event.pressed)
    return return_state;
};
