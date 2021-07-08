#include "handsdown-gold.h"

uint16_t prior_keycode = KC_NO;
uint16_t prior_keydown = 0;

void create_hg_key_with_alt(uint16_t shifted_keycode, uint16_t alt_keycode, uint16_t default_keycode); 
void create_hg_key_no_alt(uint16_t shifted_keycode, uint16_t default_keycode); 

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool return_state = true;

    switch (keycode) {
        case LAMBDA:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING("->");
                }
                else {
                    SEND_STRING("=>");
                }
            }
            break;
        case MAC_LOCK:
            if (record->event.pressed) {
                tap_code16(C(G(KC_Q)));
            }
            break;
        case HG_QUES:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    register_code16(KC_EXLM);
                    /* SEND_STRING("!"); */
                }
                else if (get_mods() & MOD_MASK_ALT) {
                    clear_mods();
                    register_code(KC_GRAVE);
                }
                else {
                    register_code16(KC_QUES);
                    /* SEND_STRING("?"); */
                }
            }
            else {
                clear_keyboard();
            }
            break;
        case HG_MINS:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    register_code16(KC_PLUS);
                }
                else {
                    register_code(KC_MINS);
                }
            }
            else {
                clear_keyboard();
            }
            break;
        case HG_SLSH:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    register_code16(KC_PIPE);
                }
                else {
                    register_code(KC_SLSH);
                }
            }
            else {
                clear_keyboard();
            }
            break;
        case HG_COMM:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    register_code(KC_SCLN);
                }
                else {
                    register_code(KC_COMM);
                }
            }   
            else {
                clear_keyboard();
            }
            break;
        case HG_DOT:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    register_code16(KC_COLN);
                }
                else {
                    register_code(KC_DOT);
                }
            }
            else {
                clear_keyboard();
            }
            break;
        case HG_DQT:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    register_code16(KC_AT);
                }
                else if (get_mods() & MOD_MASK_ALT) {
                    clear_mods();
                    register_code16(KC_LT);
                }
                else {
                    register_code16(KC_DQT);
                }
            }
            else {
                clear_keyboard();
            }
            break;
        case HG_QUOT:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    register_code16(KC_HASH);
                }
                else if (get_mods() & MOD_MASK_ALT) {
                    clear_mods();
                    register_code16(KC_GT);
                }
                else {
                    register_code(KC_QUOT);
                }
            }
            else {
                clear_keyboard();
            }
            break;
    } // end switch (keycode)

    if (record->event.pressed) {
        switch(get_highest_layer(default_layer_state)) {
            case _HANDSDOWN:
                switch (keycode) {
                    case KC_M: // IF KC_F or KC_G precedes within ADAPTIVE_TERM, then send L to avoid row jump.
                        if (((prior_keycode == KC_F)||(prior_keycode == KC_K)) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
                            tap_code(KC_L); // quickly typing "fm" yields "fl" || "km" yields "kl"
                            return_state = false; // don't do more with this record.
                        }
                        break;
                    case KC_F: // IF KC_M precedes within ADAPTIVE_TERM, then send B to avoid row jump.
                        if ((prior_keycode == KC_M) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
                            tap_code(KC_B); // quickly typing "mf" yields "mb"
                            return_state = false; // don't do more with this record.
                        }
                        break;
                    case KC_K:
                        if ((prior_keycode == KC_M) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
                            unregister_code(KC_M);
                            unregister_code(KC_K);
                            tap_code(KC_L); 
                            tap_code(KC_K); // quickly typing "mk" yields "lk"
                            return_state = false; // don't do more with this record.
                        }
                        break;
                    case KC_D:
                        if ((prior_keycode == KC_B) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
                            tap_code(KC_L); // quickly typing "bd" yields "bl"
                            return_state = false; // don't do more with this record.
                        }
                        break;
                }
                break;
        }


        prior_keycode = keycode;
        prior_keydown = timer_read(); // (re)start prior timingk
    } // end if(record->event.pressed)
    return return_state;
};

void create_hg_key_with_alt(uint16_t shifted_keycode, uint16_t alt_keycode, uint16_t default_keycode) {
    if (get_mods() & MOD_MASK_SHIFT) {
        clear_mods();
        tap_code16(shifted_keycode);
    }
    else if (get_mods() & MOD_MASK_ALT) {
        clear_mods();
        tap_code16(alt_keycode);
    }
    else {
        tap_code16(default_keycode);
    }
}

void create_hg_key_no_alt(uint16_t shifted_keycode, uint16_t default_keycode) {
    if (get_mods() & MOD_MASK_SHIFT) {
        clear_mods();
        tap_code16(shifted_keycode);
    }
    else {
        tap_code16(default_keycode);
    }
}
