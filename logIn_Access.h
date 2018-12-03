#ifndef logIn_Access_h
#define logIn_Access_h
#include "Arduino.h"

class logIn_Access
{
     private:
      
      String _password = "D1*SOLARTEAM";
      String _userName = "Solar Squad";
      String _answer;

      bool   _passwordFlag;
      bool   _usernameFlag;


  public:
           logIn_Access();
      bool passwordFlagTest();
      bool userNameFlagTest();
      void logInTest(String un, String pass);
 
  








  
};

#endif
