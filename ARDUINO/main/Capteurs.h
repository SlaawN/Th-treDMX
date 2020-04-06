#include "Arduino.h"

#define NBPinAnalog 8
#define NBValeurALire 8

class Capteurs
{
  
private :

char pin[NBPinAnalog] = {A0,A1,A2,A3,A4,A5,A6,A7}; 
int Val[NBValeurALire]; 


public:
int LireValeur(); 
int SendValToSerial();



  

};
