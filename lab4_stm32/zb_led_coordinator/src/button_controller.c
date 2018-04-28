
#include <button_controller.h>
#include <command_sender.h>

static zb_uint16_t address;

static zb_uint8_t create_command_buf(zb_uint16_t addr, zb_uint8_t val);

void button_controller_init(zb_uint16_t addr)
{

    address = addr;
}

void process_button_event(button_event_s event)
{

    switch (event)
    {

        case power_button_pressed:

            ZB_SCHEDULE_CALLBACK(
                    led_send_led_control_command,
                    create_command_buf(address, Toggle)
            );
            break;
        case level_button_pressed:

            ZB_SCHEDULE_CALLBACK(
                    led_send_level_up_down_command,
                    create_command_buf(address, Up)
            );

            break;
        case both_buttons_pressed:

            ZB_SCHEDULE_CALLBACK(
                    led_send_led_control_command,
                    create_command_buf(address, NextColor)
            );
            break;
    }
}

static zb_uint8_t create_command_buf(zb_uint16_t addr, zb_uint8_t val)
{

    zb_buf_t *buf = zb_get_in_buf();

    led_command_args_t *args = ZB_GET_BUF_PARAM(buf, led_command_args_t);

    args->addr = addr;
    args->data = val;

    return ZB_REF_FROM_BUF(buf);
}