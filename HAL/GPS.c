#include "GPS.h"

#include "uart1.h"
#include <avr/io.h>
#include <string.h>
#include <stdbool.h>
#include "dio.h"
#include "lcd.h"


unsigned char value,lati_value[15],longi_value[15],lati_dir,longi_dir;
uint8 i,j=0;
uint8 done=0;

void gps_init()//This function initializes the GPS module and sets up the necessary communication settings.
{
	UART_Init();
}

void receive() {  /*This function receives data from the GPS module and stores it in a buffer. The function likely uses a UART (Universal Asynchronous Receiver/Transmitter) interface to communicate with the GPS module,
 but the details of how the function receives the data are not shown in this code snippet.*/


	  while(UART_GetChar()!='$'){};

		  value=UART_GetChar();
	   if(value=='G')
	   {
		   value=UART_GetChar();
	    if(value=='P')
	    {
	    	value=UART_GetChar();
	     if(value=='G')
	     {
	    	 value=UART_GetChar();
	      if(value=='G')
	      {
	    	  value=UART_GetChar();
	       if(value=='A')
	       {
	    	   value=UART_GetChar();
	        if(value==',')
	        {
	        	value=UART_GetChar();

	        	while(value!=',')
	        	         {

	        	          value=UART_GetChar();
	        	         }

	        	unsigned char check =UART_GetChar();
if(check=='0' ||check=='1'||check=='2'||check=='3'||check=='4'||check=='5'||
		check=='6'||check=='7'||check=='8' ||check=='9'|| check=='.' )
	        	{
	        	lati_value[0]=check;
	        	         value=lati_value[0];
	        	         for(i=1;value!=',';i++)
	        	         {
	        	          lati_value[i]=UART_GetChar();
	        	          value=lati_value[i];
	        	         }
	        	         lati_value[i-1]='\0';
	        	         lati_dir=UART_GetChar();

	        	}
else {
	return ;
}
	        	         value=UART_GetChar();
	        	         while(value!=',')
	        	                 {
	        	                  value=UART_GetChar();
	        	                 }

	        	                 longi_value[0]=UART_GetChar();
	        	                value=longi_value[0];
	        	                 for(i=1;value!=',';i++)
	        	                 {
	        	                  longi_value[i]=UART_GetChar();
	        	                  value=longi_value[i];
	        	                 }
	        	                 longi_value[i-1]='\0';
	        	                 longi_dir=UART_GetChar();
	        	                 j =1;
	        	                }
	        	               }
	        	              }
	        	             }
	        	            }
	        	          }
	   if(j==1){
		   j=0;
		   done=1;

	   }

}

 double my_atof(char *str)/*This function converts a string of characters (str) to a double-precision floating-point number.
  This is often used for converting GPS coordinates, which are typically received as strings in a specific format, into decimal values.*/
 {
	      double result = 0.0;
	      double factor = 1.0;
	      int i = 0;
	      int sign = 1;

	      if (str[i] == '-') {
	          sign = -1;
	          i++;
	      }

	      while (str[i] != '\0' && str[i] != '.') {
	          result = result * 10.0 + (double)(str[i] - '0');
	          i++;
	      }

	      if (str[i] == '.') {
	          i++;
	          while (str[i] != '\0') {
	              result = result * 10.0 + (double)(str[i] - '0');
	              factor *= 10.0;
	              i++;
	          }
	      }

	      result /= factor;
	      result *= sign;

	      return result;
	  }

 double gps_to_decimal(double gps_coordinate) {  //: This function converts a GPS coordinate from the format it is received in (degrees, minutes, and seconds) to decimal degrees format.
 	      int degrees = (int)gps_coordinate / 100;
 	      double minutes = fmod(gps_coordinate, 100.0);
 	      double decimal_degrees = degrees + (minutes / 60);
 	      return decimal_degrees;
 	  }


void get_latitude(double *latitude) {
			  double lat= my_atof(lati_value);
			   *latitude = gps_to_decimal(lat);
		  }
 void get_longitude (double *longitude){
			  double longi=my_atof(longi_value);
			 *longitude = gps_to_decimal(longi);
		  }



















