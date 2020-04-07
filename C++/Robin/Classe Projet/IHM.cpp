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

	MemoClasse->Visible=false;
	ListBoxSeq->Visible=false;
	LabelSeq->Visible=false;
	LabelScene->Visible=false;
	LabelAideNom->Visible=false;
	EditNomScene->Visible=false;
	EditNbSeq->Visible=false;
	LabelNbSeq->Visible=false;
	EditTpsPause->Visible=false;
	LabelTpsPause->Visible=false;
	EditDureeSeq->Visible=false;
	LabelDureeSeq->Visible=false;
	NbTrackBar =8;
	NomScene ="";
	ActiveTimerTrame = 0;
	NbSeqActu=0;
	ButtonValidSeq->Visible=false;
}
//---------------------------------------------------------------------------
// Quand une des ScrollBars bouge
void __fastcall TForm1::MyTrackBarChange(TObject *Sender)
{
	// envoie la position des scrollBars dans la variable de classe.
	UnicodeString str = "ScrollBar ";
	TScrollBar * obj = (TScrollBar*) Sender;
	str += obj->Tag+1;
	str += " valeur ";
	int Position =255-obj->Position;
	str += Position;
	Label1->Caption = str;
	Seq[NbSeqActu]->setTrame(255-obj->Position, obj->Tag);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonClasseClick(TObject *Sender)
{

	ConnexionBDD->insert("INSERT INTO `Sequence` (`NbParametre`) VALUES (`NbTrackBar`)");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SendTrame()
{
//	if(interface_open>0)
//	{
//
//		try{
//			DasUsbCommand(DHC_DMXOUT,DMX_MAXCHANNEL,dmxBlock);
//		}
//		catch(int x)
//		{
//		}
//	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerSendTrameTimer(TObject *Sender)
{
	if (ActiveTimerTrame==0) {
		//SendTrame();
	}
	else{
		strcpy(dmxBlock,Seq[NbSeqActu]->getTrameFull());
		// appel la fonction d'envoie de la trame au boitier
		//SendTrame();
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Modification1Click(TObject *Sender)
{
	ListBoxSeq->Visible=true;
	LabelSeq->Visible=true;
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
	// Recupere les données que m'envoie le client connecté
	TrameSocket = AContext->Connection->IOHandler->ReadByte();
	// deconnecte le client
	AContext->Connection->Disconnect();
	Memo2->Lines->Add(TrameSocket);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ServeurDMXConnect(TIdContext *AContext)
{
	// Affiche l'adresse IP du client qui vient de se connecté
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


void __fastcall TForm1::Supression1Click(TObject *Sender)
{
	MemoClasse->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CreationSceneClick(TObject *Sender)
{
		LabelScene->Top=27;
		LabelScene->Visible=true;
		EditNomScene->Visible=true;
		LabelAideNom->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EditNomSceneKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	NomScene ="Nom de la scene : ";
	NomScene+=EditNomScene->Text;
	LabelScene->Caption=NomScene;
	if (Key==VK_RETURN) {
		LabelScene->Caption=NomScene;
		if (LabelScene->Caption=="")
		{

		}
		else
		{
			LabelScene->Caption=NomScene;
			NomScene ="";
			EditNomScene->Text ="";
			LabelScene->Top=0;
			LabelScene->Font->Size=15;
			LabelScene->Left=120;
			LabelScene->Visible=false;
			LabelAideNom->Visible=false;
			EditNomScene->Visible=false;
			EditTpsPause->Visible=true;
			LabelTpsPause->Visible=true;

		}

	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::EditNbSeqKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if (Key==VK_RETURN)
	{
		NbSeqMax=EditNbSeq->Text.ToInt();
		if (LabelScene->Caption==""){
		}
		else{
				for(int i = 0 ; i < NbTrackBar; i++)
				{
					ScrollB[i] = new TScrollBar(this);
					ScrollB[i]->Parent = this;
					ScrollB[i]->Max=255;
					ScrollB[i]->Left = i * 50 + 30;
					ScrollB[i]->Top = 120;
					ScrollB[i]->Tag = i;
					ScrollB[i]->Max = 255;
					ScrollB[i]->Position = 255;
					ScrollB[i]->Kind=sbVertical;
					ScrollB[i]->OnChange = MyTrackBarChange;
					edit[i] = new TEditHisto(this, ScrollB[i]);
					edit[i]->Width=33;
					edit[i]->Top=60;
					edit[i]->Left = i * 50 + 25;
					dmxBlock[i] = ScrollB[i]->Position;
					Seq[NbSeqActu] = new Sequence(i,0);
				}
			UnicodeString IdSeq;
			IdSeq="Id de la sequence : ";
			IdSeq+=NbSeqActu+1;
			LabelidSeq->Caption=IdSeq;
			EditNbSeq->Visible=false;
			LabelNbSeq->Visible=false;
			LabelScene->Visible=true;
			EditDureeSeq->Visible=true;
			LabelDureeSeq->Visible=true;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonValidSeqClick(TObject *Sender)
{
	EditDureeSeq->Text="";
	ButtonValidSeq->Visible=false;

	for(int i = 0 ; i < NbTrackBar; i++)
	{
		ScrollB[i]->Free();
		edit[i]->Free();
	}
	if (NbSeqActu<NbSeqMax)
	{
		Seq[NbSeqActu]->setTrameFull(dmxBlock);
		ConnexionBDD->insert("INSERT INTO `Sequence` (`IdScene`,`IdSequence`,`Duree`,) VALUES (`1`,`NbSeqActu`,`DureeSeq`)");
		NbSeqActu++;
		UnicodeString IdSeq;
		IdSeq="Id de la sequence : ";
		IdSeq+=NbSeqActu+1;
		LabelidSeq->Caption=IdSeq;
		for(int i = 0 ; i < NbTrackBar; i++)
		{
			ScrollB[i] = new TScrollBar(this);
			ScrollB[i]->Parent = this;
			ScrollB[i]->Max=255;
			ScrollB[i]->Left = i * 50 + 30;
			ScrollB[i]->Top = 120;
			ScrollB[i]->Tag = i;
			ScrollB[i]->Max = 255;
			ScrollB[i]->Position = 255;
			ScrollB[i]->Kind=sbVertical;
			ScrollB[i]->OnChange = MyTrackBarChange;
			edit[i] = new TEditHisto(this, ScrollB[i]);
			edit[i]->Width=33;
			edit[i]->Top=60;
			edit[i]->Left = i * 50 + 25;
			dmxBlock[i] = ScrollB[i]->Position;
			Seq[NbSeqActu] = new Sequence(NbSeqActu,0);
		}
	}
	if (NbSeqActu==NbSeqMax) {
		for(int i = 0 ; i < NbTrackBar; i++)
		{
			ScrollB[i]->Free();
			edit[i]->Free();
		}
		MessageBox(NULL,"La scene est parametrer","Sah Quel plaisir",0);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EditTpsPauseKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if (Key==VK_RETURN)
	{
		TpsPause=EditTpsPause->Text.ToInt();
        EditNbSeq->Visible=true;
		LabelNbSeq->Visible=true;
        EditTpsPause->Visible=false;
		LabelTpsPause->Visible=false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EditDureeSeqKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if (Key==VK_RETURN)
	{
		DureeSeq=EditDureeSeq->Text.ToInt();
		ButtonValidSeq->Visible=true;
    }
}
//---------------------------------------------------------------------------

