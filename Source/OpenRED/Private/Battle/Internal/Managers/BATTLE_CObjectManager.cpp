#include "OpenRED/Public/Battle/Internal/Managers/BATTLE_CObjectManager.h"

#include "OpenRED/Public/Battle/REDGameState_Battle.h"
#include "OpenRED/Public/Battle/Internal/ActionNames.h"
#include "OpenRED/Public/Battle/Internal/BattleState.h"
#include "OpenRED/Public/Battle/Internal/Managers/BattleEventManager.h"
#include "OpenRED/Public/Common/REDGameCommon.h"

BATTLE_CObjectManager::BATTLE_CObjectManager()
{
	for (auto& TeamManager : m_TeamManager)
	{
		TeamManager = BATTLE_TeamManager();
	}

	m_EventData = SEventData();

	for (auto& Obj : m_ObjVector)
	{
		Obj = OBJ_CBase();
	}
	for (auto& Char : m_CharVector)
	{
		Char = OBJ_CCharBase();
	}
}

void BATTLE_CObjectManager::BOM_MatchOneceInitialize(bool bIs2ndCall)
{
	if (!bIs2ndCall)
	{
		// TODO generate random seed again
	}
	m_BattleCheckSumTimeCount = 0;
	m_BattleCheckSumErrorFound = 0;
	m_BattleCheckSumErrorFoundList[0] = 0;
	m_BattleCheckSumErrorFoundList[1] = 0;

	m_RequestFadeOut = false;

	// Initialize start of battle values
	m_BurstVal[0] = 15000;
	m_BurstVal[1] = 15000;
	m_MatchStaticValue0[1] = 0;
	m_MatchStaticValue1[1] = 0;
	m_Rakusyo[1] = 0;
	m_YogoreLevel[1] = 0;
	
	m_PreBurstVal[0] = 15000;
	m_PreBurstVal[1] = 15000;
	m_PreMatchStaticValue0[1] = 0;
	m_PreMatchStaticValue1[1] = 0;
	m_PreRakusyo[1] = 0;
	m_PreYogoreLevel[1] = 0;
	for (int i = 0; i < 2; i++)
	{
		m_YogoreLv[i][0] = 0;
		m_YogoreLv[i][1] = 0;
	}
}

void BATTLE_CObjectManager::ExecuteObjectManagerEvent(BattleEventManager* pBEM)
{
	if (!pBEM) return;

	for (unsigned int i = 0; i < pBEM->m_BOMEventCount; ++i)
	{
		ExecuteObjectManagerEvent(&pBEM->m_BOMEvent[i]);
	}
	for (auto& Event : pBEM->m_BOMEvent)
	{
		Event = BOMEventInfo();
	}
}

void BATTLE_CObjectManager::BOM_RoundAndEasyResetInitialize(bool use2ndInitialize)
{
	// Reset checksum data
	
	m_BattleCheckSumTimeCount = 0;
	m_BattleCheckSumErrorFound = 0;
	m_BattleCheckSumErrorFoundList[0] = 0;
	m_BattleCheckSumErrorFoundList[1] = 0;

	m_FinishSlowTime = 0;

	// Set values to previous
	if (const auto GameState = Cast<AREDGameState_Battle>(GWorld->GetGameState()))
	{
		if (GameState->State.Get()->m_Winner == SIDE_ID_INVALID)
		{
			// TODO set up replay version
			for (int i = 0; i < 2; ++i)
			{
				m_BurstVal[i] = m_PreBurstVal[i];
				m_MatchStaticValue0[i] = m_MatchStaticValue0[i];
				m_MatchStaticValue1[i] = m_MatchStaticValue1[i];
				m_Rakusyo[i] = m_PreRakusyo[i];
				m_YogoreLevel[i] = m_PreYogoreLevel[i];
			}
		}
	}

	// Reset miscellaneous values
	m_DokiDokiStopByDokiDokiKill = 0;
	m_DokiDokiStopIgnoreTime = 0;
	m_EventVsVoiceRandomIndex = -1;
	m_EventVsVoiceNum = -1;
	m_TrialBossHP = 0;
	m_TrialBossHPMax = 0;
	m_TrialBossBarrier = 0;
	m_TrialExVal0 = 0;
	m_TrialExVal1 = 0;
	m_TrialExVal2 = 0;
	m_TrialExVal3 = 0;

	if (!use2ndInitialize)
	{
		// TODO pause stuff
	}

	// TODO handle everything else
}

void BATTLE_CObjectManager::ExecuteObjectManagerEvent(const BOMEventInfo* pEvent)
{
	if (!pEvent) return;

	const BOM_EVENT EventID = static_cast<BOM_EVENT>(pEvent->eventID - 1);
	switch (EventID)
	{
	case BOM_EVENT_ENTRY:
		{
			auto GameCommon = UREDGameCommon::sInstance;
			BOM_RoundAndEasyResetInitialize(true);
			FMemory::Memset(&m_EventData, 0, sizeof(m_EventData));

			const int MemberID = pEvent->param0;
			const int CharID = MemberID * 3;

			m_CharVector[CharID].ActionRequestForce(&AN_CmnActEntryWait);

			OBJ_CBase* TmpObj = &m_CharVector[0];
			if (!MemberID)
			{
				TmpObj = &m_CharVector[3];
			}
			TmpObj->ActionRequestForce(&AN_CmnActEntryWait);

			// TODO do the rest. i'm lazy
		}
		break;
	case BOM_EVENT_ONLYDRAMA_BATTLE_SETUP:
		{
			auto GameCommon = UREDGameCommon::sInstance;
			BOM_RoundAndEasyResetInitialize(true);
			FMemory::Memset(&m_EventData, 0, sizeof(m_EventData));

			const int MemberID = pEvent->param0;
			const int CharID = MemberID * 3;

			m_CharVector[CharID].ActionRequestForce(&AN_CmnActEntryWait);

			OBJ_CBase* TmpObj = &m_CharVector[0];
			if (!MemberID)
			{
				TmpObj = &m_CharVector[3];
			}
			TmpObj->ActionRequestForce(&AN_CmnActEntryWait);
			
			// TODO do the rest. i'm lazy
		}
		break;
	case BOM_EVENT_ARCADE_EVENT_SETUP:
		{
			FMemory::Memset(&m_EventData, 0, sizeof(m_EventData));
			for (OBJ_CCharBase& Char : m_CharVector)
			{
				// TODO stop lip, that doesn't exist yet though
			}
		}
	}
}
