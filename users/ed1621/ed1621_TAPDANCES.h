#pragma once
#include "ed1621.h"

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

enum {
    COMM_LAYR = 0,
    DOT_LAYR,
    GR_ESC
};

typedef struct {
    uint16_t layer;
    uint8_t code;
} tap_layer_toggle_t;

td_state_t cur_dance(qk_tap_dance_state_t *state);
void master_finished(qk_tap_dance_state_t *state, void *user_data);
void master_reset(qk_tap_dance_state_t *state, void *user_data);
