// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenRED/Public/Battle/REDGameState_Battle.h"

#include "OpenRED/Public/Common/REDNamespace.h"

void AREDGameState_Battle::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	UpdateBattle(DeltaSeconds);
}

void AREDGameState_Battle::UpdateBattle(float DeltaSeconds)
{
	if (IsSuspend()) return;

	// TODO move this into a rollback block once that's set up
	UpdateBattleSub(DeltaSeconds, true);
}

void AREDGameState_Battle::UpdateBattleSub(float DeltaSeconds, bool bUpdateDraw)
{
	// TODO check if game is paused first

	
	auto ObjectManager = red::btl::GetObjectManager();
}

bool AREDGameState_Battle::IsSuspend()
{
	return bIsSuspend;
}
