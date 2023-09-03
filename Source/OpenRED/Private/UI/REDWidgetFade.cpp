// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/REDWidgetFade.h"

#include "Components/Image.h"

void UREDWidgetFade::FadeOutFast(EFadeType type)
{
	FadeType = type;
	bFadeDraw = true;
	bFadeEnd = true;
	FadeTimeAdd = 1;
	FadeTime = 1;
	SwitchDispState(EFadeType::Off);
}

void UREDWidgetFade::SwitchDispState(EFadeType type)
{
	ESlateVisibility Visibility;
	if (type == EFadeType::On)
	{
		Image_DefaultFade->SetVisibility(ESlateVisibility::Collapsed);
		Visibility = ESlateVisibility::SelfHitTestInvisible;
	}
	else
	{
		Image_DefaultFade->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
		Visibility = ESlateVisibility::Collapsed;
	}
	Widget_AnimationFade->SetVisibility(Visibility);
}
