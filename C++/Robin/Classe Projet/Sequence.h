//---------------------------------------------------------------------------

#ifndef SequenceH
#define SequenceH
#include <windows.h>
#include <stdlib.h>
#include <tchar.h>
#include <stdio.h>
#include <string.h>
#include <sstream>
//#include "TrameManager.h"
//---------------------------------------------------------------------------

class Sequence
{
	private:
		int id,duree,NbSeqAdressEq;
		//TrameManager* trame;
		unsigned char trame[512];
	public:
		Sequence(int id, int duree, const char*);
		Sequence(int id, int duree);
		void setDuree(int duree);
		void setId(int id);
		void setTrame(unsigned char trame,int canal);
		void setTrameFull(const char* trame);
		int getDuree();
		int getId();
		unsigned char getTrame(int canal);
        unsigned char* getTrameFull();


};
#endif
