// Copyright Epic Games, Inc. All Rights Reserved.

#include "RabbitCatcherGameMode.h"
#include "RabbitCatcherCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARabbitCatcherGameMode::ARabbitCatcherGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
