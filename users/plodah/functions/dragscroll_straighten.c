// Will be enabled when variable defined
// define PLODAH_DRAGSCROLL_STRAIGHTEN_RATIO 2
// The value controls how much larger one dimensions scroll must be in order to cancel out the other.
// e.g.  a ratio of 2, horizontal scroll would be cancelled out when vertical scroll is 2x greater.
// A ratio of 1 would cancel diagonal scrolling
bool is_drag_scroll;
float scroll_accumulated_h;
float scroll_accumulated_v;

#if defined(PLODAH_DRAGSCROLL_STRAIGHTEN_RATIO)
    //#include "print.h"
    report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
        if (is_drag_scroll && (mouse_report.h || mouse_report.v)) {
            #ifdef CONSOLE_ENABLE
                printf( "A: h:%+03d, ha:%+03d, v:%+03d, va:%+03d || ", mouse_report.h, (int8_t)(scroll_accumulated_h*1000), mouse_report.v, (int8_t)(scroll_accumulated_v*1000) );
            #endif // CONSOLE_ENABLE
            scroll_accumulated_h += mouse_report.h;
            scroll_accumulated_v += mouse_report.v;

            if(scroll_accumulated_h != 0 && scroll_accumulated_v != 0){


                if( abs(scroll_accumulated_v) >= abs(scroll_accumulated_h) * PLODAH_DRAGSCROLL_STRAIGHTEN_RATIO  ){
                    #ifdef CONSOLE_ENABLE
                        printf("HH || " );
                    #endif // CONSOLE_ENABLE
                    scroll_accumulated_h = 0;
                }
                else if( abs(scroll_accumulated_h) > abs(scroll_accumulated_v) * PLODAH_DRAGSCROLL_STRAIGHTEN_RATIO  ){
                    #ifdef CONSOLE_ENABLE
                        printf("VV || " );
                    #endif // CONSOLE_ENABLE
                    scroll_accumulated_v = 0;
                }
            }
            else{
                #ifdef CONSOLE_ENABLE
                    printf("__ || " );
                #endif // CONSOLE_ENABLE
            }
            mouse_report.h = (int8_t)scroll_accumulated_h;
            scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
            mouse_report.v = (int8_t)scroll_accumulated_v;
            scroll_accumulated_v -= (int8_t)scroll_accumulated_v;
            #ifdef CONSOLE_ENABLE
                printf( "B: h:%+03d, ha:%+03d, v:%+03d, va:%+03d \n", mouse_report.h, (int8_t)(scroll_accumulated_h*1000), mouse_report.v, (int8_t)(scroll_accumulated_v*1000) );
            #endif // CONSOLE_ENABLE
        }
        return mouse_report;
    }
#endif // PLODAH_DRAGSCROLL_STRAIGHTEN_RATIO
