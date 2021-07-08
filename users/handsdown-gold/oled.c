#include "handsdown-gold.h"

void render_default_layer_state(void) {
    oled_write_P(PSTR(OLED_RENDER_LAYOUT_NAME), false);
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR(OLED_RENDER_LAYOUT_QWERTY), false);
            break;
        case _HANDSDOWN:
            oled_write_P(PSTR(OLED_RENDER_LAYOUT_HANDSDOWN), false);
            break;
    }
#ifdef OLED_DISPLAY_128X64
    oled_advance_page(true);
#endif
}

static void render_layer_state(void) {
    oled_write_P(PSTR(OLED_RENDER_LAYER_NAME), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
        case _HANDSDOWN:
            oled_write_P(PSTR("Base"), false);
            break;
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
        case _GAMES:
            oled_write_P(PSTR(OLED_RENDER_LAYER_GAMING), false);
        break;
        default:
            oled_write_P(PSTR("N/A"), false);
    }
}

void render_keylock_status(void) {
    led_t led_state = host_keyboard_led_state();
    oled_write_P(PSTR("\n\n"), false);
    if (led_state.num_lock) {
        oled_write_P(PSTR(""), false);
        oled_write_P(PSTR(OLED_RENDER_LOCK_NAME), false);
        oled_write_P(PSTR(OLED_RENDER_LOCK_NUML), false);
    }
    else if (led_state.caps_lock) {
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

__attribute__((weak)) void oled_driver_render_logo(void) {
    // clang-format off
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
    // clang-format on
    oled_write_P(qmk_logo, false);
}
void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_default_layer_state();
        render_layer_state();
        render_keylock_status();
    } else {
        oled_driver_render_logo();
    }
}
