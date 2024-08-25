#include "periph.h"

constexpr uint32_t* memory32(uint32_t address) {
	return reinterpret_cast<uint32_t*>(address);
}

GPIO::GPIO(STM_GPIO::Port dev):
	ID 				{dev},
	registers		{reinterpret_cast<Registers*>(STM32F407_GPIO::device_addr(dev))}
{
	STM32F407_GPIO::enable_device(ID);
}
GPIO::~GPIO() {
	STM32F407_GPIO::disable_device(ID);
}
GPIO& GPIO::set_as_output(STM_GPIO::Pin pin) {
	registers->mode |= (0x01 << pin * 2);
	return *this;
}

GPIO& GPIO::set_as_input(STM_GPIO::Pin pin) {
	registers->mode &= (~0x03 << pin * 2);
	return *this;
}

GPIO& GPIO::set_pin(STM_GPIO::Pin pin) {
	registers->output_data |= (0x01 << pin);
	return *this;
}

GPIO& GPIO::clear_pin(STM_GPIO::Pin pin) {
	registers->output_data &= ~(0x01 << pin);
	return *this;
}
GPIO& GPIO::disable_pull(STM_GPIO::Pin pin) {
	registers->pull_up_down &= ~(0x03 << pin * 2);
	return *this;
}
GPIO& GPIO::pull_up(STM_GPIO::Pin pin) {
	this->disable_pull(pin);
	registers->pull_up_down |=  (0x01 << pin * 2);
	return *this;
}
GPIO& GPIO::pull_down(STM_GPIO::Pin pin) {
	this->disable_pull(pin);
	registers->pull_up_down |=  (0x02 << pin * 2);
	return *this;
}

bool GPIO::is_set(STM_GPIO::Pin pin) {
	return registers->input_data & (1<<pin);
}

GPIO& GPIO::toggle_pin(STM_GPIO::Pin pin) {
	if (this->is_set(pin)) {
		this->clear_pin(pin);
	} else {
		this->set_pin(pin);
	}
	return *this;
}

