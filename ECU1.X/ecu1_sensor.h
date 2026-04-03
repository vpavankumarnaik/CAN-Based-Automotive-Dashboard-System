
#ifndef ECU1_SENSOR_H
#define	ECU1_SENSOR_H

#include <stdint.h>

unsigned char get_speed();
unsigned char change_gear(void);
void delay(unsigned short factor);

#endif	/* ECU1_SENSOR_H */