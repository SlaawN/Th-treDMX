//---------------------------------------------------------------------------

#ifndef SequenceH
#define SequenceH
#include <windows.h>
#include <stdlib.h>
#include <tchar.h>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <vcl.h>
//---------------------------------------------------------------------------

class Sequence
{
	private:
		int id;
		int duree;
		//trameManager* trame;
		int nbSeqUsedEq;


	public:
	   //	Sequence(int id, int duree, trameManager*);
		Sequence(int id, int duree);
		void setDuree(int duree);
		void setId(int id);
		//void setTrame(trameManager* trame);
		int getDuree();
		int getId();

};
#endif
