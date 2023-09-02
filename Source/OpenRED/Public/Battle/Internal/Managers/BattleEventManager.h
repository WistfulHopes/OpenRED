#pragma once
#include "OpenRED/Public/Battle/Internal/Enums.h"

struct BOMEventInfo
{
	BOM_EVENT eventID;
	int param0;
	int param1;
	int param2;
};

class BattleEventManager
{
public:
	BOMEventInfo m_BOMEvent[10];
	unsigned int m_BOMEventCount;
	class BattleEventBase *m_pBattleEvent;
	int m_EventArg[4];
	bool m_bFinishUIEnd;
	bool m_bEnableMatchWinSecondAction;
	bool m_bEndMatchWinSecondAction;
	int m_MatchWinFadeOutTime;
	bool m_PlayingMatchResultVoice;
	bool m_bEnterMatchResult;
	int m_DramaSkipInputDisableTime;
	BEM_STATE m_CurrentBEMState;
	BEM_STATE m_LastBEMState;
};
