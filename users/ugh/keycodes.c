#include "ed1621.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

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
            case MAC_SLEEP:
                tap_code16(A(G(KC_EJCT)));
                break;
            case MAC_LOCK:
                tap_code16(C(G(KC_Q)));
                break;
        } // end switch (keycode)

    } // end if(record->event.pressed)
    return true;
};