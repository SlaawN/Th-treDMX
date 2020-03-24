#include "EcranLcd.h"
#include "Capteurs.h"


void setup() 
{
Serial.begin(9600); //Initialisation de la communication avec la console


}

void loop() 
{
  
    
    int  tab[8];
    Capteurs RecupVal;
    Capteurs Send;
    
    for (int i; i < 8;i++)
    {
      RecupVal.LireValeur(tab);
      
    }

    Send.SendValToSerial();

}

void splitString()
{
  
}
