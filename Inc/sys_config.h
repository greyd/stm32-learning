#include <cstdint>
#include "memory.h"
#include "periph.h"

class SysConfig {
public:
    explicit SysConfig();
    SysConfig& assign_interrupt(STM_GPIO::Port port, STM_GPIO::Pin pin);
private:
    struct SysConfigRegisters {
        volatile std::uint32_t MEMRMP;
        volatile std::uint32_t PMC;
        volatile std::uint32_t EXTICR[4];
        // volatile std::uint32_t EXTICR2;
        // volatile std::uint32_t EXTICR3;
        // volatile std::uint32_t EXTICR4;
        std::uint32_t RESERVED0[2];
        volatile std::uint32_t CMPCR;
        std::uint32_t RESERVED1[2];
        volatile std::uint32_t CFGR;
    };

    volatile SysConfigRegisters * const registers;
};