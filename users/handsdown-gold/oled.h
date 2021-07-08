#pragma once

#include "quantum.h"
#include "oled_driver.h"

void oled_driver_render_logo(void);
bool process_record_user_oled(uint16_t keycode, keyrecord_t *record);
extern uint32_t oled_timer;

#define OLED_RENDER_LAYOUT_NAME    "Layout: "
#define OLED_RENDER_LAYOUT_QWERTY  "Qwerty\n"
#define OLED_RENDER_LAYOUT_HANDSDOWN "Hndwn GOLD\n"

#define OLED_RENDER_LAYER_NAME   "Layer: "
#define OLED_RENDER_LAYER_COMMANDS   "Commands"
#define OLED_RENDER_LAYER_FKEYS   "Function Keys"
#define OLED_RENDER_LAYER_NUMPAD   "Numpad"
#define OLED_RENDER_LAYER_MEDIA   "Media"
#define OLED_RENDER_LAYER_SYMBOLS   "Symbols"
#define OLED_RENDER_LAYER_GAMING   "Gaming"


#define OLED_RENDER_LOCK_NAME "Lock: "
#define OLED_RENDER_LOCK_NUML "NUML"
#define OLED_RENDER_LOCK_CAPS "CAPS"