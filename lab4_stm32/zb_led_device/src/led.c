
#include <led.h>
#include <led_api.h>

#define CURR_CHANNEL channels[curr_channel_id]
#define CHANNEL_COUNT 3

static zb_uint8_t curr_level;
static led_state_enum_t curr_state;

static Channel channels[CHANNEL_COUNT];
static zb_uint8_t curr_channel_id = 0;

static void change_state(led_state_enum_t state);

void led_init()
{

    channels[0] = Red;
    channels[1] = Green;
    channels[2] = Blue;
}

void led_set_state(led_state_enum_t state)
{

    curr_state = state;

    change_state(state);
}

void led_toggle()
{

    curr_state = (led_state_enum_t) !curr_state;

    change_state(curr_state);
}

void led_set_level(zb_uint8_t level)
{

    curr_level = level;

    set_brightness(curr_level, CURR_CHANNEL);
}

void led_change_color()
{

    set_brightness(0, CURR_CHANNEL);

    curr_channel_id = (curr_channel_id + 1) % CHANNEL_COUNT;

    set_brightness(curr_level, CURR_CHANNEL);
}

void led_up_down(led_up_down_enum_t updown)
{

    int step = updown == Led_Up ? LED_STEP : -LED_STEP;

    curr_level = (255 + (int) curr_level + step) % 255;

    set_brightness(curr_level, CURR_CHANNEL);
}

static void change_state(led_state_enum_t state)
{
    if (state == Led_State_On)
    {

        set_brightness(curr_level, CURR_CHANNEL);
    }
    else
    {

        set_brightness(0, CURR_CHANNEL);
    }
}