//---------------------------------------------------------------------------

#pragma hdrstop

#include "Programme.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Programme::Programme(){

}

void Programme::setId(int id){

   this->id=id;

}

int Programme::getId(){

  return id;

}
void Programme::setName(String name){

   this->name=name;

}
String Programme::getName(){

	return name;

}
void Programme::setNbScene(int NbScene){

   this->NbScene=NbScene;

}
int Programme::getNbScene(){

   return NbScene;

}

