// Fill out your copyright notice in the Description page of Project Settings.


#include "Battle/REDPawnPlayer.h"


// Sets default values
AREDPawnPlayer::AREDPawnPlayer()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AREDPawnPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AREDPawnPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AREDPawnPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

