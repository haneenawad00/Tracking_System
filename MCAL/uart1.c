

#include "uart1.h"
#include <avr/io.h>
#include "../LIB/bit_math.h"



#define VALUE        (uint8) 103
#define DATA_8_BIT   (uint8) 0b10000110
#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)


void UART_init()
{

	    UCSRB |= (1 << RXEN) | (1 << TXEN);/* Turn on transmission and reception */
	  	UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);/* Use 8-bit character sizes */
	  	UBRRL = BAUD_PRESCALE;		/* Load lower 8-bits of the baud rate value */
	  	UBRRH = (BAUD_PRESCALE >> 8);	/* Load upper 8-bits*/
}


void UART_SendChar(char ch)
{
	while (! (UCSRA & (1<<UDRE)));	/* Wait for empty transmit buffer*/
	UDR = ch ;
}


uint8 UART_GetChar(void)
{
	while ((UCSRA & (1 << RXC)) == 0);/* Wait till data is received */
	return(UDR);			/* Return the byte*/

}

void  UART1_recieveByte(uint8 *Str)
{
	uint8 i = 0;

	/* Receive the first byte */
	Str[i] = UART_GetChar();

	/* Receive the whole string until the '#' */
	while(Str[i] != '#')
	{
		i++;
		Str[i] = UART_GetChar();
	}

	/* After receiving the whole string plus the '#', replace the '#' with '\0' */
	Str[i] = '\0';
}
