// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "REDWidgetBase.h"
#include "UIEnums.h"
#include "REDWidgetFade.generated.h"

class UImage;
/**
 * 
 */
UCLASS()
class OPENRED_API UREDWidgetFade : public UREDWidgetBase
{
	GENERATED_BODY()

public:
	uint8 FadeType;
	uint8 DispFadeType;
	bool bFadeDraw;
	bool bFadeEnd;
	float FadeTime;
	float FadeTimeAdd;
	FLinearColor FadeColor;

	UPROPERTY()
	UImage *Image_DefaultFade;
	UPROPERTY()
	UREDWidgetBase *Widget_AnimationFade;

	void FadeOutFast(EFadeType type);
	void SwitchDispState(EFadeType type);
};
