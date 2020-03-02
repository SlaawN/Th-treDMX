//---------------------------------------------------------------------------

#ifndef SceneH
#define SceneH
#include <windows.h>
#include <stdlib.h>
#include <tchar.h>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <vcl.h>
//---------------------------------------------------------------------------

class Scene{

	private :
		int id,TpsPause,NbSequence;
		String name;
		//std::map<string sequence*> seq;

	public :
		Scene(int id,int TpsPause,int NbSequence,String name);
		Scene();
		int getId();
		String getName();
		void setId(int id);
		void setTime(int TpsPause);
		int getTime();
		void setName(String nom);
		void setNbSeq(int NbSequence);
		int getNbSeq();
		//void setSequences(std::map <string sequence*>);
		//std::map <string sequence*> getSequences();

};





#endif
