#include "gpio.hpp"

using namespace hardware;

Pin::Pin(GPIO_TypeDef *pGPIO, Pins pin) : m_pGPIO(pGPIO), m_Pin(static_cast<uint32_t>(pin)) {}

Pin Pin::New(GPIO_TypeDef *pGPIO, Pins pin)
{
    return Pin(pGPIO, pin);
}

void Pin::setMode(Mode mode)
{
    uint32_t _m = static_cast<uint32_t>(mode);
    m_pGPIO->MODER &= ~(3U << (2 * m_Pin)); // Clearing the Bit Field
    m_pGPIO->MODER |= (_m << (2 * m_Pin));  // Configuring the bit field
}

void Pin::Value(State value)
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
