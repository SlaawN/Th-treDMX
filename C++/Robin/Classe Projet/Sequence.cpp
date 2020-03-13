//---------------------------------------------------------------------------

#pragma hdrstop

#include "Sequence.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
Sequence::Sequence(int id, int duree)
{
	this->id=id;
	this->duree=duree;

}

//initialise la durée de la séquence
void Sequence::setDuree(int duree)
{
	this->duree=duree;
}

//Change l'id
void Sequence::setId(int id)
{
	this->id=id;
}

//rcupère la durée de la sequence
int Sequence::getDuree()
{
	return duree;
}

//récupère l'id de séquence
int Sequence::getId()
{
	return id;
}

