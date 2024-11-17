/*
 * main.c
 *
 *  Created on: Mar 20, 2024
 *      Author: user
 */
#include"STD_TYPES.h"
#include"util/delay.h"
#include"Port_interface.h"
#include"DIO_interface.h"
#include"CLCD_interface.h"
#include"LM35_interface.h"


void main(void)
{
  PORT_voidInit();
  CLCD_voidInit();
  CLCD_voidSendCmd(1);
  Temp_VoidInit();
  uint32 TempReading=0;
  while(1)
  {
	  TempReading = Get_u32Temp();
	  _delay_ms(10);
	  CLCD_voidGoToXY(0,0);
	  CLCD_u8SendString("Temperature:");
	  CLCD_voidGoToXY(0,1);
	  CLCD_voidSendNumber(TempReading);
	  if(TempReading <10)
	  {
		  CLCD_voidGoToXY(1,1);
		  CLCD_u8SendString(" ");
	  }
	  else{
		  /*Do nothing*/
	  }



  }


}
