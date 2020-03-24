class Capteurs
{
private :

int Analog[8];
int adresse;

public:
int LireValeur(int*tab);
int SendValToSerial();
int Capteur(int adresse);
  

};
