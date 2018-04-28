
#ifndef PROJECT_COMMAND_SENDER_H
#define PROJECT_COMMAND_SENDER_H

#include <common.h>

typedef struct
{

    zb_uint16_t addr;
    zb_uint8_t data;
} led_command_args_t;

void led_send_led_control_command(zb_uint8_t param);

void led_send_set_level_command(zb_uint8_t param);

void led_send_level_up_down_command(zb_uint8_t param);

#endif //PROJECT_COMMAND_SENDER_H
