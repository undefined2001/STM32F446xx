#include "uart.hpp"

using namespace hardware;

Uart::Uart(USART_TypeDef *pUARTx) : m_pUARTx(pUARTx) {}

Uart Uart::New(USART_TypeDef *pUARTx)
{
    return Uart(pUARTx);
}

void Uart::WaitToSent()
{
    while (!(m_pUARTx->SR & USART_SR_TXE))
        ;
}

void Uart::init(Mode mode, BaudRate br)
{
    Disable(); // Disabling Uart Peripheral to Configure
    if (mode == Mode::TX_ONLY)
    {
        m_pUARTx->CR1 |= USART_CR1_TE;
    }
    else if (mode == Mode::RX_ONLY)
    {
        m_pUARTx->CR1 |= USART_CR1_RE;
    }
    else if (mode == Mode::BOTH)
    {
        m_pUARTx->CR1 |= USART_CR1_TE | USART_CR1_TE;
    }

    uint32_t uart_div = 16000000UL / static_cast<uint32_t>(br);

    USART2->BRR = ((uart_div / 16) << USART_BRR_DIV_Mantissa_Pos) | ((uart_div % 16) << USART_BRR_DIV_Fraction_Pos);

    Enable();
}

void Uart::Enable()
{
    m_pUARTx->CR1 |= USART_CR1_UE;
}

void Uart::Disable()
{
    m_pUARTx->CR1 &= ~USART_CR1_UE;
}

/**
 * @param: format : Formated String
 * @note: blocking API
 */
void Uart::print(const char *format, ...)
{
    char buffer[255];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);
    SendBuffer(buffer);
}

void Uart::SendBuffer(const char *buffer)
{
    while (*buffer)
    {
        WaitToSent();
        m_pUARTx->DR = *buffer;
        buffer++;
    }
}
