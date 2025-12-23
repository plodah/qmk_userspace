#if defined(BETTER_DRAGSCROLL) // any condition requiring a pointing_device_task_user
    #pragma once
    #include "mouse_gesture.h"
    #if defined(BETTER_DRAGSCROLL)
        #include "better_dragscroll.h"
    #endif // #BETTER_DRAGSCROLL

    report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
        #if defined(BETTER_DRAGSCROLL)
            #if defined(PLODAH_MSGESTURE_ENABLE) && defined(DEFERRED_EXEC_ENABLE)
                pointing_device_task_mouse_gesture(mouse_report);
        #endif // defined(PLODAH_MSGESTURE_ENABLE) && defined(DEFERRED_EXEC_ENABLE)
        mouse_report = pointing_device_task_better_dragscroll(mouse_report);
        #endif
        return mouse_report;
    }

#endif // BETTER_DRAGSCROLL (all)
