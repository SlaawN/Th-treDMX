//---------------------------------------------------------------------------

#pragma hdrstop

#include "Scene.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


Scene::Scene(int id,int TpsPause,int NbSequence,String name){

	this->id=id;
	this->TpsPause=TpsPause;
	this->NbSequence=NbSequence;
	this->name=name;
}

Scene::Scene(){

	this->TpsPause=0;
	this->NbSequence=0;
	this->name="/0";

}

int Scene::getId(){

  return id;

}

String Scene::getName(){

  return name;

}

void Scene::setId(int id ){

	this->id=id;

}

void Scene::setTime(int TpsPause){

   this->TpsPause=TpsPause;

}

int Scene::getTime(){

   return TpsPause;

}

void Scene::setNbSeq(int NbSequence){

	this->NbSequence=NbSequence;

}

int Scene::getNbSeq(){

	return NbSequence;

}



