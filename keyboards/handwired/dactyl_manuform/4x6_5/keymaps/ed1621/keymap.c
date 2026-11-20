#include QMK_KEYBOARD_H

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

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
    [_QWERTY] = LAYOUT_wrapper(
        KC_GRV, _________________QWERTY_L1_________________,             _________________QWERTY_R1_________________, KC_EQL,
        KC_TAB, _________________QWERTY_L2_________________,             _________________QWERTY_R2_________________, KC_QUOT,
        LAMBDA, _________________QWERTY_L3_________________,             _________________QWERTY_R3_________________, KC_BSLS,
                                        XXX, KC_CAPS,                                  XXX, XXX,
                                KC_ESC,  KC_DEL,   MO(_FKEYS),                        DF(_GRAPHITE),    XXX,  KC_ENT,
                        SFT_T(KC_BSPC), LT(_NUMPAD, KC_MINS),            MO(_SYMBOLS),  SFT_T(KC_SPC)
    ),

    [_COMMANDS] = LAYOUT_wrapper(
        XXX, _________________CMMNDS_L1_________________,             _________________CMMNDS_R1_________________, XXX,
        XXX, _________________CMMNDS_L2_________________,             _________________CMMNDS_R2_________________, XXX,
        XXX, _________________CMMNDS_L3_________________,             _________________CMMNDS_R3_________________, XXX,
                          XXX, KC_PSCR,                                                 XXX, XXX,
                                  XXX, XXX,  XXX,             XXX, XXX, XXX,
                                            XXX, XXX,             XXX, XXX
    ),

    [_NUMPAD] = LAYOUT_wrapper(
        XXX, QK_BOOT, XXX, XXX, XXX, XXX,         _________________NUMPD_R1__________________,XXX,
        XXX, XXX, XXX, XXX, XXX, XXX,             _________________NUMPD_R2__________________,XXX,
        XXX, XXX, XXX, XXX, XXX, XXX,             _________________NUMPD_R3__________________,XXX,
                          XXX, XXX,                                                 XXX,  XXX,
                                  XXX, XXX,  XXX,             XXX, XXX, XXX,
                                            XXX, XXX,             XXX, KC_0
    ),

    [_SYMBOLS] = LAYOUT_wrapper(
        XXX, _________________SYMBLS_L1_________________,             _________________EMPTY_ROW________________, XXX,
        XXX, _________________SYMBLS_L2_________________,             XXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXX, 
        XXX, _________________SYMBLS_L3_________________,             _________________EMPTY_ROW________________, XXX,
                          XXX, XXX,                                                 XXX, XXX,
                                  XXX, XXX,  XXX,             XXX, XXX, XXX,
                                            LPARENS, RPARENS,             XXX, XXX
    ),

    [_FKEYS] = LAYOUT_wrapper(
        XXX, _________________SYMBLS_L1_________________,             _________________FKEYS_R1__________________, XXX,
        XXX, _________________SYMBLS_L2_________________,             _________________FKEYS_R2__________________, XXX,
        XXX, _________________SYMBLS_L3_________________,             _________________FKEYS_R3_________________, XXX,
                          XXX, XXX,                                                 XXX, XXX,
                                  XXX, XXX,  XXX,             XXX, XXX, XXX,
                                            XXX, XXX,             XXX, XXX
    ),

    [_GRAPHITE] = LAYOUT(
        KC_GRV,  KC_B,         KC_L,         KC_D,         KC_W,               KC_Z,               XXX,   KC_F,     KC_O,         KC_U,         KC_J,            KC_EQL,
        KC_TAB,  LGUI_T(KC_N), LALT_T(KC_R), LCTL_T(KC_T), LT(_COMMANDS,KC_S), KC_G,               KC_Y,   KC_H, LCTL_T(KC_A), LALT_T(KC_E), LGUI_T(KC_I), KC_QUOT,
        LAMBDA,  KC_Q,         KC_X,         KC_M,         KC_C,               KC_V,               KC_K,   KC_P,  KC_DOT,      KC_COMM,       KC_SLSH,         KC_BSLS,
                                                                 XXX, XXX,                                  XXX, XXX,
                                                            KC_ESC,  KC_DEL,   MO(_FKEYS),                        DF(_QWERTY),    XXX,  KC_ENT,
                                                            SFT_T(KC_BSPC), MO(_NUMPAD),            MO(_SYMBOLS),  SFT_T(KC_SPC)
    )
};
