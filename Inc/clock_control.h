#include "memory.h"
#include <cstdint>
class ClockControl {
public: 
    enum Timers {
        TIM00, TIM01, TIM02, TIM03, TIM04, 
        TIM05, TIM06, TIM07, TIM08, TIM09, 
        TIM10, TIM11, TIM12, TIM13, TIM14, 
    };
    explicit ClockControl();
    ClockControl& enable_timer(Timers timer);
    ClockControl& enable_sys_config_ctrl();
private:
    struct RCCRegisters {
        volatile std::uint32_t RCC_CR;
        volatile std::uint32_t RCC_PLLCFGR;
        volatile std::uint32_t RCC_CFGR;
        volatile std::uint32_t RCC_CIR;

        volatile std::uint32_t RCC_AHB1RSTR;
        volatile std::uint32_t RCC_AHB2RSTR;
        volatile std::uint32_t RCC_AHB3RSTR;
        std::uint32_t RESERVED0;

        volatile std::uint32_t RCC_APB1RSTR;
        volatile std::uint32_t RCC_APB2RSTR;
        std::uint32_t RESERVED1;
        std::uint32_t RESERVED2;

        volatile std::uint32_t RCC_AHB1ENR;
        volatile std::uint32_t RCC_AHB2ENR;
        volatile std::uint32_t RCC_AHB3ENR;
        std::uint32_t RESERVED3;

        volatile std::uint32_t RCC_APB1ENR;
        volatile std::uint32_t RCC_APB2ENR;
        std::uint32_t RESERVED4;
        std::uint32_t RESERVED5;

        volatile std::uint32_t RCC_AHB1LPENR;
        volatile std::uint32_t RCC_AHB2LPENR;
        volatile std::uint32_t RCC_AHB3LPENR;
        std::uint32_t RESERVED6;

        volatile std::uint32_t RCC_APB1LPENR;
        volatile std::uint32_t RCC_APB2LPENR;
        std::uint32_t RESERVED7;
        std::uint32_t RESERVED8;

        volatile std::uint32_t RCC_BDCR;
        volatile std::uint32_t RCC_CSR;
        std::uint32_t RESERVED9;
        std::uint32_t RESERVED10;

        volatile std::uint32_t RCC_SSCGR;
        volatile std::uint32_t RCC_PLLI2SCFGR;
    };
    volatile RCCRegisters* const registers;
};