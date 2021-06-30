#include "ed1621.h"

static uint32_t keyhold_timer = 0;
#ifdef HANDSDOWN_ELAN
    const uint16_t PROGMEM H_Q_combo[] = {KC_QUOT, KC_U, COMBO_END}; // TYPE "q"
    const uint16_t PROGMEM H_Z_combo[] = {KC_QUOT, KC_X, COMBO_END}; // TYPE "z"
    const uint16_t PROGMEM H_BSLS_combo[] = {KC_SLSH, KC_EQL, COMBO_END}; // TYPE "\"
    const uint16_t PROGMEM H_PLUS_combo[] = {KC_SLSH, KC_MINS, COMBO_END}; // TYPE "+"
    const uint16_t PROGMEM H_ASTRSK_combo[] = {KC_SLSH, KC_W, COMBO_END}; // TYPE "*"
    const uint16_t PROGMEM H_LBRC_combo[] = {KC_W, KC_LPRN, COMBO_END}; // TYPE "["
    const uint16_t PROGMEM H_RBRC_combo[] = {KC_LPRN, KC_RPRN, COMBO_END}; // TYPE "]"
    const uint16_t PROGMEM H_HASH_combo[] = {KC_RPRN, KC_EQL, COMBO_END}; // TYPE "#"
    const uint16_t PROGMEM H_QU_combo[] = {KC_QUOT, KC_U, COMBO_END}; // TYPE "qu"
    const uint16_t PROGMEM H_CK_combo[] = {KC_F, KC_K, COMBO_END}; // TYPE "ck"
#endif

#ifdef HANDSDOWN_ALT_TX
    const uint16_t PROGMEM H_Q_combo[] = {KC_K, KC_U, COMBO_END}; // TYPE "q"
    const uint16_t PROGMEM H_Z_combo[] = {KC_U, KC_J, COMBO_END}; // TYPE "z"
    const uint16_t PROGMEM H_SCLN_combo[] = {KC_SLSH, KC_COMM, COMBO_END}; // TYPE ";"
    const uint16_t PROGMEM H_CLN_combo[] = {KC_DOT, KC_COMM, COMBO_END}; // TYPE ":"
    const uint16_t PROGMEM H_EXCL_combo[] = {KC_SLSH, KC_DOT, COMBO_END}; // TYPE "!"
    const uint16_t PROGMEM H_BSLS_combo[] = {KC_SLSH, KC_W, COMBO_END}; // TYPE "\"

    const uint16_t PROGMEM H_ASTRSK_combo[] = {KC_MINS, KC_W, COMBO_END}; // TYPE "*"
    const uint16_t PROGMEM H_LBRC_combo[] = {KC_F, KC_DQT, COMBO_END}; // TYPE "["
    const uint16_t PROGMEM H_RBRC_combo[] = {KC_QUOT, KC_K, COMBO_END}; // TYPE "]"
    const uint16_t PROGMEM H_AT_combo[] = {KC_J, KC_HASH, COMBO_END}; // TYPE "@"
    const uint16_t PROGMEM H_CK_combo[] = {KC_C, KC_L, COMBO_END}; // TYPE "ck"
    const uint16_t PROGMEM H_QU_combo[] = {KC_K, KC_U, COMBO_END}; // TYPE "qu"
#endif

const uint16_t PROGMEM H_LM_combo[] = {KC_G, KC_M, COMBO_END}; // TYPE "LM"
const uint16_t PROGMEM H_LF_combo[] = {KC_M, KC_F, COMBO_END}; // TYPE "lf"
const uint16_t PROGMEM H_GL_combo[] = {KC_V, KC_G, COMBO_END}; // TYPE "gl"
const uint16_t PROGMEM H_LK_combo[] = {KC_X, KC_C, COMBO_END}; // TYPE "lk"

enum custom_combos {
    HC_Q,
    HC_Z,
    HC_BSLS,
    HC_ASTRSK,
    HC_LBRC,
    HC_RBRC,
    HC_TYPE_LM,
    HC_TYPE_LF,
    HC_TYPE_CK,
    HC_TYPE_GL,
    HC_TYPE_LK,
    #ifdef HANDSDOWN_ELAN
        HC_PLUS,
        HC_HASH,
    #endif
    #ifdef HANDSDOWN_ALT_TX
        HC_SCLN,
        HC_CLN,
        HC_EXCL,
        HC_AT,
        HC_TYPE_QU,
    #endif
};

combo_t key_combos[COMBO_COUNT] = {
    [HC_Q] = COMBO(H_Q_combo, KC_Q),
    [HC_Z] = COMBO(H_Z_combo, KC_Z),
    [HC_BSLS] = COMBO(H_BSLS_combo, KC_BSLS),
    [HC_ASTRSK] = COMBO(H_ASTRSK_combo, KC_ASTR),
    [HC_LBRC] = COMBO(H_LBRC_combo, KC_LBRC),
    [HC_RBRC] = COMBO(H_RBRC_combo, KC_RBRC),
    #ifdef HANDSDOWN_ELAN
        [HC_PLUS] = COMBO(H_PLUS_combo, KC_PLUS),
        [HC_HASH] = COMBO(H_HASH_combo, KC_HASH),
    #endif
    #ifdef HANDSDOWN_ALT_TX
        [HC_SCLN] = COMBO(H_SCLN_combo, KC_SCLN),
        [HC_CLN] = COMBO(H_CLN_combo, KC_COLN),
        [HC_EXCL] = COMBO(H_EXCL_combo, KC_EXLM),
        [HC_AT] = COMBO(H_AT_combo, KC_AT),

    #endif

    [HC_TYPE_LM] = COMBO_ACTION(H_LM_combo),
    [HC_TYPE_LF] = COMBO_ACTION(H_LF_combo),
    [HC_TYPE_CK] = COMBO_ACTION(H_CK_combo),
    [HC_TYPE_GL] = COMBO_ACTION(H_GL_combo),
    [HC_TYPE_LK] = COMBO_ACTION(H_LK_combo),
    [HC_TYPE_QU] = COMBO_ACTION(H_QU_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    if (pressed) {
        keyhold_timer = timer_read(); // timer for combo hold threshold
        switch(combo_index) {
            case HC_TYPE_LM ... HC_TYPE_QU: // these have a hold delay before triggering
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
                case HC_TYPE_GL:
                    tap_code(KC_G);
                    tap_code(KC_L);
                    break;
                case HC_TYPE_LK:
                    tap_code(KC_L);
                    tap_code(KC_K);
                    break;
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
                case HC_TYPE_QU:
                    SEND_STRING("u");
                    break;
            } // switch
            combo_triggered = true;
        }
    }
}

