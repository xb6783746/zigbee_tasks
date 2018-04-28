

#ifndef PROJECT_COMMON_H
#define PROJECT_COMMON_H

#include <zb_types.h>


typedef enum led_command_s
{

    LedControlCommand,
    LedSetLevelCommand,
    LedLevelUpDownCommand
} led_command_t;

typedef enum
{

    On = 1,
    Off = 2,
    Toggle = 3
} led_control_value_t;

typedef enum
{

    Up = 1,
    Down = 2
} led_up_down_value_t;

typedef struct led_packet
{

    zb_uint8_t command_type;
    zb_uint8_t data;
} led_packet_t;


#endif //PROJECT_COMMON_H
