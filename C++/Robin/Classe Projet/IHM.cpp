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
DWORD WINAPI TForm1::RecvThread(LPVOID params)
{
	TForm1 * form = (TForm1*)params;
	while(1)
	{
		WaitForSingleObject(form->sync, INFINITE);
		form->port->lireport();

		std::deque<char> & buf = form->port->getRecvBuf();
		std::vector<char> trame;

		bool bFound = false;
		int idx = -1;
		// test si on est en fin de ligne de trame
		for(int i = 0; i < buf.size(); i++)
		{
			trame.push_back(buf[i]);
			if(buf[i] == '\n' || buf[i] == '\r')
			{
				idx = i + 1;
				bFound = true;
				break;
			}
		}
		// si on est en fin de ligne supprime la 1ere valeur
		if(bFound)
		{
			for(int i = 0; i < idx; i++)
			{
				buf.pop_front();
			}

			while(buf.size() > 0 && buf[0] != '$')
			{
				buf.pop_front();
            }

			form->trames.push_back(trame);
        }

		ReleaseMutex(form->sync);
	}
}
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Panel1->Color=clRed;
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
	ConnexionBDD = new MySQL(MemoClasse);

	if (ConnexionBDD->Connexion()==true) {
		sync = CreateMutex(NULL, FALSE, NULL);
		port = new PortLS();
		port->ouvrirport();
		DWORD threadId;
		CreateThread(NULL, 0, RecvThread, this, 0, &threadId);
	}else{
		//MessageBox(NULL,"Echec","Connexion à BDD",0);
	}
	CloseServ->Visible=false;
	EditCreaSeq->Visible=false;
	LabelCreaSeq->Visible=false;
	ButtonClasse->Visible=false;
	MemoClasse->Visible=false;
	ListBoxSeq->Visible=false;
    LabelSeq->Visible=false;
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
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonClasseClick(TObject *Sender)
{
	for (int i = 0; i < NbTrackBar; i++)
	{
		dmxBlock[i]=Seq->getTrame(i);
		UnicodeString AjoutMemo="Paramètre ";
		AjoutMemo+=i+1;
		AjoutMemo+=" :";
		AjoutMemo+=dmxBlock[i];
		MemoClasse->Lines->Add(AjoutMemo);
	}
	ConnexionBDD->insert("INSERT INTO `Sequence` (`NbParametre`) VALUES (`NbTrackBar`)");
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
	//SendTrame();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Creation1Click(TObject *Sender)
{
	EditCreaSeq->Visible=true;
	LabelCreaSeq->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Modification1Click(TObject *Sender)
{
	ListBoxSeq->Visible=true;
	LabelSeq->Visible=true;
	ButtonClasse->Visible=false;
	MemoClasse->Visible=false;
	Label1->Visible=False;
	for(int i = 0 ; i < NbTrackBar; i++)
	{
		ScrollB[i]->Free();
		edit[i]->Free();
	}
	ConnexionBDD->select("SELECT * FROM `Sequence`",&ResultSelect);
	for (int i = 0; i < ResultSelect.size(); i++) {
		 ListBoxSeq->Items->Add(ResultSelect[i]);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ActiveServClick(TObject *Sender)
{
	ServeurDMX->Active=true;
	Panel1->Color=clLime;
	ActiveServ->Visible=false;
	CloseServ->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ServeurDMXExecute(TIdContext *AContext)
{
	TrameSocket = AContext->Connection->IOHandler->ReadByte();
	AContext->Connection->Disconnect();
	Memo2->Lines->Add(TrameSocket);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ServeurDMXConnect(TIdContext *AContext)
{
	Memo2->Lines->Add("IP client :" + AContext->Binding->PeerIP);  //affichage de l'ip client
}
//---------------------------------------------------------------------------
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
void __fastcall TForm1::TimerPortSerieTimer(TObject *Sender)
{
	WaitForSingleObject(sync, INFINITE);
	UnicodeString str = "";
	int i;
	for(int j = 0; j < trames.size(); j++)
	{
		std::vector<char> buf = trames[j];
		do
		{
			str += buf[i];
			i++;
		}while (i < buf.size());
		Memo2->Lines->Add(str);
	}
	trames.clear();
	ReleaseMutex(sync);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CloseServClick(TObject *Sender)
{
	ServeurDMX->Active=false;
	Panel1->Color=clRed;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EditCreaSeqKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if (Key==VK_RETURN) {
		EditCreaSeq->Visible=false;
		LabelCreaSeq->Visible=false;
		ButtonClasse->Visible=true;
		MemoClasse->Visible=true;
		NbTrackBar=EditCreaSeq->Text.ToInt();
		if (NbTrackBar>=8) {
		   NbTrackBar=8;
		}
		for(int i = 0 ; i < NbTrackBar; i++)
		{
			ScrollB[i] = new TScrollBar(this);
			ScrollB[i]->Parent = this;
			ScrollB[i]->Max=255;
			ScrollB[i]->Left = i * 50 + 30;
			ScrollB[i]->Top = 80;
			ScrollB[i]->Tag = i;
			ScrollB[i]->Max = 255;
			ScrollB[i]->Position = 255;
			ScrollB[i]->Kind=sbVertical;
			ScrollB[i]->OnChange = MyTrackBarChange;
			edit[i] = new TEditHisto(this, ScrollB[i]);
			edit[i]->Width=33;
			edit[i]->Top=20;
			edit[i]->Left = i * 50 + 25;
			dmxBlock[i] = ScrollB[i]->Position;
			Seq = new Sequence(i,0,dmxBlock[i]);
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Supression1Click(TObject *Sender)
{
	ButtonClasse->Visible=false;
	MemoClasse->Visible=false;
}
//---------------------------------------------------------------------------

