/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: eng omar
 */
#include"STD_TYPES.h"
#include"ErrType.h"
#include"CLCD_interface.h"
#include"Port_interface.h"
#include"StopWatch_interface.h"


uint8 Local_u8SWArrM[8]={0,0,':',0,0,':',0,0},i;
void main(void)
{
	StopWatch_Init();

    StopWatch_Display();

	while(1)
	{
		StopWatch_Set();
		StopWatch_TurnOn();
	}

}

