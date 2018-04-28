

#ifndef PROJECT_BUTTON_INTERRUPT_HANDLER_H
#define PROJECT_BUTTON_INTERRUPT_HANDLER_H

#include <zb_common.h>

#define BUTTON_WAIT_BEACONS 5
#define BUTTON_WAIT_PRESS_BEACONS 5

extern volatile zb_uint8_t is_handling;

void handle_button_pressed(zb_uint8_t param);

#endif //PROJECT_BUTTON_INTERRUPT_HANDLER_H
