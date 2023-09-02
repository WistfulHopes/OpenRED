// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "REDGameCommon.generated.h"

/**
 * 
 */
UCLASS()
class OPENRED_API UREDGameCommon : public UGameInstance
{
	GENERATED_BODY()

public:
	UREDGameCommon();

	static UREDGameCommon* sInstance;
};
