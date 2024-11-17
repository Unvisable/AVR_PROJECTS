/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: eng omar
 */
#include"STD_TYPES.h"
#include"util/delay.h"
#include "BIT_MATH.h"
#include"ErrType_Cal.h"
#include"ErrType.h"
#include"DIO_interface.h"
#include"CLCD_interface.h"
#include"Calculator_interface.h"
#include"Keypad_INTERFACE.h"
#include "Motor_cfg.h"
#include"Motor_interface.h"
#include "Stepper_interface.h"
#include"Hamoksha.h"

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

uint8 Intro[8]= {0b00100,0b01010,0b00100,0b11111,0b00100,0b01110,0b01010,0b00000};
uint8 Local_u8GetNum=0,Local_u8Iterator=0,Local_u8CursorIterator=9u,Local_u8Num1=0,Local_u8Num2=0;
uint16 Local_u8Num3=0;

void main(void)
{
	CLCD_voidInit();
	Motor_init();

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
    	CLCD_voidGoToXY(0,0);
    		CLCD_u8SendString("Welcome to MotorDB");
    		CLCD_u8SendSpecialCharacter(0, Intro,1,1);
    		_delay_ms(1000);
    		CLCD_voidSendCmd(1);
    		CLCD_voidGoToXY(0,0);
    		CLCD_u8SendString("choose which motor");
    		CLCD_voidGoToXY(1,0);
    		CLCD_u8SendString("do you want?");
    		_delay_ms(250);
    		CLCD_voidSendCmd(1);
    		CLCD_voidGoToXY(0,0);
    		CLCD_u8SendString("1) Dc_Motor");
    		CLCD_voidGoToXY(0,1);
    		CLCD_u8SendString("2) Stepper_Motor");
    		_delay_ms(250);
    		CLCD_voidGoToXY(0,0);
    		CLCD_u8SendString("ANSWER:");
    		do
    		{
    			 Local_u8GetNum = Keypad4x4();
    			 CLCD_voidGoToXY(0,9);
    			 CLCD_voidSendNumber(Local_u8GetNum);

    		}while(Local_u8GetNum != '=');
    		_delay_ms(250);
    		if(Local_u8GetNum == 1)
    		{
    		   CLCD_voidSendCmd(1);
    		   CLCD_voidGoToXY(0,0);
    		   CLCD_u8SendString("Dc_Motor");
    		   CLCD_voidGoToXY(1,0);
    		   CLCD_u8SendString("DashBoard");
    		   _delay_ms(500);
    		   CLCD_voidSendCmd(1);
    		   CLCD_voidGoToXY(0,0);
    		   CLCD_u8SendString("1)RotateCW");
    		   CLCD_voidGoToXY(0,1);
    		   CLCD_u8SendString("2)RotateCCW");
    		   _delay_ms(250);
    		   CLCD_voidSendCmd(1);
    		   CLCD_u8SendString("ANSWER:");
    		   do
    		   {
    			   Local_u8Num1=Keypad4x4();
    			   CLCD_voidGoToXY(0,9);
    			   CLCD_voidSendNumber(Local_u8Num1);
    		   }while(Local_u8Num1 !='=');
    		   if(Local_u8Num1 == 1)
    		   {
    			   Motor_rotateCW4Pins();
    			   _delay_ms(5000);
    		   }
    		   else if(Local_u8Num1 == 2)
    		   {
    			   Motor_rotateCWW4Pins();
    			   _delay_ms(5000);
    		   }
    		   else
    		   {
    			   CLCD_voidSendCmd(1);
    			   CLCD_u8SendString("Error");
    		   }

    		   Motor_stop();
    		   CLCD_voidSendCmd(1);
    		   CLCD_voidGoToXY(0,0);
    		   CLCD_u8SendString("Thanks");
    		   CLCD_u8SendSpecialCharacter(0, Intro,1,1);
    		   _delay_ms(1000);


    		}
    		else if(Local_u8GetNum == 2)
    		{
    			 CLCD_voidSendCmd(1);
    				   CLCD_voidGoToXY(0,0);
    				   CLCD_u8SendString("STP_Motor");
    				   CLCD_voidGoToXY(1,0);
    				   CLCD_u8SendString("DashBoard");
    				   _delay_ms(500);
    				   CLCD_voidSendCmd(1);
    				   CLCD_voidGoToXY(0,0);
    				   CLCD_u8SendString("1)RotateCW");
    				   CLCD_voidGoToXY(0,1);
    				   CLCD_u8SendString("2)RotateCCW");
    				   _delay_ms(250);
    				   CLCD_voidSendCmd(1);
    				   CLCD_u8SendString("ANSWER:");
    				   do
    				   {
    					   Local_u8Num2=Keypad4x4();
    					   CLCD_voidGoToXY(0,9);
    					   CLCD_voidSendNumber(Local_u8Num2);
    				   }while(Local_u8Num2 !='=');
    				   if(Local_u8Num2 == 1)
    				   {
    					   CLCD_voidSendCmd(1);
    					   CLCD_voidGoToXY(0,0);
    					   CLCD_u8SendString("Degree:");
    					   do
    					   {
    						   Local_u8Num3 = Keypad4x4();
    						   Local_u8Iterator++;
    						  	 switch(Local_u8Iterator)
    						  	 {
    						  	 case(1): Local_u8Num1 = Local_u8Num3;CLCD_voidGoToXY(Local_u8CursorIterator,0);CLCD_voidSendNumber(Local_u8Num3);                        break;                                      /*1 digit*/
    						  	 case(2): Local_u8Num1 = (Local_u8Num1 *10) + Local_u8Num3;CLCD_voidGoToXY(Local_u8CursorIterator,0);CLCD_voidSendNumber(Local_u8Num3);   break;                                      /*2 digit*/
    						  	 case(3): Local_u8Num1 = (Local_u8Num1 *10) + Local_u8Num3;CLCD_voidGoToXY(Local_u8CursorIterator,0);CLCD_voidSendNumber(Local_u8Num3);  break;                                      /*3 digit*/
    						  	 default: Local_u8Iterator=0;Local_u8CursorIterator=9;CLCD_voidSendCmd(1);CLCD_u8SendString("Error"); _delay_ms(500);CLCD_voidSendCmd(1);   break;
    						  	 }
    						  			   Local_u8CursorIterator++;

    					   }while(Local_u8Num3 != '=');
    					   if(Local_u8Num3>360)
    					   {
    						   CLCD_voidSendCmd(1);
    						   CLCD_u8SendString("Error");
    					   }
    					   Stp_Motor = STP_u8Rotate( &Motor,Motor.STP_u8DIR,Local_u8Num3);

    					   _delay_ms(5000);
    				   }
    				   else if(Local_u8Num1 == 2)
    				   {
    					   CLCD_voidSendCmd(1);
    					  	 CLCD_voidGoToXY(0,0);
    					  	 CLCD_u8SendString("Degree:");
    					  	 do
    					  	 {
    					  		   Local_u8Num3 = Keypad4x4();
    					  		   Local_u8Iterator++;
    					  		  	 switch(Local_u8Iterator)
    					  		  	 {
    					  		  	 case(1): Local_u8Num1 = Local_u8Num3;CLCD_voidGoToXY(Local_u8CursorIterator,0);CLCD_voidSendNumber(Local_u8Num3);                        break;                                      /*1 digit*/
    					  		  	 case(2): Local_u8Num1 = (Local_u8Num1 *10) + Local_u8Num3;CLCD_voidGoToXY(Local_u8CursorIterator,0);CLCD_voidSendNumber(Local_u8Num3);   break;                                      /*2 digit*/
    					  		  	 case(3): Local_u8Num1 = (Local_u8Num1 *10) + Local_u8Num3;CLCD_voidGoToXY(Local_u8CursorIterator,0);CLCD_voidSendNumber(Local_u8Num3);  break;                                      /*3 digit*/
    					  		  	 default: Local_u8Iterator=0;Local_u8CursorIterator=9;CLCD_voidSendCmd(1);CLCD_u8SendString("Error"); _delay_ms(500);CLCD_voidSendCmd(1);   break;
    					  		  	 }
    					  		  			   Local_u8CursorIterator++;

    					  	 }while(Local_u8Num3 != '=');
    					  	 if(Local_u8Num3>360)
    					  	 {
    					  		   CLCD_voidSendCmd(1);
    					  		   CLCD_u8SendString("Error");
    					  	 }
    					  	 Stp_Motor = STP_u8Rotate( &Motor2,Motor2.STP_u8DIR,Local_u8Num3);
    				   }
    				   else
    				   {
    					   CLCD_voidSendCmd(1);
    					   CLCD_u8SendString("Error");
    				   }

    				   Motor_stop();
    				   CLCD_voidSendCmd(1);
    				   CLCD_voidGoToXY(0,0);
    				   CLCD_u8SendString("Thanks");
    				   CLCD_u8SendSpecialCharacter(0, Intro,1,1);
    				   _delay_ms(1000);
    		}

    }


}
