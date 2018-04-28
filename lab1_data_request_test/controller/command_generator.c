
#include <common.h>
#include <command_sender.h>
#include "zb_common.h"

#define DELAY 3

#define GET_TIME(x) ((x) * DELAY * ZB_TIME_ONE_SECOND)

static zb_uint8_t create_command_buf(zb_uint16_t addr, zb_uint8_t val);

void command_generator_generate(zb_uint16_t addr)
{


    ZB_SCHEDULE_ALARM(
            led_send_led_control_command,
            create_command_buf(addr, On),
            GET_TIME(1)
    );

    ZB_SCHEDULE_ALARM(
            led_send_led_control_command,
            create_command_buf(addr, Off),
            GET_TIME(2)
    );

    ZB_SCHEDULE_ALARM(
            led_send_set_level_command,
            create_command_buf(addr, 37),
            GET_TIME(3)
    );

    ZB_SCHEDULE_ALARM(
            led_send_level_up_down_command,
            create_command_buf(addr, Up),
            GET_TIME(4)
    );

    ZB_SCHEDULE_ALARM(
            led_send_level_up_down_command,
            create_command_buf(addr, Down),
            GET_TIME(5)
    );

}

static zb_uint8_t create_command_buf(zb_uint16_t addr, zb_uint8_t val)
{

    zb_buf_t *buf = zb_get_in_buf();

    led_command_args_t *args = ZB_GET_BUF_PARAM(buf, led_command_args_t);

    args->addr = addr;
    args->data = val;

    return ZB_REF_FROM_BUF(buf);
}
