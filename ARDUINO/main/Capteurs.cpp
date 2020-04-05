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
// Methode permettant de relever les valeurs du joystick
int Capteurs::LireJoystick(char PinX, char PinY, int PinBP)
{
  //int X  ; // Valeur potentiomètre horizotal
  //int Y ; // Valeur potentiomètre Vertical
  //int BP ; // bouton poussoir
  //String  EtatX; // etat potentiomètre horizontal
  //String EtatY; // etat potentiomètre vertical
  //String EtatBP; // etat Bouton Poussoir
  
  pinMode (PinBP,INPUT);
  digitalWrite(PinBP, HIGH);
  

  X= analogRead(PinX);
  Y= analogRead(PinY);
  
  BP= digitalRead(PinBP);
  



 //delay(1000);
}

int Capteurs::SendPositionJoystickToSerialPort()
{
  String  EtatX; // etat potentiomètre horizontal
  String EtatY; // etat potentiomètre vertical
  String EtatBP; // etat Bouton Poussoir

  if (X<480)
  {
    EtatX= "bas";
  }
  else if (X>550)
  {
    EtatX= "haut";
  }
  else
  {
    EtatX = "neutre";
  }

// ----------------------------

  if (Y<500)
  {
    EtatY= "gauche";
  }
  else if (Y>530)
  {
    EtatY= "droite";
  }
  else
  {
    EtatY = "neutre";
  }

// ------------------------
  if (BP==1)
  {
    EtatBP = "BP relache";
  }
  else 
  {
    EtatBP = "BP enfonce";
  }

  Serial.print("Potentiometre horizontal :  ");
  Serial.println(EtatX);

  Serial.print("Potentiometre vertical :  ");
  Serial.println(EtatY);

  Serial.print("Bouton Poussoir :   ");
  Serial.println(EtatBP);


  delay(1000);
  
}
