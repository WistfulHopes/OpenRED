// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "REDWidgetBase.generated.h"

class UUnionAnimationManager;
/**
 * 
 */
UCLASS()
class OPENRED_API UREDWidgetBase : public UUserWidget
{
	GENERATED_BODY()

	bool bEnabledPlayChildAnim;
	bool bAllowedPlayAnimByParent;

	UPROPERTY()
	UUnionAnimationManager* UnionAnimationManager;
	float OverwriteTickDeltaTime;
};
