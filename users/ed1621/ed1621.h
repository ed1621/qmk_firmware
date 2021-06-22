#pragma once

#define MASTER_LEFT

#ifndef USERSPACE
    #define USERSPACE
#endif



#ifdef OLED_DRIVER_ENABLE
    #ifdef OLED_TIMEOUT
        #undef OLED_TIMEOUT
    #endif
    #define OLED_TIMEOUT 30000
#endif




uint8_t combo_on = 0;
bool combo_triggered = false;
void matrix_scan_user_process_combo(void);
