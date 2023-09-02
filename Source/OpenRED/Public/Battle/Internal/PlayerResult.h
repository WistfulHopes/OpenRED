#pragma once
#include "Enums.h"

class PlayerResult
{
public:
	ROUND_RESULT m_Result[10];
	unsigned int m_WinCount;
	unsigned int m_WinCountMax;
	ROUND_RESULT_EX m_ResultRounds[20];
};
