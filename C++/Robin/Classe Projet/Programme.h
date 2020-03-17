//---------------------------------------------------------------------------

#ifndef ProgrammeH
#define ProgrammeH
#include <windows.h>
#include <stdlib.h>
#include <tchar.h>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <vcl.h>
#include "Scene.h"
//---------------------------------------------------------------------------
class Programme {

	private:
		int id,NbScene;
		String name;

	public:
		Programme();
		void setId(int id);
		int getId();
		void setName(String name);
		String getName();
		void setNbScene(int NbScene);
		int getNbScene();

};
//---------------------------------------------------------------------------
#endif
