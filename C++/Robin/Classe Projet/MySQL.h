//---------------------------------------------------------------------------

#ifndef MySQLH
#define MySQLH
#include <string>
#include "includeSQL/mysql.h"
#include <vcl.h>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
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
			MySQL();
			bool Connexion();
			bool update(String req);
			bool insert(String req);
			bool supp(String req);
			bool select(AnsiString req,TMemo*);
 };

#endif
