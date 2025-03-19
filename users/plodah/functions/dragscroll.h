#pragma once

bool plodah_dragscroll_enabled;
float plodah_dragscroll_acc_h;
float plodah_dragscroll_acc_v;

void pl_dragscroll_everypress(int16_t keycode);
report_mouse_t plodah_dragscroll_pointingtask(report_mouse_t mouse_report);
void pl_dragscroll_toggle(bool pressed);
void pl_dragscroll_off(void);
void pl_dragscroll_momentary(bool pressed);
