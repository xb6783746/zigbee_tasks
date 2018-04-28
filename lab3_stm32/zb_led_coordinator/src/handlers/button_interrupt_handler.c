
#include <button_interrupt_handler.h>
#include <button_controller.h>

extern volatile zb_uint8_t power_button_flag;
extern volatile zb_uint8_t level_button_flag;

volatile zb_uint8_t is_handling;

void handle_button_pressed(zb_uint8_t param)
{

    is_handling = 0;

    button_event_s event;

    if (power_button_flag && level_button_flag)
    {

        event = both_buttons_pressed;
    }
    else if (power_button_flag)
    {

        event = power_button_pressed;
    }
    else
    {

        event = level_button_pressed;
    }

    power_button_flag = 0;
    level_button_flag = 0;

    process_button_event(event);
}