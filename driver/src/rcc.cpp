#include "rcc.hpp"

using namespace core;

void Rcc::EnablePeripheral(GPIO_TypeDef *pGPIOx)
{
    (pGPIOx == GPIOA) ? RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN : (pGPIOx == GPIOB) ? RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN
                                                          : (pGPIOx == GPIOC)   ? RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN
                                                          : (pGPIOx == GPIOD)   ? RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN
                                                          : (pGPIOx == GPIOE)   ? RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN
                                                          : (pGPIOx == GPIOF)   ? RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN
                                                          : (pGPIOx == GPIOG)   ? RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN
                                                          : (pGPIOx == GPIOH)   ? RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN
                                                                                : 0;
}

void Rcc::EnablePeripheral(TIM_TypeDef *pTIMx)
{
    (pTIMx == TIM1) ? RCC->APB2ENR |= RCC_APB2ENR_TIM1EN : (pTIMx == TIM2) ? RCC->APB1ENR |= RCC_APB1ENR_TIM2EN
                                                                           : 0;
}

void Rcc::EnablePeripheral(USART_TypeDef *pUARTx)
{
    (pUARTx == USART1) ? RCC->APB2ENR |= RCC_APB2ENR_USART1EN : (pUARTx == USART2) ? RCC->APB1ENR |= RCC_APB1ENR_USART2EN
                                                            : (pUARTx == USART3)   ? RCC->APB1ENR |= RCC_APB1ENR_USART3EN
                                                            : (pUARTx == UART4)    ? RCC->APB1ENR |= RCC_APB1ENR_UART4EN
                                                            : (pUARTx == UART5)    ? RCC->APB1ENR |= RCC_APB1ENR_UART5EN
                                                            : (pUARTx == USART6)   ? RCC->APB2ENR |= RCC_APB2ENR_USART6EN
                                                                                   : 0;
}