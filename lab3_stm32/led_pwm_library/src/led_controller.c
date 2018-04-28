#include <stm32f4xx.h>

#include <led_api.h>
#include <internal/pwm_controller.h>
#include <math.h>

#ifndef GAMMA_CORRECTION_PARAMETER_R

#define GAMMA_CORRECTION_PARAMETER_R 3.03
#endif

#ifndef GAMMA_CORRECTION_PARAMETER_G

#define GAMMA_CORRECTION_PARAMETER_G 2.0
#endif

#ifndef GAMMA_CORRECTION_PARAMETER_B

#define GAMMA_CORRECTION_PARAMETER_B 3.03
#endif

/**
 * @file src/led_controller.c
 *
 * Functions for controlling RGB led.
 *
 * Functions sets gamma-corected values of brightness.
 * \f$ realValue = 255 * (\frac{x}{255})^\gamma \f$, where value of \f$ \gamma \f$ can be defined 
 * by each channel as GAMMA_CORRECTION_PARAMETER_[R | G | B].
 */

int __errno;

/**
 * @brief Function for gamma-correcting
 *
 * @return \f$ 255 * (\frac{val}{255})^\gamma \f$, where \f$ \gamma \f$ is GAMMA_CORRECTION_PARAMETER for channel
 */
static uint8_t gamma_correction(Channel ch, uint8_t val)
{

    double tmp = val / 255.0;

    double parameter;

    switch (ch)
    {

        case Red:
            parameter = GAMMA_CORRECTION_PARAMETER_R;
            break;
        case Green:
            parameter = GAMMA_CORRECTION_PARAMETER_G;
            break;
        case Blue:
            parameter = GAMMA_CORRECTION_PARAMETER_B;
            break;
    }

    return (uint8_t)(pow(tmp, parameter) * 255);
}

void set_rgb(uint8_t r, uint8_t g, uint8_t b)
{

    uint8_t correctedR = gamma_correction(Red, r);
    uint8_t correctedG = gamma_correction(Green, g);
    uint8_t correctedB = gamma_correction(Blue, b);

    set_power(correctedR, correctedG, correctedB);
}

void set_brightness(uint8_t brightness, Channel channel)
{

    PWM_Channel ch;
    uint8_t value = gamma_correction(channel, brightness);

    switch (channel)
    {

        case Red:
            ch = PWM_FirstChannel;
            break;
        case Green:
            ch = PWM_SecondChannel;
            break;
        case Blue:
            ch = PWM_ThirdChannel;
            break;
    }

    set_channel_power(value, ch);
}
