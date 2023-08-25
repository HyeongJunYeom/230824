#include "MainGame.h"
#include "pch.h"

CMainGame::CMainGame()
{
	m_pPlayer = nullptr;
	m_pField = nullptr;
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	if (!m_pPlayer)
	{
		m_pPlayer = new CPlayer;

		int iChoice = 0;
		
		Render_Main();
		iChoice = Input_Number();

		switch (iChoice)
		{
		case NEW_GAME:
			m_pPlayer->Initialize();
			break;
		case LOAD:
			Load_Data();
			break;
		}
		
	}
	if (!m_pField)
	{
		m_pField = new CField;
		m_pField->Initialize();
	}

	m_pField->Set_Player(m_pPlayer);
}

void CMainGame::Update()
{
	int iChoice(0);

	while (true)
	{
		system("cls");

		Render_Menu();
		iChoice = Input_Number();
		switch(iChoice)
		{
		case GO_FIELD:
			if (m_pField)
			{
				m_pField->Update();
			}
			break;
		case RENDER:
			m_pPlayer->Render();
			system("pause");
			break;
		case EXIT:
			cout << "Exit..." << endl;
			cout << "Save.. Data..." << endl;
			Save_Data();
			system("pause");
			return;
		default:
			cout << "보기에 없는 선택지입니다. 다시 입력하세요." << endl;
			system("pause");
			continue;
		}
	}
}

void CMainGame::Release()
{
	if (m_pPlayer)
	{
		delete m_pPlayer;
		m_pPlayer = nullptr;
	}

	if (m_pField)
	{
		delete m_pField;
		m_pField = nullptr;
	}
}

void CMainGame::Render_Menu()
{
	cout << "===== Town Menu =====" << endl << endl;;
	cout << "1. Go to Field" << endl;
	cout << "2. Render Player Status" << endl;
	cout << "3. Exit & Save" << endl;
	cout << "Your Choice: ";		
}

void CMainGame::Render_Main()
{
	cout << "==== Main Menu =====" << endl << endl;

	cout << "1. New Game" << endl;
	cout << "2. Load Game" << endl;

	cout << "Your Choice: ";
}

void CMainGame::Save_Data()
{
	FILE* fWrite = nullptr;
	errno_t err = fopen_s(&fWrite, "../data/save.dat", "wb");

	if (0 == err)
	{
		char* pName = m_pPlayer->Get_Name();
		char* pJobString = m_pPlayer->Get_JobString();
		
		int iNameLen = strlen(pName) + 1;
		int iJobLen = strlen(pJobString) + 1;

		char szName[40] = "";
		char szJob[40] = "";
		strcpy_s(szName, 40, pName);
		strcpy_s(szJob, 40, pJobString);

		cout << "File open success" << endl;
		fwrite(m_pPlayer, sizeof(*m_pPlayer), 1, fWrite);
		fwrite(&iNameLen, sizeof(int), 1, fWrite);
		fwrite(szName, sizeof(char), iNameLen, fWrite);
		fwrite(&iJobLen, sizeof(int), 1, fWrite);
		fwrite(szJob, sizeof(char), iJobLen, fWrite);
	}
	else
	{
		cout << "Save Fault" << endl;
	}

	fclose(fWrite);
	cout << "Save succeed" << endl;
	return;
}

void CMainGame::Load_Data()
{
	FILE* fRead = nullptr;
	errno_t err = fopen_s(&fRead, "../data/save.dat", "rb");
	
	if (0 == err)
	{
		int iNameLen = 0;
		int iJobLen = 0;
		char* pName = nullptr;
		char* pJobString = nullptr;

		char szBuf[100] = "";

		cout << "File open success" << endl;
		fread(m_pPlayer, sizeof(*m_pPlayer), 1, fRead);
		fread(&iNameLen, sizeof(int), 1, fRead);
		fread(szBuf, sizeof(char), iNameLen, fRead);
		pName = new char[iNameLen];
		strcpy_s(pName, iNameLen, szBuf);
		m_pPlayer->Set_Name(pName);

		delete[] pName;
		pName = nullptr;

		fread(&iJobLen, sizeof(int), 1, fRead);
		fread(szBuf, sizeof(char), iJobLen, fRead);
		pJobString = new char[iJobLen];
		strcpy_s(pJobString, iJobLen, szBuf);
		m_pPlayer->Set_JobString(pJobString);

		delete[] pJobString;
		pJobString = nullptr;
	}
	else
	{
		cout << "Load Fault" << endl;
	}

	fclose(fRead);
	cout << "Load Succeed" << endl;
	return;
}
