/*
 * preriph.h
 *
 *  Created on: Aug 19, 2024
 *      Author: Valerii_Pavlov
 */

#include <cstdint>

#ifndef PERIPH_H_
#define PERIPH_H_

#define PERIPH_BASE         0x40000000U
#define APB1PERIPH_BASE     PERIPH_BASE
#define APB2PERIPH_BASE     0x40010000U
#define AHB1PERIPH_BASE     0x40020000U
#define AHB2PERIPH_BASE     0x50000000U


//constexpr uint32_t* memory32(uint32_t address);

namespace STM_GPIO {
	enum Port {
		GPIO_A, GPIO_B, GPIO_C, GPIO_D, GPIO_E, GPIO_F, GPIO_G, GPIO_H, GPIO_I
	};
	enum Pin {
		Pin00, Pin01, Pin02, Pin03,
		Pin04, Pin05, Pin06, Pin07,
		Pin08, Pin09, Pin10, Pin11,
		Pin12, Pin13, Pin14, Pin15,
	};
};

namespace STM32F407_GPIO {
	auto const enable_reg = reinterpret_cast<uint32_t*>(AHB1PERIPH_BASE + 0x3830);

	constexpr uint32_t base_addr = AHB1PERIPH_BASE;

	inline void enable_device(STM_GPIO::Port dev) {
		*enable_reg |= (1<< dev);
	}

	inline void disable_device(STM_GPIO::Port dev) {
		*enable_reg &= ~(1<< dev);
	}

	inline constexpr uint32_t device_addr(STM_GPIO::Port dev) {
		return base_addr + (dev * 0x400);
	}
};

class GPIO {
public:
	explicit GPIO(STM_GPIO::Port id);
	~GPIO();

	GPIO(const GPIO&)            = delete;
	GPIO(GPIO&&)                 = delete;
	GPIO& operator=(const GPIO&) = delete;
	GPIO& operator=(GPIO&&)      = delete;

	void direction(uint32_t bitmask);

	GPIO& operator = (uint32_t bitmask);

	GPIO& operator &= (uint32_t bitmask);
	GPIO& operator |= (uint32_t bitmask);

	GPIO& set_as_input(STM_GPIO::Pin pin);
	GPIO& set_as_output(STM_GPIO::Pin pin);
	GPIO& set_pin(STM_GPIO::Pin pin);
	GPIO& clear_pin(STM_GPIO::Pin pin);
	GPIO& toggle_pin(STM_GPIO::Pin pin);
	GPIO& pull_up(STM_GPIO::Pin pin);
	GPIO& pull_down(STM_GPIO::Pin pin);
	GPIO& disable_pull(STM_GPIO::Pin pin);
	bool is_set(STM_GPIO::Pin pin);
private:
	STM_GPIO::Port ID;

	struct Registers {
		uint32_t mode;
		uint32_t type;
		uint32_t speed;
		uint32_t pull_up_down;
		uint32_t input_data;
		uint32_t output_data;
		uint32_t set_reset;
		uint32_t lock;
		uint32_t alt_fn_low;
		uint32_t alt_fn_high;
	};

	volatile Registers* const registers;
};

#endif /* PERIPH_H_ */
