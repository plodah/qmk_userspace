#if defined(PLODAH_DRAGSCROLL)
  #pragma once

  bool plodah_dragscroll_enabled = 0;
  float plodah_dragscroll_acc_h = 0;
  float plodah_dragscroll_acc_v = 0;

  void pl_dragscroll_keyhandler(int8_t keycode, bool pressed) {
    switch(keycode){
      case PL_DRAG_SCROLL_MOMENTARY & 0xff:
        plodah_dragscroll_enabled = pressed;
        break;
      case PL_DRAG_SCROLL_TOGGLE & 0xff:
        if(pressed){
          plodah_dragscroll_enabled ^= 1;
        }
        break;
    }
  }
  void pl_dragscroll_everypress(int8_t keycode) {
    if( plodah_dragscroll_enabled && keycode != (PL_DRAG_SCROLL_TOGGLE & 0xff) ) {
      plodah_dragscroll_enabled ^= 1;
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
