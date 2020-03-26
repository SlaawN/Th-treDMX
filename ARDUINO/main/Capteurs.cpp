#include "Capteurs.h"
#include "Arduino.h"

// methode permettant de relever les valeurs des potentiomètres
int Capteurs::LireValeur(int*tab)
{
  for (int i = 0; i < 8; i++) 
      {
        this->Analog[i]=analogRead(tab[i]);
        
      }
}

int Capteurs::SendValToSerial()
{
  for (int i = 0; i < 8; i++)
  {
    Serial.print("Case du tableau");
    Serial.print(i);
    Serial.println(this->Analog[i]);
    delay(1000);
  }
}
    

// methode permettant d'utiliser le multiplexeur analogique
int Capteurs::Capteur(int adresse)
{
  this->adresse = adresse;
}
