
#include <xc.h>
#include "adc.h"
#include "can.h"
#include "digital_keypad.h"
#include "ecu1_sensor.h"
#include "msg_id.h"

void init_config(void)
{
    init_adc();
    init_can();
    init_digital_keypad();
}

void main(void)
{
    init_config();
    
    while (1)
    {
        unsigned char speed = get_speed();
        can_transmit( SPEED_MSG_ID , &speed, 1);
        delay(100 );
        
        unsigned char curr_gear  = change_gear();
        can_transmit( GEAR_MSG_ID , &curr_gear, 1 );
        delay(200 );
    }
}

unsigned char get_speed(void)
{
    uint16_t adc_val = read_adc(CHANNEL4);
    unsigned char speed = adc_val / 10.23;

    return speed;
}

unsigned char change_gear(void)
{
    static unsigned char gear_index = 0;
    unsigned char key;

    key = read_digital_keypad(STATE_CHANGE);

    // If currently in special mode (7) 
    if (gear_index == 7)
    {
        if (key == SWITCH1 || key == SWITCH2)
        {
            gear_index = 0;   // Go to Neutral
            return gear_index;
        }
    }

    // Normal Gear Control 
    if (key == SWITCH1 && gear_index < 6)
    {
        gear_index++;
    }
    else if (key == SWITCH2 && gear_index > 0)
    {
        gear_index--;
    }
    else if (key == SWITCH3)
    {
        gear_index = 7;   // Special index(accident)
    }

    return gear_index;
}

/* delay 1ms function */
void delay(unsigned short factor)
{
	unsigned short i, j;

	for (i = 0; i < factor; i++);
}