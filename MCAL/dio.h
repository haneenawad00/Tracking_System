 /******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: gpio.h
 *
 * Description: Header file for the AVR GPIO driver
 *
 * Author: Ahmed 
 *
 *******************************************************************************/


#ifndef DIO_H_
#define DIO_H_
#include "../LIB/std_types.h"

/* Port Defines */
#define PORTA    0
#define PORTB    1
#define PORTC    2
#define PORTD    3

/* PIN Defines */
#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7

/* PIN Directions */
#define INPUT  0
#define OUTPUT 1
#define FULL_OUTPUT  0xFF
#define FULL_INPUT    0

/* PIN Value Options */
#define HIGH   1
#define LOW    0

/* IO Pins */
void DIO_SetPinValue(uint8 u8PortIdCopy , uint8 u8PinIdCopy, uint8 u8PinValCopy);
uint8 DIO_GetPinValue(uint8 u8PortIdCopy, uint8 u8PinIdCopy);
void DIO_SetPinDirection (uint8 u8PortIdCopy, uint8 u8PinIdCopy, uint8 u8PinDirCopy);
/* IO Ports */
void DIO_SetPortDirection (uint8 u8PortId, uint8 u8PortDir);
void DIO_SetPortValue     (uint8 u8PortId, uint8 u8PortVal);

#endif /* DIO_H_ */
