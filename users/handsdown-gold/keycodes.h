#pragma once
#include "handsdown-gold.h"

#define PLACEHOLDER_SAFE_RANGE SAFE_RANGE

enum userspace_keycodes {
    LAMBDA = PLACEHOLDER_SAFE_RANGE,
    MAC_LOCK,
    HG_QUES,
    HG_MINS,
    HG_SLSH,
    HG_COMM,
    HG_DOT,
    HG_DQT,
    HG_QUOT,
    U_QUES,
    U_EXLM,
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
