
#include "ed1621.h"

#ifdef HANDSDOWN_ELAN
// Similar combo results across handsdown variants
    const uint16_t PROGMEM H_Q_combo[] = {KC_QUOT, KC_U, COMBO_END}; // TYPE "q"
    const uint16_t PROGMEM H_Z_combo[] = {KC_QUOT, KC_X, COMBO_END}; // TYPE "z"
    const uint16_t PROGMEM H_BSLS_combo[] = {KC_SLSH, KC_EQL, COMBO_END}; // TYPE "\"
    const uint16_t PROGMEM H_ASTRSK_combo[] = {KC_SLSH, KC_W, COMBO_END}; // TYPE "*"
    const uint16_t PROGMEM H_LBRC_combo[] = {KC_W, KC_LPRN, COMBO_END}; // TYPE "["
    const uint16_t PROGMEM H_RBRC_combo[] = {KC_LPRN, KC_RPRN, COMBO_END}; // TYPE "]"
    const uint16_t PROGMEM H_QU_combo[] = {KC_QUOT, KC_U, COMBO_END}; // TYPE "qu"
    const uint16_t PROGMEM H_CK_combo[] = {KC_F, KC_K, COMBO_END}; // TYPE "ck"

// Unique to Elan
    const uint16_t PROGMEM H_PLUS_combo[] = {KC_SLSH, KC_MINS, COMBO_END}; // TYPE "+"
    const uint16_t PROGMEM H_HASH_combo[] = {KC_RPRN, KC_EQL, COMBO_END}; // TYPE "#"
#endif

#ifdef HANDSDOWN_ALT_TX
// Similar combo results across handsdown variants
    const uint16_t PROGMEM H_Q_combo[] = {KC_K, KC_U, COMBO_END}; // TYPE "q"
    const uint16_t PROGMEM H_Z_combo[] = {KC_U, KC_J, COMBO_END}; // TYPE "z"
    const uint16_t PROGMEM H_BSLS_combo[] = {KC_SLSH, KC_W, COMBO_END}; // TYPE "\"
    const uint16_t PROGMEM H_ASTRSK_combo[] = {KC_MINS, KC_W, COMBO_END}; // TYPE "*"
    const uint16_t PROGMEM H_LBRC_combo[] = {KC_F, KC_DQT, COMBO_END}; // TYPE "["
    const uint16_t PROGMEM H_RBRC_combo[] = {KC_QUOT, KC_K, COMBO_END}; // TYPE "]"
    const uint16_t PROGMEM H_QU_combo[] = {KC_K, KC_U, COMBO_END}; // TYPE "qu"
    const uint16_t PROGMEM H_CK_combo[] = {KC_C, KC_L, COMBO_END}; // TYPE "ck"

// Unique to Alt-Tx
    const uint16_t PROGMEM H_SCLN_combo[] = {KC_SLSH, KC_COMM, COMBO_END}; // TYPE ";"
    const uint16_t PROGMEM H_CLN_combo[] = {KC_DOT, KC_COMM, COMBO_END}; // TYPE ":"
    const uint16_t PROGMEM H_EXCL_combo[] = {KC_SLSH, KC_DOT, COMBO_END}; // TYPE "!"
    const uint16_t PROGMEM H_LPRN_combo[] = {KC_F, KC_P, COMBO_END}; // TYPE "("
    const uint16_t PROGMEM H_RPRN_combo[] = {KC_Y, KC_K, COMBO_END}; // TYPE ")"
    const uint16_t PROGMEM H_AT_combo[] = {KC_J, KC_HASH, COMBO_END}; // TYPE "@"
    const uint16_t PROGMEM H_LV_combo[] = {KC_L, KC_D, COMBO_END}; // TYPE "lv"
#endif

const uint16_t PROGMEM H_LM_combo[] = {KC_G, KC_M, COMBO_END}; // TYPE "lm"
const uint16_t PROGMEM H_LF_combo[] = {KC_M, KC_F, COMBO_END}; // TYPE "lf"
const uint16_t PROGMEM H_GL_combo[] = {KC_V, KC_G, COMBO_END}; // TYPE "gl"
const uint16_t PROGMEM H_LK_combo[] = {KC_X, KC_C, COMBO_END}; // TYPE "lk"

enum custom_combos {
    HC_Q,
    HC_Z,
    HC_BSLS,
    HC_ASTRSK,
    HC_RBRC,
    HC_LBRC,

    #ifdef HANDSDOWN_ELAN
        HC_PLUS,
        HC_HASH,
    #endif

    #ifdef HANDSDOWN_ALT_TX
        HC_SCLN,
        HC_CLN,
        HC_EXCL,
        HC_LPRN,
        HC_RPRN,
        HC_AT,
        HC_TYPE_LV,
    #endif

    HC_TYPE_QU,
    HC_TYPE_CK,
    HC_TYPE_LM,
    HC_TYPE_LF,
    HC_TYPE_GL,
    HC_TYPE_LK,
};

combo_t key_combos[COMBO_COUNT] = {
    [HC_Q] = COMBO(H_Q_combo, KC_Q),
    [HC_Z] = COMBO(H_Z_combo, KC_Z),
    [HC_BSLS] = COMBO(H_BSLS_combo, KC_BSLS),
    [HC_ASTRSK] = COMBO(H_ASTRSK_combo, KC_ASTR),
    [HC_RBRC] = COMBO(H_RBRC_combo, KC_RBRC),
    [HC_LBRC] = COMBO(H_LBRC_combo, KC_LBRC),

    #ifdef HANDSDOWN_ELAN
        [HC_PLUS] = COMBO(H_PLUS_combo, KC_PLUS),
        [HC_HASH] = COMBO(H_HASH_combo, KC_HASH),
    #endif
    #ifdef HANDSDOWN_ALT_TX
        [HC_SCLN] = COMBO(H_SCLN_combo, KC_SCLN),
        [HC_CLN] = COMBO(H_CLN_combo, KC_COLN),
        [HC_EXCL] = COMBO(H_EXCL_combo, KC_EXLM),
        [HC_LPRN] = COMBO(H_LPRN_combo, KC_LPRN),
        [HC_RPRN] = COMBO(H_RPRN_combo, KC_RPRN),
        [HC_AT] = COMBO(H_AT_combo, KC_AT),
        [HC_TYPE_LV] = COMBO_ACTION(H_LV_combo),
    #endif

    [HC_TYPE_QU] = COMBO_ACTION(H_QU_combo),
    [HC_TYPE_CK] = COMBO_ACTION(H_CK_combo),
    [HC_TYPE_LM] = COMBO_ACTION(H_LM_combo),
    [HC_TYPE_LF] = COMBO_ACTION(H_LF_combo),
    [HC_TYPE_GL] = COMBO_ACTION(H_GL_combo),
    [HC_TYPE_LK] = COMBO_ACTION(H_LK_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    if (pressed) {
        keyhold_timer = timer_read(); // timer for combo hold threshold

        switch(combo_index) {
            case HC_TYPE_QU ... HC_TYPE_LK: // these have a hold delay before triggering
        #ifdef HANDSDOWN_ALT_TX
            case HC_TYPE_LV:
        #endif
                combo_on = combo_index; // queue for matrix_scan_user_process_combo
                break;
        } // end switch (combo_index)

    } else { // end if (pressed)
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
                case HC_TYPE_GL:
                    tap_code(KC_G);
                    tap_code(KC_L);
                    break;
                case HC_TYPE_LK:
                    tap_code(KC_L);
                    tap_code(KC_K);
                    break;
            #ifdef HANDSDOWN_ALT_TX
                case HC_TYPE_LV:
                    tap_code(KC_L);
                    tap_code(KC_V);
                    break;
            #endif
                case HC_TYPE_QU:
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
                case HC_TYPE_GL:
                    SEND_STRING("gl");
                    break;
                case HC_TYPE_LK:
                    SEND_STRING("lk");
                    break;
            #ifdef HANDSDOWN_ALT_TX
                case HC_TYPE_LV:
                    SEND_STRING("lv");
                    break;
            #endif
                case HC_TYPE_QU:
                    unregister_code(KC_Q);
                    SEND_STRING("qu");
                    break;
            } // switch
            combo_triggered = true;
        }
    }
}

