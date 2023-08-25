#pragma once

typedef struct tagInfo
{
	char* pName;
	int iHp;
	int iMaxHp;
	int iAtt;
	int iExp;
	int iMoney;
} INFO;

typedef struct tagPlayerStat
{
	char cJob;
	char* pJobString;
	int iLev;
	int iNeedExp;
} PLAYER_STAT;

typedef struct tagMonsterStat
{
	char cType;
} MONSTER_STAT;