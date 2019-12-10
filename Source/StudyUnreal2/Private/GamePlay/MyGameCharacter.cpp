// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameCharacter.h"

// Sets default values
AMyGameCharacter::AMyGameCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyGameCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyGameCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

