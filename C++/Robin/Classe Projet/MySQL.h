//---------------------------------------------------------------------------

#ifndef MySQLH
#define MySQLH
//---------------------------------------------------------------------------
 class MySQL
 {
		MySQL();
		bool Connexion()=0;
		bool update(String req)=0;
		bool insert(String req)=0;
		bool supp(String req)=0;
		bool select(String req)=0;
 };

#endif
