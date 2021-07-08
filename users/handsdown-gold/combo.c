
#include "handsdown-gold.h"

const uint16_t PROGMEM H_Q_combo[] = {KC_X, KC_K, COMBO_END}; // TYPE "z"
const uint16_t PROGMEM H_Z_combo[] = {KC_K, KC_M, COMBO_END}; // TYPE "q"
const uint16_t PROGMEM H_TILD_combo[] = {KC_K, KC_F, COMBO_END}; // TYPE "~"
const uint16_t PROGMEM H_LBRC_combo[] = {KC_R, KC_S, COMBO_END}; // TYPE "["
const uint16_t PROGMEM H_RBRC_combo[] = {KC_S, KC_N, COMBO_END}; // TYPE "]"
const uint16_t PROGMEM H_LPRN_combo[] = {KC_N, KC_H, COMBO_END}; // TYPE "("
const uint16_t PROGMEM H_RPRN_combo[] = {KC_H, KC_P, COMBO_END}; // TYPE ")"
const uint16_t PROGMEM H_LT_combo[] = {KC_W, KC_G, COMBO_END}; // TYPE "<"
const uint16_t PROGMEM H_GT_combo[] = {KC_G, KC_L, COMBO_END}; // TYPE "<"
const uint16_t PROGMEM H_BSLS_combo[] = {HG_QUES, HG_COMM, COMBO_END}; // TYPE "\"
const uint16_t PROGMEM H_CIRC_combo[] = {HG_MINS, KC_A, COMBO_END}; // TYPE "^"
const uint16_t PROGMEM H_PERC_combo[] = {HG_SLSH, KC_U, COMBO_END}; // TYPE "%"
const uint16_t PROGMEM H_UNDS_combo[] = {HG_COMM, HG_DOT, COMBO_END}; // TYPE "_"
const uint16_t PROGMEM H_ASTR_combo[] = {KC_A, KC_E, COMBO_END}; // TYPE "*"
const uint16_t PROGMEM H_EQL_combo[] = {KC_E, KC_I, COMBO_END}; // TYPE "="
const uint16_t PROGMEM H_AMPR_combo[] = {KC_I, KC_C, COMBO_END}; // TYPE "&"
const uint16_t PROGMEM H_DLR_combo[] = {KC_U, KC_O, COMBO_END}; // TYPE "$"

const uint16_t PROGMEM H_ELLIPSE_combo[] = {HG_DOT, HG_DQT, COMBO_END}; // TYPE "..."
const uint16_t PROGMEM H_LV_combo[] = {KC_L, KC_D, COMBO_END}; // TYPE "lv"
const uint16_t PROGMEM H_QU_combo[] = {KC_X, KC_K, COMBO_END}; // TYPE "qu"
const uint16_t PROGMEM H_LM_combo[] = {KC_K, KC_M, COMBO_END}; // TYPE "lm"
const uint16_t PROGMEM H_LF_combo[] = {KC_M, KC_F, COMBO_END}; // TYPE "lf"
const uint16_t PROGMEM H_LK_combo[] = {KC_G, KC_L, COMBO_END}; // TYPE "lk"


combo_t key_combos[COMBO_COUNT] = {
    [HC_Z] = COMBO(H_Z_combo, KC_Z),
    [HC_Q] = COMBO(H_Q_combo, KC_Q),
    [HC_TILD] = COMBO(H_TILD_combo, KC_TILD),
    [HC_LPRN] = COMBO(H_LPRN_combo, KC_LPRN),
    [HC_RPRN] = COMBO(H_RPRN_combo, KC_RPRN),
    [HC_LT] = COMBO(H_LT_combo, KC_LT),
    [HC_GT] = COMBO(H_GT_combo, KC_GT),
    [HC_LBRC] = COMBO(H_LBRC_combo, KC_LBRC),
    [HC_RBRC] = COMBO(H_RBRC_combo, KC_RBRC),
    [HC_CIRC] = COMBO(H_CIRC_combo, KC_CIRC),
    [HC_PERC] = COMBO(H_PERC_combo, KC_PERC),
    [HC_UNDS] = COMBO(H_UNDS_combo, KC_UNDS),
    [HC_ASTR] = COMBO(H_ASTR_combo, KC_ASTR),
    [HC_EQL] = COMBO(H_EQL_combo, KC_EQL),
    [HC_AMPR] = COMBO(H_AMPR_combo, KC_AMPR),
    [HC_DLR] = COMBO(H_DLR_combo, KC_DLR),

    [HC_BSLS] = COMBO_ACTION(H_BSLS_combo),
    [HC_ELLIPSE] = COMBO_ACTION(H_ELLIPSE_combo),
    [HC_TYPE_LV] = COMBO_ACTION(H_LV_combo),
    [HC_TYPE_QU] = COMBO_ACTION(H_QU_combo),
    [HC_TYPE_LM] = COMBO_ACTION(H_LM_combo),
    [HC_TYPE_LF] = COMBO_ACTION(H_LF_combo),
    [HC_TYPE_LK] = COMBO_ACTION(H_LK_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    if (pressed) {
        keyhold_timer = timer_read(); // timer for combo hold threshold

        switch(combo_index) {
            case HC_BSLS ... HC_TYPE_LK: // these have a hold delay before triggering
                combo_on = combo_index; // queue for matrix_scan_user_process_combo
                break;
        } // end switch (combo_index)
    } else { // end if (pressed)
        // make this smarter/smaller/faster.
        // lookup keys to output from the key_combos[key_combos] table, bypassing this switch
        if (combo_on && !combo_triggered) {// no combo, so send the underlying keys
            switch(combo_index) {
                case HC_BSLS:
                    tap_code16(KC_BSLS);
                    break;
                case HC_ELLIPSE:
                    break;
                case HC_TYPE_LV:
                    tap_code(KC_L);
                    tap_code(KC_V);
                    break;
                case HC_TYPE_QU:
                    break;
                case HC_TYPE_LM:
                    tap_code(KC_L);
                    tap_code(KC_M);
                    break;
                case HC_TYPE_LF:
                    tap_code(KC_L);
                    tap_code(KC_F);
                    break;
            }  // end switch(combo_index) {
        }
        combo_on = combo_triggered = false;
    } // ELSE IF (pressed) meaning keyup
    return;

}


void matrix_scan_user_process_combo() {
    if (!combo_triggered) {
        if (combo_on && (timer_elapsed(keyhold_timer) > COMBO_HOLD)) {
            switch(combo_on) {  // combo_on is global, set in process_combo above
                case HC_BSLS:
                    SEND_STRING("\\");
                case HC_ELLIPSE:
                    SEND_STRING("...");
                    break;
                case HC_TYPE_LV:
                    SEND_STRING("lv");
                    break;
                case HC_TYPE_QU:
                    unregister_code(KC_Q);
                    SEND_STRING("u");
                    break;
                case HC_TYPE_LM:
                    SEND_STRING("lm");
                    break;
                case HC_TYPE_LF:
                    SEND_STRING("lf");
                    break;
            } // switch
            combo_triggered = true;
        }
    }
}

