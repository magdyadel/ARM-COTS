///*
// * S2P_prog.c
// *
// *  Created on: Oct 29, 2022
// *      Author: Magdy Adel
// */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL-ARM/GPIO/GPIO_int.h"
#include "S2P_int.h"
#include "S2P_cfg.h"
#include "S2P_pvt.h"

//extern GPIO_PinConfig_t Data_pin;
//extern GPIO_PinConfig_t Shift_pin;
//extern GPIO_PinConfig_t Latch_pin;

void S2P_vInit(void)
{
	// init Shift pin , Serial data pin and Latch pin
	//GPIO_vInit(GPIO_PORTA , &Shift_pin);
	//GPIO_vInit(GPIO_PORTA , &Data_pin);
	//GPIO_vInit(GPIO_PORTA , &Latch_pin);
}
#if 0
static void Shift_Data(void)//shift clk
{
//	GPIO_vWritePinValue(Shift_pin.Port ,
//						Shift_pin.Pin ,
//						GPIO_HIGH );
//	MSTK_voidSetBusyWait(1);//	1 micro sec
//	GPIO_vWritePinValue(Shift_pin.Port ,
//						Shift_pin.Pin ,
//						GPIO_LOW );
//	MSTK_voidSetBusyWait(1);//	1 micro sec

}

static void Latch_Data(void)
{
//	GPIO_vWritePinValue(Latch_pin.Port ,
//						Latch_pin.Pin ,
//						GPIO_HIGH );
//
//	MSTK_voidSetBusyWait(1);//	1 micro sec
//
//	GPIO_vWritePinValue(Latch_pin.Port ,
//						Latch_pin.Pin ,
//						GPIO_LOW );
//	MSTK_voidSetBusyWait(1);//	1 micro sec

}

void S2P_vSendData(u32 A_u32Data)
{
//	for(u32 i=0;i<NO_REGS*8;i++)
//	{
//		GPIO_vWritePinValue(Data_pin.Port ,
//							Data_pin.Pin ,
//							GET_BIT(A_u32Data , i) );
//		/* shift bit value into register */
//		Shift_Data();
//
//	}
//	Latch_Data();

}
#endif
