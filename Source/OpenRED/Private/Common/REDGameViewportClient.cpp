// Fill out your copyright notice in the Description page of Project Settings.


#include "Common/REDGameViewportClient.h"

#include "Common/REDGameCommon.h"
#include "UI/REDWidgetFade.h"

void UREDGameViewportClient::FadeOutFast(EFadeType type) const
{
	OnFadeOutDelegates.Broadcast(false);
	UREDGameCommon::sInstance->FadeWidget->FadeOutFast(type);
}
