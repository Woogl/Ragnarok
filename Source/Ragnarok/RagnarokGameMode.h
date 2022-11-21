// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RagnarokGameMode.generated.h"

UCLASS(minimalapi)
class ARagnarokGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ARagnarokGameMode();

protected:
	virtual void BeginPlay() override;
};



