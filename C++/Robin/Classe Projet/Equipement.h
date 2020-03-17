//---------------------------------------------------------------------------

#ifndef EquipementH
#define EquipementH
#include <map>
#include "Property.h"
//---------------------------------------------------------------------------
class Equipement{

	private:
		int id,
		char *name,
		std::map<String,Property*>properties;

	public:
		std::map<String,Property*> getProperties();
		int GetNbVoies();
		bool VerifOrder(Property *order);
		void SetId(int id);
		int GetId();
		void SetName(char* name);
		char* GetName();
		Equipement(int id,char* name,std::map<String,Property*>);

}
#endif
