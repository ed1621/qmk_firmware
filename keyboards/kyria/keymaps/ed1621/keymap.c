#include "ed1621.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        GRAVE_ESC,  KC_Q,           KC_W,           KC_E,          KC_R,                     KC_T,                                                                          KC_Y,    KC_U,         KC_I,         KC_O,            KC_P,            KC_EQL,
        KC_TAB,      LGUI_T(KC_A),   LALT_T(KC_S),   LCTL_T(KC_D),  LSFT_T(KC_F),             KC_G,                                                                          KC_H,    LSFT_T(KC_J), LCTL_T(KC_K), LALT_T(KC_L),    LGUI_T(KC_SCLN), KC_QUOT,
        LAMBDA,      KC_Z,           KC_X,           KC_C,          LT(_FUNCTIONKEYS, KC_V),  KC_B,  KC_LSFT,                KC_LSFT,           KC_LSFT,            KC_LSFT, KC_N,    KC_M,         KC_COMM,      KC_DOT,          KC_SLSH,         KC_BSLS,
                                                                                U_TMX, KC_CAPS, XXX, MO(_COMMANDS), LT(_NUMPAD, KC_MINS),       LT(_MEDIA, KC_SPC), LT(_SYMBOLS, KC_ENT),   XXX, XXX,  DF(_HANDSDOWN)
    ),
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//*****************************************************//
//                                                     //
//                   HANDSDOWN LAYOUTS                 //
//  https://sites.google.com/alanreiser.com/handsdown  //
//                                                     //
//*****************************************************//

    #if defined (HANDSDOWN_ALT_TX)
    [_HANDSDOWN] = LAYOUT(
        ___,      KC_V,         KC_G,         KC_M,         KC_F,                     KC_DQT,                                KC_QUOT,  KC_K,         KC_U,         KC_J,            KC_HASH,         XXX,
        ___,      LGUI_T(KC_R), LALT_T(KC_S), LCTL_T(KC_N), LSFT_T(KC_H),             KC_P,                                  KC_Y,     LSFT_T(KC_I), LCTL_T(KC_E), LALT_T(KC_O),    LGUI_T(KC_A),    XXX,
        ___,      KC_X,         KC_C,         KC_L,         LT(_FUNCTIONKEYS, KC_D),  KC_B, KC_LBRC, XXX,      XXX, KC_RBRC, KC_MINS,  KC_W,         KC_SLSH,      KC_COMM,         KC_DOT,          XXX,
                                            ___, ___, ___, LT(_COMMANDS, KC_T), LT(_NUMPAD, KC_EQL),                    ___, ___, ___, ___, DF(_QWERTY)
    ),
    #elif defined (HANDSDOWN_ELAN)
    [_HANDSDOWN] = LAYOUT(
        ___,      KC_V,         KC_G,         KC_M,         KC_F,                     KC_K,                                              KC_QUOT,  KC_U,         KC_O,         KC_X,            KC_B,            ___,
        ___,      LGUI_T(KC_R), LALT_T(KC_S), LCTL_T(KC_N), LSFT_T(KC_T),             KC_P,                                              KC_Y,     LSFT_T(KC_I), LCTL_T(KC_E), LALT_T(KC_A),    LGUI_T(KC_H),    KC_SCLN,
        ___,      KC_J,         KC_C,         KC_L,         LT(_FUNCTIONKEYS, KC_D),  KC_MINS, KC_LBRC, KC_LSFT,       KC_LSFT, KC_RBRC, KC_SLSH,  KC_W,         KC_LPRN,      KC_RPRN,         KC_EQL,          U_SVE,
                                                        ___, ___, ___, COMM_COMMAND, DOT_NUMPAD,                  ___, ___, ___, ___, DF(_QWERTY)
    ),
    #elif defined (HANDSDOWN_ROLL)
    [_HANDSDOWN] = LAYOUT(
        ___, KC_J, KC_G, KC_M,                    KC_P, KC_V,                                                                           HDR_QUES, HDR_MINS, HDR_SLSH,   HDR_DQT, HDR_QUOT, ___,
        ___, KC_R, KC_S, KC_N,                    KC_D, KC_K,                                                                           HDR_COMM, KC_A,     KC_E,       KC_I,    KC_H,     KC_SCLN,
        ___, KC_X, KC_F, LT(_FUNCTIONKEYS, KC_L), KC_C, KC_B, KC_LBRC,      KC_LSFT,                   KC_LSFT,   KC_RBRC,              HDR_DOT,  KC_U,     KC_O,       KC_W,    KC_Y,     U_SVE,
                         ___,                     ___,  ___,  SHIFT_NUMPAD, LT(_COMMANDS, KC_T),       ALT_MEDIA, LT(_SYMBOLS, KC_SPC), KC_ENT,   KC_LGUI,  DF(_QWERTY)
    ),
    #else // HANDSDOWN
    [_HANDSDOWN] = LAYOUT(
        ___,      KC_Q,         KC_C,         KC_H,         KC_P,                     KC_V,                                         KC_K,  KC_Y,         KC_O,         KC_J,            KC_SLSH,         ___,
        ___,      LGUI_T(KC_R), LALT_T(KC_S), LCTL_T(KC_N), LSFT_T(KC_T),             KC_G,                                         KC_W,  LSFT_T(KC_U), LCTL_T(KC_E), LALT_T(KC_I),    LGUI_T(KC_A),    KC_SCLN,
        ___,      KC_X,         KC_M,         KC_L,         LT(_FUNCTIONKEYS, KC_D),  KC_B, KC_LBRC, KC_LSFT,     KC_LSFT, KC_RBRC, KC_Z,  KC_F,         KC_QUOT,      KC_COMM,         KC_DOT,          U_SVE,
                                                                       ___, ___, ___, ___, ___,                    ___, ___, ___, ___, DF(_QWERTY)
    ),
    #endif
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    [_COMMANDS] = LAYOUT(
        RESET,  XXX,  XXX,  XXX,  XXX,  XXX,                            U_RDO,    U_UND,    U_CUT,    U_CPY,    U_PST,    XXX,
        XXX,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  XXX,                            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  XXX,      XXX,
        XXX,  XXX,  XXX,  XXX,  XXX,  XXX, XXX, XXX,   XXX,     XXX,  KC_INS,   KC_HOME,  KC_PGUP,  KC_PGDN,  KC_END,   XXX,
                          RGB_M_SW, XXX,  XXX,  XXX,  XXX,  KC_BSPC,  XXX,  SGUI(KC_4),  XXX, XXX
    ),
    [_FUNCTIONKEYS] = LAYOUT(
        XXX,  XXX,  XXX,  XXX,  XXX,  XXX,                         XXX,  KC_F9,  KC_F10,  KC_F11,  KC_F12,  XXX,
        XXX,  XXX,  XXX,  XXX,  XXX,  XXX,                         XXX,  KC_F5,  KC_F6,   KC_F7,   KC_F8,   XXX,
        XXX,  XXX,  XXX,  XXX,  XXX,  XXX, XXX, XXX,    XXX, XXX,  XXX,  KC_F1,  KC_F2,   KC_F3,   KC_F4,   XXX,
                          XXX,  XXX,  XXX, XXX, XXX,    XXX, XXX,  XXX,  XXX, XXX
    ),
    [_NUMPAD] = LAYOUT(
        XXX,  XXX,  XXX,  XXX,  XXX,  XXX,                                XXX,  KC_7,  KC_8,  KC_9,  XXX,  XXX,
        XXX,  XXX,  XXX,  XXX,  XXX,  XXX,                                XXX,  KC_4,  KC_5,  KC_6,  XXX,  XXX,
        XXX,  XXX,  XXX,  XXX,  XXX,  XXX, XXX, XXX,     XXX,      XXX,   XXX,  KC_1,  KC_2,  KC_3,  XXX,  XXX,
                          XXX,  XXX,  XXX, XXX, XXX,     KC_BSPC,  KC_0,  KC_DOT,  XXX, XXX
    ),
    [_MEDIA] = LAYOUT(
        XXX,  XXX,  XXX,  XXX,      XXX,      XXX,                                    XXX,  XXX,  XXX,  XXX,  XXX,  XXX,
        XXX,  XXX,  XXX,  KC_VOLU,  KC_MPLY,  KC_MSTP,                                XXX,  XXX,  XXX,  XXX,  XXX,  XXX,
        XXX,  XXX,  XXX,  KC_VOLD,  KC_MPRV,  KC_MNXT, XXX,      XXX,      XXX,  XXX, XXX,  XXX,  XXX,  XXX,  XXX,  XXX,
                                      XXX, XXX,  XXX,  KC_MUTE,  XXX,      XXX,  XXX, XXX,  XXX, XXX
    ),
    [_SYMBOLS] = LAYOUT(
        XXX,      XXX,      KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,                              XXX,  XXX,  XXX,  XXX,  XXX,  XXX,
        KC_LBRC,  KC_RBRC,  KC_DLR,   KC_PERC,  KC_CIRC,  XXX,                                  XXX,  KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,  XXX,
        XXX,      XXX,      KC_EXLM,  KC_AT,    KC_HASH,  XXX,  KC_LBRC, KC_RBRC,    XXX, XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,
                                      XXX,      XXX,      XXX,  KC_LCBR, KC_RCBR,    XXX, XXX,  XXX,  XXX,  XXX
    ),
};


#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_UP);
        } else {
            tap_code(KC_DOWN);
        }
    }
    else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_UP);
        } else {
            tap_code(KC_DOWN);
        }
    }
    return true;
}
#endif


#ifdef HAPTIC_ENABLE
void play_haptic_pattern(uint16_t waveform) {
    haptic_enable();
    DRV_pulse(waveform);
    haptic_disable();
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _COMMANDS:
            play_haptic_pattern(transition_hum);
            break;
        case _NUMPAD:
            play_haptic_pattern(pulsing_strong);
            break;
        case _SYMBOLS:
            break;
        case _MEDIA:
            play_haptic_pattern(pulsing_sharp);
            break;
        default:
            break;
    }
    return state;
}
#endif
