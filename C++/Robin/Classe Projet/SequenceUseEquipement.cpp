//---------------------------------------------------------------------------

#pragma hdrstop

#include "SequenceUseEquipement.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

SequenceUsed::SequenceUsed(int id, int value){

   this->id=id;
   this->value=value;


}

void SequenceUsed::setSequenceValue(int value){

	this->value=value;

}

int SequenceUsed::getSequenceValue(){

  return id;

}

void SequenceUsed::setId(int id ){

	this->id=id;

}

int SequenceUsed::getId() {

	return id;

}



