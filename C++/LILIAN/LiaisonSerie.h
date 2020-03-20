//---------------------------------------------------------------------------

#ifndef LiaisonSerieH
#define LiaisonSerieH
//---------------------------------------------------------------------------
#include <windows.h>
#include <queue>
class PortLS
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
	PortLS();
	~PortLS();
	int ouvrirport();
	void lireport();
	void fermerport();
	int connectbdd();

	std::deque<char> & getRecvBuf();
};
#endif
