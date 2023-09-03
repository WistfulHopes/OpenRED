// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenRED/Public/Battle/REDGameMode_Battle.h"

#include "Battle/REDGameState_Battle.h"
#include "Battle/REDHUD_Battle.h"
#include "Battle/REDPlayerController_Battle.h"

AREDGameMode_Battle::AREDGameMode_Battle(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	GameStateClass = AREDGameState_Battle::StaticClass();
	PlayerControllerClass = AREDPlayerController_Battle::StaticClass();
	HUDClass = AREDHUD_Battle::StaticClass();
}
