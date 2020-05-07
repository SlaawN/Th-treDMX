//---------------------------------------------------------------------------

#pragma hdrstop

#include "PortSerie.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------

#pragma hdrstop
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <tchar.h>
#include <stdio.h>

#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)

// initialisation
PortSerie::PortSerie()   //Constructeur
{
	ignoreData = true;
}
//------------------------------------------------------------------------------------//

PortSerie::~PortSerie()  //destructeur
{
}

//------------------------------------------------------------------------------------//
void PortSerie::fermerport()   //Methode pour fermer le port
{
	CloseHandle(hCom); // fermeture du port s»rie
}

//------------------------------------------------------------------------------------//
// connexion au port COM1
int PortSerie::ouvrirport()
{
	DCB dcb;
	BOOL fSuccess;
	// pcComPort : Port com correspondant
	char * pcCommPort = "COM6";


   hCom = CreateFile( pcCommPort,   //nom du port
					  GENERIC_READ | GENERIC_WRITE,  //lecture et ecriture
					  0,      // pas de partage
					  NULL,   //  Aucune s»curit»
					  OPEN_EXISTING, // ouvre le port existant uniquement
					  0,      //  E/S non superpos»
					  NULL ); //  Null pour les periph»rique de communnication

   if (hCom == INVALID_HANDLE_VALUE)
   {

	   return (1);
   }

   //  Structure DCB (permet de controler :d»bit de bauds, nb de bit de d»marrage/d'arrÕt, format de donn»es)
   SecureZeroMemory(&dcb, sizeof(DCB));
   dcb.DCBlength = sizeof(DCB);

   // recup»ration des paramÀtres actuels du port
   fSuccess = GetCommState(hCom, &dcb);

   if (!fSuccess)
   {

	  printf ("GetCommState failed with error %d.", GetLastError());
	  return (2);
   }

   // On d»finit les valeurs (debit de bauds, taille des octets, nb de bits de d»marage et d'arrÕt)
   dcb.BaudRate = CBR_9600;     //  baudRate = 9600
   dcb.ByteSize = 8;             //  ByteSize
   dcb.Parity   = NOPARITY;      //  Parit» = aucune
   dcb.StopBits = ONESTOPBIT;    //  stop bit

   fSuccess = SetCommState(hCom, &dcb); // configuration du port s»rie selon la structure DCB

   if (!fSuccess)
   {
	  //  Handle the error.
	  printf ("SetCommState failed with error %d.", GetLastError());
      return (3);
   }

   //  Get the comm config again.
   fSuccess = GetCommState(hCom, &dcb);

   if (!fSuccess)
   {
      //  Handle the error.
	  printf ("GetCommState failed with error %d.", GetLastError());
	  return (2);
   }

   _tprintf (TEXT("Serial port %s successfully reconfigured."), pcCommPort);
   return (0);

}


//------------------------------------------------------------------------------------//


//Lecture du port s»rie

void PortSerie::lireport()
{
	Vcontinue = false;
	isRead = false;
	do
	{
		isRead = ReadFile(hCom, &recvChar, 1, &read, NULL);

		if(ignoreData)
		{
			if(recvChar == '-')
			{
				ignoreData = false;
            }
        }

		if(!ignoreData)
		{
			recvBuf.push_back(recvChar);
			if (!isRead)
			{
				Vcontinue = false;
				break;
			}
		}
	} while (Vcontinue);
}
//------------------------------------------------------------------------------------//
// recuperer la donn»e du buffer
std::deque<char> & PortSerie::getRecvBuf()
{
	return recvBuf;
}

//-------------------------------------------------------------------------------------//

//Ecriture sur le port Serie

void PortSerie::EcrirePort()
{

char lpBuffer [] = "A";
DWORD dNoOFBytestoWrite ; // Nombre d'octets á »crire dans le port
DWORD dNoOfBytesWritten = 0; // Nombre d'octets »crits sur le port
dNoOFBytestoWrite = sizeof ( lpBuffer ) ;

bool Resultat = WriteFile ( hCom ,
lpBuffer, // Donn»es á »crire sur le port
dNoOFBytestoWrite , // Nombre d'octets á »crire
& dNoOfBytesWritten , // Octets »crits
NULL ) ;
}


