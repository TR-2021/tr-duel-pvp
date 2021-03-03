// Fill out your copyright notice in the Description page of Project Settings.


#include "WDGameStateBase.h"
#include "WDGameModeBase.h"
#include "Net/Unrealnetwork.h"

void AWDGameStateBase::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AWDGameStateBase, CurrentRound);
	DOREPLIFETIME(AWDGameStateBase, bIsGameOver);
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
	OnRep_RoundChanged();			// Call implicitly to trigger event on Server

	if (CurrentRound > CurrentGameMode->GetMaxRounds())
	{
		bIsGameOver = true;
		OnRep_GameOver();			// Call implicitly to trigger event on Server
	}
	else
	{
		CurrentGameMode->RestartRound();
	}
}

void AWDGameStateBase::OnRep_RoundChanged()
{
	OnRoundChanged.Broadcast();
}

void AWDGameStateBase::OnRep_GameOver()
{
	OnGameOver.Broadcast();
}
