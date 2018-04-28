

#ifndef PROJECT_COMMON_H
#define PROJECT_COMMON_H

#include <zb_types.h>

#define LED_COMMAND_PACKET_SIZE 10


typedef enum {

    LedControlCommand,
    LedSetLevelCommand,
    LedLevelUpDownCommand
} LedCommand;

typedef enum{

    On = 1,
    Off = 2,
    Toggle = 3,
    NextColor = 4
} led_control_value_t;

typedef enum {

    Up = 1,
    Down = 2
} led_up_down_value_t;

typedef struct led_packet{

    zb_uint8_t command_type;
    zb_uint8_t data;
} led_packet_t;


#endif //PROJECT_COMMON_H
