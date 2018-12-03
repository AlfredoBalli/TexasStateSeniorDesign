//Code designed and implimented by Alfredo Balli and Chase Berndt
//
//** = work still needing to be done


#include <StaticThreadController.h>
#include <Thread.h>
#include <ThreadController.h>
#include "Metro.h"
#include "OneWire.h"
#include "DallasTemperature.h"
#include "a_motor_Temp.h"
#include "sensor_Data.h"
#define temp_BUS 2
#define potentiometer 4


OneWire oneWire(temp_BUS);
DallasTemperature temp(&oneWire);
int pin = 5;
float bound = 55.0f;
a_motor_Temp mTemp(pin, bound);
sensor_Data Data = sensor_Data();



unsigned long t = 300;
unsigned long tt = 0;
Metro batteryTempTimer = Metro(100);

void setup(){
pinMode(3, OUTPUT);
Serial.begin(9600);
temp.begin();

}

void loop(){
  unsigned long milli = millis();
  if(milli-tt > t)
  {
    Data.sensor_Output(milli);
    tt = milli;
  }
 
    if(batteryTempTimer.check())                                  //Timer to check battery temp. **Maybe use this timer to test all temp
     {                                                            //                               sensors. Timing work to be done.**
        temp.requestTemperatures();//Temperature request
        mTemp.mTemp_Test(temp.getTempCByIndex(0), milli);       //pass the time in milliseconds as well as the
                                                                //
     }    

    if(mTemp.flag2_Test()==false )                          //**specify the rest of the cases that will cause the loop to enter 
     {                                                       //a hard error state. As well as determine what will actually happen 
                                                             //in the **  
     

      //Enter what will happen in the hard error state.
      //Pererably a while loop that opens the contactor and displays what caused the error.
      //As well as determine if 

 
     }
     
   
  
 
  }
