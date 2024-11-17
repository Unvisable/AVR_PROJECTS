/*
 * main.c
 *
 *  Created on: May 7, 2024
 *      Author: user
 */
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "Port_interface.h"
#include "ADC_interface.h"
#include"Servo_Interface.h"
#include "CLCD_interface.h"
#include "GIE_interface.h"
#include "Map_interface.h"
//#define  MIN_PWM_VALUE      130
//#define  MAX_PWM_VALUE      600
//#define  MIN_ANGLE         -90
//#define  MAX_ANGLE          90
//#define PWM_RANGE         MAX_PWM_VALUE - MIN_PWM_VALUE
//#define ANGLE_RANGE       MAX_ANGLE - MIN_ANGLE
uint16 Pot_Reading=0;
uint32 RS=0,Speed=0;

void main(void)
{
	PORT_voidInit();
	Servo_voidInit();
	ADC_VoidInit();
	CLCD_voidInit();
	//GIE_VoidEnableGlobal();

	while(1)
	{
		Pot_Reading = ADC_u8GetChannelReading(0);
		_delay_ms(40);
        RS =Map(0,255,130,600,(uint32)Pot_Reading);
        CLCD_voidGoToXY(3,0);
        CLCD_u8SendString("Speed %:");
        Speed = Map(0,255,0,100,Pot_Reading);
        CLCD_voidGoToXY(10,0);
        CLCD_voidSendNumber(Speed);
        Set_OCR1A(RS);
        _delay_ms(2000);
        CLCD_voidSendCmd(1);
        Pot_Reading=0,RS=0;//angle=0;
	}
}



