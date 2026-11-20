#include "ed1621.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (record->event.pressed) {
        uint8_t mods = get_mods();
        switch (keycode) {
            case LAMBDA:
                if (mods & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING("->");
                    set_mods(mods);
                }
                else {
                    SEND_STRING("=>");
                }
                break;
            case LPARENS:
                if (mods & MOD_MASK_SHIFT) {
                    clear_mods();
                    tap_code16(KC_LCBR);
                    set_mods(mods);
                }
                else if (mods & MOD_MASK_CTRL) {
                    clear_mods();
                    tap_code(KC_LBRC);
                    set_mods(mods);
                }
                else {
                    tap_code16(KC_LPRN);
                }
                break;
            case RPARENS:
                if (mods & MOD_MASK_SHIFT) {
                    clear_mods();
                    tap_code16(KC_RCBR);
                    set_mods(mods);
                }
                else if (mods & MOD_MASK_CTRL) {
                    clear_mods();
                    tap_code(KC_RBRC);
                    set_mods(mods);
                }
                else {
                    tap_code16(KC_RPRN);
                }
                break;
            case LTSLASH:
                if (mods & MOD_MASK_SHIFT) {
                    clear_mods();
                    tap_code16(KC_LT);
                    set_mods(mods);
                }
                else {
                    tap_code(KC_SLSH);
                }
                break;
            case COMMQUES:
                if (mods & MOD_MASK_SHIFT) {
                    clear_mods();
                    tap_code16(KC_QUES);
                    set_mods(mods);
                }
                else {
                    tap_code(KC_COMM);
                }
                break;
        } // end switch (keycode)

    } // end if(record->event.pressed)
    return true;
};
