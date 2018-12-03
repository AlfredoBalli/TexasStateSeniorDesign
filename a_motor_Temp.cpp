#include "Arduino.h"
#include "a_motor_Temp.h"

//pin that will open contactor, temperature bound.
a_motor_Temp::a_motor_Temp(int pin, float bound)
  {
    _temp_Sample_mSecs =2000;
    _temp_Timer = 0;
    _temp_Flag1 = true;
    _temp_Flag2 = true;
   _temp_Cumalitive_Sample = 0.0f; 
   _temp_Inital_Sample = 0.0f;
    _temp_boundC = bound;
    pinMode(pin, OUTPUT);
    _pin = pin;
    
  }



void a_motor_Temp::mTemp_Test(float tC,  unsigned long milli)
{
  
  _temp_Inital_Sample = tC;        //Testing sample
  _temp_Cumalitive_Sample += tC;  //Cumaltive sample to be used for average
  _temp_Counter1++;              //Samples taken in order to determine average
  
  
  
  
  //If testing sample spikes, flag is set to false.
  if( _temp_Inital_Sample > _temp_boundC)
    _temp_Flag1 = false;
  
  
  
  
  
  //If the ammount of time specified has passed or a spike occurs
  //an average temperature will be taken and values are reset
  if(milli - _temp_Timer >= _temp_Sample_mSecs  || _temp_Flag1 == false )
  {
    
    _temp_Average1 = (_temp_Cumalitive_Sample / _temp_Counter1);
    
    
    _temp_Timer = milli;
    _temp_Cumalitive_Sample = 0.0f;
    _temp_Counter1 = 0;
  }
  
  
  
  
  
  
  //If in fact a spike does occur the average temperature is then tested in order to determine if 
  //a sensor error spiked the temperature or the batteries in fact are overheating.
  if(_temp_Flag1 == false)
  {
   
    
    if(_temp_Average1 > _temp_boundC)
    { 
      _temp_Counter2++;                                           //Incrimented if avergae fails test
    
       _temp_Flag1 = true;
    }
    else if( _temp_Average1 < _temp_boundC && _temp_Counter2 > 1) //If the counter has been incrimented and the average
    {                                                             // passes test values are reset.
     _temp_Counter2 = 0;
     
      _temp_Flag1 = true;
      
    }
    else                                                         //Counter has not incrimented past one and average passes test.
    {
      _temp_Flag1 = true;
     
    }
    
    
  }
      
    
  if(_temp_Counter2 >= 8)                                        //After 8 fails in a row flag2 is set to false and hard error state is initiated.
  {
    _temp_Flag2 = false;
    
  }


    
    
}

    
    

 
 bool a_motor_Temp::flag2_Test()
 {

    return _temp_Flag2;
  
 }

  
 void a_motor_Temp::flag2_Set(bool flag)
 {

     _temp_Flag2 = flag;                            //Can be used to enter or exit the hard error state.
  
 }

 void a_motor_Temp::counter2_Set(int cnt)
 {

     _temp_Counter2 = cnt;                          //Can be used to reset counter if hard error state is triggerd.
  
 }


 
/* void a_motor_Temp::
 void a_motor_Temp::
 void a_motor_Temp::
 void a_motor_Temp::*/
