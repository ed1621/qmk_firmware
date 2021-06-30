#pragma once
#include "ed1621.h"

#define PLACEHOLDER_SAFE_RANGE SAFE_RANGE

enum userspace_keycodes {
    LAMBDA = PLACEHOLDER_SAFE_RANGE,
    HDR_QUES,
    HDR_MINS,
    HDR_SLSH,
    HDR_DQT,
    HDR_QUOT,
    HDR_COMM,
    HDR_DOT,
};

#define XXX KC_NO
#define ___ KC_TRNS
#define U_RDO SCMD(KC_Z) //again
#define U_PST LCMD(KC_V) //paste
#define U_CPY LCMD(KC_C) //copy
#define U_CUT LCMD(KC_X) //cut
#define U_UND LCMD(KC_Z) //undo
#define U_SVE LCMD(KC_S) //save
#define U_TMX LCTL(KC_SPC) //tmux prefix
