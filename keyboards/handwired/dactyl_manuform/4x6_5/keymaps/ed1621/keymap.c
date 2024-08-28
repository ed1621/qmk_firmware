// Copyright 2021 Andrzej Kotulski (@akotulski)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum userspace_layers {
    _QWERTY = 0,
    _COMMANDS,
    _FUNCTIONKEYS,
    _NUMPAD,
    _SYMBOLS
};

enum userspace_keycodes {
    LAMBDA = QK_USER,
    LPARENS,
    RPARENS
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case LAMBDA:
                if (keyboard_report->mods & MOD_BIT (KC_LSFT)) {
                    clear_mods();
                    SEND_STRING("->");
                }
                else {
                    SEND_STRING("=>");
                }
                break;
            case LPARENS:
                if (keyboard_report->mods & MOD_BIT (KC_LSFT)) {
                    clear_mods();
                    SEND_STRING("{");
                }
                else if (keyboard_report->mods & MOD_BIT (KC_LCTL)) {
                    clear_mods();
                    SEND_STRING("[");
                }
                else {
                    SEND_STRING("(");
                }
              case RPARENS:
                if (keyboard_report->mods & MOD_BIT (KC_LSFT)) {
                    clear_mods();
                    SEND_STRING("}");
                }
                else if (keyboard_report->mods & MOD_BIT (KC_LCTL)) {
                    clear_mods();
                    SEND_STRING("]");
                }
                else {
                    SEND_STRING(")");
                }
                break;   break;
        } // end switch (keycode)

    } // end if(record->event.pressed)
    return true;
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



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base (qwerty)
     * +-----------------------------------------+                             +-----------------------------------------+
     * | ESC  |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |      |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | TAB  |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |      |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | SHFT |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   /  |      |
     * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
     *               |  [   |   ]  |                                                         |      |      |
     *               +-------------+-------------+                             +-------------+-------------+
     *                             |      |      |                             |      |      |
     *                             |------+------|                             |------+------|
     *                             |      |      |                             |      |      |
     *                             +-------------+                             +-------------+
     *                                           +-------------+ +-------------+
     *                                           |      |      | |      |      |
     *                                           |------+------| |------+------|
     *                                           |      |      | |      |      |
     *                                           +-------------+ +-------------+
     */
    [_QWERTY] = LAYOUT(
        KC_GRV,  KC_Q,         KC_W,         KC_E,         KC_R,               KC_T,               KC_Y,   KC_U,                   KC_I,         KC_O,         KC_P,            KC_EQL,
        KC_TAB,  LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LT(_COMMANDS,KC_F), KC_G,               KC_H,   LT(_FUNCTIONKEYS,KC_J), LCTL_T(KC_K), LALT_T(KC_L), LGUI_T(KC_SCLN), KC_QUOT,
        LAMBDA,  KC_Z,         KC_X,         KC_C,         KC_V,               KC_B,               KC_N,   KC_M,                   KC_COMM,      KC_DOT,       KC_SLSH,         KC_BSLS,
                                                                 XXX, XXX,                                  XXX, XXX,
                                                            KC_ESC,  KC_DEL,   XXX,                        XXX,    XXX,  KC_ENT,
                                                            SFT_T(KC_BSPC), MO(_NUMPAD),            MO(_SYMBOLS),  SFT_T(KC_SPC)
    ),

    [_COMMANDS] = LAYOUT(
        _______, _______, _______, _______, _______, KC_LBRC,             KC_RBRC, KC_P7,   KC_P8,   KC_P9,   QK_BOOT, KC_PLUS,
        _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END , KC_LPRN,             KC_RPRN, KC_P4,   KC_P5,   KC_P6,   KC_MINS, KC_PIPE,
        _______, _______, _______, _______, _______, _______,             _______, KC_P1,   KC_P2,   KC_P3,   KC_EQL,  KC_UNDS,
                          _______, KC_PSCR,                                                 _______, KC_P0,
                                  _______, _______,  _______,             _______, _______, _______,
                                            _______, _______,             _______, _______
    ),

    [_NUMPAD] = LAYOUT(
        _______, QK_BOOT, _______, _______, _______, KC_LBRC,             KC_RBRC, _______, KC_NUM,  KC_INS,  KC_SCRL, KC_MUTE,
        _______, KC_LEFT, KC_UP  , KC_DOWN, KC_RGHT, KC_LPRN,             KC_RPRN, KC_MPRV, KC_MPLY, KC_MNXT, _______, KC_VOLU,
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, KC_VOLD,
                          _______, _______,                                                 KC_EQL,  _______,
                                  _______, _______,  _______,             _______, _______, _______,
                                            _______, _______,             _______, _______
    )
};

