/*
 * bit_math.h
 *
 *  Created on: Jun 21, 2023
 *      Author: Haneenahmedawadmoham
 */

/*
/*C library that provides bit-level operations on integer data types.*/


#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(VAR,BITNO) (VAR) |=  (1 << (BITNO)) //This macro sets the n-th bit of x to 1
#define CLEAR_BIT(VAR,BITNO) (VAR) &= ~(1 << (BITNO)) //This macro sets the n-th bit of x to 0
#define TOG_BIT(VAR,BITNO) (VAR) ^=  (1 << (BITNO))  //this macro to togglevalue of bit make 0 to 1 and make 1 to 0
#define GET_BIT(VAR,BITNO) (((VAR) >> (BITNO)) & 0x01) //this macro to read the bit

#endif /* BIT_MATH_H_ */
