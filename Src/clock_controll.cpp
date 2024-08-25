#include "clock_control.h"

ClockControl::ClockControl(): registers {reinterpret_cast<RCCRegisters*>(STM32F407::RCC)} {}
ClockControl& ClockControl::enable_sys_config_ctrl() {
    this->registers->RCC_APB2ENR |= (1 << 14);

    return *this;
}