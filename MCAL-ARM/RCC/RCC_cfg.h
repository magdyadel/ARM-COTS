/*
 * RCC_cfg.h
 *
 *  Created on: Oct 12, 2022
 *      Author: Magdy Adel
 */

#ifndef RCC_RCC_CFG_H_
#define RCC_RCC_CFG_H_

/*
	Options => {
			RCC_HSE_CRYSTAL
			RCC_HSE_RC
			RCC_HSI
			RCC_PLL
		}
*/
#define RCC_CLOCK_TYPE 		RCC_HSE_CRYSTAL

/* Note: Select PLL Value if you have PLL as input clock source */
#if RCC_CLOCK_TYPE == RCC_PLL

	/*
		Options:
				RCC_PLL_IN_HSI_DIV_2
				RCC_PLL_IN_HSE_DIV_2
				RCC_PLL_IN_HSE
	*/
	#define RCC_PLL_INPUT		RCC_PLL_IN_HSE_DIV_2

	/*
		Options:
				RCC_PLL_MUL_VAL_x_2
				RCC_PLL_MUL_VAL_x_3
				RCC_PLL_MUL_VAL_x_4
				RCC_PLL_MUL_VAL_x_5
				RCC_PLL_MUL_VAL_x_6
				RCC_PLL_MUL_VAL_x_7
				RCC_PLL_MUL_VAL_x_8
				RCC_PLL_MUL_VAL_x_9
				RCC_PLL_MUL_VAL_x_10
				RCC_PLL_MUL_VAL_x_11
				RCC_PLL_MUL_VAL_x_12
				RCC_PLL_MUL_VAL_x_13
				RCC_PLL_MUL_VAL_x_14
				RCC_PLL_MUL_VAL_x_15
				RCC_PLL_MUL_VAL_x_16
				RCC_PLL_MUL_VAL_x_16_
	*/
	#define RCC_PLL_MUL_VAL 	RCC_PLL_MUL_VAL_x_2

#endif


#endif /* RCC_RCC_CFG_H_ */
