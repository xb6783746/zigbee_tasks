#ifndef PWM_API
#define PWM_API

/**
 * @file pwm_api.h
 *
 * Functions for init PWM and GPIOs
 *
 * Timer for PWM can be defined as USE_TIMERx, where x - timer number. 
 * All 4-channel timers can be used. For PWM uses first three channels.
 *
 * PWM frequency can be defined as PWM_FREQ. Default value is 100 Hz
 */

/**
 * @brief Inits timer and gpio for PWM
 *
 * Inits selected timer 
 * Inits pins, connected to first three channels of selected timer for alternate function.
 *
 */
void init_leds_pwm();

#endif
