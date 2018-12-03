
#ifndef sensor_Data_h
#define sensor_Data_h

#include "Arduino.h"

class sensor_Data
{


private:

float _battery_Temp;
float _emc_Temp;
float _motor_Temp;
float _duty_Cycle;
float _motor_Amp;


public:
sensor_Data();
void sensor_Output(unsigned long milli);
void sensor_setValues(float b_temp, float e_temp, float m_temp, float duty, float amp);

#endif


};
