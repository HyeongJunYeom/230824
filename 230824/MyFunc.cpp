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

//	매개변수가 있을 시 해당 문자열을 동적할당해서 반환하고
//	매개변수가 없을 시 입력받은 문자열을 동적할당 하고 반환한다.
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
