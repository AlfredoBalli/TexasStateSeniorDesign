
#ifndef m_Temp_h
#define m_Temp_h

#include "Arduino.h"

class a_motor_Temp
{
  private:
  bool          _temp_Flag1;
  bool          _temp_Flag2;
  int           _temp_Counter1;
  int           _temp_Counter2;
  int           _temp_Sample_Ammt;
  float         _temp_Cumalitive_Sample;
  float         _temp_Inital_Sample;
  float         _temp_Average1;
  float         _temp_boundC;
  float         _bound_tempF;
  int           _pin;
  unsigned long _temp_Sample_mSecs;
  unsigned long _temp_Timer;

 public:
  a_motor_Temp(int pin, float bound);
  void mTemp_Test(float tC,  unsigned long milli);
  bool flag1_Test();
  bool flag2_Test();
  void flag2_Set(bool flag);
  void counter2_Set(int cnt);


};




#endif
