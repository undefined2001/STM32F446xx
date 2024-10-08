#include "stm32f446xx.h"
#include "gpio.hpp"

using hardware::Pin;

Pin led = Pin::New(GPIOA, Pin::Pins::PIN5);

int main()
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    led.setMode(Pin::Mode::OUTPUT);

    while (true)
    {
        led.Value(Pin::State::HIGH);
        for (int i = 0; i < 200000; i++)
            ;
        led.Value(Pin::State::LOW);
        for (int i = 0; i < 200000; i++)
            ;
    }

    return 0;
}