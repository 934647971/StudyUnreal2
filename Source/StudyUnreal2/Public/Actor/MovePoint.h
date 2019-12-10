// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovePoint.generated.h"

UCLASS()
class STUDYUNREAL2_API AMovePoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovePoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Component)
		class UDecalComponent*	Decal;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Component)
		class UBoxComponent* Box;
};