// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/WDProjectTileActor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Character/WD_BaseCharacter.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "Containers/Map.h"
#include "Net/UnrealNetwork.h"

#include "DrawDebugHelpers.h"

AWDProjectTileActor::AWDProjectTileActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;
	SphereCollider = CreateDefaultSubobject<USphereComponent>("Collider");
	SphereCollider->InitSphereRadius(10.0f);
	SphereCollider->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereCollider->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);

	RootComponent = SphereCollider;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	ProjectileMesh->SetupAttachment(GetRootComponent());

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("Movement Component");
	ProjectileMovementComponent->InitialSpeed = 12000;

}

// Called when the game starts or when spawned
void AWDProjectTileActor::BeginPlay()
{
	Super::BeginPlay();
	ProjectileMovementComponent->Velocity = ShotDirection * ProjectileMovementComponent->InitialSpeed;
	SphereCollider->bReturnMaterialOnMove = true;
	if (HasAuthority())
	{
		SphereCollider->OnComponentHit.AddDynamic(this, &AWDProjectTileActor::OnHit);
	}
	SetLifeSpan(LifeSpan);
}

void AWDProjectTileActor::SetShotDirection(FVector Vector)
{
	ShotDirection = Vector;
}
void AWDProjectTileActor::SetShotController(AController* Controller)
{
	ShotController = Controller;
}

void AWDProjectTileActor::SetLifeTime(float Time)
{
	LifeSpan = Time;
}

void AWDProjectTileActor::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	Destroy();

	if (!GetWorld()) return;

	AWD_BaseCharacter* Character = Cast<AWD_BaseCharacter>(OtherActor);
	if (!Character) return;

		UPhysicalMaterial* PhysMaterial = Hit.PhysMaterial.Get();
		float ResultDamage = BaseDamage;
		if (PhysicsDamageMap.Contains(PhysMaterial)) {
			ResultDamage = PhysicsDamageMap[PhysMaterial];
		}
		Character->TakeDamage(ResultDamage, {}, ShotController, this);
}
void AWDProjectTileActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AWDProjectTileActor, ShotDirection);
}