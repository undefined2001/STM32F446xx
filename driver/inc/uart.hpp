#pragma once
#include "stm32f446xx.h"
#include <cstdarg>
#include <cstdio>

namespace hardware
{
    class Uart
    {
    private:
        USART_TypeDef *m_pUARTx;
        Uart(USART_TypeDef *pUSARTx);
        void SendBuffer(const char *buffer);
        void WaitToSent();
        void WaitToReceive();
        void Enable();
        void Disable();

    public:
        enum class Mode : uint32_t
        {
            TX_ONLY = 0,
            RX_ONLY,
            BOTH
        };
        enum class BaudRate : uint32_t
        {
            BR9600 = 9600,
            BR115200 = 115200
        };
        static Uart
        New(USART_TypeDef *pUARTx);
        void init(Mode mode, BaudRate br);
        void print(const char *fromat, ...);
    };
}