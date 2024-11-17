/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: eng omar
 */

#include"STD_TYPES.h"
#include"util/delay.h"
#include"ErrType.h"
#include"DIO_interface.h"
#include "Motor_cfg.h"
#include"Motor_interface.h"

void main(void)
{

    DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN7,DIO_u8PIN_OUTPUT); /*blue*/
    DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN6,DIO_u8PIN_OUTPUT); /*pink*/
    DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_OUTPUT); /*yellow*/
    DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN4,DIO_u8PIN_OUTPUT); /*orange*/


	while(1)
	{


		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN7,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN6,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN4,DIO_u8PIN_HIGH);
						_delay_ms(2);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN7,DIO_u8PIN_HIGH);
	    DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN6,DIO_u8PIN_LOW);
	    DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_HIGH);
	    DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN4,DIO_u8PIN_HIGH);
						_delay_ms(2);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN7,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN6,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN4,DIO_u8PIN_HIGH);
						_delay_ms(2);
		 DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN7,DIO_u8PIN_HIGH);
		 DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN6,DIO_u8PIN_HIGH);
		 DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_HIGH);
		 DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN4,DIO_u8PIN_LOW);
						_delay_ms(2);

	}
}
