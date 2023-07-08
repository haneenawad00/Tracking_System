

#ifndef UART1_H_
#define UART1_H_

#include "../LIB/std_types.h"


void UART_init();

void UART_sendByte(const uint8 data);

uint8 UART_GetChar(void);


void UART1_recieveByte(uint8 *Str); // Receive until #


#endif
