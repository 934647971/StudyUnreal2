// Fill out your copyright notice in the Description page of Project Settings.


#include "ShinbiCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "ConstructorHelpers.h"
#include "Engine/Blueprint.h"
#include "Engine/SkeletalMesh.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"

AShinbiCharacter::AShinbiCharacter()
{
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;


	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMesh(TEXT("SkeletalMesh'/Game/MyGame/Character/SK_Shinbi.SK_Shinbi'"));
	static ConstructorHelpers::FObjectFinder<UBlueprint> ShinbiAnimationBP(TEXT("AnimBlueprint'/Game/MyGame/Character/Animation/ABP_ShinBi.ABP_Shinbi'"));
	UClass* AniBP = (UClass*)ShinbiAnimationBP.Object->GeneratedClass;
	//MeshCom = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComponent"));
	GetMesh()->SetupAttachment(RootComponent);
	GetMesh()->SetSkeletalMesh(SkeletalMesh.Object);
	GetMesh()->SetAnimInstanceClass(AniBP);
	GetMesh()->SetRelativeRotation(FRotator(0,-90,0));
	GetMesh()->SetRelativeLocation(FVector(0,0,-90));

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmCom"));
	SpringArm->SetupAttachment(RootComponent);
	//SpringArm->bUsePawnControlRotation = true;
	SpringArm->bAbsoluteRotation = true;
	SpringArm->TargetArmLength = 600.f;
	SpringArm->RelativeRotation = FRotator(-45.f, 0.f, 0.f);
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritRoll = false;
	SpringArm->bInheritYaw = false;
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	Camera->SetupAttachment(SpringArm);
	Camera->bUsePawnControlRotation = false;
	GetCapsuleComponent()->SetGenerateOverlapEvents(true);

}
