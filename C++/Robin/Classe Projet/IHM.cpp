//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "TEditHisto.h"
#include "IHM.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
    // charge la dll
	g_dasusbdll=LoadLibrary("DasHard2006.dll");
	// recupere l'adresse du DMX
	if(g_dasusbdll)
	{
		DasUsbCommand=(DASHARDCOMMAND)::GetProcAddress((HMODULE)g_dasusbdll,"DasUsbCommand");
	}
	// ouvre la connexion à l'interface du DMX
	interface_open=DasUsbCommand(DHC_INIT,0,NULL);
	DasUsbCommand(DHC_OPEN,0,0);
	//lblResultOpenDMX->Caption=interface_open;
	// initialise les valeurs a zero
	for (int i = 0; i < 512; i++) {
		dmxBlock[i]=0;
	}
	NbTrackBar=6;
	for(int i = 0 ; i < NbTrackBar; i++)
	{
		TScrollBar * ScrollB = new TScrollBar(this);
		ScrollB->Parent = this;
		TEditHisto * edit = new TEditHisto(this, ScrollB);
		edit->Width=33;
		edit->Top=10;
		edit->Left = i * 50 + 25;
		ScrollB->Max=255;
		ScrollB->Left = i * 50 + 30;
		ScrollB->Top = 60;
		ScrollB->Tag = i;
		ScrollB->Max = 255;
		ScrollB->Position = 255;
		ScrollB->Kind=sbVertical;
		ScrollB->OnChange = MyTrackBarChange;
		dmxBlock[i] = ScrollB->Position;
		Seq = new Sequence(i,0,dmxBlock[i]);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MyTrackBarChange(TObject *Sender)
{
	UnicodeString str = "Bar appelante ";
	TScrollBar * obj = (TScrollBar*) Sender;
	str += obj->Tag;
	str += " valeur ";
	int Position =255-obj->Position;
	str += Position;
	Label1->Caption = str;
	Seq->setTrame(255-obj->Position, obj->Tag);
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	for (int i = 0; i < NbTrackBar; i++)
	{
		dmxBlock[i]=Seq->getTrame(i);
		Memo1->Lines->Add(dmxBlock[i]);
	}
	Connexion = new MySQL();
	AnsiString thierry="deux";
	Connexion->select(thierry,Memo1);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::SendTrame()
{
	if(interface_open>0)
	{

		try{
			DasUsbCommand(DHC_DMXOUT,DMX_MAXCHANNEL,dmxBlock);
		}
		catch(int x)
		{
		}
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	for (int i = 0; i < NbTrackBar; i++)
	{
		dmxBlock[i]=Seq->getTrame(i);
	}
	SendTrame();
}
//---------------------------------------------------------------------------

