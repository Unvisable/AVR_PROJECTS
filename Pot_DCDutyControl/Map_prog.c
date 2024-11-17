/*
 * Map_prog.c
 *
 *  Created on: Mar 26, 2024
 *      Author: user
 */
#include"STD_TYPES.h"
#include"Map_interface.h"



uint32 Map(uint32 InputVoltMin, uint32 InputVoltMax, uint32 OutputRangeMin, uint32 OutputRangeMax, uint32 sensorReading)
{
	return (((sensorReading - InputVoltMin) * (OutputRangeMax - OutputRangeMin)) / (InputVoltMax - InputVoltMin) + OutputRangeMin);

}

