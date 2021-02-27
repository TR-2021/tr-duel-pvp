// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/WD_BaseCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "DrawDebugHelpers.h"


// Sets default values
AWD_BaseCharacter::AWD_BaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	bUseControllerRotationYaw = false;
	
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Arm Component"));
	SpringArmComponent->bUsePawnControlRotation = true;
	SpringArmComponent->TargetArmLength = 160;
	SpringArmComponent->SocketOffset = FVector(-20, 0, 60);
	SpringArmComponent->TargetOffset = FVector(0,0,10);


	SpringArmComponent->SetupAttachment(GetRootComponent());

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);
	CameraComponent->bUsePawnControlRotation = false;

	GetCharacterMovement()->bUseControllerDesiredRotation = 0;
	GetCharacterMovement()->bOrientRotationToMovement = 0;
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
	FVector AimDirection = GetBaseAimRotation().Vector();
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, AimDirection.ToString());
	DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + AimDirection * 400, FColor::Red, false, 0.1, 0, 1);
}

// Called to bind functionality to input
void AWD_BaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//PlayerInputComponent->BindAction("Dodge", EInputEvent::IE_Pressed, this, AWD_BaseCharacter::Dodge);
	//PlayerInputComponent->BindAction("Shoot", EInputEvent::IE_Pressed, this, AWD_BaseCharacter::Fire);
	PlayerInputComponent->BindAction("Aim", EInputEvent::IE_Pressed, this, &AWD_BaseCharacter::StartAim);
	PlayerInputComponent->BindAction("Aim", EInputEvent::IE_Released, this, &AWD_BaseCharacter::StopAim);
	PlayerInputComponent->BindAction("TakeGun", EInputEvent::IE_Pressed, this, &AWD_BaseCharacter::TakeGun);
	PlayerInputComponent->BindAction("TakeGun", EInputEvent::IE_Released, this, &AWD_BaseCharacter::PutBackGun);
	PlayerInputComponent->BindAxis("MoveRight", this, &AWD_BaseCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &AWD_BaseCharacter::LookUp);
	PlayerInputComponent->BindAxis("LookAround", this, &AWD_BaseCharacter::LookAround);

	
}

float AWD_BaseCharacter::GetMovementDirection()
{
	float Direction = GetVelocity().Size()*InputDirection;
	return Direction;
}

void AWD_BaseCharacter::MoveRight(float Value)
{
	if (!GunIsTaken) {
		InputDirection = Value;
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void AWD_BaseCharacter::LookUp(float Value)
{
		AddControllerPitchInput(Value);
}

void AWD_BaseCharacter::LookAround(float Value)
{
		AddControllerYawInput(Value);
}

void AWD_BaseCharacter::TakeGun()
{
	GunIsTaken = true;
}

void AWD_BaseCharacter::PutBackGun()
{
	GunIsTaken = false;
}

void AWD_BaseCharacter::StartAim()
{
	if(GunIsTaken)
		IsAiming = true;
}

void AWD_BaseCharacter::StopAim()
{
	IsAiming = false;

}

