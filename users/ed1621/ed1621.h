#pragma once
#ifndef USERSPACE
    #define USERSPACE
#endif

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "process_combo.h"

#define MASTER_LEFT
#define TAP_CODE_DELAY 5

#ifdef TAPPING_TOGGLE
    #undef TAPPING_TOGGLE
#endif
#define TAPPING_TOGGLE 2

#ifdef TAPPING_TERM
    #undef TAPPING_TERM
#endif
#define TAPPING_TERM 180

#define TAP_HOLD_CAPS_DELAY 0
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define DEBOUNCE 5

enum userspace_layers {
    _QWERTY = 0,
    _HANDSDOWN,
    _COMMANDS,
    _FUNCTIONKEYS,
    _NUMPAD,
    _MEDIA,
    _SYMBOLS,
    _GAMING,
};


uint8_t combo_on = 0;
bool combo_triggered = false;
void matrix_scan_user_process_combo(void);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

#ifdef COMBO_ENABLE
    #include "ed1621_COMBO.h"
#endif
#ifdef TAP_DANCE_ENABLE
    #include "ed1621_TAPDANCES.h"
#endif
#ifdef HAPTIC_ENABLE
    #include "haptic.h"
#endif
#ifdef OLED_DRIVER_ENABLE
    #include "ed1621_OLED.h"
#endif
#include "ed1621_KEYCODES.h"

#ifdef TAP_DANCE_ENABLE
    #define COMM_COMMAND TD(COMM_LAYR)
    #define DOT_NUMPAD TD(DOT_LAYR)
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


