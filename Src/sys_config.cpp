#include "sys_config.h"

SysConfig::SysConfig(): registers {reinterpret_cast<SysConfigRegisters*>(STM32F407::SYSCFG)} {};

SysConfig& SysConfig::assign_interrupt(STM_GPIO::Port port, STM_GPIO::Pin pin) {
    this->registers->EXTICR[pin / 4] |= (port << (pin % 4));

    return *this;
}