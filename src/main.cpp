#include "stm32f446xx.h"
#include "gpio.hpp"

int main()
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    GPIOA->MODER |= 1 << PA5.Pin * 2;

    while (true)
    {
        PA5.pGPIO->ODR ^= 1 << 5;
        for (int i = 0; i < 2000000; i++)
            ;
    }

    return 0;
}