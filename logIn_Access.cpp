#include "Arduino.h"
#include "logIn_Access.h"

     logIn_Access:: logIn_Access()
     {
         
         _passwordFlag = false;
         _usernameFlag = false;
     }
     
bool logIn_Access::userNameFlagTest()
     {
        return _usernameFlag;
     }
     
bool logIn_Access::passwordFlagTest()
     {
        return _passwordFlag;
     }
     
void logIn_Access::logInTest(String un, String pass)
     {
          if ( un == _userName )
              _usernameFlag = true;
          else 
             Serial.println("username is incorrect");

              
          if ( pass == _password )
              _passwordFlag = true;
          else
              Serial.println("password is incorrect");
      }

      
