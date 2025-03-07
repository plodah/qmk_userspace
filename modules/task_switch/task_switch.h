#pragma once

#ifndef TASKSWITCH_DELAY
    #define TASKSWITCH_DELAY 1000
#endif // TASKSWITCH_DELAY

#if defined(DEFERRED_EXEC_ENABLE) && (!defined(TASK_SWITCH_FORCE_NDE))
    #define TASKSWITCH_MODE_DE
    #include "deferred_exec.h"
#endif // DEFERRED_EXEC_ENABLE

#if defined(TASKSWITCH_MODE_DE)
    static deferred_token taskSwitchToken = INVALID_DEFERRED_TOKEN;
#else // TASKSWITCH_MODE_DE
    bool is_taskswitch_active = false;
    uint16_t taskswitch_timer = 0;
#endif // defined(TASKSWITCH_MODE_DE)
