/*
 * ADC_prv.h
 *
 *  Created on: Mar 17, 2024
 *      Author: user
 */

#ifndef ADC_PRV_H_
#define ADC_PRV_H_

#define ENABELD  1u
#define DISABLED 0u

#define AREF_Internal_Vref_Turned_Off                                           1u
#define AVCC_With_External_Capacitor_On_AREF                                    2u
#define Reserved                                                                3u
#define Internal_Voltage                                                        4u

#define Resolution_8  1u
#define Resolution_10 2u

#define ADC_PRESCALER_BIT_MASK      0b11111000
#define ADC_Prescaler_BIT_POS        0u
#define Division_By_2   1u
#define Division_By_4   2u
#define Division_By_8   3u
#define Division_By_16  4u
#define Division_By_32  5u
#define Division_By_64  6u
#define Division_By_128 7u

#define CHANNEL_BIT_MASK 0b11100000

#endif /* ADC_PRV_H_ */
