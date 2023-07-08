/*
 * main.c
 *
 *  Created on: Jul 3, 2023
 *      Author: Haneenahmedawadmoham
 */

#include "GPS.h"
#include "lcd.h"
#include "dio.h"
#include <avr/io.h>
#include "uart1.h"
#include <util/delay.h>

int main()
{

	  SREG |= (1 << 7);  //enable globle interrupt
	  double latitude, longitude;  //This line declares two double-precision variables, latitude and longitude, which will be used to store the GPS coordinates.
      LCD_vidInit(); //This function initializes the LCD display.
      UART_Init(); //This function initializes the UART communication for the GPS module.




	while(1){

		  LCD_vidWriteString("Get Location" ); //This function displays the text "Get Location" on the LCD display.
		      _delay_ms(2000); //This function causes a delay of 2000 milliseconds (2 seconds).
		      LCD_vidSendCommand(lcd_Clear); //This function clears the LCD display.
		      receive();  //This function receives data from the GPS module and stores it in a buffer.
		      get_latitude(&latitude); //This function extracts the latitude data from the GGA message and stores it in the latitude variable in decimal values
		      get_longitude(&longitude);////This function extracts the longtude data from the GGA message and stores it in the latitude variable in decimal values
              LCD_vidWriteString("Lati:");
		      LCD_vidWriteString(&latitude);// display latitude
		      _delay_ms(2000);
		      LCD_vidSendCommand(0x40);
		      LCD_vidWriteString("Long:");
		      LCD_vidWriteString(&longitude);// display latitude
		       _delay_ms(2000);
	}
}
