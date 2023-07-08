/*
 * gps.h
 *
 *  Created on: Ù¢Ù¤â€�/Ù¡Ù â€�/Ù¢Ù Ù¢Ù¢
 *      Author: pc lab top
 */

#ifndef GPS_H_
#define GPS_H_
#include "std_types.h"
#include <stdbool.h>
#define Buffer_Size 128
#define start_Latitude 0
#define start_Longitude 0
extern volatile bool IsGGADataReceived;
extern uint8 done;

void gps_init();
double my_atof(char *str);
double gps_to_decimal(double gps_coordinate);
void get_latitude(double *latitude);
void get_longitude(double *longitude) ;
void receive();







#endif /* GPS_H_ */
