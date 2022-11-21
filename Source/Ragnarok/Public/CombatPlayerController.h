// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CombatPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class RAGNAROK_API ACombatPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UUserWidget> Widget;

	UPROPERTY()
	UUserWidget* MainHUD;

};
