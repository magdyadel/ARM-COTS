/*
 * RCC_prg.c
 *
 *  Created on: Oct 12, 2022
 *      Author: Magdy Adel
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "RCC_int.h"
#include "RCC_pvt.h"
#include "RCC_cfg.h"

void MCAL_RCC_vInit(void)
{

	/* HSE settings */
	#if RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		RCC->CR= 0X00010000; /* Enable HSE with no Bypass */
		RCC->CFGR = 0x00000001; /* Select HSE as clock source */

	#elif RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC->CR   = 0X00050000; /* Enable HSE with  Bypass */
		RCC->CFGR = 0x00000001; /* Select HSE as clock source */

	/* HSI settings */
	#elif RCC_CLOCK_TYPE == RCC_HSI
		//RCC->CR   = 0x00000081; /* Enable HSI + Trimming = 0 */
		//RCC->CFGR = 0x00000000; /* Select HSI as clock source */
		RCC->CR   = 0x00000081; /* Enable HSI + Trimming = 0 */
		RCC->CFGR = 0x00000000; /* Select HSI as clock source */

	#elif RCC_CLOCK_TYPE == RCC_PLL
		#if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
			RCC->CFGR  = 0x00000002; /* Select PLL as System Clock + HSI/2 */
			RCC->CFGR |= (RCC_PLL_MUL_VAL << 18); /* RCC Multiplication factor */
			RCC->CR   |= 0x01000081; /* Enable HSI + Trimming = 0 + PLL ON */
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
			RCC->CFGR  = 0x00030002; /* Select HSE as System Clock + HSE/2 */
			RCC->CFGR |= (RCC_PLL_MUL_VAL << 18); /* RCC Multiplication factor */
			RCC->CR    = 0x01010080; /* Enable HSE + Trimming = 0 + PLL ON */
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
			RCC->CFGR  = 0x00010002; /* Select PLL as System Clock + HSE not divided */
			RCC->CFGR |= (RCC_PLL_MUL_VAL << 18); /* RCC Multiplication factor */
			RCC->CR    = 0x01010080; /* Enable HSE + Trimming = 0 + PLL ON */
		#endif
		/* other settings */
		// - CSS ON ?
		// - MCO ?
		// - AHB, APB1, APB2 Prescalers ?
		// - ADC_Prescaler ?

		/* SYSCLK settings */
		// - System Clock switch bits: HSI/HSE/PLL
	#else
		#error("You have chosen wrong clock type")
	#endif

}

void MCAL_RCC_vDisableAllInterrupt(void)
{
	/* Disable all interrupts and clear pending bits  */
	RCC->CIR = 0x009F0000;
}
void MCAL_RCC_vEnHSIInterrupt(void)
{
	/* Enable HSI interrupts and clear pending bits  */
	RCC->CIR = 0x009F0400;
}

void MCAL_RCC_vEnableClk(u16 A_u16PeripheralID,u8 A_u8BusID)
{
	if(A_u16PeripheralID <= 31)
	{
		switch (A_u8BusID)
		{
			case RCC_AHB  : SET_BIT(RCC->AHBENR,A_u16PeripheralID);
				break;
			case RCC_APB1 : SET_BIT(RCC->APB1ENR,A_u16PeripheralID);
				break;
			case RCC_APB2 : SET_BIT(RCC->APB2ENR,A_u16PeripheralID);
				break;
			//default       : /* return Error ; */ break;
		}
	}else{/* return Error ; */}
}

void MCAL_RCC_vDisableClk(u16 A_u16PeripheralID,u8 A_u8BusID)
{
	if(A_u16PeripheralID <= 31)
	{
		switch (A_u8BusID)
		{
			case RCC_AHB  : CLR_BIT(RCC->AHBENR,A_u16PeripheralID);
				break;
			case RCC_APB1 : CLR_BIT(RCC->APB1ENR,A_u16PeripheralID);
				break;
			case RCC_APB2 : CLR_BIT(RCC->APB2ENR,A_u16PeripheralID);
				break;
			//default       : /* return Error ; */ break;
		}
	}else{/* return Error ; */}
}


void MCAL_RCC_vRESET( u16 A_u16PeripheralID,u8 A_u8BusID)
{
	if(A_u16PeripheralID <= 31)
		{
			switch (A_u8BusID)
			{
				case RCC_AHB  : break;
				case RCC_APB1 : SET_BIT(RCC->APB1RSTR,A_u16PeripheralID);
					break;
				case RCC_APB2 : SET_BIT(RCC->APB2RSTR,A_u16PeripheralID);
					break;
				//default       : /* return Error ; */ break;
			}
		}else{/* return Error ; */}
}
