// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WDHealthComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FHealthOnDieSignature, AController*)
DECLARE_MULTICAST_DELEGATE_OneParam(FHealthOnChangedSignature, float);

USTRUCT(BlueprintType)
struct FHealthData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly)
	float DefaultHealth = 100.0f;

	UPROPERTY(EditDefaultsOnly)
	float CurrentHealth = 100.0f;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WESTERNDUEL_API UWDHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWDHealthComponent();
	FHealthOnDieSignature OnDie;
	FHealthOnChangedSignature OnHealthChanged;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(EditDefaultsOnly, Replicated, Category = "Health")
	FHealthData HealthData;

	void SetHealth(float Health);

public:
	UFUNCTION()
	void OnAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
	bool IsDead();
	UFUNCTION(BlueprintCallable)
	float GetHealth();
};