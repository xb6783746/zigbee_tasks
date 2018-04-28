#include <pwm_api.h>
#include <internal/led_pwm_configuration.h>

#include <stm32f4xx_tim.h>

/**
 * @file src/pwm_configuration.c
 * 
 * Functions for init PWM and GPIOs
 */

/**
 * @brief Inits pins, connected to first three timer channels for alternate function
 */
static void init_leds(void);

/**
 * @brief Inits timer with defined PWM_FREQ
 */
static void init_timer(void);

/**
 * @brief Inits PWM on first three channels
 */
static void init_pwm(void);

void init_leds_pwm()
{

    init_leds();
    init_timer();
    init_pwm();

    TIM_Cmd(PWM_TIM, ENABLE);
}

static void init_leds(void)
{

    GPIO_PinAFConfig(PWM_GPIO, GPIO_PINSOURCE1, TIM_GPIO_AF);
    GPIO_PinAFConfig(PWM_GPIO, GPIO_PINSOURCE2, TIM_GPIO_AF);
    GPIO_PinAFConfig(PWM_GPIO, GPIO_PINSOURCE3, TIM_GPIO_AF);

    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Pin = GPIO_PWM_PIN_MASK;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

    GPIO_Init(PWM_GPIO, &GPIO_InitStructure);
}

static void init_timer(void)
{

    TIM_TimeBaseInitTypeDef timerInit;

    TIM_TimeBaseStructInit(&timerInit);

    timerInit.TIM_Period = (uint16_t) ARR_VAL;
    timerInit.TIM_Prescaler = PRESCALER - 1;
    timerInit.TIM_ClockDivision = TIM_CKD_DIV1;
    timerInit.TIM_CounterMode = TIM_CounterMode_Up;
    timerInit.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(PWM_TIM, &timerInit);

}

static void init_pwm(void)
{

    TIM_OCInitTypeDef pwmInit;

    TIM_OCStructInit(&pwmInit);

    pwmInit.TIM_OCMode = TIM_OCMode_PWM1;
    pwmInit.TIM_OutputState = TIM_OutputState_Enable;
    pwmInit.TIM_OCPolarity = TIM_OCPolarity_Low;
    pwmInit.TIM_Pulse = (uint32_t) (ARR_VAL);

    TIM_OC1Init(PWM_TIM, &pwmInit);
    TIM_OC1PreloadConfig(PWM_TIM, TIM_OCPreload_Enable);

    TIM_OC2Init(PWM_TIM, &pwmInit);
    TIM_OC2PreloadConfig(PWM_TIM, TIM_OCPreload_Enable);

    TIM_OC3Init(PWM_TIM, &pwmInit);
    TIM_OC3PreloadConfig(PWM_TIM, TIM_OCPreload_Enable);

    TIM_CtrlPWMOutputs(PWM_TIM, ENABLE);
}

