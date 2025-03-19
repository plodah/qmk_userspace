#if defined(PLODAH_DRAGSCROLL)
  #include "dragscroll.h"
  plodah_dragscroll_enabled = 0;
  plodah_dragscroll_acc_h = 0;
  plodah_dragscroll_acc_v = 0;

  void pl_dragscroll_toggle(bool pressed){
    if(pressed){
      plodah_dragscroll_enabled ^= 1;
    }
  }

  void pl_dragscroll_momentary(bool pressed){
    plodah_dragscroll_enabled = pressed;
  }

  void pl_dragscroll_off(void){
    plodah_dragscroll_enabled = 0;
  }

  void pl_dragscroll_everypress(int16_t keycode) {
    if( keycode != (PL_DRAG_SCROLL_TOGGLE) ) {
      pl_dragscroll_off();
    }
  }

  report_mouse_t plodah_dragscroll_pointingtask(report_mouse_t mouse_report) {
    if (plodah_dragscroll_enabled) {
        plodah_dragscroll_acc_h += (float)mouse_report.x / PLODAH_DRAGSCROLL_DIVISOR_H;
        plodah_dragscroll_acc_v += (float)mouse_report.y / PLODAH_DRAGSCROLL_DIVISOR_V;

        // Assign integer parts of accumulated scroll values to the mouse report
        mouse_report.h = (int8_t)plodah_dragscroll_acc_h;
        #ifdef PLODAH_DRAGSCROLL_INVERT
          mouse_report.v = -(int8_t)plodah_dragscroll_acc_v;
        #else
          mouse_report.v = (int8_t)plodah_dragscroll_acc_v;
        #endif // PLODAH_DRAGSCROLL_INVERT

        // Update accumulated scroll values by subtracting the integer parts
        plodah_dragscroll_acc_h -= (int8_t)plodah_dragscroll_acc_h;
        plodah_dragscroll_acc_v -= (int8_t)plodah_dragscroll_acc_v;

        // Clear the X and Y values of the mouse report
        mouse_report.x = 0;
        mouse_report.y = 0;

        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
  }

#endif // PLODAH_DRAGSCROLL
