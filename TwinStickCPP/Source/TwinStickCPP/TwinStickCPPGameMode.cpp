// Copyright Epic Games, Inc. All Rights Reserved.

#include "TwinStickCPPGameMode.h"
#include "TwinStickCPPPawn.h"

ATwinStickCPPGameMode::ATwinStickCPPGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = ATwinStickCPPPawn::StaticClass();
}

