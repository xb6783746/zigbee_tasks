#ifndef LED_PWM_CONFIGURATION
#define LED_PWM_CONFIGURATION

#include <stm32f4xx.h>

/**
 * @file internal/led_pwm_configuration.h
 *
 * Contains defines for different timers
 */

#ifdef USE_PWM_TIM1

#define PWM_GPIO GPIOA

#define PWM_TIM TIM1
#define PWM_TIM_CLOCK 168000000
#define TIM_GPIO_AF GPIO_AF_TIM1
#define GPIO_PWM_PIN_MASK (GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10)

#define GPIO_PINSOURCE1 GPIO_PinSource8
#define GPIO_PINSOURCE2 GPIO_PinSource9
#define GPIO_PINSOURCE3 GPIO_PinSource10

#elif defined USE_PWM_TIM8

#define PWM_GPIO GPIOC

#define PWM_TIM TIM8
#define PWM_TIM_CLOCK 168000000
#define TIM_GPIO_AF GPIO_AF_TIM8
#define GPIO_PWM_PIN_MASK (GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8)

#define GPIO_PINSOURCE1 GPIO_PinSource6
#define GPIO_PINSOURCE2 GPIO_PinSource7
#define GPIO_PINSOURCE3 GPIO_PinSource8

#elif defined USE_PWM_TIM2

#define PWM_GPIO GPIOA

#define PWM_TIM TIM2
#define PWM_TIM_CLOCK 84000000
#define TIM_GPIO_AF GPIO_AF_TIM2
#define GPIO_PWM_PIN_MASK (GPIO_Pin_15 | GPIO_Pin_1 | GPIO_Pin_2)

#define GPIO_PINSOURCE1 GPIO_PinSource15
#define GPIO_PINSOURCE2 GPIO_PinSource1
#define GPIO_PINSOURCE3 GPIO_PinSource2

#elif defined USE_PWM_TIM5

#define PWM_GPIO GPIOA

#define PWM_TIM TIM5
#define PWM_TIM_CLOCK 84000000
#define TIM_GPIO_AF GPIO_AF_TIM5
#define GPIO_PWM_PIN_MASK (GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2)

#define GPIO_PINSOURCE1 GPIO_PinSource0
#define GPIO_PINSOURCE2 GPIO_PinSource1
#define GPIO_PINSOURCE3 GPIO_PinSource2

#elif defined  USE_PWM_TIM3

#define PWM_GPIO GPIOC

#define PWM_TIM TIM3
#define PWM_TIM_CLOCK 84000000
#define TIM_GPIO_AF GPIO_AF_TIM3
#define GPIO_PWM_PIN_MASK (GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8)

#define GPIO_PINSOURCE1 GPIO_PinSource6
#define GPIO_PINSOURCE2 GPIO_PinSource7
#define GPIO_PINSOURCE3 GPIO_PinSource8

#elif defined  USE_PWM_TIM4

#define PWM_GPIO GPIOD

#define PWM_TIM TIM4
#define PWM_TIM_CLOCK 84000000
#define TIM_GPIO_AF GPIO_AF_TIM4
#define GPIO_PWM_PIN_MASK (GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14)

#define GPIO_PINSOURCE1 GPIO_PinSource12
#define GPIO_PINSOURCE2 GPIO_PinSource13
#define GPIO_PINSOURCE3 GPIO_PinSource14

#else

#error "Timer for PWM must be specified"
#endif

#ifndef PWM_FREQ

#define PWM_FREQ 100
#endif

#define PWM_TIM_FREQ 100000
#define PRESCALER PWM_TIM_CLOCK / PWM_TIM_FREQ
#define ARR_VAL PWM_TIM_FREQ / PWM_FREQ

#endif
