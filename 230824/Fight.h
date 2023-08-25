#pragma once

#include "Monster.h"
#include "Player.h"
#include "MyFunc.h"


enum CHOICE_FIGHT
{
	ATTACK = 1, RUN
};

class CFight
{
public:
	CFight();
	~CFight();

public:
	void Initialize(CPlayer* _pPlayer, CMonster* _pMonster);
	void Update();
	void Release();

public:
	int		Fight();
	int		Run();

	void	Render_State();
	void	Render_Menu();

private:
	CPlayer* m_pPlayer;
	CMonster* m_pMonster;
};

