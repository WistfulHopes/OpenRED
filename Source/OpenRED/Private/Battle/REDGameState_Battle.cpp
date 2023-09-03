// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenRED/Public/Battle/REDGameState_Battle.h"

#include "Battle/REDHUD_Battle.h"
#include "Common/REDGameViewportClient.h"
#include "Common/REDPlayerController.h"
#include "OpenRED/Public/Common/REDNamespace.h"

void AREDGameState_Battle::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	UpdateBattle(DeltaSeconds);
}

void AREDGameState_Battle::HandleMatchIsWaitingToStart()
{
	// init values
	
	PauseMenuButtonPressFrame[0] = 0;
	PauseMenuButtonPressFrame[1] = 0;
	m_BattleUpdateCount = 0;
	m_RoundUpdateCount = 0;
	m_SendMessageInterval = 0;
	bNetworkBattle = false;
	bRankMatchBattle = false;
	bCasualMatchBattle = false;
	bLobbyMatchBattle = false;

	if (!bAllocateInstances)
	{
		for (int i = 0; i < 3; i++)
		{
			TeamInfo[i] = MakeUnique<FTeamInfo>(FTeamInfo());
		}
		BattleObjectManager = MakeUnique<BATTLE_CObjectManager>(BATTLE_CObjectManager());
		EventManager = MakeUnique<BattleEventManager>(BattleEventManager());
		State = MakeUnique<BattleState>(BattleState());
	}
	
	Super::HandleMatchIsWaitingToStart();

	bDispCharaOutDispIcon = true;
	if (IsValid(PrimaryPC))
	{
		const auto HUD = PrimaryPC->GetHUD();
		if (HUD && Cast<AREDHUD_Battle>(HUD))
		{
			const auto GameViewportClient = GetGameInstance()->GetGameViewportClient();
			if (const auto REDViewportClient = Cast<UREDGameViewportClient>(GameViewportClient))
			{
				REDViewportClient->FadeOutFast(EFadeType::Off);
			}
		}
	}

	// TODO handle spawning, hud, everything else
}

void AREDGameState_Battle::HandleMatchHasStarted()
{
	Super::HandleMatchHasStarted();

	SetupBattle();
}

void AREDGameState_Battle::SetupBattle()
{
	
	BattleObjectManager.Get()->BOM_RoundAndEasyResetInitialize(false);
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
