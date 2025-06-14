#if defined (COMBO_ENABLE) && defined(DEFERRED_EXEC_ENABLE) && defined(COMBOFLOW_ENABLE)
    #if !defined(COMBOFLOW_TERM)
        #define COMBOFLOW_TERM 200
    #endif // COMBOFLOW_TERM

    #include "deferred_exec.h"
    deferred_token ComboFlowToken = INVALID_DEFERRED_TOKEN;
    uint32_t ComboFlow_reenable(uint32_t trigger_time, void *cb_arg) {
        if(!is_combo_enabled()) {
            ComboFlowToken = INVALID_DEFERRED_TOKEN;
            combo_enable();
            dprintf("COMBOFLOW re-enable\n");
        }
        else{
            dprintf("COMBOFLOW re-en...FAIL\n");
        }
        return 0;
    }

    bool process_record_comboflow(uint16_t keycode, keyrecord_t *record) {
        if(IS_COMBOEVENT(record->event)){
            dprintf("COMBOFLOW leave it");
            if(ComboFlowToken != INVALID_DEFERRED_TOKEN){
                cancel_deferred_exec(ComboFlowToken);
            }
            if(! is_combo_enabled()){
                combo_enable();
            }
        }
        else if(is_combo_enabled()) {
            combo_disable();
            dprintf("COMBOFLOW disable\n");
            ComboFlowToken = defer_exec(COMBOFLOW_TERM, ComboFlow_reenable, NULL);
        }
        else if(ComboFlowToken != INVALID_DEFERRED_TOKEN){
            dprintf("COMBOFLOW EXTEND\n");
            extend_deferred_exec(ComboFlowToken, COMBOFLOW_TERM);
        }
        return true;
    }
#endif
