#ifndef LED_API
#define LED_API

#include <led_pwm_common_structures.h>
/**
 * @file led_api.h
 *
 * Functions for controlling RGB led.
 *
 * Functions sets gamma-corected values of brightness.
 * \f$ realValue = 255 * (\frac{x}{255})^\gamma \f$, where value of \f$ \gamma \f$ can be defined as
 * GAMMA_CORRECTION_PARAMETER. Default value is 2.2
 */

/**
 * @brief Set brightness for all channels
 *
 * Sets duty cycle of all channels to \f$ \frac{correctedVal}{255}*100 \% \f$,
 * where \f$ correctedVal \f$ is gamma-corrected value of brightness.
 *
 * @param r Brightness for red channel
 * @param g Brightness for green channel
 * @param b Brightness for blue channel
 */
void set_rgb(uint8_t r, uint8_t g, uint8_t b);

/**
 * @brief Set brightness for specific channel
 *
 * Sets duty cycle of specific channel to \f$ \frac{correctedVal}{255}*100 \% \f$,
 * where \f$ correctedVal \f$ is gamma-corrected value of brightness.
 *
 * @param brightness
 * @param channel See #Channel
 *
 */
void set_brightness(uint8_t brightness, Channel channel);

#endif
