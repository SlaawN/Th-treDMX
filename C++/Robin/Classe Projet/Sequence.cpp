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

Sequence::Sequence(int id, int duree,const char *trame)
{
	this->id=id;
	this->duree=duree;
	strcpy(this->trame,trame);
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
	return this->duree;
}

//récupère l'id de séquence
int Sequence::getId()
{
	return this->id;
}
void Sequence::setTrame(unsigned char trame,int canal)
{
	this->trame[canal]=trame;
}
void Sequence::setTrameFull(const char* trame)
{
   strcpy(this->trame,trame);
}
//retourne la caractère de la trame à l'id designe en paramètre
unsigned char Sequence::getTrame(int id)
{
	return this->trame[id];
}
unsigned char* Sequence::getTrameFull()
{
	return this->trame;
}


