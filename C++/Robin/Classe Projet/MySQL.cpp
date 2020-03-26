//---------------------------------------------------------------------------

#pragma hdrstop

#include "MySQL.h"
#define HOST"192.168.64.67"
#define USER"dmx"
#define PASSWORD"dmx"
#define DATABASE"THEATRE_DMX"
#include <sstream>


//---------------------------------------------------------------------------

MySQL::MySQL(TMemo* Memo)
{
  this->Memo1=Memo;
}
bool MySQL::Connexion()
{

//	mySQL = mysql_init(NULL);
//	//mySQL, "192.168.64.67", "dmx", "dmx", "THEATRE_DMX"
//	conn=mysql_real_connect(mySQL, HOST, USER, PASSWORD, DATABASE, 0, NULL, 0);
//	if(conn==NULL)
//	{
//		return false;
//	}
//	else
//	{
	   return true;
	//}

}
bool MySQL::update(String req)
{
	//myErrorCode = mysql_errno(MyS);
//	if(myErrorCode == 0)
//	{
//		// Allocation espace m�moire
//		char requete=new char[req.Length()+1];
//		// Conversion de String en char
//		wcstombs(requete,req.c_str(),req.Length()+1);
//		// Envoie de la requ�te
//		if(!mysql_query(mySQL,requete)){
//			Etat = true;
//		}else{
//			Etat = false;
//		}
//	}else{
//		//Renvoie l'erreur
//		myErrorMsg = mysql_error(MyS);
//		*MSG_Error = myErrorMsg;
//		Etat = false;
//	}
//	return Etat;
}
bool MySQL::insert(String req)
{
	//myErrorCode = mysql_errno(MyS);
//	if(myErrorCode == 0)
//	{
//		// Allocation espace m�moire
//		char requete=new char[req.Length()+1];
//		// Conversion de String en char
//		wcstombs(requete,req.c_str(),req.Length()+1);
//		// Envoie de la requ�te
//		if(!mysql_query(mySQL,requete)){
//			Etat = true;
//		}else{
//			Etat = false;
//		}
//	}else{
//		//Renvoie l'erreur
//		myErrorMsg = mysql_error(MyS);
//		*MSG_Error = myErrorMsg;
//		Etat = false;
//	}
//	return Etat;
}
bool MySQL::supp(String req)
{
	//myErrorCode = mysql_errno(MyS);
//	if(myErrorCode == 0)
//	{
//		// Allocation espace m�moire
//		char requete=new char[req.Length()+1];
//		// Conversion de String en char
//		wcstombs(requete,req.c_str(),req.Length()+1);
//		// Envoie de la requ�te
//		if(!mysql_query(mySQL,requete)){
//			Etat = true;
//		}else{
//			Etat = false;
//		}
//	}else{
//		//Renvoie l'erreur
//		myErrorMsg = mysql_error(MyS);
//		*MSG_Error = myErrorMsg;
//		Etat = false;
//	}
//	return Etat;
}
bool MySQL::select(AnsiString req,vector<String> *ResultSelect)
{
	vector<String> c_resultat;
//		if (!mysql_query(mySQL, req.c_str()))
//		{
//			myRES = mysql_store_result(mySQL);
//			if (myRES)
//			{
//				for(unsigned int i = 0; i < myRES->row_count; i++)
//				{
//					myROW = mysql_fetch_row(myRES);
//					for(unsigned int j = 0; j < mysql_num_fields(myRES); j++)
//					{
                        c_resultat.push_back("5");
						//c_resultat.push_back(myROW[j]);
						//AnsiString aStr = myROW[j];
						//this->Memo1->Lines->Add(req);
//					}
//				}
//				mysql_free_result(myRES);
//			}
//		}
	   *ResultSelect = c_resultat;
	   return true;
}

#pragma package(smart_init)
