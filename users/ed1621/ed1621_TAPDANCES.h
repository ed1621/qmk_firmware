#pragma once
#include "ed1621.h"


enum {
    COMM_LAYR = 0,
    DOT_LAYR,
    SFT_LAYR,
    ALT_LAYR,
    GR_ESC
};

void master_finished(qk_tap_dance_state_t *state, void *user_data);
void master_reset(qk_tap_dance_state_t *state, void *user_data);
