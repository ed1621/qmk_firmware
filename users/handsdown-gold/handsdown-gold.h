#pragma once

#include QMK_KEYBOARD_H
#include "wrappers.h"

#define MASTER_LEFT

enum userspace_layers {
    _QWERTY = 0,
    _HANDSDOWN,
    _COMMANDS,
    _FUNCTIONKEYS,
    _NUMPAD,
    _MEDIA,
    _SYMBOLS,
    _GAMES,
};


extern uint8_t combo_on;
extern bool combo_triggered;
extern uint32_t keyhold_timer;

void matrix_scan_user_process_combo(void);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

#include "keycodes.h"

#ifdef COMBO_ENABLE
    #include "combo.h"
#endif
#ifdef TAP_DANCE_ENABLE
    #include "tapdances.h"
#endif
#ifdef HAPTIC_ENABLE
    #include "haptic.h"
#endif
#ifdef OLED_DRIVER_ENABLE
    #include "oled.h"
#endif

#ifdef TAP_DANCE_ENABLE
    #define GRAVE_ESC TD(GR_ESC)
#endif

#ifdef OLED_DRIVER_ENABLE
    #ifdef OLED_TIMEOUT
        #undef OLED_TIMEOUT
    #endif
    #define OLED_TIMEOUT 30000
#endif

#ifdef HAPTIC_ENABLE
    extern haptic_config_t haptic_config;
    void haptic_disable(void);
    void haptic_enable(void);
    void haptic_set_feedback(uint8_t feedback);
#endif


