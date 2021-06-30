#pragma once

#ifdef OLED_DRIVER_ENABLE
    #define OLED_DISPLAY_128X64
#endif

#ifdef RGB_ENABLE
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL
    #define RGBLIGHT_HUE_STEP 50
    #define RGBLIGHT_SAT_STEP 8
#endif

#ifdef COMBO_ENABLE
    #ifdef COMBO_COUNT
        #undef COMBO_COUNT
    #endif
    #define COMBO_COUNT 11

    #define COMBO_ALLOW_ACTION_KEYS

    #ifdef COMBO_TERM
        #undef COMBO_TERM
    #endif
    #define COMBO_TERM (TAPPING_TERM/4) // threshold to press all combo keys
    #define COMBO_HOLD (COMBO_TERM*3) // hold threshold to trigger combo
    #define ADAPTIVE_TERM COMBO_HOLD
#endif

#ifdef ENCODER_ENABLE
    #undef ENCODER_RESOLUTION
    #define ENCODER_RESOLUTION 2
    #define ENCODER_DIRECTION_FLIP
#endif

#ifdef HAPTIC_ENABLE
    #define FB_ERM_LRA 1
    #define FB_BRAKEFACTOR 3 /* For 1x:0, 2x:1, 3x:2, 4x:3, 6x:4, 8x:5, 16x:6, Disable Braking:7 */
    #define FB_LOOPGAIN 1 /* For  Low:0, Medium:1, High:2, Very High:3 */

    /* Please refer to your datasheet for the optimal setting for your specific motor. */
    #define RATED_VOLTAGE 2
    #define V_PEAK 2.8
    #define V_RMS 2.0
    #define F_LRA 205 /* resonance freq */
#endif

#define HANDSDOWN_ELAN



