//---------------------------------------------------------------------------

#ifndef TrameManagerH
#define TrameManagerH
#include "AdresseEquipement.h"
#include "Equipement.h"

#include<vector>
//---------------------------------------------------------------------------

class TrameManager{
	private:
		 std::vector<AdresseEquipement> trame;
		 char dmx[512];

	public:
		 void InsertEquipement(Equipement *,int canal);
		 bool removeEquipement(int canal);
		 bool checkConflict();
		 char * getTrame();
		 std::vector<AdresseEquipement*> getAdresseEquipement();

};
#endif
