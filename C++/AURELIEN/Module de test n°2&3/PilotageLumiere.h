//---------------------------------------------------------------------------

#ifndef PilotageLumiereH
#define PilotageLumiereH
class PilotageLumiere
{

	private:
		int CouleurR,CouleurG,CouleurV,CouleurB,CouleurW,Strobo,Timer;
		unsigned char dmxBlock[512];
	public:
	  PilotageLumiere(unsigned char dmxBlock[512]);
	  ~PilotageLumiere();
	  int getCouleurR();
	  int getCouleurG();
	  int getCouleurB();
	  int getCouleurW();
	  int getStroboscope();
	  void setCouleurR(int);
	  void setCouleurG(int);
	  void setCouleurB(int);
	  void setCouleurW(int);
	  void setStroboscope(int);
	  void setTimer(int);
	  int getTimer();
	  void setAllTo0();


};



//---------------------------------------------------------------------------
#endif
