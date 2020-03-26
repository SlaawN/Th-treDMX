//---------------------------------------------------------------------------

#ifndef MySQLH
#define MySQLH
#include <string>
#include "includeSQL/mysql.h"
#include <vcl.h>
#include <deque>
#include <vector>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
using namespace std;
//---------------------------------------------------------------------------
class MySQL
{
		private:
			MYSQL * mySQL;
			MYSQL *conn;
			MYSQL_RES *myRES;
			MYSQL_ROW myROW;
			TMemo* Memo1;
		public:
			MySQL(TMemo* Memo);
			bool Connexion();
			bool update(String req);
			bool insert(String req);
			bool supp(String req);
			bool select(AnsiString req,	vector<String> *ResultSelect);
};
#endif
