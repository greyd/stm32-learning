/*
 * memory.h
 *
 *  Created on: Aug 20, 2024
 *      Author: Valerii_Pavlov
 */

#ifndef MEMORY_H_
#define MEMORY_H_
#include <cstdint>

namespace STM32F407_IRQ {
	enum IRQ {
		WWDG, PVD, TAMP_STAMP, RTC_WKUP, FLASH, RCC, EXTI0, EXTI1, EXTI2, EXTI3, EXTI4,
		DMA1_Stream0, DMA1_Stream1, DMA1_Stream2, DMA1_Stream3, DMA1_Stream4, DMA1_Stream5, DMA1_Stream6,
		ADC, CAN1_TX, CAN1_RX0, CAN1_RX1, CAN1_SCE, EXTI9_5, TIM1_BRK_TIM9, TIM1_UP_TIM10, TIM1_TRG_COM_TIM11,
		TIM1_CC, TIM2, TIM3, TIM4, I2C1_EV, I2C1_ER, I2C2_EV, I2C2_ER, SPI1, SPI2, USART1, USART2, USART3,
		EXTI15_10, RTC_Alarm, OTG_FS_WKUP, TIM8_BRK_TIM12, TIM8_UP_TIM13, TIM8_TRG_COM_TIM14, TIM8_CC, DMA1_Stream7,
		FSMC, SDIO, TIM5, SPI3, UART4, UART5, TIM6_DAC, TIM7, DMA2_Stream0, DMA2_Stream1, DMA2_Stream2, DMA2_Stream3,
		DMA2_Stream4, ETH, ETH_WKUP, CAN2_TX, CAN2_RX0, CAN2_RX1, CAN2_SCE, OTG_FS, DMA2_Stream5, DMA2_Stream6, DMA2_Stream7,
		USART6, I2C3_EV, I2C3_ER, OTG_HS_EP1_OUT, OTG_HS_EP1_IN, OTG_HS_WKUP, OTG_HS, DCMI, CRYP, HASH_RNG, FPU
	};
}

namespace CortexM4 {
	constexpr std::uint32_t NVIC_ISER = 0xE000E100;
	constexpr std::uint32_t NVIC_ICER = 0xE000E180;
	constexpr std::uint32_t NVIC_IPR = 0xE000E400;
}

namespace STM32F407 {
	constexpr std::uint32_t APB1_BUS 		= 0x40000000;
	constexpr std::uint32_t APB2_BUS 		= 0x40010000;

	constexpr std::uint32_t AHB1_BUS 		= 0x40020000;
	constexpr std::uint32_t AHB2_BUS 		= 0x50000000;
	constexpr std::uint32_t AHB3_BUS 		= 0xA0000000;

	constexpr std::uint32_t TIM2       	   = APB1_BUS + 0x0000;
	constexpr std::uint32_t TIM3           = APB1_BUS + 0x0400;
	constexpr std::uint32_t TIM4           = APB1_BUS + 0x0800;
	constexpr std::uint32_t TIM5           = APB1_BUS + 0x0C00;
	constexpr std::uint32_t TIM6           = APB1_BUS + 0x1000;
	constexpr std::uint32_t TIM7           = APB1_BUS + 0x1400;
	constexpr std::uint32_t TIM12          = APB1_BUS + 0x1800;
	constexpr std::uint32_t TIM13          = APB1_BUS + 0x1C00;
	constexpr std::uint32_t TIM14          = APB1_BUS + 0x2000;
	constexpr std::uint32_t RTC            = APB1_BUS + 0x2800;
	constexpr std::uint32_t WWDG           = APB1_BUS + 0x2C00;
	constexpr std::uint32_t IWDG           = APB1_BUS + 0x3000;
	constexpr std::uint32_t I2S2ext        = APB1_BUS + 0x3400;
	constexpr std::uint32_t SPI2_I2S2      = APB1_BUS + 0x3800;
	constexpr std::uint32_t SPI3_I2S3      = APB1_BUS + 0x3C00;
	constexpr std::uint32_t I2S3ext        = APB1_BUS + 0x4000;
	constexpr std::uint32_t USART2         = APB1_BUS + 0x4400;
	constexpr std::uint32_t USART3         = APB1_BUS + 0x4800;
	constexpr std::uint32_t UART4          = APB1_BUS + 0x4C00;
	constexpr std::uint32_t UART5          = APB1_BUS + 0x5000;
	constexpr std::uint32_t I2C1           = APB1_BUS + 0x5400;
	constexpr std::uint32_t I2C2           = APB1_BUS + 0x5800;
	constexpr std::uint32_t I2C3           = APB1_BUS + 0x5C00;
	constexpr std::uint32_t CAN1           = APB1_BUS + 0x6400;
	constexpr std::uint32_t CAN2           = APB1_BUS + 0x6800;
	constexpr std::uint32_t PWR            = APB1_BUS + 0x7000;
	constexpr std::uint32_t DAC            = APB1_BUS + 0x7400;
	constexpr std::uint32_t UART7          = APB1_BUS + 0x7800;
	constexpr std::uint32_t UART8          = APB1_BUS + 0x7C00;

	constexpr std::uint32_t TIM1           = APB2_BUS + 0x0000;
	constexpr std::uint32_t TIM8           = APB2_BUS + 0x0400;
	constexpr std::uint32_t USART1         = APB2_BUS + 0x1000;
	constexpr std::uint32_t USART6         = APB2_BUS + 0x1400;
	constexpr std::uint32_t ADC            = APB2_BUS + 0x2000;
	constexpr std::uint32_t SDIO           = APB2_BUS + 0x2C00;
	constexpr std::uint32_t SPI1           = APB2_BUS + 0x3000;
	constexpr std::uint32_t SPI4           = APB2_BUS + 0x3400;
	constexpr std::uint32_t SYSCFG         = APB2_BUS + 0x3800;
	constexpr std::uint32_t EXTI           = APB2_BUS + 0x3C00;
	constexpr std::uint32_t TIM9           = APB2_BUS + 0x4000;
	constexpr std::uint32_t TIM10          = APB2_BUS + 0x4400;
	constexpr std::uint32_t TIM11          = APB2_BUS + 0x4800;
	constexpr std::uint32_t SPI5           = APB2_BUS + 0x5000;
	constexpr std::uint32_t SPI6           = APB2_BUS + 0x5400;
	constexpr std::uint32_t SAI1           = APB2_BUS + 0x5800;
	constexpr std::uint32_t LCD_TFT        = APB2_BUS + 0x6800;


	constexpr std::uint32_t GPIOA          = AHB1_BUS + 0x0000;
	constexpr std::uint32_t GPIOB          = AHB1_BUS + 0x0400;
	constexpr std::uint32_t GPIOC          = AHB1_BUS + 0x0800;
	constexpr std::uint32_t GPIOD          = AHB1_BUS + 0x0C00;
	constexpr std::uint32_t GPIOE          = AHB1_BUS + 0x1000;
	constexpr std::uint32_t GPIOF          = AHB1_BUS + 0x1400;
	constexpr std::uint32_t GPIOG          = AHB1_BUS + 0x1800;
	constexpr std::uint32_t GPIOH          = AHB1_BUS + 0x1C00;
	constexpr std::uint32_t GPIOI          = AHB1_BUS + 0x2000;
	constexpr std::uint32_t GPIOJ          = AHB1_BUS + 0x2400;
	constexpr std::uint32_t GPIOK          = AHB1_BUS + 0x2800;
	constexpr std::uint32_t CRC            = AHB1_BUS + 0x3000;
	constexpr std::uint32_t RCC            = AHB1_BUS + 0x3800;
	constexpr std::uint32_t FLASH          = AHB1_BUS + 0x3C00;
	constexpr std::uint32_t BKPSRAM        = AHB1_BUS + 0x4000;
	constexpr std::uint32_t DMA1	       = AHB1_BUS + 0x6000;
	constexpr std::uint32_t DMA2	       = AHB1_BUS + 0x6400;
	constexpr std::uint32_t ETHERNET_MAC   = AHB1_BUS + 0x8000;
	constexpr std::uint32_t DMA2D		   = AHB1_BUS + 0xB000;
	constexpr std::uint32_t USB_OTG_HS	   = AHB1_BUS + 0x40000;

	constexpr std::uint32_t USB_OTG_FS	   = AHB2_BUS + 0x00000;
	constexpr std::uint32_t DCMI		   = AHB2_BUS + 0x50000;
	constexpr std::uint32_t CRYP		   = AHB2_BUS + 0x60000;
	constexpr std::uint32_t HASH		   = AHB2_BUS + 0x60400;
	constexpr std::uint32_t RNG			   = AHB2_BUS + 0x60800;

	
};

#endif