//---------------------------------------------------------------------------

#ifndef IhmH
#define IhmH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <PortSerie.h>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants g�r�s par l'EDI
	TButton *BoutonOuverturePort;
	TButton *BoutonFermeturePort;
	TButton *BoutonLecturePort;
	TButton *BoutonEcriturePort;
	void __fastcall BoutonOuverturePortClick(TObject *Sender);
	void __fastcall BoutonFermeturePortClick(TObject *Sender);
	void __fastcall BoutonLecturePortClick(TObject *Sender);
	void __fastcall BoutonEcriturePortClick(TObject *Sender);

private:

PortSerie * Port;

public:		// D�clarations utilisateur
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
