#include "MyFunc.h"
#include "pch.h"

int Input_Number(int* _pInput)
{
	if (nullptr != _pInput)
	{
		cin >> *_pInput;
		return *_pInput;
	}
	int iInput(0);
	cin >> iInput; 
	return iInput;
}

//	�Ű������� ���� �� �ش� ���ڿ��� �����Ҵ��ؼ� ��ȯ�ϰ�
//	�Ű������� ���� �� �Է¹��� ���ڿ��� �����Ҵ� �ϰ� ��ȯ�Ѵ�.
char* Input_String(const char* _pInput)
{
	char* pInput = nullptr;
	if (nullptr != _pInput)
	{
		int iStrLen = strlen(_pInput) + 1;
		pInput = new char[iStrLen];
		strcpy_s(pInput, iStrLen, _pInput);
		return pInput;
	}
	char szInput[100] = "";
	cin >> szInput;
	int iStrLen = strlen(szInput) + 1;
	pInput = new char[iStrLen];
	strcpy_s(pInput, iStrLen, szInput);
	return pInput;
}
