#include <init.h>

#include <stm32f4xx.h>

#define BUTTONS_GPIO_BUS        RCC_AHB1Periph_GPIOE

#define BUTTONS_PORT_SOURCE     EXTI_PortSourceGPIOE

#define BUTTONS_GPIO            GPIOE

#define BRIGHTNESS_BUTTON_PIN   GPIO_Pin_0
#define BRIGHTNESS_BUTTON_PS    EXTI_PinSource0
#define BRIGHTNESS_BUTTON_LN    EXTI_Line0
#define BRIGHTNESS_BUTTTON_IRQ  EXTI0_IRQn

#define CHANNEL_BUTTON_PIN      GPIO_Pin_1
#define CHANNEL_BUTTON_PS       EXTI_PinSource1
#define CHANNEL_BUTTON_LN       EXTI_Line1
#define CHANNEL_BUTTON_IRQ      EXTI1_IRQn


void init_buttons()
{

    RCC_AHB1PeriphClockCmd(BUTTONS_GPIO_BUS, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Pin = CHANNEL_BUTTON_PIN | BRIGHTNESS_BUTTON_PIN;

    GPIO_Init(BUTTONS_GPIO, &GPIO_InitStructure);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

    SYSCFG_EXTILineConfig(BUTTONS_PORT_SOURCE, CHANNEL_BUTTON_PS);
    SYSCFG_EXTILineConfig(BUTTONS_PORT_SOURCE, BRIGHTNESS_BUTTON_PS);

    EXTI_InitTypeDef EXTI_InitStruct;

    EXTI_InitStruct.EXTI_Line = CHANNEL_BUTTON_LN | BRIGHTNESS_BUTTON_LN;
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;
    EXTI_Init(&EXTI_InitStruct);
}

void init_interrupts(void)
{
    NVIC_InitTypeDef nvicInit;

    nvicInit.NVIC_IRQChannel = BRIGHTNESS_BUTTTON_IRQ;
    nvicInit.NVIC_IRQChannelPreemptionPriority = 0x00;
    nvicInit.NVIC_IRQChannelSubPriority = 0x00;
    nvicInit.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&nvicInit);

    nvicInit.NVIC_IRQChannel = CHANNEL_BUTTON_IRQ;
    nvicInit.NVIC_IRQChannelPreemptionPriority = 0x00;
    nvicInit.NVIC_IRQChannelSubPriority = 0x00;
    nvicInit.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&nvicInit);

}
