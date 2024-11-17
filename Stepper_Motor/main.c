/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: eng omar
 */
#include "STD_TYPES.h"
#include "ErrType.h"
#include <util/delay.h>
#include "DIO_interface.h"

#include "Stepper_interface.h"

  STP_Config_t Motor = {
		  .STP_u8DIR = STP_CW,
		  .STP_port = DIO_u8PORTC,
		  .STP_BlueWire = DIO_u8PIN7,
		  .STP_PinkWire =DIO_u8PIN6,
		  .STP_YellowWire=DIO_u8PIN5,
		  .STP_OrangeWire=DIO_u8PIN4,

  };
  STP_Config_t Motor2 = {
 		  .STP_u8DIR = STP_CCW,
 		  .STP_port = DIO_u8PORTC,
 		  .STP_BlueWire = DIO_u8PIN7,
 		  .STP_PinkWire =DIO_u8PIN6,
 		  .STP_YellowWire=DIO_u8PIN5,
 		  .STP_OrangeWire=DIO_u8PIN4,

   };
uint8 Stp_Motor=0;
uint16 Angle = 45;
uint16 Angle2 = 45;
void main(void)
{
	DIO_u8SetPinDirection(Motor.STP_port,Motor.STP_BlueWire,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(Motor.STP_port,Motor.STP_PinkWire,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(Motor.STP_port,Motor.STP_YellowWire,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(Motor.STP_port,Motor.STP_OrangeWire,DIO_u8PIN_OUTPUT);

	DIO_u8SetPinValue(Motor.STP_port,Motor.STP_BlueWire,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Motor.STP_port,Motor.STP_PinkWire,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Motor.STP_port,Motor.STP_YellowWire,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Motor.STP_port,Motor.STP_OrangeWire,DIO_u8PIN_HIGH);

   while(1)
   {

	    Stp_Motor = STP_u8Rotate( &Motor2,Motor2.STP_u8DIR,Angle2);
	    _delay_ms(250);
	    Stp_Motor = STP_u8Rotate( &Motor,Motor.STP_u8DIR,Angle);
	    _delay_ms(250);

   }






}

