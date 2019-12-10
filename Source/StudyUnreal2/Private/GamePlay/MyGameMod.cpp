// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameMod.h"
#include "ShinbiCharacter.h"
#include "ShinbiController.h"
AMyGameMod::AMyGameMod()
{
	DefaultPawnClass = AShinbiCharacter::StaticClass();
	PlayerControllerClass = AShinbiController::StaticClass();
}
