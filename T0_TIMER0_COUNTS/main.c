/*
 * main.c

 *
 *  Created on: Apr 26, 2024
 *      Author: user
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"ErrType.h"
#include"util/delay.h"
#include"DIO_interface.h"
#include"DIO_reg.h"
#include"Port_interface.h"
#include"CLCD_interface.h"
#include"GIE_interface.h"
#include"Timers_interface.h"
#include"Timers_reg.h"
#include"SSD_INTERFACE.h"
uint8 switch_t(void);

void main(void)
{
	uint8 Local_u8Reading=0u;
	PORT_voidInit();
	GIE_VoidEnableGlobal();
	Timer0_voidInit();
	CLCD_voidInit();
	CLCD_voidSendCmd(1);
	TCNT0=0u;


	while(1)
	{
		CLCD_voidGoToXY(0,0);
		CLCD_u8SendString("TCNT0");
		Local_u8Reading = switch_t();

		CLCD_voidGoToXY(0,1);
		CLCD_voidSendNumber(Local_u8Reading);


	}
}
uint8 switch_t(void)
{
	return TCNT0;

}

