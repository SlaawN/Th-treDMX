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
#include "Scene.h"
#include"include/DasHard.h.h"
#include "MySQL.h"
#include "LiaisonSerie.h"
#include <Vcl.Menus.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdCustomTCPServer.hpp>
#include <IdTCPServer.hpp>
#include <IdContext.hpp>
#include <sstream>
#include <deque>
#include <vector>
#include <Windows.h>
#include <string>
#define DMX_MAXCHANNEL 512
using namespace std;
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants gérés par l'EDI
	//void __fastcall MonEditKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	TLabel *Label1;
	TMemo *MemoClasse;
	TTimer *TimerSendTrame;
	TMainMenu *MainMenu1;
	TMenuItem *Scene1;
	TMenuItem *CreationScene;
	TMenuItem *Modification2;
	TMenuItem *Supression2;
	TMenuItem *Programme1;
	TMenuItem *Creation3;
	TMenuItem *Modification3;
	TMenuItem *Supression3;
	TIdTCPServer *ServeurDMX;
	TButton *ActiveServ;
	TMemo *Memo2;
	TPanel *Panel1;
	TButton *CloseServ;
	TTimer *TimerPortSerie;
	TListBox *ListBoxSeq;
	TLabel *LabelSeq;
	TEdit *EditNomScene;
	TLabel *LabelScene;
	TLabel *LabelAideNom;
	TEdit *EditNbSeq;
	TLabel *LabelNbSeq;
	TButton *ButtonValidSeq;
	TLabel *LabelTpsPause;
	TEdit *EditTpsPause;
	TEdit *EditDureeSeq;
	TLabel *LabelDureeSeq;
	TLabel *LabelidSeq;
	void __fastcall FormClose(TObject*Sender,TCloseAction&Action);
	void __fastcall MyTrackBarChange(TObject *Sender);
	void __fastcall ButtonClasseClick(TObject *Sender);
	void __fastcall TimerSendTrameTimer(TObject *Sender);
	void __fastcall Modification1Click(TObject *Sender);
	void __fastcall ActiveServClick(TObject *Sender);
	void __fastcall ServeurDMXExecute(TIdContext *AContext);
	void __fastcall ServeurDMXConnect(TIdContext *AContext);
	void __fastcall TimerPortSerieTimer(TObject *Sender);
	void __fastcall CloseServClick(TObject *Sender);
	void __fastcall Supression1Click(TObject *Sender);
	void __fastcall CreationSceneClick(TObject *Sender);
	void __fastcall EditNomSceneKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall EditNbSeqKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall ButtonValidSeqClick(TObject *Sender);
	void __fastcall EditTpsPauseKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall EditDureeSeqKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);





private:	// Déclarations utilisateur
	HINSTANCE g_dasusbdll;
	typedef int(*DASHARDCOMMAND)(int,int,unsigned char*);
	DASHARDCOMMAND DasUsbCommand;
	int interface_open;
	unsigned char dmxBlock[512];
	Sequence * Seq[100];
	int NbTrackBar;
	MySQL *ConnexionBDD;
	bool ConnectBDD;
	TScrollBar * ScrollB[8];
	TEditHisto * edit[8];
	UnicodeString TrameSocket;
	UnicodeString NomScene;
	int NbSeqMax;
	int NbSeqActu;
	int TpsPause;
	int DureeSeq;
	int ActiveTimerTrame;

	static DWORD WINAPI RecvThread(LPVOID param);
	std::deque<std::vector<char> > trames;
	HANDLE sync;
	PortLS * port;
	vector<String> ResultSelect;

public:		// Déclarations utilisateur
	__fastcall TForm1(TComponent* Owner);
		void __fastcall SendTrame();

};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
