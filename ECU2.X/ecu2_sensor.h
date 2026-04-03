
#ifndef ECU2_SENSOR_H
#define	ECU2_SENSOR_H

#include <stdint.h>

typedef enum 
{
    e_ind_off,
    e_ind_left,
    e_ind_hazard,
    e_ind_right
} IndicatorStatus;

uint16_t get_rpm();
IndicatorStatus process_indicator();
void delay(unsigned short factor);

#endif	/* ECU2_SENSOR_H */

