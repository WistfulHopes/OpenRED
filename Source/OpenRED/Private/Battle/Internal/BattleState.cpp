#include "OpenRED/Public/Battle/Internal/BattleState.h"

BattleState::BattleState()
{
	m_Timer = RoundTimer();
	m_PlayerResult[0] = PlayerResult();
	m_PlayerResult[1] = PlayerResult();
	InitParam();
}

void BattleState::InitParam()
{
	m_RoundCount = 1;
	m_RoundMax = 2;
	m_FinalRound = false;
	m_IsBattleDoing = false;
	m_PauseUpdate = true;
	m_RematchRound = false;
	m_timerForcePauseSide = SIDE_ID_NUM;
	m_BattleQuickEnd = false;
	m_Winner = SIDE_ID_INVALID;
}
