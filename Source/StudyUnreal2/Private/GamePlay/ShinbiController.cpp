// Fill out your copyright notice in the Description page of Project Settings.


#include "ShinbiController.h"
#include "MovePoint.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Engine/World.h"
#include "ShinbiCharacter.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Engine.h"
#include "GenericPlatformMath.h"

AShinbiController::AShinbiController()
	:bMouseRightPress(false),
	MovePoint(nullptr),
	Character(nullptr)
{
	bShowMouseCursor = true;
	
}

void AShinbiController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	
}

void AShinbiController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindKey(EKeys::LeftMouseButton, IE_Pressed, this, &AShinbiController::OnLeftMouseDown);
	InputComponent->BindKey(EKeys::LeftMouseButton, IE_Released, this, &AShinbiController::OnLeftMouseReleased);

	InputComponent->BindKey(EKeys::RightMouseButton, IE_Pressed, this, &AShinbiController::OnRightMouseDown);
	InputComponent->BindKey(EKeys::RightMouseButton, IE_Released, this, &AShinbiController::OnRightMouseReleased);

	InputComponent->BindAxis("MoveForward", this, &AShinbiController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AShinbiController::MoveRight);

	
	InputComponent->BindAxis("Turn", this, &AShinbiController::Turn);
	InputComponent->BindAxis("lookUp", this, &AShinbiController::LookUp);
}

void AShinbiController::BeginPlay()
{
	Super::BeginPlay();
	Character = Cast<AShinbiCharacter>(GetPawn());
}

void AShinbiController::OnLeftMouseDown()
{
	MoveToPoint();
}

void AShinbiController::OnLeftMouseReleased()
{
	
}

void AShinbiController::OnRightMouseDown()
{
	bMouseRightPress = true;
}

void AShinbiController::OnRightMouseReleased()
{
	bMouseRightPress = false;
}

void AShinbiController::MoveForward(float value)
{
	if (value != 0.0f && Character != nullptr)
	{
		if (MovePoint != nullptr)
		{
			MovePoint->Destroy();
		}
		
		float Yaw = GetControlRotation().Yaw;
		FRotator Ro = FRotator(0,Yaw,0);
		FVector vec = Ro.Vector();
		FVector FVe = vec.ForwardVector;
		FVector MoveVector = FVe;
		//FVector MoveVector = FRotator(0,GetControlRotation().Yaw, 0).Vector().ForwardVector;
		Character->AddMovementInput(MoveVector, value);
	}
}

void AShinbiController::MoveRight(float value)
{
	if (value != 0.0f && Character != nullptr)
	{
		if (MovePoint != nullptr)
		{
			MovePoint->Destroy();
		}
		
		FVector MoveVector = FRotator(0, GetControlRotation().Yaw, 0).Vector().RightVector;
		Character->AddMovementInput(MoveVector, value);
	}
}

void AShinbiController::LookUp(float value)
{
	if (value != 0 && Character != nullptr && bMouseRightPress)
	{
		FRotator SpringRotation = Character->SpringArm->GetTargetRotation();
		SpringRotation.Pitch = FMath::Clamp(SpringRotation.Pitch + value * 2, -50.f, 0.f);
		Character->SpringArm->SetRelativeRotation(SpringRotation);

	}
}

void AShinbiController::Turn(float value)
{
	if (value != 0 && Character != nullptr &&bMouseRightPress)
	{
		FRotator SpringRotation = Character->SpringArm->GetTargetRotation();
		SpringRotation.Yaw = SpringRotation.Yaw + value * 2;
		Character->SpringArm->SetRelativeRotation(SpringRotation);

	}

}

void AShinbiController::MoveToPoint()
{
	
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);
	if (Hit.bBlockingHit)
	{
		if (MovePoint != nullptr)
		{
			MovePoint->Destroy();
		}
		MovePoint =Cast<AMovePoint>(GetWorld()->SpawnActor(AMovePoint::StaticClass(),&Hit.Location));
		if (Character)
		{	
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, Hit.ImpactPoint);
		}
	}
}
