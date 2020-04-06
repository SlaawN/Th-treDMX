//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Ihm.h"
#include <PortSerie.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Port = new PortSerie();
}
//---------------------------------------------------------------------------





void __fastcall TForm1::BoutonOuverturePortClick(TObject *Sender)
{
	Port->ouvrirport();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BoutonFermeturePortClick(TObject *Sender)
{
    Port->fermerport();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BoutonLecturePortClick(TObject *Sender)
{
    Port->lireport();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BoutonEcriturePortClick(TObject *Sender)
{
 	Port->EcrirePort();
}
//---------------------------------------------------------------------------

