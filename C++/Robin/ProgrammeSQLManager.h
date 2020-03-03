//---------------------------------------------------------------------------

#ifndef ProgrammeSQLManagerH
#define ProgrammeSQLManagerH
#include "BDD.h"
#include "Programme.h"
//---------------------------------------------------------------------------


class ProgrammeSQLManager{

	private:
		BDD bdd;
	public:
		Programme* loadProgramme(int id);
		bool saveProgramme(int id);
		vector<Programme*> loadProgramme(int id);

};
#endif
