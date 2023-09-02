// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenRED/Public/Common/REDGameCommon.h"

UREDGameCommon* UREDGameCommon::sInstance = nullptr;

UREDGameCommon::UREDGameCommon()
{
	if (sInstance == nullptr) sInstance = this;
}
