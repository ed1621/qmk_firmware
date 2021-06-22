#define HANDSDOWN_ELAN

#define TAP_CODE_DELAY 5
#define TAPPING_TOGGLE 2

// #define RETRO_TAPPING
// #define TAPPING_FORCE_HOLD
#define TAPPING_TERM 180

#define TAP_HOLD_CAPS_DELAY 0
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

#ifdef COMBO_ENABLE
#ifdef COMBO_COUNT
        #undef COMBO_COUNT
    #endif
    #define COMBO_COUNT 15

    #define COMBO_ALLOW_ACTION_KEYS

    #ifdef COMBO_TERM
        #undef COMBO_TERM
    #endif
    #define COMBO_TERM (TAPPING_TERM/4) // threshold to press all combo keys
    #define COMBO_HOLD (COMBO_TERM*3) // hold threshold to trigger combo
#endif
