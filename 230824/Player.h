#pragma once

#include "Define.h"
#include "MyFunc.h"
#include <cstring>

class CMonster;

enum JOB
{
	CIVIL = 0, WARRIOR, GUNNER, INFIGHTER
};

class CPlayer
{
public:
	CPlayer();
	~CPlayer();

public:
	void		Initialize();
	void		Update();
	void		Release();

public:
	void			Render() const;

	void			Attack_Monster(CMonster* _pMonster);

	INFO			Get_Info() const		{ return m_tInfo; };
	PLAYER_STAT		Get_Stat() const		{ return m_tPlayerStat; }

	char*			Get_JobString() const	{ return m_tPlayerStat.pJobString; }
	char*			Get_Name() const		{ return m_tInfo.pName; }
	int				Get_Hp() const			{ return m_tInfo.iHp; }
	int				Get_Attack() const		{ return m_tInfo.iAtt; }

	void			Set_JobString(char* _pJobString)
	{
		int iJobLen = strlen(_pJobString) + 1;
		m_tPlayerStat.pJobString = new char[iJobLen];
		strcpy_s(m_tPlayerStat.pJobString, iJobLen, _pJobString);
	}
	void			Set_Name(char* _pName)
	{
		int iNameLen = strlen(_pName) + 1; 
		m_tInfo.pName = new char[iNameLen];
		strcpy_s(m_tInfo.pName, iNameLen, _pName);
	}

	void			Min_Hp(int _iValue)		{ m_tInfo.iHp -= _iValue; }

private:
	INFO			m_tInfo;
	PLAYER_STAT		m_tPlayerStat;
};

