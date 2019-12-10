// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShinbiController.generated.h"

/**
 * 
 */
UCLASS()
class STUDYUNREAL2_API AShinbiController : public APlayerController
{
	GENERATED_BODY()
public:
	
	AShinbiController();
	virtual void PlayerTick(float DeltaTime)override;
	virtual void SetupInputComponent()override;
	virtual void BeginPlay()override;
	void OnLeftMouseDown();
	void OnLeftMouseReleased();
	void OnRightMouseDown();
	void OnRightMouseReleased();
	void MoveForward(float value);
	void MoveRight(float value);
	void LookUp(float value);
	void Turn(float value);
	void MoveToPoint();
private:
	bool bMouseRightPress;
	class AMovePoint* MovePoint;
	class AShinbiCharacter* Character;
	
};
