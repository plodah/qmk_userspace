#if defined(PLODAH_DRAGSCROLL) || (defined(PLODAH_MSJIGGLER_ENABLE) && defined(DEFERRED_EXEC_ENABLE)) // any condition requiring a pointing_device_task_user
  #pragma once
  report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    #if defined(PLODAH_MSJIGGLER_ENABLE) && defined(DEFERRED_EXEC_ENABLE)
      if( mouse_report.x != 0 || mouse_report.y != 0 ){
        jiggle_delay(5);
      }
    #endif
    #if defined(PLODAH_DRAGSCROLL)
      #if defined(PLODAH_MSGESTURE_ENABLE) && defined(DEFERRED_EXEC_ENABLE)
        switch(plodah_msgesturecheck(mouse_report)){
          case 1:
            pl_dragscroll_toggle(true);
            break;
          case -1:
            jiggler_toggle();
            break;
        }
      #endif // defined(PLODAH_MSGESTURE_ENABLE) && defined(DEFERRED_EXEC_ENABLE)
      mouse_report = plodah_dragscroll_pointingtask(mouse_report);
    #endif
    return mouse_report;
  }

#endif // PLODAH_DRAGSCROLL (all)
