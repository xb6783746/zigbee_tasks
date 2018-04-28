#include <init.h>

#include <stm32f4xx.h>

#define LED_GPIO_BUS            RCC_AHB1Periph_GPIOA
#define PWM_TIM_BUS             RCC_APB2Periph_TIM1

void init_leds()
{

    RCC_AHB1PeriphClockCmd(LED_GPIO_BUS, ENABLE);
}

void init_timer()
{

    RCC_APB2PeriphClockCmd(PWM_TIM_BUS, ENABLE);
}
