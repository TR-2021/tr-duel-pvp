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
	virtual void UnPossessed() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(EditDefaultsOnly, Category = "Player")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Player")
	UCameraComponent* CameraComponent;
	
	UPROPERTY(EditDefaultsOnly, Category = "Player")
	UCharacterMovementComponent* MovementComponent;

	UPROPERTY(EditDefaultsOnly, Replicated, Category = "Weapon")
	UWDWeaponComponent* WeaponComponent;

	UPROPERTY(EditDefaultsOnly, Replicated, Category = "Weapon")
	UWDHealthComponent* HealthComponent;

	UPROPERTY(EditDefaultsOnly, Replicated, Category = "Player")
	bool GunIsTaken = false;
	
	UPROPERTY(EditDefaultsOnly, Replicated, Category = "Player")
	bool IsAiming = false;
	
	UPROPERTY(ReplicatedUsing = OnRep_Direction)
	float InputDirection = 0;
	
	UPROPERTY(Replicated)
	FRotator AimRotator;


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

	UFUNCTION(Server, unreliable)
	void UpdateAimDirection(FRotator ClientAimRotation);

	UFUNCTION(BlueprintCallable)
	UWDHealthComponent* GetHealthComponent() { return HealthComponent; };

	FRotator GetAimOffsets();


private:
	UFUNCTION(Server, unreliable)
	void MoveRight(float Value);

	void TryMoveRight(float Value);
	void LookUp(float Value);

	void LookAround(float Value);
	
	UFUNCTION(Server, unreliable)
	void Server_TryFire();
	
	UFUNCTION(Server, reliable)
	void Server_RequestTakeGun();
	

	UFUNCTION(NetMulticast, reliable)
	void TakeGun();

	UFUNCTION(Server, reliable)
	void Server_RequestPutBackGun();


	UFUNCTION(NetMulticast, reliable)
	void PutBackGun();
	
	
	UFUNCTION(Server, reliable)
	void Server_StartAim();
	
	UFUNCTION(Server, reliable)
	void Server_StopAim();
	
	UFUNCTION()
	void OnDie(AController* KilledBy);
	

	UFUNCTION(NetMulticast, reliable)
	void KillCharacter();

	UFUNCTION(NetMulticast, reliable)
	void DeleteWeapon();
	UFUNCTION()
	void OnRep_Direction();

};
