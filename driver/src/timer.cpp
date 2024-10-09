#include "timer.hpp"

using namespace hardware;

Timer::Timer(TIM_TypeDef *pTIMx) : m_pTIMx(pTIMx) {};

Timer Timer::New(TIM_TypeDef *pTIMx)
{
    return Timer(pTIMx);
}

TIM_TypeDef *Timer::getTIMx()
{
    return m_pTIMx;
}

void Timer::setPreScaler(uint32_t presc)
{
    m_pTIMx->PSC = --presc;
}

void Timer::setAutoReload(uint32_t arr)
{
    m_pTIMx->ARR = --arr;
}

void Timer::Enable()
{
    m_pTIMx->CR1 |= TIM_CR1_CEN;
}

void Timer::Disable()
{
    m_pTIMx->CR1 &= ~TIM_CR1_CEN;
}

Timer::~Timer() {}