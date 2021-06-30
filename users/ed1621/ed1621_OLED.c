#include "ed1621.h"

uint32_t oled_timer = 0;

bool process_record_user_oled(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        oled_timer = timer_read32();
    }
    return true;
}

void render_default_layer_state(void) {
    oled_write_P(PSTR(OLED_RENDER_LAYOUT_NAME), false);
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR(OLED_RENDER_LAYOUT_QWERTY), false);
            break;
        #if defined HANDSDOWN_ELAN
            case _HANDSDOWN:
                oled_write_P(PSTR(OLED_RENDER_LAYOUT_HANDSDOWN_ELAN), false);
                break;
        #elif defined HANDSDOWN_ALT_TX
            case _HANDSDOWN:
                oled_write_P(PSTR(OLED_RENDER_LAYOUT_HANDSDOWN_ALT_TX), false);
                break;
        #else
            case _HANDSDOWN:
                oled_write_P(PSTR(OLED_RENDER_LAYOUT_HANDSDOWN), false);
                break;
        #endif
    }
    #ifdef OLED_DISPLAY_128X64
        oled_advance_page(true);
    #endif
}

void render_layer_state(void) {
    oled_write_P(PSTR(OLED_RENDER_LAYER_NAME), false);
#ifdef OLED_DISPLAY_128X64
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR(OLED_RENDER_LAYER_COMMANDS), layer_state_is(_COMMANDS));
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR(OLED_RENDER_LAYER_FKEYS), layer_state_is(_FUNCTIONKEYS));
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR(OLED_RENDER_LAYER_NUMPAD), layer_state_is(_NUMPAD));
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR(OLED_RENDER_LAYER_MEDIA), layer_state_is(_MEDIA));
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR(OLED_RENDER_LAYER_SYMBOLS), layer_state_is(_SYMBOLS));
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR(OLED_RENDER_LAYER_GAMING), layer_state_is(_GAMING));
#else
    oled_write_P(PSTR(OLED_RENDER_LAYER_COMMANDS), layer_state_is(_COMMANDS));
    oled_write_P(PSTR(OLED_RENDER_LAYER_FKEYS), layer_state_is(_FUNCTIONKEYS));
    oled_write_P(PSTR(OLED_RENDER_LAYER_NUMPAD), layer_state_is(_NUMPAD));
    oled_write_P(PSTR(OLED_RENDER_LAYER_MEDIA), layer_state_is(_MEDIA));
    oled_write_P(PSTR(OLED_RENDER_LAYER_SYMBOLS), layer_state_is(_SYMBOLS));
    oled_write_P(PSTR(OLED_RENDER_LAYER_GAMING), layer_state_is(_GAMING));
#endif
}

void render_keylock_status(uint8_t led_usb_state) {
    oled_write_P(PSTR(OLED_RENDER_LOCK_NAME), false);
    oled_write_P(PSTR(OLED_RENDER_LOCK_NUML), led_usb_state & (1 << USB_LED_NUM_LOCK));
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR(OLED_RENDER_LOCK_CAPS), led_usb_state & (1 << USB_LED_CAPS_LOCK));
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

void render_status_secondary(void) {
    oled_driver_render_logo();
}

void render_status_main(void) {
    render_default_layer_state();
    render_layer_state();
    render_keylock_status(host_keyboard_leds());
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        if (timer_elapsed32(oled_timer) > 30000) {
            oled_off();
            return;
        } else {
            oled_on();
        }
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_status_secondary();
    }
}
