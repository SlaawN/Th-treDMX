//---------------------------------------------------------------------------

#ifndef fonctionsH
#define fonctionsH
class Couleurs
{
	private:
		unsigned char * dmxBlock;

	public:
		//declarations des fonctions
		Couleurs(unsigned char * dmxBlock);
		~Couleurs();
		void Rouge();
		void Vert();
		void Bleu();
		void Blanc();
		void Stroboscope();
		void ON();
		void OFF();
		void Jaune();
};



//---------------------------------------------------------------------------
#endif
