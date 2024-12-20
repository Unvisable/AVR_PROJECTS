/*
 * TIMER_reg.h
 *
 *  Created on: Nov 30, 2023
 *      Author: yosef
 */

#ifndef TIMER_REG_H_
#define TIMER_REG_H_

#define TCCR0                     *((volatile uint8 *)0x53)
#define TCCR0_CS00				  0
#define TCCR0_CS01				  1
#define TCCR0_CS02				  2
#define TCCR0_COM01				  5
#define TCCR0_COM00				  4
#define TCCR0_WGM00				  6
#define TCCR0_WGM01				  3

#define TCNT0					  *((volatile uint8 *)0x52)

#define TIMSK					  *((volatile uint8 *)0x59)
#define TIMSK_TOIE0				  0
#define TIMSK_OCIE0				  1
#define TIMSK_TOIE1			      2
#define TIMSK_OCIE1B			  3
#define TIMSK_OCIE1A			  4
#define TIMSK_TICIE1			  5
#define TIMSK_OCIE2				  7
#define TIMSK_TOIE2			      6

#define OCR0					  *((volatile uint8 *)0x5C)
#define TIFR					  *((volatile uint8 *)0x58)

#define TCCR1A					  *((volatile uint8 *)0x4F)
#define TCCR1A_WGM10			  0
#define TCCR1A_WGM11			  1
#define TCCR1A_FOC1B			  2
#define TCCR1A_FOC1A			  3
#define TCCR1A_COM1B0			  4
#define TCCR1A_COM1B1			  5
#define TCCR1A_COM1A0			  6
#define TCCR1A_COM1A1			  7

#define TCCR1B					  *((volatile uint8 *)0x4E)
#define TCCR1B_CS10				  0
#define TCCR1B_CS11				  1
#define TCCR1B_CS12				  2
#define TCCR1B_WGM12			  3
#define TCCR1B_WGM13			  4
#define TCCR1B_ICES1			  6
#define TCCR1B_ICNC1			  7

#define OCR1AH					  *((volatile uint8 *)0x4B)
#define OCR1AL					  *((volatile uint8 *)0x4A)
#define OCR1A					  *((volatile uint16 *)0x4A)

#define OCR1BH					  *((volatile uint8 *)0x49)
#define OCR1BL					  *((volatile uint8 *)0x48)
#define OCR1B					  *((volatile uint16 *)0x48)

#define TCCR2					  *((volatile uint8 *)0x45)
#define TCCR2_CS20				  0
#define TCCR2_CS21				  1
#define TCCR2_CS22				  2
#define TCCR2_WGM21				  3
#define TCCR2_COM20				  4
#define TCCR2_COM21				  5
#define TCCR2_WGM20				  6
#define TCCR2_FOC2				  7

#define TIFR					  *((volatile uint8 *)0x58)
#define TIFR_TOV1				  2
#define TIFR_OCF1B				  3
#define TIFR_OCF1A				  4
#define TIFR_ICF1				  5

#define ICR1L					  *((volatile uint8 *)0x46)
#define ICR1H					  *((volatile uint8 *)0x47)
#define ICR1					  *((volatile uint16 *)0x46)

#define TCNT1L					  *((volatile uint8 *)0x4C)
#define TCNT1H					  *((volatile uint8 *)0x4D)
#define TCNT1					  *((volatile uint16 *)0x4C)

#define WDTCR					  *((volatile uint16 *)0x41)
#define WDTCR_WDP0				  0
#define WDTCR_WDP1				  1
#define WDTCR_WDP2				  2
#define WDTCR_WDE				  3
#define WDTCR_WDTOE				  4

#endif /* TIMER_REG_H_ */
