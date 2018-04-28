#include <zb_common.h>

#include <button_interrupt_handler.h>

#define EXTI_LINE_NAME EXTI_Line0

#define BUTTON_DELAY_BEACONS 5

volatile static zb_uint8_t pause = 0;
volatile zb_uint8_t power_button_flag = 0;

static void activate(zb_uint8_t param);

void EXTI0_IRQHandler(void)
{

    if (EXTI_GetITStatus(EXTI_LINE_NAME) != RESET)
    {

        EXTI_ClearITPendingBit(EXTI_LINE_NAME);

        if (pause)
        {

            return;
        }

        pause = 1;
        ZB_SCHEDULE_ALARM(activate, 0, BUTTON_DELAY_BEACONS);

        power_button_flag = 1;

        if (!is_handling)
        {

            is_handling = 1;
            ZB_SCHEDULE_ALARM(handle_button_pressed, 0, BUTTON_WAIT_PRESS_BEACONS);
        }
    }
}

static void activate(zb_uint8_t param)
{

    pause = 0;
}
