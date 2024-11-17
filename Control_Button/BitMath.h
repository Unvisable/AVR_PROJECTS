
#define SET_BIT(number,bitnum)    (number |= (1<<bitnum))
#define CLR_BIT(number,bitnum)   (number &= (~(1<<bitnum)))
#define TOG_BIT(number,bitnum)   (number ^= (1<<bitnum))
#define GET_BIT(number,bitnum)   ((number >> bitnum) & 1)






