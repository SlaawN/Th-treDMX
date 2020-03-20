//---------------------------------------------------------------------------

#ifndef IHMH
#define IHMH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "Sequence.h"
#include"include/DasHard.h.h"
#include <sstream>
#include <deque>
#include <vector>
#include <Windows.h>
#include <string>
#define DMX_MAXCHANNEL 512
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants gérés par l'EDI
	//void __fastcall MonEditKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	TLabel *Label1;
	TMemo *Memo1;
	TButton *Button1;
	TTimer *Timer1;
	void __fastcall MyTrackBarChange(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
private:	// Déclarations utilisateur
	HINSTANCE g_dasusbdll;
	typedef int(*DASHARDCOMMAND)(int,int,unsigned char*);
	DASHARDCOMMAND DasUsbCommand;
	int interface_open;
	unsigned char dmxBlock[512];
	Sequence * Seq;

public:		// Déclarations utilisateur
	__fastcall TForm1(TComponent* Owner);
		void __fastcall SendTrame();

};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
