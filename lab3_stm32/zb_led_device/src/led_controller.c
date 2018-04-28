
#include <led_controller.h>
#include <led.h>

static void process_led_control_command(led_control_value_t val);

static void process_set_value_command(zb_uint8_t level);

static void process_level_up_down_command(led_up_down_value_t val);

void parse(led_packet_t *packet)
{

    switch (packet->command_type)
    {

        case LedControlCommand:
            process_led_control_command((led_control_value_t) packet->data);
            break;
        case LedSetLevelCommand:
            process_set_value_command(packet->data);
            break;
        case LedLevelUpDownCommand:
            process_level_up_down_command((led_up_down_value_t) packet->data);
            break;
        default:
            break;
    }
}

static void process_led_control_command(led_control_value_t val)
{

    if (val == Toggle)
    {

        led_toggle();
    }
    else if (val == NextColor)
    {

        led_change_color();
    }
    else
    {

        led_state_enum_t state = val == On ? Led_State_On : Led_State_Off;

        led_set_state(state);
    }
}

static void process_set_value_command(zb_uint8_t level)
{

    led_set_level(level);
}

static void process_level_up_down_command(led_up_down_value_t val)
{

    led_up_down_enum_t updown = val == Up ? Led_Up : Led_Down;

    led_up_down(updown);
}