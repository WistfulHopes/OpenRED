// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "REDPawn.h"
#include "REDPawnPlayer.generated.h"

UCLASS()
class OPENRED_API AREDPawnPlayer : public AREDPawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AREDPawnPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};