#include QMK_KEYBOARD_H
#include "users/ed1621/config.h"

#ifdef HAPTIC_ENABLE
    #include "haptic.h"
    extern haptic_config_t haptic_config;
    void haptic_disable(void);
    void haptic_enable(void);
    void haptic_set_feedback(uint8_t feedback);
#endif

#define XXX KC_NO
#define ___ KC_TRNS
#define U_RDO SCMD(KC_Z) //again
#define U_PST LCMD(KC_V) //paste
#define U_CPY LCMD(KC_C) //copy
#define U_CUT LCMD(KC_X) //cut
#define U_UND LCMD(KC_Z) //undo
#define U_SVE LCMD(KC_S) //save
#define U_TMX LCTL(KC_SPC) //tmux prefix

typedef enum {
    LAMBDA = SAFE_RANGE,
} custom_keycodes;

typedef enum {
    _BASE,
    _HANDSDOWN,
    _COMMANDS,
    _FUNCTIONKEYS,
    _NUMPAD,
    _MEDIA,
    _SYMBOLS
} layers;

enum {
    COMM_LAYR,
    DOT_LAYR,
    GR_ESC
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_TRIPLE_TAP,
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

static td_tap_t ql_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if(!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }
    else if (state->count == 2) {
        if(!state->pressed) return TD_DOUBLE_TAP;
        else return TD_UNKNOWN;
    }
    else if (state->count == 3) {
        if(!state->pressed) return TD_TRIPLE_TAP;
        else return TD_UNKNOWN;
    }
    else return TD_UNKNOWN;
}

void ql_finished(qk_tap_dance_state_t *state, void *user_data, uint16_t layer, uint8_t code) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(code);
            break;
        case TD_SINGLE_HOLD:
            layer_on(layer);
            break;
        case TD_DOUBLE_TAP:
            tap_code(code);
            tap_code(code);
            break;
        case TD_TRIPLE_TAP:
            tap_code(code);
            tap_code(code);
            tap_code(code);
            break;
        default:
            break;
    }
}

void ql_reset(qk_tap_dance_state_t *state, void *user_data, uint16_t layer) {
    if (ql_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(layer);
    }
    ql_tap_state.state = TD_NONE;
}

void cl_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_finished(state, user_data, _COMMANDS, KC_COMM);
}

void cl_reset(qk_tap_dance_state_t *state, void *user_data) {
    ql_reset(state, user_data, _COMMANDS);
}

void dl_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_finished(state, user_data, _NUMPAD, KC_DOT);
}

void dl_reset(qk_tap_dance_state_t *state, void *user_data) {
    ql_reset(state, user_data, _NUMPAD);
}


qk_tap_dance_action_t tap_dance_actions[] = {
    [COMM_LAYR] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, cl_finished, cl_reset, TAPPING_TERM),
    [DOT_LAYR] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dl_finished, dl_reset, TAPPING_TERM),
    [GR_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_ESC)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        TD(GR_ESC),  KC_Q,           KC_W,           KC_E,          KC_R,                     KC_T,                                                                          KC_Y,    KC_U,         KC_I,         KC_O,            KC_P,            KC_EQL,
        KC_TAB,      LGUI_T(KC_A),   LALT_T(KC_S),   LCTL_T(KC_D),  LSFT_T(KC_F),             KC_G,                                                                          KC_H,    LSFT_T(KC_J), LCTL_T(KC_K), LALT_T(KC_L),    LGUI_T(KC_SCLN), KC_QUOT,
        LAMBDA,      KC_Z,           KC_X,           KC_C,          LT(_FUNCTIONKEYS, KC_V),  KC_B,  KC_LSFT,                KC_LSFT,           KC_LSFT,            KC_LSFT, KC_N,    KC_M,         KC_COMM,      KC_DOT,          KC_SLSH,         KC_BSLS,
                                                                                U_TMX, KC_CAPS, XXX, MO(_COMMANDS), LT(_NUMPAD, KC_MINS),       LT(_MEDIA, KC_SPC), LT(_SYMBOLS, KC_ENT),   XXX, XXX,  TT(_HANDSDOWN)
    ),
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//*****************************************************//
//                                                     //
//                   HANDSDOWN LAYOUTS                 //
//  https://sites.google.com/alanreiser.com/handsdown  //
//                                                     //
//*****************************************************//

    #if defined (HANDSDOWN_NORMAL)
    [_HANDSDOWN] = LAYOUT(
        ___,      KC_Q,         KC_C,         KC_H,         KC_P,                     KC_V,                                         KC_K,  KC_Y,         KC_O,         KC_J,            KC_SLSH,         ___,
        ___,      LGUI_T(KC_R), LALT_T(KC_S), LCTL_T(KC_N), LSFT_T(KC_T),             KC_G,                                         KC_W,  LSFT_T(KC_U), LCTL_T(KC_E), LALT_T(KC_I),    LGUI_T(KC_A),    KC_SCLN,
        ___,      KC_X,         KC_M,         KC_L,         LT(_FUNCTIONKEYS, KC_D),  KC_B, KC_LBRC, KC_LSFT,     KC_LSFT, KC_RBRC, KC_Z,  KC_F,         KC_QUOT,      KC_COMM,         KC_DOT,          U_SVE,
                                                                       ___, ___, ___, ___, ___,                    ___, ___, ___, ___, ___
    ),
    #elif defined (HANDSDOWN_ELAN)
    [_HANDSDOWN] = LAYOUT(
        ___,      KC_V,         KC_G,         KC_M,         KC_F,                     KC_K,                                              KC_QUOT,  KC_U,         KC_O,         KC_X,            KC_B,            ___,
        ___,      LGUI_T(KC_R), LALT_T(KC_S), LCTL_T(KC_N), LSFT_T(KC_T),             KC_P,                                              KC_Y,     LSFT_T(KC_I), LCTL_T(KC_E), LALT_T(KC_A),    LGUI_T(KC_H),    KC_SCLN,
        ___,      KC_J,         KC_C,         KC_L,         LT(_FUNCTIONKEYS, KC_D),  KC_MINS, KC_LBRC, KC_LSFT,       KC_LSFT, KC_RBRC, KC_SLSH,  KC_W,         KC_LPRN,      KC_RPRN,         KC_EQL,          U_SVE,
                                                        ___, ___, ___, TD(COMM_LAYR), TD(DOT_LAYR),                  ___, ___, ___, ___, ___
    ),
    #else // HANDSDOWN_ALT
    [_HANDSDOWN] = LAYOUT(
        ___,      KC_W,         KC_C,         KC_H,         KC_F,                     KC_V,                          KC_SLSH,  KC_Y,         KC_U,         KC_J,            KC_Q,            ___,
        ___,      LGUI_T(KC_R), LALT_T(KC_S), LCTL_T(KC_N), LSFT_T(KC_T),             KC_G,                          KC_K,     LSFT_T(KC_I), LCTL_T(KC_E), LALT_T(KC_O),    LGUI_T(KC_A),    KC_SCLN,
        ___,      KC_X,         KC_M,         KC_L,         LT(_FUNCTIONKEYS, KC_D),  KC_B, KC_LBRC,        KC_RBRC, KC_Z,     KC_P,         KC_QUOT,      KC_COMM,         KC_DOT,          U_SVE,
                                                                           ___, ___, ___, ___, ___,                    ___, ___, ___, ___, ___
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

static void render_status(void) {
    switch (get_highest_layer(layer_state)) {
        case _HANDSDOWN:
            oled_write_P(PSTR("HNDWN\n\n"), false);
            break;
        case _BASE:
            oled_write_P(PSTR("QWRTY\n\n"), false);
            break;
        default:
            oled_write_P(PSTR("\n\n"), false);
    }

    oled_write_P(PSTR("Layer\n"), false);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
        case _HANDSDOWN:
            oled_write_P(PSTR("BASE\n"), false);
        break;
        case _COMMANDS:
            oled_write_P(PSTR("CMNDS\n"), false);
        break;
        case _FUNCTIONKEYS:
            oled_write_P(PSTR("FKEYS\n"), false);
        break;
        case _NUMPAD:
            oled_write_P(PSTR("NUMPD\n"), false);
        break;
        case _MEDIA:
            oled_write_P(PSTR("MEDIA\n"), false);
        break;
        case _SYMBOLS:
            oled_write_P(PSTR("SMBLS\n"), false);
        break;
        default:
            oled_write_P(PSTR("N/A"), false);
    }

    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("     "), false);

    if (led_state.caps_lock) {
        oled_write_P(PSTR("CAPS "), false);
        #ifdef HAPTIC_ENABLE
            haptic_enable();
            haptic_set_feedback(1);
        #endif
    }
    else {
        oled_write_P(PSTR("     "), false);
        #ifdef HAPTIC_ENABLE
            haptic_disable();
            haptic_set_feedback(0);
        #endif
    }
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    }
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
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _COMMANDS:
            #ifdef HAPTIC_ENABLE
                play_haptic_pattern(transition_hum);
            #endif
            break;
        case _NUMPAD:
            #ifdef HAPTIC_ENABLE
                play_haptic_pattern(pulsing_strong);
            #endif
            break;
        case _SYMBOLS:
            #ifdef HAPTIC_ENABLE
                play_haptic_pattern(transition_click);
            #endif
            break;
        case _MEDIA:
            #ifdef HAPTIC_ENABLE
                play_haptic_pattern(pulsing_sharp);
            #endif
            break;
        default:
            break;
    }
    return state;
}
