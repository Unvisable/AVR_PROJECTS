#define SET_BIT(REG,NUM)    (REG|=(1<<NUM))
#define CLR_BIT(REG,NUM)    (REG&=(~(1<<NUM)))
#define TOG_BIT(VAR,BIT_NUM) VAR^=(1<<BIT_NUM)
#define GET_BIT(VAR,BIT_NUM) VAR=((VAR>>BIT_NUM)&1)





