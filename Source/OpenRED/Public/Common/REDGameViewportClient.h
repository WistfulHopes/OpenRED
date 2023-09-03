// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameViewportClient.h"
#include "UI/UIEnums.h"
#include "REDGameViewportClient.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnFadeInSignature, bool)
DECLARE_MULTICAST_DELEGATE_OneParam(FOnFadeOutSignature, bool)

/**
 * 
 */
UCLASS()
class OPENRED_API UREDGameViewportClient : public UGameViewportClient
{
	GENERATED_BODY()
	
	FOnFadeInSignature OnFadeInDelegates;
	FOnFadeOutSignature OnFadeOutDelegates;

public:
	void FadeOutFast(EFadeType type) const;
};
