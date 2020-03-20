#include "Capteurs.h"
#include "Arduino.h"

int Capteurs::LireValeur(int A1,int A2,int A3,int A4,int A5,int A6,int A7,int A8)
{
  
            int ValPot1=analogRead(A1);
            int ValPot2=analogRead(A2);
            int ValPot3=analogRead(A3);
            int ValPot4=analogRead(A4);
            int ValPot5=analogRead(A5);
            int ValPot6=analogRead(A6);
            int ValPot7=analogRead(A7);
            int ValPot8=analogRead(A8);
            

}


int Capteurs::Capteur(int adresse)
{
  this->adresse = adresse;
}
