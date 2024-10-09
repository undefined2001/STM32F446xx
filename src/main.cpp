#include "stm32f446xx.h"
#include "gpio.hpp"
#include "timer.hpp"
#include "rcc.hpp"
#include "uart.hpp"

using core::Rcc;
using hardware::Pin;
using hardware::Timer;
using hardware::Uart;

Uart uart2 = Uart::New(USART2);

Pin tx = Pin::New(GPIOA, Pin::Pins::PIN2);

Pin led = Pin::New(GPIOA, Pin::Pins::PIN5);
Pin btn = Pin::New(GPIOC, Pin::Pins::PIN13);

int main()
{
    Rcc::EnablePeripheral(GPIOA);
    Rcc::EnablePeripheral(GPIOC);
    Rcc::EnablePeripheral(USART2);

    uart2.init(Uart::Mode::BOTH, Uart::BaudRate::BR115200);

    tx.setMode(Pin::Mode::ALTFN);
    GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR2;
    GPIOA->AFR[0] |= 7 << GPIO_AFRL_AFSEL2_Pos;

    led.setMode(Pin::Mode::OUTPUT);
    btn.setMode(Pin::Mode::INPUT);
    btn.setPupd(Pin::Pupd::PULLUP);

    const char *buffer = "Hello, World!\n";

    int i = 0;

    while (true)
    {

        uart2.print("Number is :%d\n", i);
        for (int i = 0; i < 5000000; i++)
            ;
        i++;
    }

    return 0;
}