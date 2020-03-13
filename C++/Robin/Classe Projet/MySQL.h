//---------------------------------------------------------------------------

#ifndef MySQLH
#define MySQLH
//---------------------------------------------------------------------------


class MySQL{

	private:
		MYSQL mysql;
	public:
		bool update();
		bool insert();
		bool supp();
		bool select();

}

#endif
