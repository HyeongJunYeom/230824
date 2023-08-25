#include "Player.h"
#include "pch.h"
#include "Monster.h"

CPlayer::CPlayer()
{
	memset(&m_tInfo, 0, sizeof(INFO));
	memset(&m_tPlayerStat, 0, sizeof(PLAYER_STAT));
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	system("cls");
	cout << "Name: ";
	m_tInfo.pName = Input_String();

	while (true)
	{
		system("cls");
		cout << "Job Choice" << endl;
		cout << "1. Warrior" << endl;
		cout << "2. Gunner" << endl;
		cout << "3. Infighter" << endl;
		//	cout << "4. Cleric" << endl;
		cout << "Your Choice: ";
		m_tPlayerStat.cJob = (char)Input_Number();

		switch (m_tPlayerStat.cJob)
		{
		case CIVIL:
			m_tPlayerStat.pJobString = Input_String("Civil");
			m_tInfo.iAtt = 1;		m_tInfo.iMaxHp = 10;
			break;
		case WARRIOR:
			m_tPlayerStat.pJobString = Input_String("Warrior");
			m_tInfo.iAtt = 10;		m_tInfo.iMaxHp = 100;
			break;
		case GUNNER:
			m_tPlayerStat.pJobString = Input_String("Gunner");
			m_tInfo.iAtt = 13;		m_tInfo.iMaxHp = 70;
			break;
		case INFIGHTER:
			m_tPlayerStat.pJobString = Input_String("Infighter");
			m_tInfo.iAtt = 7;		m_tInfo.iMaxHp = 130;
			break;
		default:
			cout << "보기에 없는 선택입니다. 다시 입력해주세요." << endl;
			system("pause");
			continue;
		}

		m_tInfo.iHp = m_tInfo.iMaxHp;
		m_tInfo.iExp = 0;			m_tInfo.iMoney = 300;
		m_tPlayerStat.iLev = 1;		m_tPlayerStat.iNeedExp = 40;

		cout << "Charactor Initialize Complete! " << endl << endl;

		Render();
		system("pause");
		break;
	}


}

void CPlayer::Update()
{
}

void CPlayer::Release()
{
	if (m_tInfo.pName)
	{
		delete[] m_tInfo.pName;
		m_tInfo.pName = nullptr;
	}

	if (m_tPlayerStat.pJobString)
	{
		delete[] m_tPlayerStat.pJobString;
		m_tPlayerStat.pJobString = nullptr;
	}
}

void CPlayer::Render() const
{
	cout << "===== Player Status =====" << endl << endl;
	cout << "Name: " << m_tInfo.pName << endl;
	cout << "Job: " << m_tPlayerStat.pJobString << endl;
	cout << "Hp: " << m_tInfo.iHp << " / " << m_tInfo.iMaxHp << endl;
	cout << "Attack Value: " << m_tInfo.iAtt << endl;
	cout << "Exp: " << m_tInfo.iExp << " / " << m_tPlayerStat.iNeedExp << endl;
	cout << "Money: " << m_tInfo.iMoney << " G" << endl << endl;
}

void CPlayer::Attack_Monster(CMonster* _pMonster)
{
	_pMonster->Min_Hp(Get_Attack());
	cout << "Player " << Get_Name() << "s Attack!" << endl;
	cout << Get_Attack() << " Damage" << endl << endl;
}