// Will be enabled when variable defined
// define PLODAH_DRAGSCROLL_STRAIGHTEN_RATIO 2
// The value controls how much larger one dimensions scroll must be in order to cancel out the other.
// e.g.  a ratio of 2, horizontal scroll would be cancelled out when vertical scroll is 2x greater.
// A ratio of 1 would cancel diagonal scrolling

#if defined(PLODAH_DRAGSCROLL_STRAIGHTEN_RATIO)
    report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
        if (mouse_report.h || mouse_report.v) {
            if( (abs(mouse_report.h) * PLODAH_DRAGSCROLL_STRAIGHTEN_RATIO) <= abs(mouse_report.v) ){
                mouse_report.h = 0;
            }
            else if( (abs(mouse_report.v) * PLODAH_DRAGSCROLL_STRAIGHTEN_RATIO) < abs(mouse_report.h) ){
                mouse_report.v = 0;
            }
        }
        return mouse_report;
    }
#endif // PLODAH_DRAGSCROLL_STRAIGHTEN_RATIO
