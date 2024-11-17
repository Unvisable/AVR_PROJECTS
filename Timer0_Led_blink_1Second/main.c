/*
 * main.c
 *
 *  Created on: Apr 20, 2024
 *      Author: user
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"DIO_reg.h"
#include"Port_interface.h"
#include"GIE_interface.h"
#include"Timers_interface.h"
void Led_blink(void);


void main(void)
{
	PORT_voidInit();

	Timer0_voidInit();
	Timer_u8SetCallBack(Timer0_OVF_INT,&Led_blink);
	GIE_VoidEnableGlobal();

	while(1)
	{



	}
}

void Led_blink(void)
{
	static uint8 Local_u8Counter =0u;
	Local_u8Counter++;
	if(Local_u8Counter == 245u)
	{
		Timer0_voidSetPreloadValue(220u);
		DIO_u8TogglePinValue(DIO_u8PORTC,DIO_u8PIN0);
		Local_u8Counter=0;
	}


}
