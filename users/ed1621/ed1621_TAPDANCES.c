#include "ed1621_TAPDANCES.h"

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


void master_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_layer_toggle_t *tap_data = (tap_layer_toggle_t *)user_data;

    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(tap_data->code);
            break;
        case TD_SINGLE_HOLD:
            layer_on(tap_data->layer);
            break;
        case TD_DOUBLE_TAP:
            tap_code(tap_data->code);
            tap_code(tap_data->code);
            break;
        case TD_TRIPLE_TAP:
            tap_code(tap_data->code);
            tap_code(tap_data->code);
            tap_code(tap_data->code);
            break;
        default:
            break;
    }
}

void master_reset(qk_tap_dance_state_t *state, void *user_data) {
    tap_layer_toggle_t *tap_data = (tap_layer_toggle_t *)user_data;

    if (ql_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(tap_data->layer);
    }
    ql_tap_state.state = TD_NONE;
}

#define ACTION_TAP_DANCE_LAYER_TAP(layer, code) { \
        .fn = {NULL, (void *)master_finished, (void *)master_reset}, \
        .user_data = (void *)&((tap_layer_toggle_t) {layer, code}), \
        .custom_tapping_term = TAPPING_TERM, \
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [GR_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_ESC),
    [COMM_LAYR] = ACTION_TAP_DANCE_LAYER_TAP(_COMMANDS, KC_COMM),
    [DOT_LAYR] = ACTION_TAP_DANCE_LAYER_TAP(_NUMPAD, KC_DOT)
};
