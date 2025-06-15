
#if defined (COMBO_ENABLE) && defined(DEFERRED_EXEC_ENABLE) && defined(COMBOFLOW_ENABLE)
    #pragma once
    #include "action.h"
    #include "deferred_exec.h"

    #if !defined(COMBOFLOW_TERM)
        #define COMBOFLOW_TERM 200
    #endif // COMBOFLOW_TERM

    deferred_token ComboFlowToken = INVALID_DEFERRED_TOKEN;
    bool process_record_comboflow(uint16_t keycode, keyrecord_t *record);
#endif // defined (COMBO_ENABLE) && defined(DEFERRED_EXEC_ENABLE) && defined(COMBOFLOW_ENABLE)
