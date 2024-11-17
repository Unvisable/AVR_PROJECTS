/*
 * main.c
 *
 *  Created on: May 15, 2024
 *      Author: user
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include"Port_interface.h"
#include "DIO_interface.h"
#include "USART_interface.h"



void main(void)
{
	//uint8 Local_u8RecievedData;
	PORT_voidInit();
	USART_Init();

	while(1)
	{


		  USART_VoidSend('f');
		  DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);
		  _delay_ms(500);
		  USART_VoidSend('n');
		  DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
		  _delay_ms(500);
		  USART_VoidSend('K');
		  		  DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
		  		  _delay_ms(500);
		  		USART_VoidSend('k');
		  				  DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
		  				  _delay_ms(500);
		  				USART_VoidSend('H');
		  						  DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
		  						  _delay_ms(500);
		  						USART_VoidSend('L');
		  								  DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
		  								  _delay_ms(500);
		  								USART_VoidSend('D');
		  										  DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
		  										  _delay_ms(500);
		  										USART_VoidSend('I');
		  												  DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
		  												  _delay_ms(500);
		  												USART_VoidSend('S');
		  														  DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
		  														  _delay_ms(500);
		  														USART_VoidSend('G');
		  																  DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
		  																  _delay_ms(500);


	}



}

