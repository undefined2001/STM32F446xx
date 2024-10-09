#include "gpio.hpp"

using namespace hardware;

Pin::Pin(GPIO_TypeDef *pGPIO, Pins pin) : m_pGPIO(pGPIO), m_Pin(static_cast<uint32_t>(pin)) {}

Pin Pin::New(GPIO_TypeDef *pGPIO, Pins pin)
{
    return Pin(pGPIO, pin);
}

void Pin::setMode(Mode mode)
{
    m_pGPIO->MODER &= ~(3U << (2 * m_Pin));                         // Clearing the Bit Field
    m_pGPIO->MODER |= (static_cast<uint32_t>(mode) << (2 * m_Pin)); // Configuring the bit field
}

void Pin::setPupd(Pupd pupd)
{
    m_pGPIO->PUPDR &= ~(3U << (2 * m_Pin));                         // Clearing the Bit Field
    m_pGPIO->PUPDR |= (static_cast<uint32_t>(pupd) << (2 * m_Pin)); // Configuring the bit field
}

int Pin::Value()
{
    return ((m_pGPIO->IDR >> m_Pin) & 1U);
}

void Pin::Value(uint32_t value)
{
    if (value == State::LOW)
    {
        m_pGPIO->BSRR |= (1U << (16 + m_Pin));
    }
    else
    {
        m_pGPIO->BSRR |= (1U << m_Pin);
    }
}


void Pin::EnablePORT(GPIO_TypeDef *pGPIO)
{
    (pGPIO == GPIOA) ? RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN : (pGPIO == GPIOB) ? RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN
                                                         : (pGPIO == GPIOC)   ? RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN
                                                         : (pGPIO == GPIOD)   ? RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN
                                                         : (pGPIO == GPIOE)   ? RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN
                                                         : (pGPIO == GPIOF)   ? RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN
                                                         : (pGPIO == GPIOG)   ? RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN
                                                         : (pGPIO == GPIOH)   ? RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN
                                                                              : 0;
}