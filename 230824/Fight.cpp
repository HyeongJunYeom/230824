#include "Fight.h"
#include "pch.h"

CFight::CFight()
{
	m_pPlayer = nullptr;
	m_pMonster = nullptr;
}

CFight::~CFight()
{
	Release();
}

void CFight::Initialize(CPlayer* _pPlayer, CMonster* _pMonster)
{
	m_pPlayer = _pPlayer;
	m_pMonster = _pMonster;
}

void CFight::Update()
{
	int iChoice(0);
	while (true)
	{
		system("cls");
		Render_Menu();
		iChoice = Input_Number();

		switch (iChoice)
		{
		case ATTACK:
			m_pPlayer->Attack_Monster(m_pMonster);
			system("pause");

			if (0 >= m_pMonster->Get_Hp())
			{
				cout << "Monster is Dead" << endl;

				system("pause");
				return;
			}

			m_pMonster->Attack_Player(m_pPlayer);
			system("pause");

			if (0 >= m_pPlayer->Get_Hp())
			{
				cout << "Player Dead" << endl;

				system("pause");
				return;
			}
			break;
		case RUN:
			cout << "Run..." << endl;
			system("pause");
			return;
		}
	}
}

void CFight::Release()
{
	if (m_pMonster)
	{
		delete m_pMonster;
		m_pMonster = nullptr;
	}
}

int CFight::Fight()
{
	return 0;
}

int CFight::Run()
{
	return 0;
}

void CFight::Render_State()
{
	m_pPlayer->Render();

	m_pMonster->Render();
}

void CFight::Render_Menu()
{
	cout << "===== Fight Choice =====" << endl << endl;

	Render_State();

	cout << "1. Attack" << endl;
	cout << "2. Run" << endl;
	cout << "Your Choice: ";
}