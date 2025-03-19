#pragma once

#define PLODAH_MSGESTURE_TIMEOUT 225
#define PLODAH_MSGESTURE_DEBOUNCE 25
#define PLODAH_MSGESTURE_COOLDOWN 800
#define PLODAH_MSGESTURE_WIGGLES 4
#define PLODAH_MSGESTURE_THRESHOLD 1800

report_mouse_t pointing_device_task_mouse_gesture(report_mouse_t mouse_report);
void plodah_msGestureResetAll(void);
void plodah_msGestureUpdate(void);

enum gesture_actions {
    GESTURE_ACTION_NOTHING = 0,
    GESTURE_ACTION_DRAGSCROLL,
    GESTURE_ACTION_MSJIGGLER,
};

typedef struct plodah_msGesture_t {
    deferred_token cooldown;
    deferred_token timeout;
    uint8_t action;
    uint8_t count;
    int16_t accum;
    bool stage;
} plodah_msGesture_t;

plodah_msGesture_t plodah_msGesture_X;
plodah_msGesture_t plodah_msGesture_Y;
uint8_t gestureCount;
