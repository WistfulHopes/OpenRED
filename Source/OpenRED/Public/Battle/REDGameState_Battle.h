// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TeamInfo.h"
#include "Internal/BattleState.h"
#include "Internal/Managers/BattleEventManager.h"
#include "Internal/Managers/BATTLE_CObjectManager.h"
#include "OpenRED/Public/Common/REDGameState.h"


#include "REDGameState_Battle.generated.h"

class AREDPlayerController;
/**
 * 
 */
UCLASS()
class OPENRED_API AREDGameState_Battle : public AREDGameState
{
	GENERATED_BODY()

	bool bIsSuspend;

	UPROPERTY()
	AREDPlayerController* PrimaryPC;
public:

	// Pointers to internal battle state
	TUniquePtr<FTeamInfo> TeamInfo[3];
	TUniquePtr<BATTLE_CObjectManager> BattleObjectManager;
	TUniquePtr<BattleEventManager> EventManager;
	TUniquePtr<BattleState> State;

	int16 PauseMenuButtonPressFrame[2];
	uint8 m_BattleState;

	int m_NetworkErrorState;
	int m_NetworkErrorStatePrev;
	int m_BattleUpdateCount;
	int m_RoundUpdateCount;
	int m_SendMessageInterval;
	bool bNetworkBattle;
	bool bRankMatchBattle;
	bool bCasualMatchBattle;
	bool bLobbyMatchBattle;
	bool bDispCharaOutDispIcon;
	bool bAllocateInstances;
	bool bSuspend;
	bool bDispHUDTop;
	bool bDispHUDTopNotHide;
	bool bDispHUDBottom;
	
protected:
	virtual void Tick(float DeltaSeconds) override;
	virtual void HandleMatchIsWaitingToStart() override;
	virtual void HandleMatchHasStarted() override;
	
private:
	/**
	 * Battle related functions.
	 */
	void SetupBattle();
	void UpdateBattle(float DeltaSeconds);
	void UpdateBattleSub(float DeltaSeconds, bool bUpdateDraw);

public:
	virtual bool IsSuspend();
};
