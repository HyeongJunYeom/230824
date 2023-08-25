#pragma once

#include "Define.h"
#include "MyFunc.h"

class CPlayer;

enum MONSTER_TYPE
{
	EMPTY, SLIME, SKELETON, OGRE, TROLL
};

class CMonster
{
public:
	CMonster();
	~CMonster();

public:
	void Initialize(char _cType = EMPTY);
	void Update();
	void Release();

public:
	void Render() const;

	void			Attack_Player(CPlayer* _pPlayer);

	INFO			Get_Info()	const		{ return m_tInfo; }
	MONSTER_STAT	Get_rStat() const		{ return m_tMonsterStat; }

	char*			Get_Name()	const		{ return m_tInfo.pName; }
	int				Get_Hp() const			{ return m_tInfo.iHp; }
	int				Get_Attack() const		{ return m_tInfo.iAtt; }

	void			Min_Hp(int _iValue)		{ m_tInfo.iHp -= _iValue; }


private:
	INFO m_tInfo;
	MONSTER_STAT m_tMonsterStat;
};

