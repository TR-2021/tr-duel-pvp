// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WDProjectTileActor.generated.h"

class UProjectileMovementComponent;
class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class WESTERNDUEL_API AWDProjectTileActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWDProjectTileActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, Category = "ProjectTile")
	UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(EditDefaultsOnly, Category = "ProjectTile")
	USphereComponent* SphereCollider;

	UPROPERTY(EditDefaultsOnly, Category = "ProjectTile")
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY()
	FVector ShotDirection;
	UPROPERTY()
	float LifeSpan=1;

public:	
	void SetShotDirection(FVector Vector);
	void SetLifeTime(float Time);
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
