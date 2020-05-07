#include "Arduino.h"

class Joystick
{
  private:
   
  int X  ; // Valeur potentiomètre horizotal
  int Y ; // Valeur potentiomètre Vertical
  int BP ; // bouton poussoir
  
  
  public:

    int LireJoystick(char PinX, char PinY, int PinBP); // Methode permettant de relever les valeurs du joystick
    int SendPositionJoystickToSerialPort(); //Methode permettant d'envoyer les positions du joystick sur le port série
    
    
};
