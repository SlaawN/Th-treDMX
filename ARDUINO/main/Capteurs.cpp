#include "Capteurs.h"
#include "Arduino.h"

// ----------------------------------------------------------------------------
// methode permettant de relever les valeurs des potentiomètres

int Capteurs::LireValeur()   // int Capteurs::LireValeur(int*tab)
{
  for (int i = 0; i < 8; i++) 
      {
        Val[i] = analogRead(pin[i]);
        
      }
}

// -----------------------------------------------------------------------------
// methode permettant d'envoyer les valeurs des potentiomètres sur le port série

int Capteurs::SendValToSerial()
{
  for (int ii = 0; ii < 8; ii++)
  {
    Serial.print("Case du tableau n*");
    Serial.print(ii);
    Serial.print("  =  "); 
    Serial.println(Val[ii]); 
    delay(1000);
  }
}
// ----------------------------------------------------------------------------
