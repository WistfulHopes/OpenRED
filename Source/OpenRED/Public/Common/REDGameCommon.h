// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Battle/Internal/BattleEnums.h"
#include "Engine/GameInstance.h"
#include "REDGameCommon.generated.h"

class UREDWidgetFade;
/**
 * 
 */
UCLASS()
class OPENRED_API UREDGameCommon : public UGameInstance
{
	GENERATED_BODY()

public:
	UREDGameCommon();

	int playerID;
	SIDE_ID m_PlayerSide;

	UPROPERTY()
	UREDWidgetFade* FadeWidget;
	
	static UREDGameCommon* sInstance;
};
