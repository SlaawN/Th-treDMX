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

//initialise la dur�e de la s�quence
void Sequence::setDuree(int duree)
{
	this->duree=duree;
}

//Change l'id
void Sequence::setId(int id)
{
	this->id=id;
}

//rcup�re la dur�e de la sequence
int Sequence::getDuree()
{
	return duree;
}

//r�cup�re l'id de s�quence
int Sequence::getId()
{
	return id;
}

