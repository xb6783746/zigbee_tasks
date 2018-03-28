

#ifndef PROJECT_LED_H
#define PROJECT_LED_H

#include <zb_types.h>

#define LED_STEP 10

typedef enum led_state_enum{

    Led_State_On,
    Led_State_Off
} led_state_enum_t;

typedef enum led_up_down_enum{

    Led_Up,
    Led_Down
} led_up_down_enum_t;

void led_set_state(led_state_enum_t state);
void led_toggle(void);

void led_set_level(zb_uint8_t level);

void led_up_down(led_up_down_enum_t updown);

#endif //PROJECT_LED_H
