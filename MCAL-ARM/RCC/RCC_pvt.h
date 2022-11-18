/*
 * RCC_pvt.h
 *
 *  Created on: Oct 12, 2022
 *      Author: Magdy Adel
 */

#ifndef RCC_RCC_PVT_H_
#define RCC_RCC_PVT_H_




//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register: RCC
//-*-*-*-*-*-*-*-*-*-*-*

#define RCC_BASE				0x40021000UL //UL for it constant

typedef struct{
	volatile u32 CR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 APB2RSTR;
	volatile u32 APB1RSTR;
	volatile u32 AHBENR;
	volatile u32 APB2ENR;
	volatile u32 APB1ENR;
	volatile u32 BDCR;
	volatile u32 CSR;
}RCC_TypeDef;

#define RCC						((RCC_TypeDef *)RCC_BASE)
//-------------------------end-----------------------------


/* Clock Types */
#define RCC_HSE_CRYSTAL			0
#define RCC_HSE_RC				1
#define RCC_HSI					2
#define RCC_PLL					3

/* PLL Options */
#define RCC_PLL_IN_HSI_DIV_2	0
#define RCC_PLL_IN_HSE_DIV_2	1
#define RCC_PLL_IN_HSE			2

/* PLL MUL factor options */
#define RCC_PLL_MUL_VAL_x_2		0
#define RCC_PLL_MUL_VAL_x_3		1
#define RCC_PLL_MUL_VAL_x_4		2
#define RCC_PLL_MUL_VAL_x_5		3
#define RCC_PLL_MUL_VAL_x_6		4
#define RCC_PLL_MUL_VAL_x_7		5
#define RCC_PLL_MUL_VAL_x_8		6
#define RCC_PLL_MUL_VAL_x_9		7
#define RCC_PLL_MUL_VAL_x_10	8
#define RCC_PLL_MUL_VAL_x_11	9
#define RCC_PLL_MUL_VAL_x_12	10
#define RCC_PLL_MUL_VAL_x_13	11
#define RCC_PLL_MUL_VAL_x_14	12
#define RCC_PLL_MUL_VAL_x_15	13
#define RCC_PLL_MUL_VAL_x_16	14
#define RCC_PLL_MUL_VAL_x_16_	15

#endif /* RCC_RCC_PVT_H_ */
