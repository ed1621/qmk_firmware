#include "handsdown-gold.h"

void matrix_scan_user(void) {

#ifdef COMBO_ENABLE
    matrix_scan_user_process_combo();
#endif

}
