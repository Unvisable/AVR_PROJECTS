/*
 * main.c
 *
 * Created on: Mar 21, 2024
 * Author: user
 */

#include "STD_TYPES.h"
#include "util/delay.h"
#include "Port_interface.h"
#include "DIO_interface.h"
#include "Map_interface.h"
#include "LDR_interface.h"
#include "CLCD_interface.h" // Assuming you have a header file for LCD functions



void main(void)
{
    // Initialize peripherals
    PORT_voidInit();
    CLCD_voidInit();
    LDR_VoidInit();

    // Clear LCD screen
    CLCD_voidSendCmd(1);

    uint16 sensorReading = 0;
    uint16 mapped_value=0u;

    while(1)
    {
    	CLCD_voidSendCmd(1);
        CLCD_voidGoToXY(0, 0);
        CLCD_u8SendString("Light:");
        //Mapped = Map(0,170,0,255,(sint32)sensorReading);
        // Read sensor value
        sensorReading = LDR_GetValue();
        mapped_value = Map(1,683,0,255,sensorReading);
        CLCD_voidGoToXY(0,1);
        CLCD_voidSendNumber(mapped_value);
        _delay_ms(200);
        CLCD_voidSendCmd(1);
        if(mapped_value == 0)
        {
        	CLCD_voidSendCmd(1);
        	CLCD_voidGoToXY(0,0);
        	CLCD_u8SendString("It is Dark");
        	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);
        	_delay_ms(1000);
        	CLCD_voidSendCmd(1);
        }
        else if(mapped_value == 34)
        {
        	 CLCD_voidSendCmd(1);
        	 CLCD_voidGoToXY(0,0);
        	 CLCD_u8SendString("It is Mid_night");
        	 DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
        	 _delay_ms(1000);
        	 CLCD_voidSendCmd(1);
        }
        else if(mapped_value == 255)
        {
        	CLCD_voidSendCmd(1);
        	 CLCD_voidGoToXY(0,0);
        	 CLCD_u8SendString("It is LIGHt");
        	 DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
        	 _delay_ms(1000);
        	 CLCD_voidSendCmd(1);

        }


    }
}

