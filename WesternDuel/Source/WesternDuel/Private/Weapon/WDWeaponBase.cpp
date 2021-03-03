// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/WDWeaponBase.h"
#include "Weapon/WDProjectTileActor.h"
#include "UI/WDCrosshairActor.h"
#include "Net/UnrealNetwork.h"
#include "DrawDebugHelpers.h"

AWDWeaponBase::AWDWeaponBase()
{
	PrimaryActorTick.bCanEverTick = true;
	
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Root"));
	RootComponent = SkeletalMeshComponent;
	MuzzleSocketName = "Muzzle";

}

void AWDWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	Crosshair = GetWorld()->SpawnActor<AWDCrosshairActor>(CurrentWeaponData.CrosshairClass);
	bReplicates = true;
}
void AWDWeaponBase::BeginDestroy()
{
	if(Crosshair)
		Crosshair->Destroy();
	Super::BeginDestroy();
}

void AWDWeaponBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (ShouldDrawCrosshair) {
		FHitResult Hit;
		FVector Start = GetMuzzleLocation();
		FVector End = GetMuzzleLocation() + GetActorForwardVector() * 3381.236643389053;
		//DrawDebugLine(GetWorld(), Start, End, FColor::Blue, false, 0.1f, 0, 1);
		//// TODO Fix crosshair
		//GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECollisionChannel::ECC_Pawn);

		//if (Hit.bBlockingHit) {
		//	DrawDebugLine(GetWorld(), Start, Hit.ImpactPoint, FColor::Cyan, false, 0.1f, 0, 1);
		//	End = Hit.ImpactPoint;
		//}
		Crosshair->SetActorLocation(End);
	}
}
void AWDWeaponBase::Fire_Implementation()
{
	if (!IsEmpty() && GetWorld()) {
		//Fire
		DecreaseAmmoBy(1);
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
void AWDWeaponBase::DecreaseAmmoBy(int32 Num) {
	CurrentWeaponData.CurrentBullets = FMath::Clamp<int32>(CurrentWeaponData.CurrentBullets-Num,0, CurrentWeaponData.MaxBullets);
}
FVector AWDWeaponBase::GetMuzzleLocation() {
	return SkeletalMeshComponent->GetSocketLocation(MuzzleSocketName);
}

USkeletalMeshComponent* AWDWeaponBase::GetMesh()
{
	return SkeletalMeshComponent;
}

void  AWDWeaponBase::SetCrosshairDrawing(bool IsDrawing) {
	ShouldDrawCrosshair = IsDrawing;
	Crosshair->SetActorHiddenInGame(!IsDrawing);
}
void AWDWeaponBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AWDWeaponBase, SkeletalMeshComponent);
	DOREPLIFETIME(AWDWeaponBase, CurrentWeaponData);
	DOREPLIFETIME(AWDWeaponBase, ShouldDrawCrosshair);
	
}