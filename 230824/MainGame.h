#pragma once

#include "Player.h"
#include "MyFunc.h"
#include "Field.h"

enum CHOICE_TOWN
{
	GO_FIELD = 1, RENDER, EXIT
};

enum CHOICE_MAIN
{
	NEW_GAME = 1, LOAD
};

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void Initialize();
	void Update();
	void Release();

public:
	void Render_Menu();
	void Render_Main();

	void Save_Data();
	void Load_Data();

private:
	CPlayer*	m_pPlayer;
	CField*		m_pField;
};

