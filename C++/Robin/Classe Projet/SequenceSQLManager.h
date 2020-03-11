//---------------------------------------------------------------------------

#ifndef SequenceSQLManagerH
#define SequenceSQLManagerH
//---------------------------------------------------------------------------

class SequenceSQLManager{

	private:
		BDD bdd;
	public:
		Sequence* loadSequence(int id);
		bool saveSequence(int id);
		vector<Sequence*> loadSequence(int id);

};
#endif
