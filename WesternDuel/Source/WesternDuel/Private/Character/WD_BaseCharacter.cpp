// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/WD_BaseCharacter.h"
#include "Character/WDPlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/WDWeaponComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/WDHealthComponent.h"
#include "Weapon/WDWeaponBase.h"

#include "DrawDebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"
// Sets default values
AWD_BaseCharacter::AWD_BaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	bUseControllerRotationYaw = false;
	bReplicates = true;
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Arm Component"));
	SpringArmComponent->bUsePawnControlRotation = true;
	SpringArmComponent->TargetArmLength = 160;
	SpringArmComponent->SocketOffset = FVector(-20, 0, 60);
	SpringArmComponent->TargetOffset = FVector(0,0,10);

	SpringArmComponent->SetupAttachment(GetRootComponent());

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);
	CameraComponent->bUsePawnControlRotation = false;

	WeaponComponent = CreateDefaultSubobject<UWDWeaponComponent>(TEXT("Weapon"));
	HealthComponent = CreateDefaultSubobject<UWDHealthComponent>(TEXT("Health"));
	GetCharacterMovement()->bUseControllerDesiredRotation = 0;
	GetCharacterMovement()->bOrientRotationToMovement = 0;
}

// Called when the game starts or when spawned
void AWD_BaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	SetReplicateMovement(true);
	if(HasAuthority())
		HealthComponent->OnDie.AddUObject(this, &AWD_BaseCharacter::OnDie);
	WeaponComponent->SetIsReplicated(true);
	GetCapsuleComponent()->SetIsReplicated(true);
	GetMesh()->SetIsReplicated(true);
	WeaponComponent->SetCrosshairVisibility(HasAuthority() || GetLocalRole() == ENetRole::ROLE_AutonomousProxy );
	
}

// Called every frame
void AWD_BaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*FVector BaseAimDirection = GetBaseAimRotation().Vector();
	FVector ForwardVector = GetActorRotation().Vector();
	
	DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + BaseAimDirection * 400, FColor::Red, false, 0.1, 0, 1);
	DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + ForwardVector * 400, FColor::Green, false, 0.1, 0, 1);*/
}

// Called to bind functionality to input
void AWD_BaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//PlayerInputComponent->BindAction("Dodge", EInputEvent::IE_Pressed, this, AWD_BaseCharacter::Dodge);
	PlayerInputComponent->BindAction("Shoot", EInputEvent::IE_Pressed, this, &AWD_BaseCharacter::TryFire);
	PlayerInputComponent->BindAction("Aim", EInputEvent::IE_Pressed, this, &AWD_BaseCharacter::StartAim);
	PlayerInputComponent->BindAction("Aim", EInputEvent::IE_Released, this, &AWD_BaseCharacter::StopAim);
	PlayerInputComponent->BindAction("TakeGun", EInputEvent::IE_Pressed, this, &AWD_BaseCharacter::TakeGun);
	PlayerInputComponent->BindAction("TakeGun", EInputEvent::IE_Released, this, &AWD_BaseCharacter::PutBackGun);
	PlayerInputComponent->BindAxis("MoveRight", this, &AWD_BaseCharacter::TryMoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &AWD_BaseCharacter::LookUp);
	PlayerInputComponent->BindAxis("LookAround", this, &AWD_BaseCharacter::LookAround);

	
}

float AWD_BaseCharacter::GetMovementDirection()
{
	float Direction = GetVelocity().Size()*InputDirection;
	return Direction;
}
FRotator AWD_BaseCharacter::GetAimDirection() {

	FRotator AimRotator = GetBaseAimRotation() - GetActorRotation();
	AimRotator.Yaw = UKismetMathLibrary::NormalizeAxis(AimRotator.Yaw);
	FString Iam = HasAuthority() ? "Server" : "Client";
	return AimRotator;
}
void AWD_BaseCharacter::TryMoveRight(float Value) 
{
	if (!GunIsTaken) {
		AddMovementInput(GetActorRightVector(), Value);
		MoveRight(Value);
	}
}
void AWD_BaseCharacter::MoveRight_Implementation(float Value)
{
	 InputDirection = Value;
}
void AWD_BaseCharacter::LookUp(float Value)
{
		AddControllerPitchInput(Value);
}

void AWD_BaseCharacter::LookAround(float Value)
{
		AddControllerYawInput(Value);
}

void AWD_BaseCharacter::TryFire_Implementation()
{
	if (!WeaponComponent) return;
	WeaponComponent->Fire();
}

void AWD_BaseCharacter::TakeGun_Implementation()
{
	GunIsTaken = true;
	WeaponComponent->TakeGunInHand();
}

void AWD_BaseCharacter::PutBackGun_Implementation()
{
	GunIsTaken = false;
	WeaponComponent->HolstersWeapon();

}

void AWD_BaseCharacter::StartAim_Implementation()
{
	if(GunIsTaken)
		IsAiming = true;
}

void AWD_BaseCharacter::StopAim_Implementation()
{
	IsAiming = false;
}
// On Server
void AWD_BaseCharacter::OnDie(AController* KilledBy)
{
	KillCharacter();
}

void AWD_BaseCharacter::KillCharacter_Implementation() {
	WeaponComponent->Detach();
	WeaponComponent->SetCrosshairVisibility(false);

	GetMovementComponent()->StopMovementImmediately();
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	GetMesh()->SetAllBodiesSimulatePhysics(true);
	GetMesh()->SetEnablePhysicsBlending(true);
	GetMesh()->AddForceAtLocation(-GetActorForwardVector() * 3000000, GetActorLocation(), "spine_01");
	
	const auto PlayerController = Cast<APlayerController>(GetController());
	if (!PlayerController) return;
	PlayerController->ChangeState(NAME_Spectating);
}
void AWD_BaseCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AWD_BaseCharacter, GunIsTaken);
	DOREPLIFETIME(AWD_BaseCharacter, IsAiming);
	DOREPLIFETIME(AWD_BaseCharacter, HealthComponent);
	DOREPLIFETIME(AWD_BaseCharacter, InputDirection);
	DOREPLIFETIME(AWD_BaseCharacter, WeaponComponent);
};

void AWD_BaseCharacter::OnRep_Direction() {
	FString Iam = HasAuthority() ? "Server" : "Client";
	
	UE_LOG(LogTemp, Warning, TEXT("IM - %s, replicated new Value %f"),*Iam,InputDirection);
}
