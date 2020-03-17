//---------------------------------------------------------------------------

#pragma hdrstop

#include "AdresseEquipement.h"
//---------------------------------------------------------------------------
AdresseEquipement::AdresseEquipement(int adresse,Equipement* equipement){

	this->adresse=adresse;
	this->equipement=equipement;

}

std::map<Property*,int>	AdresseEquipement::GetValues(){

	return this->values;

}

int AdresseEquipement::GetAdresse(){

	return this->adresse;

}
void AdresseEquipement::SetValues(std::map<Property*,int> values){

	this->values=values;

}
void AdresseEquipement::SetAdresse(int adresse){

    this->adresse=adresse;
}
#pragma package(smart_init)
