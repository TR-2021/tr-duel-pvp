// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/WDWeaponBase.h"
#include "Weapon/WDProjectTileActor.h"
#include "DrawDebugHelpers.h"

AWDWeaponBase::AWDWeaponBase()
{
	PrimaryActorTick.bCanEverTick = true;
	
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Root"));
	RootComponent = SkeletalMeshComponent;

	CurrentWeaponData = FWeaponData{ 6, 6 };
	MuzzleSocketName = "Muzzle";

}

void AWDWeaponBase::BeginPlay()
{
	Super::BeginPlay();
}
void AWDWeaponBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	DrawDebugLine(GetWorld(), GetMuzzleLocation(), GetMuzzleLocation() + GetActorForwardVector() * 1200, FColor::Blue,false, 0.1f, 0, 1);
}
void AWDWeaponBase::Fire()
{
	if (!IsEmpty() || GetWorld()) {
		//Fire
		CurrentWeaponData.CurrentBullets--;
		//Spawn ProjectTile
		FTransform ProjectileTransform = FTransform(FRotator::ZeroRotator, GetMuzzleLocation());
		auto ProjectTile = GetWorld()->SpawnActorDeferred<AWDProjectTileActor>(CurrentWeaponData.ProjectileClass, ProjectileTransform, GetOwner());
		ProjectTile->SetShotDirection(GetActorForwardVector());
		ProjectTile->SetOwner(GetOwner());
		ProjectTile->FinishSpawning(ProjectileTransform);
	}
}


bool AWDWeaponBase::IsEmpty()
{
	return CurrentWeaponData.CurrentBullets == 0;
}

FVector AWDWeaponBase::GetMuzzleLocation() {
	return SkeletalMeshComponent->GetSocketLocation(MuzzleSocketName);
}