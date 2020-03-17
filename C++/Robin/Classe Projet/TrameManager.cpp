//---------------------------------------------------------------------------

#pragma hdrstop

#include "TrameManager.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void TrameManager::InsertEquipement(Equipement * ekip,int canal){


}
bool TrameManager::removeEquipement(int canal){

	 return true;
}
bool TrameManager::checkConflict(){

  return true;
}
char * TrameManager::getTrame()
{
	return this->dmx;
}
std::vector<AdresseEquipement*> TrameManager::getAdresseEquipement(){


}
