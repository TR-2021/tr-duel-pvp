// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WDWeaponBase.generated.h"

class AWDProjectTileActor;
class AWDCrosshairActor;
USTRUCT(BlueprintType)
struct FWeaponData {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	int32 MaxBullets;
	
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	int32 CurrentBullets;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	TSubclassOf<AWDProjectTileActor> ProjectileClass;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	TSubclassOf<AWDCrosshairActor> CrosshairClass;

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
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(EditDefaultsOnly, replicated,Category = "Weapon")
	USkeletalMeshComponent* SkeletalMeshComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	FName MuzzleSocketName;

	UPROPERTY(EditDefaultsOnly, replicated, Category = "Weapon")
	FWeaponData CurrentWeaponData;
	
	UPROPERTY()
	AWDCrosshairActor* Crosshair;
	UPROPERTY()
	bool ShouldDrawCrosshair = true;

public:
	UFUNCTION(Server, reliable)
	void Fire();

	UFUNCTION()
	bool IsEmpty();

	UFUNCTION()
	FVector GetMuzzleLocation();

	UFUNCTION()
	USkeletalMeshComponent* GetMesh();

	UFUNCTION()
	void SetCrosshairDrawing(bool IsDrawing);


private:
	void DecreaseAmmoBy(int32 Num);
	
};
