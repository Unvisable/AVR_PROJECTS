/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: eng omar
 */
#include "STD_TYPES.h"
#include <util/delay.h>
#include"DIO_interface.h"
#include"ERROR_TYP_STATE.h"



void main (void)
{
	uint8 Local_u8ButtonReading;
	DIO_u8SetPinDirection( DIO_u8PORTA, DIO_u8PIN0,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection( DIO_u8PORTB, DIO_u8PIN0,DIO_u8PIN_INPUT);
	DIO_u8SetPinValue(DIO_u8PORTB, DIO_u8PIN0, DIO_u8Pin_HIGH); /*BUTTON IS INTERNALY PULLED UP*/
	while(1)
	{
		DIO_u8ReadPinValue(DIO_u8PORTB,DIO_u8PIN0,&Local_u8ButtonReading);
		if(Local_u8ButtonReading == DIO_u8Pin_LOW)
		{
			DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8Pin_HIGH);
		}
		else
		{
			DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8Pin_LOW);
		}

	}
}

