#include "Field.h"
#include "pch.h"

CField::CField()
{
	m_pPlayer = nullptr;
}

CField::~CField()
{
	
}

void CField::Initialize()
{
	srand((unsigned int)time(NULL));
}

//	파이트 클래스 생성하여 파이트 클래스내부로 들어가기
void CField::Update()
{
	int iChoice(0);
	unsigned char cType(0);
	CMonster* pMonster = nullptr;

	while (true)
	{
		system("cls");

		Render_Menu();
		iChoice = Input_Number();
		switch (iChoice)
		{
		case LOW_DUNGEON:
			cType = (rand() % 2) + 1;
			pMonster = Apper_Monster(cType);
			break;
		case MID_DUNGEON:
			cType = (rand() % 2) + 2;
			pMonster = Apper_Monster(cType);
			break;
		case HIGH_DUNGEON:
			cType = (rand() % 2) + 3;
			pMonster = Apper_Monster(cType);
			break;
		case GO_BACK:
			cout << "Exit..." << endl;
			system("pause");
			return;
		default:
			cout << "보기에 없는 선택지입니다. 다시 입력하세요." << endl;
			system("pause");
			continue;
		}

		CFight Fight;
		Fight.Initialize(m_pPlayer, pMonster);
		Fight.Update();
		Fight.Release();

	}
}

void CField::Release()
{
	m_pPlayer = nullptr;
}


CMonster* CField::Apper_Monster(char _cType)
{
	CMonster* pMonster = new CMonster;
	pMonster->Initialize(_cType);

	cout << endl;
	cout << "Appear Monser! " << pMonster->Get_Name() << endl << endl;
	system("pause");

	return pMonster;
}

void CField::Render_Menu() const
{
	cout << "===== Field Menu =====" << endl << endl;;
	cout << "1. Low Dungeon" << endl;
	cout << "2. Mid Dungeon" << endl;
	cout << "3. High Dungeon" << endl;
	cout << "4. Go back" << endl;
	cout << "Your Choice: ";
}
