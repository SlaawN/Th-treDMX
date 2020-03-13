//---------------------------------------------------------------------------

#ifndef BDDH
#define BDDH
//---------------------------------------------------------------------------
class BDD{

	private:

	public:

		BDD();
		bool Connexion();
		bool update(String req);
		bool insert(String req);
		bool supp(String req);
		bool select(String req);

};
#endif
