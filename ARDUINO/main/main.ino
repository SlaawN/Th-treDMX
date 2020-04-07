#include "EcranLcd.h"
#include "Capteurs.h"
#include "Joystick.h"
#include "ArduinoOtherFonctions.h"



void setup() 
{
Serial.begin(9600); //Initialisation de la communication avec la console


}

void loop() 
{
  
  
  Capteurs capteur;
  Joystick joystick;

  
  //capteur.LireValeur();
      
  //capteur.SendValToSerial();

  //joystick.LireJoystick(A0,A1,7);
  // joystick.SendPositionJoystickToSerialPort();

String readStr = Serial.readStringUntil(";");
if(readStr.length() > 0)
{
    int nbResult;
    char ** splited = ArduinoOtherFonctions::splitString(readStr.c_str(), ",", &nbResult);
    
  while(nbResult > -1)
  {
    Serial.println(splited[nbResult]);
  }
        
    
   

    
}

}
