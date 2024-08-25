/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include "periph.h"
#include <cstdint>
#include "sys_config.h"
#include "clock_control.h"
#include "nvic.h"
#include "ext_interrupt.h"
//#include "stm32f4xx.h"

void sleep(uint32_t time) {
	for (volatile uint32_t i = 0 ; i < time; i++);
}

GPIO port_b (STM_GPIO::GPIO_B);
GPIO port_d (STM_GPIO::GPIO_D);
SysConfig sysCfg = SysConfig();
ClockControl clockCtrl = ClockControl();
NVIC nvic = NVIC();
ExtInterrupt extInt = ExtInterrupt();

extern "C" void EXTI15_10_IRQHandler(void) {
//	GPIO port_dD (STM_GPIO::GPIO_D);
	sleep(2000);
	extInt.clear_pending(ExtInterrupt::Line12);
	port_d.toggle_pin(STM_GPIO::Pin15);
}

int main(void) {


	port_d.set_as_output(STM_GPIO::Pin15);
	port_b.set_as_input(STM_GPIO::Pin12).pull_up(STM_GPIO::Pin12);

    clockCtrl.enable_sys_config_ctrl();
    sysCfg.assign_interrupt(STM_GPIO::GPIO_B, STM_GPIO::Pin12);
	nvic.enable_irq(NVIC::EXTI15_10);
//	nvic.set_priority(NVIC::EXTI15_10, 26);
	extInt.enable(ExtInterrupt::Line12).set_falling_trigger(ExtInterrupt::Line12);


    /* Loop forever */
	for(;;) {
 		// if (!port_b.is_set(STM_GPIO::Pin12)) {
		// 	port_d.toggle_pin(STM_GPIO::Pin15);
		// 	sleep(300000);
		// } else {
		// 	port_d.clear_pin(STM_GPIO::Pin15);
		// }
	}
}
