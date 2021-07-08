#pragma once
#include "ed1621.h"

// used if entire row on hand is empty
#define _________________EMPTY_ROW________________       XXX,  XXX,  XXX,  XXX,  XXX

// QWERTY Layer
#define _________________QWERTY_L1_________________       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________       LGUI_T(KC_A),    LALT_T(KC_S),    LCTL_T(KC_D),    LSFT_T(KC_F),    KC_G
#define _________________QWERTY_L3_________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________       KC_H,    LSFT_T(KC_J),    LCTL_T(KC_K),    LALT_T(KC_L),    LGUI_T(KC_SCLN)
#define _________________QWERTY_R3_________________       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

// COMMANDS Layer
#define _________________CMMNDS_L1_________________       RESET,    XXX,      XXX,      XXX,      XXX
#define _________________CMMNDS_L2_________________       KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  XXX
#define _________________CMMNDS_L3_________________       XXX,      XXX,      XXX,      XXX,      XXX

#define _________________CMMNDS_R1_________________       U_RDO,    U_UND,    U_CUT,    U_CPY,     U_PST
#define _________________CMMNDS_R2_________________       KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT,  XXX
#define _________________CMMNDS_R3_________________       KC_INS,   KC_HOME,  KC_PGUP,  KC_PGDN,   KC_END


// FUNCTIONKEYS Layer
#define _________________FKEYS_R1__________________       XXX,  KC_F9,  KC_F10,  KC_F11,  KC_F12
#define _________________FKEYS_R2__________________       XXX,  KC_F9,  KC_F10,  KC_F11,  KC_F12
#define _________________FKEYS_R3__________________       XXX,  KC_F5,  KC_F6,   KC_F7,   KC_F8

// NUMPAD Layer
#define _________________NUMPD_R1__________________       XXX,  KC_7,   KC_8,    KC_9,   XXX
#define _________________NUMPD_R2__________________       XXX,  KC_4,   KC_5,    KC_6,   XXX
#define _________________NUMPD_R3__________________       XXX,  KC_1,   KC_2,    KC_3,   XXX


// MEDIA Layer
#define _________________MEDIA_L2__________________       XXX,  XXX,  KC_VOLU,  KC_MPLY,  KC_MSTP
#define _________________MEDIA_L3__________________       XXX,  XXX,  KC_VOLD,  KC_MPRV,  KC_MNXT

// SYMBOLS Layer
#define _________________SYMBLS_L1_________________       XXX,  KC_AMPR,  KC_ASTR,  KC_LPRN, KC_RPRN
#define _________________SYMBLS_L2_________________       XXX,  KC_DLR,   KC_PERC,  KC_CIRC, XXX
#define _________________SYMBLS_L3_________________       XXX,  KC_EXLM,  KC_AT,    KC_HASH, XXX

#define _________________SYMBLS_R2_________________       XXX,  KC_LSFT,  KC_LCTL,  KC_LALT, KC_LGUI
