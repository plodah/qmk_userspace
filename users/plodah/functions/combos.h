#if defined(COMBO_ENABLE)
    #pragma once
    #include <stdbool.h>
    #include <stdint.h>
    #include "process_combo.h"

    bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record);
#endif // defined(COMBO_ENABLE)
