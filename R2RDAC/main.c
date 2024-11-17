/*
 * main.c
 *
 *  Created on: Mar 12, 2024
 *      Author: user
 */
#include"util/delay.h"
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"DAC_interface.h"


void main(void)
{
	DAC_voidInit();

	while(1)
	{
		for(uint16 i=1000;i<=10000; i++)
		{
			DAC_voidSetAnalog(i);
			_delay_ms(250);
		}
	}

}
