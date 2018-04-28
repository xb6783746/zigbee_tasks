#include <internal/pwm_controller.h>
#include <internal/led_pwm_configuration.h>
#include <stm32f4xx_tim.h>


/**
 * @file pwm_controller.c
 *
 * Functions for low-level PWM controlling
 */

void set_channel_power(uint8_t val, PWM_Channel channel)
{

    uint32_t pulse = ARR_VAL * val / 255;

    switch (channel)
    {

        case PWM_FirstChannel:
            TIM_SetCompare1(PWM_TIM, pulse);
            break;
        case PWM_SecondChannel:
            TIM_SetCompare2(PWM_TIM, pulse);
            break;
        case PWM_ThirdChannel:
            TIM_SetCompare3(PWM_TIM, pulse);
            break;
    }
}

void set_power(uint8_t ch1, uint8_t ch2, uint8_t ch3)
{

    uint32_t pulse = ARR_VAL * ch1 / 255;
    TIM_SetCompare1(PWM_TIM, pulse);

    pulse = ARR_VAL * ch2 / 255;
    TIM_SetCompare2(PWM_TIM, pulse);

    pulse = ARR_VAL * ch3 / 255;
    TIM_SetCompare3(PWM_TIM, pulse);


}
