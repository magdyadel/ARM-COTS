/*
 * USART_pvt.h
 *
 *  Created on: Nov 13, 2022
 *      Author: Magdy Adel
 */

#ifndef MCAL_ARM_USART_USART_PVT_H_
#define MCAL_ARM_USART_USART_PVT_H_


//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register: USART
//-*-*-*-*-*-*-*-*-*-*-*

//APB2-BUS
#define USART1_Base			0x40013800UL
//APB1-BUS
#define USART2_Base			0x40004400UL
#define USART3_Base			0x40004800UL

typedef struct{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;
}USART_TypeDef;

#define USART1				((USART_TypeDef *)USART1_Base)
#define USART2				((USART_TypeDef *)USART2_Base)
#define USART3				((USART_TypeDef *)USART3_Base)




#endif /* MCAL_ARM_USART_USART_PVT_H_ */
