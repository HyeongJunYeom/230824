#include "pch.h"
#include "MainGame.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

int main(void)
{
	CMainGame* pMainGame = new CMainGame;
	pMainGame->Initialize();
	pMainGame->Update();

	delete pMainGame;
	pMainGame = nullptr;
	_CrtDumpMemoryLeaks();

	return 0;
}