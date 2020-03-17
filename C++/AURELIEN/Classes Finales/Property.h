//---------------------------------------------------------------------------

#ifndef PropertyH
#define PropertyH
//---------------------------------------------------------------------------
class Property{

	private:
		int order,id;
		char *description;
	public:
		void SetOrder(int order);
		void SetDescription(char* description);
		void SetId(int id) ;
		char * GetDescription();
		int GetOrder();
		int GetId();
		Property(int id,int order,char * description);

}
#endif
