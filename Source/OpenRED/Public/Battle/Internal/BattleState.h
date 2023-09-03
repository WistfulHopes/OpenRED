#pragma once
#include "BattleEnums.h"
#include "PlayerResult.h"
#include "OpenRED/Public/Common/RoundTimer.h"

class BattleState
{
public:
	BattleState();
	
	RoundTimer m_Timer;
	PlayerResult m_PlayerResult[2];
	unsigned int m_RoundCount;
	unsigned int m_RoundMax;
	bool m_FinalRound;
	bool m_IsBattleDoing;
	bool m_IsStartedBattle;
	SIDE_ID m_Winner;
	bool m_PauseUpdate;
	bool m_RematchBattle;
	unsigned int m_RematchRound;
	bool m_IsBattleTempStop;
	SIDE_ID m_timerForcePauseSide;
	bool m_BattleQuickEnd;
	bool m_TimeLimitForceFinish;

private:
	void InitParam();
};
