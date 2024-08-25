#include "nvic.h"
#include "memory.h"

NVIC::NVIC():
    iser {reinterpret_cast<uint32_t*>(CortexM4::NVIC_ISER)},
    icer {reinterpret_cast<uint32_t*>(CortexM4::NVIC_ICER)},
    ipr {reinterpret_cast<uint32_t*>(CortexM4::NVIC_IPR)}
{};

NVIC& NVIC::enable_irq(NVIC::IRQ irq) {
	std::uint8_t indent = irq / 32 * 4;
	std::uint32_t * reg = reinterpret_cast<uint32_t*>(CortexM4::NVIC_ISER + indent);
	*reg |= (1<<(irq % 32));
//    (*this->iser)[irq / 32] |= (1<<(irq % 32));

    return *this;
};

NVIC& NVIC::disable_irq(NVIC::IRQ irq) {
	std::uint8_t indent = irq / 32 * 4;
	std::uint32_t * reg = reinterpret_cast<uint32_t*>(CortexM4::NVIC_ICER + indent);
	*reg |= (1<<(irq % 32));
//    *this->icer[irq / 32] |= (1<<(irq % 32));

    return *this;
};

NVIC& NVIC::set_priority(NVIC::IRQ irq, std::uint8_t priority) {
    // std::uint8_t iptx = irq / 4;
    std::uint8_t iptx_section = irq % 4;
    *this->ipr[irq / 4] |= (priority<<(iptx_section * 8));

    return *this;
};
