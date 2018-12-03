#include "sensor_Data.h"



sensor_Data::sensor_Data()
{

  _battery_Temp;
  _emc_Temp;
  _motor_Temp;
  _duty_Cycle;
  _motor_Amp;


}


void sensor_Data::sensor_Output(unsigned long milli)
{

    //time in miliseconds
    //Serial.print(milli);

    //*Make more temperature variables for battery*
    //battery Temerature
    Serial.print(_battery_Temp);

    //EMC temerpature
    Serial.print(_emc_Temp);

    //Motor Temerature
    Serial.println(_motor_Temp);

    //Duty Cycle
    Serial.print(_duty_Cycle);

     //*Think about how to measure power over Current by taking the voltage sent by the duty cycle and
     //multiplying by the current from hall effecct sensor.+*
    
    //Motor Current
    Serial.println(_motor_Amp);

    


}


void sensor_Data::sensor_setValues(float b_temp, float e_temp, float m_temp, float duty, float amp)
{

  _battery_Temp=b_temp;
  _emc_Temp=e_temp;
  _motor_Temp=m_temp;
  _duty_Cycle=duty;
  _motor_Amp=amp;
}
