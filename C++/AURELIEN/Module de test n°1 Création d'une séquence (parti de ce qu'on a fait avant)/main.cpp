﻿/*
	Page Principale du programme qui contient les aspects graphiques
	et qui s'occupe des appels de fonctions necessaires pour modifier
    les couleurs.

	Jouen Matthias -- Developpeur
*/

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "include/DasHard.h.h"
#include <winsock2.h>
	typedef int socklen_t;
//#include "include/DasHard2006.dll"

#include "main.h"
#include "fonctions.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Web.Win.Sockets"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

	#if defined (WIN32)
		WSADATA WSAData;
		int erreur = WSAStartup(MAKEWORD(2,2), &WSAData);
	#else
		int erreur = 0;
	#endif

	SOCKADDR_IN sin;
	if(!erreur)
	{
		Textco->Visible = false;
		g_dasusbdll=LoadLibrary(L"DasHard2006.dll");
		if(g_dasusbdll)
		{
			DasUsbCommand=(DASHARDCOMMAND)::GetProcAddress((HMODULE)g_dasusbdll,"DasUsbCommand");
		}
		interface_open=DasUsbCommand(DHC_INIT,0,NULL);
		DasUsbCommand(DHC_OPEN,0,0);

		if (interface_open == 136)
		{
		   Connect->Color = clLime;
		}
		else
		{
			Connect->Color = clRed;
			Textco->Visible = true;
		}

		for (int i = 0; i < 512; i++)
		{
			dmxBlock[i]=0;
		}
		dmxBlock[0]=0xFF;
		dmxBlock[1]=0xFF;
		dmxBlock[2]=0xFF;
		dmxBlock[3]=0xFF;
		dmxBlock[4]=0xFF;
		dmxBlock[5]=0xFF;

	}
	dmx = new Couleurs(dmxBlock);  //instanciation d'un nouvel attribut de classe
}

//---------------------------------------------------------------------------
 void __fastcall TForm1::SendTrame()
 {
	if(interface_open>0)
	{
		try
		{
			DasUsbCommand(DHC_DMXOUT,DMX_MAXCHANNEL,dmxBlock);  //methode d'envoi de trames
		}
		catch(int x)
		{
		}
	}

 }

 void __fastcall TForm1::FormClose(TObject*Sender,TCloseAction&Action)
 {
 //FermetureduDMX�l'arretduprogramme
	if(interface_open>0)
	{
		DasUsbCommand(DHC_CLOSE,0,0);
		DasUsbCommand(DHC_EXIT,0,NULL);
	}
	if(g_dasusbdll!=NULL)
	FreeLibrary(g_dasusbdll);
 }

//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	SendTrame();//on envoi en continu les trames dmxBlock[]
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BleuClick(TObject *Sender)
{
	dmx->Bleu();//appel fonction bleu
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BlancClick(TObject *Sender)
{
	dmx->Blanc(); //appel fonction blanc
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RougeClick(TObject *Sender)
{
	dmx->Rouge();//appel fonction rouge
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ONClick(TObject *Sender)
{
	dmx->ON();//appel fonction Allumage
	Connect->Color = clLime;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OFFClick(TObject *Sender)
{
	dmx->OFF();//appel fonction Fermeture
	Connect->Color = clRed;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StroboscopeClick(TObject *Sender)
{
	dmx->Stroboscope();//appel fonction Stroboscope
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DMXServerConnect(TIdContext *AContext)
{
	//LMessage->Items->Add(AContext->Binding->PeerPort);   //affichage du port
	LMessage->Items->Add("IP client :" + AContext->Binding->PeerIP);  //affichage de l'ip client
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerONClick(TObject *Sender)
{
 Labeltcp->Caption="Le serveur est en cours d'exécution";
 DMXServer->Active= true;
 LMessage->Visible=true;
 ServerON->Visible=false;
 ServerOFF->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DMXServerExecute(TIdContext *AContext)
{
	Labeltcp->Caption="Le serveur a reçu";
	Labeltcp->Caption="Le serveur est en cours d'exécution";


	text = AContext->Connection->IOHandler->ReadByte();
	AContext->Connection->Disconnect();


	if (text == "49"){//49 en ascii equivaut à 1 decimal
		dmx->Rouge();
		LMessage->Items->Add("Rouge");
	}
	if (text == "50"){//50 en ascii equivaut à 2 decimal
		dmx->Vert();
		LMessage->Items->Add("Vert");
	}
	if (text == "51"){ //51 en ascii equivaut à 3 decimal
		dmx->Bleu();
		LMessage->Items->Add("Bleu");
	}
	if (text == "52"){  //52 en ascii equivaut à 4 decimal
		dmx->Blanc();
		LMessage->Items->Add("Blanc");
	}
	if (text == "53"){//53 en ascii equivaut à 5 decimal
		dmx->Stroboscope();
		LMessage->Items->Add("Stroboscope");
	}
	if (text == "54"){ //54 en ascii equivaut à 6 decimal
		dmx->ON();
		LMessage->Items->Add("ON");
	}
	if (text == "55"){ //55 en ascii equivaut à 7 decimal
		dmx->OFF();
		LMessage->Items->Add("OFF");
	}
	if (text == "56") {//56 en ascii equivaut à 8 decimal
		dmx->Jaune();
        LMessage->Items->Add("Jaune");
	}


}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerOFFClick(TObject *Sender)
{
	DMXServer->Active=false;
	LMessage->Visible =false;
	ServerOFF->Visible=false;
	ServerON->Visible=true;
	Labeltcp->Caption="Le serveur est éteint";
    LMessage->Items->Clear();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::VertClick(TObject *Sender)
{
    dmx->Vert(); //appel fonction Vert
}
//---------------------------------------------------------------------------

