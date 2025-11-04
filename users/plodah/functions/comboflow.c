#if defined (COMBO_ENABLE) && defined(DEFERRED_EXEC_ENABLE) && defined(COMBOFLOW_ENABLE)

    #include "comboflow.h"
    #include "deferred_exec.h"
    #include "debug.h"
    #include "process_combo.h"

    uint32_t ComboFlow_reenable(uint32_t trigger_time, void *cb_arg) {
        if(!is_combo_enabled()) {
            ComboFlowToken = INVALID_DEFERRED_TOKEN;
            combo_enable();
            #if defined(COMBOFLOW_DEBUG)
              dprintf("COMBOFLOW re-enable\n");
            #endif // defined(COMBOFLOW_DEBUG)
        }
        else{
            #if defined(COMBOFLOW_DEBUG)
              dprintf("COMBOFLOW re-en...FAIL\n");
            #endif // defined(COMBOFLOW_DEBUG)
        }
        return 0;
    }

    bool process_record_comboflow(uint16_t keycode, keyrecord_t *record) {
        if(IS_COMBOEVENT(record->event)){
            #if defined(COMBOFLOW_DEBUG)
              dprintf("COMBOFLOW leave it");
            #endif // defined(COMBOFLOW_DEBUG)
            if(ComboFlowToken != INVALID_DEFERRED_TOKEN){
                cancel_deferred_exec(ComboFlowToken);
            }
            if(! is_combo_enabled()){
                combo_enable();
            }
        }
        else if(is_combo_enabled()) {
            combo_disable();
            #if defined(COMBOFLOW_DEBUG)
              dprintf("COMBOFLOW disable\n");
            #endif // defined(COMBOFLOW_DEBUG)
            ComboFlowToken = defer_exec(COMBOFLOW_TERM, ComboFlow_reenable, NULL);
        }
        else if(ComboFlowToken != INVALID_DEFERRED_TOKEN){
            #if defined(COMBOFLOW_DEBUG)
              dprintf("COMBOFLOW EXTEND\n");
            #endif // defined(COMBOFLOW_DEBUG)
            extend_deferred_exec(ComboFlowToken, COMBOFLOW_TERM);
        }
        return true;
    }
#endif
