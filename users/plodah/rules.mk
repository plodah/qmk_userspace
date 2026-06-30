INTROSPECTION_KEYMAP_C = plodah.c
RGB_MATRIX_CUSTOM_USER = yes

SRC += functions/0_housekeeping_task_user.c
#SRC += functions/0_keyboard_post_init_user.c
SRC += functions/0_pointing_device_task_user.c
SRC += functions/0_process_record_user.c

# SRC += functions/autocorrect.c
# SRC += functions/better_dragscroll.c
# SRC += functions/caps_word.c
SRC += functions/chordal_hold.c
# SRC += functions/combos.c
SRC += functions/debug.c
SRC += functions/dipswitch.c
SRC += functions/dynamic_macros.c
# SRC += functions/encoder_actions.c
SRC += functions/flow_tap.c
SRC += functions/leader.c
# SRC += functions/led_update_user.c
# SRC += functions/mouse_gesture.c
SRC += functions/oled.c
# SRC += functions/ploopy_via.c
SRC += functions/shutdown.c
# SRC += functions/tapdance.c
# SRC += functions/tri_layer.c
