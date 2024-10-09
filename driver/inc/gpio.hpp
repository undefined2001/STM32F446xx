#pragma once
#include "stm32f446xx.h"

namespace hardware
{
    class Pin
    {
    public:
        enum class Pins : uint32_t
        {
            PIN0 = 0,
            PIN1,
            PIN2,
            PIN3,
            PIN4,
            PIN5,
            PIN6,
            PIN7,
            PIN8,
            PIN9,
            PIN10,
            PIN11,
            PIN12,
            PIN13,
            PIN14,
            PIN15,
        };
        enum class Mode : uint32_t
        {
            INPUT = 0,
            OUTPUT,
            ALTFN,
            ANALOG
        };
        enum class Otype : uint32_t
        {
            PUSHPULL = 0,
            OPENDRAIN
        };
        enum class Ospeed : uint32_t
        {
            LOW = 0,
            MEDIUM,
            FAST,
            HIGH
        };
        enum class Pupd : uint32_t
        {
            NOPUPD = 0,
            PULLUP,
            PULLDOWN
        };
        enum class AF : uint32_t
        {

        };
        enum State : uint32_t
        {
            LOW = 0,
            HIGH
        };

    private:
        GPIO_TypeDef *m_pGPIO;
        uint32_t m_Pin;
        Pin(GPIO_TypeDef *pGPIO, Pins pin);

    public:
        static Pin New(GPIO_TypeDef *pGPIO, Pins pin);
        static void EnablePORT(GPIO_TypeDef *pGPIO);
        void setMode(Mode mode);
        void setPupd(Pupd pupd);
        void Value(uint32_t value);
        int Value();
    };

} // namespace hardware
