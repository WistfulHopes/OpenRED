// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenRED/Public/Common/REDGameMode.h"

#include "Common/REDGameState.h"
#include "Common/REDHUD.h"
#include "Common/REDPlayerController.h"

AREDGameMode::AREDGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	GameStateClass = AREDGameState::StaticClass();
	PlayerControllerClass = AREDPlayerController::StaticClass();
	HUDClass = AREDHUD::StaticClass();
}
