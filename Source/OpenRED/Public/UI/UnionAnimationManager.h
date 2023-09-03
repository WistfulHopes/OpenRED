// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UnionAnimationManager.generated.h"

DECLARE_MULTICAST_DELEGATE_TwoParams(EndDelegateSignature, class UUnionAnimationManager*, const FName&)
DECLARE_MULTICAST_DELEGATE_TwoParams(EndDelegateForParentSignature, UUnionAnimationManager*, const FName&)

/**
 * 
 */
UCLASS()
class OPENRED_API UUnionAnimationManager : public UObject
{
	GENERATED_BODY()

public:
	enum ERequestType
	{
		Start,
		Update,
		Stop,
	};

	class RequestItem
	{
	public:
		uint8 RequestType;
		FName AnimationName;
		float Speed;
		float StartPos;
	};
	
	class SGroupInstance
	{
	public:
		enum ERequestType
		{
			None,
			Single,
			SingleToggle,
			Multi,
		};
		
		class SRequest
		{
		public:
			ERequestType Type;
			FName Name;
			float Speed;
			float StartPos;
		};
		
		EndDelegateSignature EndDelegate;
		EndDelegateForParentSignature EndDelegateForParent;
	};

	TMap<int, SGroupInstance> GroupData;
	TMap<int, RequestItem> RequestData;
};
