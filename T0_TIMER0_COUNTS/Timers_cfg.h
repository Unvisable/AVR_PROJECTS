/*
 * Timers_cfg.h
 *
 *  Created on: Apr 20, 2024
 *      Author: user
 */

#ifndef TIMERS_CFG_H_
#define TIMERS_CFG_H_

#define Normal_Mode                0u
#define PWM_Phase_Correct          1u
#define CTC                        2u
#define Fast_PWM                   3u

#define MODE           Normal_Mode

#define No_clock_source                                                       0u
#define Prescaler_0                                                           1u
#define Prescaler_64                                                          3u
#define Prescaler_256                                                         4u
#define Prescaler_1024                                                        5u
#define External_clock_source_on_T0_pin_Clock_on_falling_edge                 6u
#define External_clock_source_on_T0_pin_Clock_on_rising_edge                  7u

#define Clock_Source_Val              External_clock_source_on_T0_pin_Clock_on_falling_edge

#define TCNTO_Init_val             0u
#define OCR0_Init_val              0u

#endif /* TIMERS_CFG_H_ */
