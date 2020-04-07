#include "Arduino.h"

class EcranLcd
{
  public:
    
    void AffichageLcd(char sequence_name, char equipement_name, char cannaux_dmx[8]);
    
    void EnvoyerDataAuLcd(char sequence_name, char equipement_name, char cannaux_dmx[8]);

    void LCD(char Data[4]);
    
  
};
