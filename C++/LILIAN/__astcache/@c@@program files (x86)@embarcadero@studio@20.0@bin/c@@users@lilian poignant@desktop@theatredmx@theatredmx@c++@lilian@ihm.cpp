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
}
//---------------------------------------------------------------------------







void __fastcall TForm1::BoutonOuverturePortClick(TObject *Sender)
{
PortSerie Ouvrir;
Ouvrir.ouvrirport();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BoutonFermeturePortClick(TObject *Sender)
{
PortSerie Fermer;
Fermer.fermerport();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BoutonLecturePortClick(TObject *Sender)
{
PortSerie Lire;
Lire.lireport();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::BoutonEcriturePortClick(TObject *Sender)
{
PortSerie Ecrire;
Ecrire.EcrirePort();
}
//---------------------------------------------------------------------------

