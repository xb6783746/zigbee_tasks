

#ifndef PROJECT_BUTTON_CONTROLLER_H
#define PROJECT_BUTTON_CONTROLLER_H

#include <zb_common.h>

typedef enum button_event_s
{

    power_button_pressed,
    level_button_pressed,
    both_buttons_pressed
} button_event_s;

void button_controller_init(zb_uint16_t addr);

void process_button_event(button_event_s event);

#endif //PROJECT_BUTTON_CONTROLLER_H
