// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GamePlay/MyGameCharacter.h"
#include "ShinbiCharacter.generated.h"

/**
 * 
 */
UCLASS()
class STUDYUNREAL2_API AShinbiCharacter : public AMyGameCharacter
{
	GENERATED_BODY()		
public:
	 AShinbiCharacter();
	 UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Component)
		 class USpringArmComponent* SpringArm;
	 UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Component)
		 class UCameraComponent* Camera;
	 UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Component)
		 class USkeletalMeshComponent* MeshCom;
};
