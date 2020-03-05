//---------------------------------------------------------------------------

#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
#include <iostream>
#include <conio.h>
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)

PilotageLumiere::PilotageLumiere(unsigned char dmxBlock[512])
{
	this->dmxBlock[512] = dmxBlock[512];
	CouleurR =0;
	CouleurG =0;
	CouleurB =0;
	CouleurW =0;
	Strobo =0;
	Timer=0;

}
PilotageLumiere::~PilotageLumiere()
{


}

int PilotageLumiere::getCouleurR()
{
	return this->CouleurR;
}

int PilotageLumiere::getCouleurG()
{
	return this->CouleurG;
}

int PilotageLumiere::getCouleurB()
{
	return this->CouleurB;
}

int PilotageLumiere::getCouleurW()
{
	return this->CouleurW;
}

int PilotageLumiere::getStroboscope()
{
	return this->Strobo;
}

void PilotageLumiere::setCouleurR(int ValueColor)
{
	this->CouleurR=ValueColor;
}

void PilotageLumiere::setCouleurG(int ValueColor)
{
	this->CouleurG=ValueColor;
}

void PilotageLumiere::setCouleurB(int ValueColor)
{
	this->CouleurB=ValueColor;
}

void PilotageLumiere::setCouleurW(int ValueColor)
{
	this->CouleurW=ValueColor;
}

void PilotageLumiere::setStroboscope(int ValueColor)
{
	this->Strobo=ValueColor;
}

void PilotageLumiere::setTimer(int Timer){
	this->Timer=Timer;
}

int PilotageLumiere::getTimer(){
	return this->Timer;
}
