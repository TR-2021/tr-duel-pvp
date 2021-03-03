// Fill out your copyright notice in the Description page of Project Settings.


#include "WDGameStateBase.h"
#include "WDGameModeBase.h"
#include "Net/Unrealnetwork.h"

void AWDGameStateBase::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AWDGameStateBase, CurrentRound);
}


void AWDGameStateBase::NextRound_Implementation()
{
	
	// TODO Replace lambda function with function
	GetWorld()->GetTimerManager().SetTimer(Timer,this,&AWDGameStateBase::OnChangeRound, 2, false, 2);
}

void AWDGameStateBase::OnChangeRound_Implementation()
{

	if (!GetWorld()) return;

	auto CurrentGameMode = GetWorld()->GetAuthGameMode<AWDGameModeBase>();
	if (!CurrentGameMode) return;

	CurrentRound++;

	if (CurrentRound > CurrentGameMode->GetMaxRounds())
	{
		// STOP GAME
	}
	else
	{
		CurrentGameMode->RestartRound();
	}
}