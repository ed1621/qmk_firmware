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
                        case HDR_QUES:
                            if (keyboard_report->mods & MOD_BIT (KC_LSFT)) {
                                clear_mods();
                                tap_code16(KC_EXLM);
                            }
                            else {
                                tap_code16(KC_QUES);
                            }
                            break;
                        case HDR_DQT:
                            if (keyboard_report->mods & MOD_BIT (KC_LSFT)) {
                                clear_mods();
                                tap_code16(KC_AT);
                            }
                            else {
                                tap_code(KC_BSLS);
                            }
                            break;
                        case HDR_MINS:
                            if (keyboard_report->mods & MOD_BIT (KC_LSFT)) {
                                clear_mods();
                                tap_code16(KC_PLUS);
                            }
                            else if (keyboard_report->mods & MOD_BIT (KC_LALT)) {
                                clear_mods();
                                tap_code16(KC_AMPR);
                            }
                            else {
                                tap_code(KC_MINS);
                            }
                            break;
                        case HDR_SLSH:
                            if (keyboard_report->mods & MOD_BIT (KC_LSFT)) {
                                clear_mods();
                                tap_code16(KC_PIPE);
                            }
                            else if (keyboard_report->mods & MOD_BIT (KC_LALT)) {
                                clear_mods();
                                tap_code16(KC_PERC);
                            }
                            else {
                                tap_code(KC_SLSH);
                            }
                            break;
                        case HDR_QUOT:
                            if (keyboard_report->mods & MOD_BIT (KC_LSFT)) {
                                clear_mods();
                                tap_code16(KC_HASH);
                            }
                            else if (keyboard_report->mods & MOD_BIT (KC_LALT)) {
                                clear_mods();
                                tap_code(KC_GRV);
                            }
                            else {
                                tap_code(KC_QUOT);
                            }
                            break;
                        case HDR_COMM:
                            if (keyboard_report->mods & MOD_BIT (KC_LSFT)) {
                                clear_mods();
                                tap_code(KC_SCLN);
                            }
                            else if (keyboard_report->mods & MOD_BIT (KC_LALT)) {
                                clear_mods();
                                tap_code16(KC_UNDS);
                            }
                            else {
                                tap_code(KC_COMM);
                            }
                            break;
                        case HDR_DOT:
                            if (keyboard_report->mods & MOD_BIT (KC_LSFT)) {
                                clear_mods();
                                tap_code16(KC_COLN);
                            }
                            else if (keyboard_report->mods & MOD_BIT (KC_LALT)) {
                                clear_mods();
                                SEND_STRING("...");
                            }
                            else {
                                tap_code(KC_DOT);
                            }
                            break;

                        case KC_M:
                            if ((prior_keycode == KC_G) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
                                tap_code(KC_L); // quickly typing "fm" yields "fl"
                                return_state = false; // don't do more with this record.
                            }
                            else if (keyboard_report->mods & MOD_BIT (KC_LALT)) {
                                clear_mods();
                                tap_code16(KC_TILDE);
                            }
                            break;
                        case KC_R:
                            if (keyboard_report->mods & MOD_BIT (KC_LALT)) {
                                clear_mods();
                                tap_code16(KC_LCBR);
                            }
                            break;
                        case KC_S:
                            if (keyboard_report->mods & MOD_BIT (KC_LALT)) {
                                clear_mods();
                                tap_code16(KC_RCBR);
                            }
                            break;
                        case KC_N:
                            if (keyboard_report->mods & MOD_BIT (KC_LALT)) {
                                clear_mods();
                                tap_code16(KC_LPRN);
                            }
                            break;
                        case KC_D:
                            if (keyboard_report->mods & MOD_BIT (KC_LALT)) {
                                clear_mods();
                                tap_code16(KC_RPRN);
                            }
                            break;
                        case KC_X:
                            if (keyboard_report->mods & MOD_BIT (KC_LALT)) {
                                clear_mods();
                                tap_code16(KC_LT);
                            }
                            break;
                        case KC_F:
                            if (keyboard_report->mods & MOD_BIT (KC_LALT)) {
                                clear_mods();
                                tap_code16(KC_GT);
                            }
                            break;
                        case KC_L:
                            if (keyboard_report->mods & MOD_BIT (KC_LALT)) {
                                clear_mods();
                                tap_code(KC_LBRC);
                            }
                            break;
                        case KC_C:
                            if (keyboard_report->mods & MOD_BIT (KC_LALT)) {
                                clear_mods();
                                tap_code(KC_RBRC);
                            }
                            break;
                        case KC_B: // IF KC_M precedes within ADAPTIVE_TERM, then send B to avoid row jump.
                            if ((prior_keycode == KC_C) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
                                tap_code(KC_K); // quickly typing "fm" yields "fl"
                                return_state = false; // don't do more with this record.
                            }
                            break;
                        case KC_A:
                            if (keyboard_report->mods & MOD_BIT (KC_LALT)) {
                                clear_mods();
                                tap_code16(KC_ASTR);
                            }
                            break;
                        case KC_E:
                            if (keyboard_report->mods & MOD_BIT (KC_LALT)) {
                                clear_mods();
                                tap_code(KC_EQL);
                            }
                            break;
                        case KC_H:
                            if (keyboard_report->mods & MOD_BIT (KC_LALT)) {
                                clear_mods();
                                tap_code16(KC_CIRC);
                            }
                            break;
                        case KC_U:
                            if (keyboard_report->mods & MOD_BIT (KC_LALT)) {
                                clear_mods();
                                tap_code16(KC_DLR);
                            }
                            break;
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
            } // end switch (keycode)

        prior_keycode = keycode;
        prior_keydown = timer_read(); // (re)start prior timingk
    } // end if(record->event.pressed)
    return return_state;
};
