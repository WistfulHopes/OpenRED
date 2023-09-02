// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Internal/BattleState.h"
#include "Internal/Managers/BattleEventManager.h"
#include "Internal/Managers/BATTLE_CObjectManager.h"
#include "OpenRED/Public/Common/REDGameState.h"


#include "REDGameState_Battle.generated.h"

/**
 * 
 */
UCLASS()
class OPENRED_API AREDGameState_Battle : public AREDGameState
{
	GENERATED_BODY()

	bool bIsSuspend;

public:
	TUniquePtr<BATTLE_CObjectManager> BattleObjectManager;
	TUniquePtr<BattleEventManager> EventManager;
	TUniquePtr<BattleState> State;

protected:
	virtual void Tick(float DeltaSeconds) override;

private:
	/**
	 * Battle related functions.
	 */
	void UpdateBattle(float DeltaSeconds);
	void UpdateBattleSub(float DeltaSeconds, bool bUpdateDraw);

public:
	virtual bool IsSuspend();
};
