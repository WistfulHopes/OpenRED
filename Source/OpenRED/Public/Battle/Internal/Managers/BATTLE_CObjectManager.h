#pragma once
#include "BATTLE_TeamManager.h"
#include "OpenRED/Public/Battle/Internal/CXXBYTE.h"
#include "OpenRED/Public/Battle/Internal/Objects/OBJ_CCharBase.h"

class BATTLE_CObjectManager
{
public:
	struct SEventData
	{
		int MessageTime;
		bool bMessageSet;
		OBJ_CBase *pManagerObj;
		OBJ_CBase *pSpeakChara[4];
		int LipSyncFrame;
		bool bLipSyncFlag;
		bool bEnd;
		OBJ_CBase *pExChara[4];
		CXXBYTE<16> ExCharaID[4];
		OBJ_CBase *pLoadWaitObj;
	};
	
	BATTLE_TeamManager m_TeamManager[2];
	unsigned int m_BOMFlag;

	int m_ShinSousaiTimer;

	// Per team values
	
	int m_BurstVal[2];
	int m_MatchStaticValue0[2];
	int m_MatchStaticValue1[2];
	int m_Rakusyo[2];
	int m_YogoreLevel[2];
	int m_PreBurstVal[2];
	int m_PreMatchStaticValue0[2];
	int m_PreMatchStaticValue1[2];
	int m_PreRakusyo[2];
	int m_PreYogoreLevel[2];
	
	// Post process related
	int m_DiffusionFilter2LevelMax;
	int m_DiffusionFilter2SaturationMin;
	int m_FinishSlowTime;
	int m_MotionBlurAmount;

	SEventData m_EventData;
	
private:
	// what does env do?
	int m_EnvStylishDefence;
	int m_EnvStylishTension;
	int m_EnvStylishBurst;
	// or dokidoki?
	int m_EnvDokiDokiStop;
	int m_EnvDokiDokiStopHikitsuke;
	int m_EnvDokiDokiStopXRangeMin;
	int m_EnvDokiDokiStopXRangeMax;
	int m_EnvDokiDokiStopYRangeMax;
	int m_EnvDokiDokiStopHassei;
	int m_EnvDokiDokiStopFinishStop;
	int m_DokiDokiStopByDokiDokiKill;
	int m_DokiDokiStopIgnoreTime;

	// Trial/boss related
	int m_TrialBossHP;
	int m_TrialBossHPMax;
	int m_TrialBossBarrier;
	int m_TrialExVal0;
	int m_TrialExVal1;
	int m_TrialExVal2;
	int m_TrialExVal3;
	
	// Checksum related
	unsigned int m_BattleCheckSumTimeCount;
	unsigned int m_BattleCheckSum;
	unsigned int m_BattleCheckSumErrorFound;
	uint8 m_BattleCheckSumErrorFoundList[2];

	
	unsigned int m_BOMRandomSeed;
	
	int m_EventVsVoiceRandomIndex;
	int m_EventVsVoiceNum;

	// Object vectors
	OBJ_CBase m_ObjVector[101];
	OBJ_CCharBase m_CharVector[6];
	
public:
	BATTLE_CObjectManager();
	
	void ExecuteObjectManagerEvent(class BattleEventManager* pBEM);
	void BOM_RoundAndEasyResetInitialize(bool use2ndInitialize);
	
private:
	void ExecuteObjectManagerEvent(const struct BOMEventInfo *pEvent);
};
