
#include <led.h>
#include <zb_common.h>

static void print_state(led_state_enum_t state);

static void print_level(zb_uint8_t level);

static zb_uint8_t curr_level;
static led_state_enum_t curr_state;

void led_set_state(led_state_enum_t state)
{

    curr_state = state;

    print_state(state);
}

void led_toggle()
{

    curr_state = (led_state_enum_t) !curr_state;

    print_state(curr_state);
}

void led_set_level(zb_uint8_t level)
{

    curr_level = level;

    print_level(level);
}

void led_up_down(led_up_down_enum_t updown)
{

    int step = updown == Led_Up ? LED_STEP : -LED_STEP;

    int new_value = (int) curr_level + step;

    if (new_value < 0)
    {

        curr_level = 0;
    } else if (new_value > 255)
    {

        curr_level = 255;
    } else
    {

        curr_level = (zb_uint8_t) new_value;
    }

    print_level(curr_level);
}

static void print_state(led_state_enum_t state)
{

    TRACE_MSG(TRACE_INFO1, "LED New state: %d", (FMT__D, state == Led_State_On));
}

static void print_level(zb_uint8_t level)
{

    TRACE_MSG(TRACE_INFO1, "LED New level: %d", (FMT__D, level));
}