/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "kyria.h"
#include "wrappers.h"


enum userspace_layers {
    _BEAKL = 0,
    _COMMANDS,
    _FUNCTIONKEYS,
    _NUMPAD,
    _MEDIA,
    _SYMBOLS,
};

enum userspace_keycodes {
    LAMBDA = SAFE_RANGE,
    MAC_LOCK
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
        switch (keycode) {
            case LAMBDA:
                if (record->event.pressed) {
                    if (keyboard_report->mods & MOD_BIT (KC_LSFT)) {
                        clear_mods();
                        SEND_STRING("->");
                    }
                    else {
                        SEND_STRING("=>");
                    }
                }
                break;
            case MAC_LOCK:
                if (record->event.pressed) {
                    tap_code16(C(G(KC_Q)));
                }
                break;
        } // end switch (keycode)
    return true;
};


#define LAYOUT_wrapper(...)            LAYOUT(__VA_ARGS__)
#define ___ KC_TRNS
#define TMX C(KC_SPC)
#define U_RDO SGUI(KC_Z) //again
#define U_PST G(KC_V) //paste
#define U_CPY G(KC_C) //copy
#define U_CUT G(KC_X) //cut
#define U_UND G(KC_Z) //undo
#define U_SVE G(KC_S) //save

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |RAIS/ESC|   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  | \   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/BS |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |LShift|LShift|  |LShift|LShift|   N  |   M  | ,  < | . >  | /  ? |  - _   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | GUI  | Del  | Enter| Space| Esc  |  | Enter| Space| Tab  | Bksp | AltGr|
 *                        |      |      | Alt  | Lower| Raise|  | Lower| Raise|      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_BEAKL] = LAYOUT(
      KC_GRV,  KC_Q,          KC_H,          KC_O,         KC_U,           KC_X,                         KC_G,    KC_C,            KC_R,          KC_F,           KC_Z,      KC_EQL,
      KC_TAB,  LGUI_T(KC_Y),  LALT_T(KC_I),  LCTL_T(KC_E), LT(_COMMANDS, KC_A),   KC_DOT,                         KC_D,    LT(_MEDIA, KC_S),    LCTL_T(KC_T),  LALT_T(KC_N),   LGUI_T(KC_B), KC_SCLN,
      LAMBDA,   KC_J,          KC_SLSH,          KC_COMM,        LT(_FUNCTIONKEYS, KC_K),           KC_QUOT, KC_NO, KC_NO,     KC_NO, TMX, KC_W,    KC_M,            KC_L,       KC_P,         KC_V,     KC_BSLS,
                                    KC_NO,          KC_CAPS,            KC_ESC,  LSFT_T(KC_BSPC), LT(_NUMPAD, KC_MINS),     LT(_SYMBOLS, KC_SPC), LSFT_T(KC_ENT), KC_NO,     KC_NO,             KC_NO
        ),
    // /*
//  * Commands
//  *
//  * ,------------------------------------------------.                                  ,------------------------------------------------.
//  * | RESET  |       |       |       |       |       |                                  |  Redo |  Undo |  Cut  |  Copy | Paste |        |
//  * |--------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+--------|
//  * |        |  GUI  |  ALT  |  CTL  |  SFT  |       |                                  | Left  |   Up  |  Down | Right |       |        |
//  * |--------+-------+-------+-------+-------+-------+---------------.  ,---------------+-------+-------+-------+-------+-------+--------|
//  * |        |       |       |       |       |       |       |       |  |       |       |  Ins  |  Home |  PgUp |  PgDn |  End  |        |
//  * `------------------------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+------------------------'
//  *                          |       |       |       |       |       |  |  Bspc |       |       |       |       |
//  *                          |       |       |       |       |       |  |       |       |       |       |       |
//  *                          `---------------------------------------'  `---------------------------------------'
//  */
    [_COMMANDS] = LAYOUT_wrapper(
        KC_NO,  _________________CMMNDS_L1_________________,                          _________________CMMNDS_R1_________________, KC_NO,
        KC_NO,  _________________CMMNDS_L2_________________,                          _________________CMMNDS_R2_________________, KC_NO,
        KC_NO,  _________________CMMNDS_L3_________________, KC_NO, KC_NO,      KC_NO,  KC_NO, _________________CMMNDS_R3_________________, KC_NO,
                                    KC_SLEP, KC_NO,  KC_NO,  KC_NO, KC_NO,      KC_NO,  TMX,  SGUI(KC_4),  KC_NO, MAC_LOCK
    ),

// /*
//  * Function Keys
//  *
//  * ,------------------------------------------------.                                  ,------------------------------------------------.
//  * |        |       |       |       |       |       |                                  |       |  F9   |  F10  |  F11  |  F12  |        |
//  * |--------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+--------|
//  * |        |       |       |       |       |       |                                  |       |  F5   |  F6   |  F7   |  F8   |        |
//  * |--------+-------+-------+-------+-------+-------+---------------.  ,---------------+-------+-------+-------+-------+-------+--------|
//  * |        |       |       |       |       |       |       |       |  |       |       |       |  F1   |  F2   |  F3   |  F4   |        |
//  * `------------------------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+------------------------'
//  *                          |       |       |       |       |       |  |       |       |       |       |       |
//  *                          |       |       |       |       |       |  |       |       |       |       |       |
//  *                          `---------------------------------------'  `---------------------------------------'
//  */
    [_FUNCTIONKEYS] = LAYOUT_wrapper(
        KC_NO,  _________________EMPTY_ROW________________,                        _________________FKEYS_R1__________________, KC_NO,
        KC_NO,  _________________EMPTY_ROW________________,                        _________________FKEYS_R2__________________, KC_NO,
        KC_NO,  _________________EMPTY_ROW________________,  KC_NO, KC_NO,  KC_NO, KC_NO,  _________________FKEYS_R3__________________, KC_NO,
                                                KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

// /*
//  * Numpad
//  *
//  * ,------------------------------------------------.                                  ,------------------------------------------------.
//  * |        |       |       |       |       |       |                                  |       |   7   |   8   |   9   |       |        |
//  * |--------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+--------|
//  * |        |       |       |       |       |       |                                  |       |   4   |   5   |   6   |       |        |
//  * |--------+-------+-------+-------+-------+-------+---------------.  ,---------------+-------+-------+-------+-------+-------+--------|
//  * |        |       |       |       |       |       |       |       |  |       |       |       |   1   |   2   |   3   |       |        |
//  * `------------------------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+------------------------'
//  *                          |       |       |       |       |       |  | Bspc  |   0   |   .   |       |       |
//  *                          |       |       |       |       |       |  |       |       |       |       |       |
//  *                          `---------------------------------------'  `---------------------------------------'
//  */
    [_NUMPAD] = LAYOUT_wrapper(
        KC_NO,  _________________EMPTY_ROW________________,                       _________________NUMPD_R1__________________, KC_NO,
        KC_NO,  _________________EMPTY_ROW________________,                       _________________NUMPD_R2__________________, KC_NO,
        KC_NO,  _________________EMPTY_ROW________________,  KC_NO, KC_NO,  KC_NO, KC_NO, _________________NUMPD_R3__________________, KC_NO,
                                            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_0, KC_BSPC, KC_NO, KC_NO, KC_NO
    ),

// /*
//  * Media
//  *
//  * ,------------------------------------------------.                                  ,------------------------------------------------.
//  * |        |       |       |       |       |       |                                  |       |       |       |       |       |        |
//  * |--------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+--------|
//  * |        |       |       | VolUp | Play  |  Stop |                                  |       |       |       |       |       |        |
//  * |--------+-------+-------+-------+-------+-------+---------------.  ,---------------+-------+-------+-------+-------+-------+--------|
//  * |        |       |       | VolDn | Prev  | Next  |       |       |  |       |       |       |       |       |       |       |        |
//  * `------------------------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+------------------------'
//  *                          |       |       |       | Mute  |       |  |       |       |       |       |       |
//  *                          |       |       |       |       |       |  |       |       |       |       |       |
//  *                          `---------------------------------------'  `---------------------------------------'
//  */
    [_MEDIA] = LAYOUT_wrapper(
        KC_NO,  _________________EMPTY_ROW________________,                      _________________EMPTY_ROW________________, KC_NO,
        KC_NO,  _________________MEDIA_L2__________________,                     _________________EMPTY_ROW________________, KC_NO,
        KC_NO,  _________________MEDIA_L2__________________, KC_NO, KC_NO, KC_NO, KC_NO, _________________EMPTY_ROW________________, KC_NO,
                                    KC_NO, KC_NO,  KC_NO,  KC_MUTE, KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

// /*
//  * Symbols
//  *
//  * ,------------------------------------------------.                                  ,------------------------------------------------.
//  * |        |       |   &   |   *   |       |       |                                  |       |       |       |       |       |        |
//  * |--------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+--------|
//  * |        |       |   $   |   %   |   ^   |       |                                  |       |  SFT  |  CTL  |  ALT  |  GUI  |        |
//  * |--------+-------+-------+-------+-------+-------+---------------.  ,---------------+-------+-------+-------+-------+-------+--------|
//  * |        |       |   !   |   @   |   #   |       |       |       |  |       |       |       |       |       |       |       |        |
//  * `------------------------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+------------------------'
//  *                          |       |   [   |  ]    |   (   |  )    |  |       |       |       |       |       |
//  *                          |       |       |       |       |       |  |       |       |       |       |       |
//  *                          `---------------------------------------'  `---------------------------------------'
//  */
    [_SYMBOLS] = LAYOUT_wrapper(
        KC_NO, _________________SYMBLS_L1_________________,                              _________________EMPTY_ROW________________,  KC_NO,
        KC_NO, _________________SYMBLS_L2_________________,                              _________________SYMBLS_R2_________________, KC_NO,
        KC_NO, _________________SYMBLS_L3_________________, KC_LBRC, KC_RBRC,          KC_NO, KC_NO, _________________EMPTY_ROW________________,  KC_NO,
                               KC_NO, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    )
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}


static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
            oled_write_P(PSTR("\n"), false);
}

#define OLED_RENDER_LAYER_NAME   "Layer: "
#define OLED_RENDER_LAYER_COMMANDS   "Commands"
#define OLED_RENDER_LAYER_FKEYS   "Function Keys"
#define OLED_RENDER_LAYER_NUMPAD   "Numpad"
#define OLED_RENDER_LAYER_MEDIA   "Media"
#define OLED_RENDER_LAYER_SYMBOLS   "Symbols"

#define OLED_RENDER_LOCK_NAME "Lock: "
#define OLED_RENDER_LOCK_CAPS "CAPS"

static void render_layer_state(void) {
    oled_write_P(PSTR(OLED_RENDER_LAYER_NAME), false);

    switch (get_highest_layer(layer_state)) {
        case _COMMANDS:
            oled_write_P(PSTR(OLED_RENDER_LAYER_COMMANDS), false);
        break;
        case _FUNCTIONKEYS:
            oled_write_P(PSTR(OLED_RENDER_LAYER_FKEYS), false);
        break;
        case _NUMPAD:
            oled_write_P(PSTR(OLED_RENDER_LAYER_NUMPAD), false);
        break;
        case _MEDIA:
            oled_write_P(PSTR(OLED_RENDER_LAYER_MEDIA), false);
        break;
        case _SYMBOLS:
            oled_write_P(PSTR(OLED_RENDER_LAYER_SYMBOLS), false);
        break;
        default:
            oled_write_P(PSTR("Base"), false);
            oled_write_P(PSTR("\nLayout: BEAKL"), false);
    }
}

void render_keylock_status(void) {
    led_t led_state = host_keyboard_led_state();
    oled_write_P(PSTR("\n\n"), false);
    if (led_state.caps_lock) {
        oled_write_P(PSTR(""), false);
        oled_write_P(PSTR(OLED_RENDER_LOCK_NAME), false);
        oled_write_P(PSTR(OLED_RENDER_LOCK_CAPS), false);
        #ifdef HAPTIC_ENABLE
            haptic_enable();
            haptic_set_feedback(1);
        #endif
    }
    else {
        oled_write_P(PSTR("            "), false);
        #ifdef HAPTIC_ENABLE
            haptic_disable();
            haptic_set_feedback(0);
        #endif
    }
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_qmk_logo();
        render_layer_state();
        render_keylock_status();
    } else {
        render_kyria_logo();
    }
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
        if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        // Page up/Page down
            if (clockwise) {
                if (keyboard_report->mods & MOD_BIT (KC_LSFT)) {
                    clear_mods();
                    tap_code(KC_UP);
                    register_code(KC_LSFT);
                }
                else if (keyboard_report->mods & MOD_BIT (KC_LCTL)) {
                    clear_mods();
                    tap_code16(C(KC_U));
                    register_code(KC_LCTL);
                }
                else if (keyboard_report->mods & MOD_BIT (KC_LALT)) {
                    clear_mods();
                    tap_code(KC_RIGHT);
                    register_code(KC_LALT);
                }
                else {
                    tap_code(KC_PGUP);
                }
            }
            else {
                if (keyboard_report->mods & MOD_BIT (KC_LSFT)) {
                    clear_mods();
                    tap_code(KC_DOWN);
                    register_code(KC_LSFT);
                }
                else if (keyboard_report->mods & MOD_BIT (KC_LCTL)) {
                    clear_mods();
                    tap_code16(C(KC_D));
                    register_code(KC_LCTL);
                }
                else if (keyboard_report->mods & MOD_BIT (KC_LALT)) {
                    clear_mods();
                    tap_code(KC_LEFT);
                    register_code(KC_LALT);
                }
                else {
                    tap_code(KC_PGDN);
                }
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
            play_haptic_pattern(transition_click);
            break;
        case _MEDIA:
            play_haptic_pattern(pulsing_sharp);
            break;
            break;
        default:
            break;
    }
    return state;
}
#endif
