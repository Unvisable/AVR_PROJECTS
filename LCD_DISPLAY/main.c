/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: eng omar
 */


#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "CLCD_interface.h"

void main(void)
{
	DIO_u8SetPortDirection(DIO_u8PORTA,DIO_u8PIN_OUTPUT);

	CLCD_voidInit();
	CLCD_voidSendCmd(1);

	CLCD_u8SendString("\tOMAR");
     //CLCD_voidSendNumber(10);
	while(1)
	{

	}
}
