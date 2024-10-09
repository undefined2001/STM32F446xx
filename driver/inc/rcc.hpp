#pragma once

#include "stm32f446xx.h"

namespace core
{
    class Rcc
    {
    public:
        static void EnablePeripheral(GPIO_TypeDef *pGPIOx);
        static void EnablePeripheral(TIM_TypeDef *pTIMx);
        static void EnablePeripheral(USART_TypeDef *pUSARTx);
    };

} // namespace core