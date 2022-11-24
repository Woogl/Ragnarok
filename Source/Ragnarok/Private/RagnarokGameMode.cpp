// Copyright Epic Games, Inc. All Rights Reserved.

#include "RagnarokGameMode.h"
#include "RagnarokCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARagnarokGameMode::ARagnarokGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("Blueprint'/Game/CombatSystem/Blueprints/Actors/BP_CombatPlayerCharacter'"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ARagnarokGameMode::BeginPlay()
{
	Super::BeginPlay();

}