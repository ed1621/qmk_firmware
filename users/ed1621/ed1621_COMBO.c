//
// Created by Ed Martinez on 6/6/21.
//
#define combo_OLED_row 5
const uint16_t PROGMEM H_Q_combo[] = {KC_QUOT, KC_U, COMBO_END}; // TYPE "q"
const uint16_t PROGMEM H_Z_combo[] = {KC_QUOT, KC_Y, COMBO_END}; // TYPE "z"
const uint16_t PROGMEM H_SCLN_combo[] = {KC_SLSH, KC_LPRN, COMBO_END}; // TYPE ";"
const uint16_t PROGMEM H_CLN_combo[] = {KC_SLSH, KC_RPRN, COMBO_END}; // TYPE ":"
const uint16_t PROGMEM H_BSLS_combo[] = {KC_SLSH, KC_EQL, COMBO_END}; // TYPE "\"
const uint16_t PROGMEM H_ASTRSK_combo[] = {KC_SLSH, KC_MINS, COMBO_END}; // TYPE "*"
const uint16_t PROGMEM H_PLUS_combo[] = {KC_MINS, KC_LPRN, COMBO_END}; // TYPE "+"
const uint16_t PROGMEM H_LT_combo[] = {KC_LPRN, KC_RPRN, COMBO_END}; // TYPE "<"
const uint16_t PROGMEM H_GT_combo[] = {KC_RPRN, KC_EQL, COMBO_END}; // TYPE ">"

const uint16_t PROGMEM H_LM_combo[] = {KC_G, KC_M, COMBO_END}; // TYPE "LM"
const uint16_t PROGMEM H_LF_combo[] = {KC_M, KC_F, COMBO_END}; // TYPE "lf"
const uint16_t PROGMEM H_CK_combo[] = {KC_F, KC_K, COMBO_END}; // TYPE "ck"

enum custom_combos {
    HC_Q,
    HC_Z,
    HC_SCLN,
    HC_CLN,
    HC_BSLS,
    HC_ASTRSK,
    HC_PLUS,
    HC_LT,
    HC_GT,
    HC_TYPE_LM,
    HC_TYPE_LF,
    HC_TYPE_CK,
};

combo_t key_combos[COMBO_COUNT] = {
    [HC_Q] = COMBO(H_Q_combo, KC_Q),
    [HC_Z] = COMBO(H_Z_combo, KC_Z),
    [HC_SCLN] = COMBO(H_SCLN_combo, KC_SCLN),
    [HC_CLN] = COMBO(H_CLN_combo, KC_COLN),
    [HC_BSLS] = COMBO(H_BSLS_combo, KC_BSLS),
    [HC_ASTRSK] = COMBO(H_ASTRSK_combo, KC_ASTR),
    [HC_PLUS] = COMBO(H_PLUS_combo, KC_PLUS),
    [HC_LT] = COMBO(H_LT_combo, KC_LT),
    [HC_GT] = COMBO(H_GT_combo, KC_GT),

    [HC_TYPE_LM] = COMBO_ACTION(H_LM_combo),
    [HC_TYPE_LF] = COMBO_ACTION(H_LF_combo),
    [HC_TYPE_CK] = COMBO_ACTION(H_CK_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    if (pressed) {
        keyhold_timer = timer_read(); // timer for combo hold threshold
        switch(combo_index) {
            case HC_TYPE_LM ... HC_TYPE_CK: // these have a hold delay before triggering
                combo_on = combo_index; // queue for matrix_scan_user_process_combo
                break;
        } // end switch (combo_index)
    } else { // end if (pressed)

/*/
 This is the NOT pressed switch (ie. it is the key up event)
/*/
        // make this smarter/smaller/faster.
        // lookup keys to output from the key_combos[key_combos] table, bypassing this switch
        if (combo_on && !combo_triggered) {// no combo, so send the underlying keys
            switch(combo_index) {
                case HC_TYPE_LM:
                    tap_code(KC_L);
                    tap_code(KC_M);
                    break;
                case HC_TYPE_LF:
                    tap_code(KC_L);
                    tap_code(KC_F);
                    break;
                case HC_TYPE_CK:
                    tap_code(KC_C);
                    tap_code(KC_K);
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
                case HC_TYPE_LM:
                    SEND_STRING("lm");
                    break;
                case HC_TYPE_LF:
                    SEND_STRING("lf");
                    break;
                case HC_TYPE_CK:
                    SEND_STRING("ck");
                    break;
            } // switch
            combo_triggered = true;
        }
    }
}

