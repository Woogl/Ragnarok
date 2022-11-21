// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RagnarokCharacter.generated.h"

UENUM(BlueprintType)
enum class ECharacterState : uint8
{
	Nothing,
	Attacking,
	Dodging,
	GeneralActionState,
	Dead,
	Disabled,
};

UENUM(BlueprintType)
enum class ECharacterAction : uint8
{
	Nothing,
	General,
	LightAttack,
	HeavyAttack,
	ChargedAttack,
	FallingAttack,
	SprintAttack,
	Dodge,
	EnterCombat,
	ExitCombat,
};

UENUM(BlueprintType)
enum class EMovementSpeedMode : uint8
{
	Walking,
	Joging,
	Sprinting,
};

UCLASS(config=Game)
class ARagnarokCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

public:
	ARagnarokCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Input)
	float TurnRateGamepad;

protected:

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	UFUNCTION(BlueprintImplementableEvent)
	void MyJump();

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

private:
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	EMovementSpeedMode MovementSpeedMode = EMovementSpeedMode::Joging;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	UFUNCTION(BlueprintCallable)
	FORCEINLINE EMovementSpeedMode GetCurrentSpeedMode() const { return MovementSpeedMode; }	// 리턴 타입에 포인터(*) 붙여야하나?
};

