#ifndef CLCD_PRV_H
#define CLCD_PRV_H

#define FOUR_BIT 1
#define EIGHT_BIT 2
#if CLCD_u8BIT_MODE == FOUR_BIT
static void voidSetHalfDataPort(uint8 Copy_u8Data);
#endif
static void voidSendEnablePulse(void);

#endif
