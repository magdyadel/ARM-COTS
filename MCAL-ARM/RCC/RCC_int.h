/*
 * RCC_int.h
 *
 *  Created on: Oct 12, 2022
 *      Author: Magdy Adel
 */

#ifndef RCC_RCC_INT_H_
#define RCC_RCC_INT_H_

#ifdef __cplusplus // intrinsic macro
extern "C" {
#endif



/*
 *=======================================================================
 *						Macros Configuration References
 *=======================================================================
 *
*/
//BUS ID
#define RCC_AHB					0
#define RCC_APB1				1
#define RCC_APB2				2


//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*-
//Clock Enable GPIO
#define RCC_GPIOA_APB2			2
#define RCC_GPIOB_APB2			3
#define RCC_GPIOC_APB2			4
#define RCC_GPIOD_APB2			5
#define RCC_GPIOE_APB2			6

#define RCC_AFIO_APB2			0

//Clock Enable Timers
#define RCC_TIM1_APB2			0
#define RCC_TIM2_APB1			0
#define RCC_TIM3_APB1			1
#define RCC_TIM4_APB1			2
#define RCC_TIM5_APB1			2

//Clock Enable USART
#define RCC_USART1_APB2			14
#define RCC_USART2_APB1			17
#define RCC_USART3_APB1			18

//Clock Enable SPI
#define RCC_SPI1_APB2			12
#define RCC_SPI2_APB1			14

//Clock Enable I2C
#define RCC_I2C1_APB1			21
#define RCC_I2C2_APB1			22

//===================================================================================



/*
* ===================================================================================
* 						APIs Supported by "MCAL RCC DRIVER"
* ===================================================================================
*/

void MCAL_RCC_vInit(void);

void MCAL_RCC_vEnableClk(u16 A_u16PeripheralID,u8 A_u8BusID);

void MCAL_RCC_vDisableClk(u16 A_u16PeripheralID,u8 A_u8BusID);

void MCAL_RCC_vRESET(u16 A_u16PeripheralID , u8 A_u8BusID);

void MCAL_RCC_vDisableAllInterrupt(void);
void MCAL_RCC_vEnHSIInterrupt(void);

//===================================================================================



#ifdef __cplusplus
}
#endif

#endif /* RCC_RCC_INT_H_ */
