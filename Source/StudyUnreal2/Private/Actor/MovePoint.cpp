// Fill out your copyright notice in the Description page of Project Settings.


#include "MovePoint.h"
#include "Engine.h"

// Sets default values
AMovePoint::AMovePoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UMaterialInstanceConstant> MaterialIns(TEXT("MaterialInstanceConstant'/Game/MyGame/Material/M_MovePoint_Inst.M_MovePoint_Inst'"));
	Decal = CreateDefaultSubobject<UDecalComponent>(TEXT("Decal"));
	Decal->SetupAttachment(RootComponent);
	Decal->SetDecalMaterial(MaterialIns.Object);
	Decal->SetRelativeRotation(FRotator( -90, 0, 0));
	Decal->DecalSize = FVector(70,35,35);
	
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	Box->SetupAttachment(RootComponent);
	Box->SetRelativeRotation(FRotator(-90, 0, 0));
	Box->SetBoxExtent(FVector(75,45,45));

}

// Called when the game starts or when spawned
void AMovePoint::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void AMovePoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

