//---------------------------------------------------------------------------

#ifndef SceneSQLManagerH
#define SceneSQLManagerH
//---------------------------------------------------------------------------

class SceneSQLManager{

	private:
		BDD bdd;
	public:
		loadScene(int id);
		bool saveScene(int id);
		vector<Scene*> loadScene(int id);

};
#endif
