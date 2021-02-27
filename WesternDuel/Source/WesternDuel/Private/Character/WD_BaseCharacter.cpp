// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/WD_BaseCharacter.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
AWD_BaseCharacter::AWD_BaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWD_BaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWD_BaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AWD_BaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

