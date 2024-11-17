/*
 * main,.c
 *
 *  Created on: Mar 17, 2024
 *      Author: user
 */
#include"STD_TYPES.h"
#include "util/delay.h"
#include"Port_interface.h"
#include "Map_interface.h"
#include"DIO_interface.h"
#include"ADC_interface.h"
#include "CLCD_interface.h"
#include "Timers_interface.h"
//uint32 Temp;
uint8 RES=0u;
uint16 potReading;
void main(void)
{
	PORT_voidInit();
	Timer0_voidInit();
	ADC_VoidInit();
    while(1)
    {
    	 potReading = ADC_u8GetChannelReading(0);
    	 RES = Map(0,255,0,256,potReading);
    	 Timer0_voidSetCompareMatchValue(RES);
    }
}
