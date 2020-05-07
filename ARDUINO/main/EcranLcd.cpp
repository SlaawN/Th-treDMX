#include "EcranLcd.h"
#include "U8glib.h"

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

 Adafruit_SH1106 display(23); 




void EcranLcd::AffichageLcd(char sequence_name, char equipement_name, char cannaux_dmx[8])
{
  
  
}


void EcranLcd::EnvoyerDataAuLcd(char sequence_name, char equipement_name, char cannaux_dmx[8])
{
  
}


void EcranLcd::LCD(char Data[4])
{
  
   
  display.begin();
  display.clearDisplay();

  display.setCursor(0, 0);
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.print(Data[0]);

  display.setCursor(0, 12);
  display.setTextSize(2);
  display.print(Data[1]);

  display.setCursor(0, 24);
  display.setTextSize(2);
  display.print(Data[2]);

  display.setCursor(0, 36);
  display.setTextSize(2);
  display.print(Data[3]);
  
  display.setCursor(0, 48);
  display.setTextSize(2);
  display.print(Data[4]);
  
  display.display();
  delay(1000);
  display.clearDisplay();



}
