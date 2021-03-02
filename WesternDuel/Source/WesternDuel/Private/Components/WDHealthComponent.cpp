// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/WDHealthComponent.h"
#include "Net/UnrealNetwork.h"


UWDHealthComponent::UWDHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UWDHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	SetIsReplicated(true);
	
	auto Owner = GetOwner();
	if (!Owner) return;
	Owner->OnTakeAnyDamage.AddDynamic(this, &UWDHealthComponent::OnAnyDamage);
}

void UWDHealthComponent::OnAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (IsDead()) return;

	SetHealth(HealthData.CurrentHealth - Damage);
	if (IsDead())
	{
		OnDie.Broadcast(InstigatedBy);
	}
}

bool UWDHealthComponent::IsDead()
{
	return HealthData.CurrentHealth == 0;
}
void UWDHealthComponent::SetHealth(float Health) {
	HealthData.CurrentHealth = FMath::Clamp<float>(Health, 0, HealthData.DefaultHealth);
	OnHealthChanged.Broadcast(Health);
}

float UWDHealthComponent::GetHealth() {
	return HealthData.CurrentHealth;
}

void UWDHealthComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UWDHealthComponent, HealthData);
}
