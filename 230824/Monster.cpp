#include "Monster.h"
#include "pch.h"
#include "Player.h"

CMonster::CMonster()
{
	memset(&m_tInfo, 0, sizeof(INFO));
	memset(&m_tMonsterStat, 0, sizeof(MONSTER_STAT));
}

CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize(char _cType)
{
	if (EMPTY == _cType)
		return;
	m_tMonsterStat.cType = _cType;

	switch (m_tMonsterStat.cType)
	{
	case SLIME:
		m_tInfo.pName = Input_String("Slime");
		m_tInfo.iAtt = 3;		m_tInfo.iMaxHp = 20;
		m_tInfo.iExp = 5;		m_tInfo.iMoney = 10;
		break;
	case SKELETON:
		m_tInfo.pName = Input_String("Skeleton");
		m_tInfo.iAtt = 5;		m_tInfo.iMaxHp = 30;
		m_tInfo.iExp = 7;		m_tInfo.iMoney = 20;
		break;
	case OGRE:
		m_tInfo.pName = Input_String("Ogre");
		m_tInfo.iAtt = 7;		m_tInfo.iMaxHp = 40;
		m_tInfo.iExp = 10;		m_tInfo.iMoney = 35;
		break;
	case TROLL:
		m_tInfo.pName = Input_String("Troll");
		m_tInfo.iAtt = 11;		m_tInfo.iMaxHp = 60;
		m_tInfo.iExp = 15;		m_tInfo.iMoney = 50;
		break;
	}
	m_tInfo.iHp = m_tInfo.iMaxHp;
}

void CMonster::Update()
{
}

void CMonster::Release()
{
	if (m_tInfo.pName)
	{
		delete[] m_tInfo.pName;
		m_tInfo.pName = nullptr;
	}
}

void CMonster::Render() const
{
	cout << "===== Monster Status =====" << endl << endl;
	cout << "Name: " << m_tInfo.pName << endl;
	cout << "Hp: " << m_tInfo.iHp << " / " << m_tInfo.iMaxHp << endl;
	cout << "Attack Value: " << m_tInfo.iAtt << endl << endl;
}

void CMonster::Attack_Player(CPlayer* _pPlayer)
{
	_pPlayer->Min_Hp(Get_Attack());
	cout << "Monster " << Get_Name() << "s Attack!" << endl;
	cout << Get_Attack() << " Damage" << endl << endl;
}
