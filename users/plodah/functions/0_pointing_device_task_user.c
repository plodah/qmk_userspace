#if defined(BETTER_DRAGSCROLL) // any condition requiring a pointing_device_task_user
  #pragma once

    #if defined(COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE)
        #include "mouse_jiggler.h"
    #endif // defined(COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE)

  report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    #if defined(BETTER_DRAGSCROLL)
      #if defined(PLODAH_MSGESTURE_ENABLE) && defined(DEFERRED_EXEC_ENABLE)
        switch(plodah_msgesturecheck(mouse_report)){
          case 1:
            pl_dragscroll_toggle(true);
            break;
          case -1:
            #if defined(COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE)
              jiggler_toggle();
            #endif // defined(COMMUNITY_MODULE_MOUSE_JIGGLER_ENABLE)
            break;
        }
      #endif // defined(PLODAH_MSGESTURE_ENABLE) && defined(DEFERRED_EXEC_ENABLE)
      mouse_report = pointing_device_task_better_dragscroll(mouse_report);
    #endif
    return mouse_report;
  }

#endif // BETTER_DRAGSCROLL (all)
