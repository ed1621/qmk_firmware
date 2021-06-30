#pragma once

#include QMK_KEYBOARD_H

#define MASTER_LEFT

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


extern uint8_t combo_on;
extern bool combo_triggered;
extern uint32_t keyhold_timer;

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
    #define SHIFT_NUMPAD TD(SFT_LAYR)
    #define ALT_MEDIA TD(ALT_LAYR)
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


