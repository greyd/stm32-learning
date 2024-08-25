/*
 * ext_interrupt.cpp
 *
 *  Created on: Aug 20, 2024
 *      Author: Valerii_Pavlov
 */

#include "ext_interrupt.h"

ExtInterrupt::ExtInterrupt():
	registers {reinterpret_cast<Registers*>(STM32F407::EXTI)}
	{};

ExtInterrupt& ExtInterrupt::clear_falling_trigger(ExtInterrupt::Line line) {
	this->registers->ftsr &= ~(1 << line);
	return *this;
}
ExtInterrupt& ExtInterrupt::clear_rising_trigger(ExtInterrupt::Line line) {
	this->registers->rtsr &= ~(1 << line);
	return *this;
}

ExtInterrupt& ExtInterrupt::set_falling_trigger(ExtInterrupt::Line line) {
	this->registers->ftsr |= (1 << line);
	this->clear_rising_trigger(line);
	return *this;
}
ExtInterrupt& ExtInterrupt::set_rising_trigger(ExtInterrupt::Line line) {
	this->registers->rtsr |= (1 << line);
	this->clear_falling_trigger(line);
	return *this;
}

ExtInterrupt& ExtInterrupt::enable(ExtInterrupt::Line line) {
	this->registers->imr |= (1 << line);
	return *this;
}
ExtInterrupt& ExtInterrupt::disable(ExtInterrupt::Line line) {
	this->registers->imr &= ~(1 << line);
	return *this;
}
ExtInterrupt& ExtInterrupt::clear_pending(ExtInterrupt::Line line) {
	this->registers->pr |= (1 << line);
	return *this;
}
