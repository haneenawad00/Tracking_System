/******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: gpio.c
 *
 * Description: Source file for the AVR GPIO driver
 *
 * Author: Ahmed Walid
 *
 *******************************************************************************/

#include "dio.h"
#include "dio_reg.h"
#include "../LIB/bit_math.h"
#include "../LIB/std_types.h"

/* IO Pins */
/*This function sets the value of a specific I/O pin to either high (1) or low (0). The function takes three arguments:
 * the ID of the port containing the pin (u8PortIdCopy), the ID of the pin (u8PinIdCopy),
and the value to be set (u8PinValCopy).*/
void DIO_SetPinValue(uint8 PortIdCopy , uint8 PinIdCopy, uint8 PinValCopy)
{
	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((PortIdCopy <= PORTD) && (PinIdCopy <= PIN7))
	{
		if (PinValCopy == HIGH)
		{
			/* Check on the Required PORT Number */
			switch (PortIdCopy)
			{
				case PORTA: SET_BIT(PORTA_Register,PinIdCopy); break;
				case PORTB: SET_BIT(PORTB_Register,PinIdCopy); break;
				case PORTC: SET_BIT(PORTC_Register,PinIdCopy); break;
				case PORTD: SET_BIT(PORTD_Register,PinIdCopy); break;
			}
		}
		else if (PinValCopy == LOW)
		{
			/* Check on the Required PORT Number */
			switch (PortIdCopy)
			{
				case PORTA: CLEAR_BIT(PORTA_Register,PinIdCopy); break;
				case PORTB: CLEAR_BIT(PORTB_Register,PinIdCopy); break;
				case PORTC: CLEAR_BIT(PORTC_Register,PinIdCopy); break;
				case PORTD: CLEAR_BIT(PORTD_Register,PinIdCopy); break;
			}
		}
		else
		{
			/* Do nothing, Wrong value to set */
		}
	}
	else
	{
		/* Do nothing, Error in the Pin ID or PORT ID */
	}
}
/*This function reads the value of a specific I/O pin and returns it as either high (1) or low (0).
 * The function takes two arguments:
 * the ID of the port containing the pin (u8PortIdCopy) and the ID of the pin (u8PinIdCopy).*/
uint8 DIO_GetPinValue(uint8 u8PortIdCopy, uint8 u8PinIdCopy)
{
	/* Define Local Variable to get the BIT Value */
	uint8 u8ResultLocal;
	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((u8PortIdCopy <= PORTD) && (u8PinIdCopy <= PIN7))
	{
		/* Check on the Required PORT Number */
		switch (u8PortIdCopy)
		{
			case PORTA: u8ResultLocal= GET_BIT(PINA_Register,u8PinIdCopy); break;
			case PORTB: u8ResultLocal= GET_BIT(PINB_Register,u8PinIdCopy); break;
			case PORTC: u8ResultLocal= GET_BIT(PINC_Register,u8PinIdCopy); break;
			case PORTD: u8ResultLocal= GET_BIT(PIND_Register,u8PinIdCopy); break;
		}
	}
	else
	{
		/* return 0xff in case of error in the Pin ID or PORT ID */
		u8ResultLocal = 0xFF;
	}
	return u8ResultLocal;
}


/*This function sets the direction of a specific I/O pin to either input (0) or output (1).
The function takes three arguments: the ID of the port containing the pin (u8PortIdCopy), the ID of the pin*/

void DIO_SetPinDirection (uint8 u8PortIdCopy, uint8 u8PinIdCopy, uint8 u8PinDirCopy)
{
	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((u8PortIdCopy <= PORTD) && (u8PinIdCopy <= PIN7))
	{  if ( u8PinDirCopy == OUTPUT )
		{ /* Check on the Required PORT Number */
			switch (u8PortIdCopy)
			{
				case PORTA: SET_BIT(DDRA_Register,u8PinIdCopy); break;
				case PORTB: SET_BIT(DDRB_Register,u8PinIdCopy); break;
				case PORTC: SET_BIT(DDRC_Register,u8PinIdCopy); break;
				case PORTD: SET_BIT(DDRD_Register,u8PinIdCopy); break;
			}
		}
		else if ( u8PinDirCopy == INPUT )
		{
			/* Check on the Required PORT Number */
			switch (u8PortIdCopy)
			{
				case PORTA: CLEAR_BIT(DDRA_Register,u8PinIdCopy); break;
				case PORTB: CLEAR_BIT(DDRB_Register,u8PinIdCopy); break;
				case PORTC: CLEAR_BIT(DDRC_Register,u8PinIdCopy); break;
				case PORTD: CLEAR_BIT(DDRD_Register,u8PinIdCopy); break;
			}
		}
		else
		{
			/* Do nothing, Wrong Direction Required */
		}
	}
	else
	{
		/* Do nothing, Error in the Pin ID or PORT ID */
	}
}


/*This function sets the direction of an entire I/O port to either input (0) or output (1).
 * The function takes two arguments: the ID of the port to be set (u8PortId) and the direction to be set (u8PortDir).
 */
void DIO_SetPortDirection (uint8 u8PortId, uint8 u8PortDir)
{
	/* Check on the Required PORT Number */
	switch (u8PortId)
	{
		case     PORTA: DDRA_Register = u8PortDir; break;
		case     PORTB: DDRB_Register = u8PortDir; break;
		case     PORTC: DDRC_Register = u8PortDir; break;
		case     PORTD: DDRD_Register = u8PortDir; break;
		default: /* Wrong Port ID */       break;
	}
}


/* function used for setting the value of all pins of a specific port of a microcontroller to either high or low.*/
void DIO_SetPortValue (uint8 u8PortId, uint8 u8PortVal)
{
	/* Check on the Required PORT Number */
	switch (u8PortId)
	{
		case     PORTA: PORTA_Register = u8PortVal; break;
		case     PORTB: PORTB_Register = u8PortVal; break;
		case     PORTC: PORTC_Register = u8PortVal; break;
		case     PORTD: PORTD_Register = u8PortVal; break;
		default: /* Wrong Port ID */        break;
	}
}
