#ifndef BIT_MATH_H
#define BIT_MATH.h

#define SET_BIT(VAR,BIT)    VAR |= (1<<(BIT) )
#define CLR_BIT(VAR,BIT)    VAR &= ~(1<<(BIT)) 
#define GET_BIT(VAR,BIT)    (AVR>>(BIT))&1   )
#define TOG_BIT(VAR,BIT)    VAR ^= (1<<(BIT) ) 

#endif
