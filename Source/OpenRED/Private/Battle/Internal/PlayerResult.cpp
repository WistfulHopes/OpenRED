#include "OpenRED/Public/Battle/Internal/PlayerResult.h"

PlayerResult::PlayerResult()
{
	for (ROUND_RESULT& Result : m_Result)
	{
		Result = ROUND_RESULT_INVALID;
	}
	for (ROUND_RESULT_EX& ResultEx : m_ResultRounds)
	{
		ResultEx = RR_INVALID;
	}
	m_WinCount = 0;
	m_WinCountMax = 0;
}
