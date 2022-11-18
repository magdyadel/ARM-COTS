/*
 * SERVO_prg.c
 *
 *  Created on: Nov 17, 2022
 *      Author: Magdy Adel
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL-ARM/GPIO/GPIO_int.h"
#include "../../MCAL-ARM/TIMERS/TIMERS_int.h"
#include "../../MCAL-ARM/RCC/RCC_int.h"
#include "SERVO_int.h"



static void PWM_Init()
{
    // Initialization struct
	TIMERx_Cfg_t timer2CFG;
    TIM_OCInitTypeDef TIM_OCInitStruct;


    // Step 1: Initialize TIM2
    MCAL_RCC_vEnableClk(RCC_TIM2_APB1,RCC_APB1);

    // Create 50Hz PWM
    // Prescale timer clock from 8MHz to 1MHz by prescaler = 100 ...8*10^6 / 8 = 10^6
    timer2CFG.Prescaler = 8;
    // TIM_Period = (timer_clock / PWM_frequency) - 1
    // TIM_Period = (1MHz / 50Hz) - 1 =19999
	/* Those Equations Sets The F_pwm = 50Hz & Maximizes The Resolution*/
//	PSC_Value = (uint32_t) (SERVO_CfgParam[au16_SERVO_Instance].TIM_CLK / 3276800.0);
//	ARR_Value = (uint32_t) ((SERVO_CfgParam[au16_SERVO_Instance].TIM_CLK / (50.0*(PSC_Value+1.0)))-1.0);
    timer2CFG.Period = 19999;
    timer2CFG.ClockDivision = TIM_CKD_DIV1;
    timer2CFG.CounterMode = TIM_CounterMode_Up;

    MCAL_TIMERx_vInit(TIMER2, &timer2CFG);
    // Start TIM2
    MCAL_TIMERx_vStart(TIMER2);

    // Step 2: Initialize PWM
    // Common PWM settings
    TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
    // We initialize PWM value with duty cycle of 0%
    TIM_OCInitStruct.TIM_Pulse = 0;
    MCAL_TIMERx_OC1Init(TIMER2, &TIM_OCInitStruct);
    MCAL_TIMERx_OC1PreloadConfig(TIMER2, TIM_OCPreload_Enable);

}

static void GPIO_Init(void)
{
	// Step 3: Initialize GPIOA (PA0)
	MCAL_RCC_vEnableClk(RCC_GPIOA_APB2,RCC_APB2);

	GPIO_PinConfig_t GPIO_InitStruct;
	// Initialize PA0 as push-pull alternate function (PWM output) for LED
	GPIO_InitStruct.GPIO_PinNumber = GPIO_PIN_0 ;
	GPIO_InitStruct.GPIO_MODE = GPIO_Mode_AF_OUT_PushPull;
	GPIO_InitStruct.GPIO_OUTPUT_SPEED = GPIO_Speed_2M;
	MCAL_GPIO_vInit(GPIO_PORTA, &GPIO_InitStruct);
}

void SERVO_vInit(void)
{
	GPIO_Init();
	PWM_Init();
}


void SERVOM_vStart(u8 Copy_u8Angle)
{
	u16 mappedValue = (Copy_u8Angle/0.18F) + 1000;
//	uint16_t au16_Pulse = 0;
//
//	au16_Pulse = ((af_Angle*(gs_SERVO_info[au16_SERVO_Instance].Period_Max - gs_SERVO_info[au16_SERVO_Instance].Period_Min))/180.0)
//			+ gs_SERVO_info[au16_SERVO_Instance].Period_Min;
	MCAL_TIMERx_SetCompare1(TIMER2, mappedValue);//Angle
}

void SERVOM_vStop(void)
{
	MCAL_TIMERx_SetCompare1(TIMER2, 1000);//Angle
//	TIMERS_vSetCompareMatchValue(SERVOM_TIMER, SERVOM_TIMER_Channel, 1000);
}
