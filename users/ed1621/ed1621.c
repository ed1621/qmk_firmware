//
// Created by Ed Martinez on 6/6/21.
//
#include QMK_KEYBOARD_H

#include <stdio.h>
#include "process_combo.h"
#include "ed1621.h"

typedef enum {
    LAMBDA = SAFE_RANGE,
} custom_keycodes;

typedef union {
    uint32_t raw;
    struct {
        bool osIsWindows;
    };
} user_config_t;

user_config_t user_config;

static uint32_t keyhold_timer = 0;

#ifdef COMBO_ENABLE
    #include "ed1621_COMBO.c"
#endif

#include "ed1621_KEYCODES.c"
#include "ed1621_MATRIX.c"

void keyboard_post_init_user(void) {
    // swap ctrl-cmd-alt keys as appropriate for platform
    // Read the user config from EEPROM
    user_config.raw = eeconfig_read_user();

#ifdef OLED_DRIVER_ENABLE
    oled_clear();
        if (user_config.osIsWindows) {
            oled_set_cursor(oled_max_chars() - 3, 0);
            oled_write_P(PSTR("WIN"), false);
        } else {
            oled_set_cursor(oled_max_chars() - 3, 0);
            oled_write_P(PSTR("MAC"), false);
        }
    oled_render();
    oled_on();
#endif
}
