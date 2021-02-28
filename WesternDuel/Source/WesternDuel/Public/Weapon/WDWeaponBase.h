// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WDWeaponBase.generated.h"

class AWDProjectTileActor;

USTRUCT(BlueprintType)
struct FWeaponData {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	int32 MaxBullets;
	
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	int32 CurrentBullets;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	TSubclassOf<AWDProjectTileActor> ProjectileClass;


};

UCLASS()
class WESTERNDUEL_API AWDWeaponBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWDWeaponBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	USkeletalMeshComponent* SkeletalMeshComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	FName MuzzleSocketName;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	FWeaponData CurrentWeaponData;
public:
	UFUNCTION()
	void Fire();
	UFUNCTION()
	bool IsEmpty();
	UFUNCTION()
	FVector GetMuzzleLocation();

};
