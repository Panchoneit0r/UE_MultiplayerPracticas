// Copyright Epic Games, Inc. All Rights Reserved.

#include "MultiP2GameMode.h"
#include "MultiP2Character.h"
#include "UObject/ConstructorHelpers.h"

AMultiP2GameMode::AMultiP2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
