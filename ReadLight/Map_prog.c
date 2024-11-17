/*
 * Map_prog.c
 *
 *  Created on: Mar 26, 2024
 *      Author: user
 */
#include"STD_TYPES.h"
#include"Map_interface.h"



uint16 Map(uint16 InputVoltMin, uint16 InputVoltMax, uint8 OutputRangeMin, uint8 OutputRangeMax, uint16 sensorReading)
{
	uint16 input_range = InputVoltMax - InputVoltMin;
	    uint16 output_range = OutputRangeMax - OutputRangeMin;

	    // Calculate the mapped value using separate multiplication and division
	    uint16 mapped_value = ((uint32)(sensorReading - InputVoltMin) * output_range) / input_range;

	    return mapped_value + OutputRangeMin;

}

