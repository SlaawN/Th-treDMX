//---------------------------------------------------------------------------

#pragma hdrstop

#include "Equipement.h"
//---------------------------------------------------------------------------
Equipement::Equipement(int id,char *name,std::map<String,Property*>properties){

	this->id=id;
	this->name=name;
	this->properties=properties;

}
int Equipement::GetNbVoies(){

   return 1;

}
std::map<String,Property*> Equipement::getProperties(){

	return this->properties;

}
bool Equipement::VerifOrder(Property *order){



}
void Equipement::SetId(int id){

	this->id=id;

}
int Equipement::GetId(){

	return this->id;

}
void Equipement::SetName(char *name){

	this->name=name;

}
char * Equipement::GetName(){

	return this->name;

}
#pragma package(smart_init)
