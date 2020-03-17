//---------------------------------------------------------------------------

#pragma hdrstop

#include "Property.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Property::Property(int id,int order,char * description)
{
	this->id=id;
	this->order=order;
	this->description=description;

}
void Property::SetOrder(int order){

	this->order=order;

}
void Property::SetDescription(char *description)
{
	this->description=description;
}
void Property::SetId(int id){

	this->id=id;
}
int Property::GetOrder()
{
	return this->order;
}
char * Property::GetDescription(){

   return this->description;
}
int Property::GetId(){

	return this->id;
}

