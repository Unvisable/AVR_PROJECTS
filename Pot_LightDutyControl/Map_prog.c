/*
 * Map_prog.c
 *
 *  Created on: Mar 26, 2024
 *      Author: user
 */
#include"STD_TYPES.h"
#include"Map_interface.h"



uint8 Map(uint16 InputVoltMin, uint16 InputVoltMax, uint16 OutputRangeMin, uint16 OutputRangeMax, uint16 sensorReading)
{
	return (uint8)(((sensorReading - InputVoltMin) * (OutputRangeMax - OutputRangeMin)) / (InputVoltMax - InputVoltMin) + OutputRangeMin);

}

