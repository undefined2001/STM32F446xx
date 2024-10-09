#pragma once
#include "stm32f446xx.h"

namespace hardware
{
    class Timer
    {
    private:
        TIM_TypeDef *m_pTIMx; // Pointer to the TIM peripheral

    public:
        ~Timer(); // Destructor to clean up if needed
        static Timer New(TIM_TypeDef *pTIMx);
        TIM_TypeDef *getTIMx();                    // Get the TIM peripheral
        void setPreScaler(uint32_t presc);         // Set the prescaler
        void setAutoReload(uint32_t arr);          // Set the auto-reload register
        void start();                              // Start the timer
        void stop();                               // Stop the timer
        void reset();                              // Reset timer configurations
        void setMode(uint32_t mode);               // Set timer mode (e.g., up/down counting, PWM)
        void registerCallback(void (*callback)()); // Register a callback for interrupts

    private:
        Timer(TIM_TypeDef *timx);  // Constructor to initialize the timer
        void configureClock();     // Internal method to configure the clock
        void clearConfiguration(); // Clear previous configuratio
        void Enable();             // Enable the timer
        void Disable();            // Disable the timern
        void (*m_callback)();      // Pointer to the callback function
    };

    // Implementation would go here (e.g., in Timer.cpp)
} // namespace hardware
