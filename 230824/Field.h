#pragma once

#include "MyFunc.h"
#include "Player.h"
#include "Monster.h"
#include "Fight.h"

enum CHOICE_FIELD
{
	LOW_DUNGEON = 1, MID_DUNGEON, HIGH_DUNGEON, GO_BACK
};

class CField
{
public:
	CField();
	~CField();

public:
	void Initialize();
	void Update();
	void Release();

public:
	void Set_Player(CPlayer* _pPlayer)
	{
		m_pPlayer = _pPlayer;
	}
	CMonster* Apper_Monster(char _cType);

public:
	void Render_Menu() const;

private:
	CPlayer* m_pPlayer;
};

