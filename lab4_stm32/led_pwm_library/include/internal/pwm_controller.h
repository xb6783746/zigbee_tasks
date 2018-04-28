#ifndef PWM_CONTROLLER
#define PWM_CONTROLLER

#include <stm32f4xx.h>

typedef enum
{

    PWM_FirstChannel, PWM_SecondChannel, PWM_ThirdChannel
} PWM_Channel;

/**
 * @file internal/pwm_controller.h
 *
 * Functions for low-level PWM controlling
 */

/**
 * @brief Sets duty cycle for specific channel
 *
 * Duty cycle (%) is \f$ \frac{x}{255} * 100 \f$
 *
 * @param val 
 * @param channel
 */
void set_channel_power(uint8_t val, PWM_Channel channel);

/**
 * @brief Sets duty cycles for all channels
 * 
 * Duty cycle (%) is \f$ \frac{x}{255} * 100 \f$
 * 
 */
void set_power(uint8_t ch1, uint8_t ch2, uint8_t ch3);

#endif
