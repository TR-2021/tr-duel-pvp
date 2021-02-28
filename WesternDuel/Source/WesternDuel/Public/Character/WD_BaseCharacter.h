// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WD_BaseCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UCharacterMovementComponent;
class UWDWeaponComponent;
class UWDHealthComponent;
UCLASS()
class WESTERNDUEL_API AWD_BaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AWD_BaseCharacter();

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, Category = "Player")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Player")
	UCameraComponent* CameraComponent;
	
	UPROPERTY(EditDefaultsOnly, Category = "Player")
	UCharacterMovementComponent* MovementComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	UWDWeaponComponent* WeaponComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	UWDHealthComponent* HealthComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Player")
	bool GunIsTaken = false;
	
	UPROPERTY(EditDefaultsOnly, Category = "Player")
	bool IsAiming = false;

	float InputDirection = 0;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION(BlueprintCallable)
	float GetMovementDirection();
	
	UFUNCTION(BlueprintCallable)
	bool HasGunTaken() { return GunIsTaken; }

	UFUNCTION(BlueprintCallable)
	bool IsAim() { return IsAiming; };
	
	UFUNCTION(BlueprintCallable)
	FRotator GetAimDirection();
private:
	void MoveRight(float Value);
	void LookUp(float Value);
	void LookAround(float Value);
	void TryFire();
	void TakeGun();
	void PutBackGun();
	void StartAim();
	void StopAim();
	UFUNCTION()
	void OnDie();
};
