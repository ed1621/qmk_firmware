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
#include "lily58.h"
#include "artsey.h"
#include "keymap_combo.h"
#include "artsey.c"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_A_BASE] = LAYOUT_artsey_base(A_BASE_A,A_BASE_R,A_BASE_T,A_BASE_S,
                       A_BASE_E,A_BASE_Y,A_BASE_I,A_BASE_O,
                       KC_SPC, KC_ENT),

    [_A_NUM] = LAYOUT_artsey_base(A_NUM_A,A_NUM_R,A_NUM_T,A_NUM_S,
                      A_NUM_E,A_NUM_Y,A_NUM_I,A_NUM_O,
                       KC_SPC, KC_ENT),

    [_A_NAV] = LAYOUT_artsey_base(A_NAV_A,A_NAV_R,A_NAV_T,A_NAV_S,
                      A_NAV_E,A_NAV_Y,A_NAV_I,A_NAV_O,
                       KC_SPC, KC_ENT),

    [_A_SYM] = LAYOUT_artsey_base(A_SYM_A,A_SYM_R,A_SYM_T,A_SYM_S,
                      A_SYM_E,A_SYM_Y,A_SYM_I,A_SYM_O,
                       KC_SPC, KC_ENT),

    [_A_BRAC] = LAYOUT_artsey_base(A_BRAC_A,A_BRAC_R,A_BRAC_T,A_BRAC_S,
                       A_BRAC_E,A_BRAC_Y,A_BRAC_I,A_BRAC_O,
                       KC_SPC, KC_ENT),

    [_A_MOU] = LAYOUT_artsey(A_MOU_A,A_MOU_R,A_MOU_T,A_MOU_S,
                      A_MOU_E,A_MOU_Y,A_MOU_I,A_MOU_O),

    [_A_CUSTOM] = LAYOUT_artsey(A_CUSTOM_A,A_CUSTOM_R,A_CUSTOM_T,A_CUSTOM_S,
                         A_CUSTOM_E,A_CUSTOM_Y,A_CUSTOM_I,A_CUSTOM_O)
};


#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_270;
}

static void render_status(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer\n"), false);
    switch (get_highest_layer(layer_state)) {
        case _A_BASE:
            oled_write_P(PSTR("BASE\n"), false);
            break;
        case _A_NUM:
            oled_write_P(PSTR("NUM\n"), false);
            break;
        case _A_NAV:
            oled_write_P(PSTR("NAV\n"), false);
            break;
        case _A_SYM:
            oled_write_P(PSTR("SYM\n"), false);
            break;
        case _A_BRAC:
            oled_write_P(PSTR("BRAC\n"), false);
            break;
        case _A_MOU:
            oled_write_P(PSTR("MOU\n"), false);
            break;
        case _A_CUSTOM:
            oled_write_P(PSTR("MEDIA\n"), false);
            break;
    }

    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("CAPS ") : PSTR("     "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    }
    else {}
}
#endif