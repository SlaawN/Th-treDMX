//---------------------------------------------------------------------------

#ifndef PortSerieH
#define PortSerieH


//---------------------------------------------------------------------------

#include <windows.h>
#include <queue>
class PortSerie
{

	HANDLE hCom;
	DWORD written;
	DWORD read;
	char recvChar;
	bool Vcontinue;
	int isRead;
	bool ignoreData;

	std::deque<char> recvBuf;

	public:
	PortSerie();
	~PortSerie();
	int ouvrirport();
	void lireport();
	void fermerport();
	void EcrirePort();




	std::deque<char> & getRecvBuf();
};

//---------------------------------------------------------------------------
#endif