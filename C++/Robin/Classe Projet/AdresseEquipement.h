//---------------------------------------------------------------------------

#ifndef AdresseEquipementH
#define AdresseEquipementH
#include <map>
#include "Property.h"
//---------------------------------------------------------------------------
class AdresseEquipement{

	private:
		Equipement equipement;
		int adresse,int;
		std::map<Property*,int>values;

	public:
		std::map<Property*,int> GetValues();
		int GetAdresse();
		void setValues(std::map<Property*,int> values);
		void setAdresse(int adresse);
		AdresseEquipement(int adresse,Equipement *equipement);


};
#endif
