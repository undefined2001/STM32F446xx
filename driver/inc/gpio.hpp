#pragma once

#include "stm32f446xx.h"

struct Pin
{
    GPIO_TypeDef *pGPIO;
    uint8_t Pin;
};

#define PA5 (Pin){GPIOA, 5}