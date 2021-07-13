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

#pragma once

#define MASTER_LEFT

#ifdef OLED_DRIVER_ENABLE
    #define OLED_DISPLAY_128X64
    #ifdef OLED_TIMEOUT
        #undef OLED_TIMEOUT
    #endif
    #define OLED_TIMEOUT 30000
#endif

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_SLEEP
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL
    #define RGBLIGHT_HUE_STEP 50
    #define RGBLIGHT_SAT_STEP 8
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


#define TAP_CODE_DELAY 5
#define TAPPING_TERM 275

#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

#ifdef DEBOUNCE
    #undef DEBOUNCE
    #define DEBOUNCE 9
#endif


